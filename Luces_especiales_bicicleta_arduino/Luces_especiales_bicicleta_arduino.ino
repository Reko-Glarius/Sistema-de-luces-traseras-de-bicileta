/*
 * Titulo: Sistema de control de luces traseras para bicicleta
 * 
 * Desarrollador: Ricardo Aliste G.
 * 
 * Descripcion:
 */

// Variables contantes (entradas y salidas del arduino)
const int button_left=1;   //Boton para flecha izquierda
const int button_center=2; //Boton para luces rojas centrales
const int button_right=3;  //Boton para flecha derecha

const int led_left=10;   //Puerto de luces LED de la flecha izquierda
const int led_center=11; //Puerto de luces LED centrales (luces de aviso)
const int led_right=12;  //Puerto de luces LED de la flecha derecha

// Variables de apoyo
int before_bl=0; //Variable para lectura de estado anterior del boton izquierdo (button_left)
int before_bc=0; //Variable para lectura de estado anterior del boton central (button_center)
int before_br=0; //Variable para lectura de estado anterior del boton derecho (button_right)

void setup(){
  // Inicializacion de variables que INGRESAN informacion
  pinMode(button_left, INPUT)
  pinMode(button_center, INPUT)
  pinMode(button_right, INPUT)

  // Inicializacion de variables que ENTREGAN informacion
  pinMode(led_left)
}

void loop() {
  // put your main code here, to run repeatedly:

}
