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
  void getLinAcc(float&, float&, float&);

  
private:
  int slaveAddr;
  String dataMsg = "", dataMsgBuffer = "", dataBuffer[3];
  float valA, valB, valC;

  void get(String);

  void masterSendData(String);

  // String masterReceiveData();

  String masterReceiveDataLarge();

  // String masterReceiveDataChar();
  
};

#endif
