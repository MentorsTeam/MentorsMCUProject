/* ----------------------------------- 
 * Mentors Team
 * ----------------------------------- 
 * ultrasonic.h
 * header file for ultrasonic ranging sensor
 *
 * created by: FENG Zili
 * date: 2012.09.20
*/

#include "system.h"

#ifndef _ULTRASONIC_H_
#define _ULTRASONIC_H_

class UltrasonicSensor {
    int _timerCount;
    float _distance;
    bool isBusy;
  
private:
    
public:
    UltrasonicSensor();
    void setTimerCount(int timerCount);
    void setResult(int currentTimerCount);
    
    void beginSensing();
    float getResult();
};

#endif
