/*
    Using Arduino Uno ports 8 - 12
    author: Tomas Koci
*/

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    // setting ports as outputs (for LEDs)
    DDRB = DDRB | (1 << DDB4); // PORT 12
    DDRB = DDRB | (1 << DDB3); // PORT 11
    DDRB = DDRB | (1 << DDB2); // PORT 10
    DDRB = DDRB | (1 << DDB1); // PORT 9
    DDRB = DDRB | (1 << DDB0); // PORT 8

    while (1)
    {
        int i = 0;
        int delay = 100;
        while (i <= 4)
        {
            PORTB = PORTB | (1 << i);
            _delay_ms(delay);
            if (i > 0)
            {
                PORTB = PORTB & ~(1 << i - 1);
            }
            i++;
        }
        while (i >= 0)
        {
            if (i - 1 >= 0)
            {
                PORTB = PORTB | (1 << i - 1);
                _delay_ms(delay);
            }
            PORTB = PORTB & ~(1 << i);
            i--;
        }
    }
}
