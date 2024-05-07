#ifndef SIC_MPU9250_I2C_LIB_H
#define SIC_MPU9250_I2C_LIB_H

#if ARDUINO >= 100
  #include <Arduino.h>
#else
  #include <WProgram.h>
#endif


#include <Wire.h>


class SIC {
public:
  SIC (int);

  void getRPY(float&, float&, float&);
  void getRPYrate(float&, float&, float&);
  void getAcc(float&, float&, float&);
  void getQuat(float&, float&, float&, float&);
  void getRPYvariance(float&, float&, float&);
  void getRPYrateVariance(float&, float&, float&);
  void getAccVariance(float&, float&, float&);

  
private:
  int slaveAddr;
  String dataMsg = "", dataMsgBuffer = "", dataBuffer[3];
  float valA, valB, valC, valD;

  void get(String);

  void masterSendData(String);

  // String masterReceiveData();

  String masterReceiveDataLarge();

  // String masterReceiveDataChar();
  
};

#endif
