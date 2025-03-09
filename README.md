# Arduino-Based Heart Rate & SpO2 Monitor with Bluetooth (HC-05 & MAX30100)

## 1. Introduction

This project is a real-time Heart Rate & SpO2 Monitoring System using the MAX30100 Pulse Oximeter Sensor and HC-05 Bluetooth Module. It measures:

- Heart Rate (BPM)
- Oxygen Saturation (SpO2 %)

The data is displayed on the Arduino Serial Monitor and transmitted to a mobile phone via Bluetooth for real-time monitoring.

## 2. How It Works (Procedure)

The project follows these steps:

1. The MAX30100 sensor detects heart rate and SpO2 levels using infrared and red LEDs.
2. The Arduino reads data from the sensor using I2C communication.
3. The Bluetooth module (HC-05) transmits the data wirelessly.
4. A mobile phone receives the data using a Bluetooth Terminal App.
5. The live readings are displayed on the mobile screen.

## 3. Circuit Connection

### Required Components:

| Component | Quantity |
|-----------|----------|
| Arduino Uno | 1 |
| MAX30100 Pulse Oximeter Sensor | 1 |
| HC-05 Bluetooth Module | 1 |
| Jumper Wires | As needed |

### Pin Connections:

#### MAX30100 (I2C) Sensor Connections

| MAX30100 Pin | Arduino Uno Pin |
|-------------|-----------------|
| VCC | 5V |
| GND | GND |
| SCL | A5 (SCL) |
| SDA | A4 (SDA) |

#### HC-05 Bluetooth Module Connections

| HC-05 Pin | Arduino Uno Pin |
|----------|-----------------|
| VCC | 5V |
| GND | GND |
| TX | D10 (Arduino RX) |
| RX | D11 (Arduino TX, via voltage divider) |

## 4. Step-by-Step Connection

### Step 1: Setting Up the MAX30100 Sensor

- Connect VCC → 5V, GND → GND, SCL → A5, and SDA → A4.
- Ensure the sensor is placed correctly for proper readings.

### Step 2: Connecting the HC-05 Bluetooth Module

- Connect VCC → 5V, GND → GND, TX → D10, and RX → D11.
- Use a voltage divider (1KΩ & 2KΩ resistors) for RX pin protection.

### Step 3: Uploading the Code to Arduino

- Open Arduino IDE and install the required libraries:
  - `Wire.h` (for I2C communication)
  - `MAX30100_PulseOximeter.h` (for MAX30100)
  - `SoftwareSerial.h` (for Bluetooth communication)
- Upload the program to Arduino Uno.

### Step 4: Connecting to a Mobile Phone

- Pair HC-05 Bluetooth module with your phone (PIN: 1234 or 0000).
- Open a Bluetooth Terminal App (e.g., Serial Bluetooth Terminal).
- Select HC-05 and connect.
- The heart rate and SpO2 readings will appear on the app.

### Step 5: Viewing Real-Time Data

- Heart Rate and SpO2 are displayed every 1 second.
- The "Heartbeat detected" message appears when a pulse is sensed.
- Data updates automatically without manual refresh.

## 5. Conclusion

This project successfully measures Heart Rate and SpO2 and transmits the data wirelessly to a mobile phone. It can be used for:

- Real-time health monitoring
- Medical applications
- Fitness tracking

Further improvements include:

- Building a mobile app for better visualization.
- Adding an OLED display for standalone monitoring.
- Data logging for long-term analysis.

This project is ideal for students, IoT enthusiasts, and healthcare applications.

