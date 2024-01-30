# define sensor1 7
# define sensor2 8
# define Coil 9
# define ball_size 10000000 // in nm

void setup() {
	pinMode(sensor1, INPUT);
	pinMode(sensor2, INPUT);
  pinMode(Coil, OUTPUT);
	Serial.begin(9600);
  millis();
}

void loop() {
  Serial.println(digitalRead(sensor1));
	while(digitalRead(sensor1)) {}
  digitalWrite(Coil, HIGH);
	unsigned long t1 = millis();
	while(!digitalRead(sensor1)) {}
  delay(300);
  digitalWrite(Coil, LOW);
	Serial.print("v1 = "); Serial.print(ball_size / (millis() - t1)); Serial. println("µm/s");
	while(digitalRead(sensor2)) {}
	unsigned long t2 = millis();
	while(!digitalRead(sensor2)) {}
	Serial.print("v2 = "); Serial.print(ball_size / (millis() - t2)); Serial.println("µm/s");
}
