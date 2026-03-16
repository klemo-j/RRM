// Created by kllemo on 2/24/26.

#include "logger_node.hpp"

JointLogger::JointLogger() : Node("joint_logger")
{
    subscription_ = this->create_subscription<sensor_msgs::msg::JointState>(
    "joint_states", 10, std::bind(&JointLogger::joint_states_callback, this, std::placeholders::_1));
}

void JointLogger::joint_states_callback(const sensor_msgs::msg::JointState::SharedPtr msg)
{

    size_t num_joints = msg->name.size();


    for (size_t i = 0; i < num_joints; ++i) {
        RCLCPP_INFO(this->get_logger(), "Klb: %s, Pozicia: %f", msg->name[i].c_str(), msg->position[i]);
    }


    RCLCPP_INFO(this->get_logger(), "-----------------------------------");
}
int main(int argc, char ** argv)
{
    rclcpp::init(argc, argv);
    std::shared_ptr<JointLogger> logger = std::make_shared<JointLogger>();
    rclcpp::spin(logger);
    rclcpp::shutdown();
    return 0;
}