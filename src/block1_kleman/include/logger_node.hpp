#ifndef LOGGER_NODE_HPP
#define LOGGER_NODE_HPP

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/joint_state.hpp"
#include "kleman_interface/srv/save_point.hpp"
#include <vector>
#include <fstream>
#include <cmath>

// Eigen a TF2 kniznice pre priamu kinematiku
#include <Eigen/Dense>
#include <Eigen/Geometry>
#include <tf2_ros/transform_broadcaster.h>
#include <geometry_msgs/msg/transform_stamped.hpp>

class JointLogger : public rclcpp::Node {
public:
    JointLogger();

private:
    void joint_states_callback(const sensor_msgs::msg::JointState::SharedPtr msg);
    void save_point_callback(
        const std::shared_ptr<kleman_interface::srv::SavePoint::Request> request,
        std::shared_ptr<kleman_interface::srv::SavePoint::Response> response);
    void save_to_file(int id, const std::vector<double>& positions, double max_velocity);

    // Pomocna funkcia na vytvorenie 4x4 matice z DH parametrov
    Eigen::Matrix4d create_dh_matrix(double a, double alpha, double d, double theta);

    rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr subscription_;
    rclcpp::Service<kleman_interface::srv::SavePoint>::SharedPtr service_;

    // Nastroj na vysielanie transformacii do Rviz
    tf2_ros::TransformBroadcaster tf_broadcaster_;

    std::vector<double> current_positions_;
    int point_counter_ = 0;
};

#endif