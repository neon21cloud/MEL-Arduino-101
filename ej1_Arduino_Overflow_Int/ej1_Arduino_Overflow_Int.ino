
// INICIALIZACIÓN A 0 DE VARIABLE CONTADOR
int contador;

// INICIALIZACIÓN DE CONDICIONES INICIALES DEL PROGRAMA
void setup() {
  
  // Iniciar la comunicación entre arduino y ordenador a 
  // una velocidad de 9600 bits por segundo.
  Serial.begin(9600);

}

// LOOP INFINITO; PROGRAMA PRINCIPAL
void loop() {
  // Imprimimos en la consola, con salto de línea,
  // la variable contador aumenetándola una vez cada pasada
  // contador ++ ---> contador = contador + 1
  Serial.println (contador++);

}
