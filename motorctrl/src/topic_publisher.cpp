#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include<iostream>

int main(int argc, char **argv)
{
	ros::init(argc, argv, "motorcommand");
	ros::NodeHandle node_obj;
	ros::Publisher command_pub = node_obj.advertise<std_msgs::Int32>("/command", 5);
	ros::Rate loop_rate(10);
	int command = 0;
	while(ros::ok())
	{
		std_msgs::Int32 msg;
		std::cout << "please input a key to control machine:\n"
		<< "'1' for forwar, '2' for turn left, '3' for turn right."
		<< std::endl;
		std::cin >> command;
		std::cout << "You input: " << command << std::endl;
		msg.data = command;
		command_pub.publish(msg);
		ros::spinOnce();
		loop_rate.sleep();
		
	}
}
