/*
 * input_reading.h
 *
 *  Created on: Oct 19, 2023
 *      Author: clong
 */

#ifndef INC_INPUT_READING_H_
#define INC_INPUT_READING_H_

extern int button_flag[];
void button_reading(int index);
int is_button_pressed(int index);
unsigned char is_button_pressed_1s(unsigned char index);

#endif /* INC_INPUT_READING_H_ */
