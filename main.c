/* ----------------------------------- 
 * Mentors Team
 * ----------------------------------- 
 * main.c
 * main file of the project
 *
 * created by: FENG Zili
 * date: 2012.09.20
*/

#include "msp430f149.h"

/* ------------------------------ 
 * Project architecture
 * ------------------------------ 
 * sensors.h - (hub header file for sensors)
 *           - ultrasonic.h   --> low level functions for ultrasonic sensing
 *           - infrared.h     --> low level functions for infrared-ray sensing
 *           - motion_meter.h --> low level functions for motion sensing
 *           - compass.h      --> low level functions for direction sensing
 *           - camera.h       --> low level functions for graphic sensing
 *
 * motions.h - (hub header file for motion control)
 *           - motors.h       --> low level functions for main motors control
 *           - sensing_motor.h--> low level functions for sensor motor
 *
 * parameters.h               --> parameters (eg. constants) used
 * basic_types.h              --> basic variable types defination
*/
#include "sensors.h"
#include "motions.h"
#include "parameters.h"
#include "basic_types.h"

int main(void) {
  
  while (YES) {
      // Stop watchdog timer to prevent time out reset
      WDTCTL = WDTPW + WDTHOLD;
      
      // TODO
      
  }
  
}
