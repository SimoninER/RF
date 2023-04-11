
#include <xc.h>
#include "uart.h"
#include "system.h"


void UART_Init(UART_INSTANCE *p, uint32_t baud, bool rxInt, bool txInt)
{
    uint32_t brg;
    
    p->UxMODE |= MODE_BRGH;   //high-speed
    p->UxMODE &= ~(MODE_MOD2 | MODE_MOD1 | MODE_MOD0);  //asynchronous 8-bit UART
    p->UxMODEH &= ~(MODEH_STSEL1 | MODEH_STSEL0);       //1 stop bit
    p->UxMODEH &= ~(MODEH_BCLKSEL1 | MODEH_BCLKSEL0);   // clock source is Fcy/2
    
    brg = ((2*((FCY)/baud/4-1))+1)/2;
    p->UxBRG = (uint16_t)brg;
    p->UxBRGH = brg>>16;
    
    p->UxSTAH &= ~(STAH_UTXISEL2 | STAH_UTXISEL1 | STAH_UTXISEL0); // Interrupt after TX buffer is empty
    p->UxSTAH &= ~(STAH_URXISEL2 | STAH_URXISEL1 | STAH_URXISEL0); // Interrupt after RX buffer is empty
    
    if(rxInt)   // Enable UART RX interrupt
    { 
        if(p == UART_1)_U1RXIE = 1; 
        if(p == UART_2)_U2RXIE = 1; 
    } 
    if(txInt)   // Enable UART TX interrupt
    { 
        if(p == UART_1)_U1TXIE = 1; 
        if(p == UART_2)_U2TXIE = 1; 
    } 
    
    p->UxMODE |= MODE_UARTEN;   // Enable UART
    p->UxMODE |= MODE_URXEN;    // Enable UART RX
    p->UxMODE |= MODE_UTXEN;    // Enable UART TX
    _U2TXIF = 0;        // Clear TX Interrupt flag
}

uint8_t UART_Read(UART_INSTANCE *p)
{
    while(p->UxSTAH & STAH_URXBE)    
    {
        
    }

    if(p->UxSTA & STA_OERR)
    {
        p->UxSTA &= ~STA_OERR;
    }
    
    return p->UxRXREG;
}

void UART_Write(UART_INSTANCE *p, uint8_t txData)
{
    while(p->UxSTAH & STAH_UTXBF)
    {
        
    }
    
    p->UxTXREG = txData;    
}

bool UART_IsRxReady(UART_INSTANCE *p)
{
    return (!(p->UxSTAH & STAH_URXBE));
}

bool UART_IsTxReady(UART_INSTANCE *p)
{
    return(!(p->UxSTAH & STAH_UTXBF) && (p->UxMODE & MODE_UTXEN));
}

bool UART_IsTxDone(UART_INSTANCE *p)
{
    return p->UxSTA & STA_TRMT;
}



