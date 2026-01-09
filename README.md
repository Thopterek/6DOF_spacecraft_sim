# 6DOF Spacecraft Simulation

## Project overview
* Base for using NASA Tick in combination with ROS2 and SPACE ROS
  * [Tick](https://github.com/nasa/trick) allowing for simulation of space scenarios
  * [ROS](https://github.com/ros2/ros2) as a way to implement control/autonomy stack
* Backbone for projects combining from Bare Metal development to ML integration 

## Repository Structure

* trick/ros_base directories as notes and code going through their individual concepts
  * based on chapters / concepts
  * each with smaller README.md about them
* attitude_determination_and_control for fundamental concepts and mathematical basis
* spacecraft directory the end goal of this project, combining those technologies

## Sources

* [NASA Trick](https://nasa.github.io/trick/) documentation
* [SPACE ROS](https://space-ros.github.io/docs/rolling/index.html) documentation
* [ROS2 Jazzy](https://docs.ros.org/en/jazzy/index.html) documentation
* Markley & Crassidis – Fundamentals of Spacecraft Attitude Determination and Control

## Non-Goals
This project does NOT aim to:
- Replace flight software or RTOS-based control systems
- Provide real-time guarantees beyond simulation fidelity
- Act as a full mission simulator or ground system

## Possible addition
* NASA’s Genesis (Julia) and Copernicus
* Jenkins testing
* MoveIt2 for planning
