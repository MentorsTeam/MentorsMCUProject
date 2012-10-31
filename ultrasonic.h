/* ----------------------------------- 
 * Mentors Team
 * ----------------------------------- 
 * ultrasonic.h
 * header file for ultrasonic ranging sensor
 *
 * created by: FENG Zili
 * date: 2012.09.20
*/

#include "msp430f149.h"
#include "system.h"

#ifndef _ULTRASONIC_H_
#define _ULTRASONIC_H_

class UltrasonicSensor {
    // int _timerCount;
    float _distance;
    bool _isBusy;

private:
    
public:
    UltrasonicSensor();
    // void setTimerCount(int timerCount);
    void setResult();
    
    void beginSensing();
    float getResult();
};

#endif
