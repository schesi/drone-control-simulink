#include "drone_controller.h"


QuadGuidance::QuadGuidance(){
  data = new guidance_subModelClass();
  last_request = ros::Time::now();

}

QuadGuidance::~QuadGuidance(){

}

void QuadGuidance::AssignDetection(bool flag){

  data->guidance_sub_U.flag_detect = flag;

}

void QuadGuidance::Connect(ros::Rate& rate){
  ROS_INFO("Connecting to FCU...");
  while(ros::ok() && !current_state.connected){
      ros::spinOnce();
      rate.sleep();
  }
  ROS_INFO("FCU...connected!");
  offb_set_mode.request.custom_mode = "OFFBOARD";
  arm_cmd.request.value = true;
}

void QuadGuidance::CheckStatus(){
  if( current_state.mode != "OFFBOARD" &&
      (ros::Time::now() - last_request > ros::Duration(5.0))){
      if( set_mode_client.call(offb_set_mode) &&
          offb_set_mode.response.mode_sent){
          ROS_INFO("Offboard activated!");
      }
      last_request = ros::Time::now();
  } else {
      if( !current_state.armed &&
          (ros::Time::now() - last_request > ros::Duration(5.0))){
          if( arming_client.call(arm_cmd) &&
              arm_cmd.response.success){
              ROS_INFO("Drone_01 armed");
          }
          last_request = ros::Time::now();
      }
  }

}
void QuadGuidance::AssignWps(double *wps,int size){
  //assign the wps
  for(int i=0;i<size;i++){
    data->guidance_sub_U.wps[i] = wps[i];

  }

}
void QuadGuidance::state_cb(const mavros_msgs::State::ConstPtr& msg){
  current_state = *msg;
}

void QuadGuidance::read_pose(const geometry_msgs::PoseStamped::ConstPtr& msg){
  current_pose = *msg;

  //assign input
  data->guidance_sub_U.pos_xyz[0] = current_pose.pose.position.x;
  data->guidance_sub_U.pos_xyz[1] = current_pose.pose.position.y;
  data->guidance_sub_U.pos_xyz[2] = current_pose.pose.position.z;

}

void QuadGuidance::GuidancePublisher(){
  local_pos_pub = nh.advertise<geometry_msgs::PoseStamped>
          ("drone_01/mavros/setpoint_position/local", 1);
}

void QuadGuidance::PublishMessage(geometry_msgs::PoseStamped pose){
  local_pos_pub.publish(pose);
}

void QuadGuidance::GuidanceSubscriber(guidance_subModelClass* simulink_Obj){
  data = simulink_Obj;
  current_state_sub = nh.subscribe<geometry_msgs::PoseStamped>
          ("/drone_01/mavros/local_position/pose",1,&QuadGuidance::read_pose,this);
  state_sub = nh.subscribe<mavros_msgs::State>
          ("drone_01/mavros/state", 10, &QuadGuidance::state_cb,this);

}

void QuadGuidance::GuidanceServiceClient(){
  arming_client = nh.serviceClient<mavros_msgs::CommandBool>
          ("drone_01/mavros/cmd/arming");

  set_mode_client = nh.serviceClient<mavros_msgs::SetMode>
                  ("drone_01/mavros/set_mode");

}
