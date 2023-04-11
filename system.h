

#ifndef _XTAL_FREQ
#define _XTAL_FREQ  8000000UL
#endif
#define WDT_CLR_KEY 0x5743

#include "xc.h"
#include "stdint.h"
#include "system_types.h"
#include <stdbool.h>
#include "uart.h"
#include "mcc_generated_files/watchdog.h"

#ifndef SYSTEM_H
#define	SYSTEM_H


///////////////////////////////////////////////////////////////////////////////
// Type Definitions
///////////////////////////////////////////////////////////////////////////////
typedef volatile uint16_t       vuint16_t;
///////////////////////////////////////////////////////////////////////////////
// Generic Bit Definitions
///////////////////////////////////////////////////////////////////////////////
#define BIT0    0x1
#define BIT1    0x2
#define BIT2    0x4
#define BIT3    0x8
#define BIT4    0x10
#define BIT5    0x20
#define BIT6    0x40
#define BIT7    0x80
#define BIT8    0x100
#define BIT9    0x200
#define BIT10   0x400
#define BIT11   0x800
#define BIT12   0x1000
#define BIT13   0x2000
#define BIT14   0x4000
#define BIT15   0x8000
#define BIT16   0x10000
#define BIT17   0x20000
#define BIT18   0x40000
#define BIT19   0x80000
#define BIT20   0x100000
#define BIT21   0x200000
#define BIT22   0x400000
#define BIT23   0x800000
#define BIT24   0x1000000
#define BIT25   0x2000000
#define BIT26   0x4000000
#define BIT27   0x8000000
#define BIT28   0x10000000
#define BIT29   0x20000000
#define BIT30   0x40000000
#define BIT31   0x80000000

#ifdef  FALSE
#undef  FALSE
#endif
#define FALSE   (0)

#ifdef  TRUE
#undef  TRUE
#endif
#define TRUE    (1)

//Bootloader LED flash rate
#define SYSTEM_LED_RATE 0x4000
// Bootloader run time before switching to application
#define  S_3S   0x100000
#define  S_2S   0xB0000
#define  S_1S   0x50000 
#define  S_100mS 0x10000 

#define WATCHDOG_CLR_KEY 0x5743

extern volatile bool rst;
extern volatile bool app;
extern volatile bool boot;
extern volatile uint32_t btimer;

#define COM_STATUS_LEDs  (*(vuint16_t *) (0x00E3E))  // 0x00E3E is TRISC address
#define PORTE_LAT  (*(vuint16_t *) (0x00E76))        // 0x00E76 is LATE address

inline static void SYSTEM_HealthLED_WDKick()
{
    WDTCONH = WATCHDOG_CLR_KEY; // clear watchdog timer
#ifdef TEST_BRD
    _LATB7 ^= 1;
#else
    _LATB8 ^= 1;
#endif
}

inline static void SYSTEM_CORCONInitialize()
{
    CORCON = (CORCON & 0x00F2) | CORCON_MODE_PORVALUES;    // POR value
}

inline static void SYSTEM_CORCONModeOperatingSet(SYSTEM_CORCON_MODES modeValue)
{
    CORCON = (CORCON & 0x00F2) | modeValue;
}

inline static void SYSTEM_CORCONRegisterValueSet(uint16_t value)
{
    CORCON = value;
}

inline static uint16_t SYSTEM_CORCONRegisterValueGet(void)
{    
    return CORCON;
}

inline static uint32_t SYSTEM_DeviceIdRegisterAddressGet(void)
{
    return __DEVID_BASE;
}

void SYSTEM_Initialize(void);
#endif	/* SYSTEM_H */
