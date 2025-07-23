#include<WiFiManager.h>
  const char* ssid="Dialog 4G 622";
  const char* password = "A18D81C1";
void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("\nStarting wifi Manager on ESP23 c6...");

  //Creating wifimanger object
  WiFiManager wm;

  bool res;
  res = wm.autoConnect(ssid,password);
  if(!res){
    Serial.println("Failed to connect");
    ESP.restart();
  }else{
    Serial.println("Connected.");
    Serial.print("IP: ");
    Serial.println(WiFi.localIP());
  }
  
}

void loop() {
  
}
