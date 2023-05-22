// ľo design and implement an Embedded System that toggle
// pin P3.0 continuously eveíy 500ms using 8051 Boaíd. Use
// cíystal fíequency =11.0592 & ľimeí 1 mode 1

#include <LCD.h>

unsigned int count = 0;
unsigned int byte = 0;
unsigned char a[16];

sbit buzzer = P0 ^ 3;
unsigned int b = 0;

void input()
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
        if (byte == 0)
        {
            count = val;
            byte = 1;
        }
        else
        {
            count += val * 2 * 2 * 2 * 2;
            byte = 2;
        }
    }
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

void runBuzzer()
{
    buzzer = 0;
    delay(50);
    buzzer = 1;

    b = 1;
}

void setLED(unsigned int cntr)
{
    RxD = !(cntr & (1 << 3));
    TxD = !(cntr & (1 << 2));
    WR = !(cntr & (1 << 1));
    RD = !(cntr & (1 << 0));
}
int isPrime(int n)
{
    int i = 2;
    for (i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return 0;
    }

    return 1;
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
void main(void)
{
    int i = 0;
    unsigned int itr = 0;
    int primeNo = 0;
    LCD_INIT();

    while (1)
    {
        if (byte == 0 && itr == 4)
        {
            count = 0;
            byte = 1;
            LCD_WRITE("Lower byte is 0 ", 0, 0);
        }

        if (byte == 1 && itr == 8)
        {
            count = 0;
            byte = 2;
            LCD_WRITE("Upper byte is 0 ", 0, 0);
        }
        input();
        if (byte == 0)
        {
            LCD_WRITE("Enter lower byte", 0, 0);
        }
        else if (byte == 1)
        {
            if (b == 0)
                runBuzzer();
            LCD_WRITE("Enter upper byte", 0, 0);
        }
        else
        {
            if (count == 0)
            {
                LCD_WRITE("You entered 0   ", 0, 0);
                count = 0;
                byte = 0;
                b = 0;
                itr = 0;
                continue;
            }
            LCD_WRITE("You entered ", 0, 0);
            intToChar(count);
            LCD_WRITE(a, 0, 12);
            delay(20);

            for (i = 2; i <= count; i++)
            {
                if (isPrime(i) == 1)
                {
                    primeNo++;
                }
            }
            LCD_WRITE("Primes = ", 1, 0);
            intToChar(primeNo);
            LCD_WRITE(a, 1, 10);
            if (primeNo < 16)
                setLED(primeNo);
            else
                setLED(15);
            for (i = 2; i <= count; i++)
            {
                if (isPrime(i) == 1)
                {
                    intToChar(i);
                    LCD_WRITE(a, 1, 0);
                    LCD_WRITE("is Prime", 1, 4);
                }
            }
            LCD_WRITE("                ", 1, 0);
            count = 0;
            byte = 0;
            b = 0;
        }

        itr++;
    }
}