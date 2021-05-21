/*
 * main.c
 *
 *  Created on: Mar 7, 2021
 *      Author: Administrator
 */

#include "MemMap.h"
#define F_CPU 8000000UL
#include <util/delay.h>

void sevenSegmentDisplayBCD(unsigned char num);
void SW_Play(unsigned char time);
void SW_Pause(void);
void SW_Reset(void);
void SW_SwitchMode(void);
void SW_SetIncreament(void);
void SW_SetDecreament(void);

#define   SWITCH   		0
#define   INCREAMENT   	1
#define   DECREAMENT    2
#define   PLAY_PAUSE    1
#define   RESET         2
#define   BUZZER        3

unsigned char TIMER = 10;
unsigned char tempTimer;
unsigned char timerPass;
unsigned char flagMode = 0;
unsigned char flagPlayPause = 0;

int main() {
	DDRA = 0xFF;
	PORTA = 0x00;
	DDRD = 0x08;
	PORTD = 0xF7;
	while (1) {
		SW_SwitchMode();
	}
	return 0;
}
void sevenSegmentDisplayBCD(unsigned char num) {
	if (num <= 99) {
		unsigned char rem = num % 10;
		unsigned char temp = num / 10;
		PORTA = rem | (temp << 4);
	} else
		PORTA = 0x00;
}
void SW_SwitchMode(void) {

	if (!GET_BIT(PIND, SWITCH)) {
		while (!GET_BIT(PIND, SWITCH))
			;
		flagMode ^= 1;
	}

	if (flagMode) {
		if (!GET_BIT(PIND, INCREAMENT)) {
			while (!GET_BIT(PIND, INCREAMENT))
				;
			SW_SetIncreament();
		} else if (!GET_BIT(PIND, DECREAMENT)) {
			while (!GET_BIT(PIND, DECREAMENT))
				;
			SW_SetDecreament();
		}
	} else {
		if (!GET_BIT(PIND, PLAY_PAUSE)) {
			while (!GET_BIT(PIND, PLAY_PAUSE))
				;
			flagPlayPause ^= 1;
			if (flagPlayPause) {
				SW_Play(TIMER);
			} else {
				SW_Pause();
			}
		} else if (!GET_BIT(PIND, RESET)) {
			while (!GET_BIT(PIND, RESET))
				;
			SW_Reset();
		}
	}
}
void SW_SetIncreament(void) {
	TIMER++;
	if (TIMER == 100) {
		TIMER = 0;
	}
	sevenSegmentDisplayBCD(TIMER);
}
void SW_SetDecreament(void) {
	TIMER--;
	if (TIMER == 0) {
		TIMER = 99;
	}
	sevenSegmentDisplayBCD(TIMER);
}
void SW_Play(unsigned char time) {
	tempTimer = time + 1;
	for (unsigned char i = 0; i <= time; i++) {
		tempTimer--;
		sevenSegmentDisplayBCD(tempTimer);
		_delay_ms(250);
		if (!GET_BIT(PIND, PLAY_PAUSE)) {
			while (!GET_BIT(PIND, PLAY_PAUSE))
				;
			timerPass = tempTimer;
			break;
		}
	}
	if (tempTimer == 0) {
		SET_BIT(PORTD, BUZZER);
		_delay_ms(2000);
		CLR_BIT(PORTD, BUZZER);
	}
}
void SW_Pause(void) {
	while (1) {
		if (!GET_BIT(PIND, PLAY_PAUSE)) {
			while (!GET_BIT(PIND, PLAY_PAUSE))
				;
			SW_Play(timerPass);
			break;
		}
	}
}
void SW_Reset(void) {
	sevenSegmentDisplayBCD(TIMER);
}
