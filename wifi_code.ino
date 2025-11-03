#include "Enes100.h";
unsigned long pMillis = 0;
const long interval = 1000;

void setup() {
  delay(1000);
  
  Enes100.begin("BATMAN",SEED, 328, 1116, 11, 10);
  delay(1000);
  Enes100.println("Connected...");
 // pinMode(9,OUTPUT); //this tells the Arduino that I want to use digital pin 9 as an output, or a power supply, not as a sensor
}

void loop() {
  unsigned long cMillis = millis();
  if (cMillis - pMillis >= interval){
    pMillis = cMillis;
    float Xcord = Enes100.getX();
    float Ycord = Enes100.getY();
    float angle = Enes100.getTheta();
    
    //Enes100.print("Location is :");
    //Enes100.print(Xcord);
    //Enes100.print(", ");
    //Enes100.print(Ycord);
    //Enes100.print(", ");
    //Enes100.print(angle);
    Enes100.mission(LOCATION, 'A');
  }
  delay(3000); 
}


