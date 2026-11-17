#include<reg51.h>
sbit rs=P1^0;
sbit rw=P1^1;
sbit en=P1^2;
void lcdcmd(unsigned char);
void lcddat(unsigned char);
void delay();
void main()
	{ 
		P2=0x00;
		while(1)
		{
			lcdcmd(0x38);    	//5x7 matrix
			delay();
			lcdcmd(0x01); 		//clr display
			delay();
			lcdcmd(0x10);			//curser blinking 
			delay();
			lcdcmd(0x0c);			//display on
			delay();
			lcdcmd(0x81);			//forc curser first position
			delay();
			lcdcmd(0x01);
			delay();
			lcddat('i');
			delay();
			lcddat('l');
			delay();
			lcddat('o');
			delay();
			lcddat('v');
			delay();
			lcddat('e');
			delay();
			lcddat('m');
			delay();
			lcddat('a');
			delay();
			lcddat('a');
			delay();
			
		}
	}
	void lcdcmd(unsigned char val)
	{
		P2=val;
		rs=0;
		rw=0;
		en=1;
		delay();
		en=0;
	}
	void lcddat(unsigned char val)
	{
		P2=val;
		rs=1;
		rw=0;
		en=1;
		delay();
		en=0;
	}
	void delay()
	{
		unsigned int i;
		for(i=0;i<10000;i++);
	}
	
			
			
