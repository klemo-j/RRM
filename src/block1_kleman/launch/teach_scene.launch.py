from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.conditions import IfCondition
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
import os


def generate_launch_description():
    use_rviz = LaunchConfiguration("use_rviz")

    abb_model_share = get_package_share_directory("abb_model")
    urdf_path = os.path.join(abb_model_share, "urdf", "robot.urdf")

    with open(urdf_path, "r") as f:
        robot_description = f.read()

    # RViz config – use the one from abb_model if a custom one does not exist yet
    rviz_config_path = os.path.join(
        get_package_share_directory("block1_kleman"), "rviz", "machining.rviz"
    )
    if not os.path.isfile(rviz_config_path):
        rviz_config_path = os.path.join(abb_model_share, "config", "urdf.rviz")

    return LaunchDescription([
        DeclareLaunchArgument(
            "use_rviz",
            default_value="true",
            description="Start RViz"
        ),

        # Publish robot URDF / TF
        Node(
            package="robot_state_publisher",
            executable="robot_state_publisher",
            name="robot_state_publisher",
            output="screen",
            parameters=[{"robot_description": robot_description}]
        ),

        # Visualise the work object (marker on topic visualization_marker)
        Node(
            package="block1_kleman",
            executable="model_spawner",
            name="model_spawner",
            output="screen"
        ),

        # Main trajectory executor (service: /execute_machining)
        Node(
            package="block1_kleman",
            executable="manipulator",
            name="manipulator",
            output="screen"
        ),

        # Joint data logger → /home/$USER/ros2_ws/joint_log.csv
        Node(
            package="block1_kleman",
            executable="joint_logger",
            name="joint_logger",
            output="screen"
        ),

        # RViz2
        Node(
            package="rviz2",
            executable="rviz2",
            name="rviz2",
            output="screen",
            arguments=["-d", rviz_config_path],
            condition=IfCondition(use_rviz)
        ),
    ])