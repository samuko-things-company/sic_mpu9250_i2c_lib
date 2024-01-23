
#include "sic_i2c_lib.h"


SIC::SIC (int slave_addr){
  slaveAddr = slave_addr;
}


void SIC::getRPY(float &roll, float &pitch, float &yaw){
  get("rpy-est");

  roll = valA;
  pitch = valB;
  yaw = valC;

  valA = 0.0;
  valB = 0.0;
  valC = 0.0;
}


void SIC::getRPYrate(float &roll_rate, float &pitch_rate, float &yaw_rate){
  get("rpy-rate");

  roll_rate = valA;
  pitch_rate = valB;
  yaw_rate = valC;

  valA = 0.0;
  valB = 0.0;
  valC = 0.0;
}


void SIC::getLinAcc(float &ax, float &ay, float &az){
  get("acc-cal");

  ax = valA;
  ay = valB;
  az = valC;

  valA = 0.0;
  valB = 0.0;
  valC = 0.0;
}


void SIC::getHeading(float &heading){
  get("heading");

  heading = valA;

  valA = 0.0;
  valB = 0.0;
  valC = 0.0;
}








void SIC::get(String cmd_route){
  masterSendData(cmd_route);
  dataMsg = masterReceiveDataLarge();
  
  int indexPos = 0, i=0;
  do {
    indexPos = dataMsg.indexOf(',');
    if (indexPos != -1) {
      dataMsgBuffer = dataMsg.substring(0, indexPos);
      dataMsg = dataMsg.substring(indexPos + 1, dataMsg.length());
      dataBuffer[i] = dataMsgBuffer;
      dataMsgBuffer = "";
    }
    else {
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


void SIC::masterSendData(String i2c_msg){
  char charArray[i2c_msg.length() + 1];
  i2c_msg.toCharArray(charArray, i2c_msg.length() + 1);

  Wire.beginTransmission(slaveAddr); 
  Wire.write(charArray, i2c_msg.length());                
  Wire.endTransmission();
}


// String SIC::masterReceiveData(){
//   String i2c_msg = "";
//   Wire.requestFrom(slaveAddr,15);
//   while(Wire.available()){
//     char c = Wire.read();
//     i2c_msg += c;   
//   }
//   int indexPos = i2c_msg.indexOf((char)255);
//   if (indexPos != -1) {
//     return i2c_msg.substring(0, indexPos);
//   }
//   return i2c_msg;
// }

String SIC::masterReceiveDataLarge(){
  String i2c_msg = "";
  Wire.requestFrom(slaveAddr,50);
  while(Wire.available()){
    char c = Wire.read();
    i2c_msg += c;   
  }
  int indexPos = i2c_msg.indexOf((char)255);
  if (indexPos != -1) {
    return i2c_msg.substring(0, indexPos);
  }
  return i2c_msg;
}

// String SIC::masterReceiveDataChar(){
//   String i2c_msg = "";
//   Wire.requestFrom(slaveAddr,1);
//   while(Wire.available()){
//     char c = Wire.read();
//     i2c_msg += c;   
//   }
//   int indexPos = i2c_msg.indexOf((char)255);
//   if (indexPos != -1) {
//     return i2c_msg.substring(0, indexPos);
//   }
//   return i2c_msg;
// }
