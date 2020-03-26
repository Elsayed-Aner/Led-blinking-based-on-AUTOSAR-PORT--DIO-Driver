/******************************************************************************
 *
 * Module: Button
 *
 * File Name: Button.c
 *
 * Description: Source file for Led Module.
 *
 * Author: Mohamed Tarek
 ******************************************************************************/
#include "Dio.h"
#include "Port.h"
#include "Button.h"

/* Count the number of Pressed times increment if the switch pressed for 20 ms */
static uint8 g_Pressed_Count  = 0;

/* Count the number of Released times increment if the switch released for 20 ms */
static uint8 g_Released_Count = 0;

static uint8 g_button_state     = BUTTON_RELEASED;

/*******************************************************************************************************************/
uint8 BUTTON_getState(void)
{
	return g_button_state;
}
/*******************************************************************************************************************/
void BUTTON_refreshState(void)
{
	uint8 state = Dio_ReadChannel(DioConf_BUTTON_CHANNEL_ID_INDEX);
	if(state == BUTTON_PRESSED)
	{
		g_Pressed_Count++;
		g_Released_Count = 0;
	}
	else
	{
		g_Released_Count++;
		g_Pressed_Count = 0;
	}

	if(g_Pressed_Count == 3)
	{
		g_button_state = BUTTON_PRESSED;
		g_Pressed_Count       = 0;
		g_Released_Count      = 0;
	}
	else if(g_Released_Count == 3)
	{
		g_button_state = BUTTON_RELEASED;
		g_Released_Count      = 0;
		g_Pressed_Count       = 0;
	}
}
/*******************************************************************************************************************/
