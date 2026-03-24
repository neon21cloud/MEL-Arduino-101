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
int ledPin1 = 7;         // Pin de salida digital 7.
int ledPin2 = 8;         // Pin de salida digital 8.
int ledPin3 = 12;        // Pin de salida digital 12.
                         // Pese necesitar 4 salidas digitales, ya existe una palabra reservada LED_BUILTIN hace referencia a la salida digital 13.
                       
// -- INICIALIZACIÓN DE VARIABLES 
int AnalogREAD = 0;      // Variable de lectura de entrada analógica.
int AnalogMAX = 1023;    // Valor máximo de lectura analógica.
int REDONDEO_ARRIBA = 1; // El tipo Int trunca los decimales de un número. Si queremos un redondeo hacia arriba, sumamos uno.
int THRESHOLD_1 = 0;     // Inicialización de límite 1.
int THRESHOLD_2 = 0;     // Inicialización de límite 2.
int THRESHOLD_3 = 0;     // Inicialización de límite 3.

// -- DECLARACIÓN DE CONDICIONES INICIALES
void setup() {
  
  Serial.begin(9600);                           // Iniciar comunicación entre arduino y ordenador a 9600 bits por segundo.
  pinMode(ledPin1, OUTPUT);                     // Declaración de Pin número 7 como salida digital.
  pinMode(ledPin2, OUTPUT);                     // Declaración de Pin número 8 como salida digital.
  pinMode(ledPin3, OUTPUT);                     // Declaración de Pin número 12 como salida digital.
  pinMode(LED_BUILTIN, OUTPUT);                 // Declaración de Pin número 13 como salida digital.
  THRESHOLD_1 = AnalogMAX/4;                    // Límite 1 = Primer cuarto del rango de lectura analógica.
  THRESHOLD_2 = AnalogMAX/2 + REDONDEO_ARRIBA;  // Límite 2 = Mitad del rango de lectura analógica.
  THRESHOLD_3 = AnalogMAX - AnalogMAX/4;        // Límite 3 = Tres cuartos del rango de lectura analógica.
  
}

// -- LOOP INFINITO; PROGRAMA PRINCIPAL
void loop() {

  // -- LECTURA DE ENTRADA ANALÓGICA 
  AnalogREAD = analogRead(analogPin);       // Guardar la lectura en una varible que cambia en cada vuelta de bucle
  /*
  Serial.print("AnalogREAD: ");             // Descomentar para imprimir en el monitor los valores de lectura 
  Serial.println(AnalogREAD);               // para comprobar su correcto fucionamiento
  */ 

  // -- LÓGICA DE ENCENIDO DE LEDS: CONTROL DE SALIDAS DIGITALES 
  // No solo vamos a encender los LEDs que queramos sino que especificaremos que los que no queramos tienen que
  // quedar apagados. De lo contrario, una vez se enciendan no se apagarán nunca no importan las condiciones: 
  // el programa "volvería a encender" los que sea necesario (ya estarían encendidos igualmente) y los otros seguirían 
  // encendidos, no se apagan automaticamente.

  // Encendemos el pin que queramos estableciendo su estado como HIGH  y lo apagamos estableciendolo como LOW
  
  if(AnalogREAD <= THRESHOLD_1){           // CONDICIÓN 1: Si la lectura es menor o igual al primer límite,
    digitalWrite(LED_BUILTIN, HIGH);       // encender solo un LED (y apagar los demás).
    digitalWrite(ledPin1, LOW); 
    digitalWrite(ledPin2, LOW);               
    digitalWrite(ledPin3, LOW);
    /*
    Serial.print("TH1: ");                  // Descomentar para imprimir en el monitor el valor del límite superado
    Serial.println(THRESHOLD_1);            // y del número de LEDs encendidos.
    Serial.println("Un LED encendido");     // Esto es útil para detectar errores ya sea en el montaje o en el código.
    Serial.println("----------------------");
    delay(1000);
    */
  }

  else if(AnalogREAD <= THRESHOLD_2){       // CONDICIÓN 2: Si la lectura es menor o igual al segundo límite,
    digitalWrite(LED_BUILTIN, HIGH);        // encender un LED más a parte del de la condición 1 (y apagar los demás). 
    digitalWrite(ledPin1, HIGH);            
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    /*
    Serial.print("TH2: ");
    Serial.println(THRESHOLD_2);
    Serial.println("Dos LEDs encendidos");
    Serial.println("----------------------");
    delay(1000);
    */
  }
  
  else if(AnalogREAD <= THRESHOLD_3){       // CONDICIÓN 3: Si la lectura es menor o igual al tercer límite, 
    digitalWrite(LED_BUILTIN, HIGH);        // encender un LED más a parte de los de la condición 2 (y apagar el otro).
    digitalWrite(ledPin1, HIGH);            
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, LOW);
    /*
    Serial.print("TH3: ");
    Serial.println(THRESHOLD_3);
    Serial.println("Tres LEDs encendidos");
    Serial.println("----------------------");
    delay(1000);
    */
  }

  else {                                    // Si no se cumple ninguna condición,
    digitalWrite(LED_BUILTIN, HIGH);        // encender todos los LEDs
    digitalWrite(ledPin1, HIGH);           
    digitalWrite(ledPin2, HIGH);           
    digitalWrite(ledPin3, HIGH);
    /*
    Serial.println("Thresholds superados");
    Serial.println("Todos los LEDs encendidos");
    Serial.println("----------------------");
    delay(1000);
    */
  }

  
}
