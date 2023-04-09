#ifndef DRONECONTROLLER_H_
#define DRONECONTROLLER_H_

#include <iostream>
#include <ros/ros.h>
#include <geometry_msgs/PoseStamped.h>
#include <mavros_msgs/CommandBool.h>
#include <mavros_msgs/SetMode.h>
#include <mavros_msgs/State.h>
#include <stddef.h>
#include <stdio.h>                     // This ert_main.c example uses printf/fflush
#include "guidance_sub.h"              // Model's header file
#include "rtwtypes.h"




static guidance_subModelClass guidance_sub_Obj;// Instance of model class
class QuadGuidance{

public:
	QuadGuidance();
	~QuadGuidance();
	void GuidancePublisher();
	void GuidanceSubscriber(guidance_subModelClass* simulink_Obj);
	void GuidanceServiceClient();
	void read_pose(const geometry_msgs::PoseStamped::ConstPtr& msg);
	void state_cb(const mavros_msgs::State::ConstPtr& msg);
	void Connect(ros::Rate& rate);
	void PublishMessage(geometry_msgs::PoseStamped pose);
	void CheckStatus();
	void AssignWps(double *wps,int size);
	void AssignDetection(bool flag);
	/** void AutopilotSubscriber(collision_detection_templateModelClass* simulink_Obj);
	void AutopilotPublisher();
	void AutopilotPublishMessage(collision_detection_templateModelClass data_out);
	void AutopilotReadSensorsBus(const collision_detection_node::sensor_bus sensor_bus_read);
	void AutopilotReadCourseAndBankCommands(const collision_detection_node::course_bank_commands_bus course_and_bank_commands_read);
  **/

private:
	ros::NodeHandle nh;
	ros::Publisher local_pos_pub;
	ros::Subscriber current_state_sub;
	ros::Subscriber state_sub;
	ros::ServiceClient arming_client;
	ros::ServiceClient set_mode_client;
	geometry_msgs::PoseStamped current_pose;
	mavros_msgs::State current_state;
	ros::Time last_request;
	mavros_msgs::SetMode offb_set_mode;
	mavros_msgs::CommandBool arm_cmd;
	guidance_subModelClass *data;
	//ros::Rate rate(20);
	/** ros::NodeHandle node_handle;
	ros::Publisher 	control_bus_pub;
	ros::Subscriber sensor_bus_sub;
	ros::Subscriber course_and_bank_command_sub;

	collision_detection_node::sensor_bus sensor_bus;
	collision_detection_node::control_bus control_bus;
	collision_detection_node::course_bank_commands_bus course_and_bank_commands;
	collision_detection_templateModelClass *data;

	// publisher and subscribers topics names
	std::string sensor_bus_topic_name;
	std::string control_commands_topic_name;
	std::string control_bus_topic_name;
  */
};


#endif
