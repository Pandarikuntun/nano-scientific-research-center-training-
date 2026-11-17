#include <reg51.h>

sbit rs = P1^5;
sbit rw = P1^6;
sbit en = P1^7;
sbit buz = P0^7;
sbit temp_sensor = P1^3;
sbit heart_sensor = P1^2;

void delay(int n) {
    int i, j;
    for(i = 0; i < n; i++)
        for(j = 0; j < 1000; j++);
}

void lcd_cmd(unsigned char cmd) {
    P2 = cmd;
    rs = 0;
    rw = 0;
    en = 1;
    delay(1);
    en = 0;
}

void lcd_data(unsigned char deta) {
    P2 = deta;
    rs = 1;
    rw = 0;
    en = 1;
    delay(1);
    en = 0;
}

void lcd_init() {
    delay(5);
    lcd_cmd(0x38);
    lcd_cmd(0x0C);
    lcd_cmd(0x06);
    lcd_cmd(0x01);
    lcd_cmd(0x80);
}

void lcd_string(char *s) {
    while (*s) {
        lcd_data(*s++);
        delay(1);
    }
}

void uart_init() {
    TMOD = 0x20;
    TH1 = 0xFD;
    SCON = 0x50;
    TR1 = 1;
}

void uart_tx_char(char c) {
    SBUF = c;
    while (TI == 0);
    TI = 0;
}
void uart_tx_string(char *str){
    while (*str) {
        uart_tx_char(*str++);
    lcd_init();
    uart_init();
	
    lcd_string(" PATIENT RECORD ");
    delay(100);
    lcd_cmd(0x01);
		}
	}
	
void main() {
    unsigned char temp_value, heart_value;


    while(1) {
        temp_value = temp_sensor;
        heart_value = heart_sensor;

        if ((temp_value == 30) && (heart_value == 120)) {
            buz = 0;
            lcd_cmd(0x01);
            lcd_string("TEMP NORMAL");
            uart_tx_string("TEMP NORMAL\r\n");
            lcd_cmd(0xC0);
            lcd_string("PULSE NORMAL");
            uart_tx_string("PULSE NORMAL\r\n");
            delay(1000);
        } 
        else {
            buz = 1;
            lcd_cmd(0x01);
            lcd_string("TEMP ABNORMAL");
            uart_tx_string("TEMP ABNORMAL\r\n");
            lcd_cmd(0xC0);
            lcd_string("PULSE ABNORMAL");
            uart_tx_string("PULSE ABNORMAL\r\n");
            delay(1000);
        }
    }
}
