#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_
#include "std_types.h"
#include "gpio.h"

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/



/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define ULTRASONIC_PORT_ID                PORTD_ID
#define ULTRASONIC_TRIGGER_PIN_ID         PIN7_ID
#define ULTRASONIC_ECHO_PIN_ID            PIN6_ID

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/* This is the call-back function */
void  Ultrasonic_edgeProcessing(void);

/*
 * Description : Function to initialize the Ultrasonic driver
 * 	1. Set the required clock.
 * 	2. Set the required edge detection.
 * 	3. Set callback function.
 * 	4. Set pin trigger direction
 */
void Ultrasonic_init(void);

/*
 * Send the trigger pulse
 */
void Ultrasonic_Trigger(void);

/*
 * Function to get the Distance Value.
 */
uint16 Ultrasonic_readDistance(void);



#endif /* ULTRASONIC_H_ */
