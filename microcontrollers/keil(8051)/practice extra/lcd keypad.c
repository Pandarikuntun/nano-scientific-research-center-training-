#include<reg51.h>
sbit R0 = P1^0;
sbit R1 = P1^1;
sbit R2 = P1^2;
sbit R3 = P1^3;
sbit C0 = P1^4;
sbit C1 = P1^5;
sbit C2 = P1^6;
sbit C3 = P1^7;

sbit rs = P0^0;
sbit rw = P0^1;
sbit en = P0^2;


void delay(int x){
	int i,j;
	for(i=0;i<x;i++)
	for(j=i;j<100;j++);
}
void lcdcmd(unsigned char cmd){
	P2= cmd;
	rs=0;
	rw=0;
	en=1;
	delay(1);
	en=0;
}
void lcddata(unsigned char val){
	P2=val;
	rs=1;
	rw=0;
	en=1;
	delay(1);
	en=0;
}
void lcdinit(){
	lcdcmd(0x38);
	delay(1);
	lcdcmd(0x0C);
	delay(1);
	lcdcmd(0x01);
	delay(1);
	lcdcmd(0x06);
	delay(1);
	lcdcmd(0x81);
}
	
void main(){
	lcdinit();
	P2=0x00;
	while(1){
		R0=0;
		if(C0==0){
			lcddata('7');
			delay(10);
		}
		if(C1==0){
			lcddata('8');
			delay(10);
		}
		if(C2==0){
			lcddata('9');
			delay(10);
		}
		if(C3==0){
			lcddata('/');
			delay(10);
		}

		R0=1; R1=0; 
		if(C0==0){
			lcddata('4');
			delay(10);
		}
		if(C1==0){
			lcddata('5');
			delay(10);
		}
		if(C2==0){
			lcddata('6');
			delay(10);
		}
		if(C3==0){
			lcddata('*');
			delay(10);
		}

		R1=1; R2=0;
		if(C0==0){
			lcddata('1');
			delay(10);
		}
		if(C1==0){
			lcddata('2');
			delay(10);
		}
		if(C2==0){
			lcddata('3');
			delay(10);
		}
		if(C3==0){
			lcddata('-');
			delay(10);
		}
		
		R2=1; R3=0;
		if(C0==0){
			lcddata('C');
			delay(10);
		}
		if(C1==0){
			lcddata('0');
			delay(10);
		}
		if(C2==0){
			lcddata('=');
			delay(10);
		}
		if(C3==0){
			lcddata('+');
			delay(10);
		}
	
}
	}
	
