# Ridgeback + iiwa Integration

*Tested on **Ubuntu 18.04** with **ROS Melodic**.*

<img src="./doc/img/demo.png" width="600">

This repository provides our customed ridgeback integration with KUKA LBR iiwa 7 R800 based on [ridgeback_manipulation](https://github.com/ridgeback/ridgeback_manipulation). 


## Build and Compile


1. Clone this repository with the recursive option:
  ```sh
  mkdir ros_ws && cd ros_ws && mkdir src
  catkin_init_work_space
  cd src
  git clone --recursive https://github.com/daeunSong/ridgeback_iiwa_integration.git
  ```

2. Install the dependencies:
  ```sh
  cd ..
  rosdep install --from-paths src --ignore-src -r -y
  ```

3. Add a following line in ~/.bashrc:

  `export RIDGEBACK_URDF_EXTRAS=$(catkin_find ridgeback_iiwa_description urdf/ridgeback_iiwa_7_description.urdf.xacro --first-only)`

4. Build the workspace:
  ```sh
  catkin build
  ```

5. Source the workspace:
  ```sh
  source devel/setup.bash
  ```
   You can also add this line in ~/.bashrc, but be aware that this has to be above the line in step 4.


## Demo
Run the following commands in respective terminals.

ridgeback example:
```sh
roslaunch ridgeback_gazebo ridgeback_world.launch
roslaunch ridgeback_navigation odom_navigation_demo.launch
roslaunch ridgeback_viz view_robot.launch config:=navigation
```
iiwa examples:
```sh
roslaunch iiwa_examples iiwa_updown_moveit.launch
```
```sh
roslaunch iiwa_examples iiwa_drawing_moveit.launch
```
