/* 
------------- LUCAS CRESPO - TPMEE -1ºMEL -------------
            Práctica 5. Actuadores Arduino.
Este programa consiste en una demostración de funcionamiento del lector de 
tarjetas SD de arduino, el cual se usa para reproducir música por un
altavoz de 8ohms, usando un AO LM386N para amplificar la señal de sonido.
*/


#include "SD.h"     //Librería de lectura de la tarjeta SD
#include "TMRpcm.h" //Librería para reproducir audio .wav
#include "SPI.h"    //Libreria de comunicación con periféricos

const int SD_PIN = 4 ;           // Pin de referencia para el lector de tarjetas
const int BOTON_PIN = 2;         // Entrada de datos del botón
const int MUSIC_PIN = 9;         // Auido emitido por el pin 9
const int VOLUMEN = 5;           // 0 a 7 de nivel de volumen
const int CALIDAD_SONIDO = 1;    // 0 normal, 1 reducción de ruido
const int PAUSA = 250;           // valor para no saturar a lecturas cuando se pulsa el botón
boolean fallo = false;           // variable de control
int NUMERO_CANCION = 0;

TMRpcm music;                    // El objeto de la librería se llama "music"


void setup(){

  Serial.begin(9600);
  
  if (!SD.begin(SD_PIN)) {            // Comprobar que se inicializó el lector de tarjetas
    fallo = true;
    Serial.println("SD fail");
  } else {Serial.println("SD init");}

  pinMode(BOTON_PIN, INPUT_PULLUP);   // Como el estado botón no es constante al ser pulsado, se usa INPUT_PULLUP en vez de INPUT

  music.speakerPin = MUSIC_PIN;       
  music.setVolume(VOLUMEN);           
  music.quality(CALIDAD_SONIDO);      

}


void loop() { 
 
  if (digitalRead(BOTON_PIN)==LOW  && fallo == false) {

    delay(PAUSA);
    NUMERO_CANCION++;                          //Aumenta el numero de canción
    if (NUMERO_CANCION==4) {NUMERO_CANCION=1;} // y si llegas al numero final de canción vuelve a empezar
  
    Serial.println("Boton pulsado");
    Serial.print("NUMERO_CANCION=");
    Serial.println(NUMERO_CANCION);

    if (NUMERO_CANCION ==1){music.play("1.wav");}     //Reproducir canción uno 
    if (NUMERO_CANCION ==2){music.play("2.wav");}      //Reproducir canción dos
    if (NUMERO_CANCION ==3){music.play("3.wav");}     //Reproducir canción tres

  }

} 
