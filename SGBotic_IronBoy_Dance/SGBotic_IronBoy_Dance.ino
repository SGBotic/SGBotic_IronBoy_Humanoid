#include <IronBoyController.h>
#include "IronBoyMotion.h"


IronBoyController IronBoyControl(ROBOT_CONTROLLER_COM_PORT_UART);
/**
   If your Arduino shield needs to us "Serial1",
   communication with IronBoy controller can be switched to "SoftwareSerial" using I/O port.

   To do so, we connnect the controller via D8, D9 by changing SW2 in the IRduino to D-I/O.
   Then declare it with the following code.

   IronBoyController IronBoyControl(ROBOT_CONTROLLER_COM_PORT_IO);
*/

void setup()
{

  Serial.begin(9600); // Open serial monitor at 115200 baud to see ping results.
  IronBoyControl.begin();

  delay(4000); //time to take the initial position

}

void loop() // run over and over
{

  // put your main code here, to run repeatedly:
  IBC_Motion_Status_t m_status;

  m_status = IronBoyControl.Motion.Play(MOTION_STAND);
  delay(2000);

  m_status = IronBoyControl.Motion.Play(MOTION_DANCE_KPOP_1);
 delay(3000);
 m_status = IronBoyControl.Motion.Play(MOTION_DANCE_KPOP_2);
 delay(3000);
  m_status = IronBoyControl.Motion.Play(MOTION_DANCE_KPOP_3);
 delay(3000);
  m_status = IronBoyControl.Motion.Play(MOTION_DANCE_KPOP_4);
 delay(3000);
  m_status = IronBoyControl.Motion.Play(MOTION_DANCE_KPOP_5);
 delay(3000);
   m_status = IronBoyControl.Motion.Play(MOTION_DANCE_KPOP_6);
 delay(3000);
   m_status = IronBoyControl.Motion.Play(MOTION_DANCE_KPOP_7);
 delay(3000);
   m_status = IronBoyControl.Motion.Play(MOTION_DANCE_KPOP_8);
 delay(3000);
   m_status = IronBoyControl.Motion.Play(MOTION_DANCE_KPOP_9);
 delay(2000);
//  while(1); //forever loop

}



