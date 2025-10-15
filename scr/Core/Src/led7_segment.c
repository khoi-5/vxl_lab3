/*
 * led7_segment.c
 *
 *  Created on: Oct 15, 2025
 *      Author: DELL
 */

#include "led7_segment.h"
#include "main.h"

GPIO_TypeDef *SEG_PORTS[14] = { SEG_0_GPIO_Port, SEG_1_GPIO_Port,
SEG_2_GPIO_Port, SEG_3_GPIO_Port, SEG_4_GPIO_Port, SEG_5_GPIO_Port,
SEG_6_GPIO_Port, SEG_7_GPIO_Port, SEG_8_GPIO_Port, SEG_9_GPIO_Port,
SEG_10_GPIO_Port, SEG_11_GPIO_Port, SEG_12_GPIO_Port, SEG_13_GPIO_Port };
uint16_t SEG_PINS[14] = { SEG_0_Pin, SEG_1_Pin, SEG_2_Pin, SEG_3_Pin,
SEG_4_Pin, SEG_5_Pin, SEG_6_Pin, SEG_7_Pin, SEG_8_Pin, SEG_9_Pin, SEG_10_Pin,
SEG_11_Pin, SEG_12_Pin, SEG_13_Pin };
GPIO_PinState LEDS_7SEG_state[10][7] = { { 0, 0, 0, 0, 0, 0, 1 }, { 1, 0, 0, 1,
		1, 1, 1 }, { 0, 0, 1, 0, 0, 1, 0 }, { 0, 0, 0, 0, 1, 1, 0 }, { 1, 0, 0,
		1, 1, 0, 0 }, { 0, 1, 0, 0, 1, 0, 0 }, { 0, 1, 0, 0, 0, 0, 0 }, { 0, 0,
		0, 1, 1, 1, 1 }, { 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 1, 0, 0 } };

void set_7SEG_X(const GPIO_PinState *L_LEDS_X_state) {
	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
	for (int i = 0; i < 7; i++) {
		HAL_GPIO_WritePin(SEG_PORTS[i], SEG_PINS[i], L_LEDS_X_state[i]);
	}
}

void set_7SEG_X_left(const GPIO_PinState *L_LEDS_X_state) {
	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
	for (int i = 0; i < 7; i++) {
		HAL_GPIO_WritePin(SEG_PORTS[i], SEG_PINS[i], L_LEDS_X_state[i]);
	}
}

void set_7SEG_Y(const GPIO_PinState *L_LEDS_Y_state) {
	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
	for (int i = 0; i < 7; i++) {
		HAL_GPIO_WritePin(SEG_PORTS[i + 7], SEG_PINS[i + 7], L_LEDS_Y_state[i]);
	}
}

void set_7SEG_Y_left(const GPIO_PinState *L_LEDS_Y_state) {
	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
	for (int i = 0; i < 7; i++) {
		HAL_GPIO_WritePin(SEG_PORTS[i + 7], SEG_PINS[i + 7], L_LEDS_Y_state[i]);
	}
}

void displaySetting(int time) {
	switch (counter1) {
	case 0:
		set_7SEG_Y_left(LEDS_7SEG_state[time / 10]);
		counter1 = 1;
		break;
	case 1:
		set_7SEG_Y(LEDS_7SEG_state[time % 10]);
		counter1 = 0;
		break;
	default:
		break;
	}
}

void displaySettingX(int time) {
	switch (counter2) {
	case 0:
		set_7SEG_X_left(LEDS_7SEG_state[time / 10]);
		counter2 = 1;
		break;
	case 1:
		set_7SEG_X(LEDS_7SEG_state[time % 10]);
		counter2 = 0;
		break;
	default:
		break;
	}
}
