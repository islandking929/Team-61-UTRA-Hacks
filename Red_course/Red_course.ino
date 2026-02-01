void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  while (checkDistance() < ...) {
    moveAStep();
  }
  turnLeft(90);
  while 
}

//nextTurnDir: true for right, false for left 
void moveAStep(int pathColor, bool nextTurnRight) {
  if (getColor() == pathColor) {
    delay(100);
    return;
  } else {
    brake();
  }
  if (nextTurnRight) {
    while (getColor() != pathColor) {
      turnRight(10);
    }
    turnRight(20);
    return;
  } else {
    while (getColor() != pathColor) {
      turnLeft(10);
    }
    turnleft(20);
    return;
  }
}

void checkDistance 
