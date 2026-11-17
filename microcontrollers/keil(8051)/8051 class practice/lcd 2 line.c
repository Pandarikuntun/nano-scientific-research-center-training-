#include<reg51.h>
sbit rs =P1^0;
sbit rw =P1^1;
sbit en =P1^2;
void delay(){
	int i,j;
	for(i=0;i<100;i++)
	for(j=i;j<100;j++);
}
void cmd_mode(unsigned char val){
	P2=val;
	rs &=~(1<<0);
	rw &=~(1<<1);
	en |=(1<<2);
	delay();
	en &=~(1<<2);
}
void data_mode(unsigned char data_val){
	P2=data_val;
	rs |=(1<<0);
	rw &=~(1<<1);
	en |=(1<<2);
	delay();
	en &=~(1<<2);	
}
void init(){
	cmd_mode(0x38);
	delay();
	cmd_mode(0x0F);
	delay();
	cmd_mode(0x01);
	delay();
	cmd_mode(0x80);
	delay();
}
int main(){
	unsigned char a[32]="SHIVA SAI IS   WEST FELLOW";
	int l=0;
	init();
	while(a[l]!='\0'){
		if(l==15){
			cmd_mode(0xC0);
			delay();
		}
				data_mode(a[l]);
				l++;
				delay();
		}
		delay();
		delay();
	cmd_mode(0x01);
	//while(1);
	return 0;
}