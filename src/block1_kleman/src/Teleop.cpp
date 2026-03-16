#include "Teleop.hpp"
#include <cmath>
#include <algorithm>

Teleop::Teleop() : Node("teleop_node") {
    client_ = this->create_client<rrm_msgs::srv::Command>("move_command");

    sub_ = this->create_subscription<sensor_msgs::msg::JointState>(
        "joint_states", 10, std::bind(&Teleop::joint_state_callback, this, std::placeholders::_1));

    while (!client_->wait_for_service(std::chrono::seconds(1))) {
        if (!rclcpp::ok()) return;
        RCLCPP_INFO(this->get_logger(), "Cakam na dostupnost servisu...");
    }
}

void Teleop::joint_state_callback(const sensor_msgs::msg::JointState::SharedPtr msg) {
    current_positions_ = msg->position;
    pos_received_ = true;
}

bool Teleop::move(const std::vector<double>& target_positions, double max_velocity) {
    if (!pos_received_) {
        RCLCPP_WARN(this->get_logger(), "Poloha robota nie je znama, cakam na JointState...");
        return false;
    }

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

    if (rclcpp::spin_until_future_complete(this->get_node_base_interface(), result, std::chrono::seconds(5))
        == rclcpp::FutureReturnCode::SUCCESS)
    {
        return result.get()->result_code == 0;
    }
    return false;
}