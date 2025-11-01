/*
 * global.h
 *
 *  Created on: Oct 15, 2025
 *      Author: DELL
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

//cac file.h co ban
#include "main.h"
#include "software_timer.h"
#include "button.h"

// cac file.h cua traffic light va led 7 doan
#include "light_traffic.h"
#include "led7_segment.h"

//cac file.h fsm
#include "fsm_auto.h"

//SCAN SPEED
#define SCAN 100

//che do mac dinh
#define INIT 1
#define RED_GREEN 2
#define RED_YELLOW 3
#define GREEN_RED 4
#define YELLOW_RED 5

#define MAN_RED 1200
#define MAN_GREEN 1300
#define MAN_YELLOW 1400

#define MAN_RED_GREEN 12
#define MAN_RED_YELLOW 13
#define MAN_GREEN_RED 14
#define MAN_YELLOW_RED 15

#define SET_INIT 22
#define SET_RED 23
#define SET_GREEN 24
#define SET_YELLOW_MAIN 25
#define SET_YELLOW 26

extern int status;
extern int count;
extern int counter1;
extern int counter2;


// thoi gian cua truc x
extern int time_red_x;
extern int time_green_x;
extern int time_yellow_x;
extern int time_red_new_x;
extern int time_green_new_x;
extern int time_yellow_new_x;

// thoi gian cua truc x
extern int time_red_y;
extern int time_green_y;
extern int time_yellow_y;
extern int time_red_new_y;
extern int time_green_new_y;
extern int time_yellow_new_y;

//bien time hien tai
extern int current_time_x;
extern int current_time_y;

extern int count_x;
extern int count_y;

int inc99(int v);
#endif /* INC_GLOBAL_H_ */
