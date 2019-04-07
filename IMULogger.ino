
#include "BNO.hpp"
#include "sentral.hpp"
#include "filestructures.hpp"

#include <Adafruit_BNO055.h>
#include "EM7180_Master.h"

Adafruit_BNO055 bno = Adafruit_BNO055();


static const uint8_t  MAG_RATE       = 100;  // Hz
static const uint16_t ACCEL_RATE     = 1000;  // Hz
static const uint16_t GYRO_RATE      = 1000;  // Hz
static const uint8_t  BARO_RATE      = 50;   // Hz
static const uint8_t  Q_RATE_DIVISOR = 3;    // 1/3 gyro rate
EM7180_Master em7180 = EM7180_Master(MAG_RATE, ACCEL_RATE, GYRO_RATE, BARO_RATE, Q_RATE_DIVISOR);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Running");
  Wire.begin();
  Serial.println("wire begin");
  //if (!em7180.begin()) Serial.println(em7180.getErrorString());
  Serial.println("completed one setup");
  if (!bno.begin()) Serial.println("BNO055 init error");
  Serial.println("completed setup");

}

void loop() {
  BNOData d;
  getBNO(bno, d);
  //printBNO(d);
  getSentral(em7180);
}
