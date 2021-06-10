#include <SPI.h>
#include <dht.h>

#define dht_apin A0
#define moisture_apin A1
#define Moisture_min 10
#define Moisture_max 550

int moisture;
dht DHT;

int time_to_water = 0;

void setup()
{
    Serial.begin(9600);
    delay(500);
   
}

void loop()
{

    Serial.print("Reading DHT device... ");
    DHT.read11(dht_apin);
    Serial.println("Read DHT device succsefully");

    Serial.print("Reading Moisture Sensor...");
    int output_value = analogRead(moisture_apin);
    moisture = map(output_value, Moisture_max, Moisture_min, 0, 100);
    Serial.println("Sensor read Correctly");


    delay(1000);
}