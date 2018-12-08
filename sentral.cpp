#include "sentral.hpp"
#include "EM7180_Master.h"
#include "filestructures.hpp"

SentralManager::SentralManager() {
  
}
void getSentral(EM7180_Master &em7180) {
  em7180.checkEventStatus();
  if (em7180.gotError()) {
    Serial.print("ERROR: ");
    Serial.println(em7180.getErrorString());
    return;
  }
  float qw, qx, qy, qz;

  em7180.readQuaternion(qw, qx, qy, qz);

  float roll  = atan2(2.0f * (qw * qx + qy * qz), qw * qw - qx * qx - qy * qy + qz * qz);
  float pitch = -asin(2.0f * (qx * qz - qw * qy));
  float yaw   = atan2(2.0f * (qx * qy + qw * qz), qw * qw + qx * qx - qy * qy - qz * qz);

  pitch *= 180.0f / PI;
  yaw   *= 180.0f / PI;
  yaw   += 13.8f; // Declination at Danville, California is 13 degrees 48 minutes and 47 seconds on 2014-04-04
  if (yaw < 0) yaw   += 360.0f ; // Ensure yaw stays between 0 and 360
  roll  *= 180.0f / PI;

  Serial.print("Quaternion Roll, Pitch, Yaw: ");
  Serial.print(roll, 2);
  Serial.print(", ");
  Serial.print(pitch, 2);
  Serial.print(", ");
  Serial.print(yaw, 2);


  if (em7180.gotAccelerometer()) {
    float ax, ay, az;
    em7180.readAccelerometer(ax, ay, az);
  }

  if (em7180.gotGyrometer()) {
    float gx, gy, gz;
    em7180.readGyrometer(gx, gy, gz);
  }

  if (em7180.gotMagnetometer()) {

    float mx, my, mz;
    em7180.readMagnetometer(mx, my, mz);
  }


  if (em7180.gotBarometer())
  {
    float temperature, pressure;
    // pressure = mbar, temperature = C
    em7180.readBarometer(pressure, temperature);
  }

}

