#include <sys/io.h>
#include <stdio.h>
#include <ros/ros.h>
#include <std_msgs/String.h>

extern unsigned int indexp = 0x4e;
extern unsigned int datap = 0x4f;
extern unsigned char temp;
extern int quit = 1;
iopl(3);
//init GPIO
outb(0x87, indexp);
outb(0x87, indexp);

outb(0x07, indexp);
outb(0x09, datap);

outb(0x2c, indexp);
temp = (unsigned char)inb(datap);
temp = 0x1f;
//	temp = 0x03;
outb(temp, datap);

outb(0x30, indexp);
outb(0x02, datap);

void MotorController(bool value, int direction)
{
	if (value == true)
	{
		bool quit = true;
		switch direction
		{
		case 1:
		{
			while (quit)
			{
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
	else
		{
			std::cout << "Stop!";
		}
	}
}

void ControlCallback(const std_msgs::String::ConstPtr& command)
{
	char msg[3] = command->data.c_str();
	ROS_INFO("I heard: [%s]", msg);
	bool value = (bool)msg[0];
	int direction = (int)msg[1];
	MotorController(value, direction);
}

int main(int argc, char** argv)
{
	ros::init(argc, argv, "Controller");
	ros::NodeHandle n;
	ros::Subscriber sub = n.subscribe("command", 3, ControlCallback);
	ros::spin();
}