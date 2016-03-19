int motorLeft1 = 5;
int motorLeft2 = 6;
int motorRight1 = 10;
int motorRight2 = 11;
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
  sensorLeft = analogRead(A1);
  sensorRight = analogRead(A0);

  while(true){
    if (sensorLeft < 300) {
      digitalWrite(motorRight1,100);
      delay(1000);
      digitalWrite(motorRight2,100);
      delay(1000);
    }
    else if (sensorRight < 300) {
      digitalWrite(motorLeft1,100);
      delay(1000);
      digitalWrite(motorLeft2,100);
      delay(1000);
    }
    else {
      digitalWrite(motorLeft1,1);//lower = faster
      delay(1000);
      digitalWrite(motorLeft2,1);
      delay(1000);
      digitalWrite(motorRight1,1);
      delay(1000);
      digitalWrite(motorRight2,1);
      delay(1000);
    }
      Serial.print("Sensor Left: ");
      Serial.print(sensorLeft);
      Serial.print("    ");
      Serial.print("Sensor Right: ");
      Serial.println(sensorRight);
  }
}
