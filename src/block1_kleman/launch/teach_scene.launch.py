from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.conditions import IfCondition
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
import os


def generate_launch_description():
    use_joint_state_gui = LaunchConfiguration("use_joint_state_gui")
    use_rviz = LaunchConfiguration("use_rviz")

    abb_model_share = get_package_share_directory("abb_model")
    urdf_path = os.path.join(abb_model_share, "urdf", "robot.urdf")

    with open(urdf_path, "r") as f:
        robot_description = f.read()

    return LaunchDescription([
        DeclareLaunchArgument(
            "use_joint_state_gui",
            default_value="false",
            description="Use joint_state_publisher_gui"
        ),

        DeclareLaunchArgument(
            "use_rviz",
            default_value="true",
            description="Start RViz"
        ),

        Node(
            package="robot_state_publisher",
            executable="robot_state_publisher",
            name="robot_state_publisher",
            output="screen",
            parameters=[{"robot_description": robot_description}]
        ),

        Node(
            package="joint_state_publisher_gui",
            executable="joint_state_publisher_gui",
            name="joint_state_publisher_gui",
            output="screen",
            condition=IfCondition(use_joint_state_gui)
        ),

        Node(
            package="rviz2",
            executable="rviz2",
            name="rviz2",
            output="screen",
            condition=IfCondition(use_rviz)
        ),

        Node(
            package="block1_kleman",
            executable="model_spawner",
            name="model_spawner",
            output="screen"
        ),

        Node(
            package="block1_kleman",
            executable="pose_teacher",
            name="pose_teacher",
            output="screen"
        )
    ])