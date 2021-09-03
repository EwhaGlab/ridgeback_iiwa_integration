# Demo

Run the following commands in respective terminals.

If you are using simulation, bring up Ridgeback with iiwa in Gazebo:
```shell
roslaunch ridgeback_iiwa_gazebo ridgeback_iiwa_gazebo.launch [world_name:=/path/to/my/world.world]
```

## Navigation

### Navigation without a map
<img src="./doc/img/navigation1.png" width="600">

```sh
roslaunch ridgeback_iiwa_navigation odom_navigation.launch
```
In this demonstration, it takes in information from **odometry**, laser scanner, and a goal pose and outputs safe velocity commands for navigation.


### Making a map
<img src="./doc/img/navigation2.png" width="600">

```
roslaunch ridgeback_iiwa_navigation gmapping.launch
```
In this demonstration, Ridgeback generates a map using gmapping. You must slowly drive Ridgeback around to build the map. 

When you are satisfied, you can save the produced map using map saver:
```sh
rosrun map_server map_saver -f mymap
```
This will creat a `mymap.yaml` and `mymap.pgm` files in the directory where you ran the map saver.


### Navigation with a map
<img src="./doc/img/navigation3.png" width="600">

```sh
roslaunch ridgeback_iiwa_navigation amcl_navigation.launch [map_file:=/path/to/my/map.yaml]
```
Using **amcl**, Ridgeback is able to globally localize itself in a known map. AMCL takes in information from odometry, laser scanner and an existing map and estimates the robot's pose.

With 2D Pose Estimate and 2D Nav Goal button, navigate through the goal position.



## Manipulation

### Manipulation using an interactive marker 
<img src="./doc/img/manipulation1.png" width="600">

```shell
roslaunch ridgeback_iiwa_manipulation interactive_manipulation.launch
```

In this demonstration, we launch **move_group** for planning the manipulator. Through rviz, you can manipulate the manipulator.

### Simple manipulation by code
<img src="./doc/img/manipulation2.gif" width="600">

```shell
roslaunch ridgeback_iiwa_manipulation simple_manipulation.launch
```

In this demonstration, we launch **move_group** for planning the manipulator. And we call the ROS node we have written, in this case, to move up and down.


## Navigating with manipulation
<img src="./doc/img/manipulation_w_navigation.gif" width="600">

This is a simple example that shows navigating with manipulation. The whole point is to launch just one node for **move_group**, **move_base**, **robot_state_publisher**, and **rviz** each. 

```shell
roslaunch ridgeback_iiwa_navigation odom_navigation.launch open_rviz:=false
roslaunch ridgeback_iiwa_manipulation manipulation_w_navigation.launch
```

Then, run the nodes for executing ridgeback and iiwa.

```
rosrun ridgeback_examples teleop_key.py
rosrun ridgeback_iiwa_manipulation simple_manipulation
```
