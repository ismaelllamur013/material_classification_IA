#include<math.h>

#define S0 4    // S0 a pin 4
#define S1 5    // S1 a pin 5
#define S2 6    // S2 a pin 6
#define S3 7    // S3 a pin 7
#define salidaTCS 8 // salidaTCS a pin 8

int p1,p2,p3; // variables para la entrada de la neurona
float n1,n2,n3,n4,n5,n6,n7; //variables para la salida de la naurona
double a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16; // variables salida funcion de activacion
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
  
  n1=p1*(-2.0083806e-01)+p2*( 1.5127625e-01)+ p3*(8.0826050e-01) +(-2.228661 ); //entradas por los pesos mas el bias
  n2=p1*(3.6946350e-01)+p2*(2.4473520e-01)+ p3*(1.0297609e-03) +( -3.4321442);
  n3=p1*(3.4000957e-01)+p2*( 1.8601017e-01)+ p3*(-2.2659542e-03) +(2.973249 );
  n4=p1*(3.9532769e-01)+p2*(-9.3598478e-02)+ p3*( 1.3014731e-01) +(9.927609);
  n5=p1*(1.5442686e-01)+p2*(3.9058175e-02)+ p3*(4.9165615e-01) +(-0.5342798);
  n6=p1*(1.2517734e-01)+p2*(3.9510465e-01)+ p3*(1.8679447e-01) +(  -8.712903);
  n7=p1*(-5.2942604e-01)+p2*(-4.0055703e-02)+ p3*(1.2562648e+00) +( 6.9087067);
 

  float miArray[] = {n1,n2,n3,n4,n5,n6,n7};
  //a1=pow(e,n1)/(pow(e,n1)+pow(e,n2)+pow(e,n3)+pow(e,n4)+pow(e,n5)+pow(e,n6)+pow(e,n7)+pow(e,n8)+pow(e,n9)+pow(e,n10)+pow(e,n11)+pow(e,n12)+pow(e,n13)+pow(e,n14)+pow(e,n15)+pow(e,n16));
  //a2=pow(e,n2)/(pow(e,n1)+pow(e,n2)+pow(e,n3)+pow(e,n4)+pow(e,n5)+pow(e,n6)+pow(e,n7)+pow(e,n8)+pow(e,n9)+pow(e,n10)+pow(e,n11)+pow(e,n12)+pow(e,n13)+pow(e,n14)+pow(e,n15)+pow(e,n16));
  //a3=pow(e,n3)/(pow(e,n1)+pow(e,n2)+pow(e,n3)+pow(e,n4)+pow(e,n5)+pow(e,n6)+pow(e,n7)+pow(e,n8)+pow(e,n9)+pow(e,n10)+pow(e,n11)+pow(e,n12)+pow(e,n13)+pow(e,n14)+pow(e,n15)+pow(e,n16));
  //a4=pow(e,n4)/(pow(e,n1)+pow(e,n2)+pow(e,n3)+pow(e,n4)+pow(e,n5)+pow(e,n6)+pow(e,n7)+pow(e,n8)+pow(e,n9)+pow(e,n10)+pow(e,n11)+pow(e,n12)+pow(e,n13)+pow(e,n14)+pow(e,n15)+pow(e,n16));
  //a5=pow(e,n5)/(pow(e,n1)+pow(e,n2)+pow(e,n3)+pow(e,n4)+pow(e,n5)+pow(e,n6)+pow(e,n7)+pow(e,n8)+pow(e,n9)+pow(e,n10)+pow(e,n11)+pow(e,n12)+pow(e,n13)+pow(e,n14)+pow(e,n15)+pow(e,n16));
  //a6=pow(e,n6)/(pow(e,n1)+pow(e,n2)+pow(e,n3)+pow(e,n4)+pow(e,n5)+pow(e,n6)+pow(e,n7)+pow(e,n8)+pow(e,n9)+pow(e,n10)+pow(e,n11)+pow(e,n12)+pow(e,n13)+pow(e,n14)+pow(e,n15)+pow(e,n16));
  //a7=pow(e,n7)/(pow(e,n1)+pow(e,n2)+pow(e,n3)+pow(e,n4)+pow(e,n5)+pow(e,n6)+pow(e,n7)+pow(e,n8)+pow(e,n9)+pow(e,n10)+pow(e,n11)+pow(e,n12)+pow(e,n13)+pow(e,n14)+pow(e,n15)+pow(e,n16));
  //a8=pow(e,n8)/(pow(e,n1)+pow(e,n2)+pow(e,n3)+pow(e,n4)+pow(e,n5)+pow(e,n6)+pow(e,n7)+pow(e,n8)+pow(e,n9)+pow(e,n10)+pow(e,n11)+pow(e,n12)+pow(e,n13)+pow(e,n14)+pow(e,n15)+pow(e,n16));
  //a9=pow(e,n9)/(pow(e,n1)+pow(e,n2)+pow(e,n3)+pow(e,n4)+pow(e,n5)+pow(e,n6)+pow(e,n7)+pow(e,n8)+pow(e,n9)+pow(e,n10)+pow(e,n11)+pow(e,n12)+pow(e,n13)+pow(e,n14)+pow(e,n15)+pow(e,n16));
  //a10=pow(e,n10)/(pow(e,n1)+pow(e,n2)+pow(e,n3)+pow(e,n4)+pow(e,n5)+pow(e,n6)+pow(e,n7)+pow(e,n8)+pow(e,n9)+pow(e,n10)+pow(e,n11)+pow(e,n12)+pow(e,n13)+pow(e,n14)+pow(e,n15)+pow(e,n16));
  //a11=pow(e,n11)/(pow(e,n1)+pow(e,n2)+pow(e,n3)+pow(e,n4)+pow(e,n5)+pow(e,n6)+pow(e,n7)+pow(e,n8)+pow(e,n9)+pow(e,n10)+pow(e,n11)+pow(e,n12)+pow(e,n13)+pow(e,n14)+pow(e,n15)+pow(e,n16));
  //a12=pow(e,n12)/(pow(e,n1)+pow(e,n2)+pow(e,n3)+pow(e,n4)+pow(e,n5)+pow(e,n6)+pow(e,n7)+pow(e,n8)+pow(e,n9)+pow(e,n10)+pow(e,n11)+pow(e,n12)+pow(e,n13)+pow(e,n14)+pow(e,n15)+pow(e,n16));
  //a13=pow(e,n13)/(pow(e,n1)+pow(e,n2)+pow(e,n3)+pow(e,n4)+pow(e,n5)+pow(e,n6)+pow(e,n7)+pow(e,n8)+pow(e,n9)+pow(e,n10)+pow(e,n11)+pow(e,n12)+pow(e,n13)+pow(e,n14)+pow(e,n15)+pow(e,n16));
  //a14=pow(e,n14)/(pow(e,n1)+pow(e,n2)+pow(e,n3)+pow(e,n4)+pow(e,n5)+pow(e,n6)+pow(e,n7)+pow(e,n8)+pow(e,n9)+pow(e,n10)+pow(e,n11)+pow(e,n12)+pow(e,n13)+pow(e,n14)+pow(e,n15)+pow(e,n16));
  //a15=pow(e,n15)/(pow(e,n1)+pow(e,n2)+pow(e,n3)+pow(e,n4)+pow(e,n5)+pow(e,n6)+pow(e,n7)+pow(e,n8)+pow(e,n9)+pow(e,n10)+pow(e,n11)+pow(e,n12)+pow(e,n13)+pow(e,n14)+pow(e,n15)+pow(e,n16));
  //a16=pow(e,n16)/(pow(e,n1)+pow(e,n2)+pow(e,n3)+pow(e,n4)+pow(e,n5)+pow(e,n6)+pow(e,n7)+pow(e,n8)+pow(e,n9)+pow(e,n10)+pow(e,n11)+pow(e,n12)+pow(e,n13)+pow(e,n14)+pow(e,n15)+pow(e,n16));

  float maximo=miArray[0];
  int idx_maximo=0;
  for (int i = 0; i < 7; i = i + 1) {
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
    Serial.println("LIMPIA");
    break;
  case 4:
    Serial.println("POLVO");
    break;
  case 5:
    Serial.println("QUEMADO");
    break;
  case 6:
    Serial.println("TE");
    break;
}

}
