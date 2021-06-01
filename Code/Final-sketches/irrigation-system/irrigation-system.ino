#include <SPI.h>
#include <SD.h>
#include <Time.h>
#include <dht.h>

float temperature, humidity = 10.0;
int moisture, nowTime = 10;
File myFile;

void setup()
{
    Serial.begin(9600);
    if (!SD.begin(10))
    {
        Serial.println("initialization failed!");
        while (1)
            ;
    }

    if (!SD.exists("data.csv"))
    {
        myFile = SD.open("data.csv", FILE_WRITE);
        if(myFile){
           myFile.print("temperature,humidiity,moisture");
        }
    }
    else
    {
        myFile = SD.open("data.csv", FILE_WRITE);
    }
    if (myFile)
    {
        Serial.print("Writing data...");

        myFile.print(temperature);
        myFile.print(",");
        myFile.print(humidity);
        myFile.print(",");
        myFile.print(moisture);

        Serial.println("closing file");
        myFile.close();
    }
}

void loop()
{
}