/*
 * SoftwareTimer.c
 *
 *  Created on: Oct 5, 2023
 *      Author: quoca
 */
#include "SoftwareTimer.h"

int timercounter = 0;
int timerflag = 0;

void setTimer(int duration)
{
	timercounter = duration;
	timerflag = 0;
}

void runTimer()
{
	if (timercounter > 0)
	{
		timercounter--;
		if (timercounter <= 0)
		{
			timerflag = 1;
		}
	}
}
int timercounter0 = 0;
int timerflag0 = 0;

void setTimer0(int duration)
{
	timercounter0 = duration;
	timerflag0 = 0;
}

void runTimer0()
{
	if (timercounter0 > 0)
	{
		timercounter0--;
		if (timercounter0 <= 0)
		{
			timerflag0 = 1;
		}
	}
}
