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


#define DELAY_TIME              5000

#define PIEZO_OCTAVE          3

#define PIEZO_SYLLABLE_DO     0
#define PIEZO_SYLLABLE_DO_S   1
#define PIEZO_SYLLABLE_RE     2
#define PIEZO_SYLLABLE_RE_S   3
#define PIEZO_SYLLABLE_MI     4
#define PIEZO_SYLLABLE_FA     5
#define PIEZO_SYLLABLE_FA_S   6
#define PIEZO_SYLLABLE_SOL    7
#define PIEZO_SYLLABLE_SOL_S  8
#define PIEZO_SYLLABLE_LA     9
#define PIEZO_SYLLABLE_LA_S   10
#define PIEZO_SYLLABLE_SI     11

#define PIEZO_BEAT            10

const int analogInPin = A0;
int sensorValue = 0;
int sensorValueRef = 0;


void setup()
{
  // put your setup code here, to run once:
  delay(500);
  sensorValueRef = analogRead(analogInPin);
  delay(1000);
  IronBoyControl.begin();

  //Caution
  delay(4000); //time to take the initial position
  IronBoyControl.Piezo.playSound(PIEZO_OCTAVE,  PIEZO_SYLLABLE_DO,  PIEZO_BEAT);
  delay(1000);

}

void loop() // run over and over
{
  // put your main code here, to run repeatedly:
  IBC_Motion_Status_t m_status;
  m_status = IronBoyControl.Motion.Play(MOTION_WALKFORWARD);

  sensorValue = analogRead(analogInPin);
  if (sensorValue > (sensorValueRef + 100))
  {
    IronBoyControl.Piezo.playSound(PIEZO_OCTAVE,  PIEZO_SYLLABLE_RE,  PIEZO_BEAT);
    delay(1000);
    m_status = IronBoyControl.Motion.Play(MOTION_STAND);
    delay(2000);

    m_status = IronBoyControl.Motion.Play(MOTION_BOW_DOWN);
    delay(2000);
    do
    {
      sensorValue = analogRead(analogInPin);
    } while (sensorValue > (sensorValueRef + 100));

    m_status = IronBoyControl.Motion.Play(MOTION_STAND);
    delay(2000);
  }
}



