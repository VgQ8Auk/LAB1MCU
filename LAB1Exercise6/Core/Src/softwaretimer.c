/*
 * softwaretimer.c
 *
 *  Created on: Oct 29, 2023
 *      Author: quoca
 */

int timerflag0 = 0;
int timercounter0 = 0;

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
