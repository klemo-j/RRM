#ifndef TELEOP_HPP
#define TELEOP_HPP

#include "rclcpp/rclcpp.hpp"
#include "rrm_msgs/srv/command.hpp"
#include "sensor_msgs/msg/joint_state.hpp"
#include "kleman_interface/srv/save_point.hpp"
// Zatial zakomentovane, kym nevytvorime tento service v dalsom kroku!
// #include "kleman_interface/srv/solve_ik.hpp"
#include "std_srvs/srv/trigger.hpp"
#include <vector>

class Teleop : public rclcpp::Node {
public:
    Teleop();
    bool move(const std::vector<double>& target_positions, double max_velocity);

    // Nova metoda pre inverznu kinematiku
    bool move_ik(double x, double y, double z, double velocity);

    double get_last_velocity() const;
    rclcpp::Client<kleman_interface::srv::SavePoint>::SharedPtr get_save_client() { return save_client_; }

private:
    void joint_state_callback(const sensor_msgs::msg::JointState::SharedPtr msg);

    rclcpp::Client<rrm_msgs::srv::Command>::SharedPtr client_;
    rclcpp::Client<kleman_interface::srv::SavePoint>::SharedPtr save_client_;

    // Klient pre komunikaciu s IK Solverom (zakomentovany kym nevytvorime srv)
    // rclcpp::Client<kleman_interface::srv::SolveIK>::SharedPtr ik_client_;

    rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr sub_;

    std::vector<double> current_positions_;
    bool pos_received_ = false;
    double last_velocity_ = 0.0;
};

#endif