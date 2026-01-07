/*
 * Project: Offroad Bluetooth Car
 * Author: [Your Name], USICT
 * Hardware: Arduino Nano, L298N, HC-05
 * Description: Bluetooth controlled car with Speed/Torque toggling.
 */

#include <SoftwareSerial.h>

// Bluetooth Pins (RX, TX)
SoftwareSerial BTSerial(2, 3); 

// Motor Driver Pins (L298N)
// Left Motor
const int ENA = 5;  // PWM Enabled Pin
const int IN1 = 6;
const int IN2 = 7;

// Right Motor
const int IN3 = 8;
const int IN4 = 9;
const int ENB = 10; // PWM Enabled Pin

// Variables
char command;
int motorSpeed = 255; // Default to High Speed

void setup() {
  // Start Serial Communication for Debugging and Bluetooth
  Serial.begin(9600);
  BTSerial.begin(9600);

  // Set Motor Pins as Output
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);

  Serial.println("Offroad Car Initialized");
}

void loop() {
  if (BTSerial.available()) {
    command = BTSerial.read();
    executeCommand(command);
  }
}

void executeCommand(char cmd) {
  switch (cmd) {
    case 'F': moveForward(); break;
    case 'B': moveBackward(); break;
    case 'L': turnLeft(); break;
    case 'R': turnRight(); break;
    case 'S': stopCar(); break;
    
    // Mode Switching
    case 'X': // High Speed Mode
      motorSpeed = 255; 
      Serial.println("Mode: High Speed");
      break;
    case 'x': // High Torque/Crawl Mode
      motorSpeed = 160; // Lower PWM for better control on obstacles
      Serial.println("Mode: High Torque");
      break;
  }
}

// --- Movement Functions ---

void moveForward() {
  analogWrite(ENA, motorSpeed);
  analogWrite(ENB, motorSpeed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void moveBackward() {
  analogWrite(ENA, motorSpeed);
  analogWrite(ENB, motorSpeed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void turnLeft() {
  analogWrite(ENA, motorSpeed);
  analogWrite(ENB, motorSpeed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnRight() {
  analogWrite(ENA, motorSpeed);
  analogWrite(ENB, motorSpeed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stopCar() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}
