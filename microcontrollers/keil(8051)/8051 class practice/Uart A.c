#include<reg51.h>
void bourdrate(){
	TMOD =0x20;
	TH1=0xFA;
	TR1=1;
}
int main(){
	bourdrate();
	SCON=0x50;
	while(1){
		SBUF='A';
		while(TI==0);
		TI=0;
	}
}