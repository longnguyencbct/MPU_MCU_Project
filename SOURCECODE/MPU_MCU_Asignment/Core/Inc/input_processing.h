/*
 * input_processing.h
 *
 *  Created on: Oct 19, 2023
 *      Author: clong
 */

#ifndef INC_INPUT_PROCESSING_H_
#define INC_INPUT_PROCESSING_H_

enum MODE{MODE1, MODE2, MODE3, MODE4} ;
extern enum MODE currMode;

enum AUTO1{A_RED1,A_GREEN1,A_YELLOW1};
extern enum AUTO1 currM1State1;

enum AUTO2{A_RED2,A_GREEN2,A_YELLOW2};
extern enum AUTO2 currM1State2;

extern int counterTraffic[];

extern int lightSeconds[];
extern int lightSeconds_temp[];

extern int sevenLEDdisplayBuffer[];
void init_for_automatic_leds();
void fsm_for_input_processing(void);
void sevenLEDvalueToDisplay(int index,int value);
#endif /* INC_INPUT_PROCESSING_H_ */
