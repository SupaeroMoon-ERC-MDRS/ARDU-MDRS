
// inspired by example
// this only reads the sensor and prints the value
// TODO send value to Raspi
// TODO test with hardware

#include "../ACS712/ACS712.h"

ACS712 ACS(A0, 5.0, 1023, 100);

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  while (!Serial)
    ;
  Serial.println(__FILE__);
  Serial.print("ACS712_LIB_VERSION: ");
  Serial.println(ACS712_LIB_VERSION);

  ACS.autoMidPoint();
  //  Serial.println(ACS.getMidPoint());
}

void loop()
{
  // put your main code here, to run repeatedly:
  int mA = ACS.mA_DC();
  Serial.println(mA);
  delay(100);
}
