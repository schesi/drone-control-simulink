# Drone Control via Matlab  & Simulink in ROS Gazebo
This repository contains the code related to the operation of a quadcopert in a 3D virtual world via a guidance algorithm designed in Simulink and then translated in C++ via autocode generation procedure.
This guidance algorithm will make the quadcopter perform a search between two waypoints and then a simulated detection is assumed after a certain amount of time.
Specifically this repository includes:
 - The Simulink model of the guidance algorithm
 - The ROS node that initialize the 3D simulator
 - The ROS node that contains the C++ code generated via simulink autocode

## Repository Structure

## Simulator setup
