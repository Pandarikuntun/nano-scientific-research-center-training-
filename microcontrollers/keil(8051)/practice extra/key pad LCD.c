#include<reg51.h>
sbit r1=P1^0;
sbit r2=P1^1;
sbit r3=P1^2;
sbit r4=P1^3;
sbit c1=P1^4;
sbit c2=P1^5;
sbit c3=P1^6;
sbit rs=P3^0;
sbit rw=P3^1;
sbit en=P3^2;
void lcdcmd(unsigned char);
void lcddat(unsigned char);
void delay();
void main()
{
	P2=0x00;
	P1=0xFF;
	lcdcmd(0x38); delay();
	lcdcmd(0x01); delay();
	lcdcmd(0x06); delay();
	lcdcmd(0x0c); delay();
	lcdcmd(0x81); delay();
	while(1)
		{
			r2=r3=r4=1; r1=0; 
			if(c1==0) { lcddat('1'); delay(); }
			if(c2==0) { lcddat('2'); delay(); }
			if(c3==0) { lcddat('3'); delay(); }
			r1=r3=r4=1; r2=0;
			if(c1==0) { lcddat('4'); delay(); }
			if(c2==0) { lcddat('5'); delay(); }
			if(c3==0) { lcddat('6'); delay(); }
			r1=r2=r4=1; r3=0;
			if(c1==0) { lcddat('7'); delay(); }
			if(c2==0) { lcddat('8'); delay(); }
			if(c3==0) { lcddat('9'); delay(); }
			r1=r2=r3=1; r4=0;
			if(c1==0) { lcddat('*'); delay(); }
			if(c2==0) { lcddat('0'); delay(); }
			if(c3==0) { lcddat('#'); delay(); }
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
	void lcddat(unsigned char dat)
	{
		P2=dat;
		rs=1;
		rw=0;
		en=1;
		delay();
		en=0;
	}
	void delay()
		{
			unsigned int i,j;
			for(i=0;i<100;i++)
				for(j=0;j<255;j++);
		}

				
