/*
 * fsm_auto.c
 *
 *  Created on: Oct 15, 2025
 *      Author: DELL
 */


#include "fsm_auto.h"


void fsm_auto_run(void) {
    switch (status) {
    case INIT:
        init();
        init_time();
        status = RED_GREEN;
        setTimer(0, 1000);
        setTimer(1, time_green_y * 1000);
        setTimer(9, SCAN);
        display_7led(time_red_x, time_green_y);
        break;

    case RED_GREEN: // X đỏ, Y xanh
        led_red_and_green();

        if (timer_flag[0]) {
            if (time_red_x   > 0) time_red_x--;
            if (time_green_y > 0) time_green_y--;
            display_7led(time_red_x, time_green_y);
            // cập nhật led 7-seg
            setTimer(0, 1000);
        }
        if (timer_flag[1]) {    // hết pha Y xanh -> sang Y vàng
            status = RED_YELLOW;
            setTimer(1, time_yellow_y * 1000);
            display_7led(time_red_x, time_yellow_y);
            // refresh ngay khi chuyển pha
        }
        break;

    case RED_YELLOW: // X đỏ, Y vàng
        led_red_and_yellow();

        if (timer_flag[0]) {
            if (time_red_x    > 0) time_red_x--;
            if (time_yellow_y > 0) time_yellow_y--;
            display_7led(time_red_x, time_yellow_y);
            setTimer(0, 1000);
        }
        if (timer_flag[1]) {    // hết Y vàng -> sang X xanh
            status = GREEN_RED;
            display_7led(time_green_x, time_red_y);
            setTimer(1, time_green_x * 1000);
        }
        break;

    case GREEN_RED: // X xanh, Y đỏ
        led_green_and_red();

        if (timer_flag[0]) {
            if (time_green_x > 0) time_green_x--;
            if (time_red_y   > 0) time_red_y--;
            display_7led(time_green_x, time_red_y);
            setTimer(0, 1000);
        }
        if (timer_flag[1]) {    // hết X xanh -> sang X vàng
            status = YELLOW_RED;
            display_7led(time_yellow_x, time_red_y);
            setTimer(1, time_yellow_x * 1000);
        }
        break;

    case YELLOW_RED: // X vàng, Y đỏ
        led_yellow_and_red();

        if (timer_flag[0]) {
            if (time_yellow_x > 0) time_yellow_x--;
            if (time_red_y    > 0) time_red_y--;
            display_7led(time_yellow_x, time_red_y);
            setTimer(0, 1000);
        }
        if (timer_flag[1]) {    // hết X vàng -> vòng lại Y xanh
            status = INIT;
        }
        break;

    default:
        break;
    }
}


