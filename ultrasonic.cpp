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
extern int startCountOfUSSensor, stopCountOfUSSensor;
extern void delay(int time);

UltrasonicSensor::UltrasonicSensor() {
    _distance = INFINITE_DISTANCE;
    _isBusy = false;
}

/*
void UltrasonicSensor::setTimerCount(int timerCount) { _timerCount = timerCount; }
*/

void UltrasonicSensor::setResult() { 
    _distance = (stopCountOfUSSensor - startCountOfUSSensor) * (340.0/2.0) * (1.0/512.0/1024.0) *5.0;
    _isBusy = false;
}

void UltrasonicSensor::beginSensing() {
    if (_isBusy) return;
    _isBusy = true;
    /* P1.2 - sensor #1 echo
    */
    P3DIR |= 0xe0;
    P3OUT &= ~0xe0;
    P1DIR = BIT0+BIT4;                        //����P1.0����Ϊ���
    P1SEL = BIT2;                             //����P1.2�˿�Ϊ����ģ��ʹ��
    TACTL = TASSEL1+TACLR+TAIE+MC1+ID_3;      //��ʱ��Aʱ���ź�ѡ��ACLK,ͬʱ���ö�ʱ��A����ģʽΪ��������ģʽ
    CCTL1 = CM0+SCS+CAP+CCIE;                 //���������ز���,CCI0AΪ�����ź�Դ
    _EINT(); 

    /* P3.5 - sensor #1 trig
     * P3.6 - sensor #2 trig
     * P3.7 - sensor #3 trig
    */
    for (int i=0; i<20; i++) _NOP();
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

#pragma vector=TIMERA1_VECTOR              //��ʱ��A�жϴ���
__interrupt void didDetectEdge(void)
{
 switch(TAIV)                              //������ѯ
  { case 2:                                //�����ж�
        if(CCTL1&CM0)                      //������
         {
           CCTL1=(CCTL1&(~CM0))|CM1;       //��������Ϊ�½��ش���
           startCountOfUSSensor = TAR;                      //��¼��ʼʱ��
           //overflow=0;                     //�������������λ
         }
       else if (CCTL1&CM1)                 //�½���
        {  
           CCTL1=(CCTL1&(~CM1))|CM0;       //��������Ϊ�����ش���
           stopCountOfUSSensor = TAR;                        //��start,end,overflow����������
           usSensor.setResult();
        }    
       break;
    case 10:                               //��ʱ������ж�
       //overflow++;
       break;                              //���������1
    default:break;
  }
}

/*
void didGetDistanceWithUltrasonicSensor(UltrasonicSensor *sensor) {
    
}
*/