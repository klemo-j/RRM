#include "logger_node.hpp"


JointLogger::JointLogger() : Node("joint_logger"), tf_broadcaster_(this) {
    subscription_ = this->create_subscription<sensor_msgs::msg::JointState>(
        "joint_states", 10, std::bind(&JointLogger::joint_states_callback, this, std::placeholders::_1));

    service_ = this->create_service<kleman_interface::srv::SavePoint>(
        "save_robot_pose",
        std::bind(&JointLogger::save_point_callback, this, std::placeholders::_1, std::placeholders::_2));

    RCLCPP_INFO(this->get_logger(), "Logger bezi a caka na poziadavky.");
}

// Funkcia na 4x4 maticu z DH parametrov
Eigen::Matrix4d JointLogger::create_dh_matrix(double a, double alpha, double d, double theta) {
    Eigen::Matrix4d mat = Eigen::Matrix4d::Identity();
    mat(0, 0) = std::cos(theta);
    mat(0, 1) = -std::sin(theta) * std::cos(alpha);
    mat(0, 2) = std::sin(theta) * std::sin(alpha);
    mat(0, 3) = a * std::cos(theta);

    mat(1, 0) = std::sin(theta);
    mat(1, 1) = std::cos(theta) * std::cos(alpha);
    mat(1, 2) = -std::cos(theta) * std::sin(alpha);
    mat(1, 3) = a * std::sin(theta);

    mat(2, 0) = 0.0;
    mat(2, 1) = std::sin(alpha);
    mat(2, 2) = std::cos(alpha);
    mat(2, 3) = d;

    return mat;
}

void JointLogger::joint_states_callback(const sensor_msgs::msg::JointState::SharedPtr msg) {
    current_positions_ = msg->position;


    if (current_positions_.size() < 3) return;

    double t1 = current_positions_[0];
    double t2 = current_positions_[1];
    double t3 = current_positions_[2];


    double L2 = 0.203;
    double L1 = 0.203;

    // matic (A1, A2, A3)
    Eigen::Matrix4d A1 = create_dh_matrix(0.0, M_PI_2, 0.0, M_PI + t1);
    Eigen::Matrix4d A2 = create_dh_matrix(L2,  0, 0.0, M_PI_2 + t2);
    Eigen::Matrix4d A3 = create_dh_matrix(L1, 0, 0.0, 0 + t3);


    Eigen::Matrix4d T3_0 = A1 * A2 * A3;

    //  TF
    geometry_msgs::msg::TransformStamped transform;
    transform.header.stamp = this->get_clock()->now();
    transform.header.frame_id = "base_link";
    transform.child_frame_id = "tool0_calculated";

    // (X, Y, Z) z matice
    transform.transform.translation.x = T3_0(0, 3);
    transform.transform.translation.y = T3_0(1, 3);
    transform.transform.translation.z = T3_0(2, 3);

    // Kvaternionu
    Eigen::Quaterniond q(T3_0.block<3, 3>(0, 0));
    transform.transform.rotation.x = q.x();
    transform.transform.rotation.y = q.y();
    transform.transform.rotation.z = q.z();
    transform.transform.rotation.w = q.w();

    // Publikovanie Rviz
    tf_broadcaster_.sendTransform(transform);
}

void JointLogger::save_point_callback(
    const std::shared_ptr<kleman_interface::srv::SavePoint::Request> request,
    std::shared_ptr<kleman_interface::srv::SavePoint::Response> response) {

    if (current_positions_.empty()) {
        response->result = false;
        response->message = "Chyba: Ziadne data z klbov!";
        return;
    }

    point_counter_++;
    save_to_file(point_counter_, current_positions_, request->velocity);

    response->result = true;
    response->message = "Bod " + std::to_string(point_counter_) + " ulozeny.";
    RCLCPP_INFO(this->get_logger(), "Zapisal som bod ID: %d", point_counter_);
}

void JointLogger::save_to_file(int id, const std::vector<double>& positions, double max_velocity) {
    std::ofstream outfile("trajektoria.txt", std::ios_base::app);
    if (outfile.is_open()) {
        outfile << id << " " << positions[0] << " " << positions[1] << " " << positions[2] << " " << max_velocity << "\n";
        outfile.close();
    }
}

int main(int argc, char ** argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<JointLogger>());
    rclcpp::shutdown();
    return 0;
}