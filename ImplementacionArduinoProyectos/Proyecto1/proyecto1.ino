#include<math.h>

#define S0 4    // S0 a pin 4
#define S1 5    // S1 a pin 5
#define S2 6    // S2 a pin 6
#define S3 7    // S3 a pin 7
#define salidaTCS 8 // salidaTCS a pin 8

int p1,p2,p3; // variables para la entrada de la neurona
float n1,n2,n3,n4,n5,n6,n7,n8,n9,n10,n11,n12,n13,n14,n15,n16; //variables para la salida de la naurona
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
  
  n1=p1*(-0.6253819)+p2*(0.55097234)+ p3*(0.49116465) +(8.6934674e-01); //entradas por los pesos mas el bias
  n2=p1*(0.6402558)+p2*(0.2147235)+ p3*(-0.57410747) +(-1.6040288e+00);
  n3=p1*(0.7315958)+p2*(-0.82305175)+ p3*(0.54581094) +(-3.0411396e+00);
  n4=p1*(-0.157087)+p2*(0.34974766)+ p3*(0.40838584) +(9.2198582e+00);
  n5=p1*(-0.2796196)+p2*(0.10634955)+ p3*(0.82741344) +(-4.2633052e+00);
  n6=p1*(-0.36351466)+p2*(0.48321602)+ p3*(0.46353158) +( -4.8168931e+0);
  n7=p1*(0.53713095)+p2*(0.07216033)+ p3*(-0.12655836) +(5.6632471e+00);
  n8=p1*(-0.0332643)+p2*(0.1458602)+ p3*(0.6219479) +(-6.0232849e+00);
  n9=p1*(0.3225097)+p2*(0.08742931)+ p3*(0.17330442) +(1.8121088e+00);
  n10=p1*(0.13049965)+p2*(0.1451781)+ p3*(0.39037892) +(-8.2907791e+00);
  n11=p1*(0.28945106)+p2*(0.23819429)+ p3*(0.01212402) +(-1.8871977e+00);
  n12=p1*(0.01583506)+p2*(0.03626081)+ p3*(0.35666707) +( 2.3661432e+01);
  n13=p1*(0.8619777)+p2*(-0.42877027)+ p3*(-0.10231501) +(3.6174040e+00);
  n14=p1*(-0.4209774)+p2*(0.86228704)+ p3*(-0.20726198) +( -4.0074303e-03);
  n15=p1*( 0.6219712)+p2*(0.12278113)+ p3*(-0.350343) +( -1.1478107e+00);
  n16=p1*(-0.16828847)+p2*(0.7121539)+ p3*(-0.09243802) +(-6.8009229e+00);

  float miArray[] = {n1,n2,n3,n4,n5,n6,n7,n8,n9,n10,n11,n12,n13,n14,n15,n16};
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
  for (int i = 0; i < 16; i = i + 1) {
    if (miArray[i]>maximo){
      maximo=miArray[i];
      idx_maximo=i;
    }
  }


  switch (idx_maximo) {
  case 0:
    Serial.println("ROJO");
    break;
  case 1:
    Serial.println("AZUL");
    break;
  case 2:
    Serial.println("VERDE");
    break;
  case 3:
    Serial.println("ACERO QUIRURGICO");
    break;
  case 4:
    Serial.println("PAPEL MADERA");
    break;
  case 5:
    Serial.println("PIEL MANO");
    break;
  case 6:
    Serial.println("PLASTICO NEGRO");
    break;
  case 7:
    Serial.println("PORCELANA BLANCA");
    break;
  case 8:
    Serial.println("TELGOPOR");
    break;
  case 9:
    Serial.println("LIJA FINA");
    break;
  case 10:
    Serial.println("LIJA GRUESA");
    break;
  case 11:
    Serial.println("ALGODON");
    break;
  case 12:
    Serial.println("CIAN");
    break;
  case 13:
    Serial.println("MAGENTA");
    break;
  case 14:
    Serial.println("VERDE Y AZUL");
    break;
  case 15:
    Serial.println("ROJO Y AZUL");
    break;
}

}
//-0.6253819 ,  0.6402558 ,  0.7315958 , -0.157087  , -0.2796196 , -0.36351466,  0.53713095, -0.0332643 ,  0.3225097 ,  0.13049965, 0.28945106,  0.01583506,  0.8619777 , -0.4209774 ,  0.6219712 , -0.16828847,
        
//0.55097234,  0.2147235 , -0.82305175,  0.34974766,  0.10634955,0.48321602,  0.07216033,  0.1458602 ,  0.08742931,  0.1451781 ,0.23819429,  0.03626081, -0.42877027,  0.86228704,  0.12278113, 0.7121539 ,
        
//0.49116465, -0.57410747,  0.54581094,  0.40838584,  0.82741344, 0.46353158, -0.12655836,  0.6219479 ,  0.17330442,  0.39037892, 0.01212402,  0.35666707, -0.10231501, -0.20726198, -0.350343  ,-0.09243802,
 
//8.6934674e-01, -1.6040288e+00, -3.0411396e+00,  9.2198582e+00,-4.2633052e+00, -4.8168931e+00, -5.6632471e+00, -6.0232849e+00,1.8121088e+00, -8.2907791e+00, -1.8871977e+00,  2.3661432e+01,3.6174040e+00, -4.0074303e-03, -1.1478107e+00, -6.8009229e+00,
