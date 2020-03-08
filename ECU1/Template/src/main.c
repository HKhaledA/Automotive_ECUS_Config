#include "init.h"
/********************************************************************
*                          global variables                         *
********************************************************************/

int second_int = 0;
// initial value 00111111
unsigned char light_states = 63;

int door_control_is_alive = 1;

/********************************************************************
 *                              main                                *
 ********************************************************************/
void main(void)
{
    /* board initialization */
    Init();

    /* turn off leds */
    LED0 = 1;
    LED1 = 1;
    LED2 = 1;
    LED3 = 1;
    LED4 = 1;
    LED5 = 1;
    LED6 = 1;
    LED7 = 1; 

	/* channel 0 and 1 of PIT timer are configured to interrupt every 100ms and 200ms respectively */
	PIT_ConfigureTimer(1, 100);
	PIT_ConfigureTimer(2, 200);
	
	/* start PIT timer for channel 1 and 2 */
	PIT_StartTimer(1);
	PIT_StartTimer(2); 

    /* forever */
    for(;;)
    {
		
    }
}

/********************************************************************
 *                      Interrupt Functions                         *
 ********************************************************************/  

void PITCHANNEL1(void)
{
	/* send (0.1)RPM value */
	CAN_0.BUF[8].DATA.B[0] = ADC_0.CDR[4].B.CDATA;
	CAN_0.BUF[8].DATA.B[1] =  ADC_0.CDR[4].B.CDATA >> 8;		
	CAN_0.BUF[8].CS.B.CODE = 12;
	
    PIT.CH[1].TFLG.B.TIF = 1;
}

void PITCHANNEL2(void)
{
                //Automatic Mode

              light_value = ADC_0.CDR[4].B.CDATA //for the light sensor value//            
                if(SW1 == 0) {
				if(light_value < 512)
					light_states &= 0xf; //00001111
				else 
					light_states |= 48; //00110000
			}
			// send light states message
			CAN_0.BUF[9].DATA.B[0] = light_states;
			CAN_0.BUF[9].CS.B.CODE = 12;

                // send alive message
			CAN_0.BUF[10].CS.B.CODE = 12;
			
			// send error message
			if(door_control_is_alive == 0) {
				CAN_0.BUF[11].CS.B.CODE = 12;
				P = ~P;
			} else {
				door_control_is_alive = 0;
				P = 1;
			}


		
    PIT.CH[2].TFLG.B.TIF = 1;
}

void CANMB0003(void)
{
/* No modifications needed here */
/* Receive interrupts are being cleared here */
    CAN_0.IFRL.B.BUF00I = 1;
    CAN_0.IFRL.B.BUF01I = 1;
    CAN_0.IFRL.B.BUF02I = 1;
    CAN_0.IFRL.B.BUF03I = 1;
}

void CANMB0407(void)
{
	if(CAN_0.IFRL.B.BUF05I) {
		switch(CAN_0.RXFIFO.ID.B.STD_ID) {
			case 0x302:
				light_states = (light_states & 248) | CAN_0.RXFIFO.DATA.B[0];
				LED1 = ~LED1;
				break;
			case 0x403:
				light_states = (light_states & 7) | (CAN_0.RXFIFO.DATA.B[0] << 3);
				LED2 = ~LED2;
				break;
			case 0x304:
				door_control_is_alive = 1;
				LED3 = ~LED3;
				break;
		}
	}  
   
    /* clear flags as last step here! */
    /* don't change anything below! */
    CAN_0.IFRL.B.BUF04I = 1;
    CAN_0.IFRL.B.BUF05I = 1;
    CAN_0.IFRL.B.BUF06I = 1;
    CAN_0.IFRL.B.BUF07I = 1;
}

void CANMB0811(void)
{
/* No modifications needed here */
/* transmit interrupts are being cleared here */

    CAN_0.IFRL.B.BUF08I = 1;
    CAN_0.IFRL.B.BUF09I = 1;
    CAN_0.IFRL.B.BUF10I = 1;
    CAN_0.IFRL.B.BUF11I = 1;
}

void CANMB1215(void)
{
/* No modifications needed here */
/* transmit interrupts are being cleared here */
    CAN_0.IFRL.B.BUF12I = 1;
    CAN_0.IFRL.B.BUF13I = 1;
    CAN_0.IFRL.B.BUF14I = 1;
    CAN_0.IFRL.B.BUF15I = 1;
}



/********************************************************************
 *                   Interrupt Vector Table                         *
 ********************************************************************/
#pragma interrupt Ext_Isr
#pragma section IrqSect RX address=0x040
#pragma use_section IrqSect Ext_Isr

void Ext_Isr() {
    switch(INTC.IACKR.B.INTVEC)
    {
        case 59:
            PITCHANNEL0();
            break;
        case 60:
            PITCHANNEL1();
        case 68:
            CANMB0003();
            break;
        case 69:
            CANMB0407();
            break;
        case 70:
            CANMB0811();
            break;
        case 71:
            CANMB1215();
            break;        
        default:
            break;
    }
    /* End of Interrupt Request */
    INTC.EOIR.R = 0x00000000;
}
