String inData = "";
const int buttonPin = 2;
const int ledPin = 10;
int buttonState = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.setTimeout(10);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  while (Serial.available() > 0)
  {
    //string inData=Serial.readStringUntil('\n');
      char recieved=Serial.read();
      if (recieved != '\n') inData += recieved;
      if (recieved == '\n')
      {
        if (inData == "1") digitalWrite(ledPin,HIGH);
        if (inData == "0") digitalWrite(ledPin,LOW);
        Serial.println(inData);
        inData="";
      }
  }
  if(buttonState != digitalRead(buttonPin))
  {
    if(!digitalRead(buttonPin)) Serial.println("2");
    else Serial.println("3");
    buttonState=digitalRead(buttonPin);
  }
}

