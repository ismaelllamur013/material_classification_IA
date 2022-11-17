#include<math.h>

#define S0 4    // S0 a pin 4
#define S1 5    // S1 a pin 5
#define S2 6    // S2 a pin 6
#define S3 7    // S3 a pin 7
#define salidaTCS 8 // salidaTCS a pin 8

int p1,p2,p3; // variables para la entrada de la neurona
float n1,n2,n3,n4,n5,n6; //variables para la salida de la naurona
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
  
  n1=p1*(-0.62779695)+p2*(0.32252124)+ p3*(0.87517035) +( 0.43435317); //entradas por los pesos mas el bias
  n2=p1*(-0.30060154)+p2*(0.24007687)+ p3*(0.6465385) +(-2.497379);
  n3=p1*( 0.03610214)+p2*(-0.4602592 )+ p3*( 1.0622662) +(-1.7390523);
  n4=p1*( 0.46576712)+p2*( 0.11257413)+ p3*(-0.27320874) +( 12.984279);
  n5=p1*(0.76651365)+p2*(-0.00544003)+ p3*( -0.38185242) +(-11.963888);
  n6=p1*(0.14616914)+p2*( 0.25102454)+ p3*( 0.06618386) +(   -1.6868646);
  
  float miArray[] = {n1,n2,n3,n4,n5,n6};
 
  float maximo=miArray[0];
  int idx_maximo=0;
  for (int i = 0; i < 6; i = i + 1) {
    if (miArray[i]>maximo){
      maximo=miArray[i];
      idx_maximo=i;
    }
  }


  switch (idx_maximo) {
  case 0:
    Serial.println("ACEITE");
    break;
  case 1:
    Serial.println("ALCOHOL");
    break;
  case 2:
    Serial.println("LAVANDINA");
    break;
  case 3:
    Serial.println("AGUA");
    break;
  case 4:
    Serial.println("AGUA CALIENTE");
    break;
  case 5:
    Serial.println("VACIO");
    break;
 
}

}
