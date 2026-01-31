#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 9

int R = 0;
int G = 0;
int B = 0;

int white=0;
int black=0;
int blue =0;
int red = 0;
int green =0;

void setup() {
  // put your setup code here, to run once:
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  
  // Setting frequency-scaling to 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  
  Serial.begin(9600);

}

void loop() {
  white = 0;
  black = 0;
  red = 0;
  blue = 0;
  green = 0;
  // put your main code here, to run repeatedly:
    // Setting red filtered photodiodes to be read
  while (white + black+red+blue+green < 5) {

  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  // Reading the output frequency
  R = pulseIn(sensorOut, LOW);
  R = map(R, 340, 40, 0, 255);
  // Printing the value on the serial monitor
 // Serial.print("R= ");//printing name
  //Serial.print(R);//printing RED color frequency
  //Serial.print("  ");
  delay(100);

  // Setting Green filtered photodiodes to be read
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  G = pulseIn(sensorOut, LOW);
  G = map(G, 310, 75, 0, 255);
  // Printing the value on the serial monitor
  //Serial.print("G= ");//printing name
  //Serial.print(G);//printing RED color frequency
  //Serial.print("  ");
  delay(100);

  // Setting Blue filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  B = pulseIn(sensorOut, LOW);
  B = map(B, 290, 60, 0, 255);
  // Printing the value on the serial monitor
  //Serial.print("B= ");//printing name
  //Serial.print(B);//printing RED color frequency
  //Serial.println("  ");
  delay(100);

if (R >= 230 && G >= 230 && B >= 230) {
  white += 1;
} else if (R <= 130 && G <= 130 && B <= 130) {
  black += 1;
} else if (R > G && R> B) {
  red += 1;
  } 
  else if (G > R && G> B) {
  green += 1;
  }
  else if (B > G && B> R) {
  blue += 1;
   }

  }
  if (red > white && red > blue && red > green & red > black) {
    Serial.println("Red");

  }
Serial.println(" ");
}

// int getColor() {
//   int red = 0;
//   int green = 0;
//   int blue = 0;
//   int black = 0;
//   int white = 0;

//   for (int i = 0; i < 5; i++) {
//     digitalWrite(S2,LOW);
//     digitalWrite(S3,LOW);
//     R = map(pulseIn(sensorOut, LOW), 340, 40, 0, 255);
//     delay(100);

//     digitalWrite(S2, HIGH);
//     digitalWrite(S3, HIGH);
//   }
// }

//pure black on the target reads around 340 red, 310 green, 290 blue
//pure black on the straight ramp reads 280 red, 260 green and 240 blue
//dark blue on the target reads 230 red, 130 green and 70-79 blue
//red on the target reads 60 red, 167 green, and 144 blue
//green on the target reads 136 red, 77 green and 106 blue
//light blue (Although there is only a small fraction of the blue ring) reads 180 red, 100 green and 60 blue
//pure white on the boards reads 27 red, 28 green and 25 blue
//path red reads 40-50 red, 160 green and 130-140 blue
//Path black reads 210 red, 240-250 green, and 230 blue
//path green reads 150 red, 80 green and 133 blue
//when measuring the blue on the path, it reads 180-190 red, 130 green and 85 blue


