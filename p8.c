// ľo design and implement an Embedded System that
// outputs all píime numbeís upto N( wheíe N is 1 byte data
// input thíough switch with buzzeí in between loweí nibble
// and uppeí nibble) on LCD scíeen using 8051 boaíd. Also,
// show numbeí of píime numbeís thíough LEDs.
#include <LCD.h>
sbit buzz = P0 ^ 3;
unsigned int lowerCount = -1;
unsigned int upperCount = -1;
int totalPrime = -1;
unsigned char a[16];
int isPrime(int n)
{
    int i;
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;
    if (n == 3)
        return 1;
    for (i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}
void delay(unsigned int d)
{
    unsigned int j, i;
    for (i = 0; i <= 1000; i++)
    {
        for (j = 0; j < d; j++)
            ;
    }
}
void inputLower()
{
    unsigned int val = 0;
    if (INT0 == 0)
        val += 8;
    if (INT1 == 0)
        val += 4;
    if (T0 == 0)
        val += 2;
    if (T1 == 0)
        val += 1;
    if (val != 0)
    {
        lowerCount = val;
        buzz = 0;
        delay(40);
        buzz = 1;
    }
}
void inputUpper()
{
    unsigned int val = 0;
    if (INT0 == 0)
        val += 8;
    if (INT1 == 0)
        val += 4;
    if (T0 == 0)
        val += 2;
    if (T1 == 0)
        val += 1;
    if (val != 0)
        upperCount = val;
}
void showLED(int n)
{
    RD = 1;
    if (n % 2 == 1)
    {
        RD = 0;
    }
    n = n / 2;
    WR = 1;
    if (n % 2 == 1)
    {
        WR = 0;
    }
    n = n / 2;
    TxD = 1;
    if (n % 2 == 1)
    {
        TxD = 0;
    }
    n = n / 2;
    RxD = 1;
    if (n % 2 == 1)
    {
        RxD = 0;
    }
    n = n / 2;
}
void intToChar(int n)
{
    int i = 0, j = 0;
    for (i = 0; i < 16; i++)
    {
        a[i] = ' ';
    }
    i = 0;
    while (n != 0)
    {
        a[i] = (n % 10) + '0';
        i++;
        n = n / 10;
    }
    i--;
    while (j <= i)
    {
        char temp = a[i];
        a[i] = a[j];
        a[j] = temp;
        i--;
        j++;
    }
}
void showPrime(int n)
{
    int temp;
    int i = 0;
    temp = 0;
    for (i = 1; i <= n; i++)
    {
        if (isPrime(i) == 1)
        {
            temp++;
            intToChar(i);
            LCD_WRITE(a, 0, 0);
        }
    }
    intToChar(temp);
    LCD_WRITE("Total Primes ", 0, 0);
    LCD_WRITE(a, 0, 13);
    if (totalPrime == -1)
    {
        totalPrime = temp;
    }
}
void main(void)
{
    int ctr = 0;
    int i = 0;
    int itr = 0;
    LCD_INIT();
    while (1)
    {
        itr++;
        if (lowerCount == -1)
        {
            if (itr > 5)
            {
                lowerCount = 0;
            }
            LCD_WRITE("Enter lower bit ", 0, 0);
            inputLower();
        }
        else if (upperCount == -1)
        {
            if (itr > 10)
            {
                upperCount = 0;
            }
            LCD_WRITE("Enter higher bit ", 0, 0);
            inputUpper();
        }
        else
        {
            int finalNumber = (upperCount * 16) + lowerCount;
            LCD_WRITE("Primes of ", 0, 0);
            intToChar(finalNumber);
            LCD_WRITE(a, 0, 10);
            delay(40);
            showPrime(finalNumber);
            if (totalPrime == -1)
                showLED(0);
            else
                showLED(totalPrime);
        }
    }
}
