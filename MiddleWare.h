#ifndef MIDDLEWARE_H_
#define MIDDLEWARE_H_

/*******************************************************************************
 *                                  Includes                                   *
 *******************************************************************************/

#include "std_types.h"
#include "lcd.h"
#include "Led.h"
#include "Buzzer.h"
#include "UltraSonic.h"
#include "avr/io.h"
#include <avr/interrupt.h>


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void Initialization (void);
void Display_Ultrasonic (void);
void Distance_LED_Buzzer_Mapping (void);

#endif
