#include <Wire.h>
#include "MAX30100_PulseOximeter.h"
#include <SoftwareSerial.h>

#define REPORTING_PERIOD_MS 1000  // Update every 1 second

PulseOximeter pox;
uint32_t lastReportTime = 0;

// Define Bluetooth TX/RX Pins
SoftwareSerial BTSerial(10, 11);  // HC-05: TX=10, RX=11

void onBeatDetected() {
    Serial.println("♥ Heartbeat detected!");
    BTSerial.println("♥ Heartbeat detected!");
}

void setup() {
    Serial.begin(115200);
    BTSerial.begin(9600); // HC-05 Baud Rate

    Serial.println("Initializing MAX30100...");
    BTSerial.println("Initializing MAX30100...");

    if (!pox.begin()) {
        Serial.println("Failed to initialize MAX30100!");
        BTSerial.println("Failed to initialize MAX30100!");
        while (1);
    }

    pox.setOnBeatDetectedCallback(onBeatDetected);
}

void loop() {
    pox.update();

    if (millis() - lastReportTime > REPORTING_PERIOD_MS) {
        int heartRate = pox.getHeartRate();
        int spo2 = pox.getSpO2();

        // Print on Serial Monitor
        Serial.print("Heart Rate: ");
        Serial.print(heartRate);
        Serial.print(" bpm  |  SpO2: ");
        Serial.print(spo2);
        Serial.println(" %");

        // Send data to HC-05 Bluetooth
        BTSerial.print("Heart Rate: ");
        BTSerial.print(heartRate);
        BTSerial.print(" bpm  |  SpO2: ");
        BTSerial.print(spo2);
        BTSerial.println(" %");

        lastReportTime = millis();
    }
}
