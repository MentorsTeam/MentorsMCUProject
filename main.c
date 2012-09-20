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
#include "sensor.h"
#include "motion.h"

int main(void) {
  
  while (1) {
      // Stop watchdog timer to prevent time out reset
      WDTCTL = WDTPW + WDTHOLD;
      
      // TODO
  }
  
}
