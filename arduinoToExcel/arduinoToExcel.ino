#define S0 4    // S0 a pin 4
#define S1 5    // S1 a pin 5
#define S2 6    // S2 a pin 6
#define S3 7    // S3 a pin 7
#define salidaTCS 8 // salidaTCS a pin 8

int ledPin = 13;  
int sensorValue = 0; 

void setup() {
  pinMode(S0, OUTPUT);    // pin 4 como salida
  pinMode(S1, OUTPUT);    // pin 5 como salida
  pinMode(S2, OUTPUT);    // pin 6 como salida
  pinMode(S3, OUTPUT);    // pin 7 como salida
  pinMode(salidaTCS, INPUT);  // pin 8 como salida
  
  digitalWrite(S0,HIGH);  // establece frecuencia de salida
  digitalWrite(S1,LOW);   // del modulo al 20 por ciento
  
  Serial.begin(115200);
}

int i = 0;
void loop() {
  digitalWrite(S2,LOW); // establece fotodiodos
  digitalWrite(S3,LOW); // con filtro rojo
  int rojo = pulseIn(salidaTCS, LOW); // obtiene duracion de pulso de salida del sensor
  //delay(10);
  digitalWrite(S2,HIGH);  // establece fotodiodos
  digitalWrite(S3,HIGH);  // con filtro verde
  int verde = pulseIn(salidaTCS, LOW); 
  //delay(10000);
  digitalWrite(S2,LOW); // establece fotodiodos
  digitalWrite(S3,HIGH); // con filtro azul
  int azul = pulseIn(salidaTCS, LOW);
  //delay(10000);
  Serial.print(i);
  Serial.print(",");
  Serial.print(rojo);
  Serial.print(",");
  Serial.print(verde);
  Serial.print(",");
  Serial.print(azul);
  Serial.println(";");
  i = i + 1;

  delay(100);
}
