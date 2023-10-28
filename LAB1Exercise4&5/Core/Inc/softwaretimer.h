/*
 * softwaretimer.h
 *
 *  Created on: Oct 22, 2023
 *      Author: quoca
 */

#ifndef INC_SOFTWARETIMER_H_
#define INC_SOFTWARETIMER_H_

extern int timerflag;
extern int timerflag0;
extern int timerflag1;
extern int timerflag2;

void setTimer(int duration);
void runTimer();
void setTimer0(int duration);
void runTimer0();
void setTimer1(int duration);
void runTimer1();
void setTimer2(int duration);
void runTimer2();

#endif /* INC_SOFTWARETIMER_H_ */
