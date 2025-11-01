/*
 * fsm_control_run.c
 *
 *  Created on: Nov 1, 2025
 *      Author: DELL
 */

#include"fsm_control.h"
void fsm_control_run(void){
    switch (status) {
    case SET_RED_GREEN:
        if (isButton1Pressed(2) == 1) {
        	status = SET_RED_YELLOW;
        }
        if (isButton1Pressed(0) == 1) {
        	status = RED_GREEN;
        	display_mode_auto();
        }
        	set_red_x_green_y();

    	break;
    case SET_RED_YELLOW:
        if (isButton1Pressed(2) == 1) {
        	status = SET_GREEN_RED;
        }
        if (isButton1Pressed(0) == 1) {
        	status = RED_GREEN;
        	display_mode_auto();
        }
        set_red_x_yellow_y();

    	break;
    case SET_GREEN_RED:
        if (isButton1Pressed(2) == 1) {
        	status = SET_YELLOW_RED;
        }
        if (isButton1Pressed(0) == 1) {
        	status = RED_GREEN;
        	display_mode_auto();
        }
        	set_red_x_green_y();


    	break;
    case SET_YELLOW_RED:
        if (isButton1Pressed(2) == 1) {
        	status = SET_RED_GREEN;
        }
        if (isButton1Pressed(0) == 1) {
        	status = RED_GREEN;
        	display_mode_auto();
        }
        	set_yellow_x_red_y();


    	break;




    default:
        break;
    }
}
