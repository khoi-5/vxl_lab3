/*
 * light_traffic.c
 *
 *  Created on: Oct 15, 2025
 *      Author: DELL
 */


#include "light_traffic.h"
#include "global.h"
#include "main.h"


// ====== Config ======
#define NUM_LEDS      12
#define NUM_PATTERNS  4

// Nếu phần cứng active-high, giữ như dưới.
// Nếu là active-low (common anode), có thể đổi ACTIVE/INACTIVE tương ứng.
#define ACTIVE   GPIO_PIN_SET
#define INACTIVE GPIO_PIN_RESET

// ====== LED Port/Pin Maps ======
GPIO_TypeDef *LED_PORTS[NUM_LEDS] = {
    LED_1_GPIO_Port,  LED_2_GPIO_Port,  LED_3_GPIO_Port,  LED_4_GPIO_Port,
    LED_5_GPIO_Port,  LED_6_GPIO_Port,  LED_7_GPIO_Port,  LED_8_GPIO_Port,
    LED_9_GPIO_Port,  LED_10_GPIO_Port, LED_11_GPIO_Port, LED_12_GPIO_Port
};

uint16_t LED_PINS[NUM_LEDS] = {
    LED_1_Pin,  LED_2_Pin,  LED_3_Pin,  LED_4_Pin,
    LED_5_Pin,  LED_6_Pin,  LED_7_Pin,  LED_8_Pin,
    LED_9_Pin,  LED_10_Pin, LED_11_Pin, LED_12_Pin
};

// ====== LED Patterns (4 trạng thái × 12 đèn) ======
// [0] green+red, [1] yellow+red, [2] red+green, [3] red+yellow

GPIO_PinState LEDS_state[NUM_PATTERNS][NUM_LEDS] = {
	//  XANH ,     VANG   ,  DO     , XANH   ,   VANG    , DO
    // pattern 0
    { INACTIVE, INACTIVE, ACTIVE, ACTIVE, INACTIVE, INACTIVE,
      INACTIVE, INACTIVE, ACTIVE, ACTIVE, INACTIVE, INACTIVE },

    // pattern 1
    { INACTIVE, INACTIVE, ACTIVE, INACTIVE, ACTIVE, INACTIVE,
      INACTIVE, INACTIVE, ACTIVE, INACTIVE, ACTIVE, INACTIVE },

    // pattern 2
    { ACTIVE, INACTIVE, INACTIVE, INACTIVE, INACTIVE, ACTIVE,
      ACTIVE, INACTIVE, INACTIVE, INACTIVE, INACTIVE, ACTIVE },

    // pattern 3
    { INACTIVE, ACTIVE, INACTIVE, INACTIVE, INACTIVE, ACTIVE,
      INACTIVE, ACTIVE, INACTIVE, INACTIVE, INACTIVE, ACTIVE }
};

// ====== Helpers ======
static inline void set_LEDS(const GPIO_PinState *state) {
    for (size_t i = 0; i < NUM_LEDS; ++i) {
        HAL_GPIO_WritePin(LED_PORTS[i], LED_PINS[i], state[i]);
    }
}

static inline void clear_all_leds(void) {
    for (size_t i = 0; i < NUM_LEDS; ++i) {
        HAL_GPIO_WritePin(LED_PORTS[i], LED_PINS[i], GPIO_PIN_RESET);
    }
}

// ====== Public APIs ======
void init_time(void) {
    time_red    = 5;
    time_green  = 3;
    time_yellow = 2;
}

void init(void) {
    clear_all_leds();
}

void led_red_and_green(void) {
    set_LEDS(LEDS_state[2]);
}

void led_red_and_yellow(void) {
    set_LEDS(LEDS_state[3]);
}

void led_green_and_red(void) {
    set_LEDS(LEDS_state[0]);
}

void led_yellow_and_red(void) {
    set_LEDS(LEDS_state[1]);
}

void blinking_led_red(void) {
    HAL_GPIO_TogglePin(LED_2_GPIO_Port,  LED_2_Pin);
    HAL_GPIO_TogglePin(LED_5_GPIO_Port,  LED_5_Pin);
    HAL_GPIO_TogglePin(LED_8_GPIO_Port,  LED_8_Pin);
    HAL_GPIO_TogglePin(LED_11_GPIO_Port, LED_11_Pin);
}

void blinking_led_green(void) {
    HAL_GPIO_TogglePin(LED_1_GPIO_Port,  LED_1_Pin);
    HAL_GPIO_TogglePin(LED_4_GPIO_Port,  LED_4_Pin);
    HAL_GPIO_TogglePin(LED_7_GPIO_Port,  LED_7_Pin);
    HAL_GPIO_TogglePin(LED_10_GPIO_Port, LED_10_Pin);
}

void blinking_led_yellow(void) {
    HAL_GPIO_TogglePin(LED_3_GPIO_Port,  LED_3_Pin);
    HAL_GPIO_TogglePin(LED_6_GPIO_Port,  LED_6_Pin);
    HAL_GPIO_TogglePin(LED_9_GPIO_Port,  LED_9_Pin);
    HAL_GPIO_TogglePin(LED_12_GPIO_Port, LED_12_Pin);
}
