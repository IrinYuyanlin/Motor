/************************************************************************
* Demo Program for W83627DHG GP30-37 4E/4F port 
* Mainboard:MITX-6960，BPC-7940,BPC-7942
*  GPIO   PIN	  PIN  GPIO   
*  3.3V  --A1     A6  --GP34    
*  GP30  --A2     A7  --GP35
*  GP31  --A3     A8  --GP36
*  GP32  --A4     A9  --GP37
*  GP33  --A5     A10 --GND 
************************************************************************/
#include <sys/io.h>
#include <stdio.h>

unsigned int indexp = 0x4e;
unsigned int datap = 0x4f;

main()
{
   char key[5] = {0};
   unsigned char temp;
   int quit = 1;
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
   
   /* Read/Write Data */
   printf("please input '2,0' + 'enter' to set pinA2(GPIO30) to output pins low level, and '2,1' + 'enter' to high level\n");
   printf("       input '3,0' + 'enter' to set pinA3(GPIO31) to output pins low level, and '3,1' + 'enter' to high level\n");
   printf("       input '4,0' + 'enter' to set pinA4(GPIO32) to output pins low level, and '4,1' + 'enter' to high level\n");
   printf("please input '5,0' + 'enter' to set pinA5(GPIO33) to output pins low level, and '5,1' + 'enter' to high level\n");
   printf("       input '6,0' + 'enter' to set pinA6(GPIO34) to output pins low level, and '6,1' + 'enter' to high level\n");
   printf("       input '7,0' + 'enter' to set pinA7(GPIO35) to output pins low level, and '7,1' + 'enter' to high level\n");
   printf("       input '8,0' + 'enter' to set pinA8(GPIO36) to output pins low level, and '8,1' + 'enter' to high level\n");
   printf("       input '9,0' + 'enter' to set pinA9(GPIO37) to output pins low level, and '9,1' + 'enter' to high level\n");
   printf("       input 'all,0' + 'enter' to set PinA2-9 to output pins low level '0'\n");
   printf("       input 'all,1' + 'enter' to set PinA2-9 to output pins high level '1'\n");
   printf("please input 'rd1' + 'enter' read PinA2(GPIO30) the GPIO(input) pins\n");
   printf("       input 'rd2' + 'enter' read PinA3(GPIO31) the GPIO(input) pins\n");
   printf("       input 'rd3' + 'enter' read PinA4(GPIO32) the GPIO(input) pins\n");
   printf("please input 'rd4' + 'enter' read PinA5(GPIO33) the GPIO(input) pins\n");
   printf("       input 'rd5' + 'enter' read PinA6(GPIO34) the GPIO(input) pins\n");
   printf("       input 'rd6' + 'enter' to read PinA7(GPIO35) the GPIO(input) pins\n");
   printf("       input 'rd7' + 'enter' to read PinA8(GPIO36) the GPIO(input) pins\n");
   printf("       input 'rd8' + 'enter' to read PinA9(GPIO37) the GPIO(input) pins\n");
   printf("       input 'rda' + 'enter' to read PinA2-9 the GPIO(input) pins\n");
   printf("       input 'qt' + 'enter' to quit:\n");

   while(quit)
   {
   scanf("%s", key);
   switch(key[0])
   {
      case '2': /* Pin1 GP30 */
   	outb(0xf0, indexp);
	temp = (unsigned char)inb(datap);
	temp &=0xfe;
	outb(temp, datap);
         if (key[2] == '1')
         {
   		outb(0xf1, indexp);
		temp = (unsigned char)inb(datap);
		temp |=0x01;
		outb(temp, datap);
         }
         else
         {
   		outb(0xf1, indexp);
		temp = (unsigned char)inb(datap);
		temp &=0xfe;
		outb(temp, datap);
         }
         break;
      case '3': /* Pin3 GP31 */
   	outb(0xf0, indexp);
	temp = (unsigned char)inb(datap);
	temp &= 0xfd;
	outb(temp, datap);
         if (key[2] == '1')
         {
   		outb(0xf1, indexp);
		temp = (unsigned char)inb(datap);
		temp |=0x02;
		outb(temp, datap);
         }
         else
         {
   		outb(0xf1, indexp);
		temp = (unsigned char)inb(datap);
		temp &=0xfd;
		outb(temp, datap);
         }
         break;
      case '4': /* Pin5 GP32 */
   	outb(0xf0, indexp);
	temp = (unsigned char)inb(datap);
	temp &=0xfb;
	outb(temp, datap);
         if (key[2] == '1')
         {
   		outb(0xf1, indexp);
		temp = (unsigned char)inb(datap);
		temp |=0x04;
		outb(temp, datap);
         }
         else
         {
   		outb(0xf1, indexp);
		temp = (unsigned char)inb(datap);
		temp &=0xfb;
		outb(temp, datap);
         }
         break;
      case '5': /* Pin7 GP33 */
   	outb(0xf0, indexp);
	temp = (unsigned char)inb(datap);
	temp &=0xf7;
	outb(temp, datap);
         if (key[2] == '1')
         {
   		outb(0xf1, indexp);
		temp = (unsigned char)inb(datap);
		temp |=0x08;
		outb(temp, datap);
         }
         else
         {
   		outb(0xf1, indexp);
		temp = (unsigned char)inb(datap);
		temp &=0xf7;
		outb(temp, datap);
         }
         break;
      case '6': /* Pin4 GP34 */
	outb(0xf0, indexp);
	temp = (unsigned char)inb(datap);
	temp &=0xef;
	outb(temp, datap);
         if (key[2] == '1')
         {
   		outb(0xf1, indexp);
		temp = (unsigned char)inb(datap);
		temp |=0x10;
		outb(temp, datap);
         }
         else
         {
   		outb(0xf1, indexp);
		temp = (unsigned char)inb(datap);
		temp &=0xef;
		outb(temp, datap);
         }
         break;
      case '7': /* Pin6 GP35 */
	outb(0xf0, indexp);
	temp = (unsigned char)inb(datap);
	temp &=0xdf;
	outb(temp, datap);
         if (key[2] == '1')
         {
   		outb(0xf1, indexp);
		temp = (unsigned char)inb(datap);
		temp |=0x20;
		outb(temp, datap);
         }
         else
         {
   		outb(0xf1, indexp);
		temp = (unsigned char)inb(datap);
		temp &=0xdf;
		outb(temp, datap);
         }
         break;
      case '8': /* Pin8 GP36 */
	outb(0xf0, indexp);
	temp = (unsigned char)inb(datap);
	temp &=0xbf;
	outb(temp, datap);
         if (key[2] == '1')
         {
   		outb(0xf1, indexp);
		temp = (unsigned char)inb(datap);
		temp |=0x40;
		outb(temp, datap);
         }
         else
         {
   		outb(0xf1, indexp);
		temp = (unsigned char)inb(datap);
		temp &=0xbf;
		outb(temp, datap);
         }
         break;
      case '9': /* Pin10 GP37 */
	outb(0xf0, indexp);
	temp = (unsigned char)inb(datap);
	temp &=0x7f;
	outb(temp, datap);
         if (key[2] == '1')
         {
   		outb(0xf1, indexp);
		temp = (unsigned char)inb(datap);
		temp |=0x80;
		outb(temp, datap);
         }
         else
         {
   		outb(0xf1, indexp);
		temp = (unsigned char)inb(datap);
		temp &=0x7f;
		outb(temp, datap);
         }
         break;
      case 'a':
         if ((key[1] == 'l') && (key[2] == 'l') && (key[4] == '0'))
         {
		outb(0xf0, indexp);
		temp = (unsigned char)inb(datap);
		temp &=0x00;
		outb(temp, datap);

   		outb(0xf1, indexp);
		temp = (unsigned char)inb(datap);
		temp &=0x00;
		outb(temp, datap);
         }
         else if ((key[1] == 'l') && (key[2] == 'l') && (key[4] == '1'))
         {
		outb(0xf0, indexp);
		temp = (unsigned char)inb(datap);
		temp &=0x00;
		outb(temp, datap);

   		outb(0xf1, indexp);
		temp = (unsigned char)inb(datap);
		temp |=0xff;
		outb(temp, datap);
         }
         else
         {;}
         break;
      case 'r':
	if ((key[1] == 'd') && (key[2] == '1'))
         {
		//GPIO input 
		outb(0xf0, indexp);
		temp = (unsigned char)inb(datap);
		temp |=0x01;
		outb(temp, datap);

	//Read GPIO STS
	outb(0xf1, indexp);
	temp = (unsigned char)inb(datap);/* Pin1 GP30 */
            printf("pinA2:  %d   \n", (temp >> 0) & 0x1);
         }

	else if ((key[1] == 'd') && (key[2] == '2'))
         {
		//GPIO input 
		outb(0xf0, indexp);
		temp = (unsigned char)inb(datap);
		temp |=0x02;
		outb(temp, datap);

	//Read GPIO STS
	outb(0xf1, indexp);
	temp = (unsigned char)inb(datap);/* Pin3 GP31 */
            printf("pinA3:  %d   \n", (temp >> 1) & 0x1);
         }

	else if  ((key[1] == 'd') && (key[2] == '3'))
         {
		//GPIO input 
		outb(0xf0, indexp);
		temp = (unsigned char)inb(datap);
		temp |=0x04;
		outb(temp, datap);

	//Read GPIO STS
	outb(0xf1, indexp);
        temp = (unsigned char)inb(datap);/* Pin5 GP32 */
            printf("pinA4:  %d   \n", (temp >> 2) & 0x1);
         }

	else if  ((key[1] == 'd') && (key[2] == '4'))
         {
		//GPIO input 
		outb(0xf0, indexp);
		temp = (unsigned char)inb(datap);
		temp |=0x08;
		outb(temp, datap);

	//Read GPIO STS
	outb(0xf1, indexp);
        temp = (unsigned char)inb(datap);/* Pin7 GP33 */
            printf("pinA5:  %d   \n", (temp >> 3) & 0x1);
         }

	else if  ((key[1] == 'd') && (key[2] == '5'))
         {
		//GPIO input 
		outb(0xf0, indexp);
		temp = (unsigned char)inb(datap);
		temp |=0x10;
		outb(temp, datap);

	//Read GPIO STS
	outb(0xf1, indexp);
        temp = (unsigned char)inb(datap);/* Pin4 GP34 */
            printf("pinA6:  %d   \n", (temp >> 4) & 0x1);
         }

	else if  ((key[1] == 'd') && (key[2] == '6'))
         {
		//GPIO input 
		outb(0xf0, indexp);
		temp = (unsigned char)inb(datap);
		temp |=0x20;
		outb(temp, datap);

	//Read GPIO STS
	outb(0xf1, indexp);
        temp = (unsigned char)inb(datap);/* Pin6 GP35 */
            printf("pinA7:  %d   \n", (temp >> 5) & 0x1);
         }

	else if  ((key[1] == 'd') && (key[2] == '7'))
         {
		//GPIO input 
		outb(0xf0, indexp);
		temp = (unsigned char)inb(datap);
		temp |=0x40;
		outb(temp, datap);

	//Read GPIO STS
	outb(0xf1, indexp);
        temp = (unsigned char)inb(datap);/* Pin8 GP36 */
            printf("pinA8:  %d   \n", (temp >> 6) & 0x1);
         }

	else if  ((key[1] == 'd') && (key[2] == '8'))
         {
		//GPIO input 
		outb(0xf0, indexp);
		temp = (unsigned char)inb(datap);
		temp |=0x80;
		outb(temp, datap);

	//Read GPIO STS
	outb(0xf1, indexp);
        temp = (unsigned char)inb(datap);/* Pin10 GP37 */
            printf("pinA9:  %d   \n", (temp >> 7) & 0x1);
         }

         else if ((key[1] == 'd') && (key[2] == 'a'))
         {
		//GPIO input 
		outb(0xf0, indexp);
		temp = (unsigned char)inb(datap);
		temp |=0xff;
		outb(temp, datap);
	//Read GPIO STS
	outb(0xf1, indexp);
	temp = (unsigned char)inb(datap);/* Pin1 GP30 */
            printf("pinA2:  %d   ", (temp >> 0) & 0x1);
	temp = (unsigned char)inb(datap);/* Pin3 GP31 */
            printf("pinA3:  %d   ", (temp >> 1) & 0x1);
        temp = (unsigned char)inb(datap);/* Pin5 GP32 */
            printf("pinA4:  %d   ", (temp >> 2) & 0x1);
        temp = (unsigned char)inb(datap);/* Pin7 GP33 */
            printf("pinA5:  %d   \n", (temp >> 3) & 0x1);
        temp = (unsigned char)inb(datap);/* Pin4 GP34 */
            printf("pinA6:  %d   ", (temp >> 4) & 0x1);
        temp = (unsigned char)inb(datap);/* Pin6 GP35 */
            printf("pinA7:  %d   ", (temp >> 5) & 0x1);
        temp = (unsigned char)inb(datap);/* Pin8 GP36 */
            printf("pinA8:  %d   ", (temp >> 6) & 0x1);
        temp = (unsigned char)inb(datap);/* Pin10 GP37 */
            printf("pinA9:  %d   \n", (temp >> 7) & 0x1);
         }
         else
         {;}
         break;
      case 'q':
         if (key[1] == 't')
         {

	    outb(0xAA, indexp);
            quit = 0;
         }
         else
         {;}
         break;
      default:break;
   }
   }
   printf("quit!\n");
}
