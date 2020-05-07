# Home Service Robot

Final project on the Robotic Software Engineer Nanodegree of Udacity.  

__Steps to initialization__  
  
  
  1. Download the file in /home/workspace and uncompress the map.pgm.tar.gz file found in ~/src/pick_objects/map/
  2. Go to: cd /home/workspace/catkin_ws , and type: catkin_make
  3. While on catkin_ws type: source devel/setup.bash
  4. Then type: cd /src/scripts , and type: ./home_service.sh

__Packages__

For this projects several ROS packages were used, they were:

 1. turtlebot_gazebo: is used to link the turtlebot to a gazebo environment with the turtlebot_world.launch file. It also includes a localization system, through the use of an Adaptive Monte Carlo Localization algorithm with the amcl_demo.launch. And it has a mapping system with the gmapping_demo launch.
 2. turtlebot_rviz_launchers: it loads an rviz with preconfigured settings.
 3. turtlebot_teleop: with the ps3_teleop.launch, xbox360_teleop.launch and keyboard_teleop.launch the turtlebot can be controlled.
