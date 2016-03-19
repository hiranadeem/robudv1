int motorLeft1 = 5;
int motorLeft2 = 6;
int motorRight1 = 10;
int motorRight2 = 11;

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  pinMode(motorLeft1, INPUT);
  pinMode(motorRight1, INPUT);
  pinMode(motorLeft2, INPUT);
  pinMode(motorRight2, INPUT);
}

void loop() {
  digitalWrite(motorLeft1,100);
  delay(1000);
  digitalWrite(motorLeft2,100);
  delay(1000);
  
  digitalWrite(motorRight1,100);
  delay(1000);
  digitalWrite(motorRight2,100);
  delay(1000);

}
