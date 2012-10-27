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
#include "system.h"

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

UltrasonicSensor usSensor;

void systemConfig();
void delay(int time);

int main(void) {
    systemConfig();

    while (true) {
        // Stop watchdog timer to prevent time out reset
        WDTCTL = WDTPW + WDTHOLD;
        
        usSensor.beginSensing();
        
        float distance = usSensor.getResult();
        if (distance < 0.5) {
            beginMoveBackward();
        }
        else {
            beginMoveForward();
        }
        
        // TODO
        /*
        beginMoveForward();
        delay(1);
        stopRotate(MotorLeft);
        delay(1);
        beginRotateForward(MotorLeft);
        delay(1);
        stopRotate(MotorRight);
        delay(1);
        beginRotateForward(MotorRight);
        delay(1);
        stopMove();
        
        beginMoveBackward(); 
        delay(1);
        stopRotate(MotorLeft);
        delay(1);
        beginRotateBackward(MotorLeft);
        delay(1);
        stopRotate(MotorRight);
        delay(1);
        beginRotateBackward(MotorRight);
        delay(1);
        stopMove();
        */
  }
}

void systemConfig() {
    P4DIR = 0x0f;  // Motors
   _EINT();
}

void delay(int time) {
    time <<= 1;
    int i, j;
    for (i=0; i<time; i++)
        for (j=0; j<0xffff; j++) {
          WDTCTL = WDTPW + WDTHOLD;
             i ++;
             i --;
        }
}