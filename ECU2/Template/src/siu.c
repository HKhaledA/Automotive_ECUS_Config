#include "jdp.h"

void SIU_Init(void) {
    /* LEDs */
    SIU.PCR[9].R = 0x0200;    /* LED0 */
    SIU.PCR[42].R = 0x0200;   /* LED1 */
    SIU.PCR[13].R = 0x0200;   /* LED2 */
    SIU.PCR[12].R = 0x0200;   /* LED3 */
    SIU.PCR[62].R = 0x0200;   /* LED4 */
    SIU.PCR[61].R = 0x0200;   /* LED5 */
    SIU.PCR[59].R = 0x0200;   /* LED6 */
    SIU.PCR[11].R = 0x0200;   /* LED7 */

    /* Analog Inputs */
    SIU.PCR[33].R = 0x2500;   /* ANAIN1 */
    SIU.PCR[65].R = 0x2500;   /* POT */
   
    /* Digital Inputs */
    SIU.PCR[0].R = 0x0100;    /* BT6 */
    SIU.PCR[1].R = 0x0100;    /* BT5 */
    SIU.PCR[2].R = 0x0100;    /* SW4 */
    SIU.PCR[3].R = 0x0100;    /* SW3 */
    SIU.PCR[4].R = 0x0100;    /* SW2 */
    SIU.PCR[44].R = 0x0100;   /* SW1 */
  
/********************************************************************
 *                     CAN pin configuration                        *
 ********************************************************************/  
    
    SIU.PCR[16].B.PA = 1;
    SIU.PCR[16].B.IBE = 0;
    SIU.PCR[16].B.OBE = 1;
    
    SIU.PCR[17].B.PA = 1;
    SIU.PCR[17].B.IBE = 1;   
    SIU.PCR[17].B.OBE = 0;
}