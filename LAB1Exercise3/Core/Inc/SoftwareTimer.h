/*
 * SoftwareTimer.h
 *
 *  Created on: Oct 5, 2023
 *      Author: quoca
 */

#ifndef INC_SOFTWARETIMER_H_
#define INC_SOFTWARETIMER_H_

extern int timerflag;
extern int timerflag0;

void setTimer(int duration);
void runTimer();
void setTimer0(int duration);
void runTimer0();
#endif /* INC_SOFTWARETIMER_H_ */
