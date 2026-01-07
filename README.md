# 🚙 Bluetooth Controlled Off-Road Robot

**A high-torque, rugged off-road vehicle designed for robotics competitions.**

This project features a **custom metal-chassis rover** capable of traversing rough terrain using **dual 12V high-torque motors**. Controlled wirelessly via a smartphone app (Bluetooth), the system allows for dynamic switching between **High-Speed** and **High-Torque** modes to handle obstacles effectively.

Developed for the **Offroad Car Robotics Competition** at **University School of Information, Communication & Technology (USICT)** (Feb 2024).

---

## ⚙️ Features

* **Wireless Control:** Real-time steering via Android Bluetooth App.
* **Rugged Build:** Full metal chassis with high ground clearance for durability.
* **Dual Drive Modes:**
    * 🚀 **Speed Mode:** Delivers maximum voltage for flat surfaces.
    * 🧗 **Torque Mode:** Adjusts PWM for precision climbing and crawling.
* **Powertrain:** 2x 12V High-Torque DC Motors driven by an L298N driver.
* **Brain:** Arduino Nano.

---

## 🛠️ Hardware Requirements

* **Microcontroller:** Arduino Nano
* **Communication:** HC-05 or HC-06 Bluetooth Module
* **Driver:** L298N Dual H-Bridge Motor Driver
* **Motors:** 2x 12V High-Torque DC Geared Motors
* **Power:** 12V Li-Ion Battery Pack (3S)
* **Chassis:** Custom Metal Fabrication
* **Switch:** SPST Rocker Switch

---

## 🔌 Circuit Connections

### 1. Bluetooth Module (HC-05) to Arduino Nano
| HC-05 Pin | Arduino Pin | Note |
| :--- | :--- | :--- |
| **VCC** | 5V | Power |
| **GND** | GND | Ground |
| **TX** | D2 | Connected to SoftSerial RX |
| **RX** | D3 | Connected to SoftSerial TX |

### 2. L298N Motor Driver to Arduino
| L298N Pin | Arduino Pin | Function |
| :--- | :--- | :--- |
| **ENA** | D5 | PWM Speed Control (Left Motor) |
| **IN1** | D6 | Left Motor Input A |
| **IN2** | D7 | Left Motor Input B |
| **IN3** | D8 | Right Motor Input A |
| **IN4** | D9 | Right Motor Input B |
| **ENB** | D10 | PWM Speed Control (Right Motor) |

---

## ▶️ How to Run

1.  **Assembly:** Mount the motors to the metal chassis and wire the electrical components according to the tables above.
2.  **Upload Code:** Open the `offroad_car.ino` file in the Arduino IDE and upload it to the Arduino Nano.
3.  **App Setup:**
    * Download an **"Arduino Bluetooth Controller"** app from the Google Play Store.
    * Configure the buttons to send the following characters:
        * **'F'** - Forward
        * **'B'** - Backward
        * **'L'** - Left
        * **'R'** - Right
        * **'S'** - Stop
        * **'X'** - Speed Mode (Max Power)
        * **'x'** - Torque Mode (Slower, precision control)
4.  **Drive:** Power on the car, pair your phone with the HC-05 module (Password: `1234` or `0000`), and start driving.

---

## 📜 License

MIT License

---

## 👤 Author

**[Your Name]**
*University School of Information, Communication & Technology (USICT)*
