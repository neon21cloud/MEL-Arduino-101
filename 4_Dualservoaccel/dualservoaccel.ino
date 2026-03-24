#include <Wire.h>
#include <MPU6050.h>
#include <Servo.h>   

//Servo setup
Servo servo_vertical;          
Servo servo_horizontal;          
int PIN_V = 9;
int PIN_H = 10;
int MAX_TURN = 180;
int MIN_TURN = 0;

//Accel setup
MPU6050 sensor ;
int16_t ax, ay, az ;
int16_t gx, gy, gz ;
int MAX_ACCEL = 17000;
int MIN_ACCEL = -17000;


void setup ( ) { 

  Serial.begin  (9600); 
  
  servo_vertical.attach ( PIN_V );
  servo_horizontal.attach ( PIN_H );
  
  Wire.begin ( ); 
  sensor.initialize ( ); 
  Serial.println (sensor.testConnection ( ) ? "Ready to roll" : "Connection failed"); 
  delay (1000); 

}

/* 
  La magia ocurre con la función map()
  La sintaxis es la siguiente:
  $map(value, fromLow, fromHigh, toLow, toHigh)
  
  La funcion esencialmente mapea un valor entre un rango a un valor equivalente en otro rango:
  $ long map(long x, long in_min, long in_max, long out_min, long out_max) {
  $ return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min; }

  En resumen para este programa: para los valores de ai recibidos del accelerometro,
  estableciendo sus maximos y minimos entre -17 y 17k, 
  se le asigna un correspondiente entre 0 y 180.
*/


void loop ( ) { 

  sensor.getMotion6 (&ax, &ay, &az, &gx, &gy, &gz);
  Serial.println (gx);
  ax = map (ax, MIN_ACCEL, MAX_ACCEL, MIN_TURN, MAX_TURN) ; 
  ay = map (ay, MIN_ACCEL, MAX_ACCEL, MIN_TURN, MAX_TURN) ;
  //Serial.println (ax);
  servo_vertical.write (ax);
  servo_horizontal.write (ay);
  delay (200);

}
