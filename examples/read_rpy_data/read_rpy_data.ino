#include <Wire.h>
#include "sic_mpu9250_i2c_lib.h"

// Define Slave I2C Address
const byte IMU_ADDRESS = 104; // 0x68
SIC imu(IMU_ADDRESS);

float toRad = 2 * PI / 360;
float toDeg = 1 / toRad;

void setup()
{

  // Initialize I2C communications as Master
  Wire.begin();

  // Setup serial monitor
  Serial.begin(115200);
  Serial.println("I2C Master Demonstration");

  // wait for the imu module to fully setup
  for (int i = 1; i <= 10; i += 1)
  {
    delay(1000);
    Serial.println(i);
  }

  // // Send filter gain value of 0.1
  // imu.setFilterGain(1.0);

  // read the filter gain
  float madgwickFilterGain;
  imu.getFilterGain(madgwickFilterGain);

  Serial.print("Madgwick Filter Gain: ");
  Serial.println(madgwickFilterGain, 3);

  // read the roll pitch and yaw value.
  float roll_var, pitch_var, yaw_var;
  imu.getRollVariance(roll_var);
  imu.getPitchVariance(pitch_var);
  imu.getYawVariance(yaw_var);

  String msg = "RPY_variance: [" + String(roll_var, 10) + "," + String(pitch_var, 10) + "," + String(yaw_var, 10) + "]";
  Serial.println(msg);
  Serial.println();

  delay(3000);
}

void loop()
{

  delay(50);
  // read the roll pitch and yaw value in (rad/s).
  float roll, pitch, yaw;
  imu.getRPY(roll, pitch, yaw);

  String msg = "RPY (rad/s): [" + String(roll, 4) + "," + String(pitch, 4) + "," + String(yaw, 4) + "]";
  Serial.println(msg);

  // Serial.print(roll * toDeg);
  // Serial.print(", ");
  // Serial.print(pitch * toDeg);
  // Serial.print(", ");
  // Serial.println(yaw * toDeg);
}