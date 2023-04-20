#include "thingProperties.h"
int ledPin = 23;

void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500); 
  

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);

  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();
}

void onLedChange()  {
  if(led == 1){
    digitalWrite(ledPin, HIGH);
    Serial.println("ON");
  }
  else{
    digitalWrite(ledPin, LOW);
  }
}
