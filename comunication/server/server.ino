#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>

/* Set these to your desired credentials. */
const char *ssid = "ESPap";
const char *password = "thereisnospoon";

char data[5] = {'~'}; //este array es incluso para T>=100
int pos = 1;

ESP8266WebServer server(80);

/* Just a little test message.  Go to http://192.168.4.1 in a web browser
 * connected to this access point to see it.
 */
void handleRoot() {
  server.send(200, "text/html", data);
}

void setup() {
  delay(1000);
  Serial.begin(9600);
  //Serial.println();
  //Serial.print("Configuring access point...");
  /* You can remove the password parameter if you want the AP to be open. */
  WiFi.softAP(ssid, password);

  IPAddress myIP = WiFi.softAPIP();
  //Serial.print("AP IP address: ");
  //Serial.println(myIP);
  server.on("/", handleRoot);
  server.begin();
  //Serial.println("HTTP server started");
}

void loop() {
  if (Serial.available() > 0) {
    while (Serial.available() > 0) {
        data[pos++] = Serial.read();
    }
  }
  data[pos] = '\0';
  server.handleClient();
  pos = 1;
  delay(1000);
}
