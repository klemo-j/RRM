// Created by kllemo on 2/24/26.

#ifndef ROS2_WS_LOGGER_NODE_HPP
#define ROS2_WS_LOGGER_NODE_HPP

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/joint_state.hpp"

// Definujeme triedu pre node JointLogger
class JointLogger : public rclcpp::Node
{
public:
    JointLogger();
    void joint_states_callback(const sensor_msgs::msg::JointState::SharedPtr msg);
private:
    rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr subscription_;
};

#endif //ROS2_WS_LOGGER_NODE_HPP