# define sensor1 7
# define sensor2 8
# define ball_size 1000000000 // in nm

void setup() {
	pinMode(sensor1, INPUT);
	pinMode(sensor2, INPUT);
	Serial.begin(9600);
}

void loop() {
	while(digitalRead(sensor1)) {}
	unsigned long t1 = millis();
	while(!digitalRead(sensor1)) {}
	Serial.print("v1 = "); Serial.print(ball_size / (millis() - t1)); Serial.println("nm/ms");

	while(digitalRead(sensor2)) {}
	unsigned long t2 = millis();
	while(!digitalRead(sensor2)) {}
	Serial.print("v2 = "); Serial.print(ball_size / (millis() - t2)); Serial.println("nm/ms");
}

