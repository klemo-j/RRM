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
find_package(Eigen3 REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(geometry_msgs REQUIRED)

include_directories(include)
include_directories(${EIGEN3_INCLUDE_DIR})

add_executable(logger_node src/logger_node.cpp)
ament_target_dependencies(logger_node
        rclcpp
        sensor_msgs
        Eigen3
        tf2
        tf2_ros
        geometry_msgs
        kleman_interface
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

install(DIRECTORY launch
        DESTINATION share/${PROJECT_NAME}
)

ament_package()