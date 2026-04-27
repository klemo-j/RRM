#include <memory>
#include <string>
#include <fstream>
#include <functional>

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/joint_state.hpp"

class Joint3Logger : public rclcpp::Node
{
public:
  Joint3Logger()
  : Node("joint3_logger")
  {
    file_.open("/home/kllemo/ros2_ws/joint3_log.csv");

    file_ << "time,position,velocity,acceleration\n";

    start_time_ = now();

    last_time_ = 0.0;
    last_position_ = 0.0;
    last_velocity_ = 0.0;
    first_value_ = true;

    sub_ = create_subscription<sensor_msgs::msg::JointState>(
      "joint_states",
      10,
      std::bind(&Joint3Logger::joint_callback, this, std::placeholders::_1)
    );

    RCLCPP_INFO(get_logger(), "Joint 3 logger started");
  }

  ~Joint3Logger()
  {
    file_.close();
  }

private:
  rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr sub_;
  std::ofstream file_;

  rclcpp::Time start_time_;

  double last_time_;
  double last_position_;
  double last_velocity_;
  bool first_value_;

  void joint_callback(const sensor_msgs::msg::JointState::SharedPtr msg)
  {
    int joint_index = -1;

    for (size_t i = 0; i < msg->name.size(); i++) {
      if (msg->name[i] == "joint_3") {
        joint_index = i;
        break;
      }
    }

    if (joint_index == -1) {
      return;
    }

    double time = (now() - start_time_).seconds();
    double position = msg->position[joint_index];

    double velocity = 0.0;
    double acceleration = 0.0;

    if (!first_value_) {
      double dt = time - last_time_;

      if (dt > 0.0001) {
        velocity = (position - last_position_) / dt;
        acceleration = (velocity - last_velocity_) / dt;
      }
    }

    file_ << time << ","
          << position << ","
          << velocity << ","
          << acceleration << "\n";

    last_time_ = time;
    last_position_ = position;
    last_velocity_ = velocity;
    first_value_ = false;
  }
};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);

  auto node = std::make_shared<Joint3Logger>();
  rclcpp::spin(node);

  rclcpp::shutdown();

  return 0;
}