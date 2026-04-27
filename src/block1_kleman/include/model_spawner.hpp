#ifndef BLOCK1_KLEMAN__MODEL_SPAWNER_HPP_
#define BLOCK1_KLEMAN__MODEL_SPAWNER_HPP_

#include "rclcpp/rclcpp.hpp"
#include "visualization_msgs/msg/marker.hpp"

class ModelSpawner : public rclcpp::Node
{
public:
    ModelSpawner();

private:
    void publish_marker();

    rclcpp::Publisher<visualization_msgs::msg::Marker>::SharedPtr marker_pub_;
    rclcpp::TimerBase::SharedPtr timer_;
};

#endif