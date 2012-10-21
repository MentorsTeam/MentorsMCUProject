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

void SystemConfig();
void Delay(int time);

int main(void) {
    SystemConfig();
  
    while (YES) {
        // Stop watchdog timer to prevent time out reset
        WDTCTL = WDTPW + WDTHOLD;
        
        // TODO
        //BeginMoveForward();
        /*Delay(1);
        StopRotate(MotorLeft);
        Delay(1);
        BeginRotateForward(MotorLeft);
        Delay(1);
        StopRotate(MotorRight);
        Delay(1);
        BeginRotateForward(MotorRight);
        Delay(1);
        StopMove();*/
        
        BeginMoveBackward();
        /*Delay(1);
        StopRotate(MotorLeft);
        Delay(1);
        BeginRotateBackward(MotorLeft);
        Delay(1);
        StopRotate(MotorRight);
        Delay(1);
        BeginRotateBackward(MotorRight);
        Delay(1);
        StopMove();*/
  }
  
}

void SystemConfig() {
    P3DIR = 0x0f;  // Motors
}

void Delay(int time) {
    time <<= 1;
    int i, j;
    for (i=0; i<time; i++)
        for (j=0; j<0xffff; j++) {
             i ++;
             i --;
        }
}