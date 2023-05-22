// Embedded System to display the factorial of a number (input through switch) on LCD screen using 8051 board. 

#include <LCD.h>
#include <stdio.h>
#include <stdlib.h>

void display(int num, int fact)
{
    LCD_INIT();

    while (1)
    {
        LCD_WRITE("Factorial Of ", 0, 1);
        LCD_WRITE(convString(num), 0, 1);
        LCD_WRITE(": ", 1, 1);
        LCD_WRITE(convString(fact), 1, 1);
    }
}

char *convString(int num)
{
    char *str = (char *)malloc(10 * sizeof(char));
    int i = 0;
    while (num != 0)
    {
        str[i++] = (num % 10) + '0';
        num /= 10;
    }
    str[i] = '\0';
    return str;
}
int factorial(int n)
{
    unsigned int fct = 1;
    unsigned int i;
    for (i = 1; i <= n; i++)
    {
        fct *= i;
    }

    return fct;
}

int binToDec(int prev) // to return the no of bits in counter
{
    unsigned int num = 0;
    if (INT0 == 0)
        num += 8;
    if (INT1 == 0)
        num += 4;
    if (T0 == 0)
        num += 2;
    if (T1 == 0)
        num += 1;
    if (num > 0)
        return num;
    return prev;
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
void main(void)
{
    unsigned int fct;
    unsigned int num = 0;
    while (num == 0)
    {
        num = binToDec(num);
    }
    fct = factorial(num);
    display(num, fct);
}
