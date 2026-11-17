#include<reg51.h>
sfr A=0xE0;
main(){
	SCON=0x50;
	TMOD=0x20;
	TH1=-3;
	TR1=1;
	while(1){
		while(RI==0);
		A=SBUF;
		SBUF=A;
		RI=0;
	}
}