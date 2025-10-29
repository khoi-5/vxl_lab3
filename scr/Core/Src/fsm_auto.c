/*
 * fsm_auto.c
 *
 *  Created on: Oct 15, 2025
 *      Author: DELL
 */


#include "fsm_auto.h"



void fsm_auto_run(void) {
    // --- Tick quét 7-segment: chạy nhanh, độc lập với logic 1 Hz ---
    if (timer_flag[1]) {             // Timer quét (2~5 ms)
        timer_flag[1] = 0;
        seg_scan_tick();             // Quét 2 cụm X/Y (EN trái/phải) theo disp_X/disp_Y
        setTimer(1, 250);        // Nạp lại quét
    }

    switch (status) {
    case INIT:
        init();          // GIỮ NGUYÊN
        init_time();     // GIỮ NGUYÊN

        // Bắt đầu: X đỏ, Y xanh (vì AUTO_RED dùng led_red_and_green = X đỏ, Y xanh)
        disp_X = (time_red   > 99) ? 99 : (time_red   > 0 ? time_red   : 0);
        disp_Y = (time_green > 99) ? 99 : (time_green > 0 ? time_green : 0);

        status = AUTO_RED;       // GIỮ NGUYÊN
        setTimer(0, 1000);       // 1 Hz logic
        setTimer(1, 250);    // Bắt đầu quét 7-seg
        break;

    case AUTO_RED:
        // X = ĐỎ, Y = XANH
        led_red_and_green();

        disp_X = (time_red   > 99) ? 99 : (time_red   > 0 ? time_red   : 0);
        disp_Y = (time_green > 99) ? 99 : (time_green > 0 ? time_green : 0);

        if (timer_flag[0]) {     // 1 giây
            timer_flag[0] = 0;
            if (time_red   > 0) time_red--;
            if (time_green > 0) time_green--;
            if (time_green == 0) {
                status = AUTO_YELLOW;        // X vàng, Y đỏ
            }
            setTimer(0, 1000);
        }
        break;

    case AUTO_GREEN:
        // X = XANH, Y = ĐỎ
        led_green_and_red();

        disp_X = (time_green > 99) ? 99 : (time_green > 0 ? time_green : 0);
        disp_Y = (time_red   > 99) ? 99 : (time_red   > 0 ? time_red   : 0);

        if (timer_flag[0]) {
            timer_flag[0] = 0;
            if (time_green > 0) time_green--;
            if (time_red   > 0) time_red--;
            if (time_green == 0) {
                status = AUTO_YELLOW_MAIN;   // X đỏ, Y vàng
            }
            setTimer(0, 1000);
        }
        break;

    case AUTO_YELLOW_MAIN:
        // X = VÀNG, Y = ĐỎ
        led_yellow_and_red();

        disp_X = (time_yellow > 99) ? 99 : (time_yellow > 0 ? time_yellow : 0);
        disp_Y = (time_red    > 99) ? 99 : (time_red    > 0 ? time_red    : 0);

        if (timer_flag[0]) {
            timer_flag[0] = 0;
            if (time_yellow > 0) time_yellow--;
            if (time_red    > 0) time_red--;
            if (time_red == 0) {
                init_time();                 // nạp lại red/green/yellow
                status = AUTO_RED;           // X đỏ, Y xanh
            }
            setTimer(0, 1000);
        }
        break;

    case AUTO_YELLOW:
        // X = ĐỎ, Y = VÀNG
        led_red_and_yellow();

        disp_X = (time_red    > 99) ? 99 : (time_red    > 0 ? time_red    : 0);
        disp_Y = (time_yellow > 99) ? 99 : (time_yellow > 0 ? time_yellow : 0);

        if (timer_flag[0]) {
            timer_flag[0] = 0;
            if (time_red    > 0) time_red--;
            if (time_yellow > 0) time_yellow--;
            if (time_red == 0) {
                init_time();
                status = AUTO_GREEN;         // X xanh, Y đỏ
            }
            setTimer(0, 1000);
        }
        break;

    default:
        break;
    }
}
