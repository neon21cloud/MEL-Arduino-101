/*
 ------------ LUCAS CRESPO - TPMMEE EJERCICIO 2 ARDUINO ------------
 Este programa regula el encendido de LEDs según los datos recibidos 
 por una entrada analógica del ArduinoUNO.
 -------------------------------------------------------------------
 
 Para modificar los valores de entrada analógica, haremos circular 5V 
 a través de un potenciómetro.
 Variar el potenciómetro resultará en distintos valores de entrada.

 Los LEDs se controlan empleando salidas de datos digitales.
 Siempre hay al menos un LED encendido. Se establecén varios límites, 
 de manera que superarlos significa enciender un LED más sin apagar 
 los anteriores, hasta 4. Si el valor vuelve a caer por debajo de un 
 límite, se apaga el o los LEDs correspondientes 
 
*/
 

// -- DECLARIACIÓN DE PINES DEL ARDUINO 
int analogPin = 3;       // Pin de lectura analógica. Devuelve valores de 0-1023. El pin central del potenciometro se conecta aquí; los otros dos a GND y Vcc.
                       
// -- INICIALIZACIÓN DE VARIABLES 
int AnalogREAD = 0;      // Variable de lectura de entrada analógica.
float VOLTAJE = 0;
double DIVISIONES = 0;
double ANALOG_MAX = 1023;
double VOLTAJE_MAX = 5;

// -- DECLARACIÓN DE CONDICIONES INICIALES
void setup() {
  
  Serial.begin(9600);                           // Iniciar comunicación entre arduino y ordenador a 9600 bits por segundo.
  DIVISIONES = VOLTAJE_MAX  / ANALOG_MAX;       // Precisión de medidas de tensión;
}

// -- LOOP INFINITO; PROGRAMA PRINCIPAL
void loop() {

  // -- LECTURA DE ENTRADA ANALÓGICA 
  AnalogREAD = analogRead(analogPin);       // Guardar la lectura en una varible que cambia en cada vuelta de bucle
  VOLTAJE = AnalogREAD * DIVISIONES;
  Serial.print("El voltaje es: ");
  Serial.println(VOLTAJE);

  
}
