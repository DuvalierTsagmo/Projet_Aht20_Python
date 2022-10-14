/*
  Titre      : Projet Python et AHT20
  Auteur     : Duvalier Tsagmo
  Date       : 14/10/2022
  Description: la temperature et l'humiditer de mon AHT20 va etre stocker dans la base de donnee de Python
  Version    : 0.0.1
*/


#include <Arduino.h>
#include <Adafruit_AHTX0.h>

Adafruit_AHTX0 aht;

void setup() {
  Serial.begin(9600);
}

void loop() {
  
  sensors_event_t humidity, temp;
  aht.getEvent(&humidity, &temp);// populate temp and humidity objects with fresh data

  Serial.print(temp.temperature); 
  Serial.print("x"); 
  Serial.println(humidity.relative_humidity); 

}