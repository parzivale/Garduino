#include <SPI.h>
#include <SD.h>
#include <dht.h>

#define dht_apin A0
#define moisture_apin A0
#define Moisture_min 10
#define Moisture_max 550

int moisture;
File myFile;
dht DHT;

void setup()
{
    Serial.begin(9600);
    delay(500);
    if (!SD.begin(10))
    {
        Serial.println("initialization failed!");
        while (1);
    }
    if (!SD.exists("data.csv"))
    {
        myFile = SD.open("data.csv", FILE_WRITE);
        if (myFile)
        {
            myFile.print("Temperature,Humidity,Moisture");
        }
    }
    else
    {
        myFile = SD.open("data.csv", FILE_WRITE);
    }
}

void loop()
{

    if (myFile)
    {

        Serial.print("Reading DHT device... ");
        DHT.read11(dht_apin);
        Serial.println("Read DHT device succsefully");

        Serial.print("Reading Moisture Sensor...");
        int output_value = analogRead(moisture_apin);
        moisture = map(output_value, Moisture_max, Moisture_min, 0, 100);
        Serial.println("Sensor read Correctly");

        Serial.print("Current humidity = ");
        Serial.print(DHT.humidity);
        Serial.print("%  ");
        Serial.print("temperature = ");
        Serial.println(DHT.temperature);

        Serial.print("Current moisture = ");
        Serial.print(moisture);
        Serial.println("%");

        Serial.print("Writing data... ");

        myFile.print(DHT.temperature);
        myFile.print(",");
        myFile.print(DHT.humidity);
        myFile.print(",");
        myFile.print(moisture);

        Serial.println("closing file");
        myFile.close();
    }
    delay(1000);
}