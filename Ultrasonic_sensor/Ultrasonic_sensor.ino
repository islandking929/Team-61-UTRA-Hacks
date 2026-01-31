#define Trig 10
#define Echo 11

float duration = 0;
float distance = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(Trig, OUTPUT);  
	pinMode(Echo, INPUT);  
	Serial.begin(9600);  
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Distance: ");  
	Serial.println(getUltrasonicDist());  
	delay(500);
}

float getUltrasonicDist() {
  digitalWrite(Trig, LOW);  
	delayMicroseconds(2);  
	digitalWrite(Trig, HIGH);  
	delayMicroseconds(10);  
	digitalWrite(Trig, LOW);

  duration = pulseIn(Echo, HIGH); 
  return (duration*0.0343)/2; 
}
