#include <WiFiManager.h>    // WiFi Manager
#include <HTTPClient.h>     // For HTTP POST (built-in)

  const char* ssid="Dialog 4G 622";
  const char* password = "A18D81C1";
void setup() {
  Serial.begin(115200);
  delay(1000);

  // Start WiFiManager
  WiFiManager wifiManager;
  bool res = wifiManager.autoConnect(ssid,password);
  if(!res){
    Serial.println("Not Connected to WiFi!");
  }else{
    Serial.println("Connected to WiFi!");
  }
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("Enter temperature value (°C):");
    
    // Wait for user input via Serial
    while (Serial.available() == 0) {
      delay(100);
    }

    String tempValue = Serial.readStringUntil('\n');
    tempValue.trim();  // remove newline/space

    // HTTP POST request to mock API
    HTTPClient http;
    http.begin("https://postman-echo.com/post"); // Replace with your URL
    http.addHeader("Content-Type", "application/json");

    // Create JSON payload
    String jsonPayload = "{\"temperature\": \"" + tempValue + "\"}";

    int httpResponseCode = http.POST(jsonPayload);

    if (httpResponseCode > 0) {
      String response = http.getString();
      Serial.println("Server Response:");
      Serial.println(response);
    } else {
      Serial.print("Error Code: ");
      Serial.println(httpResponseCode);
    }

    http.end();
  } else {
    Serial.println("WiFi not connected!");
  }

  delay(5000);  // wait before asking again
}
