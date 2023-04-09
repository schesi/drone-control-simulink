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

All the nodes in the catkin workspace should be symbolic lynks. Doing so allows great flexibility since each node can be easily added or removed without the need to commit changes to the repository. For example let's go into the catkin source folder by typing
```
cd ~/catkin_ws/src
```
If you don't have this environment setup please follow the instructions here [link](http://wiki.ros.org/ROS/Tutorials/InstallingandConfiguringROSEnvironment)

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
