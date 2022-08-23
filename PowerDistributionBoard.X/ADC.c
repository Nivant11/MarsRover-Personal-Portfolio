#include "../Global/canlib.h"
#include "hardware_profile.h"
#include <plib.h>
#include "ADC.h"

/*
 * Current Sensing:
 * Enable the ADC
 * Load the correct pin number into the AD1CHS register (bits 21-16)
 *      - The correct pin is that pin which is connected to the port
 *
 * Start and finish ADC sample with ADCSample()
 * Close the ADC
 * Return the contents of ADC1BUF0 (which has the voltage) divided by the resistor
 *
 */
int currentReadHOUT1() {
    EnableADC10();
    AD1CHS |= 0xF0000; //AN15
    ADCSample();
    CloseADC10();
    return ADC1BUF0 / 10000;
}

int currentReadHOUT2() {
    EnableADC10();
    AD1CHS |= 0x180000; //AN24
    ADCSample();
    CloseADC10();
    return ADC1BUF0 / 10000;
}

int currentReadHOUT3() {
    EnableADC10();
    AD1CHS |= 0x1B0000; //AN27
    ADCSample();
    CloseADC10();
    return ADC1BUF0 / 10000;
}

int currentReadHOUT4() {
    EnableADC10();
    AD1CHS |= 0x170000; //AN23
    ADCSample();
    CloseADC10();
    return ADC1BUF0 / 10000;
}

int currentReadHOUT5() {
    EnableADC10();
    AD1CHS |= 0x100000; //AN16
    ADCSample();
    CloseADC10();
    return ADC1BUF0 / 10000;
}

//HOUT6 is not connected to the gate-driver in the schematic, need a jumper wire on the board
int currentReadHOUT6() {
    EnableADC10();
    AD1CHS |= 0xB0000; //AN11
    ADCSample();
    CloseADC10();
    return ADC1BUF0 / 10000;
}

int currentReadLOUT1() {
    EnableADC10();
    AD1CHS |= 0xD0000; //AN13
    ADCSample();
    CloseADC10();
    return ADC1BUF0 / 10000;
}

int currentReadLOUT2() {
    EnableADC10();
    AD1CHS |= 0x190000; //AN25
    ADCSample();
    CloseADC10();
    return ADC1BUF0 / 10000;
}

int currentReadLOUT3() {
    EnableADC10();
    AD1CHS |= 0x1A0000; //AN26
    ADCSample();
    CloseADC10();
    return ADC1BUF0 / 10000;
}

int currentReadLOUT4() {
    EnableADC10();
    AD1CHS |= 0x140000; //AN20
    ADCSample();
    CloseADC10();
    return ADC1BUF0 / 10000;
}

int currentReadLOUT5() {
    EnableADC10();
    AD1CHS |= 0x150000; //AN21
    ADCSample();
    CloseADC10();
    return ADC1BUF0 / 10000;
}

int currentReadLOUT6() {
    EnableADC10();
    AD1CHS |= 0x110000; //AN17
    ADCSample();
    CloseADC10();
    return ADC1BUF0 / 10000;
}

int currentReadLOUT7() {
    EnableADC10();
    AD1CHS |= 0x70000; //AN7
    ADCSample();
    CloseADC10();
    return ADC1BUF0 / 10000;
}

void ADCSample() {
    AD1CHS &= ~(1UL << 23); //Clear 23rd bit
    AD1CON1bits.SAMP = 1;           // Begin sampling
    while (AD1CON1bits.SAMP);      // wait until acquisition is done
    while (!AD1CON1bits.DONE);    // wait until conversion done
}