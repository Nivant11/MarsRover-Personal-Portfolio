#ifndef HARDWARE_PROFILE_H
#define HARDWARE_PROFILE_H

#ifndef _SUPPRESS_PLIB_WARNING
#define _SUPPRESS_PLIB_WARNING
#endif
#ifndef _DISABLE_OPENADC10_CONFIGPORT_WARNING
#define _DISABLE_OPENADC10_CONFIGPORT_WARNING
#endif
#ifndef _DISABLE_OPENADC10_CONFIGSCAN_WARNING
#define _DISABLE_OPENADC10_CONFIGSCAN_WARNING
#endif

#include <plib.h>

#define getSystemClock() 40000000
#define getPeripheralClock() (getSystemClock())

#define debugLED_init()            \
  mPORTBSetPinsDigitalOut(BIT_12); \
  mPORTBClearBits(BIT_12)
#define debugLED_toggle() mPORTBToggleBits(BIT_12)

// Defines for Power Switches
#define POWER_SW_init()                                           \
  mPORTBSetPinsDigitalOut(BIT_2 | BIT_6 | BIT_7 | BIT_5 | BIT_4 | BIT_3);                 \
  mPORTBClearBits(BIT_2 | BIT_6 | BIT_7 | BIT_5 | BIT_4 | BIT_3);                         \
  mPORTCSetPinsDigitalOut(BIT_14);                                \
  mPORTCClearBits(BIT_14);                                        \
  mPORTDSetPinsDigitalOut(BIT_0 | BIT_4 | BIT_5 | BIT_6 | BIT_7); \
  mPORTDClearBits(BIT_0 | BIT_4 | BIT_5 | BIT_6 | BIT_7);         \
  mPORTESetPinsDigitalOut(BIT_1 | BIT_3);                         \
  mPORTEClearBits(BIT_1 | BIT_3);                                 \
  mPORTFSetPinsDigitalOut(BIT_1 | BIT_0);                                 \
  mPORTFClearBits(BIT_1 | BIT_0);\
  mPORTGSetPinsDigitalOut(BIT_8 | BIT_9); \
  mPORTGClearBits(BIT_8 | BIT_9)
//NOTE: The high side functionality is opposite of the low side functionality because the
// gatedriver has inverted outputs
//RB4
#define HOUT6_off() mPORTBSetBits(BIT_4)
#define HOUT6_on() mPORTBClearBits(BIT_4)
#define HOUT6_read() mPORTBReadBits(BIT_4)


//RE1
#define HOUT4_off() mPORTESetBits(BIT_1)
#define HOUT4_on() mPORTEClearBits(BIT_1)
#define HOUT4_read() mPORTEReadBits(BIT_1)

//RG9
#define HOUT5_off() mPORTGSetBits(BIT_9)
#define HOUT5_on() mPORTGClearBits(BIT_9)
#define HOUT5_read() mPORTGReadBits(BIT_9)

//RB3
#define HOUT3_off() mPORTBSetBits(BIT_3)
#define HOUT3_on() mPORTBClearBits(BIT_3)
#define HOUT3_read() mPORTBReadBits(BIT_3)

//RD0
#define HOUT1_off() mPORTDSetBits(BIT_0) 
#define HOUT1_on() mPORTDClearBits(BIT_0)
#define HOUT1_read() mPORTDReadBits(BIT_0)

//RC14
#define HOUT2_off() mPORTCSetBits(BIT_14)
#define HOUT2_on() mPORTCClearBits(BIT_14)
#define HOUT2_read() mPORTCReadBits(BIT_14)

//RE3
#define LOUT5_on() mPORTESetBits(BIT_3)
#define LOUT5_off() mPORTEClearBits(BIT_3)
#define LOUT5_read() mPORTEReadBits(BIT_3)

//RF0
#define LOUT4_on() mPORTFSetBits(BIT_0)
#define LOUT4_off() mPORTFClearBits(BIT_0)
#define LOUT4_read() mPORTFReadBits(BIT_0)

//RG8
#define LOUT6_on() mPORTGSetBits(BIT_8)
#define LOUT6_off() mPORTGClearBits(BIT_8)
#define LOUT6_read() mPORTGReadBits(BIT_8)

//RB5
#define LOUT7_on() mPORTBSetBits(BIT_5)
#define LOUT7_off() mPORTBClearBits(BIT_5)
#define LOUT7_read() mPORTBReadBits(BIT_5)

//RD4
#define LOUT2_on() mPORTDSetBits(BIT_4)
#define LOUT2_off() mPORTDClearBits(BIT_4)
#define LOUT2_read() mPORTDReadBits(BIT_4)

//RD5
#define LOUT3_on() mPORTDSetBits(BIT_5)
#define LOUT3_off() mPORTDClearBits(BIT_5)
#define LOUT3_read() mPORTDReadBits(BIT_5)

//RC13
#define LOUT1_on() mPORTCSetBits(BIT_13)
#define LOUT1_off() mPORTCClearBits(BIT_13)
#define LOUT1_read() mPORTCReadBits(BIT_13)

#endif