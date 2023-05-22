// ľo design & implement an Embedded System that displays
// the name and Roll No on LCD scíeen using 8051 Boaíd.

#include <LCD.h>
void main()
{
    LCD_INIT();
    LCD_WRITE("Asif", 0, 1);
    LCD_WRITE("20BCS056", 1, 1);
    while (1)
        ;
}
