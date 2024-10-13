#include "MiddleWare.h"
/*******************************************************************************
 *                             Main Function                                   *
 *******************************************************************************/
int main (void)
{

	Initialization ();

	while(1)
	{
		Display_Ultrasonic ();
		Distance_LED_Buzzer_Mapping ();
	}
}
