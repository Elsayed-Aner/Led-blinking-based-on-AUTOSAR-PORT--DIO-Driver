 /******************************************************************************
 *
 * Module: Gpt
 *
 * File Name: Gpt.h
 *
 * Description: Header file for GPT(Timer0) Module.
 *
 * Author: Mohamed Tarek
 ******************************************************************************/

#ifndef GPT_H
#define GPT_H

#include "Micro_Config.h"
#include "Std_Types.h"

/* 
 * Description: this function responsible for :
 *	1. Initialize Timer0 HW Driver to run in CTC Mode 
 *	2. Set the Compare Register Value to generate interrupt every Tick_Time ms 
 */	
void Timer0_start(uint8 Tick_Time);

/* Points to the required function in the OS upper layer Scheduler */
void Timer0_setCallBack(void (*Ptr2Func)(void));

#endif /* GPT_H */
