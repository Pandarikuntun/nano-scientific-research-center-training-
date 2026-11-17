#include<reg51.h>
sbit wave=P1^0;
void delay();
void main()
{
	while(1)
	{
		wave=0;
		delay();
		wave=1;
		delay();
	}
}
void delay()
{ 
	unsigned char i;
	TMOD=0x10;
	for(i=0;i<14;i++)
	{
		TH1=0x00;
		TR1=1;
		while(TF1==0);
		TF1=0;
	}
}
		