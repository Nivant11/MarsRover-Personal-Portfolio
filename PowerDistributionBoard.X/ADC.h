#ifndef _ADC_H //include guard 
#define _ADC_H

//These defs just suppress warnings
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

//Pre-declaration of all functions used in ADC.c
void ADCSample(void);
int currentReadHOUT1(void);
int currentReadHOUT2(void);
int currentReadHOUT3(void);
int currentReadHOUT4(void);
int currentReadHOUT5(void);
int currentReadHOUT6(void);
int currentReadLOUT1(void);
int currentReadLOUT2(void);
int currentReadLOUT3(void);
int currentReadLOUT4(void);
int currentReadLOUT5(void);
int currentReadLOUT6(void);
int currentReadLOUT7(void);

#endif