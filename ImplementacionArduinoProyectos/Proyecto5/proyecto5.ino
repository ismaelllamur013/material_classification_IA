#include<math.h>

#define S0 4    // S0 a pin 4
#define S1 5    // S1 a pin 5
#define S2 6    // S2 a pin 6
#define S3 7    // S3 a pin 7
#define salidaTCS 8 // salidaTCS a pin 8

int p1,p2,p3; // variables para la entrada de la neurona
float n1,n2,n3,n4,n5,n6,n7,n8; //variables para la salida de la naurona
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
  
  n1=p1*(-0.05503669)+p2*(0.7290862)+ p3*(0.23165585) +( -2.6243253); //entradas por los pesos mas el bias
  n2=p1*(-0.16369973)+p2*(0.8049504)+ p3*(0.20678426) +( 6.907587);
  n3=p1*(0.08180205)+p2*( 0.84818727)+ p3*(-0.03012482) +(-16.543528);

  float miArray[] = {n1,n2,n3};
 
  float maximo=miArray[0];
  int idx_maximo=0;
  for (int i = 0; i < 3; i = i + 1) {
    if (miArray[i]>maximo){
      maximo=miArray[i];
      idx_maximo=i;
    }
  }


  switch (idx_maximo) {
  case 0:
    Serial.println("BAJO");
    break;
  case 1:
    Serial.println("MEDIO");
    break;
  case 2:
    Serial.println("MODERADO");
    break;
  }

  n4=p1*(-0.14988829)+p2*(-0.19195212)+ p3*( 0.23508999) +(12.016132); //entradas por los pesos mas el bias
  n5=p1*(0.09310706)+p2*( -0.1984459)+ p3*( 0.01661208) +(-9.667124);
  n6=p1*(-0.01397044)+p2*(-0.08640744)+ p3*(-0.00689848) +( -1.0737325);

  float miArray2[] = {n4,n5,n6};
 
  float maximo2=miArray2[0];
  int idx_maximo2=0;
  for (int i = 0; i < 3; i = i + 1) {
    if (miArray2[i]>maximo){
      maximo2=miArray2[i];
      idx_maximo2=i;
    }
  }


  switch (idx_maximo2) {
  case 0:
    Serial.println("RUBIO");
    break;
  case 1:
    Serial.println("OSCURO");
    break;
  case 2:
    Serial.println("NEGRO");
    break;
  }

  n7=p1*(-0.10221688)+p2*( 0.05188485)+ p3*( 0.05590059) +(24.538932244997756);
  Serial.println("IBU: ");
  Serial.println(n7);

  n8=p1*(-0.00185044)+p2*(0.00136082)+ p3*( 0.00117373) +(5.147362923956349);
  Serial.println("ALCOHOL: ");
  Serial.println(n8);



  
}
