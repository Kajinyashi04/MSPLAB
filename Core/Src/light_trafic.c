/*
 * light_traffic.c
 *
 *  Created on: Mar 22, 2024
 *      Author: DELL
 */
#include "light_traffic.h"
#include "global.h"

int index_led = 0;

void red_green(){
	HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, SET);
	HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, RESET);
	HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, RESET);

	HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, RESET);
	HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, RESET);
	HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, SET);
}
void red_yellow(){
	HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, SET);
	HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, RESET);
	HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, RESET);

	HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, RESET);
	HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, SET);
	HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, RESET);
}
void green_red(){
	HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, RESET);
	HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, RESET);
	HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, SET);

	HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, SET);
	HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, RESET);
	HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, RESET);
}
void yellow_red(){
	HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, RESET);
	HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, SET);
	HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, RESET);

	HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, SET);
	HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, RESET);
	HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, RESET);
}
void green_green(){
	HAL_GPIO_TogglePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin);
	HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, RESET);
	HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, RESET);

	HAL_GPIO_TogglePin(LED_GREEN2_GPIO_Port,LED_GREEN2_Pin );
	HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, RESET);
	HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, RESET);

}
void red_red(){
	HAL_GPIO_TogglePin(LED_RED1_GPIO_Port, LED_RED1_Pin);
	HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, RESET);
	HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, RESET);

	HAL_GPIO_TogglePin(LED_RED2_GPIO_Port, LED_RED2_Pin);
	HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, RESET);
	HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, RESET);

}
void yellow_yellow(){
	HAL_GPIO_TogglePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin);
	HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, RESET);
	HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, RESET);


	HAL_GPIO_TogglePin(LED_YELLOW2_GPIO_Port,LED_YELLOW2_Pin );
	HAL_GPIO_WritePin(LED_RED2_GPIO_Port,LED_RED2_Pin , RESET);
	HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, RESET);
}
void update7SEG (){

	switch (index_led)
		  {
			  case 0:
				  HAL_GPIO_WritePin(MODE_GPIO_Port, MODE_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(DIGIT1_GPIO_Port, DIGIT1_Pin, GPIO_PIN_SET);
				  display7SEG(count1 / 10);
				  index_led = 1;
				  break;
			  case 1:
				  HAL_GPIO_WritePin(DIGIT1_GPIO_Port, DIGIT1_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(DIGIT2_GPIO_Port, DIGIT2_Pin, GPIO_PIN_SET);
				  display7SEG(count1 % 10);
				  index_led = 2;
				  break;
			  case 2:
				  HAL_GPIO_WritePin(DIGIT2_GPIO_Port, DIGIT2_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(DIGIT3_GPIO_Port, DIGIT3_Pin, GPIO_PIN_SET);
				  display7SEG(count2 / 10);
				  index_led = 3;
				  break;
			  case 3:
				  HAL_GPIO_WritePin(DIGIT3_GPIO_Port,DIGIT3_Pin , GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(DIGIT4_GPIO_Port,DIGIT4_Pin, GPIO_PIN_SET);
				  display7SEG(count2 % 10);
				  index_led = 4;
				  break;
			  case 4:
				  HAL_GPIO_WritePin(DIGIT4_GPIO_Port,DIGIT4_Pin , GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(MODE_GPIO_Port,MODE_Pin, GPIO_PIN_SET);
				  display7SEG(mode);
				  index_led = 0;
				  break;
		  }

}
void update7SEG_2 (int num){

	switch (index_led)
		  {
			  case 0:
				  HAL_GPIO_WritePin(MODE_GPIO_Port, MODE_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(DIGIT1_GPIO_Port, DIGIT1_Pin, GPIO_PIN_SET);
				  display7SEG(num / 10);
				  index_led = 1;
				  break;
			  case 1:
				  HAL_GPIO_WritePin(DIGIT1_GPIO_Port, DIGIT1_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(DIGIT2_GPIO_Port, DIGIT2_Pin, GPIO_PIN_SET);
				  display7SEG(num % 10);
				  index_led = 2;
				  break;
			  case 2:
				  HAL_GPIO_WritePin(DIGIT2_GPIO_Port, DIGIT2_Pin, GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(DIGIT3_GPIO_Port, DIGIT3_Pin, GPIO_PIN_SET);
				  display7SEG(num / 10);
				  index_led = 3;
				  break;
			  case 3:
				  HAL_GPIO_WritePin(DIGIT3_GPIO_Port,DIGIT3_Pin , GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(DIGIT4_GPIO_Port,DIGIT4_Pin, GPIO_PIN_SET);
				  display7SEG(num % 10);
				  index_led = 4;
				  break;
			  case 4:
				  HAL_GPIO_WritePin(DIGIT4_GPIO_Port,DIGIT4_Pin , GPIO_PIN_RESET);
				  HAL_GPIO_WritePin(MODE_GPIO_Port,MODE_Pin, GPIO_PIN_SET);
				  display7SEG(mode);
				  index_led = 0;
				  break;
		  }

}
void display7SEG(int k){
	switch (k){
	case 0:
		  HAL_GPIO_WritePin(GPIOA, LED_A_Pin|LED_B_Pin|LED_C_Pin|LED_D_Pin
		                          |LED_E_Pin|LED_F_Pin, GPIO_PIN_RESET);

		  HAL_GPIO_WritePin(GPIOA, LED_G_Pin, GPIO_PIN_SET);
		break;
	case 1:
		  HAL_GPIO_WritePin(GPIOA, LED_B_Pin|LED_C_Pin, GPIO_PIN_RESET);

		  HAL_GPIO_WritePin(GPIOA, LED_A_Pin|LED_D_Pin
		                          |LED_E_Pin|LED_F_Pin|LED_G_Pin, GPIO_PIN_SET);
		break;
	case 2:
		  HAL_GPIO_WritePin(GPIOA, LED_A_Pin|LED_B_Pin | LED_D_Pin
		                          |LED_E_Pin|LED_G_Pin, GPIO_PIN_RESET);

		  HAL_GPIO_WritePin(GPIOA,LED_C_Pin|LED_F_Pin, GPIO_PIN_SET);
		break;
	case 3:
		  HAL_GPIO_WritePin(GPIOA, LED_A_Pin|LED_B_Pin|LED_C_Pin|LED_D_Pin
		                          |LED_G_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOA, LED_E_Pin|LED_F_Pin, GPIO_PIN_SET);
		break;
	case 4:
		  HAL_GPIO_WritePin(GPIOA, LED_B_Pin|LED_C_Pin |LED_F_Pin|LED_G_Pin, GPIO_PIN_RESET);

		  HAL_GPIO_WritePin(GPIOA, LED_A_Pin|LED_D_Pin|LED_E_Pin, GPIO_PIN_SET);
		break;
	case 5:
		  HAL_GPIO_WritePin(GPIOA, LED_A_Pin|LED_C_Pin|LED_D_Pin
		                          |LED_F_Pin|LED_G_Pin, GPIO_PIN_RESET);

		  HAL_GPIO_WritePin(GPIOA,LED_B_Pin|LED_E_Pin, GPIO_PIN_SET);
		break;
	case 6:
		  HAL_GPIO_WritePin(GPIOA,LED_B_Pin, GPIO_PIN_SET);

		  HAL_GPIO_WritePin(GPIOA, LED_A_Pin|LED_C_Pin|LED_D_Pin
		                          |LED_E_Pin|LED_F_Pin|LED_G_Pin, GPIO_PIN_RESET);

		break;
	case 7:
		  HAL_GPIO_WritePin(GPIOA, LED_A_Pin|LED_B_Pin|LED_C_Pin , GPIO_PIN_RESET);

		  HAL_GPIO_WritePin(GPIOA, LED_D_Pin |LED_E_Pin|LED_F_Pin|LED_G_Pin, GPIO_PIN_SET);
		break;
	case 8:
		  HAL_GPIO_WritePin(GPIOA, LED_A_Pin|LED_B_Pin|LED_C_Pin|LED_D_Pin
		                          |LED_E_Pin|LED_F_Pin|LED_G_Pin, GPIO_PIN_RESET);
		break;
	case 9:
		  HAL_GPIO_WritePin(GPIOA, LED_A_Pin|LED_B_Pin|LED_C_Pin|LED_D_Pin
		                          |LED_F_Pin|LED_G_Pin, GPIO_PIN_RESET);

		  HAL_GPIO_WritePin(GPIOA, LED_E_Pin, GPIO_PIN_SET);
		break;
	default:
		break;
	}
}
