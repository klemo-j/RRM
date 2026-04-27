#include "../include/model_spawner.hpp"

#include <chrono>
#include <memory>
#include <functional>

using namespace std::chrono_literals;

ModelSpawner::ModelSpawner()
: Node("model_spawner")
{
  marker_pub_ = create_publisher<visualization_msgs::msg::Marker>(
    "visualization_marker",
    rclcpp::QoS(1).transient_local()
  );

  timer_ = create_wall_timer(
    500ms,
    std::bind(&ModelSpawner::publish_marker, this)
  );

  RCLCPP_INFO(get_logger(), "Model spawner started");
}

void ModelSpawner::publish_marker()
{
  visualization_msgs::msg::Marker marker;

  marker.header.frame_id = "base_link";
  marker.header.stamp = now();

  marker.ns = "work_object";
  marker.id = 0;
  marker.type = visualization_msgs::msg::Marker::MESH_RESOURCE;
  marker.action = visualization_msgs::msg::Marker::ADD;

  marker.mesh_resource = "package://block1_kleman/meshes/tie.stl";
  marker.mesh_use_embedded_materials = true;

  marker.scale.x = 1.0;
  marker.scale.y = 1.0;
  marker.scale.z = 1.0;

  marker.pose.position.x = 2.15;
  marker.pose.position.y = 0.35;
  marker.pose.position.z = 0.0;

  marker.pose.orientation.x = 0.0;
  marker.pose.orientation.y = 0.0;
  marker.pose.orientation.z = 0.0;
  marker.pose.orientation.w = 1.0;

  marker.color.r = 0.35f;
  marker.color.g = 0.35f;
  marker.color.b = 0.35f;
  marker.color.a = 1.0f;

  marker.lifetime = rclcpp::Duration::from_seconds(0.0);

  marker_pub_->publish(marker);
}

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<ModelSpawner>());
  rclcpp::shutdown();

  return 0;
}