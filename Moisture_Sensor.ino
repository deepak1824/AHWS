/*************************************************************************/
/* Company           :   CTI One Corporation                             */
/* Coded by          :   Deepak Shivani, Embedded & DLE                  */
/* Date              :   08/02/2019                                      */  
/* Purpose           :   Master Code for the project Automated Indoor Herb station */
/*************************************************************************/
  
  #define RELAY1  7   // defining pin number for Pump.
  #define RELAY2  6   // defining pin number for Lamp
  int val1 = 0;       //value for storing moisture value1
  int val2 = 0;       //value for storing moisture value2
  //int val3 = 0;       //value for storing moisture value3
  int soilPin1 = A0;  //Declare a variable1 for the soil moisture sensor
  int soilPin2 = A1;  //Declare a variable2 for the soil moisture sensor 
  //int soilPin3 = A2;  //Declare a variable3 for the soil moisture sensor 
   
  int soilPower1 = 8; //Variable for Soil moisture Power1
  int soilPower2 = 9; //Variable for Soil moisture Power2
  //int soilPower3 = 10;  //Variable for Soil moisture Power3
  
  //Rather than powering the sensor through the 3.3V or 5V pins, 
  //we'll use a digital pin to power the sensor. This will 
  //prevent corrosion of the sensor as it sits in the soil. 
  
  void setup() 
  {
    Serial.begin(9600);   //Used for serial communication.(Printing anything on serial monitor)
    
    pinMode(RELAY1, OUTPUT);  //Set Pump as output
    pinMode(RELAY2, OUTPUT);  //set Lamp as output
    pinMode(3, INPUT);        //Set switch to control lamp
    pinMode(soilPower1, OUTPUT);  //Set D7 as an OUTPUT
    pinMode(soilPower2, OUTPUT);  //Set D8 as an OUTPUT
    //pinMode(soilPower3, OUTPUT);  //Set D9 as an OUTPUT
    digitalWrite(soilPower1, LOW);  //Set to LOW so no power is flowing through the sensor
    digitalWrite(soilPower2, LOW);  //Set to LOW so no power is flowing through the sensor
    //digitalWrite(soilPower3, LOW);  //Set to LOW so no power is flowing through the sensor
  }
  
  void loop() 
  {
    int switchval = digitalRead(3); // Read the switch value
    if(switchval == 1 ){
    digitalWrite(RELAY2, 0);        // Turns on Relay 2
    Serial.println("Lamp OFF");
    }else{// wait for a second
    digitalWrite(RELAY2, 1);        // Turns OFF Relay 2
    Serial.println("Lamp ON");
    }
    Serial.print("Soil Moisture 1 = ");    
    Serial.println(readSoil1()); //get soil moisture value1 from the function below and print it
  
    Serial.print("Soil Moisture 2 = ");    
    Serial.println(readSoil2()); //get soil moisture value2 from the function below and print it
  /*
    Serial.print("Soil Moisture 3 = ");    
    Serial.println(readSoil3()); //get soil moisture value3 from the function below and print it
  
    */  
  //This 1 second timefrme is used so you can test the sensor and see it change in real-time.
  //For in-plant applications, you will want to take readings much less frequently.
  
    delay(1000); //take a reading every second
  }
  
  //This is a function used to get the soil moisture 1 content
  int readSoil1()
  {
    digitalWrite(soilPower1, HIGH); //turn D8 "On"
    delay(10);//wait 10 milliseconds 
    val1 = analogRead(soilPin1);  //Read the SIG value form sensor 
    if (val1 <= 350){
      digitalWrite(RELAY1,0);           // Turns ON Relay 1
      Serial.println("Pump OFF");
      delay(1000);
  }
    else{
      digitalWrite(RELAY1,1);          // Turns Relay 1 Off
      Serial.println("Pump ON");
      delay(1000);
  }
      digitalWrite(soilPower1, LOW);//turn D8 "Off"
      return val1;//send current moisture value
  }
  
  //This is a function used to get the soil moisture 2 content
  int readSoil2()
  {
  
      digitalWrite(soilPower2, HIGH); //turn D9 "On"
      delay(10);//wait 10 milliseconds 
      val2 = analogRead(soilPin2);  //Read the SIG value form sensor 
      if (val2 <= 400){
        digitalWrite(RELAY1,0);           // Turns ON Relays 1
        Serial.println("Pump OFF");
        delay(1000);
  }else{
        digitalWrite(RELAY1,1);          // Turns Relay 1 Off
        Serial.println("Pump ON");
        delay(1000);
  }
      digitalWrite(soilPower2, LOW);//turn D9 "Off"
      return val2;//send current moisture value
  }
  
  //This is a function used to get the soil moisture 3 content
  /*
  int readSoil3()
  {
  
      digitalWrite(soilPower3, HIGH);//turn D10 "On"
      delay(10);//wait 10 milliseconds 
      val3 = analogRead(soilPin3);//Read the SIG value form sensor 
      if (val3 <= 400){
        digitalWrite(RELAY1,0);           // Turns ON Relays 1
        Serial.println("Pump OFF");
        delay(5000);
        }else {
          digitalWrite(RELAY1,1);          // Turns Relay 1 Off
          Serial.println("Pump ON");
          delay(5000);
          }
      digitalWrite(soilPower3, LOW);//turn D10 "Off"
      return val3;//send current moisture value
  }*/
