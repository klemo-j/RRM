#include "Teleop.hpp"
#include <cmath>
#include <algorithm>

Teleop::Teleop() : Node("teleop_node") {
    client_ = this->create_client<rrm_msgs::srv::Command>("move_command");
    save_client_ = this->create_client<kleman_interface::srv::SavePoint>("save_robot_pose");

    // Inicializacia klienta pre IK (zakomentovana)
    // ik_client_ = this->create_client<kleman_interface::srv::SolveIK>("solve_ik");

    sub_ = this->create_subscription<sensor_msgs::msg::JointState>(
        "joint_states", 10, std::bind(&Teleop::joint_state_callback, this, std::placeholders::_1));

    while (!client_->wait_for_service(std::chrono::seconds(1))) {
        if (!rclcpp::ok()) return;
        RCLCPP_INFO(this->get_logger(), "Cakam na dostupnost servisu robota...");
    }
}

void Teleop::joint_state_callback(const sensor_msgs::msg::JointState::SharedPtr msg) {
    current_positions_ = msg->position;
    pos_received_ = true;
}

// ----- NOVA FUNKCIA PRE MANAZERA POHYBU -----
bool Teleop::move_ik(double x, double y, double z, double velocity) {
    if (!pos_received_) {
        RCLCPP_WARN(this->get_logger(), "Nemozem volat IK, poloha robota nie je znama!");
        return false;
    }

    RCLCPP_INFO(this->get_logger(), "Pytam sa IK Solvera na uhly pre X: %.2f, Y: %.2f, Z: %.2f", x, y, z);

    /* ZAKOMENTOVANE KYM NEVYTVORIME SERVICE
    auto request = std::make_shared<kleman_interface::srv::SolveIK::Request>();
    request->x = x;
    request->y = y;
    request->z = z;
    request->current_positions = current_positions_; // Pre najdenie najlepsieho riesenia

    auto result = ik_client_->async_send_request(request);
    if (rclcpp::spin_until_future_complete(this->get_node_base_interface(), result, std::chrono::seconds(2)) == rclcpp::FutureReturnCode::SUCCESS) {
        if (result.get()->success) {
            RCLCPP_INFO(this->get_logger(), "IK Solver nasiel riesenie. Vykonavam pohyb.");
            return this->move(result.get()->best_positions, velocity); // Zavolame tvoj stary move()
        } else {
            RCLCPP_WARN(this->get_logger(), "IK Solver nenasiel validne riesenie pre dany bod.");
            return false;
        }
    }
    */

    RCLCPP_ERROR(this->get_logger(), "Zatial neimplementovane, chyba IK uzol!");
    return false;
}

bool Teleop::move(const std::vector<double>& target_positions, double max_velocity) {
    if (!pos_received_) {
        RCLCPP_WARN(this->get_logger(), "Poloha robota nie je znama!");
        return false;
    }

    this->last_velocity_ = max_velocity;

    auto request = std::make_shared<rrm_msgs::srv::Command::Request>();
    std::vector<double> velocities(target_positions.size());
    double max_delta = 0.0;

    for (size_t i = 0; i < target_positions.size(); ++i) {
        double delta = std::abs(target_positions[i] - current_positions_[i]);
        if (delta > max_delta) max_delta = delta;
    }

    for (size_t i = 0; i < target_positions.size(); ++i) {
        if (max_delta > 0.001) {
            double delta = std::abs(target_positions[i] - current_positions_[i]);
            velocities[i] = (delta / max_delta) * max_velocity;
        } else {
            velocities[i] = 0.0;
        }
    }

    request->positions = target_positions;
    request->velocities = velocities;

    auto result = client_->async_send_request(request);
    if (rclcpp::spin_until_future_complete(this->get_node_base_interface(), result, std::chrono::seconds(10))
        == rclcpp::FutureReturnCode::SUCCESS) {
        return result.get()->result_code == 0;
    }
    return false;
}

double Teleop::get_last_velocity() const {
    return last_velocity_;
}