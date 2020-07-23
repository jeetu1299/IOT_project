#define ir 2
void setup()
{
  pinMode(ir, INPUT);
  Serial.begin(9600);
}

void loop() 
{
  int val = digitalRead(ir);
  Serial.println("value = "+val);
  delay(1000);
}
