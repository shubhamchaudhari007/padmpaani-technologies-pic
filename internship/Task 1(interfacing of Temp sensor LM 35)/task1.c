#include <p18f4550.h>
#include <stdio.h>

#define LCD_EN LATAbits.LATA1
#define LCD_RS LATAbits.LATA0
#define LCDPORT LATB

unsigned char str[16];

void lcd_delay()
{
    unsigned int j;

    
    
        for (j = 0; j < 100; j++)
            ;
    
}

void SendInstruction(unsigned char command)
{
    LCD_RS = 0;          // RS low: Instruction
    LCDPORT = command;
    LCD_EN = 1;           // EN High
    lcd_delay();
    LCD_EN = 0;           // EN Low; command sampled at EN falling edge
    lcd_delay();
}

void SendData(unsigned char lcddata)
{
    LCD_RS = 1;          // RS HIGH: DATA
    LCDPORT = lcddata;
    LCD_EN = 1;           // EN High
    lcd_delay();
    LCD_EN = 0;           // EN Low; data sampled at EN falling edge
    lcd_delay();
}

void InitLCD(void)
{
    ADCON1 = 0x0F;
    TRISB = 0x00;        // set data port as output
    TRISAbits.RA0 = 0;   // RS pin
    TRISAbits.RA1 = 0;   // EN pin

    SendInstruction(0x38); // 8 bit mode, 2 line, 5x7 dots
    SendInstruction(0x06); // entry mode
    SendInstruction(0x0C); // Display ON cursor OFF
    SendInstruction(0x01); // Clear display
    SendInstruction(0x80); // set address to 0
}

void LCD_display(unsigned int row, unsigned int pos, unsigned char *ch)
{
    if (row == 1)
        SendInstruction(0x80 | (pos - 1));
    else
        SendInstruction(0xC0 | (pos - 1));

    while (*ch)
        SendData(*ch++);
}

void ADCInit(void)
{
    TRISEbits.RE1 = 1;    // ADC channel 6 input
    TRISEbits.RE2 = 1;    // ADC channel 7 input
    ADCON0 = 0b00000001;  // ADC on, select channel 0
    ADCON1 = 0b00001110;  // Ref voltages Vdd & Vss; AN0 - AN7 channels Analog
    ADCON2 = 0b10101110;  // Right justified; Acquisition time 4T; Conversion clock Fosc/64
}

unsigned short Read_ADC(void)
{
    ADCON0bits.GO = 1; // Start Conversion

    while (ADCON0bits.GO)
        ; // Wait till A/D conversion is complete

    return ADRES; // Return ADC result
}

void main(void)
{
    unsigned int temp;
    InitLCD();
    ADCInit();
    LCD_display(1, 1, "Temperature:");

    while (1)
    {
        temp = Read_ADC();
        temp = ((temp * 500) / 1023);
        sprintf(str, "%d'C  ", temp);
        LCD_display(2, 1, str);
        lcd_delay(5000);
    }
}
