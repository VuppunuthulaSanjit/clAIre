/* * clAIre Navigation & Motor Control 
 * Board: ESP32
 */

#include <esp_now.h>
#include <WiFi.h>

// Motor Pins (Example for PCB Motor Driver)
const int LEFT_MOTOR = 25;
const int RIGHT_MOTOR = 26;

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  
  // Initialize ESP-NOW for low-latency communication
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }
  
  pinMode(LEFT_MOTOR, OUTPUT);
  pinMode(RIGHT_MOTOR, OUTPUT);
}

void loop() {
  // Logic: If user is detected via Vision ESP32, move forward
  // If obstacle is detected, STOP and trigger verbal warning
  bool obstacle = digitalRead(33); // Input from Vision Module
  
  if (obstacle) {
    stopMotors();
    Serial.println("OBSTACLE_STOP");
  } else {
    moveForward();
  }
  delay(50);
}

void moveForward() {
  analogWrite(LEFT_MOTOR, 150);
  analogWrite(RIGHT_MOTOR, 150);
}

void stopMotors() {
  analogWrite(LEFT_MOTOR, 0);
  analogWrite(RIGHT_MOTOR, 0);
}
