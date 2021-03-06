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
  // put your setup code here, to run once:
  IronBoyControl.begin();

  //Caution
  delay(4000); //time to take the initial position
}

void loop() // run over and over
{
  // put your main code here, to run repeatedly:
  IBC_Motion_Status_t m_status;
  m_status = IronBoyControl.Motion.Play(MOTION_STAND);

  while(1); //forever loop
}

