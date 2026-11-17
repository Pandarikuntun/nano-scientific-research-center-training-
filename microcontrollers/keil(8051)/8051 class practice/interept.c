#include<reg51.h>
void delay()
{
	int i,j;
	for(i=0;i<1000;i++)
	for(j=0;j<10000;j++);
	
}
void Timer0() interrupt 1
{
	P3^=0xFF;
}
main()
{
	TMOD&=~((1<<0)|(1<<1));
	TL0=0X00;
	TH0=0X00;
	TR0=1;
	IE=0X82;
while(1)
{
	P2^=0XFF;
	delay();
}

}