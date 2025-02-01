
// inspired by example
// this only reads the sensor and prints the value
// TODO send value to Raspi
// TODO test with hardware

#include "../ACS712/ACS712.h"
#include <Wire.h> // for i2c ...

ACS712 ACS(A0, 5.0, 1023, 100);

int mA;

void setup()
{
  // put your setup code here, to run once:
  int i2caddr = 0x01;
  Wire.begin(i2caddr);          // join i2c bus (address optional for master)
  Wire.onRequest(requestEvent); // register event
  // Serial.begin(115200);
  // while (!Serial)
  //  ;
  // Serial.println(__FILE__);
  // Serial.print("ACS712_LIB_VERSION: ");
  // Serial.println(ACS712_LIB_VERSION);

  ACS.autoMidPoint();
  //  Serial.println(ACS.getMidPoint());
}

void loop()
{
  int samplingrate = 100;
  // put your main code here, to run repeatedly:
  mA = ACS.mA_DC();
  // Serial.println(mA);
  delay(samplingrate);
}

// function that executes whenever data is requested by master

// this function is registered as an event, see setup()

void requestEvent()
{

  Wire.write(mA); // respond with message of 6 bytes

  // as expected by master
}
