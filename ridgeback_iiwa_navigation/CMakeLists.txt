cmake_minimum_required(VERSION 2.8.3)
project(ridgeback_iiwa_navigation)

find_package(catkin REQUIRED COMPONENTS roslaunch)

catkin_package()

install(
DIRECTORY launch maps params
DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)

if(CATKIN_ENABLE_TESTING)
  find_package(roslaunch REQUIRED)
  roslaunch_add_file_check(launch/odom_navigation.launch)
  roslaunch_add_file_check(launch/gmapping.launch)
  roslaunch_add_file_check(launch/amcl_navigation.launch)

endif()
