/*
 * fsm_auto.c
 *
 *  Created on: Oct 15, 2025
 *      Author: DELL
 */


#include "fsm_auto.h"
void fsm_auto_run();
void set_counter_for_traffic_light(int time1, int time2){
	count_x = time1;
	count_y = time2;
}


void fsm_auto_run(void) {
    switch (status) {
    case INIT:
        init();
        setTimer(9, SCAN);

        status = RED_GREEN;
        setTimer(0, 1000);
        setTimer(1, time_green_y * 1000);
        set_counter_for_traffic_light(time_red_x, time_green_y);

        break;

    case RED_GREEN:
        led_red_and_green();

        if (timer_flag[0]) {
            if (count_x   > 0) count_x--;
            if (count_y > 0) count_y--;
            display_7led(count_x, count_y);
            setTimer(0, 1000);
        }
        if (timer_flag[1]) {
            status = RED_YELLOW;
            setTimer(0, 1000);
            setTimer(1, time_yellow_y * 1000);
            set_counter_for_traffic_light(time_yellow_y, time_yellow_y);
        }
        break;

    case RED_YELLOW:
        led_red_and_yellow();

        if (timer_flag[0]) {
            if (count_x   > 0) count_x--;
            if (count_y > 0) count_y--;
            display_7led(count_x, count_y);
            setTimer(0, 1000);
        }
        if (timer_flag[1]) {
            status = GREEN_RED;
            setTimer(0, 1000);
            setTimer(1, time_green_x * 1000);
            set_counter_for_traffic_light(time_green_x, time_red_x);

        }
        break;

    case GREEN_RED:
        led_green_and_red();

        if (timer_flag[0]) {
            if (count_x   > 0) count_x--;
            if (count_y > 0) count_y--;
            display_7led(count_x, count_y);
            setTimer(0, 1000);
        }
        if (timer_flag[1]) {
            status = YELLOW_RED;
            setTimer(0, 1000);
            setTimer(1, time_yellow_x * 1000);
            set_counter_for_traffic_light(time_yellow_x, time_yellow_x);

        }
        break;

    case YELLOW_RED:
        led_yellow_and_red();

        if (timer_flag[0]) {
            if (count_x   > 0) count_x--;
            if (count_y > 0) count_y--;
            display_7led(count_x, count_y);
            setTimer(0, 1000);
        }
        if (timer_flag[1]) {
            status = RED_GREEN;
            setTimer(0, 1000);
            setTimer(1, time_green_y * 1000);
            set_counter_for_traffic_light(time_red_x, time_green_y);
        }
        break;

    default:
        break;
    }
}


