# define sensor1 7
# define sensor2 8
# define coil 9
# define DUR 100ul
# define ball_size 1000000000 // in nm

void setup() {
	pinMode(coil, OUTPUT);
	pinMode(sensor1, INPUT);
	pinMode(sensor2, INPUT);
}

void loop() {
	unsigned long t2;
	bool s1Done = false;
	bool s2Started = false;
	bool s2Done = false;

	while(digitalRead(sensor1)) {}
	unsigned long t1 = millis();
	digitalWrite(coil, HIGH);

	while(millis() - DUR <= t1) {
		if(digitalRead(sensor1)) {s1Done = true; Serial.print("v1 = "); Serial.print(ball_size / (millis() - t1); Serial.println("nm/ms");}
		if(!digitalRead(sensor2)) {t2 = millis(); s2Started = true;} else if(s2Started) {Serial.print("v2 = "); Serial.print(ball_size / (millis() - t2); Serial.println("nm/ms"); s2Done = true;}
	}
	digitalWrite(coil, LOW);

	if(!s1Done) {while(!digitalRead(sensor1)) {}; Serial.print("v1 = "); Serial.print(ball_size / (millis() - t1); Serial.println("nm/ms");}
	if(!s2Started) {while(digitalRead(sensor2)) {}; t2 = millis();}
	if(!s2Done) {while(!digitalRead(sensor2)) {}; Serial.print("v2 = "); Serial.print(ball_size / (millis() - t1); Serial.println("nm/ms");}
}



