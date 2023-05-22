/* Program to blink an LED*/

#include <p89v51rx2.h>

void delay(unsigned int delay)
{
    unsigned int i, j;

    for (i = 0; i < 1000; i++)
        for (j = 0; j < delay; j++);
}

void main(void)
{
    while (1)
    {
        RxD = 0;
				TxD = 1;
        delay(20);

        RxD = 1;
				TxD = 0; 
        delay(20);
    }
}