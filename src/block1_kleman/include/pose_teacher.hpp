#ifndef POSE_TEACHER_HPP_
#define POSE_TEACHER_HPP_

#include <memory>
#include <array>
#include <string>

#include <Eigen/Geometry>

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/joint_state.hpp"

#include "geometry_msgs/msg/pose.hpp"

#include "visualization_msgs/msg/interactive_marker.hpp"
#include "visualization_msgs/msg/interactive_marker_feedback.hpp"

#include "interactive_markers/interactive_marker_server.hpp"

#include "abb_irb4600_ikfast/abb_irb4600_ikfast.h"

class PoseTeacher : public rclcpp::Node
{
public:
    PoseTeacher();

private:
    void make_marker(const Eigen::Affine3d & start_pose);

    void add_axis(
      visualization_msgs::msg::InteractiveMarker & marker,
      const std::string & name,
      double x,
      double y,
      double z,
      double w);

    void marker_callback(
      const visualization_msgs::msg::InteractiveMarkerFeedback::ConstSharedPtr & feedback);

    bool calculate_ik(const geometry_msgs::msg::Pose & pose);

    void publish_joints();

    void print_joints();

    geometry_msgs::msg::Pose eigen_to_pose(const Eigen::Affine3d & tf);

    Eigen::Affine3d pose_to_eigen(const geometry_msgs::msg::Pose & pose);

    std::shared_ptr<interactive_markers::InteractiveMarkerServer> server_;

    rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr joint_pub_;
    rclcpp::TimerBase::SharedPtr timer_;

    std::array<std::string, 6> joint_names_;
    ikfast_abb::JointValues q_;
};

#endif