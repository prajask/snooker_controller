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

#define HIT "hit"

int yValue = 0; // To store value of the Y axis
int pressureValue;
int initialPressureValue;

void setup() {
  Serial.begin(9600) ;

  // initialPressureValue = analogRead(PRESSURE_PIN);

}

void loop() {

  // Serial.println(initialPressureValue);
  while(digitalRead(HIT_PIN) == HIGH){
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
  }

  Serial.println(HIT);

  delay(1000);
}
