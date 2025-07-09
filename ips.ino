#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "your_WiFi_SSID";
const char* password = "your_WiFi_Password";
const char* serverName = "https://your-server-url.com";

const int buttonPin = D5;
bool lastButtonState = HIGH;
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50;
bool messageSent = false;

WiFiClientSecure client;

void setup() {
  Serial.begin(115200);
  pinMode(buttonPin, INPUT_PULLUP);

  client.setInsecure(); 

  Serial.print("Connecting to WiFi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(300);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected.");
}

void loop() {
  bool reading = digitalRead(buttonPin);
  unsigned long currentTime = millis();

  if (reading != lastButtonState) {
    lastDebounceTime = currentTime;
  }

  if ((currentTime - lastDebounceTime) > debounceDelay) {
    if (reading == LOW && !messageSent) {
      Serial.println("Button Pressed");

      if (WiFi.status() == WL_CONNECTED) {
        HTTPClient https;
        https.begin(client, serverName);  

        int httpCode = https.GET();

        if (httpCode > 0) {
          String response = https.getString();
          Serial.println("✅Message sent! Server response:");
          Serial.println(response);
        } else {
          Serial.print("❌Failed to send message. Error: ");
          Serial.println(httpCode);
        }

        https.end();
      }

      messageSent = true;
    }

    if (reading == HIGH) {
      messageSent = false;
    }
  }

  lastButtonState = reading;
}
