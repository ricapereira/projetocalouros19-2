# include <Wire.h>
// Matriz de bits para representar os números de 0 a 9:
int numero[11][8] = { // 11 linhas, 8 colunas
 { 0,0,0,0,0,0,1,1 }, //0
 { 1,0,0,1,1,1,1,1 }, //1
 { 0,0,1,0,0,1,0,1 }, //2
 { 0,0,0,0,1,1,0,1 }, //3
 { 1,0,0,1,1,0,0,1 }, //4
 { 0,1,0,0,1,0,0,1 }, //5
 { 1,1,0,0,0,0,0,1 }, //6
 { 0,0,0,1,1,1,1,1 }, //7
 { 0,0,0,0,0,0,0,1 }, //8
 { 0,0,0,1,1,0,0,1 }, //9
 { 1,1,1,1,1,1,1,0 } //ponto decimal
};
// Configurar os pinos digitais associados a cada segmento:
const int segmentos[8] = { 22,23,24,25,26,27,28,29 };
// 2 = segmento a
// 3 = segmento b
// 4 = segmento c
// 5 = segmento d
// 6 = segmento e
// 7 = segmento f
// 8 = segmento g
// 9 = ponto decimal

char comando = 'X';
int erro = 0;
int fim = 0;

void setup() {
 Serial.begin(9600);
 Wire.begin(3);
 Wire.onReceive(receiveEvent);
 Wire.onRequest(requestEvent); 
 for (int i = 0; i <= 7; i++) {
   pinMode(segmentos[i], OUTPUT);
 }
}

// Função receber dados da central:
void receiveEvent (char bytes){
  comando = Wire.read();
  delay(100);
  }

// Função enviar dados para central:
void requestEvent (){
  Wire.write(erro);
  if (erro >= 3){
    erro=0;
  }
  
  Wire.write(fim);
    }

void loop() {
  Serial.print(erro);
  erro=0;
//Serial.print(comando);
  // put your main code here, to run repeatedly:
int fase = 1;
int button[] = { 2, 3, 4, 5}; //2= botão 1 3= botão 2 e assim sucessivamente //The four button input pins
int ledpin[] = {6, 7, 8, 9, 10, 11, 12,};  // LED pins //7 vermelho avisando p usar //8 verde avisando que fim // 9 a 13 fase na ordem
int f, v1, v2, v3, v4;


for ( int x = 0 ; x < 8 ; x ++)   // pinos do LED são saídas
  {
   pinMode (ledpin [x], OUTPUT);
  }
for ( int x = 0 ; x < 4 ; x ++)
  {
   pinMode (button [x], INPUT);  // pinos do botão são entradas
   digitalWrite (button [x],LOW);  // habilita pulldown interno; os botões começam na posição baixa;
  }
if(comando == 'B') { 
digitalWrite(ledpin[6], HIGH);
boolean inicial = digitalRead(button[0]);
if(inicial == HIGH){
    while(fase<6){
        int numero;  
        int numeronatela;
        int ledfase;
        int buttonPressed[] = {0, 0, 0, 0};
        int buttonState[] = {0, 0, 0, 0};
        
      
          if(fase == 1){
              randomSeed(analogRead(3));
              numero = random(4);
              numeronatela = numero +1;
              mostraNumero(numeronatela);  
              ledfase = fase - 1;
              digitalWrite(ledpin[ledfase-1], LOW);
              digitalWrite(ledpin[ledfase], HIGH);
              delay(2000);
              for(;;){
                for(int y=0;y<4;y++){
                  buttonState[y] = {digitalRead(button[y])};
                }
      
              //Setando variaveis para os botões pressionados...
              for(int w=0;w<4;w++){
                if(buttonState[w] == HIGH){
                  buttonPressed[w] = 1;
                  }
                }
                switch (numeronatela){
                  case 1:
                    f = 1;
                    break;
                  case 2:
                    f = 1;
                    break;
                  case 3:
                    f = 2;
                    break;
                  case 4:
                    f = 3;
                    break;
                  }               
      
              // Caso acerte, avança. Caso erre, soma um erro...
              if(buttonPressed[f] == 1){
                digitalWrite(ledpin[5], HIGH);
                delay(500);
                digitalWrite(ledpin[5], LOW);
                v1 = f; 
                fase++;               
                delay(250);
                break;
                }
              else if ((buttonPressed[f]==0 && buttonPressed[0]==1)||(buttonPressed[f]==0 && buttonPressed[1]==1)||(buttonPressed[f]==0 && buttonPressed[2]==1)||(buttonPressed[f]==0 && buttonPressed[3]==1)){
                erro++;
                
                delay(500);
                for(int z=0;z<4;z++){
                  buttonPressed[z] = {0};
              }
              }
              }
              for(int z=0;z<4;z++){
               buttonPressed[z] = {0};
              }
          }

          if(fase == 2){
              randomSeed(analogRead(3));
              numero = random(4);
              numeronatela = numero +1;
              mostraNumero(numeronatela);  
              ledfase = fase - 1;            
              digitalWrite(ledpin[ledfase-1], LOW);
              digitalWrite(ledpin[ledfase], HIGH);
              delay(2000);
              for(;;){
                for(int y=0;y<4;y++){
                  buttonState[y] = {digitalRead(button[y])};
                }
      
              //Setando variaveis para os botões pressionados...
              for(int w=0;w<4;w++){
                if(buttonState[w] == HIGH){
                  buttonPressed[w] = 1;
                  }
                }
                switch (numeronatela){
                  case 1:
                    f = 3;
                    break;
                  case 2:
                    f = v1;
                    break;
                  case 3:
                    f = 0;
                    break;
                  case 4:
                    f = v1;
                    break;
                  }               
      
              // Caso acerte, avança. Caso erre, soma um erro...
              if(buttonPressed[f] == 1){
                digitalWrite(ledpin[5], HIGH);
                delay(500);
                digitalWrite(ledpin[5], LOW);
                v2 = f; 
                fase++;               
                delay(250);
                break;
                }
              else if ((buttonPressed[f]==0 && buttonPressed[0]==1)||(buttonPressed[f]==0 && buttonPressed[1]==1)||(buttonPressed[f]==0 && buttonPressed[2]==1)||(buttonPressed[f]==0 && buttonPressed[3]==1)){
                erro++;
                
                delay(500);
                for(int z=0;z<4;z++){
                buttonPressed[z] = {0};
              }
              }
              }
              for(int z=0;z<4;z++){
               buttonPressed[z] = {0};
              }
          }
          
          if(fase == 3){
              randomSeed(analogRead(3));
              numero = random(4);
              numeronatela = numero +1;
              mostraNumero(numeronatela);  
              ledfase = fase - 1; 
              digitalWrite(ledpin[ledfase-1], LOW);
              digitalWrite(ledpin[ledfase], HIGH);
              delay(2000);
              for(;;){
                for(int y=0;y<4;y++){
                  buttonState[y] = {digitalRead(button[y])};
                }
      
              //Setando variaveis para os botões pressionados...
              for(int w=0;w<4;w++){
                if(buttonState[w] == HIGH){
                  buttonPressed[w] = 1;
                  }
                }
                switch (numeronatela){
                  case 1:
                    f = v2;
                    break;
                  case 2:
                    f = v1;
                    break;
                  case 3:
                    f = 2;
                    break;
                  case 4:
                    f = 3;
                    break;
                  }               
      
              // Caso acerte, avança. Caso erre, soma um erro...
              if(buttonPressed[f] == 1){
                digitalWrite(ledpin[5], HIGH);
                delay(500);
                digitalWrite(ledpin[5], LOW);
                v3 = f; 
                fase++;               
                delay(250);
                break;
                }
              else if ((buttonPressed[f]==0 && buttonPressed[0]==1)||(buttonPressed[f]==0 && buttonPressed[1]==1)||(buttonPressed[f]==0 && buttonPressed[2]==1)||(buttonPressed[f]==0 && buttonPressed[3]==1)){
                erro++;
                
                delay(500);
                for(int z=0;z<4;z++){
                  buttonPressed[z] = {0};
              }
              }
              }
              for(int z=0;z<4;z++){
               buttonPressed[z] = {0};
              }
          }
          if(fase == 4){
              randomSeed(analogRead(3));
              numero = random(4);
              numeronatela = numero +1;
              mostraNumero(numeronatela);  
              ledfase = fase - 1;            
              digitalWrite(ledpin[ledfase-1], LOW);
              digitalWrite(ledpin[ledfase], HIGH);
              delay(2000);
              for(;;){
                for(int y=0;y<4;y++){
                  buttonState[y] = {digitalRead(button[y])};
                }
      
              //Setando variaveis para os botões pressionados...
              for(int w=0;w<4;w++){
                if(buttonState[w] == HIGH){
                  buttonPressed[w] = 1;
                  }
                }
                switch (numeronatela){
                  case 1:
                    f = v1;
                    break;
                  case 2:
                    f = 0;
                    break;
                  case 3:
                    f = v2;
                    break;
                  case 4:
                    f = v2;
                    break;
                  }               
      
              // Caso acerte, avança. Caso erre, soma um erro...
              if(buttonPressed[f] == 1){
                digitalWrite(ledpin[5], HIGH);
                delay(500);
                digitalWrite(ledpin[5], LOW);
                v4 = f; 
                fase++;               
                delay(250);
                break;
                }
              else if ((buttonPressed[f]==0 && buttonPressed[0]==1)||(buttonPressed[f]==0 && buttonPressed[1]==1)||(buttonPressed[f]==0 && buttonPressed[2]==1)||(buttonPressed[f]==0 && buttonPressed[3]==1)){
                erro++;
                
                delay(500);
                for(int z=0;z<4;z++){
                  buttonPressed[z] = {0};
              }
              }
              }
              for(int z=0;z<4;z++){
               buttonPressed[z] = {0};
              }
          }

          if(fase == 5){
              randomSeed(analogRead(3));
              numero = random(4);
              numeronatela = numero +1;
              mostraNumero(numeronatela);  
              ledfase = fase - 1;            
              digitalWrite(ledpin[ledfase-1], LOW);
              digitalWrite(ledpin[ledfase], HIGH);
              delay(2000);
              for(;;){
                for(int y=0;y<4;y++){
                  buttonState[y] = {digitalRead(button[y])};
                }
      
              //Setando variaveis para os botões pressionados...
              for(int w=0;w<4;w++){
                if(buttonState[w] == HIGH){
                  buttonPressed[w] = 1;
                  }
                }
                switch (numeronatela){
                  case 1:
                    f = v1;
                    break;
                  case 2:
                    f = v2;
                    break;
                  case 3:
                    f = v3;
                    break;
                  case 4:
                    f = v4;
                    break;
                  }               
      
              // Caso acerte, avança. Caso erre, soma um erro...
              if(buttonPressed[f] == 1){
                digitalWrite(ledpin[5], HIGH);
                digitalWrite(ledpin[ledfase], LOW);
                digitalWrite(ledpin[6], LOW);
                fim++;               
                delay(250);
                break;
                }
              else if ((buttonPressed[f]==0 && buttonPressed[0]==1)||(buttonPressed[f]==0 && buttonPressed[1]==1)||(buttonPressed[f]==0 && buttonPressed[2]==1)||(buttonPressed[f]==0 && buttonPressed[3]==1)){
                erro++;
                
                delay(500);
                for(int z=0;z<4;z++){
                  buttonPressed[z] = {0};
              }
              }
              }
              for(int z=0;z<4;z++){
               buttonPressed[z] = {0};
              }
          }
    }
}
}
}

// Implementando a função mostraNumero, que exibe os numeros em sequência a cada 1 segundo:
void mostraNumero(int valor) { // valor é a linha (número a mostrar)
 int pino = 22; // começar contagem no pino 2
 for (int i = 0; i < 8; i++) {
 digitalWrite(pino, numero[valor][i]); // fixa na linha e aciona os bits de cada coluna (0 ou 1)
 pino++;
 }
}
