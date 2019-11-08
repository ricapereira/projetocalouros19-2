#include <Wire.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int controle_1 = 0;
byte variavel_1 = 0;
int controle_2 = 0;
byte variavel_2 = 0;
int controle_3 = 0;
byte variavel_3 = 0;
int controle_4 = 0;
byte variavel_4 = 0;
int controle_5 = 0;
byte variavel_5 = 0;
int controle_enviar = 0;
int estagio_jogo = -1;
byte erro_local = 0;
byte erro_geral;
int numero_aleatorio;
byte resposta_1;
byte resposta_2;
byte resposta_3;
byte resposta_4;
byte resposta_5;
char posicao_1[5];
char posicao_2[5];
char posicao_3[5];
char posicao_4[5];
char posicao_5[5];
char comando = 'A';
int fim = 0;

void receiveEvent(int bytes){
  char y = Wire.read();
  comando = y;
  int x = Wire.read();
  erro_geral = x;
  delay(100); 
  }

void requestEvent(){
  Wire.write(erro_local);
  Wire.write(fim);
}
                                  
void setup(){
  Wire.begin(1);
  Wire.onReceive(receiveEvent);
  Wire.onRequest(requestEvent);
  lcd.begin (16, 2); 
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  pinMode(10, INPUT);
  pinMode(13, INPUT);
  }

void loop(){
  if(comando == 'A'){
    estagio_jogo = -1;
    erro_local = 0;
    randomSeed(analogRead(3));
    numero_aleatorio = random(20);
    switch(numero_aleatorio){
      case 0:
        resposta_1 = 0;
        resposta_2 = 0;
        resposta_3 = 0;
        resposta_4 = 0;
        resposta_5 = 0;
        posicao_1[0] = 'C';
        posicao_1[1] = 'X';
        posicao_1[2] = 'Z';
        posicao_1[3] = 'R'; 
        posicao_1[4] = 'J';
        posicao_2[0] = 'A';
        posicao_2[1] = 'I';
        posicao_2[2] = 'U';
        posicao_2[3] = 'S';
        posicao_2[4] = 'D';
        posicao_3[0] = 'I';
        posicao_3[1] = 'X';
        posicao_3[2] = 'P';
        posicao_3[3] = 'F';
        posicao_3[4] = 'R';
        posicao_4[0] = 'X';
        posicao_4[1] = 'N';
        posicao_4[2] = 'Q';
        posicao_4[3] = 'T';
        posicao_4[4] = 'E';
        posicao_5[0] = 'A'; 
        posicao_5[1] = 'V'; 
        posicao_5[2] = 'I'; 
        posicao_5[3] = 'N';
        posicao_5[4] = 'O';  
        break;
      case 1:
        resposta_1 = 1;
        resposta_2 = 1;
        resposta_3 = 1;
        resposta_4 = 1;
        resposta_5 = 1;
        posicao_1[0] = 'S';
        posicao_1[1] = 'P';
        posicao_1[2] = 'Z';
        posicao_1[3] = 'R'; 
        posicao_1[4] = 'T';
        posicao_2[0] = 'A';
        posicao_2[1] = 'E';
        posicao_2[2] = 'U';
        posicao_2[3] = 'O';
        posicao_2[4] = 'D';
        posicao_3[0] = 'I';
        posicao_3[1] = 'D';
        posicao_3[2] = 'T';
        posicao_3[3] = 'R';
        posicao_3[4] = 'S';
        posicao_4[0] = 'B';
        posicao_4[1] = 'R';
        posicao_4[2] = 'Q';
        posicao_4[3] = 'T';
        posicao_4[4] = 'E';
        posicao_5[0] = 'O'; 
        posicao_5[1] = 'A'; 
        posicao_5[2] = 'M'; 
        posicao_5[3] = 'N';
        posicao_5[4] = 'H';  
        break;
      case 2:
        resposta_1 = 2;
        resposta_2 = 3;
        resposta_3 = 4;
        resposta_4 = 2;
        resposta_5 = 3;
        posicao_1[0] = 'A';
        posicao_1[1] = 'B';
        posicao_1[2] = 'S';
        posicao_1[3] = 'J'; 
        posicao_1[4] = 'O';
        posicao_2[0] = 'C';
        posicao_2[1] = 'B';
        posicao_2[2] = 'N';
        posicao_2[3] = 'E';
        posicao_2[4] = 'Z';
        posicao_3[0] = 'R';
        posicao_3[1] = 'U';
        posicao_3[2] = 'M';
        posicao_3[3] = 'F';
        posicao_3[4] = 'N';
        posicao_4[0] = 'O';
        posicao_4[1] = 'U';
        posicao_4[2] = 'S';
        posicao_4[3] = 'N';
        posicao_4[4] = 'P';
        posicao_5[0] = 'I'; 
        posicao_5[1] = 'F'; 
        posicao_5[2] = 'K'; 
        posicao_5[3] = 'O';
        posicao_5[4] = 'J';  
        break;  
      case 3:
        resposta_1 = 1;
        resposta_2 = 0;
        resposta_3 = 4;
        resposta_4 = 3;
        resposta_5 = 3;
        posicao_1[0] = 'R';
        posicao_1[1] = 'N';
        posicao_1[2] = 'T';
        posicao_1[3] = 'G'; 
        posicao_1[4] = 'J';
        posicao_2[0] = 'O';
        posicao_2[1] = 'R';
        posicao_2[2] = 'A';
        posicao_2[3] = 'E';
        posicao_2[4] = 'I';
        posicao_3[0] = 'R';
        posicao_3[1] = 'S';
        posicao_3[2] = 'T';
        posicao_3[3] = 'U';
        posicao_3[4] = 'B';
        posicao_4[0] = 'V';
        posicao_4[1] = 'W';
        posicao_4[2] = 'X';
        posicao_4[3] = 'R';
        posicao_4[4] = 'Y';
        posicao_5[0] = 'Z'; 
        posicao_5[1] = 'R'; 
        posicao_5[2] = 'U'; 
        posicao_5[3] = 'E';
        posicao_5[4] = 'I';  
        break;
      case 4:
        resposta_1 = 2;
        resposta_2 = 1;
        resposta_3 = 0;
        resposta_4 = 4;
        resposta_5 = 4;
        posicao_1[0] = 'Y';
        posicao_1[1] = 'U';
        posicao_1[2] = 'C';
        posicao_1[3] = 'F'; 
        posicao_1[4] = 'Z';
        posicao_2[0] = 'A';
        posicao_2[1] = 'H';
        posicao_2[2] = 'E';
        posicao_2[3] = 'S';
        posicao_2[4] = 'R';
        posicao_3[0] = 'U';
        posicao_3[1] = 'X';
        posicao_3[2] = 'E';
        posicao_3[3] = 'Z';
        posicao_3[4] = 'Q';
        posicao_4[0] = 'Q';
        posicao_4[1] = 'L';
        posicao_4[2] = 'S';
        posicao_4[3] = 'M';
        posicao_4[4] = 'V';
        posicao_5[0] = 'Z'; 
        posicao_5[1] = 'S'; 
        posicao_5[2] = 'T'; 
        posicao_5[3] = 'R';
        posicao_5[4] = 'A';  
        break;
      case 5:
        resposta_1 = 3;
        resposta_2 = 3;
        resposta_3 = 0;
        resposta_4 = 3;
        resposta_5 = 1;
        posicao_1[0] = 'B';
        posicao_1[1] = 'O';
        posicao_1[2] = 'C';
        posicao_1[3] = 'T'; 
        posicao_1[4] = 'D';
        posicao_2[0] = 'F';
        posicao_2[1] = 'R';
        posicao_2[2] = 'X';
        posicao_2[3] = 'E';
        posicao_2[4] = 'C';
        posicao_3[0] = 'R';
        posicao_3[1] = 'Z';
        posicao_3[2] = 'E';
        posicao_3[3] = 'T';
        posicao_3[4] = 'U';
        posicao_4[0] = 'I';
        posicao_4[1] = 'X';
        posicao_4[2] = 'Q';
        posicao_4[3] = 'M';
        posicao_4[4] = 'L';
        posicao_5[0] = 'P'; 
        posicao_5[1] = 'O'; 
        posicao_5[2] = 'W'; 
        posicao_5[3] = 'S';
        posicao_5[4] = 'A';  
        break;
      case 6:
        resposta_1 = 0;
        resposta_2 = 2;
        resposta_3 = 4;
        resposta_4 = 1;
        resposta_5 = 3;
        posicao_1[0] = 'M';
        posicao_1[1] = 'E';
        posicao_1[2] = 'S';
        posicao_1[3] = 'K'; 
        posicao_1[4] = 'L';
        posicao_2[0] = 'A';
        posicao_2[1] = 'Z';
        posicao_2[2] = 'U';
        posicao_2[3] = 'X';
        posicao_2[4] = 'T';
        posicao_3[0] = 'R';
        posicao_3[1] = 'Q';
        posicao_3[2] = 'V';
        posicao_3[3] = 'N';
        posicao_3[4] = 'I';
        posicao_4[0] = 'K';
        posicao_4[1] = 'T';
        posicao_4[2] = 'Q';
        posicao_4[3] = 'P';
        posicao_4[4] = 'Z';
        posicao_5[0] = 'B'; 
        posicao_5[1] = 'E'; 
        posicao_5[2] = 'N'; 
        posicao_5[3] = 'O';
        posicao_5[4] = 'A';  
        break;
      case 7:
        resposta_1 = 2;
        resposta_2 = 0;
        resposta_3 = 1;
        resposta_4 = 2;
        resposta_5 = 3;
        posicao_1[0] = 'W';
        posicao_1[1] = 'F';
        posicao_1[2] = 'N';
        posicao_1[3] = 'H'; 
        posicao_1[4] = 'L';
        posicao_2[0] = 'E';
        posicao_2[1] = 'L';
        posicao_2[2] = 'O';
        posicao_2[3] = 'P';
        posicao_2[4] = 'Q';
        posicao_3[0] = 'H';
        posicao_3[1] = 'G';
        posicao_3[2] = 'K';
        posicao_3[3] = 'L';
        posicao_3[4] = 'Z';
        posicao_4[0] = 'A';
        posicao_4[1] = 'M';
        posicao_4[2] = 'R';
        posicao_4[3] = 'O';
        posicao_4[4] = 'P';
        posicao_5[0] = 'R'; 
        posicao_5[1] = 'S'; 
        posicao_5[2] = 'T'; 
        posicao_5[3] = 'O';
        posicao_5[4] = 'V';  
        break;
      case 8:
        resposta_1 = 4;
        resposta_2 = 4;
        resposta_3 = 2;
        resposta_4 = 2;
        resposta_5 = 1;
        posicao_1[0] = 'Y';
        posicao_1[1] = 'U';
        posicao_1[2] = 'D';
        posicao_1[3] = 'Q'; 
        posicao_1[4] = 'S';
        posicao_2[0] = 'P';
        posicao_2[1] = 'W';
        posicao_2[2] = 'M';
        posicao_2[3] = 'S';
        posicao_2[4] = 'O';
        posicao_3[0] = 'P';
        posicao_3[1] = 'Z';
        posicao_3[2] = 'N';
        posicao_3[3] = 'G';
        posicao_3[4] = 'F';
        posicao_4[0] = 'A';
        posicao_4[1] = 'E';
        posicao_4[2] = 'H';
        posicao_4[3] = 'R';
        posicao_4[4] = 'S';
        posicao_5[0] = 'T'; 
        posicao_5[1] = 'O'; 
        posicao_5[2] = 'H'; 
        posicao_5[3] = 'R';
        posicao_5[4] = 'A';  
        break;
      case 9:
        resposta_1 = 0;
        resposta_2 = 2;
        resposta_3 = 3;
        resposta_4 = 2;
        resposta_5 = 4;
        posicao_1[0] = 'M';
        posicao_1[1] = 'E';
        posicao_1[2] = 'C';
        posicao_1[3] = 'D'; 
        posicao_1[4] = 'A';
        posicao_2[0] = 'A';
        posicao_2[1] = 'E';
        posicao_2[2] = 'U';
        posicao_2[3] = 'I';
        posicao_2[4] = 'O';
        posicao_3[0] = 'R';
        posicao_3[1] = 'T';
        posicao_3[2] = 'H';
        posicao_3[3] = 'N';
        posicao_3[4] = 'J';
        posicao_4[0] = 'J';
        posicao_4[1] = 'H';
        posicao_4[2] = 'D';
        posicao_4[3] = 'E';
        posicao_4[4] = 'T';
        posicao_5[0] = 'P'; 
        posicao_5[1] = 'L'; 
        posicao_5[2] = 'F'; 
        posicao_5[3] = 'Z';
        posicao_5[4] = 'O';  
        break;
      case 10:
        resposta_1 = 3;
        resposta_2 = 3;
        resposta_3 = 4;
        resposta_4 = 2;
        resposta_5 = 1;
        posicao_1[0] = 'E';
        posicao_1[1] = 'R';
        posicao_1[2] = 'D';
        posicao_1[3] = 'O'; 
        posicao_1[4] = 'A';
        posicao_2[0] = 'K';
        posicao_2[1] = 'L';
        posicao_2[2] = 'O';
        posicao_2[3] = 'R';
        posicao_2[4] = 'P';
        posicao_3[0] = 'W';
        posicao_3[1] = 'E';
        posicao_3[2] = 'R';
        posicao_3[3] = 'C';
        posicao_3[4] = 'D';
        posicao_4[0] = 'V';
        posicao_4[1] = 'F';
        posicao_4[2] = 'E';
        posicao_4[3] = 'Z';
        posicao_4[4] = 'U';
        posicao_5[0] = 'U'; 
        posicao_5[1] = 'M'; 
        posicao_5[2] = 'I'; 
        posicao_5[3] = 'O';
        posicao_5[4] = 'L';  
        break;
      case 11:
        resposta_1 = 2;
        resposta_2 = 3;
        resposta_3 = 0;
        resposta_4 = 4;
        resposta_5 = 4;
        posicao_1[0] = 'P';
        posicao_1[1] = 'Q';
        posicao_1[2] = 'A';
        posicao_1[3] = 'Z'; 
        posicao_1[4] = 'X';
        posicao_2[0] = 'A';
        posicao_2[1] = 'F';
        posicao_2[2] = 'R';
        posicao_2[3] = 'M';
        posicao_2[4] = 'K';
        posicao_3[0] = 'I';
        posicao_3[1] = 'L';
        posicao_3[2] = 'W';
        posicao_3[3] = 'V';
        posicao_3[4] = 'C';
        posicao_4[0] = 'Z';
        posicao_4[1] = 'Y';
        posicao_4[2] = 'T';
        posicao_4[3] = 'P';
        posicao_4[4] = 'G';
        posicao_5[0] = 'Q'; 
        posicao_5[1] = 'S'; 
        posicao_5[2] = 'T'; 
        posicao_5[3] = 'X';
        posicao_5[4] = 'O';  
        break;
      case 12:
        resposta_1 = 4;
        resposta_2 = 3;
        resposta_3 = 2;
        resposta_4 = 1;
        resposta_5 = 0;
        posicao_1[0] = 'T';
        posicao_1[1] = 'R';
        posicao_1[2] = 'A';
        posicao_1[3] = 'B'; 
        posicao_1[4] = 'D';
        posicao_2[0] = 'C';
        posicao_2[1] = 'F';
        posicao_2[2] = 'D';
        posicao_2[3] = 'O';
        posicao_2[4] = 'I';
        posicao_3[0] = 'C';
        posicao_3[1] = 'A';
        posicao_3[2] = 'G';
        posicao_3[3] = 'H';
        posicao_3[4] = 'Q';
        posicao_4[0] = 'Y';
        posicao_4[1] = 'M';
        posicao_4[2] = 'R';
        posicao_4[3] = 'D';
        posicao_4[4] = 'P';
        posicao_5[0] = 'A'; 
        posicao_5[1] = 'D'; 
        posicao_5[2] = 'R'; 
        posicao_5[3] = 'U';
        posicao_5[4] = 'O';  
        break;
      case 13:
        resposta_1 = 3;
        resposta_2 = 1;
        resposta_3 = 4;
        resposta_4 = 0;
        resposta_5 = 2;
        posicao_1[0] = 'I';
        posicao_1[1] = 'U';
        posicao_1[2] = 'J';
        posicao_1[3] = 'B'; 
        posicao_1[4] = 'A';
        posicao_2[0] = 'Q';
        posicao_2[1] = 'R';
        posicao_2[2] = 'W';
        posicao_2[3] = 'H';
        posicao_2[4] = 'J';
        posicao_3[0] = 'Q';
        posicao_3[1] = 'E';
        posicao_3[2] = 'V';
        posicao_3[3] = 'G';
        posicao_3[4] = 'A';
        posicao_4[0] = 'V';
        posicao_4[1] = 'T';
        posicao_4[2] = 'D';
        posicao_4[3] = 'S';
        posicao_4[4] = 'Z';
        posicao_5[0] = 'L'; 
        posicao_5[1] = 'R'; 
        posicao_5[2] = 'O'; 
        posicao_5[3] = 'S';
        posicao_5[4] = 'Q';  
        break;
      case 14:
        resposta_1 = 1;
        resposta_2 = 4;
        resposta_3 = 2;
        resposta_4 = 0;
        resposta_5 = 3;
        posicao_1[0] = 'T';
        posicao_1[1] = 'H';
        posicao_1[2] = 'E';
        posicao_1[3] = 'S'; 
        posicao_1[4] = 'I';
        posicao_2[0] = 'M';
        posicao_2[1] = 'P';
        posicao_2[2] = 'S';
        posicao_2[3] = 'N';
        posicao_2[4] = 'O';
        posicao_3[0] = 'Z';
        posicao_3[1] = 'K';
        posicao_3[2] = 'M';
        posicao_3[3] = 'A';
        posicao_3[4] = 'L';
        posicao_4[0] = 'E';
        posicao_4[1] = 'F';
        posicao_4[2] = 'G';
        posicao_4[3] = 'H';
        posicao_4[4] = 'I';
        posicao_5[0] = 'J'; 
        posicao_5[1] = 'K'; 
        posicao_5[2] = 'L'; 
        posicao_5[3] = 'M';
        posicao_5[4] = 'N';  
        break;
      case 15:
        resposta_1 = 4;
        resposta_2 = 1;
        resposta_3 = 4;
        resposta_4 = 0;
        resposta_5 = 4;
        posicao_1[0] = 'G';
        posicao_1[1] = 'H';
        posicao_1[2] = 'S';
        posicao_1[3] = 'A'; 
        posicao_1[4] = 'O';
        posicao_2[0] = 'X';
        posicao_2[1] = 'L';
        posicao_2[2] = 'P';
        posicao_2[3] = 'Q';
        posicao_2[4] = 'Z';
        posicao_3[0] = 'R';
        posicao_3[1] = 'F';
        posicao_3[2] = 'I';
        posicao_3[3] = 'D';
        posicao_3[4] = 'H';
        posicao_4[0] = 'A';
        posicao_4[1] = 'B';
        posicao_4[2] = 'C';
        posicao_4[3] = 'D';
        posicao_4[4] = 'E';
        posicao_5[0] = 'Y'; 
        posicao_5[1] = 'W'; 
        posicao_5[2] = 'X'; 
        posicao_5[3] = 'C';
        posicao_5[4] = 'R';  
        break;
      case 16:
        resposta_1 = 0;
        resposta_2 = 1;
        resposta_3 = 4;
        resposta_4 = 4;
        resposta_5 = 3;
        posicao_1[0] = 'F';
        posicao_1[1] = 'O';
        posicao_1[2] = 'Q';
        posicao_1[3] = 'L'; 
        posicao_1[4] = 'H';
        posicao_2[0] = 'N';
        posicao_2[1] = 'U';
        posicao_2[2] = 'Z';
        posicao_2[3] = 'P';
        posicao_2[4] = 'O';
        posicao_3[0] = 'I';
        posicao_3[1] = 'X';
        posicao_3[2] = 'A';
        posicao_3[3] = 'F';
        posicao_3[4] = 'R';
        posicao_4[0] = 'K';
        posicao_4[1] = 'A';
        posicao_4[2] = 'S';
        posicao_4[3] = 'Z';
        posicao_4[4] = 'O';
        posicao_5[0] = 'T'; 
        posicao_5[1] = 'Y'; 
        posicao_5[2] = 'U'; 
        posicao_5[3] = 'R';
        posicao_5[4] = 'O';  
        break;
      case 17:
        resposta_1 = 3;
        resposta_2 = 3;
        resposta_3 = 1;
        resposta_4 = 4;
        resposta_5 = 2;
        posicao_1[0] = 'R';
        posicao_1[1] = 'S';
        posicao_1[2] = 'A';
        posicao_1[3] = 'J'; 
        posicao_1[4] = 'P';
        posicao_2[0] = 'U';
        posicao_2[1] = 'N';
        posicao_2[2] = 'V';
        posicao_2[3] = 'O';
        posicao_2[4] = 'Y';
        posicao_3[0] = 'U';
        posicao_3[1] = 'V';
        posicao_3[2] = 'X';
        posicao_3[3] = 'Y';
        posicao_3[4] = 'Z';
        posicao_4[0] = 'P';
        posicao_4[1] = 'A';
        posicao_4[2] = 'T';
        posicao_4[3] = 'R';
        posicao_4[4] = 'E';
        posicao_5[0] = 'R'; 
        posicao_5[1] = 'W'; 
        posicao_5[2] = 'M'; 
        posicao_5[3] = 'S';
        posicao_5[4] = 'D';  
        break; 
      case 18:
        resposta_1 = 0;
        resposta_2 = 2;
        resposta_3 = 3;
        resposta_4 = 1;
        resposta_5 = 4;
        posicao_1[0] = 'L';
        posicao_1[1] = 'P';
        posicao_1[2] = 'A';
        posicao_1[3] = 'R'; 
        posicao_1[4] = 'X';
        posicao_2[0] = 'Y';
        posicao_2[1] = 'O';
        posicao_2[2] = 'E';
        posicao_2[3] = 'L';
        posicao_2[4] = 'N';
        posicao_3[0] = 'T';
        posicao_3[1] = 'R';
        posicao_3[2] = 'U';
        posicao_3[3] = 'I';
        posicao_3[4] = 'V';
        posicao_4[0] = 'P';
        posicao_4[1] = 'T';
        posicao_4[2] = 'U';
        posicao_4[3] = 'O';
        posicao_4[4] = 'N';
        posicao_5[0] = 'B'; 
        posicao_5[1] = 'L'; 
        posicao_5[2] = 'M'; 
        posicao_5[3] = 'Z';
        posicao_5[4] = 'E';  
        break;            
      case 19:
        resposta_1 = 0;
        resposta_2 = 0;
        resposta_3 = 4;
        resposta_4 = 2;
        resposta_5 = 2;
        posicao_1[0] = 'P';
        posicao_1[1] = 'C';
        posicao_1[2] = 'L';
        posicao_1[3] = 'Z'; 
        posicao_1[4] = 'N';
        posicao_2[0] = 'R';
        posicao_2[1] = 'O';
        posicao_2[2] = 'T';
        posicao_2[3] = 'S';
        posicao_2[4] = 'D';
        posicao_3[0] = 'L';
        posicao_3[1] = 'O';
        posicao_3[2] = 'P';
        posicao_3[3] = 'Q';
        posicao_3[4] = 'E';
        posicao_4[0] = 'U';
        posicao_4[1] = 'I';
        posicao_4[2] = 'S';
        posicao_4[3] = 'B';
        posicao_4[4] = 'H';
        posicao_5[0] = 'R'; 
        posicao_5[1] = 'W'; 
        posicao_5[2] = 'O'; 
        posicao_5[3] = 'X';
        posicao_5[4] = 'N';  
        break;                                                                               
      }
    }
  if(estagio_jogo == -1){
    fim = 0;
    lcd.clear();
    lcd.setCursor(5,0);
    lcd.print("ESPERE");
    lcd.setCursor(4, 1);
    lcd.print("UM POUCO");
    analogWrite(A0, 0);
    analogWrite(A1, 0);
    if(comando == 'B'){
      estagio_jogo = 0;
      }
    delay(10);
  }
  if(estagio_jogo == 0){
    lcd.clear();
    controle_enviar = digitalRead(13);
    if(controle_enviar == HIGH){
      if((variavel_1 == resposta_1)&&(variavel_2 == resposta_2)&&(variavel_3 == resposta_3)&&(variavel_4 == resposta_4)&&(variavel_5 == resposta_5)){
        estagio_jogo = 1;
        }
      else{
        erro_local++;
        }  
    delay(200);
      }
    lcd.setCursor(0, 0);
    lcd.print("DESCUBRA A SENHA");  
    controle_1 = digitalRead(6);
      if(controle_1 == HIGH){
      variavel_1++;
      if(variavel_1 == 5){
        variavel_1 = 0;
        }
      delay(200);
      }
    lcd.setCursor(1,1);
    lcd.print(posicao_1[variavel_1]);  
    controle_2 = digitalRead(7);
    if(controle_2 == HIGH){
      variavel_2++;
      if(variavel_2 == 5){
        variavel_2 = 0;
        }
      delay(200);
        }
    lcd.setCursor(4,1);
    lcd.print(posicao_2[variavel_2]);    
    controle_3 = digitalRead(8);
    if(controle_3 == HIGH){
      variavel_3++;
      if(variavel_3 == 5){
        variavel_3 = 0;
        }
      delay(200);
      }
    lcd.setCursor(7,1);
    lcd.print(posicao_3[variavel_3]);    
    controle_4 = digitalRead(9);
    if(controle_4 == HIGH){
      variavel_4++;
      if(variavel_4 == 5){
        variavel_4 = 0;
        }
      delay(200);
      }
    lcd.setCursor(10,1);
    lcd.print(posicao_4[variavel_4]);
    controle_5 = digitalRead(10);
    if(controle_5 == HIGH){
      variavel_5++;
      if(variavel_5 == 5){
        variavel_5 = 0;
        }
      delay(200);
      }
    lcd.setCursor(13,1);
    lcd.print(posicao_5[variavel_5]);  
    if(estagio_jogo == 1){
      fim = 1;
      lcd.clear();
      lcd.setCursor(5,0);
      lcd.print("MODULO");
      lcd.setCursor(3,1);
      lcd.print("DESATIVADO");
      analogWrite(A0, 1023);
      analogWrite(A1, 0);
      delay(10);
      }
    else{
      analogWrite(A0, 0);
      analogWrite(A1, 1023); 
      }   
    if(erro_geral >= 3){
      lcd.clear();
      lcd.setCursor(6,0);
      lcd.print("GAME");
      lcd.setCursor(6,1);
      lcd.print("OVER");
      delay(1000);
      estagio_jogo = 2;
      }       
    delay(100);
              
}
}
  







