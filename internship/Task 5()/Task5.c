#include <p18f4550.h>

// Function prototypes
void initialize();
void processDigitalInputs();
void processAnalogInput();
void controlBuzzer();
unsigned int ADC_Read(unsigned char channel);

// Define constants
#define BUTTON1 PORTCbits.RC0
#define BUTTON2 PORTCbits.RC1
#define BUZZER PORTCbits.RC2
#define LED1 PORTBbits.RB0
#define LED2 PORTBbits.RB1
#define LED3 PORTBbits.RB2
#define LED4 PORTBbits.RB3
#define ANALOG_THRESHOLD 512 // Adjust threshold according to your sensor

void main() {
    initialize();

    while (1) {
        processDigitalInputs();
        processAnalogInput();
        controlBuzzer();
    }
}

void initialize() {
    OSCCON = 0x72;    // Internal oscillator, 8MHz
    TRISC = 0b00000011; // RC0 and RC1 as inputs
    TRISB = 0;          // All PORTB pins as outputs
    //ANSEL = 0;          // All pins as digital

    // ADC initialization
    ADCON0 = 0b00000001; // Vref+ = Vdd, Vref- = Vss, ADC Channel select = AN0
    ADCON1 = 0b00001110; // Right justify result, Fosc/8, Analog channels on RA0/AN0
}

void processDigitalInputs() {
    // Logic for processing digital inputs
    if (!BUTTON1 && !BUTTON2) {
        LED1 = 1;
        LED2 = 0;
        LED3 = 0;
        LED4 = 0;
    } else if (!BUTTON1 && BUTTON2) {
        LED1 = 0;
        LED2 = 1;
        LED3 = 0;
        LED4 = 0;
    } else if (BUTTON1 && !BUTTON2) {
        LED1 = 0;
        LED2 = 0;
        LED3 = 1;
        LED4 = 0;
    } else {
        LED1 = 0;
        LED2 = 0;
        LED3 = 0;
        LED4 = 1;
    }
}

void processAnalogInput() {
    // Read analog input from the potentiometer connected to AN0
    unsigned int analogValue = ADC_Read(0);

    // Perform actions based on the analog value
    if (analogValue > ANALOG_THRESHOLD) {
        BUZZER = 1; // Turn on the buzzer
    } else {
        BUZZER = 0; // Turn off the buzzer
    }
}

void controlBuzzer() {
    // Additional logic for controlling the buzzer based on other conditions
    // You can add more conditions based on your requirements
}

unsigned int ADC_Read(unsigned char channel) {
    ADCON0 = (channel << 2) | 0x01; // Select ADC channel and enable ADC module
    while (!ADCON0bits.GO); // Wait for conversion to complete
    return (ADRESH << 8) + ADRESL; // Combine high and low bytes to get the result
}
