# Home Service Robot

Final project on the Robotic Software Engineer Nanodegree of Udacity.  

__Steps to initialization__  
  
  
  1. Download the file in /home/workspace and uncompress the map.pgm.tar.gz file found in ~/src/pick_objects/map/
  2. Go to: cd /home/workspace/catkin_ws , and type: catkin_make
  3. While on catkin_ws type: source devel/setup.bash
  4. Then type: cd /src/scripts , and type: ./home_service.sh

__Packages__

For this projects several ROS packages were used, they were:

  1.turtlebot_gazebo: 
gmapping: With the gmapping_demo.launch file, you can easily perform SLAM and build a map of the environment with a robot equipped with laser range finder sensors or RGB-D cameras.
turtlebot_teleop: With the keyboard_teleop.launch file, you can manually control a robot using keyboard commands.
turtlebot_rviz_launchers: With the view_navigation.launch file, you can load a preconfigured rviz workspace. You’ll save a lot of time by launching this file, because it will automatically load the robot model, trajectories, and map for you.
turtlebot_gazebo: With the turtlebot_world.launch you can deploy a turtlebot in a gazebo environment by linking the world file to it.
