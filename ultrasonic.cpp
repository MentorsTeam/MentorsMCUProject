/* ----------------------------------- 
 * Mentors Team
 * ----------------------------------- 
 * ultrasonic.c
 * source code for ultrasonic ranging sensor
 *
 * created by: FENG Zili
 * date: 2012.09.20
*/

#include "ultrasonic.h"

extern UltrasonicSensor usSensor;

UltrasonicSensor::UltrasonicSensor() {
    
}

void UltrasonicSensor::setTimerCount(int timerCount) { _timerCount = timerCount; }

void UltrasonicSensor::setResult(int currentTimerCount) { 
    _distance = (currentTimerCount - _timerCount) * (340.0/2.0) * (1.0/512.0/1024.0);
}

void UltrasonicSensor::beginSensing() {
    if (isBusy) return;
    
    TACTL = TASSEL_2 + ID_3 + MC_1 + TACLR;
    P1IE |= 0x01;
    P1IES &= ~0x01;
    
    /* P3.5 - sensor #1
     * P3.6 - sensor #2
     * P3.7 - sensor #3
    */
    P3DIR |= 0xe0;
    P3OUT |= 0xe0;
    for (int i=0; i<20; i++) _NOP();
    P3OUT &= ~0xe0;
}

float UltrasonicSensor::getResult() {
    return _distance;
}                  

/* ------------------------------ 
 * Interrupts
 * ------------------------------
*/

#pragma vector=PORT1_VECTOR
__interrupt void didDetectEdge() {
    switch (P1IFG) {
        // Rising edge
        case 0x01:
            P1IE &= ~0x01;
            P1IFG &= ~0x01;
            usSensor.setTimerCount(TAR);
            P1IE |= 0x02;
            P1IES &= ~0x02;
            break;
        
        // Falling edge
        case 0x02:
            P1IE &= ~0x02;
            P1IFG &= ~0x02;
            usSensor.setResult(TAR);
            break;
    }
    
}

void didGetDistanceWithUltrasonicSensor(UltrasonicSensor *sensor) {
    
}