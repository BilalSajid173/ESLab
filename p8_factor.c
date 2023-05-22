// Embedded System to display factor of a number (input through switch) on LCD and LED with buzzer in between every factor using 8051 board.

#include <p89v51rx2>
#include <LCD.H>

sbit sw1 = P3 ^ 2;
sbit sw2 = P3 ^ 3;
sbit sw3 = P3 ^ 4;
sbit sw4 = P3 ^ 5;
sbit buzz = P0 ^ 3;

void main()
{
    unsigned int n, x;
    buzz = 1;

    for (int x; x > 0; x--)
    {
        if (x * (n / x) == n)
        {
            LCD_WRITE("%lu", x, 0, 1);
            buzz = 0;
            buzz = 1;
        }
    }
}

void delay(unsigned int del)
{
    unsigned int i, j;
    for (i = 0; i <= 1000; i++)
    {
        for (j = 0; j <= del; j = j + 2)
        {
            j--;
        }
    }
}