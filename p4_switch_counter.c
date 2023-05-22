// 4. 	Embedded System to implement counter based on four switches as binary input 

#include <p89v51rx2.h>

sbit sw1 = P3 ^ 2;
sbit sw2 = P3 ^ 3;
sbit sw3 = P3 ^ 4;
sbit sw4 = P3 ^ 5;
void delay(unsigned int del)
{
    unsigned int i, j;
    for (i = 0; i <= 32000; i++)
    {
        for (j = 0; j <= del; j++)
        {
        }
    }
}
void counter(unsigned int n)
{
    unsigned int i;
    for (i = 0; i < n; i++)
    {
        if (i & (1 << 0))
            RxD = 0;
        else
            RxD = 1;

        if (i & (1 << 1))
            TxD = 0;
        else
            TxD = 1;

        if (i & (1 << 2))
            WR = 0;
        else
            WR = 1;

        if (i & (1 << 3))
            RD = 0;
        else
            RD = 1;

        delay(20);
    }
}
void main(void)
{
    sw1 = 1;
    sw2 = 1;
    sw3 = 1;
    sw4 = 1;
    RxD = 1;
    TxD = 1;
    WR = 1;
    RD = 1;
    while (1)
    {
        if (sw1 == 0)
        {
            counter(2);
            sw1 = 1;
        }
        if (sw2 == 0)
        {
            counter(4);
            sw2 = 1;
        }
        if (sw3 == 0)
        {
            counter(8);
            sw3 = 1;
        }
        if (sw4 == 0)
        {
            counter(16);
            sw4 = 1;
        }
    }
}