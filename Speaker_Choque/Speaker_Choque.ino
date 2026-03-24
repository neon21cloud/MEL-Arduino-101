/* 
------------- LUCAS CRESPO - TPMEE -1ºMEL -------------
            Práctica 5. Actuadores Arduino.
Este programa consiste en una demostración de funcionamiento del lector de 
tarjetas SD de arduino, el cual se usa para reproducir música por un
altavoz de 8ohms, usando un AO LM386N para amplificar la señal de sonido.

El circuito montado reproducirá pistas de audio cuando: 
- Se pulse un botón designado para ello.
- Se detecte un choque o golpe al circuito.
*/


#include "SD.h"     //Librería de lectura de la tarjeta SD
#include "TMRpcm.h" //Librería para reproducir audio .wav
#include "SPI.h"    //Libreria de comunicación con periféricos

const int SD_PIN = 4 ;           // Pin de referencia para el lector de tarjetas
const int BOTON_PIN = 2;         // Entrada de datos del botón
const int MUSIC_PIN = 9;         // Audio emitido por el pin 9
const int SHK_PIN = 7;           // Entrada de datos del sensor de choque
const int VOLUMEN = 5;           // 0 a 7 de nivel de volumen
const int CALIDAD_SONIDO = 1;    // 0 normal, 1 reducción de ruido
const int PAUSA_SD = 250;        // Valor para no saturar a lecturas cuando se pulsa el botón
const int PAUSA_SHK = 1;         // Valor para no saturar a lecturas el sensor de choque
const int INIT_LED = 8;          // LED indicador de correcta inicialización de sistemas
const int ERROR_LED = 6;         // LED indicador de salida de error
boolean fallo = false;           // Variable de control de errores
int NUMERO_CANCION = 0;          // Contador para la libreria de audio

TMRpcm music;                    // El objeto de la librería TMRpcm se llamará "music"


void setup(){

  Serial.begin(9600);
  
  pinMode(INIT_LED, OUTPUT);
  pinMode(ERROR_LED, OUTPUT);
  pinMode(SHK_PIN, INPUT);
  pinMode(BOTON_PIN, INPUT_PULLUP);   // Como el estado botón no es constante al ser pulsado, se usa INPUT_PULLUP en vez de INPUT
  
  if (!SD.begin(SD_PIN)) {            // Comprobar que se inicializó el lector de tarjetas
    fallo = true;                     
    Serial.println("SD fail");
  } else {Serial.println("SD init"); digitalWrite(INIT_LED, HIGH); digitalWrite(ERROR_LED, LOW);}   // De estar todo en orden, se enciende un LED verde

  music.speakerPin = MUSIC_PIN;       
  music.setVolume(VOLUMEN);           
  music.quality(CALIDAD_SONIDO);      

}

/* Mientras no haya error, si se pulsa el botón o detecta choque se reproduce audio.
   De lo contrario, se termina por la salida de error:
*/

void loop() { 

  delay(PAUSA_SHK); 
  if (digitalRead(BOTON_PIN) == LOW || digitalRead(SHK_PIN) == LOW && fallo == false) {

    delay(PAUSA_SD);
    NUMERO_CANCION ++;                                 // Aumenta el numero de canción
    if (NUMERO_CANCION == 4) {NUMERO_CANCION = 1;}     // y si llegas al numero final de canción vuelve a empezar
  
    Serial.println("Boton pulsado");
    Serial.print("NUMERO_CANCION=");
    Serial.println(NUMERO_CANCION);

    if (NUMERO_CANCION == 1){music.play("1.wav");}     // Reproducir canción uno 
    if (NUMERO_CANCION == 2){music.play("2.wav");}     // Reproducir canción dos
    if (NUMERO_CANCION == 3){music.play("3.wav");}     // Reproducir canción tres

  }

  else if (fallo == true){                             // Salida de error. Enciende una luz roja
    
    digitalWrite(INIT_LED, LOW);
    digitalWrite(ERROR_LED, HIGH);
      
  }    

} 
