/*
  Titre      : Projet Python et AHT20
  Auteur     : Duvalier Tsagmo
  Date       : 14/10/2022
  Description: la temperature et l'humiditer de mon AHT20 va etre stocker dans la base de donnee de Python
  Version    : 0.0.1
*/

// les include du projet
#include <Arduino.h>
#include <Adafruit_AHTX0.h>

// Declaration des mes variables
Adafruit_AHTX0 aht;

// ma fonction setup
void setup()
{
    Serial.begin(9600);
}

// mon loop
void loop()
{
    sensors_event_t humidity, temp;
    aht.getEvent(&humidity, &temp); // remplir les objets de température et d'humidité avec de nouvelles données
    Serial.print(temp.temperature);
    Serial.print("x");
    Serial.println(humidity.relative_humidity);
}