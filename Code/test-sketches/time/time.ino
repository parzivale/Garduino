#include <Time.h>
#include <TimeLib.h>

void setup(){
    Serial.begin(9600);
}

void loop(){
    time_t t;
    t = now();

    Serial.println(hour(t));
}