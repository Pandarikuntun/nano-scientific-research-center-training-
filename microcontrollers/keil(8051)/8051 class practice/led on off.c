#include<reg51.h>
void delay(){
	int i,j;
	for(i=0;i<100;i++)
	for(j=i;j<1000;j++);
}
int main(){
	P1=0x00;				//led on
	while(1){
		P1 |=(1<<1);				///led on
		delay();
		P1 &=~(1<<1);				//led off
		delay();
	}
}