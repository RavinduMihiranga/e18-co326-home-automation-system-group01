// Libraries
#include <DHT.h>
#include <ESP8266WiFi.h>
#include<time.h>
#include "NTPClient.h"
#include "WiFiUdp.h"

// Constants
#define DHTPIN D2            // Pin connected to DHT sensor
#define light D4
#define DHTTYPE DHT21        // DHT 21 (AM2301)

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", utcOffsetInSeconds);

void setup() {
  Serial.begin(SERIAL_BAUD);
  dht.begin();
  pinMode(light, OUTPUT);
  pinMode(DHTPIN, INPUT);
  pinMode(LDR_PIN,INPUT);
  digitalWrite(light, HIGH);// intialy light set to off

   timeClient.begin();
}


float get_farenheit(float celcius){
  return (celcius * 9/5 ) + 32 ;
}

void loop() {



  timeClient.update();

 //calculate timestamp
  unsigned long now = millis();
  if (now - lastMsg > 5000) {
  lastMsg = now;



  int ldrValue = readLDRValue();    // Call the function to read LDR value
  float humidity = readHumidity();  // Call the function to read humidity value
  float temperature = readTemperature();  // Call the function to read temperature value



  displayLDRValue(ldrValue);        // Call the function to display LDR value
  displayHumidity(humidity);        // Call the function to display humidity value
  displayTemperature(temperature);  // Call the function to display temperature value
  displayIntensity(Iluminance);  // Call the function to display temperature value


   float farenheit = get_farenheit(temperature) ;







  delay(2000);  // Delay 2 seconds
}
}
