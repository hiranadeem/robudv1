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


  while(true){
    sensorLeft = analogRead(A1);
    sensorRight = analogRead(A0);
      Serial.print("Sensor Left: ");
      Serial.print(sensorLeft);
      Serial.print("    ");
      Serial.print("Sensor Right: ");
      Serial.println(sensorRight);
    if (sensorLeft < 300) {
      analogWrite(motorRight1,100);
      delay(1000);
      analogWrite(motorRight2,100);
      delay(1000);
    }
    else if (sensorRight < 300) {
      analogWrite(motorLeft1,100);
      delay(1000);
      analogWrite(motorLeft2,100);
      delay(1000);
    }
    else {
      analogWrite(motorLeft1,1);//lower = faster
      delay(1000);
      analogWrite(motorLeft2,1);
      delay(1000);
      analogWrite(motorRight1,1);
      delay(1000);
      analogWrite(motorRight2,1);
      delay(1000);
    }

  }
}
