#include <SPI.h>
#include <SD.h>

float hum_data = 0.0;
float temp_data = 0.0;

File myFile;
File myFile2;
void setup()
{
    // Open serial communications and wait for port to open:
    Serial.begin(9600);
    while (!Serial)
    {
        ; // wait for serial port to connect. Needed for native USB port only
    }
    Serial.print("Initializing SD card...");
    if (!SD.begin(10))
    {
        Serial.println("initialization failed!");
        while (1);
    }
    Serial.println("initialization done.");
    // open the file. note that only one file can be open at a time,
    // so you have to close this one before opening another.
    myFile = SD.open("data.txt", FILE_WRITE);
    // if the file opened okay, write to it:
    if (myFile)
    {
        Serial.print("Writing data...");
        //myFile.println("%f, ", hum_data);
        for (int i = 0; i < 200; i++)
        {
            hum_data = hum_data + 1;
            myFile.println(hum_data);
        }
        myFile.close();
    }
    else
    {
        // if the file didn't open, print an error:
        Serial.println("error opening data.txt");
    }

}
void loop()
{
    // nothing happens after setup
}
