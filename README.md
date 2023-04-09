# Drone Control via Matlab  & Simulink in ROS Gazebo
This repository contains the code related to the operation of a quadcopert in a 3D virtual world via a guidance algorithm designed in Simulink and then translated in C++ via autocode generation procedure.
This guidance algorithm will make the quadcopter perform a search between two waypoints and then a simulated detection is assumed after a certain amount of time.
Specifically this repository includes:
 - The Simulink model of the guidance algorithm
 - The ROS node that initialize the 3D simulator
 - The ROS node that contains the C++ code generated via simulink autocode

## Repository Structure

## Simulator setup
The first step (if not done already) is to setup the ROS environment. The instruction on how to setup ROS invironment can be found at this [link](http://wiki.ros.org/ROS/Tutorials/InstallingandConfiguringROSEnvironment).



### Installing dependencies
First let's install mavros by typing
```
sudo apt-get install ros-noetic-mavros ros-noetic-mavros-extras
```
Install the geographic libraries
```
wget https://raw.githubusercontent.com/mavlink/mavros/master/mavros/scripts/install_geographiclib_datasets.sh
sudo bash ./install_geographiclib_datasets.sh   
```

Now you need to download this repository into **~/git_repos** folder. It would make your life easier later.

We now need to link the nodes from the **drone-control-simulink** repository (I am very tired and not a lot of fantasy in choosing names) to our local ROS environment.

The ROS environment is what allows us to compile the code inside the nodes. Usually this code is then compiled and the environment variables are stored in the system. If the environment setting has been deleted it is possible to set it back again using the following steps. Let’s type the following command the the terminal:
```
mkdir -p ~/catkin_ws/src
cd ~/catkin_ws/
catkin build
```
If you don't have this environment setup please follow the instructions at this [link](http://wiki.ros.org/ROS/Tutorials/InstallingandConfiguringROSEnvironment). Please use the same environment as described in the tutorial.

Now download the repository of PX4 from this [link](https://github.com/PX4/PX4-Autopilot) in the **~/git_repos/** folder by typing
```
cd ~/git_repos/
git clone https://github.com/PX4/PX4-Autopilot.git --recursive
```
Also if you don't have the catkin tools installed you can do that by doing
```
sudo apt-get update
sudo apt-get install python3-catkin-tools
```

### Compiling ROS Nodes
The first step is to link the simulator folder to the **catkin_w** workspace. In order to do this type
```
cd ~/catkin_ws/src
```
now we need to create a symbolic link with the folder containing the drone simulator code. This can be done by typing
```
ln -s ~/git_repos/drone-control-simulink/nodes/flight_simulator/
```
and
```
ln -s ~/git_repos/drone-control-simulink/nodes/px4_simulink_mavros/
```
now type
```
catkin build
```
you should see something like
```
build] Found 2 packages in 0.0 seconds.                                       
[build] Updating package table.                                                
Starting  >>> catkin_tools_prebuild                                            
Finished  <<< catkin_tools_prebuild                [ 1.0 seconds ]             
Starting  >>> flight_simulator                                                 
Starting  >>> px4_simulink_mavros                                              
Finished  <<< flight_simulator                     [ 1.1 seconds ]             
Finished  <<< px4_simulink_mavros                  [ 3.1 seconds ]             
[build] Summary: All 3 packages succeeded!                                     
[build]   Ignored:   None.                                                     
[build]   Warnings:  None.                                                     
[build]   Abandoned: None.                                                     
[build]   Failed:    None.                                                      
[build] Runtime: 4.1 seconds total.                                            
[build] Note: Workspace packages have changed, please re-source setup files to use them.
simone@devpc:~/catkin_ws$
```
### Activating the Simulator Node
First we will activate the simulator node. This step can be done by following the instruction at this [link](https://docs.px4.io/main/en/simulation/ros_interface.html). Where the following commands should be issued:
```
cd ~/git_repos/PX4-Autopilot
source ~/catkin_ws/devel/setup.bash    # (optional)
source Tools/simulation/gazebo-classic/setup_gazebo.bash $(pwd) $(pwd)/build/px4_sitl_default
export ROS_PACKAGE_PATH=$ROS_PACKAGE_PATH:$(pwd)
export ROS_PACKAGE_PATH=$ROS_PACKAGE_PATH:$(pwd)/Tools/simulation/gazebo-classic/sitl_gazebo-classic
```
Furthermore the ground station control software QgroundControl should be launched. The file is located at [link](https://docs.qgroundcontrol.com/master/en/getting_started/download_and_install.html). Now you need to type
```
roslaunch flight_simulator single_quadcopter_baylands.launch
```
