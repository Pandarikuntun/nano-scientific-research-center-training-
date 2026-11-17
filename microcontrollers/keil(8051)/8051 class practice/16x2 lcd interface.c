#include <reg51.h>
#define lcd_data_port P2   // LCD 8-bit data lines connected to Port 2

// Control pins connected to Port 1
// RW = P1.1, RS = P1.2, EN = P1.3

void delay() {
    int i, j;
    for(i = 0; i < 100; i++)
        for(j = 0; j < 100; j++);
}

// Function to send command to LCD
void lcd_cmd(unsigned char cmd) {
    lcd_data_port = cmd;       // Send command to data port

    P1 &= ~(1 << 2);  // RS = 0 ? command mode
    P1 &= ~(1 << 1);  // RW = 0 ? write mode
    P1 |=  (1 << 3);  // EN = 1 ? enable high
    delay();
    P1 &= ~(1 << 3);  // EN = 0 ? enable low to latch
    delay();
}

// Function to send data (character) to LCD
void lcd_data(unsigned char dat) {
    lcd_data_port = dat;       // Send data byte

    P1 |=  (1 << 2);  // RS = 1 ? data mode
    P1 &= ~(1 << 1);  // RW = 0 ? write mode
    P1 |=  (1 << 3);  // EN = 1 ? enable high
    delay();
    P1 &= ~(1 << 3);  // EN = 0 ? enable low
    delay();
}

// Function to initialize LCD
void lcd_init() {
    lcd_cmd(0x38);  // Use 2 lines, 5x7 matrix
    lcd_cmd(0x0E);  // Display ON, cursor ON
    lcd_cmd(0x01);  // Clear display
    lcd_cmd(0x80);  // Set cursor to first line, first position
}

// Main Function
void main() {
    unsigned char msg[] = "I love maa";
		unsigned char msg1[] = "I love dad";
    int i = 0;

    lcd_init();  // Initialize LCD

    while(msg[i] != '\0') {  // Display message1
        lcd_data(msg[i]);
        i++;
    }
		i=0;
		lcd_cmd(0x0C0);
		while(msg1[i]!='\0'){		// Display message1
			lcd_data(msg1[i]);
			i++;
		}

    while(1);  // Infinite loop to hold display
}
