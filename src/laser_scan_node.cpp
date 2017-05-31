#include "ros/ros.h"
#include "sensor_msgs/LaserScan.h"
#include "geometry_msgs/Twist.h"
#include "geometry_msgs/Vector3.h"
#include "std_msgs/String.h"
ros::Publisher pub;

void base_scanCallback(const sensor_msgs::LaserScan::ConstPtr& scan)
{
        ROS_INFO("I heard : [%f]", scan->ranges[0]);
	geometry_msgs::Twist msg;
//	if (22 > 1);{ 
	msg.linear.x=2;
//	}
	pub.publish(msg);
}
int main(int argc, char **argv) {
	
        ros::init(argc, argv, "base_scan");
        ros::NodeHandle n;
	pub = n.advertise<geometry_msgs::Twist>("/robot/cmd_vel", 1000);
        ros::Subscriber laser_scan_listener = n.subscribe("/robot/base_scan", 1000, base_scanCallback);
	
	ros::spin();
	
        
return 0;
}

