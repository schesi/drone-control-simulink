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
catkin_make
```
If you don't have this environment setup please follow the instructions here [link](http://wiki.ros.org/ROS/Tutorials/InstallingandConfiguringROSEnvironment).Please use the same environment as described in the tutorial.

Now download the repository of PX4 from this [link](https://github.com/PX4/PX4-Autopilot) in the **~/git_repos/** folder by typing
```
git clone https://github.com/PX4/PX4-Autopilot.git --recursive
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
