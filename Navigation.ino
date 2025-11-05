int ENA = 3;
int In1 = 4;
int In2 = 5;


int SPEED = 210;

int ENB = 6;
int In3 = 7;
int In4 = 8;

int ENC = 22;
int In5 = 24; 
int In6 = 26;

int In7 = 28;
int In8 = 30;
int END = 32;

void going_straight(int time) {

  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(In3, OUTPUT);
  pinMode(In4, OUTPUT);
  pinMode(ENB, OUTPUT);

  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);
  digitalWrite(In3, HIGH);
  digitalWrite(In4, LOW);
  analogWrite(ENA,SPEED);
  analogWrite(ENB,SPEED);

//

  pinMode(In5, OUTPUT);
  pinMode(In6, OUTPUT);
  pinMode(ENC, OUTPUT);
  pinMode(In7, OUTPUT);
  pinMode(In8, OUTPUT);
  pinMode(ENB, OUTPUT);

  digitalWrite(In5, HIGH);
  digitalWrite(In6, LOW);
  digitalWrite(In7, HIGH);
  digitalWrite(In8, LOW);
  analogWrite(ENC,SPEED);
  analogWrite(END,SPEED);
  delay(time);
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  analogWrite(ENC, 0);
  analogWrite(END, 0);
}

void turn(char* direction, int time) {
  char main;
  char second;
  if (*direction == "RIGHT") {
    main = "HIGH";
    main = "LOW";
  } else {
    main = "LOW";
    second = "HIGH";
  }
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(In3, OUTPUT);
  pinMode(In4, OUTPUT);
  pinMode(ENB, OUTPUT);

  digitalWrite(In1, main);
  digitalWrite(In2, second);
  digitalWrite(In3, second);
  digitalWrite(In4, main);
  analogWrite(ENA,SPEED);
  analogWrite(ENB,SPEED);

//

  pinMode(In5, OUTPUT);
  pinMode(In6, OUTPUT);
  pinMode(ENC, OUTPUT);
  pinMode(In7, OUTPUT);
  pinMode(In8, OUTPUT);
  pinMode(ENB, OUTPUT);

  digitalWrite(In5, main);
  digitalWrite(In6, second);
  digitalWrite(In7, second);
  digitalWrite(In8, main);
  analogWrite(ENC,SPEED);
  analogWrite(END,SPEED);
  delay(time);
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  analogWrite(ENC, 0);
  analogWrite(END, 0);
}
void setup () {
  going_straight(2000);
  turn("RIGHT", 1000);
  // turn("LEFT", 1000);
}

void loop(){}