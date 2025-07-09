<div align="center">

<img src="https://img.icons8.com/fluency/96/alarm.png" width="80" />

# IPS – Instant Ping System  
*A Wi-Fi-enabled emergency alert button using ESP8266 and Telegram*

[![Platform](https://img.shields.io/badge/platform-ESP8266-pink.svg)](#hardware)
[![Built With](https://img.shields.io/badge/built%20with-C++-purple.svg)](https://www.arduino.cc/)
[![Telegram](https://img.shields.io/badge/telegram-bot-blue.svg)](https://telegram.org/)

</div>

---

## 📖 Overview

**IPS (Instant Ping System)** is a compact hardware-software project that allows you to send an instant Telegram message by pressing a physical button.  
Perfect for:

- 🔴 Emergency alert systems  
- 🧓 Elder assistance at home  
- 🏢 Panic buttons in offices or labs  
- 👨‍🔧 Maker projects & IoT experimentation

---

## 📸 Demo

<p align="center">
  <img src="ips_pic.jpg">
</p>

---

## 📡 How It Works


[Button Pressed] --> [ESP8266 Connects Wi-Fi] --> [Sends HTTP Request] --> [PHP Server Calls Telegram Bot API] --> [Message Delivered in Telegram]


The ESP8266 sends an HTTP request to a PHP server (hosted on Render or Replit), and the server uses the Telegram Bot API to deliver the message to the specified chat.

---

## 🚀 How to Use

1. **Setup your hardware:**
   - Connect the push button to the ESP8266 as follows:  
     - One side of the button to GPIO D5 (GPIO14)  
     - The other side to GND  
   - Use `INPUT_PULLUP` mode for the button pin in the code to avoid external resistors.

2. **Configure your software:**
   - Flash the ESP8266 code with your Wi-Fi SSID and password.  
   - Make sure the `serverName` points to your hosted PHP server URL that forwards the message to Telegram.

3. **Power on the ESP8266** and ensure it connects to your Wi-Fi network.  
   - Open the Serial Monitor at 115200 baud rate to see status messages.

4. **Press the button**:  
   - When the button is pressed, the ESP8266 will send an HTTP GET request to your PHP server.  
   - The PHP server will use the Telegram Bot API to send a predefined alert message to your Telegram chat.

5. **Check your Telegram app**:  
   - The message like `🔔 Farnaz NEED HELP!!` should appear instantly in the chat you specified.

     ###  Message sent example (Serial Monitor output):

  <img src="mes.jpg" width="300">


---



## 🔧 Hardware

| Component       | Description                  |
|----------------|------------------------------|
| ESP8266 Board  | We used NodeMCU (ESP-12E)     |
| Push Button    | Momentary tactile switch      |
| Jumper Wires   | For connections               |
| Breadboard     | For quick prototyping         |
| Wi-Fi Network  | Required for connectivity     |

### 🔌 Circuit Diagram

[Button] -----> [D5 (GPIO14)]
[Button] -----> [GND]

> *Use INPUT_PULLUP to avoid external resistor.*

---

## 💻 Software Setup

### 🧠 ESP8266 Code

1. Open Arduino IDE.
2. Install `ESP8266 Board` from Board Manager.
3. Install `ESP8266HTTPClient.h` and `WiFiClientSecure.h`.
4. Flash the code from [`ips.ino`](ips.ino) to your board.

🛑 **Do NOT include real credentials in public repositories!**

```cpp
const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";
const char* serverName = "https://your-server-url.com";
```

## Credits

Made by Farnaz Tarabi
