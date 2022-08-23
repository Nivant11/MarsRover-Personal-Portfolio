#include "can_commands.h"
#include "../Global/canlib.h"
#include "hardware_profile.h"
#include "ADC.h"

/**
 * A blank prototype that is used for commands that are invalid or not assigned
 * @param message the CAN message
 */
void blankCMD(CANRxMessageBuffer* message) { return; }

void pwrSwitchCMD(CANRxMessageBuffer* message) {
  if (message->data[0] == 'W' && message->msgEID.DLC == 4) {
    if (message->data[2] & 0x01)
      HOUT1_on();
    else
      HOUT1_off();
    if (message->data[2] & 0x02)
      HOUT2_on();
    else
      HOUT2_off();
    if (message->data[2] & 0x04)
      HOUT3_on();
    else
      HOUT3_off();
    if (message->data[2] & 0x08)
      HOUT4_on();
    else
      HOUT4_off();
    if (message->data[2] & 0x10)
      HOUT5_on();
    else
      HOUT5_off();

    if (message->data[3] & 0x01)
      LOUT1_on();
    else
      LOUT1_off();
    if (message->data[3] & 0x02)
      LOUT2_on();
    else
      LOUT2_off();
    if (message->data[3] & 0x04)
      LOUT3_on();
    else
      LOUT3_off();
    if (message->data[3] & 0x08)
      LOUT4_on();
    else
      LOUT4_off();
    if (message->data[3] & 0x10)
      LOUT5_on();
    else
      LOUT5_off();
    if (message->data[3] & 0x20)
      LOUT6_on();
    else
      LOUT6_off();
    if (message->data[3] & 0x40)
      LOUT7_on();
    else
      LOUT7_off();
  } else if (message->data[0] == 'R' && message->msgEID.DLC == 3) {
    uint8_t buffer[4] = {'Q', 0x10, 0x00, 0x00};
    if (HOUT1_read()) buffer[2] |= 0x01;
    if (HOUT2_read()) buffer[2] |= 0x02;
    if (HOUT3_read()) buffer[2] |= 0x04;
    if (HOUT4_read()) buffer[2] |= 0x08;
    if (HOUT5_read()) buffer[2] |= 0x10;

    if (LOUT1_read()) buffer[3] |= 0x01;
    if (LOUT2_read()) buffer[3] |= 0x02;
    if (LOUT3_read()) buffer[3] |= 0x04;
    if (LOUT4_read()) buffer[3] |= 0x08;
    if (LOUT5_read()) buffer[3] |= 0x10;
    if (LOUT6_read()) buffer[3] |= 0x20;
    if (LOUT7_read()) buffer[3] |= 0x40;
    canlib_debugMessage(0x400 | message->data[2], buffer, 4);
  }
}


void currentSenseCMD(CANRxMessageBuffer* message){
    if(message->data[0] == 'R' && message->msgEID.DLC == 4){
        
        /*The buffer to be transmitted:
         * buffer[0] - the type of message (query)
         * buffer[1] - the address (right next to the pwrSwitchCMD, at 0x11)
         * buffer[2] - current from a high port
         * buffer[3] - current from a low port
         */
        uint8_t buffer[4] = {'Q', 0x11, 0x00, 0x00};
        
        //Setting the buffer according to which port's current is desired
        if (message->data[2] & 0x01) buffer[2] |= currentReadHOUT1(); //Reading HOUT1
        if (message->data[2] & 0x02) buffer[2] |= currentReadHOUT2(); //Reading HOUT2
        if (message->data[2] & 0x04) buffer[2] |= currentReadHOUT3(); //Reading HOUT3
        if (message->data[2] & 0x08) buffer[2] |= currentReadHOUT4(); //Reading HOUT4
        if (message->data[2] & 0x10) buffer[2] |= currentReadHOUT5(); //Reading HOUT5
        if (message->data[2] & 0x20) buffer[2] |= currentReadHOUT6(); //Reading HOUT6
        
        if (message->data[3] & 0x01) buffer[3] |= currentReadLOUT1(); //Reading LOUT1
        if (message->data[3] & 0x02) buffer[3] |= currentReadLOUT2(); //Reading LOUT2
        if (message->data[3] & 0x04) buffer[3] |= currentReadLOUT3(); //Reading LOUT3
        if (message->data[3] & 0x08) buffer[3] |= currentReadLOUT4(); //Reading LOUT4
        if (message->data[3] & 0x10) buffer[3] |= currentReadLOUT5(); //Reading LOUT5
        if (message->data[3] & 0x20) buffer[3] |= currentReadLOUT6(); //Reading LOUT6
        if (message->data[3] & 0x40) buffer[3] |= currentReadLOUT7(); //Reading LOUT7
        
        canlib_debugMessage(0x400 | message->data[2], buffer, 4);
        
    }
    
}

// clang-format off
void (*CMD_CCB[256])(CANRxMessageBuffer* message) = {
    blankCMD,  blankCMD,  blankCMD,  blankCMD,
    blankCMD,  blankCMD,  blankCMD,  blankCMD,  // 0-7
    blankCMD,  blankCMD,  blankCMD,  blankCMD,
    blankCMD,  blankCMD,  blankCMD,  blankCMD,
    pwrSwitchCMD,  currentSenseCMD,  blankCMD,  blankCMD,
    blankCMD,  blankCMD,  blankCMD,  blankCMD,  // 0x10-0x17
    blankCMD,  blankCMD,  blankCMD,  blankCMD,
    blankCMD,  blankCMD,  blankCMD,  blankCMD,
    blankCMD,  blankCMD,  blankCMD,  blankCMD,
    blankCMD,  blankCMD,  blankCMD,  blankCMD,  // 0x20-0x27
    blankCMD,  blankCMD,  blankCMD,  blankCMD,
    blankCMD,  blankCMD,  blankCMD,  blankCMD,
    blankCMD,  blankCMD,  blankCMD,  blankCMD,
    blankCMD,  blankCMD,  blankCMD,  blankCMD,  // 0x30-0x37
    blankCMD,  blankCMD,  blankCMD,  blankCMD,
    blankCMD,  blankCMD,  blankCMD,  blankCMD,
    blankCMD,  blankCMD,  blankCMD,  blankCMD,
    blankCMD,  blankCMD,  blankCMD,  blankCMD,  // 0x40-0x47
    blankCMD,  blankCMD,  blankCMD,  blankCMD,
    blankCMD,  blankCMD,  blankCMD,  blankCMD,
    blankCMD,  blankCMD,  blankCMD,  blankCMD,
    blankCMD,  blankCMD,  blankCMD,  blankCMD,  // 0x50-0x57
    blankCMD,  blankCMD,  blankCMD,  blankCMD,
    blankCMD,  blankCMD,  blankCMD,  blankCMD,
    blankCMD,  blankCMD,  blankCMD,  blankCMD,
    blankCMD,  blankCMD,  blankCMD,  blankCMD,  // 0x60-0x67
    blankCMD,  blankCMD,  blankCMD,  blankCMD,
    blankCMD,  blankCMD,  blankCMD,  blankCMD,
    blankCMD,  blankCMD,  blankCMD,  blankCMD,
    blankCMD,  blankCMD,  blankCMD,  blankCMD,  // 0x70-0x77
    blankCMD,  blankCMD,  blankCMD,  blankCMD,
    blankCMD,  blankCMD,  blankCMD,  blankCMD,
    blankCMD,  blankCMD,  blankCMD,  blankCMD,
    blankCMD,  blankCMD,  blankCMD,  blankCMD,  // 0x80-0x87
    blankCMD,  blankCMD,  blankCMD,  blankCMD,
    blankCMD,  blankCMD,  blankCMD,  blankCMD,
    blankCMD,  blankCMD,  blankCMD,  blankCMD,
    blankCMD,  blankCMD,  blankCMD,  blankCMD,  /// 0x90-0x97
    blankCMD,  blankCMD,  blankCMD,  blankCMD,
    blankCMD,  blankCMD,  blankCMD,  blankCMD,
    blankCMD,  blankCMD,  blankCMD,  blankCMD,
    blankCMD,  blankCMD,  blankCMD,  blankCMD,  // 0xA0-0xA7
    blankCMD,  blankCMD,  blankCMD,  blankCMD,
    blankCMD,  blankCMD,  blankCMD,  blankCMD,
    blankCMD,  blankCMD,  blankCMD,  blankCMD,
    blankCMD,  blankCMD,  blankCMD,  blankCMD,  // 0xB0-0xB7
    blankCMD,  blankCMD,  blankCMD,  blankCMD,
    blankCMD,  blankCMD,  blankCMD,  blankCMD,
    blankCMD,  blankCMD,  blankCMD,  blankCMD,
    blankCMD,  blankCMD,  blankCMD,  blankCMD,  // 0xC0-0xC7
    blankCMD,  blankCMD,  blankCMD,  blankCMD,
    blankCMD,  blankCMD,  blankCMD,  blankCMD,
    blankCMD,  blankCMD,  blankCMD,  blankCMD,
    blankCMD,  blankCMD,  blankCMD,  blankCMD,  // 0xD0-0xD7
    blankCMD,  blankCMD,  blankCMD,  blankCMD,
    blankCMD,  blankCMD,  blankCMD,  blankCMD,
    blankCMD,  blankCMD,  blankCMD,  blankCMD,
    blankCMD,  blankCMD,  blankCMD,  blankCMD,  // 0xE0-0xE7
    blankCMD,  blankCMD,  blankCMD,  blankCMD,
    blankCMD,  blankCMD,  blankCMD,  blankCMD,
    blankCMD,  blankCMD,  blankCMD,  blankCMD,
    blankCMD,  blankCMD,  blankCMD,  blankCMD,  // 0xF0-0xF7
    blankCMD,  blankCMD,  blankCMD,  blankCMD,
    blankCMD,  blankCMD,  blankCMD,  blankCMD
};
// clang-format on