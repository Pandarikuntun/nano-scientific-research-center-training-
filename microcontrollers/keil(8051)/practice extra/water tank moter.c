#include<reg51.h>
sbit mot = P1^0;
sbit mois1 =P1^1;
sbit mois2 =P1^2;
sbit buz =P1^3;
void main()
{
	mois1=mois2=mot=0;
	while(1)
	{
		if(mois1=mois2=0)
		{
			mot =1;
			buz=1;
		}
		if(mois1=mois2=1)
		{
			mot =0;
			buz=0;
		}
	}
}