#include <Servo.h>

Servo myServo;
const short servoPin = 11;
int angle = 0;
void setup() {
  Serial.begin(9600);
  myServo.attach(servoPin);
}

void loop() {
  for(angle; angle < 180; angle ++)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myServo.write(angle);              // tell servo to go to position in variable 'pos' 
    delay(1);
    Serial.println(myServo.read());    // waits 15ms for the servo to reach the position 
  } 
  for(angle; angle>=1; angle--)     // goes from 180 degrees to 0 degrees 
  {                                
    myServo.write(angle);              // tell servo to go to position in variable 'pos' 
    delay(1);                       // waits 15ms for the servo to reach the position 
    Serial.println(myServo.read());
  } 
}
