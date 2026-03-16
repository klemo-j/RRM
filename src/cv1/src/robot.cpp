#include "cv1/robot.hpp"
#include "rclcpp/rclcpp.hpp"


Robot::Robot() : x_(0.0), y_(0.0) {
    
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Hello, I'm a robot initialized at [0,0]");
}

void Robot::move(double x, double y) {
    
    x_ += x;
    y_ += y;
}

double Robot::getX() const {
    return x_;
}

double Robot::getY() const {
    return y_;
}