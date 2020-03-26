 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.h
 *
 * Description: Header file for Port Module.
 *
 * Author: Mohamed Tarek
 ******************************************************************************/

#ifndef PORT_H
#define PORT_H

/* Id for the company in the AUTOSAR
 * for example Mohamed Tarek's ID = 1000 :) */
#define PORT_VENDOR_ID    (1000U)

/* Port Module Id */
#define PORT_MODULE_ID    (124U)

/* Port Instance Id */
#define PORT_INSTANCE_ID  (0U)

/*
 * Module Version 1.0.0
 */
#define PORT_SW_MAJOR_VERSION           (1U)
#define PORT_SW_MINOR_VERSION           (0U)
#define PORT_SW_PATCH_VERSION           (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_AR_RELEASE_MAJOR_VERSION   (4U)
#define PORT_AR_RELEASE_MINOR_VERSION   (0U)
#define PORT_AR_RELEASE_PATCH_VERSION   (3U)

/*
 * Macros for Port Status
 */
#define PORT_INITIALIZED                (1U)
#define PORT_NOT_INITIALIZED            (0U)

/* Standard AUTOSAR types */
#include "Std_Types.h"

/* AUTOSAR checking between Std Types and Port Modules */
#if ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Std_Types.h does not match the expected version"
#endif

/* Port Pre-Compile Configuration Header file */
#include "Port_Cfg.h"

/* AUTOSAR Version checking between Port_Cfg.h and Port.h files */
#if ((PORT_CFG_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (PORT_CFG_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (PORT_CFG_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Port_Cfg.h does not match the expected version"
#endif

/* Software Version checking between Port_Cfg.h and Port.h files */
#if ((PORT_CFG_SW_MAJOR_VERSION != PORT_SW_MAJOR_VERSION)\
 ||  (PORT_CFG_SW_MINOR_VERSION != PORT_SW_MINOR_VERSION)\
 ||  (PORT_CFG_SW_PATCH_VERSION != PORT_SW_PATCH_VERSION))
  #error "The SW version of Port_Cfg.h does not match the expected version"
#endif

/******************************************************************************
 *                      API Service Id Macros                                 *
 ******************************************************************************/
/* Service ID for PORT Initialization */
#define PORT_INIT_SID                     (uint8)0x00

/* Service ID for PORT SetPinDirection */
#define PORT_SET_PIN_DIRECTION_SID        (uint8)0x01

/* Service ID for PORT Refresh Port Direction */
#define PORT_REFRESH_PORT_DIRECTION_SID   (uint8)0x02

/* Service ID for PORT Get Version Information */
#define PORT_GET_VERSION_INFO_SID         (uint8)0x03

/* Service ID for PORT Set Pin Mode */
 #define PORT_SET_PIN_MODE_SID             (uint8)0x04

/*******************************************************************************
 *                      DET Error Codes                                        *
 *******************************************************************************/
/* DET code to report Invalid Port Pin ID requested */
#define PORT_E_PARAM_PIN                  (uint8)0x0A

/* DET code to report Port Pin not configured as changeable */
#define PORT_E_DIRECTION_UNCHANGEABLE     (uint8)0x0B

/* DET code to report API Port_Init service called with wrong parameter. */
#define PORT_E_PARAM_CONFIG               (uint8)0x0C

/* DET code to report API Port_SetPinMode called with invalid mode */
#define PORT_E_PARAM_INVALID_MODE         (uint8)0x0D

/* DET code to report API Port_SetPinMode service called when mode is unchangeable. */
#define PORT_E_MODE_UNCHANGEABLE          (uint8)0x0E

/* DET code to report API service called without module initialization */
#define PORT_E_UNINIT                     (uint8)0x0F

/* DET code to report APIs called with a Null Pointer */
#define PORT_E_PARAM_POINTER              (uint8)0x10

/* Non AUTOSAR files */
#include "Common_Macros.h"
/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/
/*Data type for the symbolic name of a port pin*/
typedef uint8 Port_PinType;

/*Possible directions of a port pin*/
typedef enum {
	 PORT_PIN_IN, PORT_PIN_OUT
 } Port_PinDirectionType;

/*Different port pin modes*/
typedef uint8 Port_PinModeType;

/* Type definition for Port_ID used by the Port APIs */
typedef uint8 Port_IDType;

/* Pin config structure*/
typedef struct {
	// Number of the port.
	 Port_IDType Port_Num;
	// Number of the pin.
	 Port_PinType Pin_Num;
	// Direction of the pin.
	 Port_PinDirectionType Pin_Dir;
	// Pin level value.
	uint8 Pin_Level;
	// Pin pullup rsistor.
	uint8 PullUp;
	// pin direction changeable during runtime?.
	uint8 Pin_Dir_Chang;
	// Pin mode changeable during runtime?.
	uint8 Pin_Mode_Chang;
	// Mode of a given pin.
	Port_PinModeType Pin_Mode;
 } Pin_ConfigType;

 /*Type of the external data structure containing the initialization data for this module*/
typedef struct {
	 Pin_ConfigType Pin_config[PORT_CONFIGURED_PINS];

 } Port_ConfigType;
/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/
/* Function for Initializes the Port Driver module*/
void Port_Init( const Port_ConfigType* ConfigPtr );

/* Function for Sets the port pin direction*/
#if (PORT_SET_PIN_DIRECTION_API == STD_ON)
void Port_SetPinDirection( Port_PinType Pin, Port_PinDirectionType Direction );
#endif

/* Function for Refreshes port direction*/
void Port_RefreshPortDirection( void );

/* Function for Returns the version information of this module*/
#if (PORT_VERSION_INFO_API == STD_ON)
void Port_GetVersionInfo( Std_VersionInfoType* versioninfo );
#endif

/* Function for Sets the port pin mode*/
void Port_SetPinMode( Port_PinType Pin, Port_PinModeType Mode );

/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/
extern const Port_ConfigType Port_Configuration;


#endif /* PORT_H */
