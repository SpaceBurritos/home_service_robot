#!/bin/sh

export ROBOT_INITIAL_POSE="-x 22 -y 4 -Y 0"

xterm -e " roslaunch turtlebot_gazebo turtlebot_world.launch world_file:=$(rospack find pick_objects)/worlds/myWorld.world" &
sleep 5
xterm -e " roslaunch turtlebot_gazebo amcl_demo.launch map_file:=$(rospack find pick_objects)/map/map.yaml" &
sleep 5
xterm -e " roslaunch turtlebot_rviz_launchers view_navigation.launch " &
sleep 5
xterm -e " rosrun add_markers add_markers"
