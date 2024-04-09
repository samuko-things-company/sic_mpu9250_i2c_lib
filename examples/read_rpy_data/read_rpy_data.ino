
/*
 * Basic example code on how to control via I2C your geared DC motor with quadrature 
 * encoder which is already connected to the smc_driver shield module and have already
 * succesfully set up their velocity PID control using the smc_app GUI 
 * 
 * The code basically sends a low target velocity (in rad/s), waits for some time and then
 * sends a high target velocity (in rad/s). it also prints out the motors' angular positions
 * (in rad) and angular velocities (in rad/s).
 * 
 * you can copy the code and use it in your project as you will.
 */

// Samuko Imu Compute (SIC) i2c communication library
#include <sic_mpu9250_i2c_lib.h>


uint8_t imuAddress = 0x68;
SIC imu(0x68);

///////// my sepcial delay function ///////////////
void delayMs(int ms) {
  for (int i = 0; i < ms; i += 1) {
    delayMicroseconds(1000);
  }
}
//////////////////////////////////////////////////

float toRad = 2*PI/360;
float toDeg = 1/toRad;

float roll, pitch, yaw;

long prevSampleTime;
long sampleTime = 20; // millisec

void setup()
{
  // start i2c communication
  Wire.begin(); 

  // setup serial communication to print result on serial minitor               
  Serial.begin(115200);

  // wait for the imu module to fully setup
  for (int i=1; i<=10; i+=1){
    delayMs(1000); 
    Serial.println(i);
  }
  
  prevSampleTime = millis();
}


 
void loop()
{  
  
  if ((millis() - prevSampleTime) >= sampleTime) {
    /* CODE SHOULD GO IN HERE*/

    imu.getRPY(roll, pitch, yaw);

    Serial.print(roll*toDeg,1);
    Serial.print(", ");
    Serial.print(pitch*toDeg,1);
    Serial.print(", ");
    Serial.println(yaw*toDeg,1);

    Serial.println();
    
    prevSampleTime = millis();
  }

}
