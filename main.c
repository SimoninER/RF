
/**
  Section: Included Files
*/
#include "system.h"
#include "mcc_generated_files/boot/boot_run.h"
#include <libpic30.h>

/*
                         Main application
 */
int main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    RCON = 0x00;    // reset RCON if software reset has been executed
#ifdef DEBUG   
    printf("My Bootloader!\r");
#endif
    while (TRUE)
    {
        BOOT_Tasks();
    }
    return 1; 
}
/**
 End of File
*/

