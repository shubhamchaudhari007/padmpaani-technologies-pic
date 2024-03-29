#include <p18f4550.h>


#define RD0 PORTDbits.RD0
#define RD1 PORTDbits.RD1
// Function to initialize Timer1
void delay_ms(unsigned int milliseconds) {
    unsigned int i, j;

    for (i = 0; i < milliseconds; i++)
        for (j = 0; j < 4000; j++) {}  // Adjust this value based on your clock frequency
}
void initTimer1() {
    T1CON = 0b00110001;    // Timer1, 8-bit, prescaler 1:8
    TMR1H = 0x3C;          // Initial value for 1-second overflow
    TMR1L = 0xB0;
    T1CONbits.TMR1ON = 1;   // Enable Timer1
}

// Function to configure digital input pins
void initButtons() {
    TRISB = 0xFF;          // RB0 and RB1 as input
}

// Function to configure digital output pins
void initLEDs() {
    TRISD = 0x00;          // RD0 and RD1 as output
}

// Main function
void main() {
    unsigned char counter = 0;

    initTimer1();
    initButtons();
    initLEDs();

    while (1) {
        // Check if Timer1 overflowed (1 second elapsed)
        if (PIR1bits.TMR1IF) {
            PIR1bits.TMR1IF = 0;  // Clear Timer1 overflow flag
            counter++;

            // Handle LED blinking based on the counter value
            if (PORTBbits.RB1) {  // If BTN2 is pressed
                RD1 = ~RD1;        // Toggle LED2
                delay_ms(counter * 100);  // Blink speed determined by counter
            }
        }

        // Check if BTN1 is pressed
        if (!PORTBbits.RB0) {
            RD0 = 1;  // Turn on LED1
        } else {
            RD0 = 0;  // Turn off LED1
        }

        // Check if both buttons are pressed (reset functionality)
        if (!PORTBbits.RB0 && !PORTBbits.RB1) {
            counter = 0;  // Reset the counter
            RD0 = 0;      // Turn off LED1
            RD1 = 0;      // Turn off LED2
        }
    }

    return;
}
