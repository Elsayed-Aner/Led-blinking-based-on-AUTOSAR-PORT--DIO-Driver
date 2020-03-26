/******************************************************************************
 *
 * Module: Led
 *
 * File Name: Led.c
 *
 * Description: Source file for Led Module.
 *
 * Author: Mohamed Tarek
 ******************************************************************************/
#include "Port.h"
#include "Dio.h"
#include "Led.h"


void LED_setOn(void)
{
	Dio_WriteChannel(DioConf_LED_CHANNEL_ID_INDEX,LED_ON); // LED ON
}
/*********************************************************************************************/
void LED_setOff(void)
{
	Dio_WriteChannel(DioConf_LED_CHANNEL_ID_INDEX,LED_OFF); // LED OFF
}
/*********************************************************************************************/
void LED_refreshOutput(void)
{
	Dio_LevelType state = Dio_ReadChannel(DioConf_LED_CHANNEL_ID_INDEX);
	Dio_WriteChannel(DioConf_LED_CHANNEL_ID_INDEX,state); // re-write the same value
}
/*********************************************************************************************/
void LED_toggle(void)
{
	Dio_LevelType state = Dio_FlipChannel(DioConf_LED_CHANNEL_ID_INDEX);
}
/*********************************************************************************************/
