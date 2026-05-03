from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
import os


def generate_launch_description():
    abb_share = get_package_share_directory("abb_model")
    urdf_path = os.path.join(abb_share, "urdf", "robot.urdf")
    with open(urdf_path, "r") as f:
        robot_description = f.read()

    pkg_share = get_package_share_directory("block1_kleman")
    rviz_config = os.path.join(pkg_share, "rviz", "machining.rviz")
    rviz_args = ["-d", rviz_config] if os.path.isfile(rviz_config) else []

    return LaunchDescription([
        Node(
            package="robot_state_publisher",
            executable="robot_state_publisher",
            parameters=[{"robot_description": robot_description}],
            output="screen",
        ),
        Node(
            package="block1_kleman",
            executable="model_spawner",
            output="screen",
        ),
        Node(
            package="block1_kleman",
            executable="manipulator",
            output="screen",
        ),
        Node(
            package="rviz2",
            executable="rviz2",
            arguments=rviz_args,
            output="screen",
        ),
    ])