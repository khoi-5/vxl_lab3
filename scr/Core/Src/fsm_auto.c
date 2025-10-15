/*
 * fsm_auto.c
 *
 *  Created on: Oct 15, 2025
 *      Author: DELL
 */

#include  "main.h"
#include "fsm_auto.h"
#include "led7_segment.h"
#include "light_traffic.h"


void fsm_auto_run() {
	switch (status) {
	case INIT:
		HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, SET);
		init();
		status = AUTO_RED;
		setTimer(0, 1000);
		break;
	case AUTO_RED:
		led_red_and_green();
		set_7SEG_X(LEDS_7SEG_state[time_green]);
		set_7SEG_Y(LEDS_7SEG_state[time_red]);
		if (timer_flag[0] == 1) {
			time_green--;
			time_red--;
			if (time_green == 0) {
				status = AUTO_YELLOW;
			}
			setTimer(0, 1000);
		}
		if (isButton1Pressed(0) == 1) {
			init();
			status = MAN_RED;
			setTimer(0, 100000);
			setTimer(1, 250);
			setTimer(2, 250);
		}
		break;
	case AUTO_GREEN:
		led_green_and_red();
		set_7SEG_X(LEDS_7SEG_state[time_red]);
		set_7SEG_Y(LEDS_7SEG_state[time_green]);
		if (timer_flag[0] == 1) {
			time_green--;
			time_red--;
			if (time_green == 0) {
				status = AUTO_YELLOW_MAIN;
			}
			setTimer(0, 1000);
		}
		if (isButton1Pressed(0) == 1) {
			init();
			status = MAN_RED;
			setTimer(0, 1000);

		}
		break;
	case AUTO_YELLOW_MAIN:
		led_yellow_and_red();
		set_7SEG_X(LEDS_7SEG_state[time_red]);
		set_7SEG_Y(LEDS_7SEG_state[time_yellow]);
		if (timer_flag[0] == 1) {
			time_red--;
			time_yellow--;
			if (time_red == 0) {
				init_time();
				status = AUTO_RED;
			}
			setTimer(0, 1000);
		}
		if (isButton1Pressed(0) == 1) {
			init();
			status = MAN_RED;
			setTimer(0, 1000);

		}
		break;
	case AUTO_YELLOW:
		led_red_and_yellow();
		set_7SEG_X(LEDS_7SEG_state[time_yellow]);
		set_7SEG_Y(LEDS_7SEG_state[time_red]);
		if (timer_flag[0] == 1) {
			time_red--;
			time_yellow--;
			if (time_red == 0) {
				init_time();
				status = AUTO_GREEN;
			}
			setTimer(0, 1000);
		}
		if (isButton1Pressed(0) == 1) {
			init();
			status = MAN_RED;
			setTimer(0, 1000);

		}
		break;
	default:
		break;
	}
}

