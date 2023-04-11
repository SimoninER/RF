/*****************************************************************************
*
*               PROPRIETARY NOTICE
*               ----------- ------
*
*  This code is the sole property of xxxx Corporation and may
*  not be used, duplicated or distributed without the express written 
*  permission of xxxx Corporation
*  
*  Copyright (C) 2020 xxxx Corporation
*
*               ALL RIGHTS RESERVED
*               --- ------ --------
*
*  NAME:        uart.h
*
*  Date:        9/27/20
*
*  USAGE:    See Below
*
*  DESCRIPTION:
*             uart.c header file
*
*  AUTHOR:   Simon Malkevich
*
*
*****************************************************************************/

#ifndef UART_H
#define UART_H

#include <xc.h>
#include "system.h"
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <libpic30.h>


#define MODE_UARTEN     BIT15
#define MODE_USIDL      BIT13
#define MODE_WAKE       BIT12
#define MODE_RXBIMD     BIT11
#define MODE_BRKOVR     BIT9
#define MODE_UTXBRK     BIT8
#define MODE_BRGH       BIT7
#define MODE_ABAUD      BIT6
#define MODE_UTXEN      BIT5
#define MODE_URXEN      BIT4
#define MODE_MOD3       BIT3
#define MODE_MOD2       BIT2
#define MODE_MOD1       BIT1
#define MODE_MOD0       BIT0

#define MODEH_SLPEN     BIT15
#define MODEH_ACTIVE    BIT14
#define MODEH_BCLKMOD   BIT11
#define MODEH_BCLKSEL1  BIT10
#define MODEH_BCLKSEL0  BIT9
#define MODEH_HALFDPLX  BIT8
#define MODEH_RUNOVF    BIT7
#define MODEH_URXINV    BIT6
#define MODEH_STSEL1    BIT5
#define MODEH_STSEL0    BIT4
#define MODEH_C0EN      BIT3
#define MODEH_UTXINV    BIT2
#define MODEH_FLO1      BIT1
#define MODEH_FLO0      BIT0

#define STAH_UTXISEL2   BIT14
#define STAH_UTXISEL1   BIT13
#define STAH_UTXISEL0   BIT12
#define STAH_URXISEL2   BIT10
#define STAH_URXISEL1   BIT9
#define STAH_URXISEL0   BIT8
#define STAH_TXWRE      BIT7
#define STAH_STPMD      BIT6
#define STAH_UTXBE      BIT5
#define STAH_UTXBF      BIT4
#define STAH_RIDLE      BIT3
#define STAH_XON        BIT2
#define STAH_URXBE      BIT1
#define STAH_URXBF      BIT0

#define STA_TXMTIE      BIT15
#define STA_PERIE       BIT14
#define STA_ABDOVE      BIT13
#define STA_CERIE       BIT12
#define STA_FERIE2      BIT10
#define STA_RXBKIE      BIT9
#define STA_OERIE       BIT8
#define STA_TRMT        BIT7
#define STA_PERR        BIT6
#define STA_ABDOVF      BIT5
#define STA_CERIF       BIT4
#define STA_FERR        BIT3
#define STA_RXBKIF      BIT2
#define STA_OERR        BIT1
#define STA_TXCIF       BIT0

typedef struct 
{
    uint16_t UxMODE;
    uint16_t UxMODEH;
    uint16_t UxSTA;
    uint16_t UxSTAH;
    uint16_t UxBRG;
    uint16_t UxBRGH;
    uint16_t UxRXREG;
    uint16_t DUMMY;
    uint16_t UxTXREG;
    uint16_t UxP1;
    uint16_t UxP2;
    uint16_t UxP3;
    uint16_t UxP3H;
    uint16_t UxTXCHK;
    uint16_t UxRXCHK;
    uint16_t UxSCCON;
    uint16_t UxSCINT;
    uint16_t UxINT;   
}UART_INSTANCE;

#define UART_1 ((UART_INSTANCE*)&U1MODE)
#define UART_2 ((UART_INSTANCE*)&U2MODE)

//#define BLD_BAUD   460800L
#define BLD_BAUD   115200L

inline static void UART_Enable(UART_INSTANCE *p)
{
    p->UxMODE |= MODE_UARTEN;   // Enable UART
}

inline static void UART_Disable(UART_INSTANCE *p)
{
    p->UxMODE |= !MODE_UARTEN;   // Disable UART
}

void UART_Init(UART_INSTANCE *p, uint32_t baud, bool rxInt, bool txInt);
uint8_t UART_Read(UART_INSTANCE *p);
void UART_Write(UART_INSTANCE *p,uint8_t txData);
bool UART_IsRxReady(UART_INSTANCE *p);
bool UART_IsTxReady(UART_INSTANCE *p);
bool UART_IsTxDone(UART_INSTANCE *p);

#endif