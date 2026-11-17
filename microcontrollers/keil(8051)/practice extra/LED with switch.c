#include<reg51.h>
sbit led1=P1^0; //led
sbit sw1=P2^0;   // switch
void main()
{
	led1=0xff;
	sw1=0xff;
	if(sw1==0)
	{
		led1=1;
		while(sw1==0);
	}	
	
}
