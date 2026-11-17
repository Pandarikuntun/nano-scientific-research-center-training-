#include<reg51.h>
sbit rs = P3^5;
sbit rw = P3^6;
sbit en = P3^7;
sbit led = P3^3;

void delay(int n){
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<100;j++);
}
void lcd_cmd(unsigned char cmd){
	P1=cmd;
	rs=0;
	rw=0;
	en=1;
	delay(1);
	en=0;
}
void lcd_dat(unsigned char deta){
	P1=deta;
	rs=1;
	rw=0;
	en=1;
	delay(1);
	en=0;
}
void lcd_init(){
	delay(5);
	lcd_cmd(0x38);
	delay(1);
	lcd_cmd(0x0C);
	delay(1);
	lcd_cmd(0x10);
	delay(1);
	lcd_cmd(0x01);
	delay(1);
	lcd_cmd(0x06);
	delay(1);
	lcd_cmd(0x80);
	delay(1);
}
void string(char *str){
	while(*str){
		lcd_dat(*str++);
		delay(1);
	}
}
void uart_init(){
	TMOD=0x20;
	TH1=0xFD;
	SCON=0x50;
	TR1=1;
}
void utx_char(char c){
	SBUF=c;
	while(TI==0);
	TI=0;
}
void utx_string(char *str1){
	while(*str1){
		utx_char(*str1++);
	}
}
int main(){
	unsigned int i;
	unsigned char seg[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x67,0x40};
	char *lcddis[]={" ZERO "," ONE "," TWO "," THREE "," FOUR "," FIVE "," SIX "," SEVEN "," EIGHT "," NINE "," NEXT-> "};
	lcd_init();
	uart_init();
	

	while(1){
	
		
			for(i=0;i<11;i++){
				string(" LCD STATUS ");
				lcd_cmd(0xC0);
				//lcd_cmd()
				P3 |=(1<<3);
				string(lcddis[i]);
				P2=seg[i];
				utx_string(lcddis[i]);
				delay(900);
				lcd_cmd(0x01);
			}
			P3 &=~(1<<3);
			//lcd_cmd(0x01);
			delay(1000);
	}
}