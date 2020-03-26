 /******************************************************************************
 *
 * Module: Dio
 *
 * File Name: Dio_Regs.h
 *
 * Description: Header file for Dio Module Registers.
 *
 * Author: Mohamed Tarek
 ******************************************************************************/

#ifndef DIO_REGS_H
#define DIO_REGS_H

#include "Std_Types.h"

/* Definition for PORTA Registers */
#define PORTA_REG	(*(volatile uint8 *)0x003B)
#define DDRA_REG	(*(volatile uint8 *)0x003A)
#define PINA_REG 	(*(volatile uint8 *)0x0039)

/* Definition for PORTB Registers */
#define PORTB_REG	(*(volatile uint8 *)0x0038)
#define DDRB_REG	(*(volatile uint8 *)0x0037)
#define PINB_REG 	(*(volatile uint8 *)0x0036)

/* Definition for PORTC Registers */
#define PORTC_REG	(*(volatile uint8 *)0x0035)
#define DDRC_REG	(*(volatile uint8 *)0x0034)
#define PINC_REG 	(*(volatile uint8 *)0x0033)

/* Definition for PORTD Registers */
#define PORTD_REG	(*(volatile uint8 *)0x0032)
#define DDRD_REG	(*(volatile uint8 *)0x0031)
#define PIND_REG 	(*(volatile uint8 *)0x0030)

#endif /* DIO_REGS_H */
