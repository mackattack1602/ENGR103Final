#include <Adafruit_CircuitPlayground.h>
#include <cmath>

const int switchPin = 7;
const int LeftButton = 4;
const int RightButton = 5;
volatile bool SwitchFlag = false;
volatile bool ButtonFlag = false;
float enemyPosition = 1;
int lowTime = 1;
int highTime = 10;

void switchISR(){
  SwitchFlag = true;
}

void buttonISR(){
  ButtonFlag = true;
}


void setup() {
  Serial.begin(9600);
  CircuitPlayground.begin();
  pinMode(switchPin, INPUT_PULLUP);
  pinMode(LeftButton, INPUT_PULLDOWN);
  pinMode(RightButton, INPUT_PULLDOWN);
  attachInterrupt(digitalPinToInterrupt(switchPin), switchISR, CHANGE);
  attachInterrupt(digitalPinToInterrupt(LeftButton), buttonISR, FALLING);
  attachInterrupt(digitalPinToInterrupt(RightButton), buttonISR, FALLING);
}

void loop() {
  if (SwitchFlag){
    startGame();
  }
}

void startGame() {
  if (ButtonFlag){
    lowTime = 0;
    highTime = 0;
    Serial.println((90 - enemyPosition)/10);
    ButtonFlag = false;
  }
  CircuitPlayground.setPixelColor(9, 0, 255, 0);
  CircuitPlayground.setPixelColor(round(enemyPosition/10),255,255,255);
  enemyPosition = enemyPosition + random(lowTime,highTime);
  delay(1000); 
}

