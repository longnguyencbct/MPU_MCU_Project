/*
 * input_reading.c
 *
 *  Created on: Oct 19, 2023
 *      Author: clong
 */

#include "main.h"

//we aim to work with more than one buttons
#define N0_OF_BUTTONS 				       4
//timer interrupt duration is 10ms, so to pass 1 second,
//we need to jump to the interrupt service routine 200 time
#define DURATION_FOR_AUTO_INCREASING	   1000
#define BUTTON_IS_PRESSED                  GPIO_PIN_RESET
#define BUTTON_IS_RELEASED                 GPIO_PIN_SET
//the buffer that the final result is stored after
//debouncing
static GPIO_PinState buttonBuffer[N0_OF_BUTTONS];
//we define two buffers for debouncing
static GPIO_PinState debounceButtonBuffer1[N0_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer2[N0_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer3[N0_OF_BUTTONS];
//static GPIO_PinState debounceButtonBuffer4[N0_OF_BUTTONS];
//static GPIO_PinState debounceButtonBuffer5[N0_OF_BUTTONS];
//we define a flag for a button pressed more than 1 second.
static uint8_t flagForButtonPress1s[N0_OF_BUTTONS];
//we define counter for automatically increasing the value
//after the button is pressed more than 1 second.
static uint16_t counterForButtonPress1s[N0_OF_BUTTONS];
void button_reading(int index){
	switch(index){

	case 0:
		//debounceButtonBuffer5[0] =debounceButtonBuffer4[0];
		//debounceButtonBuffer4[0] =debounceButtonBuffer3[0];
		//debounceButtonBuffer3[0] =debounceButtonBuffer2[0];
		debounceButtonBuffer2[0] =debounceButtonBuffer1[0];
		debounceButtonBuffer1[0] = HAL_GPIO_ReadPin(A0_PedButton_GPIO_Port, A0_PedButton_Pin);
		if(debounceButtonBuffer1[0] == debounceButtonBuffer2[0]
			//&&debounceButtonBuffer2[0] == debounceButtonBuffer3[0]
		)
			buttonBuffer[0] = debounceButtonBuffer1[0];
			if(buttonBuffer[0] == BUTTON_IS_PRESSED){
			//if a button is pressed, we start counting
				if(counterForButtonPress1s[0] < DURATION_FOR_AUTO_INCREASING){
					counterForButtonPress1s[0]++;
				} else {
				//the flag is turned on when 1 second has passed
				//since the button is pressed.
					flagForButtonPress1s[0] = 1;
					//todo
				}
			} else {
				counterForButtonPress1s[0] = 0;
				flagForButtonPress1s[0] = 0;
			}
		break;
	case 1:
		//debounceButtonBuffer5[1] =debounceButtonBuffer4[1];
		//debounceButtonBuffer4[1] =debounceButtonBuffer3[1];
		//debounceButtonBuffer3[1] =debounceButtonBuffer2[1];
		debounceButtonBuffer2[1] =debounceButtonBuffer1[1];
		debounceButtonBuffer1[1] = HAL_GPIO_ReadPin(A1_Button1_GPIO_Port, A1_Button1_Pin);
		if(debounceButtonBuffer1[1] == debounceButtonBuffer2[1]
		//&&debounceButtonBuffer2[1] == debounceButtonBuffer3[1]
		)
			buttonBuffer[1] = debounceButtonBuffer1[1];
			if(buttonBuffer[1] == BUTTON_IS_PRESSED){
			//if a button is pressed, we start counting
				if(counterForButtonPress1s[1] < DURATION_FOR_AUTO_INCREASING){
					counterForButtonPress1s[1]++;
				} else {
				//the flag is turned on when 1 second has passed
				//since the button is pressed.
					flagForButtonPress1s[1] = 1;
					//todo
				}
			} else {
				counterForButtonPress1s[1] = 0;
				flagForButtonPress1s[1] = 0;
			}
		break;
	case 2:
		//debounceButtonBuffer5[2] =debounceButtonBuffer4[2];
		//debounceButtonBuffer4[2] =debounceButtonBuffer3[2];
		//debounceButtonBuffer3[2] =debounceButtonBuffer2[2];
		debounceButtonBuffer2[2] =debounceButtonBuffer1[2];
		debounceButtonBuffer1[2] = HAL_GPIO_ReadPin(A2_Button2_GPIO_Port, A2_Button2_Pin);
		if(debounceButtonBuffer1[2] == debounceButtonBuffer2[2]
			//&&debounceButtonBuffer2[2] == debounceButtonBuffer3[2]
		)
			buttonBuffer[2] = debounceButtonBuffer1[2];
			if(buttonBuffer[2] == BUTTON_IS_PRESSED){
			//if a button is pressed, we start counting
				if(counterForButtonPress1s[2] < DURATION_FOR_AUTO_INCREASING){
					counterForButtonPress1s[2]++;
				} else {
				//the flag is turned on when 1 second has passed
				//since the button is pressed.
					flagForButtonPress1s[2] = 1;
					//todo
				}
			} else {
				counterForButtonPress1s[2] = 0;
				flagForButtonPress1s[2] = 0;
			}
		break;
	case 3:
		//debounceButtonBuffer5[3] =debounceButtonBuffer4[3];
		//debounceButtonBuffer4[3] =debounceButtonBuffer3[3];
		//debounceButtonBuffer3[3] =debounceButtonBuffer2[3];
		debounceButtonBuffer2[3] =debounceButtonBuffer1[3];
		debounceButtonBuffer1[3] = HAL_GPIO_ReadPin(A3_Button3_GPIO_Port, A3_Button3_Pin);
		if(debounceButtonBuffer1[3] == debounceButtonBuffer2[3]
			//&&debounceButtonBuffer2[3] == debounceButtonBuffer3[3]
		)
			buttonBuffer[3] = debounceButtonBuffer1[3];
			if(buttonBuffer[3] == BUTTON_IS_PRESSED){
			//if a button is pressed, we start counting
				if(counterForButtonPress1s[3] < DURATION_FOR_AUTO_INCREASING){
					counterForButtonPress1s[3]++;
				} else {
				//the flag is turned on when 1 second has passed
				//since the button is pressed.
					flagForButtonPress1s[3] = 1;
					//todo
				}
			} else {
				counterForButtonPress1s[3] = 0;
				flagForButtonPress1s[3] = 0;
			}
		break;
	default:
		break;
	}

}

unsigned char is_button_pressed(uint8_t index){
	if(index >= N0_OF_BUTTONS) return 0;
	return (buttonBuffer[index] == BUTTON_IS_PRESSED);
}
unsigned char is_button_pressed_1s(unsigned char index){
	if(index >= N0_OF_BUTTONS) return 0xff;
	return (flagForButtonPress1s[index] == 1);
}

