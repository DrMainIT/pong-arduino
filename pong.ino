#include <WebSocketsClient.h>
#include <ESP8266WiFi.h>

const char* ssid = "WIFI_NETWORK";
const char* password = "wifiPassword";
const char* websocket_server = "192.168.1.10"; // IP del server WebSocket
const uint16_t websocket_port = 8765;

WebSocketsClient webSocket;

#define BUTTON_PIN4 4
#define BUTTON_PIN13 13


void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("Waitting");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi");

  webSocket.begin(websocket_server, websocket_port, "/");
  webSocket.onEvent(webSocketEvent);
  pinMode(BUTTON_PIN4, INPUT_PULLUP);
  pinMode(BUTTON_PIN13, INPUT_PULLUP);
}

void loop() {
  webSocket.loop();

  // Invia un messaggio ogni 2 secondi
  static unsigned long lastTime = 0;
  if (millis() - lastTime > 50) {
    lastTime = millis();
    byte buttonState13 = digitalRead(BUTTON_PIN13);
    byte buttonState4 = digitalRead(BUTTON_PIN4);
    String message; 
    String downValue;
    String upValue;
    if(buttonState4 == 0){
        downValue = "1";
    }else{
        downValue = "0";
    }
    if(buttonState13 == 0){
      upValue = "1";
    }else{
      upValue = "0";
    }

    message = "{\"moveDown\":" + downValue + ",\"moveUP\":" + upValue + "}"; 
    //Serial.println("This is the message" +  message);
    webSocket.sendTXT(message);
  }
}

void webSocketEvent(WStype_t type, uint8_t * payload, size_t length) {
  switch (type) {
    case WStype_DISCONNECTED:
      Serial.println("Disconnected");
      break;
    case WStype_CONNECTED:
      Serial.println("Connected to WebSocket server");
      break;
    case WStype_TEXT:
      Serial.printf("Received text: %s\n", payload);
      break;
  }
}