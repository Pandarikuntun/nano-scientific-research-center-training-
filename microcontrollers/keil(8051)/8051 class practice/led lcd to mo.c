#include <reg51.h>

sbit rs = P1^0;
sbit rw = P1^1;
sbit en = P1^2;
#define LED_PIN 2   // LED connected to P0.2

void delay_timer() {
    TF0 = 0;
    TH0 = 0x93;
    TL0 = 0xFF;
    TR0 = 1;
    while (TF0 == 0);
    TR0 = 0;
    TF0 = 0;
}

void lcd_delay() {
    int i, j;
    for (i = 0; i < 100; i++)
        for (j = 0; j < 100; j++);
}

void lcd_cmd(unsigned char val) {
    P0 = val;
    P1 &= ~((1 << 0) | (1 << 1));  // RS=0, RW=0
    P1 |= (1 << 2);                // EN=1
    lcd_delay();
    P1 &= ~(1 << 2);               // EN=0
}

void lcd_data(unsigned char val) {
    P1 = val;
    P1 |= (1 << 0);                // RS=1
    P1 &= ~(1 << 1);               // RW=0
    P1 |= (1 << 2);                // EN=1
    lcd_delay();
    P1 &= ~(1 << 2);               // EN=0
}

void lcd_init() {
    lcd_cmd(0x38);  // 2 lines, 5x7 matrix
    lcd_delay();
    lcd_cmd(0x0C);  // Display ON, cursor OFF
    lcd_delay();
    lcd_cmd(0x01);  // Clear display
    lcd_delay();
    lcd_cmd(0x80);  // Move to first line
    lcd_delay();
}

void lcd_string(char *s) {
    while (*s) {
        lcd_data(*s++);
        lcd_delay();
    }
}

void main() {
    TMOD &= 0xF0;
    TMOD |= 0x01;   // Timer0 mode1 (16-bit)
    P0 = 0x00;
    lcd_init();

    while (1) {
        P2 |= (1 << LED_PIN);    // LED ON using bitwise OR
        lcd_cmd(0x01);           // Clear LCD
        lcd_cmd(0x80);
        lcd_string("LED ON");
        delay_timer();

        P2 &= ~(1 << LED_PIN);   // LED OFF using bitwise AND with NOT
        lcd_cmd(0x01);
        lcd_cmd(0x80);
        lcd_string("LED OFF");
        delay_timer();
    }
}
