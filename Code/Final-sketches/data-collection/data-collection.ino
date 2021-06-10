#include <SPI.h>
#include <SD.h>
#include <dht.h>

#define dht_apin A0
#define moisture_apin A1
#define Moisture_min 10
#define Moisture_max 550

int moisture;
File myFile;
dht DHT;

void setup()
{
    Serial.begin(9600);
    delay(500);
    if (!SD.begin(4))
    {
        Serial.println("initialization failed!");
        while (1)
            ;
    }
    if (!SD.exists("potData.csv"))
    {
        Serial.println("Couldnt find pot_data.csv");
        myFile = SD.open("potData.csv", FILE_WRITE);
        Serial.println("");
        if (myFile)
        {
            myFile.println("Temperature,Humidity,Moisture");
            myFile.close();
        }
    }
    for(int i=0; i < 10; i++){
    myFile = SD.open("potData.csv", FILE_WRITE);
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
    myFile.println(moisture);

    myFile.close();

    Serial.println("data written...");
    delay(500);
    }    
}

void loop()
{   

}