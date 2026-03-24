//servo STD cables: naranja --> Vcc; amarillo --> control; marron --> GND

#include <Servo.h>

Servo Servo1;  // Crear objeto servo (hasta 12 en muchas placas)
Servo Servo2;  // Crear objeto servo (hasta 12 en muchas placas)


int pos = 0;   // Variable en la que guardar la posición del servo (grados)
int TIME = 5; //tiempo en ms

void setup() {
  Servo1.attach(8);  // establecer el pin 9 como salida de control digital para el servo
  Servo2.attach(10);  // establecer el pin 9 como salida de control digital para el servo
}


void loop() {
  for (pos = 0; pos <= 180; pos += 1) { // barrido hasta 180 grados en pasos de uno en uno
    Servo1.write(pos);              // le dice al servo la posición en la que colocarse
    Servo2.write(pos);              // le dice al servo la posición en la que colocarse
    delay(TIME);                       // espera 15 ms para que el servo llegue a la posición
  }
  for (pos = 180; pos >= 0; pos -= 1) { // dehacer el recorrido
    Servo1.write(pos);
    Servo2.write(pos);           
    delay(TIME);                       
  }
}
