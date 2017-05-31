#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "geometry_msgs/Vector3.h"

int main(int argc, char**argv){
        ros::init(argc, argv, "node1");
        ros::NodeHandle n;
        ros::Publisher pub = n.advertise<geometry_msgs::Twist>("chatter", 1000);

        ros::Rate Loop_rate(10);

        while(ros::ok()){
                geometry_msgs::Twist msg;
                msg.linear.x=4;
                pub.publish(msg);
                ros::spinOnce();
                Loop_rate.sleep();
        }

        return 0;

void chatterCallback(const geometry_msgs::Twist::ConstPtr& msg)
{
        ROS_INFO("I heard : [%f]", msg->linear.x);
}

int main(int argc, char **argv) {

        ros::init(argc, argv, "listener");
        ros::NodeHandle n;
        ros::Subscriber chatter_pub = n.subscribe("chatter", 1000, chatterCallback);

ros::spin();
return 0;
}


}
