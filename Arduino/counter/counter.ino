
#define in 2
#define out 3

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
  
}
  
