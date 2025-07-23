# ESP8266 WiFi Projects

This repository contains three Arduino sketches designed for WiFi connectivity and secure communication using the ESP8266 microcontroller. These sketches demonstrate the use of WiFi connections, secure HTTPS requests, and WiFi credential management.

## 📁 Files Included

### 1. `WiFiManager.ino`
- A sketch to manage WiFi credentials on ESP8266.
- It automatically launches a configuration portal if the device cannot connect to a saved network.
- Built on the popular [WiFiManager](https://github.com/tzapu/WiFiManager) library.

### 2. `WiFiClientSecure.ino`
- Demonstrates how to make secure HTTPS requests using `WiFiClientSecure`.
- Connects to a remote server using TLS/SSL encryption.
- Useful for secure API communication or IoT projects requiring encrypted data.

### 3. `HTTPCLient.ino`
- A basic HTTP client example using the `HTTPClient` library.
- Sends GET/POST requests to remote HTTP servers.
- Great starting point for REST API integrations.

## 🛠 Requirements

- **Board**: ESP8266 (e.g., NodeMCU, Wemos D1 mini)
- **Arduino IDE** with the following installed:
  - ESP8266 Board Package
  - `WiFiManager` library
  - `ESP8266HTTPClient`
  - `WiFiClientSecure`

## 🔧 How to Use

1. Open any of the `.ino` files in the Arduino IDE.
2. Connect your ESP8266 board via USB.
3. Select the correct board and COM port from the **Tools** menu.
4. Upload the sketch to your device.
5. Open the Serial Monitor for debugging and logs.

## 📦 Installation Tips

To install `WiFiManager`:
- Go to **Sketch > Include Library > Manage Libraries...**
- Search for `WiFiManager` by **Tzapu** and install it.

## 📝 License

This project is open source and available under the [MIT License](LICENSE).

---

Feel free to fork, contribute, or raise issues.

