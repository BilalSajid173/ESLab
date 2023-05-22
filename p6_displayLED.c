// 6.	To design & implement an Embedded System that displays the name and Roll No on LCD screen using 8051 Board.
// 	15/03/23

#include <LCD.H>

void main(void)
{
	unsigned char x = 0, y = 0;
	LCD_INIT();
	LCD_WRITE("ADNAN AHMAD", line1, x);
	delay(2000);
	LCD_WRITE("20BCS006", line1, x);
	LCD_WRITE("Abdul Basit", line1, x);
	delay(2000);
	LCD_WRITE("20BCS004", line1, x);
	delay(2000);
}