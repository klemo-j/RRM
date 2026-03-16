#include "logger_node.hpp"

JointLogger::JointLogger() : Node("joint_logger") {
    subscription_ = this->create_subscription<sensor_msgs::msg::JointState>(
        "joint_states", 10, std::bind(&JointLogger::joint_states_callback, this, std::placeholders::_1));

    service_ = this->create_service<kleman_interface::srv::SavePoint>(
        "save_robot_pose",
        std::bind(&JointLogger::save_point_callback, this, std::placeholders::_1, std::placeholders::_2));

    RCLCPP_INFO(this->get_logger(), "Logger bezi a caka na poziadavky.");
}

void JointLogger::joint_states_callback(const sensor_msgs::msg::JointState::SharedPtr msg) {
    current_positions_ = msg->position;
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