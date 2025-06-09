/*
Engineering 103H Final Project by Cooper Mack
Inspired by "Night Light Fright" from Mario Party
*/
#include <Adafruit_CircuitPlayground.h>
#include <cmath>

// variables declared
const int switchPin = 7;
const int LeftButton = 4;
const int RightButton = 5;
volatile bool SwitchFlag = false;
volatile bool ButtonFlag = false;
float enemyPosition = 1;
float lowTime = 1;
float highTime = 10;
float highScore = 10;


void switchISR(){ // flag is changed when the switch is flipped
  SwitchFlag = true;
}

void buttonISR(){ // flag is changed when button is pressed
  ButtonFlag = true;
}

void setup() { // runs once when plugged in
  Serial.begin(9600);
  CircuitPlayground.begin();
// input setup
  pinMode(switchPin, INPUT_PULLUP);
  pinMode(LeftButton, INPUT_PULLDOWN);
  pinMode(RightButton, INPUT_PULLDOWN);
  attachInterrupt(digitalPinToInterrupt(switchPin), switchISR, CHANGE);
  attachInterrupt(digitalPinToInterrupt(LeftButton), buttonISR, FALLING);
  attachInterrupt(digitalPinToInterrupt(RightButton), buttonISR, FALLING);
}

void loop(){ // runs indefinitely
  if (SwitchFlag){ // when the switch is flipped, run startGame()
    startGame();
  }
}
// plays the game
void startGame() { 
// if player presses the button, game ends and score is saved
  if (ButtonFlag) { 
    CircuitPlayground.playTone(500, 1000);
    lowTime = 0;
    highTime = 0;
    Serial.print("You Win! It was ");
    Serial.print((90 - enemyPosition)/10);
    Serial.println(" meters away!");
    if((90 - enemyPosition)/10 < highScore){
      highScore = (90 - enemyPosition)/10;
      Serial.println("New High Score!");
    }
    delay(10000);
    SwitchFlag = false;
    for (int i = 0; i<10; i++){
      CircuitPlayground.setPixelColor(i, 0, 0, 0);
    }
    enemyPosition = 1;
    lowTime = 1;
    highTime = 10;
    ButtonFlag = false;
  }
// game initialization
  CircuitPlayground.setPixelColor(9, 0, 255, 0);
  CircuitPlayground.setPixelColor(round(enemyPosition/10),255,255,255);
  enemyPosition = enemyPosition + random(lowTime,highTime);
// if enemy reaches character, game ends
  if (enemyPosition >= 90){ 
    Serial.println("You lose!");
    CircuitPlayground.playTone(500, 1000);
    CircuitPlayground.setPixelColor(9, 255, 0, 0);
    lowTime = 0;
    highTime = 0;
    delay(10000);
    SwitchFlag = false;
    for (int i = 0; i<10; i++){
      CircuitPlayground.setPixelColor(i, 0, 0, 0);
    }
    enemyPosition = 1;
    lowTime = 1;
    highTime = 10;
  }
  delay(1000); 
}




