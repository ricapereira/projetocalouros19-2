#include <Wire.h>

byte hotwire = 0;
int wire[] = {2, 3, 4, 5, 6};
byte t;
//variáveis LEDs
byte led1 = 10;
byte led2 = 11;
byte led3 = 12;
byte led4 = 13;
byte ledconfR = 7;
byte ledconfG = 8;
byte buzzer = 9;
byte R;
//variáveis Buzzers
const int potenciometro = 2;
int valor = 0;
int letra = 600; 
int espaco = 1000;
int frequencia = 3000;
byte timer1 = 50;
int timer2 = 1000;
byte frequencia2 = 72;
// intervalos para se achar a comuninação com o potenciômetro;
int i1 = 880;
int i2 = 850;
int j1 = 666;
int j2 = 636;
int k1 = 450;
int k2 = 420;
int l1 = 240;
int l2 = 210;
byte m1 = 90;
byte m2 = 60;
//variáveis central
byte fase = 0;
int erro_vetor[5] = {0,0,0,0,0};
byte erro = 0;
byte i;
char comando = 'A';

void receiveEvent(int bytes){
  char y = Wire.read();
  comando = y;
  delay(100); 
  }

void requestEvent(){
  Wire.write(erro);
  Wire.write(fase);
}  

void setup() {
  Wire.begin(4);
  Wire.onReceive(receiveEvent);
  Wire.onRequest(requestEvent);
  
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(ledconfG, OUTPUT);
  pinMode(ledconfR, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(hotwire, INPUT);
  
  randomSeed(analogRead(A0));
 
    hotwire = random(2, 7);
    
    R = random(0, 3);

  }

void loop() {
 
if((fase == 0) && (comando == 'B')){

  if(wire[0] == hotwire){t = 0;}
  if(wire[1] == hotwire){t = 1;}
  if(wire[2] == hotwire){t = 2;}
  if(wire[3] == hotwire){t = 3;}
  if(wire[4] == hotwire){t = 4;}

  delay(100);
  digitalWrite(ledconfR, HIGH);
  
  valor = analogRead(potenciometro);

// sinais de luz:

//Red
  if(hotwire == 6){
    if(R == 0){
      digitalWrite(led3, HIGH);}
    if(R == 1){
      digitalWrite(led1, HIGH); 
      digitalWrite(led3, HIGH);
      digitalWrite(led4, HIGH);}
    if(R == 2){
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, HIGH);}
  }

//Yellow
  if(hotwire == 5){
    if(R == 0){
      digitalWrite(led2, HIGH);}
    if(R == 1){
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);}
    if(R == 2){
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led4, HIGH);}
  }

//Green
  if(hotwire == 4){
    if(R == 0){
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);}
    if(R == 2){
      digitalWrite(led2, HIGH);
      digitalWrite(led4, HIGH);}
    if(R == 1){
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);}
  }

//Blue
  if(hotwire == 3){
    if(R == 0){
      digitalWrite(led1, HIGH);}
    if(R == 1){
      digitalWrite(led4, HIGH);}
    if(R == 2){
      digitalWrite(led1, HIGH);
      digitalWrite(led3, HIGH);}
   }

//Purple
  if(hotwire == 2){
    if(R == 0){
      digitalWrite(led3, HIGH);
      digitalWrite(led4, HIGH);}
    if(R == 1){
      digitalWrite(led1, HIGH);
      digitalWrite(led4, HIGH);}
    if(R == 2){
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, HIGH);}
   }

//Sinais de "som";

  if(R == 0){
//faixa 1  
    while(i1 > valor && i2 < valor){
      valor = analogRead(potenciometro);     
      noTone(buzzer);
            
      if(i1 > valor && i2 < valor){
        tone(buzzer, frequencia, 150);
        valor = analogRead(potenciometro);
        if(not(digitalRead(2) == HIGH && digitalRead(3) == HIGH && digitalRead(4) == HIGH && digitalRead(5) == HIGH && digitalRead(6) == HIGH)){
          if(digitalRead(wire[t]) == LOW){
            digitalWrite(ledconfG, HIGH);
            delay(timer1);
            digitalWrite(ledconfR, LOW);
            delay(timer2);
            fase = 1;}
        else if(digitalRead(wire[t]) == HIGH){
          for(i = 0; i <= 4; i++){
            if(digitalRead(wire[i]) == LOW){
              erro_vetor[i]=1;
              digitalWrite(ledconfR, HIGH);}
            erro = erro_vetor[0] + erro_vetor[1] + erro_vetor[2] + erro_vetor[3] + erro_vetor[4];}}}        }
      else{break;}
      if(i1 > valor && i2 < valor){  
        delay(letra);
        valor = analogRead(potenciometro);}
      else{break;}  
      if(i1 > valor && i2 < valor){  
        tone(buzzer, frequencia, 400);
        valor = analogRead(potenciometro);}
      else{break;}
      if(i1 > valor && i2 < valor){   
        delay(espaco);
        valor = analogRead(potenciometro);}
      else{break;}  
      if(i1 > valor && i2 < valor){
        tone(buzzer, frequencia, 400);
        valor = analogRead(potenciometro);}
      else{break;}  
      if(i1 > valor && i2 < valor){
        delay(letra);
        valor = analogRead(potenciometro);}
      else{break;}
      if(i1 > valor && i2 < valor){
        tone(buzzer, frequencia, 400);
        valor = analogRead(potenciometro);}
      else{break;}  
      if(i1 > valor && i2 < valor){
        delay(letra);
        valor = analogRead(potenciometro);}
      else{break;}
      if(i1 > valor && i2 < valor){
        tone(buzzer, frequencia, 150);
        valor = analogRead(potenciometro);
        if(not(digitalRead(2) == HIGH && digitalRead(3) == HIGH && digitalRead(4) == HIGH && digitalRead(5) == HIGH && digitalRead(6) == HIGH)){
          if(digitalRead(wire[t]) == LOW){
            digitalWrite(ledconfG, HIGH);
            delay(timer1);
            digitalWrite(ledconfR, LOW);
            delay(timer2);
            fase = 1;}
        else if(digitalRead(wire[t]) == HIGH){
          for(i = 0; i <= 4; i++){
            if(digitalRead(wire[i]) == LOW){
              erro_vetor[i]=1;
              digitalWrite(ledconfR, HIGH);}
            erro = erro_vetor[0] + erro_vetor[1] + erro_vetor[2] + erro_vetor[3] + erro_vetor[4];}}}        }
      else{break;}
      if(i1 > valor && i2 < valor){
        delay(letra);
        valor = analogRead(potenciometro);}
      else{break;}
      if(i1 > valor && i2 < valor){
        tone(buzzer, frequencia, 150);
        valor = analogRead(potenciometro);}
      else{break;}  
      if(i1 > valor && i2 < valor){
        delay(espaco);
        valor = analogRead(potenciometro);}
      else{break;}
      if(i1 > valor && i2 < valor){    
        tone(buzzer, frequencia, 150);
        valor = analogRead(potenciometro);}
      else{break;}
      if(i1 > valor && i2 < valor){  
        delay(letra);
        valor = analogRead(potenciometro);}
      else{break;}
      if(i1 > valor && i2 < valor){  
        tone(buzzer, frequencia, 400);
        valor = analogRead(potenciometro);}
      else{break;}   
      if(i1 > valor && i2 < valor){  
        delay(espaco);
        valor = analogRead(potenciometro);}
      else{break;}
      if(i1 > valor && i2 < valor){
        tone(buzzer, frequencia, 150);
        valor = analogRead(potenciometro);
        if(not(digitalRead(2) == HIGH && digitalRead(3) == HIGH && digitalRead(4) == HIGH && digitalRead(5) == HIGH && digitalRead(6) == HIGH)){
          if(digitalRead(wire[t]) == LOW){
            digitalWrite(ledconfG, HIGH);
            delay(timer1);
            digitalWrite(ledconfR, LOW);
            delay(timer2);
            fase = 1;}
        else if(digitalRead(wire[t]) == HIGH){
          for(i = 0; i <= 4; i++){
            if(digitalRead(wire[i]) == LOW){
              erro_vetor[i]=1;
              digitalWrite(ledconfR, HIGH);}
            erro = erro_vetor[0] + erro_vetor[1] + erro_vetor[2] + erro_vetor[3] + erro_vetor[4];}}}        }
      else{break;}
      if(i1 > valor && i2 < valor){  
        delay(letra);
        valor = analogRead(potenciometro);}
      else{break;}
      if(i1 > valor && i2 < valor){  
        tone(buzzer, frequencia, 400);
        valor = analogRead(potenciometro);}
      else{break;}
      if(i1 > valor && i2 < valor){  
        delay(letra);
        valor = analogRead(potenciometro);}
      else{break;}
      if(i1 > valor && i2 < valor){  
        tone(buzzer, frequencia, 150);
        valor = analogRead(potenciometro);}
      else{break;}
      if(i1 > valor && i2 < valor){  
        delay(letra);
        valor = analogRead(potenciometro);}
      else{break;}
      if(i1 > valor && i2 < valor){
        tone(buzzer, frequencia2, 400);
        valor = analogRead(potenciometro);}
      else{break;}  
      if(i1 > valor && i2 < valor){  
        delay(espaco);
        valor = analogRead(potenciometro);}
      else{break;}
    }
//faixa 2   
    while(j1 > valor && j2 < valor){
      valor = analogRead(potenciometro);     
      noTone(buzzer);
            
      if(j1 > valor && j2 < valor){
        tone(buzzer, frequencia, 100);
        valor = analogRead(potenciometro);
        if(not(digitalRead(2) == HIGH && digitalRead(3) == HIGH && digitalRead(4) == HIGH && digitalRead(5) == HIGH && digitalRead(6) == HIGH)){
          if(digitalRead(wire[t]) == LOW){
            digitalWrite(ledconfG, HIGH);
            delay(timer1);
            digitalWrite(ledconfR, LOW);
            delay(timer2);
            fase = 1;}
        else if(digitalRead(wire[t]) == HIGH){
          for(i = 0; i <= 4; i++){
            if(digitalRead(wire[i]) == LOW){
              erro_vetor[i]=1;
              digitalWrite(ledconfR, HIGH);}
            erro = erro_vetor[0] + erro_vetor[1] + erro_vetor[2] + erro_vetor[3] + erro_vetor[4];}}}        }
      else{break;}
      if(j1 > valor && j2 < valor){  
        delay(letra);
        valor = analogRead(potenciometro);}
      else{break;}  
      if(j1 > valor && j2 < valor){  
        tone(buzzer, frequencia, 400);
        valor = analogRead(potenciometro);}
      else{break;}
      if(j1 > valor && j2 < valor){   
        delay(espaco);
        valor = analogRead(potenciometro);}
      else{break;}
      if(j1 > valor && j2 < valor){
        tone(buzzer, frequencia, 400);
        valor = analogRead(potenciometro);}
      else{break;}  
      if(j1 > valor && j2 < valor){
        delay(letra);
        valor = analogRead(potenciometro);}
      else{break;}
      if(j1 > valor && j2 < valor){
        tone(buzzer, frequencia, 400);
        valor = analogRead(potenciometro);}
      else{break;}  
      if(j1 > valor && j2 < valor){
        delay(letra);
        valor = analogRead(potenciometro);}
      else{break;}
      if(j1 > valor && j2 < valor){
        tone(buzzer, frequencia, 100);
        valor = analogRead(potenciometro);}
      else{break;}
      if(j1 > valor && j2 < valor){
        delay(letra);
        valor = analogRead(potenciometro);
        if(not(digitalRead(2) == HIGH && digitalRead(3) == HIGH && digitalRead(4) == HIGH && digitalRead(5) == HIGH && digitalRead(6) == HIGH)){
          if(digitalRead(wire[t]) == LOW){
            digitalWrite(ledconfG, HIGH);
            delay(timer1);
            digitalWrite(ledconfR, LOW);
            delay(timer2);
            fase = 1;}
        else if(digitalRead(wire[t]) == HIGH){
          for(i = 0; i <= 4; i++){
            if(digitalRead(wire[i]) == LOW){
              erro_vetor[i]=1;
              digitalWrite(ledconfR, HIGH);}
            erro = erro_vetor[0] + erro_vetor[1] + erro_vetor[2] + erro_vetor[3] + erro_vetor[4];}}}        }
      else{break;}
      if(j1 > valor && j2 < valor){
        tone(buzzer, frequencia, 100);
        valor = analogRead(potenciometro);}
      else{break;}
      if(j1 > valor && j2 < valor){
        delay(espaco);
        valor = analogRead(potenciometro);}
      else{break;}
      if(j1 > valor && j2 < valor){    
        tone(buzzer, frequencia, 100);
        valor = analogRead(potenciometro);}
      else{break;}
      if(j1 > valor && j2 < valor){  
        delay(letra);
        valor = analogRead(potenciometro);}
      else{break;}
      if(j1 > valor && j2 < valor){  
        tone(buzzer, frequencia, 100);
        valor = analogRead(potenciometro);}
      else{break;}   
      if(j1 > valor && j2 < valor){  
        delay(letra);
        valor = analogRead(potenciometro);}
      else{break;}
      if(j1 > valor && j2 < valor){  
        tone(buzzer, frequencia, 400);
        valor = analogRead(potenciometro);}
      else{break;}
      if(j1 > valor && j2 < valor){  
        delay(espaco);
        valor = analogRead(potenciometro);}
      else{break;}
      if(j1 > valor && j2 < valor){
        tone(buzzer, frequencia, 100);
        valor = analogRead(potenciometro);}
      else{break;}
      if(j1 > valor && j2 < valor){  
        delay(letra);
        valor = analogRead(potenciometro);
        if(not(digitalRead(2) == HIGH && digitalRead(3) == HIGH && digitalRead(4) == HIGH && digitalRead(5) == HIGH && digitalRead(6) == HIGH)){
          if(digitalRead(wire[t]) == LOW){
            digitalWrite(ledconfG, HIGH);
            delay(timer1);
            digitalWrite(ledconfR, LOW);
            delay(timer2);
            fase = 1;}
        else if(digitalRead(wire[t]) == HIGH){
          for(i = 0; i <= 4; i++){
            if(digitalRead(wire[i]) == LOW){
              erro_vetor[i]=1;
              digitalWrite(ledconfR, HIGH);}
            erro = erro_vetor[0] + erro_vetor[1] + erro_vetor[2] + erro_vetor[3] + erro_vetor[4];}}}        }
      else{break;}
      if(j1 > valor && j2 < valor){  
        tone(buzzer, frequencia, 400);
        valor = analogRead(potenciometro);}
      else{break;}
      if(j1 > valor && j2 < valor){  
        delay(letra);
        valor = analogRead(potenciometro);}
      else{break;}
      if(j1 > valor && j2 < valor){  
        tone(buzzer, frequencia, 100);
        valor = analogRead(potenciometro);}
      else{break;}
      if(j1 > valor && j2 < valor){  
        delay(letra);
        valor = analogRead(potenciometro);}
      else{break;}
      if(j1 > valor && j2 < valor){  
        tone(buzzer, frequencia, 100);
        valor = analogRead(potenciometro);}
      else{break;}
      if(j1 > valor && j2 < valor){  
        delay(letra);
        valor = analogRead(potenciometro);}
      else{break;}
      if(j1 > valor && j2 < valor){
        tone(buzzer, frequencia2, 200);
        valor = analogRead(potenciometro);}
      else{break;}  
      if(j1 > valor && j2 < valor){  
        delay(espaco);
        valor = analogRead(potenciometro);}
      else{break;}
    } 
//faixa 3
    while(k1 > valor && k2 < valor){
      valor = analogRead(potenciometro);     
      noTone(buzzer);
            
      if(k1 > valor && k2 < valor){
        tone(buzzer, frequencia, 100);
        valor = analogRead(potenciometro);
        if(not(digitalRead(2) == HIGH && digitalRead(3) == HIGH && digitalRead(4) == HIGH && digitalRead(5) == HIGH && digitalRead(6) == HIGH)){
          if(digitalRead(wire[t]) == LOW){
            digitalWrite(ledconfG, HIGH);
            delay(timer1);
            digitalWrite(ledconfR, LOW);
            delay(timer2);
            fase = 1;}
        else if(digitalRead(wire[t]) == HIGH){
          for(i = 0; i <= 4; i++){
            if(digitalRead(wire[i]) == LOW){
              erro_vetor[i]=1;
              digitalWrite(ledconfR, HIGH);}
            erro = erro_vetor[0] + erro_vetor[1] + erro_vetor[2] + erro_vetor[3] + erro_vetor[4];}}}        }
      else{break;}
      if(k1 > valor && k2 < valor){  
        delay(letra);
        valor = analogRead(potenciometro);}
      else{break;}  
      if(k1 > valor && k2 < valor){  
        tone(buzzer, frequencia, 400);
        valor = analogRead(potenciometro);}
      else{break;}
      if(k1 > valor && k2 < valor){   
        delay(espaco);
        valor = analogRead(potenciometro);}
      else{break;}
      if(k1 > valor && k2 < valor){
        tone(buzzer, frequencia, 400);
        valor = analogRead(potenciometro);}
      else{break;}  
      if(k1 > valor && k2 < valor){
        delay(letra);
        valor = analogRead(potenciometro);}
      else{break;}
      if(k1 > valor && k2 < valor){
        tone(buzzer, frequencia, 100);
        valor = analogRead(potenciometro);}
      else{break;}  
      if(k1 > valor && k2 < valor){
        delay(espaco);
        valor = analogRead(potenciometro);
        if(not(digitalRead(2) == HIGH && digitalRead(3) == HIGH && digitalRead(4) == HIGH && digitalRead(5) == HIGH && digitalRead(6) == HIGH)){
          if(digitalRead(wire[t]) == LOW){
            digitalWrite(ledconfG, HIGH);
            delay(timer1);
            digitalWrite(ledconfR, LOW);
            delay(timer2);
            fase = 1;}
        else if(digitalRead(wire[t]) == HIGH){
          for(i = 0; i <= 4; i++){
            if(digitalRead(wire[i]) == LOW){
              erro_vetor[i]=1;
              digitalWrite(ledconfR, HIGH);}
            erro = erro_vetor[0] + erro_vetor[1] + erro_vetor[2] + erro_vetor[3] + erro_vetor[4];}}}        }
      else{break;}
      if(k1 > valor && k2 < valor){
        tone(buzzer, frequencia, 100);
        valor = analogRead(potenciometro);}
      else{break;}
      if(k1 > valor && k2 < valor){
        delay(espaco);
        valor = analogRead(potenciometro);}
      else{break;}
      if(k1 > valor && k2 < valor){
        tone(buzzer, frequencia, 100);
        valor = analogRead(potenciometro);}
      else{break;}
      if(k1 > valor && k2 < valor){
        delay(letra);
        valor = analogRead(potenciometro);}
      else{break;}
      if(k1 > valor && k2 < valor){    
        tone(buzzer, frequencia, 400);
        valor = analogRead(potenciometro);}
      else{break;}
      if(k1 > valor && k2 < valor){  
        delay(letra);
        valor = analogRead(potenciometro);}
      else{break;}
      if(k1 > valor && k2 < valor){  
        tone(buzzer, frequencia, 100);
        valor = analogRead(potenciometro);
        if(not(digitalRead(2) == HIGH && digitalRead(3) == HIGH && digitalRead(4) == HIGH && digitalRead(5) == HIGH && digitalRead(6) == HIGH)){
          if(digitalRead(wire[t]) == LOW){
            digitalWrite(ledconfG, HIGH);
            delay(timer1);
            digitalWrite(ledconfR, LOW);
            delay(timer2);
            fase = 1;}
        else if(digitalRead(wire[t]) == HIGH){
          for(i = 0; i <= 4; i++){
            if(digitalRead(wire[i]) == LOW){
              erro_vetor[i]=1;
              digitalWrite(ledconfR, HIGH);}
            erro = erro_vetor[0] + erro_vetor[1] + erro_vetor[2] + erro_vetor[3] + erro_vetor[4];}}}        }
      else{break;}   
      if(k1 > valor && k2 < valor){  
        delay(letra);
        valor = analogRead(potenciometro);}
      else{break;}
      if(k1 > valor && k2 < valor){  
        tone(buzzer, frequencia, 100);
        valor = analogRead(potenciometro);}
      else{break;}
      if(k1 > valor && k2 < valor){  
        delay(letra);
        valor = analogRead(potenciometro);}
      else{break;}      
      if(k1 > valor && k2 < valor){
        tone(buzzer, frequencia2, 400);
        valor = analogRead(potenciometro);}
      else{break;}  
      if(k1 > valor && k2 < valor){  
        delay(espaco);
        valor = analogRead(potenciometro);}
      else{break;}
    }
//faixa 4
    while(l1 > valor && l2 < valor){
      valor = analogRead(potenciometro);     
      noTone(buzzer);
            
      if(l1 > valor && l2 < valor){
        tone(buzzer, frequencia, 100);
        valor = analogRead(potenciometro);}
      else{break;}
      if(l1 > valor && l2 < valor){  
        delay(letra);
        valor = analogRead(potenciometro);}
      else{break;}
      if(l1 > valor && l2 < valor){  
        tone(buzzer, frequencia, 100);
        valor = analogRead(potenciometro);}
      else{break;}
      if(l1 > valor && l2 < valor){  
        delay(letra);
        valor = analogRead(potenciometro);}
      if(l1 > valor && l2 < valor){
        tone(buzzer, frequencia, 400);
        valor = analogRead(potenciometro);}
      else{break;}
      if(l1 > valor && l2 < valor){  
        delay(letra);}
      if(l1 > valor && l2 < valor){
        tone(buzzer, frequencia, 100);
        valor = analogRead(potenciometro);}
      else{break;}
      if(l1 > valor && l2 < valor){   
        delay(espaco);
        valor = analogRead(potenciometro);}
      else{break;}
      if(l1 > valor && l2 < valor){
        tone(buzzer, frequencia, 400);
        valor = analogRead(potenciometro);}
      else{break;}  
      if(l1 > valor && l2 < valor){
        delay(letra);
        valor = analogRead(potenciometro);
        if(not(digitalRead(2) == HIGH && digitalRead(3) == HIGH && digitalRead(4) == HIGH && digitalRead(5) == HIGH && digitalRead(6) == HIGH)){
          if(digitalRead(wire[t]) == LOW){
            digitalWrite(ledconfG, HIGH);
            delay(timer1);
            digitalWrite(ledconfR, LOW);
            delay(timer2);
            fase = 1;}
        else if(digitalRead(wire[t]) == HIGH){
          for(i = 0; i <= 4; i++){
            if(digitalRead(wire[i]) == LOW){
              erro_vetor[i]=1;
              digitalWrite(ledconfR, HIGH);}
            erro = erro_vetor[0] + erro_vetor[1] + erro_vetor[2] + erro_vetor[3] + erro_vetor[4];}}}        }
      else{break;}
      if(l1 > valor && l2 < valor){
        tone(buzzer, frequencia, 400);
        valor = analogRead(potenciometro);}
      else{break;}
      if(l1 > valor && l2 < valor){
        delay(letra);
        valor = analogRead(potenciometro);}
      else{break;}
      if(l1 > valor && l2 < valor){
        tone(buzzer, frequencia, 400);
        valor = analogRead(potenciometro);}
      else{break;}  
      if(l1 > valor && l2 < valor){
        delay(espaco);
        valor = analogRead(potenciometro);}
      else{break;}
      if(l1 > valor && l2 < valor){
        tone(buzzer, frequencia, 400);
        valor = analogRead(potenciometro);}
      else{break;}
      if(l1 > valor && l2 < valor){
        delay(letra);
        valor = analogRead(potenciometro);}
      else{break;}
      if(l1 > valor && l2 < valor){
        tone(buzzer, frequencia, 100);
        valor = analogRead(potenciometro);}
      else{break;}
      if(l1 > valor && l2 < valor){
        delay(letra);
        valor = analogRead(potenciometro);}
      else{break;}
      if(l1 > valor && l2 < valor){    
        tone(buzzer, frequencia, 400);
        valor = analogRead(potenciometro);}
      else{break;}
      if(l1 > valor && l2 < valor){  
        delay(letra);
        valor = analogRead(potenciometro);
        if(not(digitalRead(2) == HIGH && digitalRead(3) == HIGH && digitalRead(4) == HIGH && digitalRead(5) == HIGH && digitalRead(6) == HIGH)){
          if(digitalRead(wire[t]) == LOW){
            digitalWrite(ledconfG, HIGH);
            delay(timer1);
            digitalWrite(ledconfR, LOW);
            delay(timer2);
            fase = 1;}
        else if(digitalRead(wire[t]) == HIGH){
          for(i = 0; i <= 4; i++){
            if(digitalRead(wire[i]) == LOW){
              erro_vetor[i]=1;
              digitalWrite(ledconfR, HIGH);}
            erro = erro_vetor[0] + erro_vetor[1] + erro_vetor[2] + erro_vetor[3] + erro_vetor[4];}}}        }
      else{break;}
      if(l1 > valor && l2 < valor){  
        tone(buzzer, frequencia, 100);
        valor = analogRead(potenciometro);}
      else{break;}   
      if(l1 > valor && l2 < valor){  
        delay(espaco);
        valor = analogRead(potenciometro);}
      else{break;}
      if(l1 > valor && l2 < valor){  
        tone(buzzer, frequencia, 400);
        valor = analogRead(potenciometro);}
      else{break;}
      if(l1 > valor && l2 < valor){
        delay(letra);
        valor = analogRead(potenciometro);}
      if(l1 > valor && l2 < valor){  
        tone(buzzer, frequencia, 400);
        valor = analogRead(potenciometro);}
      else{break;}
      if(l1 > valor && l2 < valor){
        delay(letra);
        valor = analogRead(potenciometro);}
      if(l1 > valor && l2 < valor){  
        tone(buzzer, frequencia, 400);
        valor = analogRead(potenciometro);}
      else{break;}
      if(l1 > valor && l2 < valor){
        delay(letra);
        valor = analogRead(potenciometro);}
      else{break;}
      if(l1 > valor && l2 < valor){
        tone(buzzer, frequencia2, 400);
        valor = analogRead(potenciometro);}
      else{break;}  
      if(l1 > valor && l2 < valor){  
        delay(espaco);
        valor = analogRead(potenciometro);}
      else{break;}
    }
//faixa 5
    while(m1 > valor && m2 < valor){
      valor = analogRead(potenciometro);     
      noTone(buzzer);
            
      if(m1 > valor && m2 < valor){
        tone(buzzer, frequencia, 100);
        valor = analogRead(potenciometro);
        if(not(digitalRead(2) == HIGH && digitalRead(3) == HIGH && digitalRead(4) == HIGH && digitalRead(5) == HIGH && digitalRead(6) == HIGH)){
          if(digitalRead(wire[t]) == LOW){
            digitalWrite(ledconfG, HIGH);
            delay(timer1);
            digitalWrite(ledconfR, LOW);
            delay(timer2);
            fase = 1;}
        else if(digitalRead(wire[t]) == HIGH){
          for(i = 0; i <= 4; i++){
            if(digitalRead(wire[i]) == LOW){
              erro_vetor[i]=1;
              digitalWrite(ledconfR, HIGH);}
            erro = erro_vetor[0] + erro_vetor[1] + erro_vetor[2] + erro_vetor[3] + erro_vetor[4];}}}        }
      else{break;}
      if(m1 > valor && m2 < valor){  
        delay(letra);
        valor = analogRead(potenciometro);}
      else{break;}
      if(m1 > valor && m2 < valor){  
        tone(buzzer, frequencia, 100);
        valor = analogRead(potenciometro);}
      else{break;}
      if(m1 > valor && m2 < valor){  
        delay(letra);
        valor = analogRead(potenciometro);}
      if(m1 > valor && m2 < valor){
        tone(buzzer, frequencia, 400);
        valor = analogRead(potenciometro);}
      else{break;}
      if(m1 > valor && m2 < valor){  
        delay(letra);}
      if(m1 > valor && m2 < valor){
        tone(buzzer, frequencia, 100);
        valor = analogRead(potenciometro);
        if(not(digitalRead(2) == HIGH && digitalRead(3) == HIGH && digitalRead(4) == HIGH && digitalRead(5) == HIGH && digitalRead(6) == HIGH)){
          if(digitalRead(wire[t]) == LOW){
            digitalWrite(ledconfG, HIGH);
            delay(timer1);
            digitalWrite(ledconfR, LOW);
            delay(timer2);
            fase = 1;}
        else if(digitalRead(wire[t]) == HIGH){
          for(i = 0; i <= 4; i++){
            if(digitalRead(wire[i]) == LOW){
              erro_vetor[i]=1;
              digitalWrite(ledconfR, HIGH);}
            erro = erro_vetor[0] + erro_vetor[1] + erro_vetor[2] + erro_vetor[3] + erro_vetor[4];}}}        }
      else{break;}
      if(m1 > valor && m2 < valor){   
        delay(espaco);
        valor = analogRead(potenciometro);}
      else{break;}
      if(m1 > valor && m2 < valor){
        tone(buzzer, frequencia, 400);
        valor = analogRead(potenciometro);}
      else{break;}  
      if(m1 > valor && m2 < valor){
        delay(letra);
        valor = analogRead(potenciometro);}
      else{break;}
      if(m1 > valor && m2 < valor){
        tone(buzzer, frequencia, 400);
        valor = analogRead(potenciometro);}
      else{break;}
      if(m1 > valor && m2 < valor){
        delay(letra);
        valor = analogRead(potenciometro);}
      else{break;}
      if(m1 > valor && m2 < valor){
        tone(buzzer, frequencia, 400);
        valor = analogRead(potenciometro);}
      else{break;}  
      if(m1 > valor && m2 < valor){
        delay(espaco);
        valor = analogRead(potenciometro);
        if(not(digitalRead(2) == HIGH && digitalRead(3) == HIGH && digitalRead(4) == HIGH && digitalRead(5) == HIGH && digitalRead(6) == HIGH)){
          if(digitalRead(wire[t]) == LOW){
            digitalWrite(ledconfG, HIGH);
            delay(timer1);
            digitalWrite(ledconfR, LOW);
            delay(timer2);
            fase = 1;}
        else if(digitalRead(wire[t]) == HIGH){
          for(i = 0; i <= 4; i++){
            if(digitalRead(wire[i]) == LOW){
              erro_vetor[i]=1;
              digitalWrite(ledconfR, HIGH);}
            erro = erro_vetor[0] + erro_vetor[1] + erro_vetor[2] + erro_vetor[3] + erro_vetor[4];}}}        }
      else{break;}
      if(m1 > valor && m2 < valor){
        tone(buzzer, frequencia, 400);
        valor = analogRead(potenciometro);}
      else{break;}
      if(m1 > valor && m2 < valor){
        delay(letra);
        valor = analogRead(potenciometro);}
      else{break;}
      if(m1 > valor && m2 < valor){
        tone(buzzer, frequencia, 400);
        valor = analogRead(potenciometro);}
      else{break;}
      if(m1 > valor && m2 < valor){
        delay(espaco);
        valor = analogRead(potenciometro);}
      else{break;}
      if(m1 > valor && m2 < valor){    
        tone(buzzer, frequencia, 100);
        valor = analogRead(potenciometro);}
      else{break;}
      if(m1 > valor && m2 < valor){  
        delay(letra);
        valor = analogRead(potenciometro);}
      if(m1 > valor && m2 < valor){
        tone(buzzer, frequencia2, 400);
        valor = analogRead(potenciometro);}
      else{break;}  
      if(m1 > valor && m2 < valor){  
        delay(espaco);
        valor = analogRead(potenciometro);}
      else{break;}
    }
  }

  if(R == 1){
//faixa 1  
    while(i1 > valor && i2 < valor){
      valor = analogRead(potenciometro);     
      noTone(buzzer);
            
      if(i1 > valor && i2 < valor){
        tone(buzzer, frequencia, 100);
        valor = analogRead(potenciometro);
        if(not(digitalRead(2) == HIGH && digitalRead(3) == HIGH && digitalRead(4) == HIGH && digitalRead(5) == HIGH && digitalRead(6) == HIGH)){
          if(digitalRead(wire[t]) == LOW){
            digitalWrite(ledconfG, HIGH);
            delay(timer1);
            digitalWrite(ledconfR, LOW);
            delay(timer2);
            fase = 1;}
        else if(digitalRead(wire[t]) == HIGH){
          for(i = 0; i <= 4; i++){
            if(digitalRead(wire[i]) == LOW){
              erro_vetor[i]=1;
              digitalWrite(ledconfR, HIGH);}
            erro = erro_vetor[0] + erro_vetor[1] + erro_vetor[2] + erro_vetor[3] + erro_vetor[4];}}}        }
      else{break;}
      if(i1 > valor && i2 < valor){  
        delay(letra);
        valor = analogRead(potenciometro);}
      else{break;}
      if(i1 > valor && i2 < valor){  
        tone(buzzer, frequencia, 100);
        valor = analogRead(potenciometro);}
      else{break;}
      if(i1 > valor && i2 < valor){  
        delay(letra);
        valor = analogRead(potenciometro);}
      if(i1 > valor && i2 < valor){
        tone(buzzer, frequencia, 400);
        valor = analogRead(potenciometro);}
      else{break;}
      if(i1 > valor && i2 < valor){  
        delay(letra);}
      if(i1 > valor && i2 < valor){
        tone(buzzer, frequencia, 100);
        valor = analogRead(potenciometro);
        if(not(digitalRead(2) == HIGH && digitalRead(3) == HIGH && digitalRead(4) == HIGH && digitalRead(5) == HIGH && digitalRead(6) == HIGH)){
          if(digitalRead(wire[t]) == LOW){
            digitalWrite(ledconfG, HIGH);
            delay(timer1);
            digitalWrite(ledconfR, LOW);
            delay(timer2);
            fase = 1;}
        else if(digitalRead(wire[t]) == HIGH){
          for(i = 0; i <= 4; i++){
            if(digitalRead(wire[i]) == LOW){
              erro_vetor[i]=1;
              digitalWrite(ledconfR, HIGH);}
            erro = erro_vetor[0] + erro_vetor[1] + erro_vetor[2] + erro_vetor[3] + erro_vetor[4];}}}        }
      else{break;}
      if(i1 > valor && i2 < valor){   
        delay(espaco);
        valor = analogRead(potenciometro);}
      else{break;}
      if(i1 > valor && i2 < valor){
        tone(buzzer, frequencia, 100);
        valor = analogRead(potenciometro);}
      else{break;}  
      if(i1 > valor && i2 < valor){
        delay(letra);
        valor = analogRead(potenciometro);}
      else{break;}
      if(i1 > valor && i2 < valor){
        tone(buzzer, frequencia, 400);
        valor = analogRead(potenciometro);}
      else{break;}
      if(i1 > valor && i2 < valor){
        delay(espaco);
        valor = analogRead(potenciometro);}
      else{break;}
      if(i1 > valor && i2 < valor){
        tone(buzzer, frequencia, 400);
        valor = analogRead(potenciometro);}
      else{break;}  
      if(i1 > valor && i2 < valor){
        delay(letra);
        valor = analogRead(potenciometro);
        if(not(digitalRead(2) == HIGH && digitalRead(3) == HIGH && digitalRead(4) == HIGH && digitalRead(5) == HIGH && digitalRead(6) == HIGH)){
          if(digitalRead(wire[t]) == LOW){
            digitalWrite(ledconfG, HIGH);
            delay(timer1);
            digitalWrite(ledconfR, LOW);
            delay(timer2);
            fase = 1;}
        else if(digitalRead(wire[t]) == HIGH){
          for(i = 0; i <= 4; i++){
            if(digitalRead(wire[i]) == LOW){
              erro_vetor[i]=1;
              digitalWrite(ledconfR, HIGH);}
            erro = erro_vetor[0] + erro_vetor[1] + erro_vetor[2] + erro_vetor[3] + erro_vetor[4];}}}        }
      else{break;}
      if(i1 > valor && i2 < valor){
        tone(buzzer, frequencia, 400);
        valor = analogRead(potenciometro);}
      else{break;}
      if(i1 > valor && i2 < valor){
        delay(espaco);
        valor = analogRead(potenciometro);}
      else{break;}
      if(i1 > valor && i2 < valor){
        tone(buzzer, frequencia, 100);
        valor = analogRead(potenciometro);}
      else{break;}
      if(i1 > valor && i2 < valor){
        delay(letra);
        valor = analogRead(potenciometro);}
      else{break;}
      if(i1 > valor && i2 < valor){    
        tone(buzzer, frequencia, 400);
        valor = analogRead(potenciometro);}
      else{break;}
      if(i1 > valor && i2 < valor){  
        delay(letra);
        valor = analogRead(potenciometro);}
      if(i1 > valor && i2 < valor){
        tone(buzzer, frequencia2, 400);
        valor = analogRead(potenciometro);}
      else{break;}  
      if(i1 > valor && i2 < valor){  
        delay(espaco);
        valor = analogRead(potenciometro);}
      else{break;}
}
//faixa 2   
    while(j1 > valor && j2 < valor){
      valor = analogRead(potenciometro);     
      noTone(buzzer);
            
      if(j1 > valor && j2 < valor){
        tone(buzzer, frequencia, 100);
        valor = analogRead(potenciometro);}
      else{break;}
      if(j1 > valor && j2 < valor){  
        delay(letra);
        valor = analogRead(potenciometro);}
      else{break;}
      if(j1 > valor && j2 < valor){  
        tone(buzzer, frequencia, 400);
        valor = analogRead(potenciometro);}
      else{break;}
      if(j1 > valor && j2 < valor){  
        delay(letra);
        valor = analogRead(potenciometro);}
      else{break;}  
      if(j1 > valor && j2 < valor){
        tone(buzzer, frequencia, 100);
        valor = analogRead(potenciometro);}
      else{break;}
      if(j1 > valor && j2 < valor){  
        delay(letra);}
      else{break;}  
      if(j1 > valor && j2 < valor){
        tone(buzzer, frequencia, 100);
        valor = analogRead(potenciometro);}
      else{break;}
      if(j1 > valor && j2 < valor){   
        delay(espaco);
        valor = analogRead(potenciometro);
        if(not(digitalRead(2) == HIGH && digitalRead(3) == HIGH && digitalRead(4) == HIGH && digitalRead(5) == HIGH && digitalRead(6) == HIGH)){
          if(digitalRead(wire[t]) == LOW){
            digitalWrite(ledconfG, HIGH);
            delay(timer1);
            digitalWrite(ledconfR, LOW);
            delay(timer2);
            fase = 1;}
        else if(digitalRead(wire[t]) == HIGH){
          for(i = 0; i <= 4; i++){
            if(digitalRead(wire[i]) == LOW){
              erro_vetor[i]=1;
              digitalWrite(ledconfR, HIGH);}
            erro = erro_vetor[0] + erro_vetor[1] + erro_vetor[2] + erro_vetor[3] + erro_vetor[4];}}}        }
      else{break;}
      if(j1 > valor && j2 < valor){
        tone(buzzer, frequencia, 100);
        valor = analogRead(potenciometro);}
      else{break;}  
      if(j1 > valor && j2 < valor){
        delay(letra);
        valor = analogRead(potenciometro);}
      else{break;}
      if(j1 > valor && j2 < valor){
        tone(buzzer, frequencia, 100);
        valor = analogRead(potenciometro);}
      else{break;}
      if(j1 > valor && j2 < valor){
        delay(letra);
        valor = analogRead(potenciometro);}
      else{break;}
      if(j1 > valor && j2 < valor){
        tone(buzzer, frequencia, 400);
        valor = analogRead(potenciometro);}
      if(j1 > valor && j2 < valor){
        delay(espaco);
        valor = analogRead(potenciometro);}
      else{break;}
      if(j1 > valor && j2 < valor){
        tone(buzzer, frequencia, 100);
        valor = analogRead(potenciometro);
        if(not(digitalRead(2) == HIGH && digitalRead(3) == HIGH && digitalRead(4) == HIGH && digitalRead(5) == HIGH && digitalRead(6) == HIGH)){
          if(digitalRead(wire[t]) == LOW){
            digitalWrite(ledconfG, HIGH);
            delay(timer1);
            digitalWrite(ledconfR, LOW);
            delay(timer2);
            fase = 1;}
        else if(digitalRead(wire[t]) == HIGH){
          for(i = 0; i <= 4; i++){
            if(digitalRead(wire[i]) == LOW){
              erro_vetor[i]=1;
              digitalWrite(ledconfR, HIGH);}
            erro = erro_vetor[0] + erro_vetor[1] + erro_vetor[2] + erro_vetor[3] + erro_vetor[4];}}}        }
      else{break;}  
      if(j1 > valor && j2 < valor){
        delay(letra);
        valor = analogRead(potenciometro);}
      else{break;}
      if(j1 > valor && j2 < valor){
        tone(buzzer, frequencia, 100);
        valor = analogRead(potenciometro);}
      else{break;}
      if(j1 > valor && j2 < valor){
        delay(letra);
        valor = analogRead(potenciometro);}
      else{break;}
      if(j1 > valor && j2 < valor){
        tone(buzzer, frequencia, 100);
        valor = analogRead(potenciometro);}
      else{break;}
      if(j1 > valor && j2 < valor){
        delay(letra);
        valor = analogRead(potenciometro);}
      else{break;}
      if(j1 > valor && j2 < valor){
        tone(buzzer, frequencia, 400);
        valor = analogRead(potenciometro);}
      else{break;}            
      if(j1 > valor && j2 < valor){
        delay(espaco);
        valor = analogRead(potenciometro);}
      else{break;}
      if(j1 > valor && j2 < valor){
        tone(buzzer, frequencia, 100);
        valor = analogRead(potenciometro);}
      else{break;}
      if(j1 > valor && j2 < valor){
        delay(letra);
        valor = analogRead(potenciometro);}
      else{break;}
      if(j1 > valor && j2 < valor){    
        tone(buzzer, frequencia, 400);
        valor = analogRead(potenciometro);}
      else{break;}
      if(j1 > valor && j2 < valor){  
        delay(letra);
        valor = analogRead(potenciometro);}
      if(j1 > valor && j2 < valor){
        tone(buzzer, frequencia2, 400);
        valor = analogRead(potenciometro);}
      else{break;}  
      if(j1 > valor && j2 < valor){  
        delay(espaco);
        valor = analogRead(potenciometro);}
      else{break;}
}
//faixa 3
    while(k1 > valor && k2 < valor){
      valor = analogRead(potenciometro);     
      noTone(buzzer);
            
      if(k1 > valor && k2 < valor){
        tone(buzzer, frequencia, 100);
        valor = analogRead(potenciometro);
        if(not(digitalRead(2) == HIGH && digitalRead(3) == HIGH && digitalRead(4) == HIGH && digitalRead(5) == HIGH && digitalRead(6) == HIGH)){
          if(digitalRead(wire[t]) == LOW){
            digitalWrite(ledconfG, HIGH);
            delay(timer1);
            digitalWrite(ledconfR, LOW);
            delay(timer2);
            fase = 1;}
        else if(digitalRead(wire[t]) == HIGH){
          for(i = 0; i <= 4; i++){
            if(digitalRead(wire[i]) == LOW){
              erro_vetor[i]=1;
              digitalWrite(ledconfR, HIGH);}
            erro = erro_vetor[0] + erro_vetor[1] + erro_vetor[2] + erro_vetor[3] + erro_vetor[4];}}}        }
      else{break;}
      if(k1 > valor && k2 < valor){  
        delay(letra);
        valor = analogRead(potenciometro);}
      else{break;}
      if(k1 > valor && k2 < valor){  
        tone(buzzer, frequencia, 400);
        valor = analogRead(potenciometro);}
      else{break;}
      if(k1 > valor && k2 < valor){  
        delay(letra);
        valor = analogRead(potenciometro);}
      else{break;}        
      if(k1 > valor && k2 < valor){
        tone(buzzer, frequencia, 100);
        valor = analogRead(potenciometro);}
      else{break;}
      if(k1 > valor && k2 < valor){  
        delay(letra);}
      if(k1 > valor && k2 < valor){
        tone(buzzer, frequencia, 100);
        valor = analogRead(potenciometro);
        if(not(digitalRead(2) == HIGH && digitalRead(3) == HIGH && digitalRead(4) == HIGH && digitalRead(5) == HIGH && digitalRead(6) == HIGH)){
          if(digitalRead(wire[t]) == LOW){
            digitalWrite(ledconfG, HIGH);
            delay(timer1);
            digitalWrite(ledconfR, LOW);
            delay(timer2);
            fase = 1;}
        else if(digitalRead(wire[t]) == HIGH){
          for(i = 0; i <= 4; i++){
            if(digitalRead(wire[i]) == LOW){
              erro_vetor[i]=1;
              digitalWrite(ledconfR, HIGH);}
            erro = erro_vetor[0] + erro_vetor[1] + erro_vetor[2] + erro_vetor[3] + erro_vetor[4];}}}        }
      else{break;}
      if(k1 > valor && k2 < valor){   
        delay(espaco);
        valor = analogRead(potenciometro);}
      else{break;}
      if(k1 > valor && k2 < valor){
        tone(buzzer, frequencia, 100);
        valor = analogRead(potenciometro);}
      else{break;}  
      if(k1 > valor && k2 < valor){
        delay(letra);
        valor = analogRead(potenciometro);}
      else{break;}
      if(k1 > valor && k2 < valor){
        tone(buzzer, frequencia, 400);
        valor = analogRead(potenciometro);}
      else{break;}
      if(k1 > valor && k2 < valor){
        delay(espaco);
        valor = analogRead(potenciometro);}
      else{break;}
      if(k1 > valor && k2 < valor){
        tone(buzzer, frequencia, 400);
        valor = analogRead(potenciometro);}
      else{break;}  
      if(k1 > valor && k2 < valor){
        delay(letra);
        valor = analogRead(potenciometro);
        if(not(digitalRead(2) == HIGH && digitalRead(3) == HIGH && digitalRead(4) == HIGH && digitalRead(5) == HIGH && digitalRead(6) == HIGH)){
          if(digitalRead(wire[t]) == LOW){
            digitalWrite(ledconfG, HIGH);
            delay(timer1);
            digitalWrite(ledconfR, LOW);
            delay(timer2);
            fase = 1;}
        else if(digitalRead(wire[t]) == HIGH){
          for(i = 0; i <= 4; i++){
            if(digitalRead(wire[i]) == LOW){
              erro_vetor[i]=1;
              digitalWrite(ledconfR, HIGH);}
            erro = erro_vetor[0] + erro_vetor[1] + erro_vetor[2] + erro_vetor[3] + erro_vetor[4];}}}        }
      else{break;}
      if(k1 > valor && k2 < valor){
        tone(buzzer, frequencia, 400);
        valor = analogRead(potenciometro);}
      else{break;}
      if(k1 > valor && k2 < valor){
        delay(espaco);
        valor = analogRead(potenciometro);}
      else{break;}
      if(k1 > valor && k2 < valor){
        tone(buzzer, frequencia, 100);
        valor = analogRead(potenciometro);}
      else{break;}
      if(k1 > valor && k2 < valor){
        delay(letra);
        valor = analogRead(potenciometro);}
      else{break;}
      if(k1 > valor && k2 < valor){    
        tone(buzzer, frequencia, 400);
        valor = analogRead(potenciometro);}
      else{break;}
      if(k1 > valor && k2 < valor){  
        delay(letra);
        valor = analogRead(potenciometro);}
      if(k1 > valor && k2 < valor){
        tone(buzzer, frequencia2, 400);
        valor = analogRead(potenciometro);}
      else{break;}  
      if(k1 > valor && k2 < valor){  
        delay(espaco);
        valor = analogRead(potenciometro);}
      else{break;}
}
//faixa 4
    while(l1 > valor && l2 < valor){
      valor = analogRead(potenciometro);     
      noTone(buzzer);
            
      if(l1 > valor && l2 < valor){
        tone(buzzer, frequencia, 100);
        valor = analogRead(potenciometro);
        if(not(digitalRead(2) == HIGH && digitalRead(3) == HIGH && digitalRead(4) == HIGH && digitalRead(5) == HIGH && digitalRead(6) == HIGH)){
          if(digitalRead(wire[t]) == LOW){
            digitalWrite(ledconfG, HIGH);
            delay(timer1);
            digitalWrite(ledconfR, LOW);
            delay(timer2);
            fase = 1;}
        else if(digitalRead(wire[t]) == HIGH){
          for(i = 0; i <= 4; i++){
            if(digitalRead(wire[i]) == LOW){
              erro_vetor[i]=1;
              digitalWrite(ledconfR, HIGH);}
            erro = erro_vetor[0] + erro_vetor[1] + erro_vetor[2] + erro_vetor[3] + erro_vetor[4];}}}        }
      else{break;}
      if(l1 > valor && l2 < valor){  
        delay(letra);
        valor = analogRead(potenciometro);}
      else{break;}
      if(l1 > valor && l2 < valor){  
        tone(buzzer, frequencia, 400);
        valor = analogRead(potenciometro);}
      else{break;}
      if(l1 > valor && l2 < valor){  
        delay(letra);
        valor = analogRead(potenciometro);}
      if(l1 > valor && l2 < valor){
        tone(buzzer, frequencia, 100);
        valor = analogRead(potenciometro);}
      else{break;}
      if(l1 > valor && l2 < valor){  
        delay(letra);
        if(not(digitalRead(2) == HIGH && digitalRead(3) == HIGH && digitalRead(4) == HIGH && digitalRead(5) == HIGH && digitalRead(6) == HIGH)){
          if(digitalRead(wire[t]) == LOW){
            digitalWrite(ledconfG, HIGH);
            delay(timer1);
            digitalWrite(ledconfR, LOW);
            delay(timer2);
            fase = 1;}
        else if(digitalRead(wire[t]) == HIGH){
          for(i = 0; i <= 4; i++){
            if(digitalRead(wire[i]) == LOW){
              erro_vetor[i]=1;
              digitalWrite(ledconfR, HIGH);}
            erro = erro_vetor[0] + erro_vetor[1] + erro_vetor[2] + erro_vetor[3] + erro_vetor[4];}}}        }
      if(l1 > valor && l2 < valor){
        tone(buzzer, frequencia, 100);
        valor = analogRead(potenciometro);}
      else{break;}
      if(l1 > valor && l2 < valor){   
        delay(espaco);
        valor = analogRead(potenciometro);}
      else{break;}
      if(l1 > valor && l2 < valor){
        tone(buzzer, frequencia, 100);
        valor = analogRead(potenciometro);}
      else{break;}  
      if(l1 > valor && l2 < valor){
        delay(espaco);
        valor = analogRead(potenciometro);}
      else{break;}
      if(l1 > valor && l2 < valor){
        tone(buzzer, frequencia, 400);
        valor = analogRead(potenciometro);}
      else{break;}
      if(l1 > valor && l2 < valor){
        delay(letra);
        valor = analogRead(potenciometro);
        if(not(digitalRead(2) == HIGH && digitalRead(3) == HIGH && digitalRead(4) == HIGH && digitalRead(5) == HIGH && digitalRead(6) == HIGH)){
          if(digitalRead(wire[t]) == LOW){
            digitalWrite(ledconfG, HIGH);
            delay(timer1);
            digitalWrite(ledconfR, LOW);
            delay(timer2);
            fase = 1;}
        else if(digitalRead(wire[t]) == HIGH){
          for(i = 0; i <= 4; i++){
            if(digitalRead(wire[i]) == LOW){
              erro_vetor[i]=1;
              digitalWrite(ledconfR, HIGH);}
            erro = erro_vetor[0] + erro_vetor[1] + erro_vetor[2] + erro_vetor[3] + erro_vetor[4];}}}        }
      else{break;}
      if(l1 > valor && l2 < valor){
        tone(buzzer, frequencia, 400);
        valor = analogRead(potenciometro);}
      if(l1 > valor && l2 < valor){
        delay(espaco);
        valor = analogRead(potenciometro);}
      else{break;}
      if(l1 > valor && l2 < valor){
        tone(buzzer, frequencia, 100);
        valor = analogRead(potenciometro);}
      else{break;} 
      if(l1 > valor && l2 < valor){  
        delay(letra);
        valor = analogRead(potenciometro);}
      if(l1 > valor && l2 < valor){
        tone(buzzer, frequencia2, 400);
        valor = analogRead(potenciometro);}
      else{break;}  
      if(l1 > valor && l2 < valor){  
        delay(espaco);
        valor = analogRead(potenciometro);}
      else{break;}
}
//faixa 5
    while(m1 > valor && m2 < valor){
      valor = analogRead(potenciometro);     
      noTone(buzzer);
            
      if(m1 > valor && m2 < valor){
        tone(buzzer, frequencia, 100);
        valor = analogRead(potenciometro);
        if(not(digitalRead(2) == HIGH && digitalRead(3) == HIGH && digitalRead(4) == HIGH && digitalRead(5) == HIGH && digitalRead(6) == HIGH)){
          if(digitalRead(wire[t]) == LOW){
            digitalWrite(ledconfG, HIGH);
            delay(timer1);
            digitalWrite(ledconfR, LOW);
            delay(timer2);
            fase = 1;}
        else if(digitalRead(wire[t]) == HIGH){
          for(i = 0; i <= 4; i++){
            if(digitalRead(wire[i]) == LOW){
              erro_vetor[i]=1;
              digitalWrite(ledconfR, HIGH);}
            erro = erro_vetor[0] + erro_vetor[1] + erro_vetor[2] + erro_vetor[3] + erro_vetor[4];}}}        }
      else{break;}
      if(m1 > valor && m2 < valor){  
        delay(letra);
        valor = analogRead(potenciometro);}
      else{break;}
      if(m1 > valor && m2 < valor){  
        tone(buzzer, frequencia, 400);
        valor = analogRead(potenciometro);}
      else{break;}
      if(m1 > valor && m2 < valor){  
        delay(letra);
        valor = analogRead(potenciometro);}
      if(m1 > valor && m2 < valor){
        tone(buzzer, frequencia, 400);
        valor = analogRead(potenciometro);}
      else{break;}
      if(m1 > valor && m2 < valor){  
        delay(letra);}
      if(m1 > valor && m2 < valor){
        tone(buzzer, frequencia, 100);
        valor = analogRead(potenciometro);
        if(not(digitalRead(2) == HIGH && digitalRead(3) == HIGH && digitalRead(4) == HIGH && digitalRead(5) == HIGH && digitalRead(6) == HIGH)){
          if(digitalRead(wire[t]) == LOW){
            digitalWrite(ledconfG, HIGH);
            delay(timer1);
            digitalWrite(ledconfR, LOW);
            delay(timer2);
            fase = 1;}
        else if(digitalRead(wire[t]) == HIGH){
          for(i = 0; i <= 4; i++){
            if(digitalRead(wire[i]) == LOW){
              erro_vetor[i]=1;
              digitalWrite(ledconfR, HIGH);}
            erro = erro_vetor[0] + erro_vetor[1] + erro_vetor[2] + erro_vetor[3] + erro_vetor[4];}}}        }
      else{break;}
      if(m1 > valor && m2 < valor){   
        delay(espaco);
        valor = analogRead(potenciometro);}
      else{break;}
      if(m1 > valor && m2 < valor){
        tone(buzzer, frequencia, 400);
        valor = analogRead(potenciometro);}
      else{break;}  
      if(m1 > valor && m2 < valor){
        delay(letra);
        valor = analogRead(potenciometro);}
      else{break;}
      if(m1 > valor && m2 < valor){
        tone(buzzer, frequencia, 100);
        valor = analogRead(potenciometro);}
      else{break;}
      if(m1 > valor && m2 < valor){
        delay(espaco);
        valor = analogRead(potenciometro);}
      else{break;}
      if(m1 > valor && m2 < valor){
        tone(buzzer, frequencia, 100);
        valor = analogRead(potenciometro);}
      if(m1 > valor && m2 < valor){
        delay(espaco);
        valor = analogRead(potenciometro);
        if(not(digitalRead(2) == HIGH && digitalRead(3) == HIGH && digitalRead(4) == HIGH && digitalRead(5) == HIGH && digitalRead(6) == HIGH)){
          if(digitalRead(wire[t]) == LOW){
            digitalWrite(ledconfG, HIGH);
            delay(timer1);
            digitalWrite(ledconfR, LOW);
            delay(timer2);
            fase = 1;}
        else if(digitalRead(wire[t]) == HIGH){
          for(i = 0; i <= 4; i++){
            if(digitalRead(wire[i]) == LOW){
              erro_vetor[i]=1;
              digitalWrite(ledconfR, HIGH);}
            erro = erro_vetor[0] + erro_vetor[1] + erro_vetor[2] + erro_vetor[3] + erro_vetor[4];}}}        }
      else{break;}
      if(m1 > valor && m2 < valor){
        tone(buzzer, frequencia, 100);
        valor = analogRead(potenciometro);}
      else{break;} 
      if(m1 > valor && m2 < valor){
        delay(letra);
        valor = analogRead(potenciometro);}
      else{break;}
      if(m1 > valor && m2 < valor){
        tone(buzzer, frequencia, 100);
        valor = analogRead(potenciometro);}
      else{break;}
      if(m1 > valor && m2 < valor){
        delay(letra);
        valor = analogRead(potenciometro);}
      else{break;}
      if(m1 > valor && m2 < valor){
        tone(buzzer, frequencia, 400);
        valor = analogRead(potenciometro);}
      if(m1 > valor && m2 < valor){
        delay(letra);
        valor = analogRead(potenciometro);}
      else{break;}
      if(m1 > valor && m2 < valor){
        tone(buzzer, frequencia2, 400);
        valor = analogRead(potenciometro);}
      else{break;}  
      if(m1 > valor && m2 < valor){  
        delay(espaco);
        valor = analogRead(potenciometro);}
      else{break;}
}
  }

  if(R == 2){
//faixa 1  
    while(i1 > valor && i2 < valor){
      valor = analogRead(potenciometro);     
      noTone(buzzer);
            
      if(i1 > valor && i2 < valor){
        tone(buzzer, frequencia, 100);
        valor = analogRead(potenciometro);
        if(not(digitalRead(2) == HIGH && digitalRead(3) == HIGH && digitalRead(4) == HIGH && digitalRead(5) == HIGH && digitalRead(6) == HIGH)){
          if(digitalRead(wire[t]) == LOW){
            digitalWrite(ledconfG, HIGH);
            delay(timer1);
            digitalWrite(ledconfR, LOW);
            delay(timer2);
            fase = 1;}
        else if(digitalRead(wire[t]) == HIGH){
          for(i = 0; i <= 4; i++){
            if(digitalRead(wire[i]) == LOW){
              erro_vetor[i]=1;
              digitalWrite(ledconfR, HIGH);}
            erro = erro_vetor[0] + erro_vetor[1] + erro_vetor[2] + erro_vetor[3] + erro_vetor[4];}}}        }
      else{break;}
      if(i1 > valor && i2 < valor){  
        delay(letra);
        valor = analogRead(potenciometro);}
      else{break;}
      if(i1 > valor && i2 < valor){  
        tone(buzzer, frequencia, 400);
        valor = analogRead(potenciometro);}
      else{break;}
      if(i1 > valor && i2 < valor){  
        delay(letra);
        valor = analogRead(potenciometro);}
      if(i1 > valor && i2 < valor){
        tone(buzzer, frequencia, 400);
        valor = analogRead(potenciometro);}
      else{break;}
      if(i1 > valor && i2 < valor){  
        delay(letra);}
      if(i1 > valor && i2 < valor){
        tone(buzzer, frequencia, 100);
        valor = analogRead(potenciometro);}
      else{break;}
      if(i1 > valor && i2 < valor){   
        delay(espaco);
        valor = analogRead(potenciometro);}
      else{break;}
      if(i1 > valor && i2 < valor){
        tone(buzzer, frequencia, 100);
        valor = analogRead(potenciometro);
        if(not(digitalRead(2) == HIGH && digitalRead(3) == HIGH && digitalRead(4) == HIGH && digitalRead(5) == HIGH && digitalRead(6) == HIGH)){
          if(digitalRead(wire[t]) == LOW){
            digitalWrite(ledconfG, HIGH);
            delay(timer1);
            digitalWrite(ledconfR, LOW);
            delay(timer2);
            fase = 1;}
        else if(digitalRead(wire[t]) == HIGH){
          for(i = 0; i <= 4; i++){
            if(digitalRead(wire[i]) == LOW){
              erro_vetor[i]=1;
              digitalWrite(ledconfR, HIGH);}
            erro = erro_vetor[0] + erro_vetor[1] + erro_vetor[2] + erro_vetor[3] + erro_vetor[4];}}}        }
      else{break;}  
      if(i1 > valor && i2 < valor){
        delay(letra);
        valor = analogRead(potenciometro);}
      else{break;}
      if(i1 > valor && i2 < valor){
        tone(buzzer, frequencia, 400);
        valor = analogRead(potenciometro);}
      else{break;}
      if(i1 > valor && i2 < valor){
        delay(letra);
        valor = analogRead(potenciometro);}
      else{break;}
      if(i1 > valor && i2 < valor){
        tone(buzzer, frequencia, 400);
        valor = analogRead(potenciometro);}
      if(i1 > valor && i2 < valor){
        delay(espaco);
        valor = analogRead(potenciometro);}
      else{break;}
      if(i1 > valor && i2 < valor){
        tone(buzzer, frequencia, 100);
        valor = analogRead(potenciometro);}
      else{break;} 
      if(i1 > valor && i2 < valor){
        delay(letra);
        valor = analogRead(potenciometro);}
      else{break;}
      if(i1 > valor && i2 < valor){
        tone(buzzer, frequencia, 400);
        valor = analogRead(potenciometro);}
      else{break;}
      if(i1 > valor && i2 < valor){
        delay(letra);
        valor = analogRead(potenciometro);
        if(not(digitalRead(2) == HIGH && digitalRead(3) == HIGH && digitalRead(4) == HIGH && digitalRead(5) == HIGH && digitalRead(6) == HIGH)){
          if(digitalRead(wire[t]) == LOW){
            digitalWrite(ledconfG, HIGH);
            delay(timer1);
            digitalWrite(ledconfR, LOW);
            delay(timer2);
            fase = 1;}
        else if(digitalRead(wire[t]) == HIGH){
          for(i = 0; i <= 4; i++){
            if(digitalRead(wire[i]) == LOW){
              erro_vetor[i]=1;
              digitalWrite(ledconfR, HIGH);}
            erro = erro_vetor[0] + erro_vetor[1] + erro_vetor[2] + erro_vetor[3] + erro_vetor[4];}}}        }
      else{break;}
      if(i1 > valor && i2 < valor){
        tone(buzzer, frequencia, 100);
        valor = analogRead(potenciometro);}
      if(i1 > valor && i2 < valor){
        delay(espaco);
        valor = analogRead(potenciometro);}
      else{break;}
      if(i1 > valor && i2 < valor){
        tone(buzzer, frequencia, 400);
        valor = analogRead(potenciometro);}
      else{break;}
      if(i1 > valor && i2 < valor){
        delay(letra);
        valor = analogRead(potenciometro);}
      if(i1 > valor && i2 < valor){
        tone(buzzer, frequencia, 400);
        valor = analogRead(potenciometro);}
      else{break;}
      if(i1 > valor && i2 < valor){
        delay(letra);
        valor = analogRead(potenciometro);}
      if(i1 > valor && i2 < valor){
        tone(buzzer, frequencia, 400);
        valor = analogRead(potenciometro);}
      else{break;}
      if(i1 > valor && i2 < valor){
        delay(letra);
        valor = analogRead(potenciometro);}                      
      if(i1 > valor && i2 < valor){
        tone(buzzer, frequencia2, 400);
        valor = analogRead(potenciometro);}
      else{break;}  
      if(i1 > valor && i2 < valor){  
        delay(espaco);
        valor = analogRead(potenciometro);}
      else{break;}
}
//faixa 2   
    while(j1 > valor && j2 < valor){
      valor = analogRead(potenciometro);     
      noTone(buzzer);
            
      if(j1 > valor && j2 < valor){
        tone(buzzer, frequencia, 100);
        valor = analogRead(potenciometro);
        if(not(digitalRead(2) == HIGH && digitalRead(3) == HIGH && digitalRead(4) == HIGH && digitalRead(5) == HIGH && digitalRead(6) == HIGH)){
          if(digitalRead(wire[t]) == LOW){
            digitalWrite(ledconfG, HIGH);
            delay(timer1);
            digitalWrite(ledconfR, LOW);
            delay(timer2);
            fase = 1;}
        else if(digitalRead(wire[t]) == HIGH){
          for(i = 0; i <= 4; i++){
            if(digitalRead(wire[i]) == LOW){
              erro_vetor[i]=1;
              digitalWrite(ledconfR, HIGH);}
            erro = erro_vetor[0] + erro_vetor[1] + erro_vetor[2] + erro_vetor[3] + erro_vetor[4];}}}        }
      else{break;}
      if(j1 > valor && j2 < valor){  
        delay(letra);
        valor = analogRead(potenciometro);}
      else{break;}
      if(j1 > valor && j2 < valor){  
        tone(buzzer, frequencia, 400);
        valor = analogRead(potenciometro);}
      else{break;}
      if(j1 > valor && j2 < valor){  
        delay(letra);
        valor = analogRead(potenciometro);}
      if(j1 > valor && j2 < valor){
        tone(buzzer, frequencia, 400);
        valor = analogRead(potenciometro);}
      else{break;}
      if(j1 > valor && j2 < valor){  
        delay(letra);}
      if(j1 > valor && j2 < valor){
        tone(buzzer, frequencia, 100);
        valor = analogRead(potenciometro);}
      else{break;}
      if(j1 > valor && j2 < valor){   
        delay(espaco);
        valor = analogRead(potenciometro);
        if(not(digitalRead(2) == HIGH && digitalRead(3) == HIGH && digitalRead(4) == HIGH && digitalRead(5) == HIGH && digitalRead(6) == HIGH)){
          if(digitalRead(wire[t]) == LOW){
            digitalWrite(ledconfG, HIGH);
            delay(timer1);
            digitalWrite(ledconfR, LOW);
            delay(timer2);
            fase = 1;}
        else if(digitalRead(wire[t]) == HIGH){
          for(i = 0; i <= 4; i++){
            if(digitalRead(wire[i]) == LOW){
              erro_vetor[i]=1;
              digitalWrite(ledconfR, HIGH);}
            erro = erro_vetor[0] + erro_vetor[1] + erro_vetor[2] + erro_vetor[3] + erro_vetor[4];}}}        }
      else{break;}
      if(j1 > valor && j2 < valor){
        tone(buzzer, frequencia, 100);
        valor = analogRead(potenciometro);}
      else{break;}  
      if(j1 > valor && j2 < valor){
        delay(espaco);
        valor = analogRead(potenciometro);}
      else{break;}
      if(j1 > valor && j2 < valor){
        tone(buzzer, frequencia, 100);
        valor = analogRead(potenciometro);}
      else{break;}
      if(j1 > valor && j2 < valor){
        delay(letra);
        valor = analogRead(potenciometro);}
      else{break;}
      if(j1 > valor && j2 < valor){
        tone(buzzer, frequencia, 100);
        valor = analogRead(potenciometro);}
      if(j1 > valor && j2 < valor){
        delay(letra);
        valor = analogRead(potenciometro);}
      else{break;}
      if(j1 > valor && j2 < valor){
        tone(buzzer, frequencia, 100);
        valor = analogRead(potenciometro);}
      else{break;} 
      if(j1 > valor && j2 < valor){
        delay(espaco);
        valor = analogRead(potenciometro);
        if(not(digitalRead(2) == HIGH && digitalRead(3) == HIGH && digitalRead(4) == HIGH && digitalRead(5) == HIGH && digitalRead(6) == HIGH)){
          if(digitalRead(wire[t]) == LOW){
            digitalWrite(ledconfG, HIGH);
            delay(timer1);
            digitalWrite(ledconfR, LOW);
            delay(timer2);
            fase = 1;}
        else if(digitalRead(wire[t]) == HIGH){
          for(i = 0; i <= 4; i++){
            if(digitalRead(wire[i]) == LOW){
              erro_vetor[i]=1;
              digitalWrite(ledconfR, HIGH);}
            erro = erro_vetor[0] + erro_vetor[1] + erro_vetor[2] + erro_vetor[3] + erro_vetor[4];}}}        }
      else{break;}
      if(j1 > valor && j2 < valor){
        tone(buzzer, frequencia, 400);
        valor = analogRead(potenciometro);}
      else{break;}
      if(j1 > valor && j2 < valor){
        delay(letra);
        valor = analogRead(potenciometro);}
      else{break;}
      if(j1 > valor && j2 < valor){
        tone(buzzer, frequencia, 400);
        valor = analogRead(potenciometro);}
      if(j1 > valor && j2 < valor){
        delay(letra);
        valor = analogRead(potenciometro);}
      else{break;}
      if(j1 > valor && j2 < valor){
        tone(buzzer, frequencia, 400);
        valor = analogRead(potenciometro);}
      else{break;}
      if(j1 > valor && j2 < valor){
        delay(letra);
        valor = analogRead(potenciometro);}                  
      if(j1 > valor && j2 < valor){
        tone(buzzer, frequencia2, 400);
        valor = analogRead(potenciometro);}
      else{break;}  
      if(j1 > valor && j2 < valor){  
        delay(espaco);
        valor = analogRead(potenciometro);}
      else{break;}
}
//faixa 3
    while(k1 > valor && k2 < valor){
      valor = analogRead(potenciometro);     
      noTone(buzzer);
            
      if(k1 > valor && k2 < valor){
        tone(buzzer, frequencia, 100);
        valor = analogRead(potenciometro);
        if(not(digitalRead(2) == HIGH && digitalRead(3) == HIGH && digitalRead(4) == HIGH && digitalRead(5) == HIGH && digitalRead(6) == HIGH)){
          if(digitalRead(wire[t]) == LOW){
            digitalWrite(ledconfG, HIGH);
            delay(timer1);
            digitalWrite(ledconfR, LOW);
            delay(timer2);
            fase = 1;}
        else if(digitalRead(wire[t]) == HIGH){
          for(i = 0; i <= 4; i++){
            if(digitalRead(wire[i]) == LOW){
              erro_vetor[i]=1;
              digitalWrite(ledconfR, HIGH);}
            erro = erro_vetor[0] + erro_vetor[1] + erro_vetor[2] + erro_vetor[3] + erro_vetor[4];}}}        }
      else{break;}
      if(k1 > valor && k2 < valor){  
        delay(letra);
        valor = analogRead(potenciometro);}
      else{break;}
      if(k1 > valor && k2 < valor){  
        tone(buzzer, frequencia, 100);
        valor = analogRead(potenciometro);}
      else{break;}
      if(k1 > valor && k2 < valor){  
        delay(letra);
        valor = analogRead(potenciometro);}
      if(k1 > valor && k2 < valor){
        tone(buzzer, frequencia, 100);
        valor = analogRead(potenciometro);}
      else{break;}
      if(k1 > valor && k2 < valor){  
        delay(letra);}
      if(k1 > valor && k2 < valor){
        tone(buzzer, frequencia, 400);
        valor = analogRead(potenciometro);}
      else{break;}
      if(k1 > valor && k2 < valor){   
        delay(espaco);
        valor = analogRead(potenciometro);}
      else{break;}
      if(k1 > valor && k2 < valor){
        tone(buzzer, frequencia, 400);
        valor = analogRead(potenciometro);
        if(not(digitalRead(2) == HIGH && digitalRead(3) == HIGH && digitalRead(4) == HIGH && digitalRead(5) == HIGH && digitalRead(6) == HIGH)){
          if(digitalRead(wire[t]) == LOW){
            digitalWrite(ledconfG, HIGH);
            delay(timer1);
            digitalWrite(ledconfR, LOW);
            delay(timer2);
            fase = 1;}
        else if(digitalRead(wire[t]) == HIGH){
          for(i = 0; i <= 4; i++){
            if(digitalRead(wire[i]) == LOW){
              erro_vetor[i]=1;
              digitalWrite(ledconfR, HIGH);}
            erro = erro_vetor[0] + erro_vetor[1] + erro_vetor[2] + erro_vetor[3] + erro_vetor[4];}}}        }
      else{break;}  
      if(k1 > valor && k2 < valor){
        delay(letra);
        valor = analogRead(potenciometro);}
      else{break;}
      if(k1 > valor && k2 < valor){
        tone(buzzer, frequencia, 400);
        valor = analogRead(potenciometro);}
      else{break;}
      if(k1 > valor && k2 < valor){
        delay(letra);
        valor = analogRead(potenciometro);}
      else{break;}
      if(k1 > valor && k2 < valor){
        tone(buzzer, frequencia, 400);
        valor = analogRead(potenciometro);}
      if(k1 > valor && k2 < valor){
        delay(espaco);
        valor = analogRead(potenciometro);}
      else{break;}
      if(k1 > valor && k2 < valor){
        tone(buzzer, frequencia, 100);
        valor = analogRead(potenciometro);}
      else{break;} 
      if(k1 > valor && k2 < valor){
        delay(letra);
        valor = analogRead(potenciometro);}
      else{break;}
      if(k1 > valor && k2 < valor){
        tone(buzzer, frequencia, 400);
        valor = analogRead(potenciometro);}
      else{break;}
      if(k1 > valor && k2 < valor){
        delay(espaco);
        valor = analogRead(potenciometro);
        if(not(digitalRead(2) == HIGH && digitalRead(3) == HIGH && digitalRead(4) == HIGH && digitalRead(5) == HIGH && digitalRead(6) == HIGH)){
          if(digitalRead(wire[t]) == LOW){
            digitalWrite(ledconfG, HIGH);
            delay(timer1);
            digitalWrite(ledconfR, LOW);
            delay(timer2);
            fase = 1;}
        else if(digitalRead(wire[t]) == HIGH){
          for(i = 0; i <= 4; i++){
            if(digitalRead(wire[i]) == LOW){
              erro_vetor[i]=1;
              digitalWrite(ledconfR, HIGH);}
            erro = erro_vetor[0] + erro_vetor[1] + erro_vetor[2] + erro_vetor[3] + erro_vetor[4];}}}        }
      else{break;}
      if(k1 > valor && k2 < valor){
        tone(buzzer, frequencia, 100);
        valor = analogRead(potenciometro);}
      if(k1 > valor && k2 < valor){
        delay(letra);
        valor = analogRead(potenciometro);}
      else{break;}
      if(k1 > valor && k2 < valor){
        tone(buzzer, frequencia, 400);
        valor = analogRead(potenciometro);}
      else{break;}
      if(k1 > valor && k2 < valor){
        delay(letra);
        valor = analogRead(potenciometro);}
      if(k1 > valor && k2 < valor){
        tone(buzzer, frequencia, 100);
        valor = analogRead(potenciometro);}
      else{break;}
      if(k1 > valor && k2 < valor){
        delay(letra);
        valor = analogRead(potenciometro);}
      else{break;}               
      if(k1 > valor && k2 < valor){
        tone(buzzer, frequencia2, 400);
        valor = analogRead(potenciometro);}
      else{break;}  
      if(k1 > valor && k2 < valor){  
        delay(espaco);
        valor = analogRead(potenciometro);}
      else{break;}
}
//faixa 4
    while(l1 > valor && l2 < valor){
      valor = analogRead(potenciometro);     
      noTone(buzzer);
            
      if(l1 > valor && l2 < valor){
        tone(buzzer, frequencia, 100);
        valor = analogRead(potenciometro);
        if(not(digitalRead(2) == HIGH && digitalRead(3) == HIGH && digitalRead(4) == HIGH && digitalRead(5) == HIGH && digitalRead(6) == HIGH)){
          if(digitalRead(wire[t]) == LOW){
            digitalWrite(ledconfG, HIGH);
            delay(timer1);
            digitalWrite(ledconfR, LOW);
            delay(timer2);
            fase = 1;}
        else if(digitalRead(wire[t]) == HIGH){
          for(i = 0; i <= 4; i++){
            if(digitalRead(wire[i]) == LOW){
              erro_vetor[i]=1;
              digitalWrite(ledconfR, HIGH);}
            erro = erro_vetor[0] + erro_vetor[1] + erro_vetor[2] + erro_vetor[3] + erro_vetor[4];}}}        }
      else{break;}
      if(l1 > valor && l2 < valor){  
        delay(letra);
        valor = analogRead(potenciometro);}
      else{break;}
      if(l1 > valor && l2 < valor){  
        tone(buzzer, frequencia, 100);
        valor = analogRead(potenciometro);}
      else{break;}
      if(l1 > valor && l2 < valor){  
        delay(letra);
        valor = analogRead(potenciometro);}
      if(l1 > valor && l2 < valor){
        tone(buzzer, frequencia, 100);
        valor = analogRead(potenciometro);}
      else{break;}
      if(l1 > valor && l2 < valor){  
        delay(letra);}
      if(l1 > valor && l2 < valor){
        tone(buzzer, frequencia, 400);
        valor = analogRead(potenciometro);}
      else{break;}
      if(l1 > valor && l2 < valor){   
        delay(espaco);
        valor = analogRead(potenciometro);}
      else{break;}
      if(l1 > valor && l2 < valor){
        tone(buzzer, frequencia, 100);
        valor = analogRead(potenciometro);
        if(not(digitalRead(2) == HIGH && digitalRead(3) == HIGH && digitalRead(4) == HIGH && digitalRead(5) == HIGH && digitalRead(6) == HIGH)){
          if(digitalRead(wire[t]) == LOW){
            digitalWrite(ledconfG, HIGH);
            delay(timer1);
            digitalWrite(ledconfR, LOW);
            delay(timer2);
            fase = 1;}
        else if(digitalRead(wire[t]) == HIGH){
          for(i = 0; i <= 4; i++){
            if(digitalRead(wire[i]) == LOW){
              erro_vetor[i]=1;
              digitalWrite(ledconfR, HIGH);}
            erro = erro_vetor[0] + erro_vetor[1] + erro_vetor[2] + erro_vetor[3] + erro_vetor[4];}}}        }
      else{break;}  
      if(l1 > valor && l2 < valor){
        delay(letra);
        valor = analogRead(potenciometro);}
      else{break;}
      if(l1 > valor && l2 < valor){
        tone(buzzer, frequencia, 400);
        valor = analogRead(potenciometro);}
      else{break;}
      if(l1 > valor && l2 < valor){
        delay(espaco);
        valor = analogRead(potenciometro);}
      else{break;}
      if(l1 > valor && l2 < valor){
        tone(buzzer, frequencia, 100);
        valor = analogRead(potenciometro);}
      if(l1 > valor && l2 < valor){
        delay(letra);
        valor = analogRead(potenciometro);}
      else{break;}
      if(l1 > valor && l2 < valor){
        tone(buzzer, frequencia, 100);
        valor = analogRead(potenciometro);}
      else{break;} 
      if(l1 > valor && l2 < valor){
        delay(letra);
        valor = analogRead(potenciometro);}
      else{break;}
      if(l1 > valor && l2 < valor){
        tone(buzzer, frequencia, 100);
        valor = analogRead(potenciometro);}
      else{break;}
      if(l1 > valor && l2 < valor){
        delay(espaco);
        valor = analogRead(potenciometro);
        if(not(digitalRead(2) == HIGH && digitalRead(3) == HIGH && digitalRead(4) == HIGH && digitalRead(5) == HIGH && digitalRead(6) == HIGH)){
          if(digitalRead(wire[t]) == LOW){
            digitalWrite(ledconfG, HIGH);
            delay(timer1);
            digitalWrite(ledconfR, LOW);
            delay(timer2);
            fase = 1;}
        else if(digitalRead(wire[t]) == HIGH){
          for(i = 0; i <= 4; i++){
            if(digitalRead(wire[i]) == LOW){
              erro_vetor[i]=1;
              digitalWrite(ledconfR, HIGH);}
            erro = erro_vetor[0] + erro_vetor[1] + erro_vetor[2] + erro_vetor[3] + erro_vetor[4];}}}        }
      else{break;}
      if(l1 > valor && l2 < valor){
        tone(buzzer, frequencia, 400);
        valor = analogRead(potenciometro);}
      if(l1 > valor && l2 < valor){
        delay(letra);
        valor = analogRead(potenciometro);}
      else{break;}
      if(l1 > valor && l2 < valor){
        tone(buzzer, frequencia, 400);
        valor = analogRead(potenciometro);}
      else{break;}
      if(l1 > valor && l2 < valor){
        delay(letra);
        valor = analogRead(potenciometro);}
      if(l1 > valor && l2 < valor){
        tone(buzzer, frequencia, 400);
        valor = analogRead(potenciometro);}
      else{break;}
      if(l1 > valor && l2 < valor){
        delay(letra);
        valor = analogRead(potenciometro);}
      else{break;}               
      if(l1 > valor && l2 < valor){
        tone(buzzer, frequencia2, 400);
        valor = analogRead(potenciometro);}
      else{break;}  
      if(l1 > valor && l2 < valor){  
        delay(espaco);
        valor = analogRead(potenciometro);}
      else{break;}
}
//faixa 5
    while(m1 > valor && m2 < valor){
      valor = analogRead(potenciometro);     
      noTone(buzzer);
            
      if(m1 > valor && m2 < valor){
        tone(buzzer, frequencia, 100);
        valor = analogRead(potenciometro);
        if(not(digitalRead(2) == HIGH && digitalRead(3) == HIGH && digitalRead(4) == HIGH && digitalRead(5) == HIGH && digitalRead(6) == HIGH)){
          if(digitalRead(wire[t]) == LOW){
            digitalWrite(ledconfG, HIGH);
            delay(timer1);
            digitalWrite(ledconfR, LOW);
            delay(timer2);
            fase = 1;}
        else if(digitalRead(wire[t]) == HIGH){
          for(i = 0; i <= 4; i++){
            if(digitalRead(wire[i]) == LOW){
              erro_vetor[i]=1;
              digitalWrite(ledconfR, HIGH);}
            erro = erro_vetor[0] + erro_vetor[1] + erro_vetor[2] + erro_vetor[3] + erro_vetor[4];}}}        }
      else{break;}
      if(m1 > valor && m2 < valor){  
        delay(letra);
        valor = analogRead(potenciometro);}
      else{break;}
      if(m1 > valor && m2 < valor){  
        tone(buzzer, frequencia, 100);
        valor = analogRead(potenciometro);}
      else{break;}
      if(m1 > valor && m2 < valor){  
        delay(letra);
        valor = analogRead(potenciometro);}
      if(m1 > valor && m2 < valor){
        tone(buzzer, frequencia, 100);
        valor = analogRead(potenciometro);}
      else{break;}
      if(m1 > valor && m2 < valor){  
        delay(letra);}
      if(m1 > valor && m2 < valor){
        tone(buzzer, frequencia, 400);
        valor = analogRead(potenciometro);
        if(not(digitalRead(2) == HIGH && digitalRead(3) == HIGH && digitalRead(4) == HIGH && digitalRead(5) == HIGH && digitalRead(6) == HIGH)){
          if(digitalRead(wire[t]) == LOW){
            digitalWrite(ledconfG, HIGH);
            delay(timer1);
            digitalWrite(ledconfR, LOW);
            delay(timer2);
            fase = 1;}
        else if(digitalRead(wire[t]) == HIGH){
          for(i = 0; i <= 4; i++){
            if(digitalRead(wire[i]) == LOW){
              erro_vetor[i]=1;
              digitalWrite(ledconfR, HIGH);}
            erro = erro_vetor[0] + erro_vetor[1] + erro_vetor[2] + erro_vetor[3] + erro_vetor[4];}}}        }
      else{break;}
      if(m1 > valor && m2 < valor){   
        delay(espaco);
        valor = analogRead(potenciometro);}
      else{break;}
      if(m1 > valor && m2 < valor){
        tone(buzzer, frequencia, 400);
        valor = analogRead(potenciometro);}
      else{break;}  
      if(m1 > valor && m2 < valor){
        delay(letra);
        valor = analogRead(potenciometro);}
      else{break;}
      if(m1 > valor && m2 < valor){
        tone(buzzer, frequencia, 400);
        valor = analogRead(potenciometro);}
      else{break;}
      if(m1 > valor && m2 < valor){
        delay(letra);
        valor = analogRead(potenciometro);}
      else{break;}
      if(m1 > valor && m2 < valor){
        tone(buzzer, frequencia, 400);
        valor = analogRead(potenciometro);}
      if(m1 > valor && m2 < valor){
        delay(espaco);
        valor = analogRead(potenciometro);
        if(not(digitalRead(2) == HIGH && digitalRead(3) == HIGH && digitalRead(4) == HIGH && digitalRead(5) == HIGH && digitalRead(6) == HIGH)){
          if(digitalRead(wire[t]) == LOW){
            digitalWrite(ledconfG, HIGH);
            delay(timer1);
            digitalWrite(ledconfR, LOW);
            delay(timer2);
            fase = 1;}
        else if(digitalRead(wire[t]) == HIGH){
          for(i = 0; i <= 4; i++){
            if(digitalRead(wire[i]) == LOW){
              erro_vetor[i]=1;
              digitalWrite(ledconfR, HIGH);}
            erro = erro_vetor[0] + erro_vetor[1] + erro_vetor[2] + erro_vetor[3] + erro_vetor[4];}}}        }
      else{break;}
      if(m1 > valor && m2 < valor){
        tone(buzzer, frequencia, 400);
        valor = analogRead(potenciometro);}
      else{break;} 
      if(m1 > valor && m2 < valor){
        delay(espaco);
        valor = analogRead(potenciometro);}
      else{break;}
      if(m1 > valor && m2 < valor){
        tone(buzzer, frequencia, 400);
        valor = analogRead(potenciometro);}
      else{break;}
      if(m1 > valor && m2 < valor){
        delay(letra);
        valor = analogRead(potenciometro);}
      else{break;}
      if(m1 > valor && m2 < valor){
        tone(buzzer, frequencia, 400);
        valor = analogRead(potenciometro);}
      if(m1 > valor && m2 < valor){
        delay(letra);
        valor = analogRead(potenciometro);}
      if(m1 > valor && m2 < valor){
        tone(buzzer, frequencia, 400);
        valor = analogRead(potenciometro);}
      if(m1 > valor && m2 < valor){
        delay(letra);
        valor = analogRead(potenciometro);}
      else{break;}   
      if(m1 > valor && m2 < valor){
        tone(buzzer, frequencia2, 400);
        valor = analogRead(potenciometro);}
      else{break;}  
      if(m1 > valor && m2 < valor){  
        delay(espaco);
        valor = analogRead(potenciometro);}
      else{break;}
}
  }

//Verificação do fio correto:

  if(not(digitalRead(2) == HIGH && digitalRead(3) == HIGH && digitalRead(4) == HIGH && digitalRead(5) == HIGH && digitalRead(6) == HIGH)){
    if(digitalRead(wire[t]) == LOW){
      digitalWrite(ledconfG, HIGH);
      delay(timer1);
      digitalWrite(ledconfR, LOW);
      delay(timer2);
      fase = 1;}
    else if(digitalRead(wire[t]) == HIGH){
      for(i = 0; i <= 4; i++){
        if(digitalRead(wire[i]) == LOW){
          erro_vetor[i]=1;
          digitalWrite(ledconfR, HIGH);}
        erro = erro_vetor[0] + erro_vetor[1] + erro_vetor[2] + erro_vetor[3] + erro_vetor[4];}}}
    
Serial.println(valor);}

if(fase == 1){
  digitalWrite(ledconfG, HIGH);
  digitalWrite(ledconfR, LOW);}  
}
