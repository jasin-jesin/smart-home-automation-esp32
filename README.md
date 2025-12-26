# Smart Home Automation & Security System (ESP32)

## Overview
This project is a multi-generation smart home automation and security system that I originally started developing in Grade 8. Over several years, the system evolved through multiple versions as my understanding of embedded systems, IoT platforms, sensors, and cloud services improved.

The current version is a nostalgic rebuild using modern hardware and updated platforms, reflecting how my engineering approach has matured over time.

---

## Hardware (Latest Version)
- ESP32-S3
- Custom zero-PCB relay module
- BME688 – temperature, humidity, pressure, air quality
- VEML7700 – ambient light sensor
- ESP32-CAM (previous versions)
- GSM module (previous versions)

---

## Core Features
- Home appliance control using relay modules
- Environmental monitoring
- Human presence detection
- Gas and flame safety alerts
- Camera-based security with facial recognition
- Automatic door access for recognised faces
- Alerts via GSM, email, and cloud notifications
- Real-time dashboards and data logging

---

## Project Evolution Timeline

### Version 1 – Basic IoT Automation (Grade 8)
- IR sensor for human detection
- Rain sensor
- MQ-2 gas sensor
- Flame sensor
- Relay-based appliance control
- Cloud control using Blynk

---

### Version 2 – Safety & Alerts
- GSM-based SMS alerts
- Improved gas and fire detection
- Real-time emergency notifications

---

### Version 3 – Camera & Security
- ESP32-CAM integration
- Image capture and email alerts
- Basic facial recognition
- Automatic door unlocking for recognised faces
- Call alerts for unknown faces

---

### Version 4 – Platform Exploration
- Cayenne
- ESP RainMaker
- Firebase backend
- ThingSpeak for data collection and visualisation

---

### Version 5 – Custom Mobile App
- Android app developed using Kodular
- Firebase real-time database
- Direct device control without third-party dashboards

---

## Current Version – Modern Rebuild
- ESP32-S3 platform
- High-accuracy sensors (BME688, VEML7700)
- Clean relay PCB design
- Updated Blynk platform with built-in email notifications
- Improved firmware structure and reliability

---

## Platforms & Technologies Used
- ESP32 / ESP32-S3
- Blynk
- Firebase
- ThingSpeak
- ESP RainMaker
- Kodular
- GSM communication
- Embedded C / Arduino framework

---

## Why This Project Matters
This project represents long-term learning, experimentation, and system evolution. Revisiting it after several years helped me reflect on how my design, debugging, and architecture decisions have improved with experience.

---

## Future Improvements
- Local AI inference for face recognition
- Improved security and encryption
- Web dashboard integration
- Modular PCB design
