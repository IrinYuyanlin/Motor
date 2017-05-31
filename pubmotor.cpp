#include "ros/ros.h"
#include "std_msgs/String.h"
#include<sys/io.h>
#include<stdio.h>
#include<iostream>

class RobotDriver
{
private:
	ros::NodeHandle nh_;
	ros::Publisher cmd_;
	
public:
	RobotDriver(ros::NodeHandle &nh)
	{
		nh_ = nh;
		cmd_ = nh.advertise<std_msgs::String>("command", 3);
	}
	
	bool driveMotor()
	{
		while (nh_.ok())
		{
			std::cout << "type '+/-' and '1/2/3' to move forward"
				"/backward and straight/left/right";
			std_msgs::String command;
			std::cin.getline(str, 3);
			command.data = str;
			cmd_.publish(command);
		}
		return true;
	}
};

int main(int argc, char** argv)
{
	ros::init(argc, argv, "robot_command");
	rosNodeHandle nh;
	ros::Rate loop_rate(10);
	RobotDriver driver(nh);
	driver.driveMotor();
	ros::spinOnce();
}