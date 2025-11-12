// back left wheel pin
int ENA = 3;
int In1 = 4;
int In2 = 5;




int SPEED = 210;
// front left wheel pin
int ENB = 6;
int In3 = 7;
int In4 = 8;


int ENC = 22;
int In5 = 24;
int In6 = 26;


int In7 = 28;
int In8 = 30;
int END = 32;


void setup ()
{


  //back left wheel


  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  pinMode(ENA, OUTPUT);


  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);


  analogWrite(ENA,SPEED);


 // front left wheel
  pinMode(In3, OUTPUT);
  pinMode(In4, OUTPUT);
  pinMode(ENB, OUTPUT);


  digitalWrite(In3, HIGH);
  digitalWrite(In4, LOW);


  analogWrite(ENB,SPEED);


//
 //
  pinMode(In5, OUTPUT);
  pinMode(In6, OUTPUT);
  pinMode(ENC, OUTPUT);


  digitalWrite(In5, HIGH);
  digitalWrite(In6, LOW);


  analogWrite(ENC,SPEED);




  pinMode(In7, OUTPUT);
  pinMode(In8, OUTPUT);
  pinMode(ENB, OUTPUT);


  digitalWrite(In7, HIGH);
  digitalWrite(In8, LOW);


  analogWrite(END,SPEED);
 
}


void loop(){}
