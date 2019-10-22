#include <Wire.h>

#define startButton 2
#define ledDo 6
#define ledOk 7
byte a; // Primeiro Led
byte b; // Segundo Led
byte c; // Terceiro Led
byte d; // Quarto Led
byte e; // Quinto Led
byte f; // Gabarito Primeiro Led
byte g; // Gabarito Segundo Led
byte h; // Gabarito Terceiro Led
byte i; // Gabarito Quarto Led
byte j; // Gabarito Quinto Led
byte buttonPressed[] = {0, 0, 0, 0};
byte buttonState[] = {0, 0, 0, 0};
byte button[] = {3, 4, 5, 8}; // 3-VM  4-VD  5-AM  6-AZ
byte ledpin[] = {9, 10, 11, 12}; // 9-VM  10-VD  11-AM  12-AZ
byte fim = 0;
char comando = 'X'; // Comando da central para começar o jogo
char v = 'Y';
byte error = 0; // Contador de erros
byte start = 0;
int timer1 = 1000; // Tempo led
int timer2 = 500;  // Tempo erro
byte level = 0; // Variavel de níveis do jogo


void setup() {

// Comunicação com a central:
Wire.begin(2);
Wire.onReceive(receiveEvent);
Wire.onRequest(requestEvent);

pinMode(ledDo, OUTPUT);
pinMode(ledOk, OUTPUT);

for(byte x=0; x<4; x++)  // Leds Output
  {
    pinMode(ledpin[x], OUTPUT);
  }
for(byte x=0; x<4; x++) // Botões Input
  {
    pinMode(button[x],INPUT);
  }

randomSeed(analogRead(A0));
a = random(0,4); // Primeiro Led
b = random(0,4); // Segundo Led
c = random(0,4); // Terceiro Led
d = random(0,4); // Quarto Led
e = random(0,4); // Quinto Led

// Gabarito...
switch (a){
  case 0:
    f = 1;
    break;
  case 1:
    f = 3;
    break;
  case 2:
    f = 0;
    break;
  case 3:
    f = 2;
    break;
  }

  switch (b){
  case 0:
    g = 3;
    break;
  case 1:
    g = 0;
    break;
  case 2:
    g = 2;
    break;
  case 3:
    g = 1;
    break;
  }

  switch (c){
  case 0:
    h = 2;
    break;
  case 1:
    h = 1;
    break;
  case 2:
    h = 3;
    break;
  case 3:
    h = 0;
    break;
  }
  switch (d){
  case 0:
    i = 0;
    break;
  case 1:
    i = 2;
    break;
  case 2:
    i = 1;
    break;
  case 3:
    i = 3;
    break;
  }
  switch (e){
  case 0:
    j = 3;
    break;
  case 1:
    j = 2;
    break;
  case 2:
    j = 0;
    break;
  case 3:
    j = 1;
    break;
  }
}

// Função receber dados da central:
void receiveEvent (char bytes){
  v = Wire.read();
  comando = v;
  delay(100);
  }

// Função enviar dados para central:
void requestEvent (){
  Wire.write(error);
  Wire.write(fim);
    }
  
void primeiraLeitura(){
  for(;;){
      for(byte y=0;y<4;y++){
       buttonState[y] = {digitalRead(button[y])};
      }

      //Setando variaveis para os botões pressionados...
      for(byte w=0;w<4;w++){
        if(buttonState[w] == HIGH){
          buttonPressed[w] = 1;
          }
        }

      // Caso acerte, avança. Caso erre, soma um erro...
      if(buttonPressed[f] == 1){
        delay(250);
        break;
        }
       else if ((buttonPressed[f]==0 && buttonPressed[0]==1)||(buttonPressed[f]==0 && buttonPressed[1]==1)||(buttonPressed[f]==0 && buttonPressed[2]==1)||(buttonPressed[f]==0 && buttonPressed[3]==1)){
        error++;
        delay(timer2);
        for(byte z=0;z<4;z++){
          buttonPressed[z] = {0};
        }
        }
      }
  }

void segundaLeitura(){
  for(;;){
          for(byte y=0;y<4;y++){
            buttonState[y] = {digitalRead(button[y])};
          }

        //Setando variaveis para os botões pressionados...
        for(byte w=0;w<4;w++){
          if(buttonState[w] == HIGH){
            buttonPressed[w] = 1;
            }
          }

        // Caso acerte, avança. Caso erre, soma um erro...
        if(buttonPressed[g] == 1){
          delay(250);
          break;
          }
        else if ((buttonPressed[g]==0 && buttonPressed[0]==1)||(buttonPressed[g]==0 && buttonPressed[1]==1)||(buttonPressed[g]==0 && buttonPressed[2]==1)||(buttonPressed[g]==0 && buttonPressed[3]==1)){
           error++;
           delay(timer2);
          for(byte z=0;z<4;z++){
            buttonPressed[z] = {0};
        }
        }
        }
  }

void terceiraLeitura(){
  for(;;){
          for(byte y=0;y<4;y++){
            buttonState[y] = {digitalRead(button[y])};
          }

        //Setando variaveis para os botões pressionados...
        for(int w=0;w<4;w++){
          if(buttonState[w] == HIGH){
            buttonPressed[w] = 1;
            }
          }

        // Caso acerte, avança. Caso erre, soma um erro...
        if(buttonPressed[h] == 1){
          delay(250);
          break;
          }
        else if ((buttonPressed[h]==0 && buttonPressed[0]==1)||(buttonPressed[h]==0 && buttonPressed[1]==1)||(buttonPressed[h]==0 && buttonPressed[2]==1)||(buttonPressed[h]==0 && buttonPressed[3]==1)){
          error++;
          delay(timer2);
          for(byte z=0;z<4;z++){
            buttonPressed[z] = {0};
        }
        }
        }
  }

void quartaLeitura(){
  for(;;){
          for(byte y=0;y<4;y++){
            buttonState[y] = {digitalRead(button[y])};
          }

        //Setando variaveis para os botões pressionados...
        for(byte w=0;w<4;w++){
          if(buttonState[w] == HIGH){
            buttonPressed[w] = 1;
            }
          }

        // Caso acerte, avança. Caso erre, soma um erro...
        if(buttonPressed[i] == 1){
          delay(250);
          break;
          }
        else if ((buttonPressed[i]==0 && buttonPressed[0]==1)||(buttonPressed[i]==0 && buttonPressed[1]==1)||(buttonPressed[i]==0 && buttonPressed[2]==1)||(buttonPressed[i]==0 && buttonPressed[3]==1)){
          error++;
          delay(timer2);
          for(byte z=0;z<4;z++){
            buttonPressed[z] = {0};
        }
        }
        }
  }

void loop() { 
  
if(comando == 'B' && fim == 0){

digitalWrite(ledDo, HIGH);

for(byte z=0;z<4;z++){
  buttonPressed[z] = {0};
}

// Apertando o botão start o jogo começa
while(start==0){
  byte p = digitalRead(startButton);
  if(p!=0 && fim==0){
    start++;
  }
 }

// O jogo inicia aqui:

/////// Fase 1: /////////////////////////////////////////////////////////////////////////////////////
    //led piscando...
    delay(timer1);
    digitalWrite(ledpin[a],HIGH);
    delay(timer1);
    digitalWrite(ledpin[a],LOW);
    
    //Leitura dos botões...
    primeiraLeitura();

     // Passa para o próximo level...
     delay(500);
     for(byte z=0;z<4;z++){
      buttonPressed[z] = {0};
     }
     
/////// Fase 2: /////////////////////////////////////////////////////////////////////////////////////
    //led piscando...
    delay(timer1);
    digitalWrite(ledpin[a],HIGH);
    delay(timer1);
    digitalWrite(ledpin[a],LOW);
    delay(timer1);
    digitalWrite(ledpin[b],HIGH);
    delay(timer1);
    digitalWrite(ledpin[b],LOW);

        // 1ª Leitura dos botões...
        primeiraLeitura();
      
        for(byte z=0;z<4;z++){
         buttonPressed[z] = {0};
        }

        // 2ª Leitura dos botões...
        segundaLeitura();
      
    // Reseta as variaveis de botão.
     for(byte z=0;z<4;z++){
      buttonPressed[z] = {0};
     }

/////// Fase 3: /////////////////////////////////////////////////////////////////////////////////////
    //led piscando...
    delay(timer1);
    digitalWrite(ledpin[a],HIGH);
    delay(timer1);
    digitalWrite(ledpin[a],LOW);
    delay(timer1);
    digitalWrite(ledpin[b],HIGH);
    delay(timer1);
    digitalWrite(ledpin[b],LOW);
    delay(timer1);
    digitalWrite(ledpin[c],HIGH);
    delay(timer1);
    digitalWrite(ledpin[c],LOW);

    // 1ª Leitura dos botões...
        primeiraLeitura();
        
        for(byte z=0;z<4;z++){
         buttonPressed[z] = {0};
        }

        // 2ª Leitura dos botões...
        segundaLeitura();
        
         // Reseta as variaveis de botão.
        for(byte z=0;z<4;z++){
          buttonPressed[z] = {0};
        }

        // 3ª Leitura dos botões...
        terceiraLeitura();

       // Reseta as variaveis de botão.
        for(byte z=0;z<4;z++){
          buttonPressed[z] = {0};
        }

/////// Fase 4: /////////////////////////////////////////////////////////////////////////////////////
    //led piscando...
    delay(timer1);
    digitalWrite(ledpin[a],HIGH);
    delay(timer1);
    digitalWrite(ledpin[a],LOW);
    delay(timer1);
    digitalWrite(ledpin[b],HIGH);
    delay(timer1);
    digitalWrite(ledpin[b],LOW);
    delay(timer1);
    digitalWrite(ledpin[c],HIGH);
    delay(timer1);
    digitalWrite(ledpin[c],LOW);
    delay(timer1);
    digitalWrite(ledpin[d],HIGH);
    delay(timer1);
    digitalWrite(ledpin[d],LOW);

    // 1ª Leitura dos botões...
        primeiraLeitura();
        
        for(byte z=0;z<4;z++){
         buttonPressed[z] = {0};
        }

        // 2ª Leitura dos botões...
        segundaLeitura();
        
         // Reseta as variaveis de botão.
        for(byte z=0;z<4;z++){
          buttonPressed[z] = {0};
        }

        // 3ª Leitura dos botões...
        terceiraLeitura();

       // Reseta as variaveis de botão.
        for(byte z=0;z<4;z++){
          buttonPressed[z] = {0};
        }

        // 4ª Leitura dos botões...
        quartaLeitura();

       // Reseta as variaveis de botão.
        for(byte z=0;z<4;z++){
          buttonPressed[z] = {0};
        }

/////// Fase 5: /////////////////////////////////////////////////////////////////////////////////////
    //led piscando...
    delay(timer1);
    digitalWrite(ledpin[a],HIGH);
    delay(timer1);
    digitalWrite(ledpin[a],LOW);
    delay(timer1);
    digitalWrite(ledpin[b],HIGH);
    delay(timer1);
    digitalWrite(ledpin[b],LOW);
    delay(timer1);
    digitalWrite(ledpin[c],HIGH);
    delay(timer1);
    digitalWrite(ledpin[c],LOW);
    delay(timer1);
    digitalWrite(ledpin[d],HIGH);
    delay(timer1);
    digitalWrite(ledpin[d],LOW); 
    delay(timer1);
    digitalWrite(ledpin[e],HIGH);
    delay(timer1);
    digitalWrite(ledpin[e],LOW);   

    // 1ª Leitura dos botões...
        primeiraLeitura();
        
        for(byte z=0;z<4;z++){
         buttonPressed[z] = {0};
        }

        // 2ª Leitura dos botões...
        segundaLeitura();
        
         // Reseta as variaveis de botão.
        for(byte z=0;z<4;z++){
          buttonPressed[z] = {0};
        }

        // 3ª Leitura dos botões...
        terceiraLeitura();

       // Reseta as variaveis de botão.
        for(byte z=0;z<4;z++){
          buttonPressed[z] = {0};
        }

        // 4ª Leitura dos botões...
        quartaLeitura();

       // Reseta as variaveis de botão.
        for(byte z=0;z<4;z++){
          buttonPressed[z] = {0};
        }
        
    // 5ª Leitura dos botões...
        for(;;){
          for(byte y=0;y<4;y++){
            buttonState[y] = {digitalRead(button[y])};
          }

        //Setando variaveis para os botões pressionados...
        for(byte w=0;w<4;w++){
          if(buttonState[w] == HIGH){
            buttonPressed[w] = 1;
            }
          }

        // Caso acerte, avança. Caso erre, soma um erro...
        if(buttonPressed[j] == 1){
          delay(250);
          break;
          }
        else if ((buttonPressed[j]==0 && buttonPressed[0]==1)||(buttonPressed[j]==0 && buttonPressed[1]==1)||(buttonPressed[j]==0 && buttonPressed[2]==1)||(buttonPressed[j]==0 && buttonPressed[3]==1)){
          error++;
          delay(timer2);
          for(byte z=0;z<4;z++){
            buttonPressed[z] = {0};
        }
        }
        }

       // Reseta as variaveis de botão.
        for(byte z=0;z<4;z++){
          buttonPressed[z] = {0};
        }

        digitalWrite(ledDo, LOW);
        digitalWrite(ledOk, HIGH);
        start = 0;
        fim = 1;}
  }
  




  


    
  
