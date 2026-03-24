
// INICIALIZACIÓN A 0 DE VARIABLE CONTADOR
int x = 1;    //entero
float z;  //fraccionario

int runXtimes = 1;


// INICIALIZACIÓN DE CONDICIONES INICIALES DEL PROGRAMA
void setup() {
  
  // Iniciar la comunicación entre arduino y ordenador a 
  // una velocidad de 9600 bits por segundo.
  Serial.begin(9600);

}

// LOOP INFINITO; PROGRAMA PRINCIPAL
void loop() {
  
  if (runXtimes){
    
    Serial.println ("Sin decimal point");
    Serial.println (z = (float)x/2);
    Serial.println ("Con decimal point");
    Serial.println (z = (float)x/2.0);

    runXtimes--;
  
  }
}
