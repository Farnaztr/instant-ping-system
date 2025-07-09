<div align="center">

<img src="https://img.icons8.com/fluency/96/alarm.png" width="80" />

# IPS – Instant Ping System  
*A Wi-Fi-enabled emergency alert button using ESP8266 and Telegram*

[![Platform](https://img.shields.io/badge/platform-ESP8266-blue.svg)](#hardware)
[![Built With](https://img.shields.io/badge/built%20with-C++-informational)](https://www.arduino.cc/)
[![Telegram](https://img.shields.io/badge/telegram-bot-blue)](https://telegram.org/)

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
