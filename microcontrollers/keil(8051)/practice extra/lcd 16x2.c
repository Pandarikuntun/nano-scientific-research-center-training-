#include<reg51.h>
sbit RS = P1^0;
sbit RW = P1^1;
sbit EN = P1^2;
void delay(){
	int i ,j;
	for(i=0;i<10;i++)
	for(j=i;j<1000;j++);
}

void lcd_cmd(unsigned char cmd){
	P2=cmd;
	RS=0;
	RW=0;
	EN=1;
	EN=0;
}
void lcd_deta(unsigned char deta){
	P2=deta;
	RS=1;
	RW=0;
	EN=1;
	EN=0;
}
void lcd_init(){
	lcd_cmd(0x38);
	lcd_cmd(0x0C);
	lcd_cmd(0x01);
	lcd_cmd(0x06);
	//lcd_cmd(0x0F);
}
int main(){
	lcd_init();	
		lcd_cmd(0x0F);
		delay();
		lcd_deta('M');
		lcd_cmd(0x1C);
		delay();
		lcd_deta('a');
		lcd_cmd(0x1C);
		delay();
		lcd_deta('h');
		lcd_cmd(0x1C);
		delay();
		lcd_deta('a');
		lcd_cmd(0x1C);
		delay();
		lcd_deta('d');
		lcd_cmd(0x1C);
		delay();
		lcd_deta('e');
		lcd_cmd(0x1C);
		delay();
		lcd_deta('v');
		lcd_cmd(0x1C);
		delay();
		lcd_deta('i');
		delay();
		lcd_cmd(0x01);

	return 0;
}
