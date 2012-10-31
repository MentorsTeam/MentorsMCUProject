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
    P1DIR = BIT0+BIT4;                        //设置P1.0方向为输出
    P1SEL = BIT2;                             //设置P1.2端口为功能模块使用
    TACTL = TASSEL1+TACLR+TAIE+MC1+ID_3;      //定时器A时钟信号选择ACLK,同时设置定时器A计数模式为连续增计模式
    CCTL1 = CM0+SCS+CAP+CCIE;                 //输入上升沿捕获,CCI0A为捕获信号源
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

#pragma vector=TIMERA1_VECTOR              //定时器A中断处理
__interrupt void didDetectEdge(void)
{
 switch(TAIV)                              //向量查询
  { case 2:                                //捕获中断
        if(CCTL1&CM0)                      //上升沿
         {
           CCTL1=(CCTL1&(~CM0))|CM1;       //更变设置为下降沿触发
           startCountOfUSSensor = TAR;                      //记录初始时间
           //overflow=0;                     //溢出计数变量复位
         }
       else if (CCTL1&CM1)                 //下降沿
        {  
           CCTL1=(CCTL1&(~CM1))|CM0;       //更变设置为上升沿触发
           stopCountOfUSSensor = TAR;                        //用start,end,overflow计算脉冲宽度
           usSensor.setResult();
        }    
       break;
    case 10:                               //定时器溢出中断
       //overflow++;
       break;                              //溢出计数加1
    default:break;
  }
}

/*
void didGetDistanceWithUltrasonicSensor(UltrasonicSensor *sensor) {
    
}
*/