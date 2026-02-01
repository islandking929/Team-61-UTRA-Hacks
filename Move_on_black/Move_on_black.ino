#define enA 9
#define inA1 8
#define inA2 7

#define enB 6
#define inB1 5
#define inB2 4

const int pwm10 = 26;

void setup() {
  // put your setup code here, to run once:
  pinMode(enA, OUTPUT);
  pinMode(inA1, OUTPUT);
  pinMode(inA2, OUTPUT);

  pinMode(enB, OUTPUT);
  pinMode(inB1, OUTPUT);
  pinMode(inB2, OUTPUT);

  analogWrite(enA, pwm10);
  analogWrite(enB, pwm10);
  moveForward();
}

void loop() {
  // put your main code here, to run repeatedly:
  int color = getColor(5);
  if (color != 1) {
    brake();
    if (color == 0) {
      bool foundBlack = false;
      for (int i = 0; i < 3; i++) {
        moveLeft();
        delay(200);
        brake();
        color = getColor(5);
        if (color == 1) {
          foundBlack = true;
          break;
        }
      }
      if (!foundBlack) {
        moveRight();
        delay(600);
        brake();
        for (int i = 0; i < 3; i++) {
          moveRight();
          delay(200);
          brake();
          color = getColor(5);
          if (color == 1) {
            foundBlack = true;
            break;
          }
        }
      }
      if (foundBlack) {
        moveForward();
      }
    }
  } else if (color == 2) {

  } else if (color == 3) {

  }

}


void moveRightWheelClockwise() {
  digitalWrite(inA1, HIGH);
  digitalWrite(inA2, LOW);
}

void moveRightWheelCounterClockwise() {
  digitalWrite(inA1, LOW);
  digitalWrite(inA2, HIGH);
}

void moveLeftWheelClockwise() {
  digitalWrite(inB1, HIGH);
  digitalWrite(inB2, LOW);
}

void moveLeftWheelCounterClockwise() {
  digitalWrite(inB1, LOW);
  digitalWrite(inB2, HIGH);
}

void moveForward() {
  moveRightWheelCounterClockwise();
  moveLeftWheelCounterClockwise();
}

void moveLeft() {
  moveRightWheelClockwise();
  moveLeftWheelCounterClockwise();
}

void moveRight() {
  moveLeftWheelClockwise();
  moveRightWheelCounterClockwise();
}

void stop() {
  digitalWrite(inA1, LOW);
  digitalWrite(inA2, LOW);
 
  digitalWrite(inB1, LOW);
  digitalWrite(inB2, LOW);
}

void brake() {
  digitalWrite(inA1, HIGH);
  digitalWrite(inA2, HIGH);
 
  digitalWrite(inB1, HIGH);
  digitalWrite(inB2, HIGH);
}


int getColor(int reps) {
  int red = 0;
  int green = 0;
  int blue = 0;
  int black = 0;
  int white = 0;

  int R = 0;
  int G = 0;
  int B = 0;

  for (int i = 0; i < reps; i++) {
    digitalWrite(S2,LOW);
    digitalWrite(S3,LOW);
    R = map(pulseIn(sensorOut, LOW), 340, 40, 0, 255);
    delay(10);

    digitalWrite(S2, HIGH);
    digitalWrite(S3, HIGH);
    G = map(pulseIn(sensorOut, LOW), 310, 75, 0, 255);
    delay(10);

    digitalWrite(S2, LOW);
    digitalWrite(S3, HIGH);
    B = map(pulseIn(sensorOut, LOW), 290, 60, 0, 255);
    delay(10);
  }

  if (R >= 230 && G >= 230 && B >= 230) {
    white += 1;
  } else if (R <= 130 && G <= 130 && B <= 130) {
    black += 1;
  } else if (R > G && R > B) {
    red += 1;
  } else if (G > R && G > B) {
    green += 1;
  } else if (B > G && B > R) {
    blue += 1;
  }

  if (white > blue && white > green && white > black && white > red) {
    return 0;
  }
  if (black > blue && black > green && black > red && black > white) {
    return 1;
  }
  if (red > blue && red > green && red > black && red > white) {
    return 2;
  }
  if (green > blue && green > red && green > black && green > white) {
    return 3;
  }
  if (blue > red && blue > green && blue > black && blue > white) {
    return 4;
  }
  return 5;
}
