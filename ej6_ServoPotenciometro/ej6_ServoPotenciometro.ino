/*
 ------------ LUCAS CRESPO - TPMMEE EJERCICIO 3 ARDUINO ------------
 Este programa regula el giro de un servomotor (0-180º) en funcion de 
 los valores leidos por un potenciometro a través de una entrada analógica.
 -------------------------------------------------------------------
 
 Para modificar los valores de entrada analógica, haremos circular 5V 
 a través de un potenciómetro.
 Variar el potenciómetro resultará en distintos valores de entrada.

 El servo se controla empleando salidas de datos digitales.
 
*/


#include <Servo.h>
Servo Servo1;  // Crear objeto servo (hasta 12 en muchas placas)

// -- DECLARIACIÓN DE PINES DEL ARDUINO 
int analogPin = 3;         // Pin de lectura analógica. Devuelve valores de 0-1023. El pin central del potenciometro se conecta aquí; los otros dos a GND y Vcc.
int digitalPin = 9;        // Pin de salida digital. El cable amarillo del servo se conecta aquí; los otros dos a GND (marron) y Vcc (rojo).
              
// -- INICIALIZACIÓN DE VARIABLES 
int AnalogREAD = 0;        // Variable de lectura de entrada analógica
float POSICION = 0;        // Variable de grados de giro del potenciometro
double GIRO = 0;           // Variable de incrementos de giro para cada valor del potenciometro
double ANALOG_MAX = 1023;  // Variable de valor máximo registrado en la entrada analógica
double GRADOS_MAX = 180;   // Varaible de grados máximos que puede girar el potenciometro
int TIME = 5;              // Variable de delay en mili segundos
float PORCENTAJE = 0 ;     // Variable de % de potencia del potenciometro

// -- DECLARACIÓN DE CONDICIONES INICIALES
void setup() {
  
  Serial.begin(9600);                    // Iniciar comunicación entre arduino y ordenador a 9600 bits por segundo
  GIRO = GRADOS_MAX  / ANALOG_MAX;       // Calculo de incrementos de giro para cada valor del potenciometro
  Servo1.attach(digitalPin);             // Establecer el pin digital 9 como salida de control digital para el servo

}

// -- LOOP INFINITO; PROGRAMA PRINCIPAL
void loop() {

  AnalogREAD = analogRead(analogPin);    // Guardar la lectura del potenciometro en una varible que cambia en cada vuelta de bucle
  POSICION = AnalogREAD * GIRO;          // Grados de giro del potenciometro, cambia cada vuelta de bucle
  PORCENTAJE = AnalogREAD / ANALOG_MAX * 100;
  Servo1.write(POSICION);                // Le dice al servo la posición en la que colocarse
  delay(TIME);                           // Espera 5 ms despues de cada movimiento del servo
  Serial.print("Potenciometro: ");       // Imprime en el monitor el % de potencia
  Serial.print(PORCENTAJE);
  Serial.println("%");
  Serial.print("La posicion es: ");      // Imprime en el monitor los grados que gira en cada vuelta de bucle
  Serial.println(POSICION);
               
    
}
