#include "jdp.h" 

void MEInit(void)
{
    // Peripherie im RUN0 Mode komplett aktivieren
    ME.RUNPC[0].R = 0xFE;
    // im Low Power Mode alles aktivieren
    ME.LPPC[0].B.STOP0 = 1;
    ME.LPPC[0].B.HALT0 = 1;
    // ADC0 aktivieren
    ME.PCTL[32].R = 0;
    // PIT aktivieren
    ME.PCTL[92].R = 0;
    // CAN aktivieren
    ME.PCTL[16].R = 0;
    // activate eTimer 0
    ME.PCTL[38].R = 0;
    
    // auf PLL warten
    while(ME.GS.R & (1 << 6));

    // in RUN0 Mode wechseln
    ME.MCTL.R = 0x40005AF0;
    ME.MCTL.R = 0x4000A50F;       
}