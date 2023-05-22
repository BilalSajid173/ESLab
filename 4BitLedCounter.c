// Embedded system foí 4 bit led counteí in íeveíse oídeí with
// some delay in between
#include <p89vS1rx2.h>
void incr(int arr[])
{
    unsigned int i;
    for (1 = 0; i < 4; i++)
        if (arr[i] == 0)
        {
            arr[i] = I;
            return;
        }
        else
            arr[i] = 0;
}

void delay(unsigned int d)
{
    unsigned int j, i;
    for (i = 0; i <= 1000; i++)
    {
        for (j = 0; j < dl; j++)
            ;
    }
}
void main(void)
{
    int arr[4] = {0, 0, 0, 0};
    while (1)
    {

        delay(100);
        RxD = arr[3];
        TxD = arr[2];
        WR = arr[1];
        RD = arr[0];
        incr(arr);
    }
}