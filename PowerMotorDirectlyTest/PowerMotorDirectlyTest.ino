int ledPin = 13;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  //SweepAnalogWrite();
  ManualPWM();
  
  //TestLEDBlink();
}

void ManualPWM()
{
  int period = 10; //10 ms
  int onPeriod = 0;
  int offPeriod = 0;
  
  int incomingByte = 8;
  
  while (incomingByte != 999)
  {
    for (int x = 0; x < 10; x++)
    {
      Serial.println(x);
      for (int y = 0; y < 1000; y ++)
      {
        onPeriod = x;
        offPeriod = period - onPeriod;
        digitalWrite(A3, HIGH);
        delay(onPeriod);
        digitalWrite(A3, LOW);
        delay(offPeriod);
      }
    }
    
    for (int x = 10; x > 0; x--)
    {
      Serial.println(x);
      for (int y = 0; y < 1000; y ++)
      {
        onPeriod = x;
        offPeriod = period - onPeriod;
        digitalWrite(A3, HIGH);
        delay(onPeriod);
        digitalWrite(A3, LOW);
        delay(offPeriod);
      }
      
    }
     
    /*
    if (Serial.available() > 0)
    {
      incomingByte = Serial.read();
    }
    */
    
    
  }
}
void SweepAnalogWrite()
{
  for (int x = 0; x < 255; x++) 
  {
      analogWrite(A3, x);
      Serial.println(x);
      delay(50);
  }
  for (int x = 255; x > 0; x--)
  {
    analogWrite(A3, x);
    Serial.println(x);
    delay(50);
  }
}

void TestLEDBlink()
{
  digitalWrite(ledPin, HIGH);
  delay(500);
  digitalWrite(ledPin, LOW);
  delay(500);
}
