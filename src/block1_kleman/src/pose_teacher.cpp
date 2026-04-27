#include "../include/pose_teacher.hpp"

#include <vector>
#include <sstream>
#include <limits>
#include <chrono>
#include <functional>

#include "visualization_msgs/msg/marker.hpp"
#include "visualization_msgs/msg/interactive_marker_control.hpp"

using namespace std::chrono_literals;

PoseTeacher::PoseTeacher()
: Node("pose_teacher")
{
  joint_pub_ = create_publisher<sensor_msgs::msg::JointState>("joint_states", 10);

  joint_names_ = {
    "joint_1",
    "joint_2",
    "joint_3",
    "joint_4",
    "joint_5",
    "joint_6"
  };

  q_ = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};

  server_ = std::make_shared<interactive_markers::InteractiveMarkerServer>(
    "pose_teacher_marker",
    this
  );

  Eigen::Affine3d start_pose = ikfast_abb::computeFk(q_);

  make_marker(start_pose);

  timer_ = create_wall_timer(
    30ms,
    std::bind(&PoseTeacher::publish_joints, this)
  );

  RCLCPP_INFO(get_logger(), "Pose teacher started");
}

geometry_msgs::msg::Pose PoseTeacher::eigen_to_pose(const Eigen::Affine3d & tf)
{
  geometry_msgs::msg::Pose p;

  p.position.x = tf.translation().x();
  p.position.y = tf.translation().y();
  p.position.z = tf.translation().z();

  Eigen::Quaterniond q(tf.rotation());
  q.normalize();

  p.orientation.x = q.x();
  p.orientation.y = q.y();
  p.orientation.z = q.z();
  p.orientation.w = q.w();

  return p;
}

Eigen::Affine3d PoseTeacher::pose_to_eigen(const geometry_msgs::msg::Pose & p)
{
  Eigen::Affine3d tf = Eigen::Affine3d::Identity();

  tf.translation() << p.position.x, p.position.y, p.position.z;

  Eigen::Quaterniond q(
    p.orientation.w,
    p.orientation.x,
    p.orientation.y,
    p.orientation.z
  );

  q.normalize();
  tf.linear() = q.toRotationMatrix();

  return tf;
}

void PoseTeacher::make_marker(const Eigen::Affine3d & start_pose)
{
  visualization_msgs::msg::InteractiveMarker marker;

  marker.header.frame_id = "base_link";
  marker.name = "gizmo";
  marker.description = "gizmo";
  marker.pose = eigen_to_pose(start_pose);
  marker.scale = 0.65;

  visualization_msgs::msg::InteractiveMarkerControl main_control;
  main_control.always_visible = true;

  visualization_msgs::msg::Marker ball;
  ball.type = visualization_msgs::msg::Marker::SPHERE;
  ball.scale.x = 0.12;
  ball.scale.y = 0.12;
  ball.scale.z = 0.12;
  ball.color.r = 1.0;
  ball.color.g = 0.2;
  ball.color.b = 0.0;
  ball.color.a = 1.0;
  ball.pose.orientation.w = 1.0;

  main_control.markers.push_back(ball);
  marker.controls.push_back(main_control);

  add_axis(marker, "x", 1.0, 0.0, 0.0, 1.0);
  add_axis(marker, "y", 0.0, 1.0, 0.0, 1.0);
  add_axis(marker, "z", 0.0, 0.0, 1.0, 1.0);

  server_->insert(
    marker,
    std::bind(&PoseTeacher::marker_callback, this, std::placeholders::_1)
  );

  server_->applyChanges();
}

void PoseTeacher::add_axis(
  visualization_msgs::msg::InteractiveMarker & marker,
  const std::string & name,
  double x,
  double y,
  double z,
  double w)
{
  visualization_msgs::msg::InteractiveMarkerControl move;

  move.name = "move_" + name;
  move.orientation.x = x;
  move.orientation.y = y;
  move.orientation.z = z;
  move.orientation.w = w;
  move.orientation_mode = visualization_msgs::msg::InteractiveMarkerControl::FIXED;
  move.interaction_mode = visualization_msgs::msg::InteractiveMarkerControl::MOVE_AXIS;

  marker.controls.push_back(move);

  visualization_msgs::msg::InteractiveMarkerControl rotate;

  rotate.name = "rotate_" + name;
  rotate.orientation.x = x;
  rotate.orientation.y = y;
  rotate.orientation.z = z;
  rotate.orientation.w = w;
  rotate.orientation_mode = visualization_msgs::msg::InteractiveMarkerControl::FIXED;
  rotate.interaction_mode = visualization_msgs::msg::InteractiveMarkerControl::ROTATE_AXIS;

  marker.controls.push_back(rotate);
}

void PoseTeacher::marker_callback(
  const visualization_msgs::msg::InteractiveMarkerFeedback::ConstSharedPtr & feedback)
{
  if (feedback->event_type ==
      visualization_msgs::msg::InteractiveMarkerFeedback::POSE_UPDATE)
  {
    calculate_ik(feedback->pose);
  }

  if (feedback->event_type ==
      visualization_msgs::msg::InteractiveMarkerFeedback::MOUSE_UP)
  {
    if (calculate_ik(feedback->pose)) {
      print_joints();
    }
  }
}

bool PoseTeacher::calculate_ik(const geometry_msgs::msg::Pose & pose)
{
  Eigen::Affine3d target = pose_to_eigen(pose);

  std::vector<ikfast_abb::JointValues> solutions = ikfast_abb::computeIK(target);

  if (solutions.empty()) {
    RCLCPP_WARN(get_logger(), "IK solution not found");
    return false;
  }

  int best = 0;
  double best_dist = std::numeric_limits<double>::max();

  for (size_t i = 0; i < solutions.size(); i++) {
    double dist = 0.0;

    for (size_t j = 0; j < 6; j++) {
      double diff = solutions[i][j] - q_[j];
      dist += diff * diff;
    }

    if (dist < best_dist) {
      best_dist = dist;
      best = i;
    }
  }

  q_ = solutions[best];

  publish_joints();

  return true;
}

void PoseTeacher::publish_joints()
{
  sensor_msgs::msg::JointState msg;

  msg.header.stamp = now();

  for (size_t i = 0; i < 6; i++) {
    msg.name.push_back(joint_names_[i]);
    msg.position.push_back(q_[i]);
  }

  joint_pub_->publish(msg);
}

void PoseTeacher::print_joints()
{
  std::stringstream ss;

  ss << "\n";
  ss << "JOINTS:\n";
  ss << "{";

  for (size_t i = 0; i < 6; i++) {
    ss << q_[i];

    if (i < 5) {
      ss << ", ";
    }
  }

  ss << "}";

  RCLCPP_INFO(get_logger(), "%s", ss.str().c_str());
}

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);

  auto node = std::make_shared<PoseTeacher>();
  rclcpp::spin(node);

  rclcpp::shutdown();

  return 0;
}