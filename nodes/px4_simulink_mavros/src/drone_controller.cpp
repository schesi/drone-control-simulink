/**
 * @file offb_node.cpp
 * @brief Offboard control example node, written with MAVROS version 0.19.x, PX4 Pro Flight
 * Stack and tested in Gazebo SITL
 */
#include <iostream>
#include <ros/ros.h>
#include <geometry_msgs/PoseStamped.h>
#include <mavros_msgs/CommandBool.h>
#include <mavros_msgs/SetMode.h>
#include <mavros_msgs/State.h>
#include "drone_controller.h"
#include <stddef.h>
#include <stdio.h>                     // This ert_main.c example uses printf/fflush
#include "guidance_sub.h"              // Model's header file
#include "rtwtypes.h"
#define FREQUENCY  20.0 	// system frequencys

int main(int argc, char **argv)
{
    ros::init(argc, argv, "guidance_node");
    // define local variables
    QuadGuidance guidance_node;
    ros::Time t0, tk;
    ros::Duration delta_t(55.0);


    geometry_msgs::PoseStamped next_wps;
    double wps[6] = {0,   0,  40,
                    30, -100, 40 };
    bool flag_detect = false;
    //frequency
    ros::Rate rate(FREQUENCY);
    guidance_sub_Obj.initialize();
    //initialize the node
    guidance_node.GuidancePublisher();

    guidance_node.GuidanceSubscriber(&guidance_sub_Obj);
    guidance_node.GuidanceServiceClient();
    guidance_node.Connect(rate);

    next_wps.pose.position.x = 0;
    next_wps.pose.position.y = 0;
    next_wps.pose.position.z = 0;

    //send a few setpoints before starting
    guidance_node.AssignWps(wps,6);

    t0 = ros::Time::now();
    while(ros::ok()){
      // Pretend an object is detected
      tk = ros::Time::now();

      if ((tk-t0)> delta_t){
        ROS_INFO("Object Detected!");

        guidance_node.AssignDetection(true);
        delta_t = ros::Duration(1000);
      }

      guidance_node.CheckStatus();

      // run one step of simulink
      guidance_sub_Obj.step();
      //assign output
      next_wps.pose.position.x = guidance_sub_Obj.guidance_sub_Y.target_pos_xyz[0];
      next_wps.pose.position.y = guidance_sub_Obj.guidance_sub_Y.target_pos_xyz[1];
      next_wps.pose.position.z = guidance_sub_Obj.guidance_sub_Y.target_pos_xyz[2];
      guidance_node.PublishMessage(next_wps);
      //local_pos_pub.publish(pose);
      ros::spinOnce();
      rate.sleep();
    }
    guidance_sub_Obj.terminate();

    return 0;
}
