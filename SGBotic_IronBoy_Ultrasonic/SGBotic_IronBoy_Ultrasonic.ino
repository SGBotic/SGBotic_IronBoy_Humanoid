#include <IronBoyController.h>
#include "IronBoyMotion.h"
#include <NewPing.h>

IronBoyController IronBoyControl(ROBOT_CONTROLLER_COM_PORT_UART);
/**
   If your Arduino shield needs to us "Serial1",
   communication with IronBoy controller can be switched to "SoftwareSerial" using I/O port.

   To do so, we connnect the controller via D8, D9 by changing SW2 in the IRduino to D-I/O.
   Then declare it with the following code.

   IronBoyController IronBoyControl(ROBOT_CONTROLLER_COM_PORT_IO);
*/

//Ultrasonic sensor
#define TRIGGER_PIN  12  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     11  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

int sensorValue = 0;
int sensorValueRef = 0;

long randNumber;

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
void setup()
{

  Serial.begin(9600); // Open serial monitor at 115200 baud to see ping results.
  randomSeed(analogRead(1));
  IronBoyControl.begin();

  //Caution
  delay(4000); //time to take the initial position
  // IronBoyControl.Piezo.playSound(PIEZO_OCTAVE,  PIEZO_SYLLABLE_DO,  PIEZO_BEAT);
  // delay(1000);

}

void loop() // run over and over
{
  // put your main code here, to run repeatedly:
  IBC_Motion_Status_t m_status;
  m_status = IronBoyControl.Motion.Play(MOTION_STAND);
  delay(3000);
  m_status = IronBoyControl.Motion.Play(MOTION_WALKFORWARD);
  //  delay(5000);
  sensorValue = 0;
  for (int i = 0; i < 32; i++)
  {
    sensorValue += sonar.ping_cm();
    delay(1);
  }
  sensorValue = sensorValue >> 5;
  Serial.print("Sensor value: ");
  Serial.println(sensorValue);

  if (sensorValue < 30)
  {
    randNumber = random(100);
    if (randNumber < 50)
    {
      m_status = IronBoyControl.Motion.Play(MOTION_TURN_LEFT);
      delay(1000);
    } else
    {
      m_status = IronBoyControl.Motion.Play(MOTION_TURN_RIGHT);
      delay(1000);
    }
  }
}

