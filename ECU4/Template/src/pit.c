#include "jdp.h" 

/* configures timer "timerChannel" and sets it to period of "loadValue" ms */
void PIT_ConfigureTimer(int timerChannel, unsigned int loadValue)
{
  /* Set load value */
  PIT.CH[timerChannel].LDVAL.B.TSV = loadValue*16000;
}

void PIT_StartTimer(int timerChannel)
{
  /* Enable timer */
  PIT.CH[timerChannel].TCTRL.B.TEN = 1; 
}

void PIT_StopTimer(int timerChannel)
{
  /* Disable timer */
  PIT.CH[timerChannel].TCTRL.B.TEN = 0;
}

void PIT_ChannelInit(int timerChannel)
{
  /* Load value */
  PIT.CH[timerChannel].LDVAL.B.TSV = 0;
  /* Reset timer interrupt flag */
  PIT.CH[timerChannel].TFLG.B.TIF = 1;
  /* Enable timer interrupts */
  PIT.CH[timerChannel].TCTRL.B.TIE = 1;
  /* Enable timer */
  PIT.CH[timerChannel].TCTRL.B.TEN = 0;  
}

void PIT_Init(void)
{
  /* Switch on PIT module */
  PIT.PITMCR.B.MDIS = 0;
  /* Run timer for debug mode */
  PIT.PITMCR.B.FRZ = 0;
  /* Initialize timer 0 */ 
  PIT_ChannelInit(0);
  /* Initialize timer 1 */
  PIT_ChannelInit(1);
}