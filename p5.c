// Embedded System that inteífaces an 8051 micíocontíolleíby
// taking input fíom switch & then completes its cycle (in
// íeveíse oídeí) with a buzzeí at the completion of counteí.
#include <p89v51rx2.h>
unsigned int count = 0;
sbit buzzer = P0 ^ 3;
void delay(unsigned int dela)
{
    unsigned int i, j;
    for (i = 0; i < 1000; i++)
        for (j = 0; j < dela; j++)
            ;
}
void rangeCounter()
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
        count = val;
}
void runBuzzer()
{
    buzzer = 0;
    delay(10);
    buzzer = 1;
}
void setLED(unsigned int cntr)
{
    RxD = !(cntr & (1 << 3));
    TxD = !(cntr & (1 << 2));
    WR = !(cntr & (1 << 1));
    RD = !(cntr & (1 << 0));
}
void main(void)
{
    unsigned int cntr;
    cntr = count;
    while (1)
    {
        rangeCounter();
        delay(100);
        setLED(cntr);
        cntr--;
        if (cntr ==
            -1)
        {
            runBuzzer();
            cntr = count;
        }
    }
}
