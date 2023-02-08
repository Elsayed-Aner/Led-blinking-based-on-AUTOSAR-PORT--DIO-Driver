<div align="center">

  <img src="images/logo_1.1.JPG.jpg" alt="logo" width="auto" height="auto" />
  <h1>Atmega16 AUTOSAR Port Driver</h1>
  
  <p>
    Led toggling by a button on AVR MCU (Atmega16) by apply the full AUTOSAR Port layered architecture model.
  </p>
  
  
  <!-- Badges -->
<p>
  <a href="https://github.com/Elsayed-Aner/Led-blinking-based-on-AUTOSAR-PORT--DIO-Driver/graphs/contributors">
    <img src="https://img.shields.io/github/contributors/Elsayed-Aner/Led-blinking-based-on-AUTOSAR-PORT--DIO-Driver" alt="contributors" />
  </a>
  <a href="">
    <img src="https://img.shields.io/github/last-commit/Elsayed-Aner/Led-blinking-based-on-AUTOSAR-PORT--DIO-Driver" alt="last update" />
  </a>
  <a href="https://github.com/Elsayed-Aner/Led-blinking-based-on-AUTOSAR-PORT--DIO-Driver/network/members">
    <img src="https://img.shields.io/github/forks/Elsayed-Aner/Led-blinking-based-on-AUTOSAR-PORT--DIO-Driver" alt="forks" />
  </a>
  <a href="https://github.com/Elsayed-Aner/Led-blinking-based-on-AUTOSAR-PORT--DIO-Driver/stargazers">
    <img src="https://img.shields.io/github/stars/Elsayed-Aner/Led-blinking-based-on-AUTOSAR-PORT--DIO-Driver" alt="stars" />
  </a>
  <a href="https://github.com/Elsayed-Aner/Led-blinking-based-on-AUTOSAR-PORT--DIO-Driver/issues/">
    <img src="https://img.shields.io/github/issues/Elsayed-Aner/Led-blinking-based-on-AUTOSAR-PORT--DIO-Driver" alt="open issues" />
  </a>
  <a href="https://github.com/Elsayed-Aner/Led-blinking-based-on-AUTOSAR-PORT--DIO-Driver/blob/master/LICENSE">
    <img src="https://img.shields.io/github/license/Elsayed-Aner/Led-blinking-based-on-AUTOSAR-PORT--DIO-Driver" alt="license" />
  </a>
</p>
   
<h4>
    <a href="https://github.com/Elsayed-Aner/Led-blinking-based-on-AUTOSAR-PORT--DIO-Driver/">View Demo</a>
  <span> · </span>
    <a href="https://github.com/Elsayed-Aner/Led-blinking-based-on-AUTOSAR-PORT--DIO-Driver">Documentation</a>
  <span> · </span>
    <a href="https://github.com/Elsayed-Aner/Led-blinking-based-on-AUTOSAR-PORT--DIO-Driver/issues/">Report Bug</a>
  <span> · </span>
    <a href="https://github.com/Elsayed-Aner/Led-blinking-based-on-AUTOSAR-PORT--DIO-Driver/issues/">Request Feature</a>
  </h4>
</div>

<br />

  
</div>
<br />


<!-- AUTOSAR DRIVER -->
# AUTOSAR DRIVER

- [System API](#system-api)
- [Features](#features)
- [PORT Driver](#port-driver)
- [DIO Driver](#dio-driver)
- [Functions](#functions)
- [Contributing](#contributing)
- [License](#license)
- [Contact](#contact)
- [Acknowledgements](#acknowledgements)


<!-- System API -->
## System API
- `DIO_READ_CHANNEL_SID`
- `DIO_READ_PORT_SID`
- `DIO_WRITE_PORT_SID`
- `DIO_READ_CHANNEL_GROUP_SID`
- `DIO_WRITE_CHANNEL_GROUP_SID`
- `DIO_GET_VERSION_INFO_SID`
- `DIO_INIT_SID`
- `DIO_FLIP_CHANNEL_SID`

<!-- Features -->
## Features

- abstracted layers.
- store data into encrypted files.
- multiple command option.

<!-- PORT Driver -->
## PORT Driver

<!-- DIO Driver -->
## DIO Driver

```c
 /******************************************************************************
 * Module: Dio
 * File Name: Dio.h
 * Description: Header file for Dio Module.
 ******************************************************************************/

#ifndef DIO_H
#define DIO_H

/* Id for the company in the AUTOSAR
 * for example Mohamed Tarek's ID = 1000 :) */
#define DIO_VENDOR_ID    (1000U)

/* Dio Module Id */
#define DIO_MODULE_ID    (120U)

/* Dio Instance Id */
#define DIO_INSTANCE_ID  (0U)

/*
 * Module Version 1.0.0
 */
#define DIO_SW_MAJOR_VERSION           (1U)
#define DIO_SW_MINOR_VERSION           (0U)
#define DIO_SW_PATCH_VERSION           (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define DIO_AR_RELEASE_MAJOR_VERSION   (4U)
#define DIO_AR_RELEASE_MINOR_VERSION   (0U)
#define DIO_AR_RELEASE_PATCH_VERSION   (3U)

/*
 * Macros for Dio Status
 */
#define DIO_INITIALIZED                (1U)
#define DIO_NOT_INITIALIZED            (0U)

/* Standard AUTOSAR types */
#include "Std_Types.h"

/* AUTOSAR checking between Std Types and Dio Modules */
#if ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != DIO_AR_RELEASE_MAJOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_MINOR_VERSION != DIO_AR_RELEASE_MINOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_PATCH_VERSION != DIO_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Std_Types.h does not match the expected version"
#endif

/* Dio Pre-Compile Configuration Header file */
#include "Dio_Cfg.h"

/* AUTOSAR Version checking between Dio_Cfg.h and Dio.h files */
#if ((DIO_CFG_AR_RELEASE_MAJOR_VERSION != DIO_AR_RELEASE_MAJOR_VERSION)\
 ||  (DIO_CFG_AR_RELEASE_MINOR_VERSION != DIO_AR_RELEASE_MINOR_VERSION)\
 ||  (DIO_CFG_AR_RELEASE_PATCH_VERSION != DIO_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Dio_Cfg.h does not match the expected version"
#endif

/* Software Version checking between Dio_Cfg.h and Dio.h files */
#if ((DIO_CFG_SW_MAJOR_VERSION != DIO_SW_MAJOR_VERSION)\
 ||  (DIO_CFG_SW_MINOR_VERSION != DIO_SW_MINOR_VERSION)\
 ||  (DIO_CFG_SW_PATCH_VERSION != DIO_SW_PATCH_VERSION))
  #error "The SW version of Dio_Cfg.h does not match the expected version"
#endif

/* Non AUTOSAR files */
#include "Common_Macros.h"

/* Service ID for DIO read Channel */
#define DIO_READ_CHANNEL_SID           (uint8)0x00

/* Service ID for DIO write Channel */
#define DIO_WRITE_CHANNEL_SID          (uint8)0x01

/* Service ID for DIO read Port */
#define DIO_READ_PORT_SID              (uint8)0x02

/* Service ID for DIO write Port */
#define DIO_WRITE_PORT_SID             (uint8)0x03

/* Service ID for DIO read Channel Group */
#define DIO_READ_CHANNEL_GROUP_SID     (uint8)0x04

/* Service ID for DIO write Channel Group */
#define DIO_WRITE_CHANNEL_GROUP_SID    (uint8)0x05

/* Service ID for DIO GetVersionInfo */
#define DIO_GET_VERSION_INFO_SID       (uint8)0x12

/* Service ID for DIO Init Channel */
#define DIO_INIT_SID                   (uint8)0x10

/* Service ID for DIO flip Channel */
#define DIO_FLIP_CHANNEL_SID           (uint8)0x11

/* DET code to report Invalid Channel */
#define DIO_E_PARAM_INVALID_CHANNEL_ID (uint8)0x0A

/* Dio_Init API service called with NULL pointer parameter */
#define DIO_E_PARAM_CONFIG             (uint8)0x10

/* DET code to report Invalid Port */
#define DIO_E_PARAM_INVALID_PORT_ID    (uint8)0x14

/* DET code to report Invalid Channel Group */
#define DIO_E_PARAM_INVALID_GROUP      (uint8)0x1F

#define DIO_E_PARAM_POINTER             (uint8)0x20

#define DIO_E_UNINIT                   (uint8)0xF0

/* Type definition for Dio_ChannelType used by the DIO APIs */
typedef uint8 Dio_ChannelType;

/* Type definition for Dio_PortType used by the DIO APIs */
typedef uint8 Dio_PortType;

/* Type definition for Dio_LevelType used by the DIO APIs */
typedef uint8 Dio_LevelType;

/* Type definition for Dio_PortLevelType used by the DIO APIs */
typedef uint8 Dio_PortLevelType;

/* Structure for Dio_ChannelGroup */
typedef struct
{
  /* Mask which defines the positions of the channel group */
  uint8 mask;
  /* Position of the group from LSB */
  uint8 offset;
  /* This shall be the port ID which the Channel group is defined. */
  Dio_PortType PortIndex;
} Dio_ChannelGroupType;

typedef struct
{
	/* Member contains the ID of the Port that this channel belongs to */
	Dio_PortType Port_Num;
	/* Member contains the ID of the Channel*/
	Dio_ChannelType Ch_Num;
}Dio_ConfigChannel;

/* Data Structure required for initializing the Dio Driver */
typedef struct
{
	Dio_ConfigChannel Channels[DIO_CONFIGURED_CHANNLES];
} Dio_ConfigType;

/* Function for DIO read Channel API */
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId);

/* Function for DIO write Channel API */
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level);

/* Function for DIO read Port API */
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);

/* Function for DIO write Port API */
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level);

/* Function for DIO Initialization API */
void Dio_Init(const Dio_ConfigType * ConfigPtr);

#if (DIO_FLIP_CHANNEL_API == STD_ON)
/* Function for DIO flip channel API */
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId);
#endif

/* Function for DIO Get Version Info API */
#if (DIO_VERSION_INFO_API == STD_ON)
void Dio_GetVersionInfo(Std_VersionInfoType *versioninfo);
#endif

/* Extern PB structures to be used by Dio and other modules */
extern const Dio_ConfigType Dio_Configuration;
#endif /* DIO_H */
```

<!-- Functions -->
## Functions

Use this space to tell a little more about your project and how it can be used. Show additional screenshots, code samples, demos or link to other resources.


<!-- Contributing -->
## Contributing

Contributions are always welcome!


<!-- License -->
## License

Distributed under the no License. See LICENSE.txt for more information.


<!-- Contact -->
## Contact

Elsayed Atif Aner - [facebook](https://www.facebook.com/alsayed.atif) - alsayedatif88@gmail.com

Project Link: [https://github.com/Elsayed-Aner/Led-blinking-based-on-AUTOSAR-PORT--DIO-Driver](https://github.com/Elsayed-Aner/Led-blinking-based-on-AUTOSAR-PORT--DIO-Driver)

<!-- Acknowledgments -->
## Acknowledgements

Use this section to mention useful resources and libraries that you have used in your projects.

 - [Alex Fosdick](https://www.coursera.org/instructor/~19507668)
 - [Quantum Leaps, LLC](https://www.youtube.com/@StateMachineCOM)
