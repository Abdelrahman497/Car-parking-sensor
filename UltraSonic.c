#include "UltraSonic.h"
#include <util/delay.h>
#include "icu.h"

/*******************************************************************************
 *                          Global Variables                                   *
 *******************************************************************************/

uint8 g_edgeCount = 0;
uint16 g_time = 0;
uint8 g_distance = 0;



/*******************************************************************************
 *                          Functions Definitions                              *
 *******************************************************************************/

/* This is the call-back function */
void  Ultrasonic_edgeProcessing(void)
{
	g_edgeCount++;
	if(g_edgeCount == 1)
	{
		/*
		 * Clear the timer counter register to start measurements from the
		 * first detected rising edge
		 */
		ICU_clearTimerValue();
		/* Detect falling edge */
		ICU_setEdgeDetectionType(FALLING);
	}
	else if(g_edgeCount == 2)
	{
		/* Store the Period time value + High time value */
		g_time = ICU_getInputCaptureValue();
		/* Clear the timer counter register to start measurements again */
		ICU_clearTimerValue();
		/* Detect rising edge */
		ICU_setEdgeDetectionType(RAISING);

		g_edgeCount = 0 ;
	}
}

/*
 * Description : Function to initialize the Ultrasonic driver
 * 	1. Set the required clock.
 * 	2. Set the required edge detection.
 * 	3. Set callback function.
 * 	4. Set pin trigger direction
 */
void Ultrasonic_init(void)
{
	ICU_ConfigType ptr = {F_CPU_8,RAISING};

	ICU_init(&ptr);

	ICU_setCallBack(Ultrasonic_edgeProcessing);

	GPIO_setupPinDirection(ULTRASONIC_PORT_ID,ULTRASONIC_TRIGGER_PIN_ID,PIN_OUTPUT);
}

/*
 * Send the trigger pulse
 */
void Ultrasonic_Trigger(void)
{
	GPIO_writePin(ULTRASONIC_PORT_ID, ULTRASONIC_TRIGGER_PIN_ID, LOGIC_HIGH);
	_delay_us(30);
	GPIO_writePin(ULTRASONIC_PORT_ID, ULTRASONIC_TRIGGER_PIN_ID, LOGIC_LOW);
}

/*
 * Function to get the Distance Value.
 */
uint16 Ultrasonic_readDistance(void)
{
	Ultrasonic_Trigger();

	g_distance = (uint16)( g_time / 115);

	return g_distance ;
}




