#include "MiddleWare.h"
#include <util/delay.h>
#include <avr/io.h>


/*******************************************************************************
 *                          Global Variables                                   *
 *******************************************************************************/
uint8 Dis = 0;


/*******************************************************************************
 *                          Functions Definitions                              *
 *******************************************************************************/

void Initialization (void)
{
	SREG |= (1<<7);
	Buzzer_init();
	LCD_init();
	LEDS_init();
	Ultrasonic_init();
	LCD_displayStringRowColumn(0,0,"Distance = ");//11
	LCD_displayStringRowColumn(0,14,"Cm");

}

void Display_Ultrasonic (void)
{

	Dis = Ultrasonic_readDistance();

	/* Display the temperature value every time at same position */
	LCD_moveCursor(0,11);
	if(Dis >= 50)
	{
		LCD_intgerToString(Dis);
	}
	else
	{
		LCD_intgerToString(Dis);
		/* In case the digital value is two or one digits print space in the next digit place */
		LCD_displayCharacter(' ');
	}
}

void Distance_LED_Buzzer_Mapping (void)
{

	Dis = Ultrasonic_readDistance();
	if( Dis <= 5 )
	{

		led_on(PIN0);
		led_on(PIN1);
		led_on(PIN2);
		_delay_ms(500);
		led_off(PIN0);
		led_off(PIN1);
		led_off(PIN2);
		_delay_ms(500);

		Buzzer_on();
		LCD_displayStringRowColumn(1,5,"STOP");

	}

	else if (Dis >= 6 && Dis <= 10 )
	{
		led_on(PIN0);
		led_on(PIN1);
		led_on(PIN2);
		Buzzer_off();
		LCD_displayStringRowColumn(1,5,"    ");

	}

	else if (Dis >= 11 && Dis <= 15  )
	{
		led_on(PIN0);
		led_on(PIN1);
		led_off(PIN2);
		Buzzer_off();
		LCD_displayStringRowColumn(1,5,"    ");
	}

	else if (Dis >= 16 && Dis <= 20  )
	{
		led_on(PIN0);
		led_off(PIN1);
		led_off(PIN2);
		Buzzer_off();
		LCD_displayStringRowColumn(1,5,"    ");
	}


	else if ( Dis > 20 )
	{
		led_off(PIN0);
		led_off(PIN1);
		led_off(PIN2);
		Buzzer_off();
		LCD_displayStringRowColumn(1,5,"    ");
	}

}

