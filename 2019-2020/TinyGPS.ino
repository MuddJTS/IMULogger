#include <TinyGPS.h>

#define gpsSerial Serial1

static const uint32_t GPSBaud = 9600;

long lat, lon;
long gpsReading;

TinyGPS gps; //Create gps object

void initGPS() {
  Serial.begin(115200); // Connect serial
  gpsSerial.begin(GPSBaud); 
}

/*void getGPSPosition() {
  while(gpsSerial.available()) { // Check for gps data
    gpsReading = gpsSerial.read();

    if (gps.encode(gpsReading)) { //Encode gps data
      gps.get_position(&lat, &lon); // get latitude, longitude, and altitude
      
      //display position
      Serial.print("Position: ");

      //print latitude
      Serial.print("lat: ");
      Serial.print(lat / 100000.0);
      Serial.print(" ");

      //print longitude
      Serial.print("long: ");
      Serial.println(lon / 100000.0); 

      //print altitude
      Serial.print("alt: ");
      Serial.println(gps.f_altitude());
    }
  }
}*/
