//
// Created by kllemo on 3/7/26.
//

#ifndef ROS2_WS_TELEOP_HPP
#define ROS2_WS_TELEOP_HPP

#include "rclcpp/rclcpp.hpp"
#include "rrm_msgs/srv/command.hpp"
#include "sensor_msgs/msg/joint_state.hpp"
#include <vector>

class Teleop : public rclcpp::Node {
public:
    Teleop();

    bool move(const std::vector<double>& target_positions, double max_velocity);

private:
    void joint_state_callback(const sensor_msgs::msg::JointState::SharedPtr msg);

    rclcpp::Client<rrm_msgs::srv::Command>::SharedPtr client_;
    rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr sub_;

    std::vector<double> current_positions_;
    bool pos_received_ = false;
};

#endif
