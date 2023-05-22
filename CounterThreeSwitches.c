// AIM :- Design an ES to implement counter based on three switches as
// binary input
#include <p89v51rx2.h>
void delay(int dela)
{
    int i, j;
    for (i = 0; i <= 1000; i++)
        for (j = 0; j < dela; j++)
            ;
}
void c1()
{
    int i;
    for (i = 0; i < 2; i++)
    {
        RD = !i;
        delay(100);
    }
}
void c2()
{
    int i, j;
    for (i = 0; i < 2; i++)
        for (j = 0; j < 2; j++)
        {
            WR = !i;
            RD = !j;
            delay(100);
        }
}
void c3()
{
    int i, j, k;
    for (i = 0; i < 2; i++)
        for (j = 0; j < 2; j++)
            for (k = 0; k < 2; k++)
            {
                RD = !k;
                WR = !j;
                TxD = !i;
                delay(100);
            }
}
void c4()
{
    int i, j, k, l;
    for (i = 0; i < 2; i++)
        for (j = 0; j < 2; j++)
            for (k = 0; k < 2; k++)
                for (l = 0; l < 2; l++)
                {
                    RD = !l;
                    WR = !k;
                    TxD = !j;
                    RxD = !i;
                    delay(100);
                }
}
void main()
{
    int arr[] = {0, 0, 0};
    int i;
    int num;
    INT0 = 1;
    while (1)
    {
        num = 0;
        arr[0] = !INT1;
        arr[1] = !T0;
        arr[2] = !T1;
        for (i = 0; i < 3; i++)
            num = ((num * 2) + arr[i]);
        if (num == 1)
            c1();
        else if (num == 2)
            c2();
        else if (num == 3)
            c3();
        else if (num == 4)
            c4();
    }
}