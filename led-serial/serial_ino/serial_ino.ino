int ledPin = 13;   // select the pin for the LED
int val = 0;       // variable to store the data from the serial port

void setup() {
  pinMode(ledPin,OUTPUT);    // declare the LED's pin as output
  Serial.begin(57600);        // connect to the serial port
}

void loop () {
  val = Serial.read();      // read the serial port
  // if the stored value is a single-digit number, blink the LED that number
  if (val > '0' && val <= '9' ) {
    val = val - '0';          // convert from character to number
    for (int i=0; i<val; i++) {
      digitalWrite(ledPin,HIGH);
      delay(150);
      digitalWrite(ledPin, LOW);
      delay(150);
    }
  }
}
