#define Trig 10
#define Echo 11

//NOTE: based on minimal testing, ultrasonic sensor seems to overestimate by <=1cm
//dead zone seems to be <5cm so not useful. Doesnt work past 2.74 meters, at 1.4m is +-3cm and a bit unreliable/inconsistent

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

	//write if statement for if getutlrasonicdist <10, turn whatever
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
