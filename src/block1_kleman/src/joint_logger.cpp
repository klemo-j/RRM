#include <memory>
#include <string>
#include <fstream>
#include <functional>
#include <cstdlib>   // getenv

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/joint_state.hpp"

/*
 * Logs joint_3 position, velocity and acceleration to a CSV file.
 *
 * Velocity and acceleration are taken directly from the JointState message
 * (manipulator node fills msg.velocity  = q_vel_  and
 *                             msg.effort = q_acc_  for all joints).
 *
 * The log file path is determined at runtime:
 *   $ROS_LOG_DIR/joint_log.csv   if ROS_LOG_DIR is set
 *   $HOME/ros2_ws/joint_log.csv  otherwise
 */

class JointLogger : public rclcpp::Node
{
public:
  JointLogger()
  : Node("joint_logger")
  {
    // Resolve output path without hardcoding the username
    std::string log_path;
    const char * ros_log = std::getenv("ROS_LOG_DIR");
    const char * home    = std::getenv("HOME");

    if (ros_log) {
      log_path = std::string(ros_log) + "/joint_log.csv";
    } else if (home) {
      log_path = std::string(home) + "/ros2_ws/joint_log.csv";
    } else {
      log_path = "/tmp/joint_log.csv";
    }

    file_.open(log_path);

    if (!file_.is_open()) {
      RCLCPP_ERROR(get_logger(), "Cannot open log file: %s", log_path.c_str());
    } else {
      RCLCPP_INFO(get_logger(), "Logging joint_3 to: %s", log_path.c_str());
      file_ << "time,position,velocity,acceleration\n";
    }

    start_time_ = now();

    sub_ = create_subscription<sensor_msgs::msg::JointState>(
      "joint_states",
      10,
      std::bind(&JointLogger::joint_callback, this, std::placeholders::_1)
    );

    RCLCPP_INFO(get_logger(), "Joint logger started");
  }

  ~JointLogger()
  {
    if (file_.is_open()) {
      file_.close();
    }
  }

private:
  rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr sub_;
  std::ofstream file_;
  rclcpp::Time  start_time_;

  void joint_callback(const sensor_msgs::msg::JointState::SharedPtr msg)
  {
    if (!file_.is_open()) {
      return;
    }

    // Find joint_3
    int idx = -1;
    for (size_t i = 0; i < msg->name.size(); i++) {
      if (msg->name[i] == "joint_3") {
        idx = static_cast<int>(i);
        break;
      }
    }
    if (idx == -1) { return; }

    const double time     = (now() - start_time_).seconds();
    const double position = msg->position[idx];

    // Velocity is published in msg.velocity, acceleration in msg.effort
    // (see manipulator.cpp publish_joints())
    double velocity     = 0.0;
    double acceleration = 0.0;

    if (idx < static_cast<int>(msg->velocity.size())) {
      velocity = msg->velocity[idx];
    }
    if (idx < static_cast<int>(msg->effort.size())) {
      acceleration = msg->effort[idx];
    }

    file_ << time         << ","
          << position     << ","
          << velocity     << ","
          << acceleration << "\n";
  }
};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<JointLogger>());
  rclcpp::shutdown();
  return 0;
}