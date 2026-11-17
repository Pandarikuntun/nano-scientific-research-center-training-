#include <reg51.h>

sbit rs = P1^2;
sbit rw = P1^1;
sbit en = P1^0;
sbit led = P1^7;   // LED connected to P1.7
sbit intr = P1^6; 	//interept

void delay(int n) {
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < 120; j++);
}

void lcd_cmd(unsigned char val) {
    P2 = val;
    rs =0;
    rw =0;
    en =1;
    delay(1);
    en =0;
}

void lcd_dat(unsigned char data_val) {
    P2 = data_val;
    rs =1;
    rw =0;
    en =1;
    delay(1);
    en =0;
}

void lcd_init() {
    lcd_cmd(0x38); // 8-bit, 2-line 3x8 matrix
    delay(1);
    lcd_cmd(0x0C); // Display ON, Cursor OFF
    delay(1);
    lcd_cmd(0x01); // Clear display
    delay(1);
    lcd_cmd(0x06); // Auto increment cursor
    delay(1);
    lcd_cmd(0x80); // Cursor at line 1
    delay(1);
}

void lcd_string(char *s) {
    while (*s) {
        lcd_dat(*s++);
        delay(1);
    }
}

void uart_init() {
    TMOD = 0x20;   // Timer1 mode 2
    TH1 = 0xFD;    // Baud rate 9600 for 11.0592MHz
    SCON = 0x50;   // 8-bit UART, REN=1
    TR1 = 1;       // Start timer
}

void uart_tx_char(char c) {
    SBUF = c;
    while (TI == 0);
    TI = 0;
}

void uart_tx_string(char *str) {
    while (*str) {
        uart_tx_char(*str++);
    }
}
void Timer0() interrupt 1
{
	intr=0xFF;
	TMOD =0x20;
	TL0=0x00;
	TH0=0x00;
	TR0=1;
	IE=0x82;
}

int main() {
    lcd_init();
    uart_init();
    lcd_cmd(0x80);
    lcd_string("LED STATUS:");
		
    while (1) {
        // LED ON
        P1 |= (1 << 7); // Bitwise LED ON
        lcd_cmd(0xC0);   // Move to second line
        lcd_string("ON ");
        uart_tx_string("LED ON");
        delay(1000);

        P1 &= ~(1 << 7);    // Bitwise LED OFF
        lcd_cmd(0xC0);
        lcd_string("OFF");
        uart_tx_string("LED OFF");
        delay(1000);
    }
}
