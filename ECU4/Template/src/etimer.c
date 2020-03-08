#include "jdp.h" 

void eTimerInit()
{
    // start value
    ETIMER_0.CHANNEL[0].LOAD.R = 0;
    // end value
    //ETIMER_0.CHANNEL[0].CNTR.R = 16000000;
    ETIMER_0.CHANNEL[0].COMP1.R = 0xFFFF;
    ETIMER_0.CHANNEL[0].COMP2.R = 0xFFFF;

    // count rising edges
    ETIMER_0.CHANNEL[0].CTRL.B.CNTMODE = 1;
    // source: IPBus Prescaler 1
    ETIMER_0.CHANNEL[0].CTRL.B.PRISRC = 0b11000;
    // count repeatedly
    ETIMER_0.CHANNEL[0].CTRL.B.ONCE = 0;
    // use compare registers
    ETIMER_0.CHANNEL[0].CTRL.B.LENGTH = 1;
    // count up
    ETIMER_0.CHANNEL[0].CTRL.B.DIR = 0;
    ETIMER_0.CHANNEL[0].CTRL.B.SECSRC = 0b11000;

    // output enable
    ETIMER_0.CHANNEL[0].CTRL2.B.OEN = 1;
    //
    ETIMER_0.CHANNEL[0].CTRL2.B.OUTMODE = 0b0;
    
    // reload counter on capture 1 event
    ETIMER_0.CHANNEL[0].CTRL3.B.ROC = 0b01;
    
    // interrupt enable
    ETIMER_0.CHANNEL[0].INTDMA.B.TOFIE = 1;
    ETIMER_0.CHANNEL[0].INTDMA.B.TCF2IE = 1;
    ETIMER_0.CHANNEL[0].INTDMA.B.TCF1IE = 1;
    ETIMER_0.CHANNEL[0].INTDMA.B.TCFIE = 1;    
}