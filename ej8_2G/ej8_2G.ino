/* 
------------- LUCAS CRESPO - TPMEE -1ºMEL -------------
            Práctica 6. Uso de funciones.
Este programa consiste en una demostración del uso de funciones en arduino.
El programa llama a una función capaz de realizar ecuaciones de segundo grado
con parámetros preestablecidos.

Precisamente porque el programa solo ejecuta una operación y no da la opción al
usuario de cambiar los valores de entrada en cada ejecución, se ha limitado el 
bucle principal a una sola ejecución.

Específicamente, el programa realiza la operación X^2 +3X -4  = 0, resolviendo X.
Los resultados posibles son x1=1   y x2=-4. [Sin retorno]

Luego, el programa realiza la operación X^2 -6X +5  = 0, resolviendo X.
Los resultados posibles son x1=1   y x2=-4.  [Con retorno]
*/

// Declaraciones con double para poder usar decimales de ser necesario

double A_1 = 1 ;          // X^2
double B_1 = 3 ;          // +3X
double C_1 = -4 ;         // -4

double A_2 = 1 ;          // X^2
double B_2 = -6 ;         // -6X
double C_2 = 5 ;          // +5

double X_1;               // Varaibles para almacenar los valores de retorno de funciones
double X_2;               // para la segunda ecuación


// Límite de ejecuciones
int runXtimes = 1;


void setup() {
  Serial.begin(9600);
   
}

void loop() {            
  if (runXtimes){
    Serial.println("ECUACIÓN X^2 +3X -4  = 0: ");
    ecuacion1_sin_return(A_1, B_1, C_1);                        // Llamada a la función en la que se pasan los argumentos necesario
    Serial.println("ECUACIÓN X^2 -6X +5  = 0: ");
    Serial.print("X1: ");
    Serial.println(X_1 = ecuacion2_x1_return(A_2, B_2, C_2));
    Serial.print("X2: ");
    Serial.println(X_2 = ecuacion2_x2_return(A_2, B_2, C_2));
    runXtimes--;
  }                    
}


// Declaración de función. Recibe valores del bucle principal pero no devuelve nada.
// Guarda el resultado en un array y lo imprime por pantalla.

void ecuacion1_sin_return(double a, double b, double c){

  double x1 = ( -b + sqrt( b*b - 4*a*c )) / 2 * a;   // Primer posible resultado para X.
  double x2 = ( -b - sqrt( b*b - 4*a*c )) / 2 * a;   // Segundo posible resultado para X.

  double solucion[2] = { x1, x2 };                   // Almacén de datos en el array.
  for(int i = 0; i < 2; i++ ){                       // Impresión del array.
    Serial.print("X");
    Serial.print(i+1);
    Serial.print(": ");
    Serial.println(solucion[i]);   }
    
}


// Función con retorno para la segunda ecuacion: primera solución.

double ecuacion2_x1_return(double a, double b, double c){

  int x1 = ( -b + sqrt( b*b - 4*a*c )) / 2 * a;   // Primer posible resultado para X.
  return x1;

}


// Función con retorno para la segunda ecuacion: segunda solución.

double ecuacion2_x2_return(double a, double b, double c){

  int x2 = ( -b - sqrt( b*b - 4*a*c )) / 2 * a;   // Segundo posible resultado para X.
  return x2;
  
}
