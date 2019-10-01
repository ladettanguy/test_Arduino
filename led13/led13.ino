void setup() {
  // put your setup code here, to run once:
  pinMode (13, OUTPUT);
  pinMode (12, OUTPUT);
  pinMode (11, OUTPUT);
  pinMode (10, OUTPUT);
  Serial.begin(9600);
  Serial.setTimeout(10);
}

void loop()
{
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0)
  {
    String myData = Serial.readStringUntil("\n");
    if (myData != "")
    {
      // Si myData n'est pas vide
      if (myData != "")
      {
        if (myData.substring(0, 2) == "10")
        {
          // commande de la LED13

          digitalWrite(13, LOW);
        }
        if (myData.substring(0, 2) == "11")
        {
          //Allumer la led

          digitalWrite(13, HIGH);
        }

        // Commande de la LED12


        if (myData.substring(0, 2) == "21")
        {
          //Allumer la led

          digitalWrite(12, HIGH);
        }
        if (myData.substring(0, 2) == "20")
        {

          digitalWrite(12, LOW);
        }

        // commande de la LED11
        if (myData.substring(0, 2) == "31")
        {
          //Allumer la led

          digitalWrite(11, HIGH);
        }

        if (myData.substring(0, 2) == "30")
        {

          digitalWrite(11, LOW);
        }

        if (myData.substring(0, 2) == "41")
        {
          //Allumer la led

          digitalWrite(10, HIGH);
        }

        if (myData.substring(0, 2) == "40")
        {

          digitalWrite(10, LOW);
        }

        Serial.print(myData);
        
        if (myData.substring(0, 1) == "s")
        {
          int led13 = digitalRead(13);
          Serial.print("1");
          Serial.print(led13);
          int led12 = digitalRead(12);
          Serial.print("2");
          Serial.print(led12);
          int led11 = digitalRead(11);
          Serial.print("3");
          Serial.print(led11);
          int led10 = digitalRead(10);
          Serial.print("4");
          Serial.println(led10);
        }

        myData = "";
        //Serial.print("\n");
      }
    }
  }


}
