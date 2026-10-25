# Sandalwood Farm Surveillance and Protection System 🌳

An IoT-based surveillance and protection system designed to detect suspicious movement and potential illegal cutting of sandalwood trees using wireless sensor nodes and centralized monitoring.

## 📌 Project Overview

Sandalwood trees have significant economic value and are vulnerable to unauthorized cutting and theft. This project proposes an affordable, scalable IoT-based monitoring system that detects abnormal tree movement and transmits sensor data to a central master node for monitoring and threat identification.

The system uses motion sensing, wireless communication, and environmental monitoring to help distinguish potential threats from natural disturbances such as strong winds.

## 🎯 Objectives

- Detect abnormal tree movement, tilting, and vibrations that may indicate cutting attempts.
- Transmit sensor data wirelessly from individual tree nodes to a master node.
- Monitor multiple trees through a centralized system.
- Reduce false alarms using environmental data from a wind sensor.
- Explore low-power operation for outdoor deployment.
- Provide a foundation for real-time alerts and centralized surveillance.

## 🏗️ System Architecture

The proposed system consists of two main components:

### 1. Child / Sensor Node

Each sensor node is intended to be installed near a monitored tree.

**Main components:**
- Arduino Nano — local sensor controller
- MPU6050 accelerometer and gyroscope — detects movement and changes in orientation
- NRF24L01+ RF module — wireless data communication

The sensor node collects motion data, evaluates suspicious movement, and transmits information to the master node.

### 2. Master Node

The master node collects data from the sensor nodes and acts as the central communication gateway.

**Main components:**
- ESP32 — central controller and data processing
- Compatible RF communication module — receives sensor-node data
- Wi-Fi connectivity — enables communication with a monitoring dashboard

### 3. Environmental Monitoring

A centralized wind sensor is proposed to measure wind speed. This information can help identify movement caused by environmental conditions and reduce unnecessary alerts.

### 4. Centralized Monitoring

The proposed monitoring interface can display node status, detected events, and alerts. A centralized CCTV system may also be used to visually verify suspicious activity.

> **Implementation note:** Confirm which features are working in your final prototype before describing them as completed functionality.

## 🧰 Hardware Requirements

| Component | Purpose |
|---|---|
| Arduino Nano | Sensor-node controller |
| ESP32 development board | Master-node controller |
| MPU6050 | Motion and orientation sensing |
| NRF24L01+ | Wireless communication, if used in the final build |
| Wind sensor / anemometer | Environmental monitoring |
| Power supply or battery | Powers the sensor nodes |
| CCTV camera (optional) | Visual verification |

The exact hardware requirements depend on the final circuit and communication architecture.

## 💻 Software and Technologies

- Embedded C/C++ for microcontroller programming
- Arduino IDE for firmware development
- Sensor interfacing and data acquisition
- Wireless communication between sensor and master nodes
- Wi-Fi-based data transmission through the ESP32
- Dashboard or IoT platform, if implemented

## ⚙️ Working Principle

1. **Sensor initialization:** The child node initializes the motion sensor and wireless communication module.
2. **Motion monitoring:** The MPU6050 measures acceleration and orientation changes.
3. **Event detection:** The controller evaluates sensor readings to identify abnormal movement.
4. **Wireless transmission:** The child node transmits relevant data to the master node.
5. **Data processing:** The master node receives the information and processes the reported event.
6. **Environmental verification:** Wind measurements can be considered when evaluating possible false alarms.
7. **Monitoring and alerts:** The collected information can be presented on a centralized dashboard for further inspection.

## 📊 Testing and Evaluation

The project report discusses the importance of wireless communication performance, power consumption, latency, and energy efficiency.

The following tests are recommended for evaluating the implemented prototype:

- Motion detection under normal and abnormal conditions
- Wireless communication reliability and operating range
- Response time between event detection and master-node reception
- False-positive behavior during windy conditions
- Power consumption during active and idle states
- Node connectivity and recovery after communication loss

Measured results should be added here once verified on the actual hardware.

## 📷 Project Images
<img width="1070" height="807" alt="image" src="https://github.com/user-attachments/assets/12db909d-7793-497a-90bc-fb1b40bbf910" />


Add your actual prototype and system diagrams to the repository.


## 🚀 Getting Started

1. Clone or download this repository.
2. Install the Arduino IDE.
3. Install the required board support packages and sensor libraries.
4. Open the child-node and master-node firmware projects.
5. Configure the hardware pins and wireless communication settings to match the circuit.
6. Upload the appropriate firmware to each microcontroller.
7. Power on the sensor and master nodes.
8. Verify wireless communication and sensor readings using the serial monitor.

**Note:** Exact library names, pin mappings, configuration values, and dashboard setup instructions should be documented alongside the final source code.

## 🔮 Future Improvements

- Implement robust multi-node routing if a mesh network is required.
- Add a reliable event-classification algorithm to distinguish cutting attempts from environmental movement.
- Integrate real-time notifications.
- Develop an interactive dashboard with node status and event history.
- Add battery monitoring and optimized sleep modes.
- Evaluate outdoor range, reliability, and long-term power consumption.
- Integrate optional camera-based verification.

## 🌱 Applications

- Sandalwood farms and plantations
- High-value tree protection
- Forest monitoring
- Agricultural security
- Remote environmental monitoring

## 👨‍💻 Project Information

**Project:** Sandalwood Farm Surveillance and Protection System  
**Domain:** Internet of Things (IoT), Embedded Systems, Wireless Sensor Networks  
**Institution:** G H Raisoni College of Engineering, Nagpur, India

## 📄 Research Reference

This repository accompanies the project report titled *Sandalwood Farm Surveillance and Protection System*.

## ⚠️ Disclaimer

This project is a prototype and research-oriented system. Its effectiveness in detecting unauthorized tree cutting depends on the implemented hardware, detection logic, communication reliability, and field testing. It is intended to support monitoring, not to guarantee prevention of theft.
