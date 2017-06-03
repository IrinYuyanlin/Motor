#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include<iostream>
#include<sys/io.h>
#include<stdio.h>
#include<ctime>

unsigned int indexp = 0x4e;
unsigned int datap = 0x4f;
unsigned char temp;
int quit = 1;

void MotorController(bool value, int direction)
{
    if (value == true)
    {
        std::cout << "Motor function work!" << std::endl;
        bool quit = true;
        switch (direction)
        {
        case 1:
        {
            while (quit)
            {
                std::cout << "forward!" << std::endl;
                outb(0xf0, indexp);
                temp = (unsigned char)inb(datap);
                temp &= 0x00;
                outb(temp, datap);
                outb(0xf1, indexp);
                temp = (unsigned char)inb(datap);
                temp |= 0xff;
                outb(temp, datap);
                usleep(50);

                outb(0xf0, indexp);
                temp = (unsigned char)inb(datap);
                temp &= 0x00;
                outb(temp, datap);
                outb(0xf1, indexp);
                temp = (unsigned char)inb(datap);
                temp |= 0x00;
                outb(temp, datap);
                usleep(50);
            }
        }
        case 2:
        {
            while (quit)
            {
                std::cout << "left" << std::endl;
                outb(0xf0, indexp);
                temp = (unsigned char)inb(datap);
                temp &= 0xf0;
                outb(temp, datap);
                outb(0xf1, indexp);
                temp = (unsigned char)inb(datap);
                temp |= 0x00;
                outb(temp, datap);
                usleep(50);

                outb(0xf0, indexp);
                temp = (unsigned char)inb(datap);
                temp &= 0xf0;
                outb(temp, datap);
                outb(0xf1, indexp);
                temp = (unsigned char)inb(datap);
                temp |= 0x0f;
                outb(temp, datap);
                usleep(50);
            }
        }
        case 3:
        {
            while (quit)
            {
                std::cout << "right" << std::endl;
                outb(0xf0, indexp);
                temp = (unsigned char)inb(datap);
                temp &= 0x0f;
                outb(temp, datap);
                outb(0xf1, indexp);
                temp = (unsigned char)inb(datap);
                temp |= 0x00;
                outb(temp, datap);
                usleep(50);

                outb(0xf0, indexp);
                temp = (unsigned char)inb(datap);
                temp &= 0x0f;
                outb(temp, datap);
                outb(0xf1, indexp);
                temp = (unsigned char)inb(datap);
                temp |= 0xf0;
                outb(temp, datap);
                usleep(50);
            }
        }
        }
    }
    else
    {
        std::cout << "Stop!";
    }
}

int caluint(int num)
{
	int ans = num + 22;
	std::cout << "test sucessful: " << ans;
	return ans;
}

void command_callback(const std_msgs::Int32::ConstPtr& msg)
{
	ROS_INFO("Receive: [%d]", msg->data);
	int ans;
	ans = caluint(msg->data);
    bool value = true;
    MotorController(value, msg->data);
}

int main(int argc,char **argv)
{
    iopl(3);
    // init GPIO
    outb(0x87, indexp);
    outb(0x87, indexp);
    outb(0x07, indexp);
    outb(0x09, datap);
    outb(0x2c, indexp);
    temp = (unsigned char)inb(datap);
    temp = 0x1f;
    //    temp = 0x03;
    outb(temp, datap);
    outb(0x30, indexp);
    outb(0x02, datap);

	ros::init(argc, argv, "motorcontroll");
	ros::NodeHandle node_obj2;
	ros::Subscriber motor_sub = node_obj2.subscribe("/command", 5, command_callback);

	ros::spin();
	return 0;
}
