#ifndef DAQLIB_H_NIX
#define DAQLIB_H_NIX

#ifdef _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <DAQdisplay.h>

int setupDAQ(int setupNum);
int continueSuperLoop(void);
int digitalRead(int channelNumber);
int digitalWrite(int channelNumber, int value);
int displayWrite(int channelNumber, int value);

int setupDAQ(int setupNum)
{
	return daqd_startWindow(1);
	
	
}


#else
#error Visual Studio requires _CRT_SECURE_NO_WARNINGS to be defined.
#endif
#endif
