#include "jdp.h" 

/* is needed when single shot mode is enabled */
void ADC_StartConversion()
{
    /* start ADC0 conversion */
    ADC_0.MCR.B.NSTART = 1;
    /* wait until conversion is completed */
    while(ADC_0.MSR.B.NSTART);
}

/* initialize ADC */
void ADCInit()
{
    /* disable Power Down Mode */
    ADC_0.MCR.B.PWDN = 0;
    /* Scan Mode */
    ADC_0.MCR.B.MODE = 1;
    /* Overwrite Enable */
    ADC_0.MCR.B.OWREN = 1;
    /* Channel 4 (Potentiometer) */
    ADC_0.NCMR[0].B.CH4 = 1;
    /* Channel 2 (ANA IN1) */
    ADC_0.NCMR[0].B.CH2 = 1;
    /* Channel 5 (Temperature) */
    ADC_0.NCMR[0].B.CH5 = 1;
    /* start conversion */
    ADC_0.MCR.B.NSTART = 1;
}