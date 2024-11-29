/*
 * fsm_manual.c
 *
 *  Created on: Nov 3, 2024
 *      Author: THUAN
 */

#include "fsm_manual.h"

void fsm_manual_run()
{
	switch(state)
	{
		case MAN_INIT:
			HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET);
			HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, SET);
			HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, SET);

			HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, SET);
			HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, SET);
			HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, SET);

			if (1)
			{
				state = MAN_RED;
			}
			break;
		case MAN_RED:
			time_buffer[0] = man_red;
			time_buffer[1] = MAN_RED - 10;


			HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
			HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, SET);
			HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, SET);

			HAL_GPIO_TogglePin(LED_RED1_GPIO_Port, LED_RED1_Pin);
			HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, SET);
			HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, SET);

			if (man_red > 99)
			{
				man_red = 0;
			}
			if (buttonIsPressed(0))
			{
				state = MAN_GREEN;
			}

			if (buttonIsPressed(1))
			{
				man_red++;
			}
			if (buttonIsPressed(2))
			{
				red = man_red;
				man_red = 0;
			}

			break;
		case MAN_GREEN:
			time_buffer[0] = man_green;
			time_buffer[1] = MAN_GREEN - 10;

			HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET);
			HAL_GPIO_TogglePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin);
			HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, SET);

			HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, SET);
			HAL_GPIO_TogglePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin);
			HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, SET);

			if (man_green > 99)
			{
				man_green = 0;
			}

			if (buttonIsPressed(0))
			{
				state = MAN_YELLOW;
			}

			if (buttonIsPressed(1))
			{
				man_green++;
			}
			if (buttonIsPressed(2))
			{
				green = man_green;
				man_green = 0;
			}

			break;
		case MAN_YELLOW:
			time_buffer[0] = man_yellow;
			time_buffer[1] = MAN_YELLOW - 10;

			HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET);
			HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, SET);
			HAL_GPIO_TogglePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin);

			HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, SET);
			HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, SET);
			HAL_GPIO_TogglePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin);

			if (man_yellow > 99)
			{
				man_yellow = 0;
			}
			if (buttonIsPressed(0))
			{
				state = INIT;
			}

			if (buttonIsPressed(1))
			{
				man_yellow++;
			}
			if (buttonIsPressed(2))
			{
				yellow = man_yellow;
				man_yellow = 0;
			}

			break;
		default:
			break;
	}
}
