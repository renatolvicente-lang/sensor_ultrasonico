#include <NewPing.h>

#define pinTrig 14
#define pinEcho 12
#define led 26

NewPing sonar(pinTrig, pinEcho, 400);// cria um objeto "sonar" onde é guardado o numero do pino do trigger, do echo e a distancia máxima

void setup() {

  Serial.begin(115200);
  pinMode(led, OUTPUT);
  Serial.println("Hello, ESP32!");
}

void loop() {

delay(500);

unsigned int leituraSensor = sonar.ping_median(5);// le o que o sensor transmite
unsigned int distanciaCM = sonar.convert_cm(leituraSensor);//converte o que o sensor transmite para cm

  Serial.print("Distância:  ");
  Serial.print(distanciaCM);
  Serial.println("cm");

if(distanciaCM < 40){
  digitalWrite(led, HIGH);
}else{
  digitalWrite(led, LOW);
}

delay(500);
}
