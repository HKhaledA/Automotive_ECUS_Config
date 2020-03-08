#include "jdp.h" 

void InterruptInit()
{
    /* vector table entry size = 8 bytes (1) 4 bytes (0) */
    INTC.MCR.B.VTES = 0;
    /* software vector mode enable */
    INTC.MCR.B.HVEN = 0;
    /* vector table base adress */
    INTC.IACKR.B.VTBA = 0x12000;
    /* interrupt priority register PIT */
    INTC.PSR[59].B.PRI = 0x5;
    /* interrupt priority register PIT */
    INTC.PSR[60].B.PRI = 0x5;
    // interrupt priority register CAN MB 0-3
    INTC.PSR[68].B.PRI = 0x1;
    // interrupt priority register CAN MB 4-7
    INTC.PSR[69].B.PRI = 0x1;
    // interrupt priority register CAN MB 8-11 
    INTC.PSR[70].B.PRI = 0x1;
    // interrupt priority register CAN MB 12-15 
    INTC.PSR[71].B.PRI = 0x1;
}
