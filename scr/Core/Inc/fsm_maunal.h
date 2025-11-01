/*
 * fsm_maunal.h
 *
 *  Created on: Nov 1, 2025
 *      Author: DELL
 */

#ifndef INC_FSM_MAUNAL_H_
#define INC_FSM_MAUNAL_H_

#include "global.h"
int  inc99(int v);


void manual_init_new_from_current(void);


void manual_update_display_from_new_state(void);


void manual_handle_button1_inc_new(void);


void manual_handle_button2_commit(void);


void manual_handle_button0_next_state(void);


void fsm_manual_run(void);

static inline void manual_update_display_from_new_pair(void){
}
void timer2();

#endif /* INC_FSM_MAUNAL_H_ */
