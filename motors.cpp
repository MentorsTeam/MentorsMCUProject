/* ----------------------------------- 
 * Mentors Team
 * ----------------------------------- 
 * motors.c
 * source code for main motors - left & right
 *
 * created by: FENG Zili
 * date: 2012.09.20
*/

#include "motors.h"

void beginRotateForward(Motor motor) {
    /* 
        P4.0 --> MoterLeft-red
        P4.1 --> MoterLeft-black
        P4.2 --> MoterRight-red
        P4.3 --> MoterRight-black
    */
    switch (motor) {
        case MotorLeft:
            P4OUT &= 0xfd;
            P4OUT |= 0x01;
        break;
        
        case MotorRight:
            P4OUT &= 0xf7;
            P4OUT |= 0x04;
        break;
    }
}

void beginRotateBackward(Motor motor) {
    switch (motor) {
        case MotorLeft:
            P4OUT &= 0xfe;
            P4OUT |= 0x02;
        break;
        
        case MotorRight:
            P4OUT &= 0xfb;
            P4OUT |= 0x08;
        break;
    }
}

void beginMoveForward() {
    beginRotateForward(MotorLeft);
    beginRotateForward(MotorRight);
}

void beginMoveBackward() {
    beginRotateBackward(MotorLeft);
    beginRotateBackward(MotorRight);
}

void beginTurnLeft() {
  	beginRotateForward(MotorRight);
    beginRotateBackward(MotorLeft);
}

void beginTurnRight() {
  	beginRotateForward(MotorLeft);
    beginRotateBackward(MotorRight);
}

void stopRotate(Motor moter) {
    switch (moter) {
        case MotorLeft:
            P4OUT &= 0xfc;
        break;
        
        case MotorRight:
            P4OUT &= 0xf3;
        break;
    }
}

void stopMove() {
    stopRotate(MotorLeft);
    stopRotate(MotorRight);
}
