/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-joystick
 */

#define VRX_PIN  A5 // Arduino pin connected to VRX pin
#define VRY_PIN  A4 // Arduino pin connected to VRY pin
// #define PRESSURE_PIN A3
#define HIT_PIN 3

#define LEFT_SLOW "left_slow"
#define LEFT_MEDIUM "left_medium"
#define LEFT_FAST "left_fast"

#define RIGHT_SLOW "right_slow"
#define RIGHT_MEDIUM "right_medium"
#define RIGHT_FAST "right_fast"

#define HIT_SLOW "hit_slow"
#define HIT_MEDIUM "hit_medium"
#define HIT_FAST "hit_fast"

int yValue = 0; // To store value of the Y axis

int pressureValue;
int initialPressureValue;
int pressureDifference;

void setup() {
  Serial.begin(9600) ;

  initialPressureValue = analogRead(PRESSURE_PIN);

}

void loop() {

  // Serial.println(initialPressureValue);
  pressureValue = analogRead(PRESSURE_PIN) - initialPressureValue;
  while(pressureValue <= 10){
    // Serial.println(pressureValue);
    yValue = analogRead(VRY_PIN);
    if(yValue >= 550 && yValue < 707){
      Serial.println(LEFT_SLOW);
      delay(500);
    }
    else if(yValue >= 707 && yValue < 864){
      Serial.println(LEFT_MEDIUM);
      delay(500);
    }
    else if(yValue >= 864 && yValue < 1023){
      Serial.println(LEFT_FAST);
      delay(500);
    }
    else if(yValue <= 500 && yValue > 334){
      Serial.println(RIGHT_SLOW);
      delay(500);
    }
    else if(yValue <= 334 && yValue > 168){
      Serial.println(RIGHT_MEDIUM);
      delay(500);
    }
    else if(yValue <= 168 && yValue > 0){
      Serial.println(RIGHT_FAST);
      delay(500);
    }

    pressureValue = analogRead(PRESSURE_PIN) - initialPressureValue;
  }

  if(pressureValue < 341) Serial.println(HIT_SLOW);
  else if(pressureValue >= 341 && pressureValue < 682) Serial.println(HIT_MEDIUM);
  else if(pressureValue >= 682 && pressureValue < 1024) Serial.println(HIT_FAST);

  delay(1000);
}
