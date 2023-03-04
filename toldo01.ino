/* SIMULACIÓN DE TOLDO. 

Nesta práctica vamos simular o avance dun toldo en función da
intensidade da luz solar, pero non ten retorno, só avance.
O motor de DC está alimentado externamente por unha pila de 9V;
un relé SPDT, conectado ó pin 12, vai accionar o motor cando o LDR
detecte moita luz ou estea en baixa resistencia.
O LDR está en serie cunha resitencia PULLDOWN, e conectado ó pin 
A0 (entrada analóxica).

Cando a luz sexa intensa, o LDR está en baixa intensidade e por
tanto vaise activar o relé que á sua vez activa o motor durante 7 
segundos e logo apágase.


Entradas: pin analóxico A0
Saídas: relé SPDT

Autor: Jéssica Suárez Parada
Data: 27/02/2023

*/

#define LDR A0    //Donde poña LDR, arduino sustitueo por A0
#define rele 12   

//int pinSensor = A0
//int pinRele = 12

int umbral = 950;
int entrada = -999;
bool releOn = false;
int contador = 0;
bool finCarreira = false;

void setup() {
  pinMode(LDR, INPUT);    //as entradas analóxicas non hai porque declaralas
  pinMode(rele, OUTPUT);    
  Serial.begin(9600);     //Velocidade do motor
}

void loop(){ 
  //LECTURA DE ENTRADAS
  entrada = analogRead(LDR);      // A lectura abarcará os valores dentro do rango 54 - 974 
  Serial.print("Entrada LDR: ");  // imprime o rango de valor no que se encontra en ese momento
  Serial.println(entrada);        //nomea ó LDR
  
  //ACCIONAMENTOS DOS ACTUADORES
  if(entrada > umbral) {  // si a entrada e maior co umbral activa o fin de carreira  
    releOn = true;                                 
    contador = 100;     
  }
  
  if(contador > 0 && entrada > umbral) {
  Serial.print("Contador: "); Serial.println(contador); // imprime o valor do contador hacia atrás
  contador--;
  delay(70);
  }
  
  else {
  releOn = false;  
}
   digitalWrite(rele, releOn);
}

