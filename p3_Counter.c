// Embedded system for 3 bit led counter with some delay in between

#include <p89v51rx2.h>
void delay(unsigned int time)
{
	unsigned int i, j;
	for (i = 0; i < time; i++)
		for (j = 0; j < 125; j++)
			;
}

void main()
{
	unsigned char count = 0;
	while (1)
	{

		unsigned int num;

		for (num = 0; num <= 7; num++)
		{
			unsigned int i;
			for (i = 2; i >= 0; i--)
			{
				unsigned int bits = num >> i & 1;
				unsigned int first_digit = bits % 10;
				unsigned int second_digit = (bits / 10) % 10;
				unsigned int third_digit = bits / 100;
				RxD = ~first_digit;
				TxD = ~second_digit;
				WR = ~third_digit;
				delay(1000);
			}
		}
	}
}
