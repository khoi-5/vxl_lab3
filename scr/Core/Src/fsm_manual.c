/*
 * fsm_manual.c
 *
 *  Created on: Nov 1, 2025
 *      Author: DELL
 */


#include "fsm_maunal.h"
void manual_inc_time_xy(void){
    if (isButton1Pressed(1) != 1) return; // one-shot edge

    switch (status) {
    case MAN_RED_GREEN:
        // X: RED,  Y: GREEN
        time_red_x   = inc99(time_red_x);
        time_green_y = inc99(time_green_y);
        set_counter_for_traffic_light(time_red_x, time_green_y);
        break;

    case MAN_RED_YELLOW:
        // X: RED,  Y: YELLOW
        time_red_x     = inc99(time_red_x);
        time_yellow_y  = inc99(time_yellow_y);
        set_counter_for_traffic_light(time_red_x, time_yellow_y);
        break;

    case MAN_GREEN_RED:
        // X: GREEN, Y: RED
        time_green_x = inc99(time_green_x);
        time_red_y   = inc99(time_red_y);
        set_counter_for_traffic_light(time_green_x, time_red_y);
        break;

    case MAN_YELLOW_RED:
        // X: YELLOW, Y: RED
        time_yellow_x = inc99(time_yellow_x);
        time_red_y    = inc99(time_red_y);
        set_counter_for_traffic_light(time_yellow_x, time_red_y);
        break;

    default:
        break;
    }
    // Nếu bạn muốn lưu cấu hình mới để AUTO dùng ngay khi thoát MANUAL,
    // thì không cần làm gì thêm — các biến time_* đã được cập nhật.
}

void fsm_manual_run(){
    switch (status) {


    case MAN_RED_GREEN:
		if (isButton1Pressed(0) == 1) {
			init();
			status = MAN_RED_YELLOW;
		}
        if (timer_flag[2]) {
    		blinking_red_x_green_y();
            setTimer(2, 250);
        }
        manual_inc_time_xy();
        break;

    case MAN_RED_YELLOW:
		if (isButton1Pressed(0) == 1) {
			init();
			status = MAN_GREEN_RED;
		}
        if (timer_flag[2]) {
    		blinking_red_x_yellow_y();
            setTimer(2, 250);
        }
        manual_inc_time_xy();
        break;


    case MAN_GREEN_RED:
		if (isButton1Pressed(0) == 1) {
			init();
			status = MAN_YELLOW_RED;
		}
        if (timer_flag[2]) {
    		blinking_green_x_red_y();
            setTimer(2, 250);
        }
        manual_inc_time_xy();
        break;


    case MAN_YELLOW_RED:
		if (isButton1Pressed(0) == 1) {
			init();
			status = INIT;
		}
        if (timer_flag[2]) {
    		blinking_yellow_x_red_y();
            setTimer(2, 250);
        }
        manual_inc_time_xy();
        break;



    default:
        break;
    }
}
