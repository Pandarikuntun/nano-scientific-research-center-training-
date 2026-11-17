#include<reg51.h>
void delay(){
	int i,j;
	for(i=0;i<100;i++)
	for(j=0;j<100;j++);
	}
void main(){
	unsigned char i;
	while(1){
	for(i=0x01;i<0x80;i=i<<1){
		P1=i;
		delay();
		}
	}
}