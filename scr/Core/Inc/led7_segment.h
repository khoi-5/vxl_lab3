/*
 * led7_segment.h
 *
 *  Created on: Oct 15, 2025
 *      Author: DELL
 */

#ifndef INC_LED7_SEGMENT_H_
#define INC_LED7_SEGMENT_H_

#include "main.h"
#include "global.h"

extern int red_time;
extern int green_time;
extern int yellow_time;

GPIO_TypeDef *SEG_PORTS[14];
uint16_t SEG_PINS[14];
GPIO_PinState LEDS_7SEG_state[10][7];
void set_7SEG_X(const GPIO_PinState *L_LEDS_X_state);
void set_7SEG_X_left(const GPIO_PinState *L_LEDS_X_state);
void set_7SEG_Y(const GPIO_PinState *L_LEDS_Y_state);
void set_7SEG_Y_left(const GPIO_PinState *L_LEDS_Y_state);
void displaySetting(int time);
void displaySettingX(int time);


#endif /* INC_LED7_SEGMENT_H_ */
