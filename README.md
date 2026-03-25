# Temperature-Controlled Fan System (Arduino)

This project is a simple Arduino-based **automatic temperature control system** that turns a **fan ON or OFF** based on the measured temperature. It uses a **DS18B20 temperature sensor**, a **relay module**, and an **LCD display** for real-time monitoring.

---

## Project Overview

The system continuously monitors temperature and automatically controls a fan:

- If temperature is **above 36°C** → Fan turns ON  
- If temperature is **below 36°C** → Fan turns OFF  

It is designed for:
- small cooling systems  
- room temperature monitoring  
- basic automation projects  

---

## Features

### 🌡️ Temperature Monitoring
- Uses **DS18B20 digital temperature sensor**  
- Provides accurate temperature readings in °C  

---

### 🔌 Automatic Fan Control
- Controls fan using a relay module  
- Turns ON/OFF based on temperature threshold  

---

### 📺 LCD Display
- 16x2 I2C LCD  
- Displays:
  - current temperature  
  - fan status (ON/OFF)  

---

### ⚙️ Simple Automation Logic
- No manual input required  
- Fully automatic operation  

---

## System Workflow

### 1. Initialization
- LCD turns ON  
- Sensor initializes  

---

### 2. Temperature Reading
- DS18B20 reads temperature  
- Value displayed on LCD  

---

### 3. Decision Logic

- If `temperature > 36°C`:
  - Fan turns ON  
  - LCD shows: `FAN ON`

- If `temperature < 36°C`:
  - Fan turns OFF  
  - LCD shows: `FAN OFF`

---

### 4. Loop
- System updates every second  

---

## Pin Configuration

| Component        | Arduino Pin |
|------------------|------------|
| DS18B20 Data     | 2          |
| Relay Module     | 5          |
| LCD (SDA)        | A4         |
| LCD (SCL)        | A5         |

---

## Wiring Connections

### 🌡️ DS18B20 Temperature Sensor
- VCC → 5V  
- GND → GND  
- DATA → Pin 2  
- Add **4.7kΩ resistor** between DATA and VCC  

---

### 🔌 Relay Module
- IN → Pin 5  
- VCC → 5V  
- GND → GND  

⚠️ Note: Relay is **active LOW**
- LOW → ON  
- HIGH → OFF  

---

### 📺 LCD (I2C)
- SDA → A4  
- SCL → A5  
- VCC → 5V  
- GND → GND  

---

## Hardware Components

- Arduino Uno / Nano  
- DS18B20 Temperature Sensor  
- Relay Module  
- Fan (AC or DC)  
- 16x2 LCD (I2C)  
- 4.7kΩ Resistor  
- Jumper wires  
- Power supply  

---

## Key Parameters

| Parameter        | Value |
|------------------|------|
| Temperature Limit| 36°C |
| Update Interval  | 1 sec |

---

## Notes

- Ensure proper resistor (4.7kΩ) for DS18B20  
- Relay may require external power for high loads  
- LCD address is usually `0x27`  
- Sensor accuracy depends on placement  

---

## Limitations

- Fixed temperature threshold (not adjustable)  
- No manual override  
- No IoT or remote monitoring  
- No hysteresis (may switch rapidly near threshold)  

---

## Summary

This project demonstrates a simple **automatic temperature control system** that combines:

- digital temperature sensing  
- relay-based control  
- real-time LCD display  

It is suitable for:

- small cooling systems  
- home automation basics  
- embedded system learning  
