/*
 * global.h
 *
 *  Created on: Oct 15, 2025
 *      Author: DELL
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "software_timer.h"
#include "button.h"
#include "main.h"

#define INIT 1
#define AUTO_RED 2
#define AUTO_GREEN 3
#define AUTO_YELLOW_MAIN 4
#define AUTO_YELLOW 5

#define MAN_RED 12
#define MAN_GREEN 13
#define MAN_YELLOW 14

#define SET_INIT 22
#define SET_RED 23
#define SET_GREEN 24
#define SET_YELLOW_MAIN 25
#define SET_YELLOW 26

extern int status;
extern int count;
extern int counter1;
extern int counter2;
extern int time_red;
extern int time_green;
extern int time_yellow;
extern int time_red_new;
extern int time_green_new;
extern int time_yellow_new;

#endif /* INC_GLOBAL_H_ */
