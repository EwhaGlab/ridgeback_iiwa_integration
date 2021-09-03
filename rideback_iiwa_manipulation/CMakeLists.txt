cmake_minimum_required(VERSION 2.8.3)
project(ridgeback_iiwa_manipulation)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  iiwa_ros
  moveit_core
  moveit_ros_planning
  moveit_ros_planning_interface
  moveit_visual_tools
)

catkin_package()

install(
DIRECTORY launch rviz
DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)

include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(simple_manipulation src/simple_manipulation.cpp)
add_dependencies(simple_manipulation iiwa_msgs_generate_messages_cpp)
target_link_libraries(simple_manipulation ${catkin_LIBRARIES})
