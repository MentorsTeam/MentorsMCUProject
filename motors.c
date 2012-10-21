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

void BeginRotateForward(Motor motor) {
    /* 
        P3.0 --> MoterLeft-red
        P3.1 --> MoterLeft-black
        P3.2 --> MoterRight-red
        P3.3 --> MoterRight-black
    */
    switch (motor) {
        case MotorLeft:
            P3OUT &= 0xfd;
            P3OUT |= 0x01;
        break;
        
        case MotorRight:
            P3OUT &= 0xf7;
            P3OUT |= 0x04;
        break;
    }
}

void BeginRotateBackward(Motor motor) {
    switch (motor) {
        case MotorLeft:
            P3OUT &= 0xfe;
            P3OUT |= 0x02;
        break;
        
        case MotorRight:
            P3OUT &= 0xfb;
            P3OUT |= 0x08;
        break;
    }
}

void BeginMoveForward() {
    BeginRotateForward(MotorLeft);
    BeginRotateForward(MotorRight);
}

void BeginMoveBackward() {
    BeginRotateBackward(MotorLeft);
    BeginRotateBackward(MotorRight);
}

void StopRotate(Motor moter) {
    switch (moter) {
        case MotorLeft:
            P3OUT &= 0xfc;
        break;
        
        case MotorRight:
            P3OUT &= 0xf3;
        break;
    }
}

void StopMove() {
    StopRotate(MotorLeft);
    StopRotate(MotorRight);
}
