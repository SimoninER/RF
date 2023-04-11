

// Configuration bits: selected in the GUI

// FSEC
#pragma config BWRP = OFF    //Boot Segment Write-Protect bit->Boot Segment may be written
#pragma config BSS = DISABLED    //Boot Segment Code-Protect Level bits->No Protection (other than BWRP)
#pragma config BSEN = OFF    //Boot Segment Control bit->No Boot Segment
#pragma config GWRP = OFF    //General Segment Write-Protect bit->General Segment may be written
#pragma config GSS = DISABLED    //General Segment Code-Protect Level bits->No Protection (other than GWRP)
#pragma config CWRP = OFF    //Configuration Segment Write-Protect bit->Configuration Segment may be written
#pragma config CSS = DISABLED    //Configuration Segment Code-Protect Level bits->No Protection (other than CWRP)
#pragma config AIVTDIS = OFF    //Alternate Interrupt Vector Table bit->Disabled AIVT

// FBSLIM
#pragma config BSLIM = 8191    //Boot Segment Flash Page Address Limit bits->8191

// FOSCSEL
#pragma config FNOSC = FRC              // Oscillator Source Selection (Internal Fast RC (FRC))
#pragma config IESO = OFF               // Two-speed Oscillator Start-up Enable bit (Start up with user-selected oscillator source)

// FOSC
// Oscillator Mode Settings
// EC (External Clock, AOSCMD<1:1> bits value 11))
// XT (Crystal, AOSCMD<1:0> bits value 11))
// HS (High-Speed, AOSCMD<0:1> bits value 11))
// EC (Auxiliary Oscillator disabled, default setting, AOSCMD<0:0> bits value 11))
#ifndef EXT_OSC
#pragma config POSCMD = NONE            // Primary Oscillator Mode Select bits (Primary oscillator disabled)
#else
#pragma config POSCMD = EC              // Primary Oscillator Mode Select bits (External Clock)
#endif
#ifndef DEBUG
#pragma config OSCIOFNC = ON            // OSC2 Pin Function bit (ON - OSC2 is general purpose digital I/O pin, OFF OSC2 output)
#else
#pragma config OSCIOFNC = OFF            
#endif
#pragma config FCKSM = CSECMD           // Clock Switching Mode bits (Clock switching is enabled,Fail-safe Clock Monitor is disabled)
#pragma config XTCFG = G1               // XT Config (8-16 MHz crystals)
#pragma config XTBST = ENABLE           // XT Boost (Boost the kick-start)

// FWDT
#pragma config RWDTPS = PS1024          //Run Mode Watchdog Timer Post Scaler select bits->1:1048576
#pragma config RCLKSEL = LPRC           //Watchdog Timer Clock Select bits->Always use LPRC
#pragma config WINDIS = ON              //Watchdog Timer Window Enable bit->Watchdog Timer in Window mode
#pragma config WDTWIN = WIN25           //Watchdog Timer Window Select bits->WDT Window is 25% of WDT period
#pragma config SWDTPS = PS1048576       //Sleep Mode Watchdog Timer Post Scaler select bits->1:1048576
#pragma config FWDTEN = ON_SW           //Watchdog Timer Enable bit->WDT controlled via SW, use WDTCON.ON bit

// FICD
#pragma config ICS = PGD2               //ICD Communication Channel Select bits->Communicate on PGC2 and PGD2
#pragma config JTAGEN = OFF             //JTAG Enable bit->JTAG is disabled

// FDMTIVTL
#pragma config DMTIVTL = 0              //Dead Man Timer Interval low word->0

// FDMTIVTH
#pragma config DMTIVTH = 0              //Dead Man Timer Interval high word->0

// FDMTCNTL
#pragma config DMTCNTL = 0              //Lower 16 bits of 32 bit DMT instruction count time-out value (0-0xFFFF)->0

// FDMTCNTH
#pragma config DMTCNTH = 0              //Upper 16 bits of 32 bit DMT instruction count time-out value (0-0xFFFF)->0

// FDMT
#pragma config DMTDIS = OFF             //Dead Man Timer Disable bit->Dead Man Timer is Disabled and can be enabled by software

// FDEVOPT
#pragma config ALTI2C1 = OFF            //Alternate I2C1 Pin bit->I2C1 mapped to SDA1/SCL1 pins
#pragma config ALTI2C2 = OFF            //Alternate I2C2 Pin bit->I2C2 mapped to SDA2/SCL2 pins
#pragma config SMBEN = SMBUS            //SM Bus Enable->SMBus input threshold is enabled
#pragma config SPI2PIN = PPS            //SPI2 Pin Select bit->SPI2 uses I/O remap (PPS) pins

// FALTREG
#pragma config CTXT1 = OFF              //Specifies Interrupt Priority Level (IPL) Associated to Alternate Working Register 1 bits->Not Assigned
#pragma config CTXT2 = OFF              //Specifies Interrupt Priority Level (IPL) Associated to Alternate Working Register 2 bits->Not Assigned
#pragma config CTXT3 = OFF              //Specifies Interrupt Priority Level (IPL) Associated to Alternate Working Register 3 bits->Not Assigned
#pragma config CTXT4 = OFF              //Specifies Interrupt Priority Level (IPL) Associated to Alternate Working Register 4 bits->Not Assigned

// MSI INTERFACE 
#pragma config MBXM0 = S2M              // Mailbox 0 data direction (Mailbox register configured for Master data read (Slave to Master data transfer))
#pragma config MBXM1 = M2S              // Mailbox 1 data direction (Mailbox register configured for Master data read (Slave to Master data transfer))
#pragma config MBXM2 = S2M              // Mailbox 2 data direction (Mailbox register configured for Master data write (Master to Slave data transfer))
#pragma config MBXM3 = M2S              // Mailbox 3 data direction (Mailbox register configured for Master data read (Slave to Master data transfer))
#pragma config MBXM4 = M2S              // Mailbox 4 data direction (Mailbox register configured for Master data read (Slave to Master data transfer))
#pragma config MBXM5 = M2S              // Mailbox 5 data direction (Mailbox register configured for Master data read (Slave to Master data transfer))
#pragma config MBXM6 = M2S              // Mailbox 6 data direction (Mailbox register configured for Master data read (Slave to Master data transfer))
#pragma config MBXM7 = M2S              // Mailbox 7 data direction (Mailbox register configured for Master data read (Slave to Master data transfer))
#pragma config MBXM8 = M2S              // Mailbox 8 data direction (Mailbox register configured for Master data read (Slave to Master data transfer))
#pragma config MBXM9 = S2M              // Mailbox 9 data direction (Mailbox register configured for Master data read (Slave to Master data transfer))
#pragma config MBXM10 = S2M             // Mailbox 10 data direction (Mailbox register configured for Master data read (Slave to Master data transfer))
#pragma config MBXM11 = S2M             // Mailbox 11 data direction (Mailbox register configured for Master data read (Slave to Master data transfer))
#pragma config MBXM12 = S2M             // Mailbox 12 data direction (Mailbox register configured for Master data read (Slave to Master data transfer))
#pragma config MBXM13 = S2M             // Mailbox 13 data direction (Mailbox register configured for Master data read (Slave to Master data transfer))
#pragma config MBXM14 = S2M             // Mailbox 14 data direction (Mailbox register configured for Master data read (Slave to Master data transfer))
#pragma config MBXM15 = M2S             // Mailbox 15 data direction (Mailbox register configured for Master data read (Slave to Master data transfer))

#pragma config MBXHSA = MBX0            // Mailbox handshake protocol block A register assignment (MSIxMBXD0 assigned to mailbox handshake protocol block A)
#pragma config MBXHSB = MBX2            // Mailbox handshake protocol block B register assignment (MSIxMBXD1 assigned to mailbox handshake protocol block B)
#pragma config MBXHSC = MBX15           // Mailbox handshake protocol block C register assignment (MSIxMBXD15 assigned to mailbox handshake protocol block C)

#pragma config HSAEN = ON               // Mailbox A data flow control protocol block enable (Mailbox data flow control handshake protocol block enabled.)
#pragma config HSBEN = ON               // Mailbox B data flow control protocol block enable (Mailbox data flow control handshake protocol block enabled.)
#pragma config HSCEN = ON               // Mailbox C data flow control protocol block enable (Mailbox data flow control handshake protocol block enabled.)
#pragma config HSDEN = OFF               // Mailbox D data flow control protocol block enable (Mailbox data flow control handshake protocol block disabled.)
#pragma config HSEEN = OFF              // Mailbox E data flow control protocol block enable (Mailbox data flow control handshake protocol block disabled.)
#pragma config HSFEN = OFF              // Mailbox F data flow control protocol block enable (Mailbox data flow control handshake protocol block disabled.)
#pragma config HSGEN = OFF              // Mailbox G data flow control protocol block enable (Mailbox data flow control handshake protocol block disabled.)
#pragma config HSHEN = OFF              // Mailbox H data flow control protocol block enable (Mailbox data flow control handshake protocol block disabled.)

// FCFGPRA0
#pragma config CPRA0 = MSTR             //Pin RA0 Ownership Bits->Master core owns pin.
#pragma config CPRA1 = MSTR             //Pin RA1 Ownership Bits->Master core owns pin.
#pragma config CPRA2 = SLV1             //Pin RA2 Ownership Bits->Master core owns pin.
#pragma config CPRA3 = SLV1             //Pin RA3 Ownership Bits->Master core owns pin.
#pragma config CPRA4 = SLV1             //Pin RA4 Ownership Bits->Master core owns pin.

// FCFGPRB0
#pragma config CPRB0 = MSTR             //Pin RB0 Ownership Bits->Master core owns pin.
#pragma config CPRB1 = MSTR             //Pin RB1 Ownership Bits->Master core owns pin.
#pragma config CPRB2 = MSTR             //Pin RB2 Ownership Bits->Master core owns pin.
#pragma config CPRB3 = MSTR             //Pin RB3 Ownership Bits->Master core owns pin.
#pragma config CPRB4 = MSTR             //Pin RB4 Ownership Bits->Master core owns pin.
#pragma config CPRB5 = MSTR             //Pin RB5 Ownership Bits->Master core owns pin.
#pragma config CPRB6 = MSTR             //Pin RB6 Ownership Bits->Master core owns pin.
#pragma config CPRB7 = MSTR             //Pin RB7 Ownership Bits->Master core owns pin.
#pragma config CPRB8 = MSTR             //Pin RB8 Ownership Bits->Master core owns pin.
#pragma config CPRB9 = SLV1             //Pin RB9 Ownership Bits->Master core owns pin.
#pragma config CPRB10 = SLV1            //Pin RB10 Ownership Bits->Master core owns pin.
#pragma config CPRB11 = SLV1            //Pin RB11 Ownership Bits->Master core owns pin.
#pragma config CPRB12 = SLV1            //Pin RB12 Ownership Bits->Master core owns pin.
#pragma config CPRB13 = SLV1            //Pin RB13 Ownership Bits->Master core owns pin.
#pragma config CPRB14 = MSTR            //Pin RB14 Ownership Bits->Master core owns pin.
#pragma config CPRB15 = MSTR            //Pin RB15 Ownership Bits->Master core owns pin.

#pragma config S1FNOSC = FRC            // Oscillator Source Selection (Internal Fast RC (FRC))
#pragma config S1IESO = OFF             // Two-speed Oscillator Start-up Enable bit (Start up with user-selected oscillator source)
#pragma config S1OSCIOFNC = ON          // Slave OSC2 Pin Function bit (ON - OSC2 is general purpose digital I/O pin, OFF OSC2 output)
#pragma config S1FCKSM = CSECMD         // Clock Switching Mode bits (Clock switching is enabled,Fail-safe Clock Monitor is disabled)
#pragma config S1RWDTPS = PS1024        // Run Mode Watchdog Timer Post Scaler select bits (1:1024) ~ 1 Second
#pragma config S1RCLKSEL = LPRC         // Watchdog Timer Clock Select bits (Always use LPRC)
#pragma config S1WINDIS = ON            // Watchdog Timer Window Enable bit (Watchdog Timer operates in Non-Window mode)
#pragma config S1WDTWIN = WIN25         // Watchdog Timer Window Select bits (WDT Window is 25% of WDT period)
#pragma config S1SWDTPS = PS1048576     // Sleep Mode Watchdog Timer Post Scaler select bits (1:1048576)
#pragma config S1FWDTEN = ON_SW         // Watchdog Timer Enable bit (WDT controlled via WDTCON.ON bit)

#pragma config S1ICS = PGD2             // ICD Communication Channel Select bits (Communicate on S1PGEC2 and S1PGED2)       

#pragma config S1ISOLAT = ON            // Isolate the Slave core subsystem from the master subsystem during Debug (The slave can operate (in debug mode) even if the SLVEN bit in the MSI is zero.)
#pragma config S1NOBTSWP = OFF          // BOOTSWP Instruction Enable/Disable bit (BOOTSWP instruction is disabled)
#pragma config S1ALTI2C1 = ON           // Alternate I2C1 Pin bit (I2C1 mapped to SDA1/SCL1 pins)
#pragma config S1SPI1PIN = PPS          // S1 SPI1 Pin Select bit (Slave SPI1 uses I/O remap (PPS) pins)
#pragma config S1SSRE = ON              // Slave Slave Reset Enable (Slave generated resets will reset the Slave Enable Bit in the MSI module)
#pragma config S1MSRE = ON              // Master Slave Reset Enable (The master software oriented RESET events (RESET Op-Code, Watchdog timeout, TRAP reset, illegalInstruction) will also cause the slave subsystem to reset.)
#pragma config S1CTXT1 = IPL6           // Specifies Interrupt Priority Level (IPL) Associated to Alternate Working Register 1 bits (IPL6)
#pragma config S1CTXT2 = OFF            // Specifies Interrupt Priority Level (IPL) Associated to Alternate Working Register 2 bits (Not Assigned)
#pragma config S1CTXT3 = OFF            // Specifies Interrupt Priority Level (IPL) Associated to Alternate Working Register 3 bits (Not Assigned)
#pragma config S1CTXT4 = OFF            // Specifies Interrupt Priority Level (IPL) Associated to Alternate Working Register 4 bits (Not Assigned)

#include "xc.h"
#include "system.h"
#include <stdbool.h>

volatile bool rst = FALSE;
volatile bool app = FALSE;
volatile bool boot = TRUE;
volatile uint32_t btimer;

void SYSTEM_Initialize(void)
{
    
        //Switch to FRC (no divider, no PLL), assuming we aren't already running from that.
    if(_COSC != 0b000)
    {
        __builtin_write_OSCCONH(0x00);  //NOSC = 0b000 = FRC without divider or PLL
        __builtin_write_OSCCONL((OSCCON & 0x7E) | 0x01);  //Clear CLKLOCK and assert OSWEN = 1 to initiate switch over
        //Wait for switch over to complete.
        while(_COSC != _NOSC);
    }
    
    // Configure PLL pre scaler, both PLL post scalers, and PLL feedback divider
    _PLLPRE = 1;      // N1=1
    _PLLFBDIV = 160;  // M = 160 (ex: FVCO = 1280MHz = 8MHz * 160)
    _POST1DIV = 4;    // N2=4 (1280MHz / 4, followed by /2 (N3), followed by fixed / 2 = 80MHz)
    _POST2DIV = 2;    // N3=2
#ifndef EXT_OSC
    // Initiate Clock Switch to FRC with PLL (NOSC = 0b001)
    __builtin_write_OSCCONH(0x01);
#else
    // Initiate Clock Switch to Primary Oscillator with PLL (NOSC = 0b011)
    __builtin_write_OSCCONH(0x03);
#endif
    if(_COSC != _NOSC)
    {
        __builtin_write_OSCCONL((OSCCON & 0x7F) | 0x01);    //Assert OSWEN and make sure CLKLOCK is clear, to initiate the switching operation
        // Wait for clock switch to finish
        while(_COSC != _NOSC);    
    }
    
    _NSTDIS = 1; // disable nesting interrupts    

    // UART initialization
    UART_Init(UART_1,BLD_BAUD,FALSE,FALSE);
#ifdef TEST_BRD   
    //Set PPS up for the UART on B5 and B6
    _RP38R = 0b000001;  // B6 TX
    _U1RXR = 37;        // B5 RX
#else
    //Set PPS up for the UART on B6 and B7
    _RP39R = 0b000001;  // B7 TX
    _U1RXR = 38;        // B6 RX
#endif
    
    // Health tick LED
#ifdef TEST_BRD
    _TRISB7 = 0;
    // Manual Bootloader start
    _ANSELA0 = 0;
    _TRISA0 = 1; // A0 is input
#else
    _TRISB8 = 0;
#endif
  
#ifdef DEBUG
    // Osc out on B1
    _TRISB1 = 0;
#endif    
    WDTCONLbits.ON = 1;
    __builtin_enable_interrupts();
       
}

/**
 End of File
*/