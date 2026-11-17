#include<reg51.h>
sbit motp1=P1^0;
sbit motn1=P1^1;
sbit motp2=P1^2;
sbit motn2=P1^3;
sbit sw1=P2^0;
sbit sw2=P2^1;
sbit sw3=P2^2;
sbit sw4=P2^3;
sbit sw5=P2^4;
void main()
{
	motp1=motn1=motp2=motn2=0;
		if(sw1==1)
	{									//forward move
		motp1=1;	motn1=0;
		motp2=0;	motn2=1;
	}
		if(sw2==1)
	{								//backword move
		motp1=0;	motn1=1;
		motp2=1;	motn2=0;
	}
		if(sw3==1)
	{								// right move
		motp1=1;	motn1=0;	
		motp2=1;	motn2=0;
	}
		if(sw4==1)
	{								//left move
		motp1=0;	motn1=1;
		motp2=0;	motn2=1;
	}
		if(sw5==1)
	{								//off condition
		motp1=1;	motn1=1;
		motp2=1;	motn2=1;
	}
}