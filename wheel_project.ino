#include <Adafruit_CircuitPlayground.h>

float X;
int lightDelay = 250;
int frame1, frame2;
int readingDelay = 500;
int x1, x2, buttonState1, buttonState2; 
int button1 = 19;
int button2 = 4;

void setup() {
  Serial.begin(9600);
  CircuitPlayground.begin();

}

void loop() {
  turnOff();
  buttonState1 = digitalRead(button1);
  buttonState2 = digitalRead(button2);
  Serial.print("READINGGGGGGGG");
  Serial.println(buttonState1);
  
  if(buttonState1 == 1 || buttonState2 == 1) {
    delay(15);
    buttonState1 = digitalRead(button1);
    buttonState2 = digitalRead(button2);
    Serial.print("ONNNNNNNN");
    Serial.println(buttonState1);

    while(buttonState1 == 0 && buttonState2 == 0) {
      X = CircuitPlayground.motionX();
      Serial.print("  X: ");
      Serial.println(X);
      buttonState1 = digitalRead(button1);
      buttonState2 = digitalRead(button2);

      Serial.print("buttonState1 is: ");
      Serial.println(buttonState1);

      frame1 = CircuitPlayground.motionX();
      x1 = CircuitPlayground.motionX();
      delay(5);
      x2 = CircuitPlayground.motionX();
      delay(20);
      frame2 = CircuitPlayground.motionX();
    
      if (frame1 == frame2) {
        turnRed();
      }
      else if (x2-x1<0 && X<0 ) {
        turnYellow();
        Serial.print("YELLOW");
        delay(lightDelay);
      }
      else if (x2-x1>0 && X>0) {
        turnGreen();
        Serial.print("GREEN");
        delay(lightDelay);
      }
      else if (x2-x1<0 && X>0) {
        turnBlue();
        Serial.print("BLUE");
        delay(lightDelay);
      }
      else if(x2-x1 && X<0) {
        turnPurple();
        Serial.print("PURPLE");
        delay(lightDelay);;
      }
    }
  }
}

void turnGreen(void) {
  CircuitPlayground.setPixelColor(1, 0, 255, 0);
  CircuitPlayground.setPixelColor(2, 0, 255, 0);
  CircuitPlayground.setPixelColor(3, 0, 255, 0);
  CircuitPlayground.setPixelColor(4, 0, 255, 0);                  //green
  CircuitPlayground.setPixelColor(5, 0, 255, 0);
  CircuitPlayground.setPixelColor(6, 0, 255, 0);
  CircuitPlayground.setPixelColor(7, 0, 255, 0);
  CircuitPlayground.setPixelColor(8, 0, 255, 0);
  CircuitPlayground.setPixelColor(9, 0, 255, 0);
}

void turnBlue(void) {
  CircuitPlayground.setPixelColor(1, 0, 0, 255);
  CircuitPlayground.setPixelColor(2, 0, 0, 255);
  CircuitPlayground.setPixelColor(3, 0, 0, 255);
  CircuitPlayground.setPixelColor(4, 0, 0, 255);                  //blue
  CircuitPlayground.setPixelColor(5, 0, 0, 255);
  CircuitPlayground.setPixelColor(6, 0, 0, 255);
  CircuitPlayground.setPixelColor(7, 0, 0, 255);
  CircuitPlayground.setPixelColor(8, 0, 0, 255);
  CircuitPlayground.setPixelColor(9, 0, 0, 255);
}

void turnPurple(void) {
  CircuitPlayground.setPixelColor(1, 80, 0, 80);
  CircuitPlayground.setPixelColor(2, 80, 0, 80);
  CircuitPlayground.setPixelColor(3, 80, 0, 80);                 //purple
  CircuitPlayground.setPixelColor(4, 80, 0, 80);
  CircuitPlayground.setPixelColor(5, 80, 0, 80);
  CircuitPlayground.setPixelColor(6, 80, 0, 80);
  CircuitPlayground.setPixelColor(7, 80, 0, 80);
  CircuitPlayground.setPixelColor(8, 80, 0, 80);
  CircuitPlayground.setPixelColor(9, 80, 0, 80);
}

void turnRed(void) {
  CircuitPlayground.setPixelColor(1, 255, 0, 0);
  CircuitPlayground.setPixelColor(2, 255, 0, 0);
  CircuitPlayground.setPixelColor(3, 255, 0, 0);                   //red
  CircuitPlayground.setPixelColor(4, 255, 0, 0);
  CircuitPlayground.setPixelColor(5, 255, 0, 0);
  CircuitPlayground.setPixelColor(6, 255, 0, 0);
  CircuitPlayground.setPixelColor(7, 255, 0, 0);
  CircuitPlayground.setPixelColor(8, 255, 0, 0);
  CircuitPlayground.setPixelColor(9, 255, 0, 0);
}

void turnYellow(void) {
  CircuitPlayground.setPixelColor(1, 255, 255, 0);
  CircuitPlayground.setPixelColor(2, 255, 255, 0);
  CircuitPlayground.setPixelColor(3, 255, 255, 0);                   //yellow
  CircuitPlayground.setPixelColor(4, 255, 255, 0);
  CircuitPlayground.setPixelColor(5, 255, 255, 0);
  CircuitPlayground.setPixelColor(6, 255, 255, 0);
  CircuitPlayground.setPixelColor(7, 255, 255, 0);
  CircuitPlayground.setPixelColor(8, 255, 255, 0);
  CircuitPlayground.setPixelColor(9, 255, 255, 0);
}

void turnOff(void) {
  CircuitPlayground.setPixelColor(1, 0, 0, 0);
  CircuitPlayground.setPixelColor(2, 0, 0, 0);
  CircuitPlayground.setPixelColor(3, 0, 0, 0);                   //red
  CircuitPlayground.setPixelColor(4, 0, 0, 0);
  CircuitPlayground.setPixelColor(5, 0, 0, 0);
  CircuitPlayground.setPixelColor(6, 0, 0, 0);
  CircuitPlayground.setPixelColor(7, 0, 0, 0);
  CircuitPlayground.setPixelColor(8, 0, 0, 0);
  CircuitPlayground.setPixelColor(9, 0, 0, 0);
}

