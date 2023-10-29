/*
 * softwaretimer.c
 *
 *  Created on: Oct 29, 2023
 *      Author: quoca
 */

int timerflag0 = 0;
int timercounter0 = 0;
int timerflag1 = 0;
int timercounter1 = 0;
int timerflag2 = 0;
int timercounter2 = 0;

void settimer0(int duration)
{
	timercounter0 = duration;
	timerflag0 = 0;
}

void runtimer0()
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

void settimer1(int duration)
{
	timercounter1 = duration;
	timerflag1 = 0;
}

void runtimer1()
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

void settimer2(int duration)
{
	timercounter2 = duration;
	timerflag2 = 0;
}

void runtimer2()
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
