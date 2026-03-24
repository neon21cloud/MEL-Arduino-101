/* 
------------- LUCAS CRESPO - TPMEE -1ºMEL -------------
                Práctica 7. Display LCD.
Este programa consiste en una demostración de funcionamiento
  del display LCD. El arduino lee la tensión a través de un
potenciómetro, con un máximo de 5V, y actualiza en tiempo real
        el resultado en la pantalla LCD.
*/

#include <LiquidCrystal.h>                  // Librería de control del LCD. 
LiquidCrystal lcd(1, 2, 4, 5, 6, 7);        // Objecto LCD con parámetros (rs, enable, d4, d5, d6, d7). 
int analogPin = 3;                          // Potenciometro: pin central al A3.

int AnalogREAD = 0;      
double DIVISIONES = 0;
double ANALOG_MAX = 1023;
double VOLTAJE_MAX = 5;
double VOLTAJE;

void setup() {
 lcd.begin(16,2);                           // Init del LCD, especificando dimensiones (ancho y alto)
 lcd.noCursor();                            // Oculta el cursor del LCD 
 DIVISIONES = VOLTAJE_MAX  / ANALOG_MAX;    // Se establece el incremento de cada valor recibido por la lectura de A3 
}

void loop() {
 AnalogREAD = analogRead(analogPin);     
 VOLTAJE = AnalogREAD * DIVISIONES;         // Calculo del voltaje con el valor recibido por el pin A3
 LCD_Print(VOLTAJE);                        // Impresión por el LCD del valor de voltaje
}

void LCD_Print(double VOLTAJE){

 lcd.setCursor(0,0); lcd.print("VOLTAJE:"); // Posicion comienzo de escritura en el LCD + impresión de texto
 lcd.setCursor(0,1); lcd.print(VOLTAJE);
 lcd.setCursor(4,1); lcd.print("V"); 
 delay(200); 
 lcd.clear();                               // Limpiar la lectura de salida para no sobreescribir celdas en el LCD

}
