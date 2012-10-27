/* ----------------------------------- 
 * Mentors Team
 * ----------------------------------- 
 * system.h
 * header file for top-level object
 *
 * created by: FENG Zili
 * date: 2012.09.20
*/

#ifndef _SYSTEM_H_
#define _SYSTEM_H_

/* ------------------------------ 
 * Peripheral list & file structure
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

class System {
    UltrasonicSensor usSensor;
    
private:
    
public:
    System();
};

#endif
