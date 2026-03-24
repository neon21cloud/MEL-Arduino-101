#include <AFMotor.h> 
AF_DCMotor motor1(2);
AF_DCMotor motor2(3);


void setup() {
 
  Serial.begin(9600);
  motor1.setSpeed(200);
  motor1.run(RELEASE);
  motor2.setSpeed(200);
  motor2.run(RELEASE);
 
}

void loop() {

  
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  Serial.println("F");
  delay(1000); 
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  Serial.println("B");      
  delay(1000);  
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  Serial.println("R");      
  delay(1000); 
  
}
