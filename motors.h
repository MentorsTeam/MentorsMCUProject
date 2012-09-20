/* ----------------------------------- 
 * Mentors Team
 * ----------------------------------- 
 * motors.h
 * header file for main motors - left & right
 *
 * created by: FENG Zili
 * date: 2012.09.20
*/

#ifndef _MOTORS_H_
#define _MOTORS_H_

enum {
    MotorLeft,
    MotorRight
} Motor;

void BeginRotateForward(Motor motor);
void BeginRotateBackward(Motor motor);
void BeginMoveAhead();
void BeginMoveBackward();

void StopRotate(Motor moter);
void StopMove();

#endif
