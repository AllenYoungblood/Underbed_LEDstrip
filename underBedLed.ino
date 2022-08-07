int lightSen = A5;    //analog input for photoresistor
int led = 10;         // this is the PWM pin for the LED strip
int brightness = 0;    // how bright the LED is on startup
int fadeAmount = 2;    // how many points to fade the LED by. hihger number causes faster fade

int inputPin = 8;               // choose the input pin (for PIR sensor)
int inputPinTwo = 7;            // a second PIR sensor can be set, if no sensor jump to ground using resistor
int pirState = LOW;             // we start, assuming no motion detected
int val = 0;                    // variable for reading the pin status
int valTwo = 0;                 // Second PIR sensor value if used
int lightLevel = 0;             // this is the value set by your photo resistor
 
void setup() {
  pinMode(led, OUTPUT);      // declare LED as output
  pinMode(inputPin, INPUT);     // declare sensor as input
 
  //Serial.begin(9600); //used for debug
}
 
void loop(){
  lightLevel = analogRead(lightSen);  //Read inputs
  val = digitalRead(inputPin); 
  valTwo = digitalRead(inputPinTwo);
  
  //Serial.println(lightLevel);
  
  if ((val == HIGH || valTwo == HIGH) && lightLevel <= 30) {  //if conditions are met,
    if (pirState == LOW) {                        
      //Serial.println("Motion detected!");
      //if (val == 1){
      //  Serial.println("Sensor 1 triggered");
      //} else {
      //  Serial.println("Sensor 2 triggered");
      //}
      fadeOn(true);
      pirState = HIGH;
    }
  val = digitalRead(inputPin);  // read input value
  valTwo = digitalRead(inputPinTwo);
  while ((val == HIGH || valTwo == HIGH) && lightLevel <= 30) {
    for (int i = 0; i <= 60; i++) {
      delay(1000);
      if (lightSen >= 50) {
        break; 
      }
    }
    val = digitalRead(inputPin);  // read input value
    valTwo = digitalRead(inputPinTwo);
  }
  //delay (3000);
  } else {
    if (pirState == HIGH){
      Serial.println("Motion ended!");
      fadeOn(false);
      pirState = LOW;
    }
  }
}

void fadeOn (bool desiredState) {   //fade on or off depending on bool state passed on. 
  if (desiredState == true) {       // fadeon(true) means the lights will fade on
    Serial.println("Light is Fading on");
    if (fadeAmount <= 1) {
      fadeAmount = -fadeAmount;
    }
    while (brightness < 100) {
      brightness = brightness + fadeAmount;
      analogWrite(led, brightness);
      delay(50);
      }
    delay(1000);  
  } else {
    Serial.println("Light is Fading off");
    if (fadeAmount > 0) {
      fadeAmount = -fadeAmount;
    }
    while (brightness >= 1) {
      brightness = brightness + fadeAmount;
      analogWrite(led, brightness);
      delay(50);
      }
    delay(1000);  
  }
}
