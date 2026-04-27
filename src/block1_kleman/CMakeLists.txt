cmake_minimum_required(VERSION 3.8)
project(block1_kleman)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)

find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(visualization_msgs REQUIRED)
find_package(interactive_markers REQUIRED)
find_package(Eigen3 REQUIRED)

find_package(abb_irb4600_ikfast REQUIRED)

include_directories(
        include
)

add_executable(model_spawner
        src/model_spawner.cpp
)

ament_target_dependencies(model_spawner
        rclcpp
        visualization_msgs
)

add_executable(pose_teacher
        src/pose_teacher.cpp
)

ament_target_dependencies(pose_teacher
        rclcpp
        sensor_msgs
        geometry_msgs
        visualization_msgs
        interactive_markers
        abb_irb4600_ikfast
)

target_link_libraries(pose_teacher
        Eigen3::Eigen
)

add_executable(joint_logger
        src/joint_logger.cpp
)

ament_target_dependencies(joint_logger
        rclcpp
        sensor_msgs
)

install(TARGETS
        model_spawner
        pose_teacher
        joint_logger
        DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY
        include/
        DESTINATION include
)

install(DIRECTORY
        launch
        DESTINATION share/${PROJECT_NAME}
)

install(DIRECTORY
        rviz
        DESTINATION share/${PROJECT_NAME}
        OPTIONAL
)

install(DIRECTORY
        meshes
        DESTINATION share/${PROJECT_NAME}
)

ament_package()