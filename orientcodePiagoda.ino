#include "Enes100.h"

// =========================
// MOTOR PINS
// =========================

// RIGHT SIDE (two motors)
// back right 
int ENA_RIGHT = 3;
int In1 = 4;
int In2 = 5;

// front right 
int ENB_RIGHT = 6;
int In3 = 7;
int In4 = 8;

// LEFT SIDE (two motors)
// back left 
int ENC_LEFT = 22;
int In5 = 24;
int In6 = 26;

// front left 
int In7 = 28;
int In8 = 30;
int END_LEFT = 32;

int SPEED = 210;

void stopMotor() {
  analogWrite(ENA_RIGHT, 0);
  analogWrite(ENB_RIGHT, 0);
  analogWrite(ENC_LEFT, 0);
  analogWrite(END_LEFT, 0);
}

void going_straight(char* direction, int time) {
  char* first;
  char* second;
  if (direction == "FORWARD") {
    first = HIGH;
    second = LOW;
  } else if (direction == "BACKWARD") {
    first = LOW;
    second = HIGH;
  }
  // RIGHT SIDE → forward
  digitalWrite(In1, first);
  digitalWrite(In2, second);
  digitalWrite(In3, first);
  digitalWrite(In4, second);

  analogWrite(ENA_RIGHT, SPEED);
  analogWrite(ENB_RIGHT, SPEED);

  // LEFT SIDE → forward
  digitalWrite(In5, first);
  digitalWrite(In6, second);
  digitalWrite(In7, first);
  digitalWrite(In8, second);

  analogWrite(ENC_LEFT, SPEED);
  analogWrite(END_LEFT, SPEED);

  delay(time);
  stopMotor();
}
// ======================================
// TURN RIGHT FUNCTION (time-based only)
// ======================================
void turnRightForTime(int turnTimeMs) {

    // Right turn = left wheels forward, right wheels backward
    digitalWrite(In1, LOW);
    digitalWrite(In2, HIGH);

    digitalWrite(In3, LOW);
    digitalWrite(In4, HIGH);

    digitalWrite(In5, HIGH);
    digitalWrite(In6, LOW);

    digitalWrite(In7, HIGH);
    digitalWrite(In8, LOW);

    analogWrite(ENA_RIGHT, SPEED);
    analogWrite(ENB_RIGHT, SPEED);
    analogWrite(ENC_LEFT, SPEED);
    analogWrite(END_LEFT, SPEED);

    delay(turnTimeMs);

    // STOP
    analogWrite(ENA_RIGHT, 0);
    analogWrite(ENB_RIGHT, 0);
    analogWrite(ENC_LEFT, 0);
    analogWrite(END_LEFT, 0);
}
void turnLeftForTime(int turnTimeMs) {

    // Right turn = right wheels forward, left wheels backward
    digitalWrite(In1, HIGH);
    digitalWrite(In2, LOW);

    digitalWrite(In3, HIGH);
    digitalWrite(In4, LOW);

    digitalWrite(In5, LOW);
    digitalWrite(In6, HIGH);

    digitalWrite(In7, LOW);
    digitalWrite(In8, HIGH);

    analogWrite(ENA_RIGHT, SPEED);
    analogWrite(ENB_RIGHT, SPEED);
    analogWrite(ENC_LEFT, SPEED);
    analogWrite(END_LEFT, SPEED);

    delay(turnTimeMs);

    // STOP
    analogWrite(ENA_RIGHT, 0);
    analogWrite(ENB_RIGHT, 0);
    analogWrite(ENC_LEFT, 0);
    analogWrite(END_LEFT, 0);
} 
void setup() {
    Enes100.begin("BATMAN", SEED, 316, 1116, 13, 12);
    Enes100.println("Connected...");
}

void loop() {

    Enes100.println("Requesting prediction...");
    int result = Enes100.MLGetPrediction(1);
    Enes100.println("ML predicts: " + String(result));

    // ===============================
    // MAP ML RESULT → TURN TIME (ms)
    // ===============================
    int turnTime = 0;

    if (result == 0) {
        Enes100.mission(LOCATION, 'A'); // orzo top left 
        going_straight("BACKWARD", 500);
        turnTime = 4270; // turn left for 4.3 sec
        turnLeftForTime(turnTime);
        going_straight("FORWARD", 2000); // go over planter  
    }
    else if (result == 1) { // orzo bottom left 
        Enes100.mission(LOCATION, 'B');
        going_straight("BACKWARD", 500); // go back before orienting 
        turnTime = 8540;   // 8.5 seconds 
        turnLeftForTime(turnTime); 
        going_straight("FORWARD", 2000); // go over planter  
    }
    else if (result == 2) { // orzo bottom right 
        Enes100.mission(LOCATION, 'C');
        going_straight("BACKWARD", 500); // go back before orienting 
        turnTime = 3770;   // 7.5 sec 
        turnRightForTime(turnTime); 
        going_straight("FORWARD", 2000); // go over planter  
    }
    else { // orzo top right 
        Enes100.mission(LOCATION, 'D');
        going_straight("BACKWARD", 500); // go back before orienting 
        turnTime = 7540;  // 7.5 seconds
        turnRightForTime(turnTime); 
        going_straight("FORWARD", 2000); // go over planter  
    }
    delay(2000);
}
