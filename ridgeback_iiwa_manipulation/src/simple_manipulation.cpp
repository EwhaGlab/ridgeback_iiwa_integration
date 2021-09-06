#include "iiwa_ros/iiwa_ros.hpp"
#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>
#include <ros/package.h>
#include <cmath>
#include <stdio.h>
#include <string>
#include <vector>


using namespace std;
using moveit::planning_interface::MoveItErrorCode;

// Create MoveGroup
static const std::string PLANNING_GROUP = "manipulator";
static const std::string EE_LINK = "iiwa_link_ee";

bool sim;

vector<string> split(string input, char delimiter){
    vector<string> ans;
    stringstream str(input);
    string temp;

    while(getline(str, temp, delimiter)){
        ans.push_back(temp);
    }

    return ans;
}

int main (int argc, char **argv) {
    // Initialize ROS
    ros::init(argc, argv, "SimpleManipulation");
    ros::NodeHandle nh("~");
    nh.param("sim", sim, true);


    // ROS spinner.
    ros::AsyncSpinner spinner(1);
    spinner.start();

    std::string movegroup_name, ee_link;
    geometry_msgs::PoseStamped command_cartesian_position;
    std::string cartesian_position_topic;

    // Dynamic parameters. Last arg is the default value. You can assign these from a launch file.
    nh.param<std::string>("move_group", movegroup_name, PLANNING_GROUP);
    nh.param<std::string>("ee_link", ee_link, EE_LINK);

    // Create Move Group
    moveit::planning_interface::MoveGroupInterface move_group(PLANNING_GROUP);
    moveit::planning_interface::PlanningSceneInterface planning_scene_interface;
    moveit::planning_interface::MoveGroupInterface::Plan my_plan;

    // Configure Move Group
    move_group.setPlanningTime(0.5);
    move_group.setPlannerId(PLANNING_GROUP+"[RRTConnectkConfigDefault]");
    move_group.setEndEffectorLink(ee_link);
    ROS_INFO("Planning frame: %s", move_group.getPlanningFrame().c_str());
    ROS_INFO("End effector link: %s", move_group.getEndEffectorLink().c_str());

    // Dynamic parameter to choose the rate at wich this node should run
    double ros_rate;
    nh.param("ros_rate", ros_rate, 0.1); // 0.1 Hz = 10 seconds
    ros::Rate* loop_rate_ = new ros::Rate(ros_rate);

    int direction = 1;
    MoveItErrorCode success_plan = MoveItErrorCode::FAILURE, motion_done = MoveItErrorCode::FAILURE;

    while (ros::ok()){
        ros::Duration(5).sleep(); // wait for 5 sec
        ROS_INFO("Sleeping 5 seconds before starting ... ");

        command_cartesian_position = move_group.getCurrentPose(ee_link);
        command_cartesian_position.pose.position.z -= direction * 0.10;

        move_group.setStartStateToCurrentState();
        move_group.setPoseTarget(command_cartesian_position, ee_link);
        success_plan = move_group.plan(my_plan);
        if (success_plan == MoveItErrorCode::SUCCESS) {
            motion_done = move_group.execute(my_plan);
        }
        if (motion_done == MoveItErrorCode::SUCCESS) {
            direction *= -1; // In the next iteration the motion will be on the opposite direction
            ros::Duration(1).sleep(); // wait for 1 sec
        }
    }

    cerr<<"Stopping spinner..."<<endl;
    spinner.stop();

    cerr<<"Bye!"<<endl;

    return 0;
}
