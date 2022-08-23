#include "../Global/canlib.h"
#include "can_commands.h"
#include "config.h"
#include "hardware_profile.h"

void main(void) {
  DisableWDT();
  SYSTEMConfigPerformance(getSystemClock());
  debugLED_init();
  POWER_SW_init();

  HOUT1_on();
  HOUT2_on();
  HOUT3_on();
  HOUT4_on();
  HOUT5_on();
  HOUT6_on();
  LOUT1_on();
  LOUT2_on();
  LOUT3_on();
  LOUT4_on();
  LOUT5_on();
  LOUT6_on();
  LOUT7_on();

  canlib_config(RPD11, RPD10, 0x404, getPeripheralClock());

  INTEnableSystemMultiVectoredInt();
  WDTCONbits.WDTCLR = 1;
  EnableWDT();
  int x;
  while (1) {
    WDTCONbits.WDTCLR = 1;
    debugLED_toggle();
    for (x = 0; x < 300000; x++) WDTCONbits.WDTCLR = 1;
  }
}

void rxHandler(canlib_message_t* message) {
  //if (message->msgEID.DLC >= 2) (*CMD_CCB[message->data[1]])(message);
}

void rxHandler2(canlib_message_t* message) { return; }

void rxHandlerAllCall(canlib_message_t* message) { rxHandler(message); }