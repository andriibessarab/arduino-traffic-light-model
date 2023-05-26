const unsigned short t1Pins[] = {5, 6, 7};
const unsigned short t2Pins[] = {2, 3, 4};
const unsigned short streetLightsPins[] = {10, 11, 12, 13};
const unsigned short buttonPin = 8;
const unsigned short switchPin = 9;
const unsigned short photocellPin = A0;

int buttonReading;
int switchReading;
int photocellReading;

int switchHigh;  // state when switch will be consdierered on


// Method: setup()
// Description: Initializes the pins and sets the initial state of the switch.
void setup() {
  // Set data rate for serial monitor
  Serial.begin(9600);

  // Configure PIN behaviour for traffic light LEDs
  for (int i = 0; i < 3; i++) {
    pinMode(t1Pins[i], OUTPUT);
    pinMode(t2Pins[i], OUTPUT);
  }
  
  // Configure PIN behaviour for street light LEDs
  for (int i = 0; i < 3; i++) {
    pinMode(t1Pins[i], OUTPUT);
    pinMode(t2Pins[i], OUTPUT);
  }

  // Configure input PIN behaviours
  pinMode(switchPin, INPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(photocellPin, INPUT);
  
  // Set state at which switch is considered on
  switchHigh = digitalRead(switchPin);
}


// Method: loop()
// Description: The main loop that checks the state of the switch and button to perform specific actions.
void loop() {
  // Take & store readings
  switchReading = digitalRead(switchPin);
  buttonReading = digitalRead(buttonPin);
  photocellReading = analogRead(photocellPin);
  
 // Determine dimness
  if (photocellReading < 250) {
    streetLightsOn();  // turn on street lights
  } else {
  	streetLightsOff();  // turn off street lights
  }

  // Check if switch is off
  if (switchReading != switchHigh) {
    nightCycle();   // run night cycle
  } else {
    // Check if button is pressed
    if (buttonReading == HIGH) { 
      turnLeftCycle();  // run turn left cycle
    } else {
      defaultCycle();  // run day cycle
    }
  }
}


// Method: defaultCycle()
// Description: Performs the default cycle of the LEDs.
void defaultCycle() {
  digitalWrite(t1Pins[0], HIGH);
  digitalWrite(t2Pins[2], HIGH);
  delay(9000);
  digitalWrite(t2Pins[2], LOW);

  digitalWrite(t2Pins[1], HIGH);
  delay(3000);
  digitalWrite(t2Pins[1], LOW);

  digitalWrite(t2Pins[0], HIGH);
  delay(2000);
  digitalWrite(t1Pins[0], LOW);

  digitalWrite(t1Pins[2], HIGH);
  delay(9000);
  digitalWrite(t1Pins[2], LOW);

  digitalWrite(t1Pins[1], HIGH);
  delay(3000);
  digitalWrite(t1Pins[1], LOW);

  digitalWrite(t1Pins[0], HIGH);
  delay(2000);
  digitalWrite(t2Pins[0], LOW);
  digitalWrite(t1Pins[0], LOW);
}


// Method: nightCycle()
// Description: Performs the night cycle of the LEDs.
void nightCycle() {
  digitalWrite(t1Pins[0], HIGH);
  digitalWrite(t2Pins[0], HIGH);
  delay(4000);

  digitalWrite(t1Pins[0], LOW);
  digitalWrite(t2Pins[0], LOW);
  delay(4000);
}


// Method: turnLeftCycle()
// Description: Performs the turn left cycle of the LEDs.
void turnLeftCycle() {
  digitalWrite(t2Pins[0], HIGH);

  for (short i = 0; i < 5; i++) {
    digitalWrite(t1Pins[2], HIGH);
    delay(1000);
    digitalWrite(t1Pins[2], LOW);
    delay(1000);
  }

  digitalWrite(t2Pins[0], LOW);
}


// Method: streetLightsOn()
// Description: Turns on street light LEDs.
void streetLightsOn() {
  for(short i = 0; i < 4; i++) {
    digitalWrite(streetLightsPins[i], HIGH);
  }
}


// Method: streetLightsOff()
// Description: Turns off street light LEDs.
void streetLightsOff() {
  for(short i = 0; i < 4; i++) {
    digitalWrite(streetLightsPins[i], LOW);
  }
}
