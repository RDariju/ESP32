#include <WiFiManager.h>
#include <HTTPClient.h>
#include <WiFiClientSecure.h>

void setup() {
  Serial.begin(115200);
  delay(1000);

  WiFiManager wm;
  wm.autoConnect("ESP-Google");

  Serial.println("Connected to WiFi!");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\n Enter message (sent to Google Sheets):");

    while (Serial.available() == 0) {
      delay(100);
    }

    String userInput = Serial.readStringUntil('\n');
    userInput.trim();

    String json = "{\"message\": \"" + userInput + "\"}";

    WiFiClientSecure client;
    client.setInsecure();  // WARNING: disables SSL verification (OK for testing)

    HTTPClient https;
    https.begin(client,"https://script.google.com/macros/s/AKfycbwoM4xhu3NCIxm9p-BFpCtl9eOP061tvNTSLpUFld5NP5iZDtcRHwrrZIhc-8lIMLLaig/exec");  // Replace with your full script URL
    https.addHeader("Content-Type", "application/json");

    int res = https.POST(json);

    if (res > 0) {
      String reply = https.getString();
      Serial.println("Google Sheets Response: " + reply);
    } else {
      Serial.print("HTTPS Error: ");
      Serial.println(res);
    }

    https.end();
  } else {
    Serial.println("WiFi not connected.");
  }

  delay(5000);
}
