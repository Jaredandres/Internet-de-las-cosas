#include <ESP8266WiFi.h>

// Credenciales wifi

#define ssid "gissy_peace"
#define password "ola444444"
// server to connect to and relative path to PHP script
char server[] = "8080-jaredandres-internetdel-0xqomf9q5cm.ws-us77.gitpod.io";
String url = "/sensor1_temp";

bool iterar = true;

void setup()
{
  Serial.begin(9600);
  Serial.println();

  pinMode(0, INPUT_PULLUP);
  int valor = digitalRead(0);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(250);
  }
  Serial.print("\nConectado al Wi-Fi");
  Serial.println();
  Serial.println("Connecting to server...");
  Serial.println(server);
  WiFiClientSecure client;
  client.setInsecure();
  const int httpPort = 443;
  if (!client.connect(server, httpPort)) {
    Serial.println("connection failed");
    return;
  }

  Serial.print("Requesting URL: ");
  Serial.println(url);

  Serial.println(valor);
  client.print(String("GET ") + url + valor + " HTTP/1.1\r\n" +
               "Host: " + server + "\r\n" +
               "Connection: close\r\n\r\n");

  // Close connecting
  Serial.println();
  Serial.println("closing connection");
}

void loop() {
  int valor = digitalRead(0);
  Serial.println(valor);
  //client.print(String("GET ") + url + valor + " HTTP/1.1\r\n" +
               //"Host: " + server + "\r\n" +
               //"Connection: close\r\n\r\n");
} // End Loop
