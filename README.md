# I2C Network with ESP32 & Arduino for Temperature and Humidity Monitoring

This project demonstrates an I2C-based communication system between ESP32 and Arduino for real-time temperature and humidity monitoring. The collected data is sent to an IoT platform for remote visualization and control.

## Project Overview

The system is designed for smart environment applications and IoT learning. It uses I2C to connect microcontrollers and sensors, and Wi-Fi (via ESP32) to push data to an online IoT dashboard.

## Components Used

- **ESP32**  
  Acts as the main controller and IoT gateway.

- **Arduino Uno**  
  Used as an I2C slave device collecting sensor data.

- **I2C Communication**  
  For data transfer between Arduino and ESP32.


## Features

- I2C-based communication between ESP32 and Arduino  
- Real-time temperature and humidity monitoring  
- Wireless data transmission to cloud  
- Remote control capability from the IoT dashboard  
- Ideal for smart home or environment monitoring systems

## Files Included

- Arduino and ESP32 source code (Arduino IDE compatible)  
- Documentation for setup and usage

## Usage

1. Connect the ADS1115 sensor to the Arduino and set up I2C with ESP32  
2. Upload the respective codes to the Arduino and ESP32  
3. Configure your IoT platform credentials (e.g., Wi-Fi, API key)  
4. Monitor temperature and humidity remotely via dashboard  
5. Optionally control actuators from the cloud


