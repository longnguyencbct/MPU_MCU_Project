/*
 * input_processing.c
 *
 *  Created on: Oct 19, 2023
 *      Author: clong
 */

//#include "input_reading.h"
#include "led_display.h"
#include "software_timer.h"

int sevenLEDdisplayBuffer[]={0,1,0,0};
enum MODE{MODE1, MODE2, MODE3, MODE4} ;
enum MODE currMode = MODE1;

enum AUTO1{A_RED1,A_YELLOW1,A_GREEN1};
enum AUTO1 currM1State1=A_RED1;

enum AUTO2{A_RED2,A_YELLOW2,A_GREEN2};
enum AUTO2 currM1State2=A_GREEN2;
int counterTraffic[]={5,3};

int lightSeconds[]={5,2,3};
int lightSeconds_temp[]={5,2,3};//red yellow green
void fsm_for_automatic_leds() {
    if (timer_flag[3] == 1) {
        setTimer(3, 100);
        counterTraffic[0]--;
        counterTraffic[1]--;

        if (counterTraffic[0] == 0) {
        	OffAllLED1();
            switch (currM1State1) {
                case A_RED1:
                    currM1State1 = A_GREEN1;
                    counterTraffic[0] = lightSeconds[2];
                    OnGreen1();
                    break;
                case A_GREEN1:
                    currM1State1 = A_YELLOW1;
                    counterTraffic[0] = lightSeconds[1];
                    OnYellow1();
                    break;
                case A_YELLOW1:
                    currM1State1 = A_RED1;
                    counterTraffic[0] = lightSeconds[0];
                    OnRed1();
                    break;
            }
        }

        if (counterTraffic[1] == 0) {
        	OffAllLED2();
            switch (currM1State2) {
                case A_RED2:
                    currM1State2 = A_GREEN2;
                    counterTraffic[1] = lightSeconds[2];
                    OnGreen2();
                    break;
                case A_GREEN2:
                    currM1State2 = A_YELLOW2;
                    counterTraffic[1] = lightSeconds[1];
                    OnYellow2();
                    break;
                case A_YELLOW2:
                    currM1State2 = A_RED2;
                    counterTraffic[1] = lightSeconds[0];
                    OnRed2();
                    break;
            }
        }
    }
    //updateM1LEDS();
    update_counterTraffic_to_Buffer();
}

void fsm_for_input_processing(void){
	//button_reading(0);
	//button_reading(1);
	//button_reading(2);
	if(timer_flag[1]==1){
		setTimer(1,30);
		switch(currMode){
		case MODE1:
			/*if(is_button_pressed(0)||is_button_pressed_1s(0)){
				currMode = MODE2;
				sevenLEDvalueToDisplay(0,2);
				sevenLEDvalueToDisplay(1,lightSeconds[0]);
				OffAllLED();
				//ToggleAllRed();
				resetBuffer_lightSeconds();
			}
			*/
			 fsm_for_automatic_leds();//////////////fsm for automatic leds
			break;
		case MODE2:
			if(is_button_pressed(0)||is_button_pressed_1s(0)){
				currMode = MODE3;
				sevenLEDvalueToDisplay(0,3);
				sevenLEDvalueToDisplay(1,lightSeconds[1]);
				OffAllLED();
				//ToggleAllYellow();
				resetBuffer_lightSeconds();
			}
			if(is_button_pressed(1)||is_button_pressed_1s(1)){
				lightSeconds_temp[0]+=1;
				if(lightSeconds_temp[0]>99){
					lightSeconds_temp[0]=1;
				}
				sevenLEDvalueToDisplay(1,lightSeconds_temp[0]);
			}
			if(is_button_pressed(2)||is_button_pressed_1s(2)){
				currMode = MODE1;
				saveBuffer_lightSeconds();

				M1_transition_function();
			}
			sevenLEDvalueToDisplay(0,2);
			sevenLEDvalueToDisplay(1,lightSeconds_temp[0]);
			break;
		case MODE3:
			if(is_button_pressed(0)||is_button_pressed_1s(0)){
				currMode = MODE4;
				sevenLEDvalueToDisplay(0,4);
				sevenLEDvalueToDisplay(1,lightSeconds[2]);
				OffAllLED();
				//ToggleAllGreen();
				resetBuffer_lightSeconds();
			}
			if(is_button_pressed(1)||is_button_pressed_1s(1)){
				lightSeconds_temp[1]+=1;
				if(lightSeconds_temp[1]>99){
					lightSeconds_temp[1]=1;
				}
				sevenLEDvalueToDisplay(1,lightSeconds_temp[1]);
			}
			if(is_button_pressed(2)||is_button_pressed_1s(2)){
				currMode = MODE1;
				saveBuffer_lightSeconds();

				M1_transition_function();
			}
			sevenLEDvalueToDisplay(0,3);
			sevenLEDvalueToDisplay(1,lightSeconds_temp[1]);
			break;
		case MODE4:
			if(is_button_pressed(0)||is_button_pressed_1s(0)){
				currMode = MODE1;
				resetBuffer_lightSeconds();

				M1_transition_function();
			}
			if(is_button_pressed(1)||is_button_pressed_1s(1)){
				lightSeconds_temp[2]+=1;
				if(lightSeconds_temp[2]>99){
					lightSeconds_temp[2]=1;
				}
				sevenLEDvalueToDisplay(1,lightSeconds_temp[2]);
			}
			if(is_button_pressed(2)||is_button_pressed_1s(2)){
				currMode = MODE1;
				saveBuffer_lightSeconds();

				M1_transition_function();
			}

			sevenLEDvalueToDisplay(0,4);
			sevenLEDvalueToDisplay(1,lightSeconds_temp[2]);
			break;

		}
	}

	TimerInterupt();

}


void sevenLEDvalueToDisplay(int index,int value){
	if(value>99){
		return;
	}
	switch(index){
	case 0:
		sevenLEDdisplayBuffer[0]=value/10;
		sevenLEDdisplayBuffer[1]=value%10;
		break;
	case 1:
		sevenLEDdisplayBuffer[2]=value/10;
		sevenLEDdisplayBuffer[3]=value%10;
		break;
	default:
		break;
	}
}
void resetBuffer_lightSeconds(){
	for(int i=0;i<3;i++){
		lightSeconds_temp[i]=lightSeconds[i];
	}
}
void saveBuffer_lightSeconds(){
	for(int i=0;i<3;i++){
		lightSeconds[i]=lightSeconds_temp[i];
	}
}

void update_counterTraffic_to_Buffer(){
	sevenLEDdisplayBuffer[0]=counterTraffic[0]/10;
	sevenLEDdisplayBuffer[1]=counterTraffic[0]%10;
	sevenLEDdisplayBuffer[2]=counterTraffic[1]/10;
	sevenLEDdisplayBuffer[3]=counterTraffic[1]%10;
}
void update_lightSeconds_to_counterTraffic(){
	counterTraffic[0]=lightSeconds[0];
	counterTraffic[1]=lightSeconds[2];
}
void init_for_automatic_leds(){
	OffAllLED();
	OnRed1();
	OnGreen2();
}

void M1_transition_function(){
	update_lightSeconds_to_counterTraffic();
	currM1State1=A_RED1;
	currM1State2=A_GREEN2;
	sevenLEDvalueToDisplay(0,counterTraffic[0]);
	sevenLEDvalueToDisplay(1,counterTraffic[2]);
	init_for_automatic_leds();
}
