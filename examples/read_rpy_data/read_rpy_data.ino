
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


uint8_t imuAddress = 0x68;
SIC imu(0x68); // please update with the address you set when doing calibration and filter setup with the sic_mpu9250_setup_application

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

    Serial.print(roll);
    Serial.print(", ");
    Serial.print(pitch);
    Serial.print(", ");
    Serial.println(yaw);

    // Serial.print(roll*toDeg,1);
    // Serial.print(", ");
    // Serial.print(pitch*toDeg,1);
    // Serial.print(", ");
    // Serial.println(yaw*toDeg,1);
    
    prevSampleTime = millis();
  }

}
