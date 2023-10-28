/*
 * softwaretimer.c
 *
 *  Created on: Oct 22, 2023
 *      Author: quoca
 */

#include "softwaretimer.h"
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
int timercounter1 = 0;
int timerflag1 = 0;

void setTimer1(int duration)
{
	timercounter1 = duration;
	timerflag1 = 0;
}

void runTimer1()
{
	if (timercounter1 > 0)
	{
		timercounter1--;
		if (timercounter1 <= 0)
		{
			timerflag1 = 1;
		}
	}
}
int timercounter2 = 0;
int timerflag2 = 0;

void setTimer2(int duration)
{
	timercounter2 = duration;
	timerflag2 = 0;
}

void runTimer2()
{
	if (timercounter2 > 0)
	{
		timercounter2--;
		if (timercounter2 <= 0)
		{
			timerflag2 = 1;
		}
	}
}
