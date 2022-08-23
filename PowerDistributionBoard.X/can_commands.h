#ifndef CAN_COMMANDS_H
#define CAN_COMMANDS_H

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
#include <stdint.h>

void (*CMD_CCB[256])(CANRxMessageBuffer* message);

#endif