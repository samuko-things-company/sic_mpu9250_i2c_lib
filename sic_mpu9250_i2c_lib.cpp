
#include "sic_mpu9250_i2c_lib.h"

SIC::SIC(int slave_addr)
{
  slaveAddr = slave_addr;
}

void SIC::setFilterGain(float gain)
{
  send("/gain", gain);
}

void SIC::getFilterGain(float &gain)
{
  get("/gain");

  gain = valA;

  valA = 0.0;
  valB = 0.0;
  valC = 0.0;
}

void SIC::getRPY(float &roll, float &pitch, float &yaw)
{
  get("/rpy");

  roll = valA;
  pitch = valB;
  yaw = valC;

  valA = 0.0;
  valB = 0.0;
  valC = 0.0;
}

void SIC::getQuat(float &qw, float &qx, float &qy, float &qz)
{
  float r, p, y;
  getRPY(r, p, y);

  qw = cos(r / 2) * cos(p / 2) * cos(y / 2) + sin(r / 2) * sin(p / 2) * sin(y / 2);
  qx = sin(r / 2) * cos(p / 2) * cos(y / 2) - cos(r / 2) * sin(p / 2) * sin(y / 2);
  qy = cos(r / 2) * sin(p / 2) * cos(y / 2) + sin(r / 2) * cos(p / 2) * sin(y / 2);
  qz = cos(r / 2) * cos(p / 2) * sin(y / 2) - sin(r / 2) * sin(p / 2) * cos(y / 2);
}

void SIC::getGyro(float &roll_rate, float &pitch_rate, float &yaw_rate)
{
  get("/gyr-cal");

  roll_rate = valA;
  pitch_rate = valB;
  yaw_rate = valC;

  valA = 0.0;
  valB = 0.0;
  valC = 0.0;
}

void SIC::getAcc(float &ax, float &ay, float &az)
{
  get("/acc-cal");

  ax = valA;
  ay = valB;
  az = valC;

  valA = 0.0;
  valB = 0.0;
  valC = 0.0;
}

void SIC::getRollVariance(float &var)
{
  get("/r-var");

  var = valA;

  valA = 0.0;
  valB = 0.0;
  valC = 0.0;
}

void SIC::getPitchVariance(float &var)
{
  get("/p-var");

  var = valA;

  valA = 0.0;
  valB = 0.0;
  valC = 0.0;
}

void SIC::getYawVariance(float &var)
{
  get("/y-var");

  var = valA;

  valA = 0.0;
  valB = 0.0;
  valC = 0.0;
}

void SIC::getAxVariance(float &var)
{
  get("/ax-var");

  var = valA;

  valA = 0.0;
  valB = 0.0;
  valC = 0.0;
}

void SIC::getAyVariance(float &var)
{
  get("/ay-var");

  var = valA;

  valA = 0.0;
  valB = 0.0;
  valC = 0.0;
}

void SIC::getAzVariance(float &var)
{
  get("/az-var");

  var = valA;

  valA = 0.0;
  valB = 0.0;
  valC = 0.0;
}

void SIC::getGxVariance(float &var)
{
  get("/gx-var");

  var = valA;

  valA = 0.0;
  valB = 0.0;
  valC = 0.0;
}

void SIC::getGyVariance(float &var)
{
  get("/gy-var");

  var = valA;

  valA = 0.0;
  valB = 0.0;
  valC = 0.0;
}

void SIC::getGzVariance(float &var)
{
  get("/gz-var");

  var = valA;

  valA = 0.0;
  valB = 0.0;
  valC = 0.0;
}

void SIC::masterSendData(String i2c_msg)
{
  char charArray[i2c_msg.length() + 1];
  i2c_msg.toCharArray(charArray, i2c_msg.length() + 1);

  Wire.beginTransmission(slaveAddr);
  Wire.write(charArray);
  Wire.endTransmission();
}

String SIC::masterReceiveData(byte dataSize)
{
  String i2c_msg = "";
  Wire.requestFrom((int)slaveAddr, (int)dataSize);
  while (Wire.available())
  {
    char c = Wire.read();
    i2c_msg += c;
  }
  int indexPos = i2c_msg.indexOf((char)255);
  if (indexPos != -1)
  {
    return i2c_msg.substring(0, indexPos);
  }
  return i2c_msg;
}

void SIC::get(String address_route)
{
  masterSendData(address_route);
  dataMsg = masterReceiveData(32);

  int indexPos = 0, i = 0;
  do
  {
    indexPos = dataMsg.indexOf(',');
    if (indexPos != -1)
    {
      dataMsgBuffer = dataMsg.substring(0, indexPos);
      dataMsg = dataMsg.substring(indexPos + 1, dataMsg.length());
      dataBuffer[i] = dataMsgBuffer;
      dataMsgBuffer = "";
    }
    else
    {
      if (dataMsg.length() > 0)
        dataBuffer[i] = dataMsg;
    }
    i += 1;
  } while (indexPos >= 0);

  valA = dataBuffer[0].toFloat();
  valB = dataBuffer[1].toFloat();
  valC = dataBuffer[2].toFloat();

  dataMsg = "";
  dataMsgBuffer = "";
  dataBuffer[0] = "";
  dataBuffer[1] = "";
  dataBuffer[2] = "";
}

void SIC::send(String address_route, float valA)
{
  String msg_buffer = address_route;
  msg_buffer += ",";
  msg_buffer += String(valA, 3);

  masterSendData(msg_buffer);
}