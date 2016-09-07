#define AMARELO 0
#define VERMELHO 1
#define AZUL 2
#define VERDE 3

int notas[4];
int leds[4];
int botoes[4];

#define CAMPAINHA 13
#define INTERVALO 500
#define COMPRIMENTO 11
int sequencia[COMPRIMENTO] = {
  AZUL, 
  VERMELHO, 
  VERMELHO, 
  VERDE, 
  AMARELO,
  AZUL,
  VERDE,
  AZUL,
  AMARELO,
  VERMELHO,
  VERDE
};

void setup() {
  leds[AMARELO] = 2;
  leds[VERMELHO] = 3;
  leds[AZUL] = 4;
  leds[VERDE] = 5;

  botoes[AMARELO] = 6;
  botoes[VERMELHO] = 7;
  botoes[AZUL] = 8;
  botoes[VERDE] = 9;

  notas[AMARELO] = 442;          //A1
  notas[VERMELHO] = 442*sqrt(2); //Eb1
  notas[AZUL] = 884;             //A2
  notas[VERDE] = 884*sqrt(2);    //Eb2

  for (int i=0; i<4; i++){
    pinMode(leds[i], OUTPUT);
    pinMode(botoes[i], INPUT);
  }
  pinMode(CAMPAINHA, OUTPUT);
}

void loop() {

  // reprodução da sequencia
  for (int i=0; i<COMPRIMENTO; i++){
    int atual = sequencia[i];
    digitalWrite(leds[atual], HIGH);
    tone(CAMPAINHA, notas[atual], INTERVALO);
    delay(INTERVALO);
    digitalWrite(leds[atual], LOW);
    delay(INTERVALO/2);
  }
  delay(INTERVALO*4);
  
  // leitura dos botões:
  for (int i=0; i<COMPRIMENTO; i++){
    for (int cor=0; cor<4; cor++){
      if (digitalRead(botoes[cor])==HIGH){
        digitalWrite(leds[cor], HIGH);
        tone(CAMPAINHA, notas[cor], INTERVALO);
        delay(INTERVALO);
        digitalWrite(leds[cor], LOW); 
        delay(INTERVALO/2);
      }
    }
  }
  delay(INTERVALO*2);
}


