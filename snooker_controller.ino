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

#define LEFT "left"
#define RIGHT "right"
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
    if(yValue >= 550){
      Serial.println(LEFT);
      delay(500);
    }
    else if(yValue <=500){
      Serial.println(RIGHT);
      delay(500);
    }
  }

  Serial.println(HIT);

  delay(1000);
}
