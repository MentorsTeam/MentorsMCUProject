/* -----------------------------------
 * Mentors Team
 * ----------------------------------- 
 * position.h
 * header file for position controller class
 *
 * created by: FENG Zili
 * date: 2012.11.01
*/

#include "msp430f149.h"
#include "system.h"

#ifndef _POSITION_H_
#define _POSITION_H_

class Position {
    int _x, _y;
    int _dx, _dy;
    int _direction, _dDirection;
    // TODO


private:
    void saveCurrentPosition();

public:
    Position();
    void getPosition(int &x, int &y);

    void didReceiveUltrasonicData(float distance);
    void didReceiveInfraredData();
};

#endif
