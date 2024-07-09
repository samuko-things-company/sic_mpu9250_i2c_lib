/*
 * Basic example code shows how to read orientation data from the sic_mpu9250 driver shield module
 * which have been succesfully calibrated with filter and covariances setup
 *
 * The code basically reads roll, pitch, and yaw values from the sic_mpu9250 connected to it.
 * read printed values from serial monitor or serial plotter.
 *
 * you can copy the code and use it in your project as you will.
 */

// Samuko Imu Compute (SIC) i2c communication library
#include <sic_mpu9250_i2c_lib.h>

// please update with the address with that which you set when doing
// calibration and filter setup with the sic_mpu9250_setup_application
uint8_t imuAddress = 104; // i.e 0x68 in HEX
SIC imu(imuAddress);

float toRad = 2 * PI / 360;
float toDeg = 1 / toRad;

float roll, pitch, yaw, gain; // create variables to store orientations

long prevSampleTime;
long sampleTime = 100; // millisec

void setup()
{
  // start i2c communication
  Wire.begin();

  // setup serial communication to print result on serial minitor
  Serial.begin(115200);

  // wait for the imu module to fully setup
  for (int i = 1; i <= 10; i += 1)
  {
    delay(1000);
    Serial.println(i);
  }

  imu.setFilterGain(0.1);
  imu.getFilterGain(gain);
  Serial.println(gain, 3);

  prevSampleTime = millis();
}

void loop()
{

  if ((millis() - prevSampleTime) >= sampleTime)
  {
    /* CODE SHOULD GO IN HERE*/

    imu.getRPY(roll, pitch, yaw); // read roll, pitch, yaw in radians

    // Serial.print(roll, 4);
    // Serial.print(", ");
    // Serial.print(pitch, 4);
    // Serial.print(", ");
    // Serial.println(yaw, 4);

    Serial.print(roll * toDeg, 1);
    Serial.print(", ");
    Serial.print(pitch * toDeg, 1);
    Serial.print(", ");
    Serial.println(yaw * toDeg, 1);

    prevSampleTime = millis();
  }
}