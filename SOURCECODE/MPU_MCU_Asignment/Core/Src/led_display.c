/*
 * led_display.c
 *
 *  Created on: Oct 19, 2023
 *      Author: clong
 */


#include "main.h"
#include "input_processing.h"
#include "software_timer.h"

/*////////////////////////////////////////////////
  void OnP_A(int num){
	  num+=1;
	  switch(num){
	  case 1:
		  HAL_GPIO_WritePin (P_A1_GPIO_Port, P_A1_Pin, GPIO_PIN_RESET);
		  break;
	  case 2:
		  HAL_GPIO_WritePin (P_A2_GPIO_Port, P_A2_Pin, GPIO_PIN_RESET);
		  break;
	  default:
		  break;
	  }
  }
  void OnP_B(int num){
	  num+=1;
	  switch(num){
	  case 1:
		  HAL_GPIO_WritePin (P_B1_GPIO_Port, P_B1_Pin, GPIO_PIN_RESET);
		  break;
	  case 2:
		  HAL_GPIO_WritePin (P_B2_GPIO_Port, P_B2_Pin, GPIO_PIN_RESET);
		  break;
	  default:
		  break;
	  }
  }
  void OnP_C(int num){
	  num+=1;
	  switch(num){
	  case 1:
		  HAL_GPIO_WritePin (P_C1_GPIO_Port, P_C1_Pin, GPIO_PIN_RESET);
		  break;
	  case 2:
		  HAL_GPIO_WritePin (P_C2_GPIO_Port, P_C2_Pin, GPIO_PIN_RESET);
		  break;
	  default:
		  break;
	  }
  }
  void OnP_D(int num){
	  num+=1;
	  switch(num){
	  case 1:
		  HAL_GPIO_WritePin (P_D1_GPIO_Port, P_D1_Pin, GPIO_PIN_RESET);
		  break;
	  case 2:
		  HAL_GPIO_WritePin (P_D2_GPIO_Port, P_D2_Pin, GPIO_PIN_RESET);
		  break;
	  default:
		  break;
	  }
  }
  void OnP_E(int num){
	  num+=1;
	  switch(num){
	  case 1:
		  HAL_GPIO_WritePin (P_E1_GPIO_Port, P_E1_Pin, GPIO_PIN_RESET);
		  break;
	  case 2:
		  HAL_GPIO_WritePin (P_E2_GPIO_Port, P_E2_Pin, GPIO_PIN_RESET);
		  break;
	  default:
		  break;
	  }
  }
  void OnP_F(int num){
	  num+=1;
	  switch(num){
	  case 1:
		  HAL_GPIO_WritePin (P_F1_GPIO_Port, P_F1_Pin, GPIO_PIN_RESET);
		  break;
	  case 2:
		  HAL_GPIO_WritePin (P_F2_GPIO_Port, P_F2_Pin, GPIO_PIN_RESET);
		  break;
	  default:
		  break;
	  }
  }
  void OnP_G(int num){
	  num+=1;
	  switch(num){
	  case 1:
		  HAL_GPIO_WritePin (P_G1_GPIO_Port, P_G1_Pin, GPIO_PIN_RESET);
		  break;
	  case 2:
		  HAL_GPIO_WritePin (P_G2_GPIO_Port, P_G2_Pin, GPIO_PIN_RESET);
		  break;
	  default:
		  break;
	  }
  }
/////////////////////////////////////////////////
  void OffP_A(int num){
	  num+=1;
	  switch(num){
	  case 1:
		  HAL_GPIO_WritePin (P_A1_GPIO_Port, P_A1_Pin, GPIO_PIN_SET);
		  break;
	  case 2:
		  HAL_GPIO_WritePin (P_A2_GPIO_Port, P_A2_Pin, GPIO_PIN_SET);
		  break;
	  default:
		  break;
	  }
  }
  void OffP_B(int num){
	  num+=1;
	  switch(num){
	  case 1:
		  HAL_GPIO_WritePin (P_B1_GPIO_Port, P_B1_Pin, GPIO_PIN_SET);
		  break;
	  case 2:
		  HAL_GPIO_WritePin (P_B2_GPIO_Port, P_B2_Pin, GPIO_PIN_SET);
		  break;
	  default:
		  break;
	  }
  }
  void OffP_C(int num){
	  num+=1;
	  switch(num){
	  case 1:
		  HAL_GPIO_WritePin (P_C1_GPIO_Port, P_C1_Pin, GPIO_PIN_SET);
		  break;
	  case 2:
		  HAL_GPIO_WritePin (P_C2_GPIO_Port, P_C2_Pin, GPIO_PIN_SET);
		  break;
	  default:
		  break;
	  }
  }
  void OffP_D(int num){
	  num+=1;
	  switch(num){
	  case 1:
		  HAL_GPIO_WritePin (P_D1_GPIO_Port, P_D1_Pin, GPIO_PIN_SET);
		  break;
	  case 2:
		  HAL_GPIO_WritePin (P_D2_GPIO_Port, P_D2_Pin, GPIO_PIN_SET);
		  break;
	  default:
		  break;
	  }
  }
  void OffP_E(int num){
	  num+=1;
	  switch(num){
	  case 1:
		  HAL_GPIO_WritePin (P_E1_GPIO_Port, P_E1_Pin, GPIO_PIN_SET);
		  break;
	  case 2:
		  HAL_GPIO_WritePin (P_E2_GPIO_Port, P_E2_Pin, GPIO_PIN_SET);
		  break;
	  default:
		  break;
	  }
  }
  void OffP_F(int num){
	  num+=1;
	  switch(num){
	  case 1:
		  HAL_GPIO_WritePin (P_F1_GPIO_Port, P_F1_Pin, GPIO_PIN_SET);
		  break;
	  case 2:
		  HAL_GPIO_WritePin (P_F2_GPIO_Port, P_F2_Pin, GPIO_PIN_SET);
		  break;
	  default:
		  break;
	  }
  }
  void OffP_G(int num){
	  num+=1;
	  switch(num){
	  case 1:
		  HAL_GPIO_WritePin (P_G1_GPIO_Port, P_G1_Pin, GPIO_PIN_SET);
		  break;
	  case 2:
		  HAL_GPIO_WritePin (P_G2_GPIO_Port, P_G2_Pin, GPIO_PIN_SET);
		  break;
	  default:
		  break;
	  }
  }
/////////////////////////////////////////////////
void display7SEG(int lednum,int num){
	  if(lednum!=0&&lednum!=1){return;}
	  switch (num) {
	      case 0:
	    	  OnP_A(lednum);
	    	  OnP_B(lednum);
	    	  OnP_C(lednum);
	    	  OnP_D(lednum);
	    	  OnP_E(lednum);
	    	  OnP_F(lednum);
	    	  OffP_G(lednum);
	          break;
	      case 1:
	    	  OffP_A(lednum);
	    	  OnP_B(lednum);
	    	  OnP_C(lednum);
	    	  OffP_D(lednum);
	    	  OffP_E(lednum);
	    	  OffP_F(lednum);
	    	  OffP_G(lednum);
	          break;
	      case 2:
	    	  OnP_A(lednum);
	    	  OnP_B(lednum);
	    	  OffP_C(lednum);
	    	  OnP_D(lednum);
	    	  OnP_E(lednum);
	    	  OffP_F(lednum);
	    	  OnP_G(lednum);
	          break;
	      case 3:
	    	  OnP_A(lednum);
	    	  OnP_B(lednum);
	    	  OnP_C(lednum);
	    	  OnP_D(lednum);
	    	  OffP_E(lednum);
	    	  OffP_F(lednum);
	    	  OnP_G(lednum);
	          break;
	      case 4:
	    	  OffP_A(lednum);
	    	  OnP_B(lednum);
	    	  OnP_C(lednum);
	    	  OffP_D(lednum);
	    	  OffP_E(lednum);
	    	  OnP_F(lednum);
	    	  OnP_G(lednum);
	          break;
	      case 5:
	    	  OnP_A(lednum);
	    	  OffP_B(lednum);
	    	  OnP_C(lednum);
	    	  OnP_D(lednum);
	    	  OffP_E(lednum);
	    	  OnP_F(lednum);
	    	  OnP_G(lednum);
	          break;
	      case 6:
	    	  OnP_A(lednum);
	    	  OffP_B(lednum);
	    	  OnP_C(lednum);
	    	  OnP_D(lednum);
	    	  OnP_E(lednum);
	    	  OnP_F(lednum);
	    	  OnP_G(lednum);
	          break;
	      case 7:
	    	  OnP_A(lednum);
	    	  OnP_B(lednum);
	    	  OnP_C(lednum);
	    	  OffP_D(lednum);
	    	  OffP_E(lednum);
	    	  OffP_F(lednum);
	    	  OffP_G(lednum);
	          break;
	      case 8:
	    	  OnP_A(lednum);
	    	  OnP_B(lednum);
	    	  OnP_C(lednum);
	    	  OnP_D(lednum);
	    	  OnP_E(lednum);
	    	  OnP_F(lednum);
	    	  OnP_G(lednum);
	          break;
	      case 9:
	    	  OnP_A(lednum);
	    	  OnP_B(lednum);
	    	  OnP_C(lednum);
	    	  OnP_D(lednum);
	    	  OffP_E(lednum);
	    	  OnP_F(lednum);
	    	  OnP_G(lednum);
	          break;
	      default:
	    	  OnP_A(lednum);
	    	  OnP_B(lednum);
	    	  OnP_C(lednum);
	    	  OnP_D(lednum);
	    	  OnP_E(lednum);
	    	  OnP_F(lednum);
	    	  OffP_G(lednum);
	    	  break;
	  }

  }
/////////////////////////////////////////////////
void OnEN_7SEG0(int i){
	  switch(i){
	  	  case 0:
	  		  HAL_GPIO_WritePin (EN0_7SEG0_GPIO_Port, EN0_7SEG0_Pin, GPIO_PIN_RESET);
	  		  break;
	  	  case 1:
	  		  HAL_GPIO_WritePin (EN1_7SEG0_GPIO_Port, EN1_7SEG0_Pin, GPIO_PIN_RESET);
	  		  break;
	  	  default:
	  		  break;
	  }
  }
void OffEN_7SEG0(int i){
	  switch(i){
	  	  case 0:
	  		  HAL_GPIO_WritePin (EN0_7SEG0_GPIO_Port, EN0_7SEG0_Pin, GPIO_PIN_SET);
	  		  break;
	  	  case 1:
	  		  HAL_GPIO_WritePin (EN1_7SEG0_GPIO_Port, EN1_7SEG0_Pin, GPIO_PIN_SET);
	  		  break;
	  	  default:
	  		  break;
	  }
  }

void OnEN_7SEG1(int i){
	  switch(i){
	  	  case 0:
	  		  HAL_GPIO_WritePin (EN0_7SEG1_GPIO_Port, EN0_7SEG1_Pin, GPIO_PIN_RESET);
	  		  break;
	  	  case 1:
	  		  HAL_GPIO_WritePin (EN1_7SEG1_GPIO_Port, EN1_7SEG1_Pin, GPIO_PIN_RESET);
	  		  break;
	  	  default:
	  		  break;
	  }
  }
void OffEN_7SEG1(int i){
	  switch(i){
	  	  case 0:
	  		  HAL_GPIO_WritePin (EN0_7SEG1_GPIO_Port, EN0_7SEG1_Pin, GPIO_PIN_SET);
	  		  break;
	  	  case 1:
	  		  HAL_GPIO_WritePin (EN1_7SEG1_GPIO_Port, EN1_7SEG1_Pin, GPIO_PIN_SET);
	  		  break;
	  	  default:
	  		  break;
	  }
  }
/////////////////////////////////////////////////
void TurnOffAll7SEG0(){
	  OffEN_7SEG0(0);
	  OffEN_7SEG0(1);
  }
void TurnOffAll7SEG1(){
	  OffEN_7SEG1(0);
	  OffEN_7SEG1(1);
  }
/////////////////////////////////////////////////
void update7SEG0(int index){
	    switch (index){
	        case 0:
	            //Display the first 7SEG with sevenLEDdisplayBuffer[1]
	        	TurnOffAll7SEG0();
	        	display7SEG(0,sevenLEDdisplayBuffer[1]);
	            break;
	        case 1:
	            //Display the second 7SEG with sevenLEDdisplayBuffer[0]
	        	TurnOffAll7SEG0();
	        	display7SEG(0,sevenLEDdisplayBuffer[0]);
	            break;
	        default:
	            break;
	    }
    	OnEN_7SEG0(index);
	}
void update7SEG1(int index){
	    switch (index){
	        case 0:
	            //Display the first 7SEG with sevenLEDdisplayBuffer[1]
	        	TurnOffAll7SEG1();
	        	display7SEG(1,sevenLEDdisplayBuffer[3]);
	            break;
	        case 1:
	            //Display the second 7SEG with sevenLEDdisplayBuffer[0]
	        	TurnOffAll7SEG1();
	        	display7SEG(1,sevenLEDdisplayBuffer[2]);
	            break;
	        default:
	            break;
	    }
    	OnEN_7SEG1(index);
	}

/*////////////////////////////////////////////////////////////////////////////////////

void OnRed1(){
	  HAL_GPIO_WritePin (D2_LED1_GPIO_Port, D2_LED1_Pin, 1);
	  HAL_GPIO_WritePin (D3_LED1_GPIO_Port, D3_LED1_Pin, 0);
}
void OnYellow1(){
	  HAL_GPIO_WritePin (D2_LED1_GPIO_Port, D2_LED1_Pin, 1);
	  HAL_GPIO_WritePin (D3_LED1_GPIO_Port, D3_LED1_Pin, 1);
}
void OnGreen1(){
	  HAL_GPIO_WritePin (D2_LED1_GPIO_Port, D2_LED1_Pin, 0);
	  HAL_GPIO_WritePin (D3_LED1_GPIO_Port, D3_LED1_Pin, 1);
}

void OffAllLED1(){
	  HAL_GPIO_WritePin (D2_LED1_GPIO_Port, D2_LED1_Pin, 0);
	  HAL_GPIO_WritePin (D3_LED1_GPIO_Port, D3_LED1_Pin, 0);
}
/////////////////////////////////////////////////
void OnRed2(){
	  HAL_GPIO_WritePin (D4_LED2_GPIO_Port, D4_LED2_Pin, 1);
	  HAL_GPIO_WritePin (D5_LED2_GPIO_Port, D5_LED2_Pin, 0);
}
void OnYellow2(){
	  HAL_GPIO_WritePin (D4_LED2_GPIO_Port, D4_LED2_Pin, 1);
	  HAL_GPIO_WritePin (D5_LED2_GPIO_Port, D5_LED2_Pin, 1);
}
void OnGreen2(){
	  HAL_GPIO_WritePin (D4_LED2_GPIO_Port, D4_LED2_Pin, 0);
	  HAL_GPIO_WritePin (D5_LED2_GPIO_Port, D5_LED2_Pin, 1);
}

void OffAllLED2(){
	HAL_GPIO_WritePin (D4_LED2_GPIO_Port, D4_LED2_Pin, 0);
	HAL_GPIO_WritePin (D5_LED2_GPIO_Port, D5_LED2_Pin, 0);
}
/////////////////////////////////////////////////

void OffAllLED(){
	OffAllLED1();
	OffAllLED2();
}
/*/////////*////////////////////
void OnPed_Red(){
		HAL_GPIO_WritePin (D6_PedLED_GPIO_Port, D6_PedLED_Pin, 1);
		HAL_GPIO_WritePin (D7_PedLED_GPIO_Port, D7_PedLED_Pin, 0);
}
void OnPed_Green(){
		HAL_GPIO_WritePin (D6_PedLED_GPIO_Port, D6_PedLED_Pin, 0);
		HAL_GPIO_WritePin (D7_PedLED_GPIO_Port, D7_PedLED_Pin, 1);
}
void OffPed(){
		HAL_GPIO_WritePin (D6_PedLED_GPIO_Port, D6_PedLED_Pin, 0);
		HAL_GPIO_WritePin (D7_PedLED_GPIO_Port, D7_PedLED_Pin, 0);
}
void OnPed_Mixed(){
		HAL_GPIO_WritePin (D6_PedLED_GPIO_Port, D6_PedLED_Pin, 1);
		HAL_GPIO_WritePin (D7_PedLED_GPIO_Port, D7_PedLED_Pin, 1);
}

/*/////////*////////////////////
void OnBuzzer(){
	  HAL_GPIO_WritePin (D12_PedBuzzer_GPIO_Port, D12_PedBuzzer_Pin, 1);
	  HAL_GPIO_WritePin (D13_PedBuzzer_GPIO_Port, D13_PedBuzzer_Pin, 1);
}
void OffBuzzer(){
	  HAL_GPIO_WritePin (D12_PedBuzzer_GPIO_Port, D12_PedBuzzer_Pin, 0);
	  HAL_GPIO_WritePin (D13_PedBuzzer_GPIO_Port, D13_PedBuzzer_Pin, 0);
}
/*//////////*//////////////////////////////////////
/*
void ToggleAllRed(){
	HAL_GPIO_TogglePin(LED_RED1_GPIO_Port, LED_RED1_Pin);
	HAL_GPIO_TogglePin(LED_RED2_GPIO_Port, LED_RED2_Pin);
}

void ToggleAllYellow(){
	HAL_GPIO_TogglePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin);
	HAL_GPIO_TogglePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin);
}

void ToggleAllGreen(){
	HAL_GPIO_TogglePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin);
	HAL_GPIO_TogglePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin);
}
/*////////////////////////////////////////////////

void updateM1LEDS(){
	OffAllLED();
	switch(currM1State1){
		case A_RED1:
			OnRed1();
			break;
		case A_YELLOW1:
			OnYellow1();
			break;
		case A_GREEN1:
			OnGreen1();
			break;
	}
	switch(currM1State2){
		case A_RED2:
			OnRed2();
			break;
		case A_YELLOW2:
			OnYellow2();
			break;
		case A_GREEN2:
			OnGreen2();
			break;
	}
}
/////////////////////////////////////////////////
int index_led=0;
const int sevenSegTimer=5;
const int LEDblinkingTimer=25;
void TimerInterupt(){
	if(timer_flag[0]==1){
		setTimer(0,sevenSegTimer);
		index_led++;
		if(index_led>1){
			index_led=0;
		}
//		update7SEG0(index_led);
//		update7SEG1(index_led);
	}
	if(timer_flag[2]==1){
		setTimer(2,LEDblinkingTimer);
		switch(currMode){
			case MODE2:
//				ToggleAllRed();
				break;
			case MODE3:
//				ToggleAllYellow();
				break;
			case MODE4:
//				ToggleAllGreen();
				break;
			default:
				break;
		}
	}
}

