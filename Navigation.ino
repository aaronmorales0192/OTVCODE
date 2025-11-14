#include "Enes100.h";

int ENA_RIGHT = 3;
int In1 = 4;
int In2 = 5;


int SPEED = 210;

int ENB_RIGHT = 6;
int In3 = 7;
int In4 = 8;

int ENC_LEFT = 22;
int In5 = 24; 
int In6 = 26;

int In7 = 28;
int In8 = 30;
int END_LEFT = 32;

void pinSetup(){
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  pinMode(ENA_RIGHT, OUTPUT);
  pinMode(In3, OUTPUT);
  pinMode(In4, OUTPUT);
  pinMode(ENB_RIGHT, OUTPUT);

  pinMode(In5, OUTPUT);
  pinMode(In6, OUTPUT);
  pinMode(ENC_LEFT, OUTPUT);
  pinMode(In7, OUTPUT);
  pinMode(In8, OUTPUT);
  pinMode(END_LEFT, OUTPUT);
}

void stopMotor() {
  analogWrite(ENA_RIGHT, 0);
  analogWrite(ENB_RIGHT, 0);
  analogWrite(ENC_LEFT, 0);
  analogWrite(END_LEFT, 0);
}

void going_straight(int time) {


  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);
  digitalWrite(In3, HIGH);
  digitalWrite(In4, LOW);
  analogWrite(ENA_RIGHT,SPEED);
  analogWrite(ENB_RIGHT,SPEED);

//

 
  digitalWrite(In5, HIGH);
  digitalWrite(In6, LOW);
  digitalWrite(In7, HIGH);
  digitalWrite(In8, LOW);
  analogWrite(ENC_LEFT,SPEED);
  analogWrite(END_LEFT,SPEED);
  delay(time);
  analogWrite(ENA_RIGHT, 0);
  analogWrite(ENB_RIGHT, 0);
  analogWrite(ENC_LEFT, 0);
  analogWrite(END_LEFT, 0);
}

void turn(char* direction, int time) {
  char main;
  char second;
  if (*direction == "RIGHT") {
    main = "HIGH";
    second = "LOW";
  } else {
    main = "LOW";
    second = "HIGH";
  }

  digitalWrite(In1, main);
  digitalWrite(In2, second);
  digitalWrite(In3, second);
  digitalWrite(In4, main);
  analogWrite(ENA_RIGHT,SPEED);
  analogWrite(ENB_RIGHT,SPEED);

//



  digitalWrite(In5, main);
  digitalWrite(In6, second);
  digitalWrite(In7, second);
  digitalWrite(In8, main);
  analogWrite(ENC_LEFT,SPEED);
  analogWrite(END_LEFT,SPEED);
  delay(time);
  analogWrite(ENA_RIGHT, 0);
  analogWrite(ENB_RIGHT, 0);
  analogWrite(ENC_LEFT, 0);
  analogWrite(END_LEFT, 0);
}

void setup () {
  delay(1000);
  Enes100.begin("BATMAN",SEED, 534, 1116, 10, 11);
  delay(1000);
  Enes100.println("Connected...");
  pinSetup();
  going_straight(2000);
  turn("RIGHT", 1000);
  float angle = Enes100.getTheta();
  if (Enes100.getY() > 1){
      if (angle < -1.57079632679){
        stopMotor();
      }
  } else {
    if (Enes100.getTheta() > 1.57079632679){
      stopMotor();
    }
  }
  going_straight(10000);
  delay("10000");
  // turn("LEFT", 1000);
}


void loop(){}
