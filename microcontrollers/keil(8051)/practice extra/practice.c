#include<reg51.h>
sbit sen1=P0^0;
sbit sen2=P0^1;
sbit mot1=P1^0;
sbit buz=P1^1;

void main()
{
	unsigned int i;
	sen1=sen2=mot1=buz=0;
	while(1){
		if(sen1=sen1==0)
		{
			buz=1;
			for(i=0;i<255;i++);
			buz=0;
			mot1=1;
		}
		if(sen1=sen2==1)
		{
			buz=1;
			for(i=0;i<255;i++);
			buz=0;
			mot1=0;
		}
	}
}