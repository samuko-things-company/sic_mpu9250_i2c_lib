#ifndef SIC_MPU9250_I2C_LIB_H
#define SIC_MPU9250_I2C_LIB_H

#if ARDUINO >= 100
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

#include <Wire.h>
#include <math.h>

class SIC
{
public:
  SIC(int);

  bool setFilterGain(float);
  void getFilterGain(float &);

  void getRPY(float &, float &, float &);
  void getGyro(float &, float &, float &);
  void getAcc(float &, float &, float &);
  void getQuat(float &, float &, float &, float &);

  void getRollVariance(float &);
  void getPitchVariance(float &);
  void getYawVariance(float &);

  void getAxVariance(float &);
  void getAyVariance(float &);
  void getAzVariance(float &);

  void getGxVariance(float &);
  void getGyVariance(float &);
  void getGzVariance(float &);

private:
  int slaveAddr;
  String dataMsg = "", dataMsgBuffer = "", dataBuffer[3];
  float valA, valB, valC;

  void get(String);

  bool send(String, float);

  void masterSendData(String);

  String masterReceiveData();

  String masterReceiveCharData();
};

#endif
