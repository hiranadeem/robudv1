int motorLeft1 = 5;
int motorLeft2 = 6;
int motorRight1 = 9;
int motorRight2 = 10;

int sensorLeft, sensorRight;

int trigPin = 11;    //Trig - green Jumper
int echoPin = 12;    //Echo - blue Jumper
long duration, cm, inches;

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  pinMode(motorLeft1, INPUT);//set up motors
  pinMode(motorRight1, INPUT);
  pinMode(motorLeft2, INPUT);
  pinMode(motorRight2, INPUT);
  pinMode(A0, INPUT);//set up photoresistor analog input
  pinMode(A1, INPUT);
  pinMode(trigPin, OUTPUT);//set up ultrasonic sensor
  pinMode(echoPin, INPUT);
}

void loop() {
  
  while(true){
    sensorLeft = analogRead(A1);//continuously read photoresistors
    sensorRight = analogRead(A0);
    Serial.print("Sensor Left: ");
    Serial.print(sensorLeft);
    Serial.print("    ");
    Serial.print("Sensor Right: ");
    Serial.println(sensorRight);
    
    // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
    // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
    digitalWrite(trigPin, LOW);
    delayMicroseconds(5);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
   
    // Read the signal from the sensor: a HIGH pulse whose
    // duration is the time (in microseconds) from the sending
    // of the ping to the reception of its echo off of an object.
    pinMode(echoPin, INPUT);
    duration = pulseIn(echoPin, HIGH);
   
    // convert the time into a distance
    inches = (duration/2) / 74; 
    
    if (sensorLeft < 100) {
      analogWrite(motorLeft1, 200);   // turn the LED on (HIGH is the voltage level)
      delay(100);              // wait for a second
      analogWrite(motorLeft2, 0);    // turn the LED off by making the voltage LOW
      delay(100);     // wait for a second
      
      analogWrite(motorRight1, 100);   // turn the LED on (HIGH is the voltage level)
      delay(100);              // wait for a second
      analogWrite(motorRight2, 0);    // turn the LED off by making the voltage LOW
      delay(100); 
    }
    else if (sensorRight < 90) {
      analogWrite(motorLeft1, 100);   // turn the LED on (HIGH is the voltage level)
      delay(100);              // wait for a second
      analogWrite(motorLeft2, 0);    // turn the LED off by making the voltage LOW
      delay(100);     // wait for a second
      
      analogWrite(motorRight1, 200);   // turn the LED on (HIGH is the voltage level)
      delay(100);              // wait for a second
      analogWrite(motorRight2, 0);    // turn the LED off by making the voltage LOW
      delay(100); 
    }
    else if (inches < 5) {
      analogWrite(motorLeft1, 0);   // turn the LED on (HIGH is the voltage level)
      delay(1000);              // wait for a second
      analogWrite(motorLeft2, 0);    // turn the LED off by making the voltage LOW
      delay(1000);     // wait for a second
      
      analogWrite(motorRight1, 0);   // turn the LED on (HIGH is the voltage level)
      delay(1000);              // wait for a second
      analogWrite(motorRight2, 0);    // turn the LED off by making the voltage LOW
      delay(1000); 
    }
    else {
      analogWrite(motorLeft1, 200);   // turn the LED on (HIGH is the voltage level)
      delay(100);              // wait for a second
      analogWrite(motorLeft2, 0);    // turn the LED off by making the voltage LOW
      delay(100);     // wait for a second
      
      analogWrite(motorRight1, 200);   // turn the LED on (HIGH is the voltage level)
      delay(100);              // wait for a second
      analogWrite(motorRight2, 0);    // turn the LED off by making the voltage LOW
      delay(100); 
    }
  }
}
