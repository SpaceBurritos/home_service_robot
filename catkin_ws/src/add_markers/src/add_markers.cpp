#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <nav_msgs/Odometry.h>
#include <std_msgs/Int8.h>

int action = 0;
void callback(const std_msgs::Int8::ConstPtr& msg){

 action = msg->data;

}

int main( int argc, char** argv )
{
  ros::init(argc, argv, "visualization_marker");
  ros::NodeHandle n;
  ros::Rate r(1);

  ros::Subscriber sub_pick = n.subscribe("robot_action",1,callback);
  ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker",1);

  // Set our initial shape type to be a cube
  uint32_t shape = visualization_msgs::Marker::CUBE;


  while (ros::ok())
  {
    ros::spinOnce();
    visualization_msgs::Marker marker;
    visualization_msgs::Marker marker_2;

    // Set the frame ID and timestamp.  See the TF tutorials for information on these.
    marker.header.frame_id = "map";
    marker.header.stamp = ros::Time::now();
    marker_2.header.frame_id = "map";
    marker_2.header.stamp = ros::Time::now();

    // Set the namespace and id for this marker.  This serves to create a unique ID
    // Any marker sent with the same namespace and id will overwrite the old one
    marker.ns = "basic_shapes";
    marker.id = 0;
    marker_2.ns = "basic_shapes";
    marker_2.id = 2;

    // Set the marker type.  Initially this is CUBE, and cycles between that and SPHERE, ARROW, and CYLINDER
    marker.type = shape;
    marker_2.type = shape;

    // Set the marker action.  Options are ADD, DELETE, and new in ROS Indigo: 3 (DELETEALL)
    marker.action = visualization_msgs::Marker::ADD;
    marker_2.action = visualization_msgs::Marker::ADD;

    // Set the pose of the marker.  This is a full 6DOF pose relative to the frame/time specified in the header
    marker.pose.position.x = 2.9;
    marker.pose.position.y = 12;
    marker.pose.position.z = 0;
    marker.pose.orientation.x = 0;
    marker.pose.orientation.y = 0;
    marker.pose.orientation.z = 0;
    marker.pose.orientation.w = 1;
    marker_2.pose.position.x = 4;
    marker_2.pose.position.y = 0;
    marker_2.pose.position.z = 0;
    marker_2.pose.orientation.x = 0;
    marker_2.pose.orientation.y = 0;
    marker_2.pose.orientation.z = 0;
    marker_2.pose.orientation.w = 1;

    // Set the scale of the marker -- 1x1x1 here means 1m on a side
    marker.scale.x = 0.5;
    marker.scale.y = 0.5;
    marker.scale.z = 0.5;
    marker_2.scale.x = 0.5;
    marker_2.scale.y = 0.5;
    marker_2.scale.z = 0.5;

    // Set the color -- be sure to set alpha to something non-zero!
    marker.color.r = 0.0f;
    marker.color.g = 0.0f;
    marker.color.b = 1.0f;
    marker.color.a = 1.0;
    marker_2.color.r = 0.0f;
    marker_2.color.g = 1.0f;
    marker_2.color.b = 0.0f;
    marker_2.color.a = 1.0;

    marker.lifetime = ros::Duration();
    marker_2.lifetime = ros::Duration();

    // Publish the marker
    while (marker_pub.getNumSubscribers() < 1)
    {
      if (!ros::ok())
      {
        return 0;
      }
      ROS_INFO("Please create a subscriber to the marker");
      sleep(1);
    }
    ROS_INFO("%i", action);
    if (action == 1){
    marker.action = visualization_msgs::Marker::ADD;
    marker_pub.publish(marker);
    ROS_INFO("Going to the PickUp Zone");
    //ROS::Duration(10)::sleep();
    } else if (action == 3){
    marker_2.action = visualization_msgs::Marker::ADD;
    marker_pub.publish(marker_2);
    ROS_INFO("Going to the Drop Off Zone");
    } else if (action ==2 || action == 4) {
      ROS_INFO("Interacting with the Object");
      marker.action = visualization_msgs::Marker::DELETE;
      marker_2.action = visualization_msgs::Marker::DELETE;
      marker_pub.publish(marker);
      marker_pub.publish(marker_2);
    } else { 
      ROS_INFO("error");
    }
    r.sleep();
  }
}
