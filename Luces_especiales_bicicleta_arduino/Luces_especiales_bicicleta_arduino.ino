/*
 * Titulo: Sistema de control de luces traseras para bicicleta
 * 
 * Desarrollador: Ricardo Aliste G.
 * 
 * Descripcion:
 */

// Variables contantes (definicion de los pines del arduino)
const int PIN_BL=1; //PIN para el boton para flecha izquierda
const int PIN_BC=2; //PIN para el boton para luces rojas centrales
const int PIN_BR=3; //PIN para el boton para flecha derecha

const int led_left=10;   //Puerto de luces LED de la flecha izquierda
const int led_center=11; //Puerto de luces LED centrales (luces de aviso)
const int led_right=12;  //Puerto de luces LED de la flecha derecha


// Variables de apoyo
int button_left=0;   //Variable para lectura de estado actual del boton izquierdo
int button_center=0; //Variable para lectura de estado anterior del boton central
int button_right=0;  //Variable para lectura de estado anterior del boton derecho

int before_bl=0; //Variable para lectura de estado anterior del boton izquierdo (button_left)
int before_bc=0; //Variable para lectura de estado anterior del boton central (button_center)
int before_br=0; //Variable para lectura de estado anterior del boton derecho (button_right)

int switcher=0; ///Variable para detectar si es primera activacion o no

// Funciones implementadas
int ACTION_BUTTON(int BL, int BC, int BR, int B_BL, int B_BC, int B_BR){
  if(BL==B_BL && BC==B_BC && BR==B_BR){return 6;}
  else{
    if(BL!=B_BL){
      if(BL==HIGH){return 0;}
      else{return 3;}
    }
    if(BC!=B_BC){
      if(BC==HIGH){return 1;}
      else{return 5;}
    }
    if(BR!=B_BR){
      if(BR==HIGH){return 2;}
      else{return 5;}
    }
  }
}


// Preparacion de sistema previo a activacion
void setup(){
  // Inicializacion de variables que INGRESAN informacion
  pinMode(PIN_BL, INPUT);
  pinMode(PIN_BC, INPUT);
  pinMode(PIN_BR, INPUT);

  // Inicializacion de variables que ENTREGAN informacion
  pinMode(led_left, OUTPUT);
  pinMode(led_center, OUTPUT);
  pinMode(led_right, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  button_left=digitalRead(PIN_BL);
  button_center=digitalRead(PIN_BC);
  button_right=digitalRead(PIN_BR);
  
  if(switcher==0){
    before_bl=digitalRead(PIN_BL);
    before_bc=digitalRead(PIN_BC);
    before_br=digitalRead(PIN_BR);

    switcher=1;
  }
  else{
    switch(ACTION_BUTTON(button_left, button_center, button_right, before_bl, before_bc, before_br)){
      case 0: //Se prende flecha izq.
        digitalWrite(led_left, HIGH);
      case 1: //Se prende luz central.
        digitalWrite(led_center, HIGH);
      case 2: //Se prende flecha der.
        digitalWrite(led_right, HIGH);
      
      case 3: //Se apaga flecha izq.
        digitalWrite(led_left, LOW);
      case 4: //Se apaga luz central.
        digitalWrite(led_center, LOW);
      case 5: //Se apaga flecha der.
        digitalWrite(led_right, LOW);
      
      default: //No se realiza ninguna accion
        switcher=switcher;
    }
  }
}
