# sic_i2c_lib
This is a child project of the Samuko IMU Compute (SIC) project. This library helps communicate with the already setup IMU (`MPU9250 module`) with  arduino-based microcontroller projects via I2C, after successful setup with the [**`sic_calibration_py_codes`**](https://github.com/samuko-things-company/sic_calibration_py_codes).

> you can use it in your Arduino-based robotics project (e.g Arduino UNO, Arduino NANO, Arduino MEGA, Esp32, etc.)

A simple way to get started is simply to try out and follow the example code


## How to Use the Library
- Ensure you have the **`sic_mpu9250_driver module`** interfaced with the **`MPU9250`** module. setup and cilibrate it using the **`sic_calibration_py_codes`**.

- Download download the library by clicking on the green Code button above (or clone it)

- move the downloaded library file to your Arduino library folder
  > e.g on linux: ... home/Arduino/libraries/
  >
  > e.g on windows: ... Documents/Arduino/libraries/

- restart your ArduinoIDE and navigate to examples and run the example code and see how the motors behave.

- you can copy this example code into your project and modify it to your taste.


## Basic Library functions and usage

- connect to sic_driver shield module
  > SIC("port_name or port_path")

- get filtered Roll, Pitch and incremental Yaw values
  > getRPY(&roll, &pitch, &yaw)

- get filtered absolute Yaw orientation readings
  > getHeading(&yaw_abs)

- get Roll, Pitch and Yaw rates value
  > getRPYrate(&roll_rate, &pitch_rate, &yaw_rate)

- get linear acceleration values ax, ay, az
  > getLinAcc(&ax, &ay, &az)
