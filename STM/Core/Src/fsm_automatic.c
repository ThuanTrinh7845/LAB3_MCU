/*
 * fsm_automatic.c
 *
 *  Created on: Nov 2, 2024
 *      Author: THUAN
 */

#include "fsm_automatic.h"

void update_buffer()
{
	time_buffer[0]--;
	time_buffer[1]--;
}

void fsm_automatic_run()
{

	switch(state)
	{
		case INIT:
			HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET);
			HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, SET);
			HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, SET);

			HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, SET);
			HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, SET);
			HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, SET);


			if (red - (yellow + green) > 0)
			{
				green += red - (yellow + green);
			}
			if (red - (yellow + green) < 0)
			{
				red += (yellow + green) - red;
			}

			if (1)
			{
				state = AUTO_RED_GREEN;

				time_buffer[0] = red;
				time_buffer[1] = green;
			}
			break;
		case AUTO_RED_GREEN:
			red_green();

////			if (timerFlag[1] == 1)
////			{
////				setTimer(100, 1);
//				time_buffer[0]--;
//				time_buffer[1]--;
////			}

			if (time_buffer[1] <= 0)
			{
				state = AUTO_RED_YELLOW;
				//setTimer(100, 1);

				time_buffer[1] = yellow;
			}
			if (buttonIsPressed(0))
			{
				state = MAN_INIT;
			}
			break;
		case AUTO_RED_YELLOW:
			red_yellow();

////			if (timerFlag[1] == 1)
////			{
////				setTimer(100, 1);
//				time_buffer[0]--;
//				time_buffer[1]--;
////			}
			if (time_buffer[0] <= 0)
			{
				state = AUTO_GREEN_RED;
				//setTimer(100, 1);

				time_buffer[0] = green;
				time_buffer[1] = red;
			}
			if (buttonIsPressed(0))
			{
				state = MAN_INIT;
			}
			break;
		case AUTO_GREEN_RED:
			green_red();

////			if (timerFlag[1] == 1)
////			{
////				setTimer(100, 1);
//				time_buffer[0]--;
//				time_buffer[1]--;
////			}


			if (time_buffer[0] <= 0)
			{
				state = AUTO_YELLOW_RED;
				//setTimer(100, 1);

				time_buffer[0] = yellow;
			}
			if (buttonIsPressed(0))
			{
				state = MAN_INIT;
			}
			break;
		case AUTO_YELLOW_RED:
			yellow_red();

////			if (timerFlag[1] == 1)
////			{
////				setTimer(100, 1);
//				time_buffer[0]--;
//				time_buffer[1]--;
////			}


			if (time_buffer[0] <= 0)
			{
				state = AUTO_RED_GREEN;
				//setTimer(100, 1);

				time_buffer[0] = red;
				time_buffer[1] = green;

			}
			if (buttonIsPressed(0))
			{
				state = MAN_INIT;
			}
			break;
		default:
			break;
	}

}
