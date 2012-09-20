/* ----------------------------------- 
 * Mentors Team
 * ----------------------------------- 
 * ultrasonic.h
 * header file for ultrasonic ranging sensor
 *
 * created by: FENG Zili
 * date: 2012.09.20
*/

#ifndef _ULTRASONIC_H_
#define _ULTRASONIC_H_

void BeginSensing();

/* ------------------------------ 
 * Interrupts
 * ------------------------------
*/
/*
#pragma vector=DID_SEND_BEGIN_SENSING_MESSAGE
__interupt DidSendBeginSensingMessage();

#pragma vector=GET_ULTRASONIC_SIGNAL_UP
__interupt DidReceiveUltrasonicSignalUp();

#pragma vector=GET_ULTRASONIC_SIGNAL_DOWN
__interupt DidReceiveUltrasonicSignalDown();
*/

#endif
