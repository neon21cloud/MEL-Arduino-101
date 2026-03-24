/* 
------------- LUCAS CRESPO - TPMEE -1ºMEL -------------
            Práctica 4. Uso del bucle for.
*/


// VARIABLES GLOBALES
int y, z;                            // Inicialización de variables x, y.

// CONDICIONES INICIALES
void setup() {
  Serial.begin(9600);                // Iniciar comunicación entre arduino y ordenador a 9600 bits/s.
}

//PROGRAMA PRINCIPAL
void loop() {

    // Para X con valores de 1 a 200, se calculan Y y Z según las formulas establecidas
    // y se muestran por pantalla.
    
    for (int x = 1; x <= 200; x++){  
        y = pow(x, 2) + 3;
        z = y - x;                   // Al ser X una variable local del bucle, Y y Z tienen que ser declaradas en cada vuelta
        Serial.print("X = ");           
        Serial.println(x);
        Serial.print("Y = ");
        Serial.println(y);
        Serial.print("Z = ");
        Serial.println(z);         
    }
    
}
