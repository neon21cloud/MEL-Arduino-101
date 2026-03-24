/*
Herramientas --> Monitor (terminal)
*/

// int resultado;
int runXtimes = 5;
void setup() {
  Serial.begin(9600);
 
}

void loop() {
 
  if (runXtimes){
    Serial.println(suma(2,3)); //print = impresion
    Serial.println(resta(5,2)); //println = impresion en la línea
    Serial.println(producto(6,5)); //se imprime en otra línea por haber usado println en el anterior
    //resultado = suma(2,3);
    //Serial.println(resultado);
    runXtimes--;
  }  
}

int suma (int x, int y) {
  return x + y;
}

int resta (int x, int y) {
  return x - y;
}

int producto (int x, int y) {
  return x * y;
}
