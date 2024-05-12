# sic_mpu9250_i2c_lib
This is a child project of the **`sic_mpu9250 project`**. This library helps communicate with the already setup IMU (`MPU9250 module`) with  arduino-based microcontroller projects via I2C, after successful setup with the [**`sic_mpu9250_setup_application`**](https://github.com/samuko-things-company/sic_mpu9250_setup_application).

> you can use it in your Arduino-based robotics project (e.g Arduino UNO, Arduino NANO, Arduino MEGA, Esp32, etc.)

A simple way to get started is simply to try out and follow the example code


## How to Use the Library
- Ensure you have the **`sic_mpu9250_driver module`**. Calibrate it and set it up using the **`sic_mpu9250_setup_application`**.

- Download download the library by clicking on the green Code button above (or clone it)

- Move the downloaded library file to your Arduino library folder
  > e.g on linux: ... home/Arduino/libraries/
  >
  > e.g on windows: ... Documents/Arduino/libraries/

- restart your ArduinoIDE and navigate to examples and run the example `read_rpy_data.ino` code and see the IMU readings.

- you can copy this example code into your project and modify it to your taste.


## Basic Library functions and usage

- connect to sic_driver shield module
  > SIC("port_name or port_path")

- get filtered Roll, Pitch and Yaw values in 6dp
  > getRPY(&roll, &pitch, &yaw)

- get Roll, Pitch and Yaw rates value in 6dp
  > getRPYrate(&roll_rate, &pitch_rate, &yaw_rate)

- get linear acceleration values ax, ay, az in 6dp
  > getAcc(&ax, &ay, &az)

- get rpy variances in 6dp
  > getRPYvariance(&r_var, &p_var, &y_var)

- get rpy rate variances in 6dp
  > getRPYrateVariance(&r_var, &p_var, &y_var)

- get acceleration variances in 6dp
  > getAccVariance(&ax_var, &ay_, &az_var)
