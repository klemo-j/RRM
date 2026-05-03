#ifndef MANIPULATOR_HPP_
#define MANIPULATOR_HPP_

#include <array>
#include <fstream>
#include <memory>
#include <string>

#include <Eigen/Geometry>

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/joint_state.hpp"
#include "std_msgs/msg/int8.hpp"
#include "std_srvs/srv/trigger.hpp"
#include "visualization_msgs/msg/marker.hpp"

#include "abb_irb4600_ikfast/abb_irb4600_ikfast.h"

class Manipulator : public rclcpp::Node
{
public:
  Manipulator();

  enum State { IDLE = 0, PTP = 1, APPROACHING = 2, MACHINING = 3, RETRACTING = 4 };

private:
  // ROS interfaces
  rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr     joint_pub_;
  rclcpp::Publisher<std_msgs::msg::Int8>::SharedPtr               state_pub_;
  rclcpp::Publisher<visualization_msgs::msg::Marker>::SharedPtr   path_pub_;
  rclcpp::Service<std_srvs::srv::Trigger>::SharedPtr              service_;

  // Two callback groups so idle timer keeps running during sequence
  rclcpp::CallbackGroup::SharedPtr  service_cbg_;
  rclcpp::CallbackGroup::SharedPtr  timer_cbg_;
  rclcpp::TimerBase::SharedPtr      idle_timer_;

  // State
  std::array<std::string, 6> joint_names_;
  ikfast_abb::JointValues    q_;
  ikfast_abb::JointValues    q_vel_;
  ikfast_abb::JointValues    q_acc_;

  visualization_msgs::msg::Marker path_marker_;
  int path_id_;

  // CSV log
  std::ofstream  log_file_;
  rclcpp::Time   log_start_;
  bool           logging_;

  // Callbacks
  void execute_callback(
    const std::shared_ptr<std_srvs::srv::Trigger::Request> req,
    std::shared_ptr<std_srvs::srv::Trigger::Response> res);

  // Sequence
  void run_sequence();

  // Motion primitives
  void move_ptp(const ikfast_abb::JointValues & target, double duration);
  void move_ptp_via(
    const ikfast_abb::JointValues & start,
    const ikfast_abb::JointValues & via,
    const ikfast_abb::JointValues & goal,
    double t_via, double total_duration);
  bool move_lin(
    const Eigen::Affine3d & start_pose,
    const Eigen::Affine3d & goal_pose,
    double duration, int state);

  // Helpers
  Eigen::Affine3d make_approach_pose(const Eigen::Affine3d & pose, double distance);
  bool calculate_ik(
    const Eigen::Affine3d & pose,
    const ikfast_abb::JointValues & previous,
    ikfast_abb::JointValues & result);

  // Quintic s-curve and derivatives
  double s_curve(double tau);
  double s_curve_vel(double tau, double duration);
  double s_curve_acc(double tau, double duration);

  // Publishing & logging
  void publish_joints();
  void publish_state(int state);
  void start_path(int state);
  void add_path_point(const Eigen::Affine3d & pose);
  void publish_path();
  void log_sample();
};

#endif