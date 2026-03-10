#include <iostream> 
#include "rclcpp/rclcpp.hpp"
#include "cv1/robot.hpp"

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    
    Robot robot;
    char input;

    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Robot active. Use W/A/S/D to move. Press Q to quit.");


    while (rclcpp::ok()) {
        std::cout << "Enter command (w/a/s/d): ";
        std::cin >> input;

        
        if (input == 'q') {
            break;
        }

    
        if (input == 'w') {
            robot.move(1.0, 0.0);
        } else if (input == 's') {
            robot.move(-1.0, 0.0);
        } else if (input == 'a') {
            robot.move(0.0, 1.0);
        } else if (input == 'd') {
            robot.move(0.0, -1.0);
        } else {
            std::cout << "Unknown command!" << std::endl;
            continue; 
        }

        
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Current Position: [X: %.2f, Y: %.2f]", 
                    robot.getX(), robot.getY());
    }

    rclcpp::shutdown();
    return 0;
}