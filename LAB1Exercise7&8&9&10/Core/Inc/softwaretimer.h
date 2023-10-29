/*
 * softwaretimer.h
 *
 *  Created on: Oct 29, 2023
 *      Author: quoca
 */

#ifndef INC_SOFTWARETIMER_H_
#define INC_SOFTWARETIMER_H_

extern int timerflag0;
extern int timerflag1;
extern int timerflag2;

void settimer0(int duration);
void runtimer0();

void settimer1(int duration);
void runtimer1();

void settimer2(int duration);
void runtimer2();

#endif /* INC_SOFTWARETIMER_H_ */
