// Set the pin number where the PIR motion sensor is connected
int IRpin = 2;
int pirPin = 8;
int buzzer = 9; 
int relayPin = 6;
int testPin = 7;
int previousState;
// Set the delay time for detecting no motion (in milliseconds)
int noMotionDelay = 1000; // 5 seconds


void setup() {
  // Initialize serial communication at 9600 bits per second
  Serial.begin(9600);
  // Set the PIR motion sensor pin as input
  pinMode(buzzer, OUTPUT); // Set buzzer - pin 9 as an output
pinMode(IRpin, INPUT_PULLUP);
  pinMode(pirPin, INPUT);
  pinMode(relayPin, OUTPUT);
  pinMode(testPin, OUTPUT);

}

void loop() {
  // Read the value of the PIR motion sensor
  int pirValue = digitalRead(pirPin);

  if(previousState != digitalRead(IRpin)){
    tone(buzzer, 1000);
    if(digitalRead(IRpin) == HIGH){
      digitalWrite(relayPin, HIGH);
      Serial.println("Relay is turned on");
    }else{
         digitalWrite(relayPin, LOW);
           Serial.println("Relay is turned off");
    }
     previousState = digitalRead(IRpin);
    Serial.println("Change triggered");

  }
  // If the PIR motion sensor detects motion, print a message to the serial monitor
  if (pirValue == HIGH) {
     Serial.println("Motion detected!");
    if(digitalRead(IRpin) == LOW){
    tone(buzzer, 1000);
    }else{
      Serial.println("The module is turned off");
    }
  }
  else {
      Serial.println("No motion detected.");
  }

  // Delay for 100 milliseconds

delay(1000);
noTone(buzzer);

Serial.println("Cycle passed!");

}
