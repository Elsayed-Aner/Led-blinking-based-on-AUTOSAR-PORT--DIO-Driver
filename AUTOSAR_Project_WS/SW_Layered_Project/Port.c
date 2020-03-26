 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.c
 *
 * Description: Source file for Port Module.
 *
 * Author: Mohamed Tarek
 ******************************************************************************/

#include "Port.h"
#include "Dio_Regs.h"

#if (PORT_DEV_ERROR_DETECT == STD_ON)

#include "Det.h"
/* AUTOSAR Version checking between Det and Port Modules */
#if ((DET_AR_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 || (DET_AR_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 || (DET_AR_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Det.h does not match the expected version"
#endif

#endif

STATIC Pin_ConfigType * Port_Pin_Config = NULL_PTR;
STATIC uint8 Port_Status = PORT_NOT_INITIALIZED;

/************************************************************************************
* Service Name: Port_Init
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): ConfigPtr - Pointer to configuration set
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Initialize the Port module.
************************************************************************************/
void Port_Init( const Port_ConfigType* ConfigPtr )
{
	Port_IDType *Port_Ptr = NULL_PTR;
	Port_PinType *Pin_PTR = NULL_PTR;
	uint8 *DDR_Ptr = NULL_PTR;
	boolean error = FALSE;
	#if (PORT_DEV_ERROR_DETECT == STD_ON)
	/* check if the input configuration pointer is not a NULL_PTR */
	if (NULL_PTR == ConfigPtr)
	{
		/* Report to DET  */
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_INIT_SID,
		     PORT_E_PARAM_CONFIG);
			 error = TRUE;
	}
	else
    #endif

if (FALSE == error)
{
	{
	Port_Pin_Config = ConfigPtr->Pin_config;
	volatile int i;
	for (i = MIN_PIN_NUM; i <= MAX_PIN_NUM ; i++)
	{
		switch(Port_Pin_Config[i].Port_Num)
		{
			case 0:	Port_Ptr = &PORTA_REG;
					Pin_PTR  = &PINA_REG;
					DDR_Ptr  = &DDRA_REG;

		        break;
			case 1:	Port_Ptr = &PORTB_REG;
					Pin_PTR  = &PINB_REG;
					DDR_Ptr  = &DDRB_REG;
		        break;
			case 2:	Port_Ptr = &PORTC_REG;
					Pin_PTR  = &PINC_REG;
					DDR_Ptr  = &DDRC_REG;
		        break;
			case 3:	Port_Ptr = &PORTD_REG;
					Pin_PTR  = &PIND_REG;
					DDR_Ptr  = &DDRD_REG;
		        break;
		}
		if (INPUT == (Port_Pin_Config[i].Pin_Dir))
		{
			CLEAR_BIT(*DDR_Ptr,Port_Pin_Config[i].Pin_Num);
			
			if (STD_HIGH == (Port_Pin_Config[i].PullUp))
			{
				SET_BIT(*Port_Ptr,Port_Pin_Config[i].Pin_Num);
			}
			else if (STD_LOW == (Port_Pin_Config[i].PullUp))
			{
				CLEAR_BIT(*Port_Ptr,Port_Pin_Config[i].Pin_Num);
			}
		}
		else if (OUTPUT == (Port_Pin_Config[i].Pin_Dir))
		{
			SET_BIT(*DDR_Ptr,Port_Pin_Config[i].Pin_Num);
			
			if (STD_HIGH == (Port_Pin_Config[i].Pin_Level))
			{
				SET_BIT(*Port_Ptr,Port_Pin_Config[i].Pin_Num);
			}
			else if (STD_LOW == (Port_Pin_Config[i].Pin_Level))
			{
				CLEAR_BIT(*Port_Ptr,Port_Pin_Config[i].Pin_Num);
			}
		}
		Port_Status = PORT_INITIALIZED;
	}
}
}

}


/************************************************************************************
* Service Name: Port_SetPinDirection
* Service ID[hex]: 0x01
* Sync/Async: Synchronous
* Reentrancy: reentrant
* Parameters (in): Pin - Port Pin ID number , Direction - Port Pin Direction
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Sets the port pin direction.
************************************************************************************/
void Port_SetPinDirection( Port_PinType Pin, Port_PinDirectionType Direction )
{
	/*
	Port_IDType *Port_Ptr = NULL_PTR;
	Port_PinType *Pin_PTR = NULL_PTR;
	*/
	uint8 *DDR_Ptr = NULL_PTR;
	boolean error = FALSE;
	#if (PORT_DEV_ERROR_DETECT == STD_ON)
	/* check if the Port driver is initialized*/
	if (PORT_NOT_INITIALIZED == Port_Status)
	{
		/* Report to DET  */
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_DIRECTION_SID,
		     PORT_E_UNINIT );
			 error = TRUE;
	}
	else {}
	/* check if Incorrect Port Pin ID passed*/
	if ((Pin > MAX_PIN_NUM) || (Pin < MIN_PIN_NUM ))
	{
		/* Report to DET  */
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_DIRECTION_SID,
		     PORT_E_PARAM_PIN);
			 error = TRUE;
	}
	else {}
	/* check if Port Pin not configured as changeable */
	if (STD_OFF == Port_Pin_Config[Pin].Pin_Dir_Chang)
	{
		/* Report to DET  */
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_DIRECTION_SID,
		     PORT_E_DIRECTION_UNCHANGEABLE);
			 error = TRUE;
	}
	else {}
    #endif

	if (FALSE == error)
	{


		switch(Port_Pin_Config[Pin].Port_Num)
		{
			case 0:	DDR_Ptr  = &DDRA_REG;
				break;
			case 1:	DDR_Ptr  = &DDRB_REG;
				break;
			case 2:	DDR_Ptr  = &DDRC_REG;
				break;
			case 3:	DDR_Ptr  = &DDRD_REG;
				break;
		}
		if (INPUT == Direction)
		{
			CLEAR_BIT(*DDR_Ptr,Port_Pin_Config[Pin].Pin_Num);
			/*
			if (STD_HIGH == (Port_Pin_Config[i].PullUp))
			{
				SET_BIT(*Port_Ptr,Port_Pin_Config[i].Pin_Num);
			}
			else if (STD_LOW == (Port_Pin_Config[i].PullUp))
			{
				CLEAR_BIT(*Port_Ptr,Port_Pin_Config[i].Pin_Num);
			}
			*/
		}
		else if (OUTPUT == Direction)
		{
			SET_BIT(*DDR_Ptr,Port_Pin_Config[Pin].Pin_Num);
			/*
			if (STD_HIGH == (Port_Pin_Config[i].Pin_Level))
			{
				SET_BIT(*Port_Ptr,Port_Pin_Config[i].Pin_Num);
			}
			else if (STD_LOW == (Port_Pin_Config[i].Pin_Level))
			{
				CLEAR_BIT(*Port_Ptr,Port_Pin_Config[i].Pin_Num);
			}
			*/
		}
	}	
}


/************************************************************************************
* Service Name: Port_RefreshPortDirection
* Service ID[hex]: 0x02
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Refreshes port direction.
************************************************************************************/
void Port_RefreshPortDirection( void )
{
	uint8 *DDR_Ptr = NULL_PTR;
	uint8 DDR_Value;
	{
	volatile int i;
	for (i = MIN_PIN_NUM; i <= MAX_PIN_NUM; i+=8)
	{
		switch(Port_Pin_Config[i].Port_Num)
		{
			case 0:	DDR_Ptr  = &DDRA_REG;
				break;
			case 1:	DDR_Ptr  = &DDRB_REG;
				break;
			case 2:	DDR_Ptr  = &DDRC_REG;
				break;
			case 3:	DDR_Ptr  = &DDRD_REG;
				break;
		}
		DDR_Value = *DDR_Ptr;
		*DDR_Ptr = DDR_Value;
	}
}
}


/************************************************************************************
* Service Name: Port_GetVersionInfo
* Service ID[hex]: 0x03
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): versioninfo - Pointer to where to store the version information of this module.
* Return value: None
* Description: Returns the version information of this module.
************************************************************************************/
#if (PORT_VERSION_INFO_API == STD_ON)
	void Port_GetVersionInfo( Std_VersionInfoType* versioninfo )
	{
	
	#if (PORT_DEV_ERROR_DETECT == STD_ON)
		/* Check if input pointer is not Null pointer */
		if(NULL_PTR == versioninfo)
		{
			/* Report to DET  */
			Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
					PORT_GET_VERSION_INFO_SID, PORT_E_PARAM_POINTER);
		}
		else
	#endif /* (PORT_DEV_ERROR_DETECT == STD_ON) */
		{
			/* Copy the vendor Id */
			versioninfo->vendorID = (uint16)PORT_VENDOR_ID;
			/* Copy the module Id */
			versioninfo->moduleID = (uint16)PORT_MODULE_ID;
			/* Copy Software Major Version */
			versioninfo->sw_major_version = (uint8)PORT_SW_MAJOR_VERSION;
			/* Copy Software Minor Version */
			versioninfo->sw_minor_version = (uint8)PORT_SW_MINOR_VERSION;
			/* Copy Software Patch Version */
			versioninfo->sw_patch_version = (uint8)PORT_SW_PATCH_VERSION;
		}
	}
#endif

/************************************************************************************
* Service Name: Port_SetPinMode
* Service ID[hex]: 0x04
* Sync/Async: Synchronous
* Reentrancy: reentrant
* Parameters (in): Pin - Port Pin ID number, Mode - New Port Pin mode to be set on port pin
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Sets the port pin mode.
************************************************************************************/
void Port_SetPinMode( Port_PinType Pin, Port_PinModeType Mode )
{
	boolean error = FALSE;
	#if (PORT_DEV_ERROR_DETECT == STD_ON)
	/* check if the Port driver is initialized*/
	if (PORT_NOT_INITIALIZED == Port_Status)
	{
		/* Report to DET  */
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_MODE_SID,
		     PORT_E_UNINIT );
			 error = TRUE;
	}
	else {}
	/* check if Incorrect Port Pin ID passed*/
	if ((Pin > MAX_PIN_NUM) || (Pin < MIN_PIN_NUM ))
	{
		/* Report to DET  */
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_MODE_SID,
		     PORT_E_PARAM_PIN);
			 error = TRUE;
	}
	else {}
	/* check if Incorrect Port Pin Mode passed*/
	if ((Mode > I2C_MODE) || (Pin < DIO_MODE ))
	{
		/* Report to DET  */
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_MODE_SID,
		     PORT_E_PARAM_INVALID_MODE);
			 error = TRUE;
	}
	else {}
	/* check if Port Pin mode not configured as changeable */
	if (STD_OFF == Port_Pin_Config[Pin].Pin_Mode_Chang)
	{
		/* Report to DET  */
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_MODE_SID,
		     PORT_E_MODE_UNCHANGEABLE);
			 error = TRUE;
	}
	else {}
	#endif
}