#include <ESP8266WiFi.h>
#include <WiFiClient.h>
 
// WiFi information
const char WIFI_SSID[] = "ESPap";
const char WIFI_PSK[] = "thereisnospoon";
 
// Remote site information
const char http_site[] = "192.168.4.1";
const int http_port = 80;

// Global variables
WiFiClient client;
int pos;
bool flag;
char result[4]; //este array cubre incluso si T>=100
 
void setup() {
  
  // Set up serial console to read web page
  Serial.begin(9600);
  
  // Connect to WiFi
  connectWiFi();
  
  // Attempt to connect to website
  if ( !getPage() ) {
    Serial.println("GET request failed");
  }
}
 
void loop() {
  
  // If there are incoming bytes, print them
  if ( client.available() ) {
    char c = client.read();
    //Serial.print(c);
    if(c=='~') {
      flag = true;
    }
    else if(flag) {
      result[pos++] = c;
    }
  }

  //"cierro" el array
  result[pos] = '\0';
  
  // If the server has disconnected, stop the client and WiFi
  if ( !client.connected() ) {

    Serial.print(result);

    // Close socket and wait for disconnect from WiFi
    client.stop();
    if ( WiFi.status() != WL_DISCONNECTED ) {
      WiFi.disconnect();
    }

    connectWiFi();
    
    if ( !getPage() ) {
      Serial.println("GET request failed");
    }
  }
}
 
// Attempt to connect to WiFi
void connectWiFi() {
  
  // Set WiFi mode to station (client)
  WiFi.mode(WIFI_STA);
  
  // Initiate connection with SSID and PSK
  WiFi.begin(WIFI_SSID, WIFI_PSK);
  
  // Blink LED while we wait for WiFi connection
  while ( WiFi.status() != WL_CONNECTED ) {
    //Serial.print(".");
    delay(500);
  }
}
 
// Perform an HTTP GET request to a remote page
bool getPage() {
  
  // Attempt to make a connection to the remote server
  if ( !client.connect(http_site, http_port) ) {
    return false;
  }
  
  // Make an HTTP GET request
  client.println("GET / HTTP/1.1");
  client.print("Host: ");
  client.println(http_site);
  client.println("Connection: close");
  client.println();

  //Initializing the variables
  pos = 0;
  flag = false;
  result[4] = {0};
  
  return true;
}
