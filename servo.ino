#include <Servo.h>

Servo myServo;



void setup() {

  delay(500);        // let power settle

  myServo.attach(9); // signal on D9

  myServo.write(90); // neutral

  delay(500);

}



void loop() {

  for (int pos = 90; pos <= 180; pos++) {

    myServo.write(pos);

    delay(15);

  }

  delay(500);

  for (int pos = 180; pos >= 90; pos--) {

    myServo.write(pos);

    delay(15);

  }

  delay(500);

}


