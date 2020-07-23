
#define in 2
#define out 3
#include "Arduino.h"
#include "ACS712.h"

const int analogIn = A0;
int mVperAmp = 185; // use 100 for 20A Module and 66 for 30A Module
int RawValue= 0;
int ACSoffset = 2500;
double Voltage = 0;
double Amps = 0;
double power = 0;


int count=0;

void setup()
{
  Serial.begin(9600);
  Serial.print("Visitor Counter");
  delay(2000);
  pinMode(in, INPUT);
  pinMode(out, INPUT);
  Serial.flush();
  Serial.print("Person In Room:");
  //Serial.setCursor(0,1);
  Serial.print(count);
}

void loop()
{  
  int in_value = digitalRead(in);
  int out_value = digitalRead(out);
  if(in_value == LOW)
  {
    count++;
    Serial.flush();
    Serial.print("Person In Room:");
    //Serial.setCursor(0,1);
    Serial.print(count);
    delay(1000);
  }
  
  if(out_value == LOW)
  {
    count--;
    Serial.flush();
    Serial.print("Person In Room:");
    //Serial.setCursor(0,1);
    Serial.print(count);
    delay(1000);
  }

  if(count==0)
  {
    RawValue = analogRead(analogIn);
    Voltage = (RawValue / 1023.0) * 5000; // Gets you mV
    Amps = ((Voltage - ACSoffset) / mVperAmp);
    power = Voltage * Amps;


    //Serial.print("Raw Value = " ); // shows pre-scaled value
    //Serial.print(RawValue);
    //Serial.print("\t mV = "); // shows the voltage measured
    //Serial.print(Voltage,3); // the '3' after voltage allows you to display 3 digits after decimal point
    //Serial.print("\t Amps = "); // shows the voltage measured
    //Serial.println(Amps,3); // the '3' after voltage allows you to display 3 digits after decimal point
    Serial.println(power);
    delay(2500);

  }
}
  
