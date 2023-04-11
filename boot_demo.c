/**
  @Generated 16-bit Bootloader Source File

  @Company:
    Microchip Technology Inc.

  @File Name: 
    boot_demo.c

  @Summary:
    This is the boot_demo.c file generated using 16-bit Bootloader

  @Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  16-bit Bootloader - 1.19.1
        Device            :  dsPIC33CH128MP502
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.36B
        MPLAB             :  MPLAB X v5.15
*/
/*
Copyright (c) [2012-2022] Microchip Technology Inc.  

    All rights reserved.

    You are permitted to use the accompanying software and its derivatives 
    with Microchip products. See the Microchip license agreement accompanying 
    this software, if any, for additional info regarding your rights and 
    obligations.
    
    MICROCHIP SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT 
    WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT 
    LIMITATION, ANY WARRANTY OF MERCHANTABILITY, TITLE, NON-INFRINGEMENT 
    AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT WILL MICROCHIP OR ITS
    LICENSORS BE LIABLE OR OBLIGATED UNDER CONTRACT, NEGLIGENCE, STRICT 
    LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR OTHER LEGAL EQUITABLE 
    THEORY FOR ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES INCLUDING BUT NOT 
    LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES, 
    OR OTHER SIMILAR COSTS. 
    
    To the fullest extend allowed by law, Microchip and its licensors 
    liability will not exceed the amount of fees, if any, that you paid 
    directly to Microchip to use this software. 
    
    THIRD PARTY SOFTWARE:  Notwithstanding anything to the contrary, any 
    third party software accompanying this software is subject to the terms 
    and conditions of the third party's license agreement.  To the extent 
    required by third party licenses covering such third party software, 
    the terms of such license will apply in lieu of the terms provided in 
    this notice or applicable license.  To the extent the terms of such 
    third party licenses prohibit any of the restrictions described here, 
    such restrictions will not apply to such third party software.
*/
//#include "../memory/flash.h"
#include "system.h"
#include "mcc_generated_files/memory/flash.h"
#include "mcc_generated_files/boot/boot_process.h"
//#include "boot_process.h"

#include <stdbool.h>
#include <stdint.h>
//#include "boot_config.h"
#include "mcc_generated_files/boot/boot_config.h"
//#include "boot_application_header.h"
#include "mcc_generated_files/boot/boot_application_header.h"
//#include "boot_process.h"
//#include "../system.h"


#define DOWNLOADED_IMAGE    0u
#define EXECUTION_IMAGE     0u

static bool inBootloadMode = false;
static bool executionImageRequiresValidation = true;
static bool executionImageValid = false;

static bool EnterBootloadMode(void);
static void RunBootLoader(void);
static bool EnterBootLoadMode(void);
void BlinkBootLoaderLED(void);

void BOOT_Tasks(void)
{
    BlinkBootLoaderLED();
    BOOT_ProcessCommand();
}

static bool EnterBootloadMode(void)
{   
#ifdef TEST_BRD
    if((_SWR == TRUE) || (_RA0 == 0))
#else
    if(_SWR == TRUE) 
#endif
    {
           RCON = 0x00;    // reset RCON if software reset has been executed
           return TRUE;
    }
    else
        return FALSE;
}

static void RunBootLoader()
{
        BlinkBootLoaderLED();
        if(BOOT_ProcessCommand() == BOOT_COMMAND_SUCCESS)
        {
            /* Add code here if you want to */
        }
}

void BlinkBootLoaderLED(void)
{
    static uint32_t count = 0;
    
    if(((++count) % SYSTEM_LED_RATE)==0)
    {
        SYSTEM_HealthLED_WDKick();
    }
}