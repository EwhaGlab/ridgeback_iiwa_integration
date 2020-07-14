# Ridgeback + iiwa Integration

This repository provides the ridgeback + iiwa integrated description files with a simple demo in ros gazebo.


## Installation
1. add a following line in ~/.bashrc

`export RIDGEBACK_URDF_EXTRAS=$(catkin_find ridgeback_iiwa_description urdf/ridgeback_iiwa_7_description.urdf.xacro --first-only)`

2. move the zip files into the ROS workspace folder

3. install dependent package
```sh
sudo apt-get install ros-kinetic-lms1xx
```

4. build the package
```sh
catkin build
```


## Demo
```sh
roslaunch ridgeback_description description.launch
```
