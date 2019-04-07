#include "BNO.hpp"

void getBNO(Adafruit_BNO055 &bno, BNOData d) {
  
  // Possible vector values can be:
  // - VECTOR_ACCELEROMETER - m/s^2
  // - VECTOR_MAGNETOMETER  - uT
  // - VECTOR_GYROSCOPE     - rad/s
  // - VECTOR_EULER         - degrees
  // - VECTOR_LINEARACCEL   - m/s^2
  // - VECTOR_GRAVITY       - m/s^2
  d.time = millis();
  d.quat = bno.getQuat();
  d.acc = bno.getVector(Adafruit_BNO055::VECTOR_ACCELEROMETER);
  d.gyr = bno.getVector(Adafruit_BNO055::VECTOR_GYROSCOPE);
  d.mag = bno.getVector(Adafruit_BNO055::VECTOR_MAGNETOMETER);
}
