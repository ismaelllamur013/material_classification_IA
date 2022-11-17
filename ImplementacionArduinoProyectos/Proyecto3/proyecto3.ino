#include<math.h>

#define S0 4    // S0 a pin 4
#define S1 5    // S1 a pin 5
#define S2 6    // S2 a pin 6
#define S3 7    // S3 a pin 7
#define salidaTCS 8 // salidaTCS a pin 8

int p1,p2,p3; // variables para la entrada de la neurona
float n1; //variables para la salida de la naurona
float e=2.7182818;
int rojo, verde, azul;

void setup() {
  // put your setup code here, to run once:
  pinMode(S0, OUTPUT);    // pin 4 como salida
  pinMode(S1, OUTPUT);    // pin 5 como salida
  pinMode(S2, OUTPUT);    // pin 6 como salida
  pinMode(S3, OUTPUT);    // pin 7 como salida
  pinMode(salidaTCS, INPUT);  // pin 8 como salida
  
  digitalWrite(S0,HIGH);  // establece frecuencia de salida
  digitalWrite(S1,LOW);   // del modulo al 20 por ciento
  
  Serial.begin(115200);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  //
  rojo=0;
  verde=0;
  azul=0;
  
  for (int i = 0; i <= 5; i++) {
    digitalWrite(S2,LOW); // establece fotodiodos
    digitalWrite(S3,LOW); // con filtro rojo
    rojo = rojo + pulseIn(salidaTCS, LOW); // obtiene duracion de pulso de salida del sensor
    //delay(10);
    digitalWrite(S2,HIGH);  // establece fotodiodos
    digitalWrite(S3,HIGH);  // con filtro verde
    verde = verde + pulseIn(salidaTCS, LOW); 
    //delay(10000);
    digitalWrite(S2,LOW); // establece fotodiodos
    digitalWrite(S3,HIGH); // con filtro azul
    azul = azul +pulseIn(salidaTCS, LOW);
  }
  
  //Entradas de la neurona
  p1=rojo/5 ;
  p2=verde/5 ;
  p3=azul/5 ;
  
  n1=p1*(-0.02573817)+p2*( -0.00182566)+ p3*(0.04872086) +(4.132734595094611); //entradas por los pesos mas el bias
  Serial.println(n1);


}
