/* ----------------------------------- 
 * Mentors Team
 * ----------------------------------- 
 * infrared.h
 * header file for infrared-ray sensor
 *
 * created by: FENG Zili
 * date: 2012.09.20
*/

#ifndef _INFRARED_H_
#define _INFRARED_H_

#include "basic_types.h"

typedef enum {
    InfraredSensorFront,
    InfraredSensorLeft,
    InfraredSensorRight,
    InfraredSensorBack
} InfraredSensor;

bool IsBlackLineUnderSensor(InfraredSensor sensor);

#endif
