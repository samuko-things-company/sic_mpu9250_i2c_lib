# sic_mpu9250_i2c_lib
This is a child project of the **`sic_mpu9250 project`**. This library helps communicate with the already setup IMU (`MPU9250 module`) with  arduino-based microcontroller projects via I2C, after successful setup with the [**`sic_mpu9250_setup_application`**](https://github.com/samuko-things-company/sic_mpu9250_setup_application).

> you can use it in your Arduino-based robotics project (e.g Arduino UNO, Arduino NANO, Arduino MEGA, Esp32, etc.)

A simple way to get started is simply to try out and follow the example code


## How to Use the Library
- Ensure you have the **`sic_mpu9250_driver module`**. Calibrate it and set it up using the **`sic_mpu9250_setup_application`**.

- Download download the library by clicking on the green Code button above (or clone it)
  > if you download it, extract it and change the folder name to `sic_mpu9250_i2c_lib`

- Move the downloaded library file -`sic_mpu9250_i2c_lib` - to your Arduino library folder
  > e.g on linux: ... home/Arduino/libraries/
  >
  > e.g on windows: ... Documents/Arduino/libraries/

- restart your ArduinoIDE and navigate to examples and run the example `read_rpy_data.ino` code and see the IMU readings.

- you can copy this example code into your project and modify it to your taste.


## Basic Library functions and usage

- connect to sic_mpu9250 module via i2c by creating an object
  > `SIC` imu(i2cAddress)

- get filtered Roll, Pitch and Yaw values in 6dp
  > imu.`getRPY`(&roll, &pitch, &yaw)

- get filtered quaternion [qw, qx, qy, qz] values in 6dp
  > imu.`getQuat`(&qw, &qx, &qy, &qz)

- get Roll, Pitch and Yaw rates value in 6dp
  > imu.`getGyro`(&gx, &gy, &gz)

- get linear acceleration values ax, ay, az in 6dp
  > imu.`getAcc`(&ax, &ay, &az)

- get roll variance in 10dp
  > imu.`getRollVariance`(&r_var)

- get pitch variance in 10dp
  > imu.`getPitchVariance`(&p_var)

- get yaw variance in 10dp
  > imu.`getYawVariance`(&y_var)

- get roll rate variances in 10dp
  > imu.`getGxVariance`(&gx_var)

- get pitch rate variances in 10dp
  > imu.`getGyVariance`(&gy_var)

- get yaw rate variances in 10dp
  > imu.`getGzVariance`(&gz_var)

- get accX variances in 10dp
  > imu.`getAxVariance`(&ax_var)

- get accY variances in 10dp
  > imu.`getAyVariance`(&ay_var)

- get accZ variances in 10dp
  > imu.`getAzVariance`(&az_var)
