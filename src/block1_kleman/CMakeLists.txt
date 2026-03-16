cmake_minimum_required(VERSION 3.8)
project(block1_kleman)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rrm_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(kleman_interface REQUIRED)
find_package(std_srvs REQUIRED)

include_directories(include)

add_executable(logger_node src/logger_node.cpp)
ament_target_dependencies(logger_node
        rclcpp
        sensor_msgs
        kleman_interface
        std_srvs
)

add_executable(teleop_node src/teleop_node.cpp src/Teleop.cpp)
ament_target_dependencies(teleop_node
        rclcpp
        rrm_msgs
        sensor_msgs
        kleman_interface
        std_srvs
)

install(TARGETS logger_node teleop_node
        DESTINATION lib/${PROJECT_NAME})

ament_package()