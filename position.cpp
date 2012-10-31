/* -----------------------------------
 * Mentors Team
 * -----------------------------------
 * ultrasonic.c
 * source code for position controller
 *
 * created by: FENG Zili
 * date: 2012.11.01
*/

#include "position.h"

void Position::saveCurrentPosition() {

}

Position::Position() {}

void Position::getPosition(int &x, int &y) {
    x = _x;
    y = _y;
}
