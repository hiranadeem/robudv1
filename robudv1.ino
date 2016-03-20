int motorLeft1 = 5;
int motorLeft2 = 6;
int motorRight1 = 9;
int motorRight2 = 10;
int sensorLeft, sensorRight;

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  pinMode(motorLeft1, INPUT);
  pinMode(motorRight1, INPUT);
  pinMode(motorLeft2, INPUT);
  pinMode(motorRight2, INPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
}

void loop() {
  while(true){
    sensorLeft = analogRead(A1);
    sensorRight = analogRead(A0);
    Serial.print("Sensor Left: ");
    Serial.print(sensorLeft);
    Serial.print("    ");
    Serial.print("Sensor Right: ");
    Serial.println(sensorRight);
    
    if (sensorLeft < 100) {
      analogWrite(motorLeft1, 100);   // turn the LED on (HIGH is the voltage level)
      delay(100);              // wait for a second
      analogWrite(motorLeft2, 0);    // turn the LED off by making the voltage LOW
      delay(100);     // wait for a second
      
      analogWrite(motorRight1, 49);   // turn the LED on (HIGH is the voltage level)
      delay(100);              // wait for a second
      analogWrite(motorRight2, 0);    // turn the LED off by making the voltage LOW
      delay(100); 
    }
    else if (sensorRight < 90) {
      analogWrite(motorLeft1, 49);   // turn the LED on (HIGH is the voltage level)
      delay(100);              // wait for a second
      analogWrite(motorLeft2, 0);    // turn the LED off by making the voltage LOW
      delay(100);     // wait for a second
      
      analogWrite(motorRight1, 100);   // turn the LED on (HIGH is the voltage level)
      delay(100);              // wait for a second
      analogWrite(motorRight2, 0);    // turn the LED off by making the voltage LOW
      delay(100); 
    }
    else {
      analogWrite(motorLeft1, 100);   // turn the LED on (HIGH is the voltage level)
      delay(100);              // wait for a second
      analogWrite(motorLeft2, 0);    // turn the LED off by making the voltage LOW
      delay(100);     // wait for a second
      
      analogWrite(motorRight1, 100);   // turn the LED on (HIGH is the voltage level)
      delay(100);              // wait for a second
      analogWrite(motorRight2, 0);    // turn the LED off by making the voltage LOW
      delay(100); 
    }
  }
}
