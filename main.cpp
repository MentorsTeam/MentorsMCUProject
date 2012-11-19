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
int startCountOfUSSensor, stopCountOfUSSensor;
float distance;

void systemConfig();
void delay(int time);

int main(void) {
  	float distanceNear = kDistanceNearInitial;
	ControllMode currentMode = ControllModeSearching;
	int approachCount = 30000, backOffCount = 0;
        int iDontKnowCountPrimary = 30, iDontKnowCountSecondary = 500;
	bool USSensorWorking = false;
        distance = usSensor.getResult();
        if(distance > kApproachDistanceMin && distance < distanceNear) USSensorWorking = true;
	int programCount = 0;
  
    systemConfig();
    stopMove();
    delay(200);
    beginMoveForward();
    delay(75);
    beginTurnRight();
    delay(9);
    stopMove();
    delay(100);
    beginMoveForward();
    delay(100);
    beginTurnRight();
    delay(5);
    beginMoveForward();
    delay(150);
    beginMoveBackward();
    delay(8);
    beginTurnRight();
    delay(40);
    beginMoveForward();
    delay(60);
    beginMoveBackward();
    delay(30);
        beginTurnRight();
    delay(40);
    beginMoveForward();
    delay(60);
    beginMoveBackward();
    delay(30);
    while (true) {
        // Stop watchdog timer to prevent time out reset
        WDTCTL = WDTPW + WDTHOLD;
		/*programCount ++;
		if (programCount == 0xffff) {
		    WDTCTL = WDTPW|0xff00;
		}
                */
        //delay(10);
        usSensor.beginSensing();
        distance = usSensor.getResult();
        USSensorWorking = false;
        if(distance > kApproachDistanceMin && distance < distanceNear) USSensorWorking = true;
		switch (currentMode) {
		  
		case ControllModeSearching:
			if (USSensorWorking) {
       				beginMoveForward();
				if (currentMode != ControllModeApproaching) {
			  		approachCount = kApproachCountMax;
				}
			        currentMode = ControllModeApproaching;
			}
                        else {
                          beginTurnLeft();
                          iDontKnowCountPrimary --;
                          if (iDontKnowCountPrimary == 0) {
                              iDontKnowCountPrimary = 10;
                              iDontKnowCountSecondary --;
                              if (iDontKnowCountSecondary == 0) {
                                  iDontKnowCountSecondary = 500;
                                  currentMode = ControllModeIDontKnowWhatTheHellShouldIDo;
                              }
                          }
                        }
			break;
                        
                case ControllModeIDontKnowWhatTheHellShouldIDo:
                        beginMoveForward();
                        iDontKnowCountPrimary --;
                          if (iDontKnowCountPrimary == 0) {
                              iDontKnowCountPrimary = 20;
                              iDontKnowCountSecondary --;
                              if (iDontKnowCountSecondary == 0) {
                                  iDontKnowCountSecondary = 500;
                                  currentMode = ControllModeSearching;
                              }
                          }
                        break;
			
		case ControllModeApproaching:
                        if(USSensorWorking) {
                          beginMoveForward();
                          delay(1);
                          if(distance < 0.2)
                          {
                            delay(240);
                            approachCount = kApproachCountMax;
                            currentMode = ControllModeBackingOff;
                          }
                          else if(distance < 0.5)
                          {
                            approachCount = 600;
                          }
                          else if(distance < 1.0)
                          {
                            approachCount = 1200;
                          }
                        }
                        else {
                          approachCount--;
                          beginMoveForward();
                          delay(1);
		  	  if (approachCount <= 0) {
			  	approachCount = kApproachCountMax;
				currentMode = ControllModeBackingOff;
                          }
                        }
                        /*
                        if (distance < kApproachDistanceMin) {
                            approachCount = 0;
                            currentMode = ControllModeBackingOff;
                        }
                        */
			break;
			
		case ControllModeBackingOff:
                  if (backOffCount == 0) {
                        stopMove();
                        beginRotateBackward(MotorLeft);
                        delay(60);
                  }
		  	beginMoveBackward();
                        delay(120);
                        /*
                        backOffCount++;
		 	if (backOffCount >= kBackOffCountMax) {
		        backOffCount = 0;
                        */
				currentMode = ControllModeSearching;
		  	//}
		  	break;
		}
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
        for (j=0; j<0xfff; j++) {
          WDTCTL = WDTPW + WDTHOLD;
              i++;
              i--;
        }
}
