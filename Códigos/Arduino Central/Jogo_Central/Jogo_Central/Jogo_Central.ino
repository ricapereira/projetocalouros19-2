#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

int acionamento = 0;
int controle_acionamento;
int erro_geral;
int erro_senhas;
int erro_leds;
int erro_memoria;
int erro_fios;
char selecao_jogo = 'A';
int suporte = 0;
int S = 0;
int M = 5;
int contador_loop = 10;
int fim_senhas;
int fim_geral;
int fim_leds;
int fim_memoria;
int fim_fios;
byte reset = 0;
int cont=0;

void setup(){
  Wire.begin();
  Serial.begin(9600);
  lcd.begin (16, 2);
  pinMode(8, INPUT); 
  pinMode(2, OUTPUT);
  pinMode(9, OUTPUT);
  
}

void loop(){
  
  if(erro_geral >= 3){
    lcd.clear();
    lcd.setCursor(6,0);
    lcd.print("GAME");
    lcd.setCursor(6,1);
    lcd.print("OVER");
    Wire.beginTransmission(1);
    Wire.write(erro_geral);
    Wire.endTransmission();
    tone(9,2000);
    delay(5000);
    noTone(9);
    acionamento = 0;
    erro_geral = 0;
    }
  contador_loop--;
  if(contador_loop == 0){
    contador_loop = 10;
    }
  controle_acionamento = digitalRead(8);
  if(controle_acionamento == HIGH){
    acionamento++;
    delay(200);
    if(acionamento == 2){
      acionamento = 0;
      }
    }
  if(acionamento == 1){
    if((M > 0)||(S>59)){
    if(contador_loop == 10){
      tone(9,2000);
    }
    if(contador_loop<10){
      noTone(9);
    }}
    else{
      if(contador_loop == 10){
        tone(9,2000);
      }
      if((contador_loop<10)&&(contador_loop > 5)){
        noTone(9);
      }
      if(contador_loop == 5){
        tone(9,2000);}
      if(contador_loop < 5){
        noTone(9);
      }
      }
    reset = 0;
    digitalWrite(2, HIGH);
    if(suporte == 0){
      selecao_jogo = 'B';
      suporte = 1;
      }  
    Wire.beginTransmission(1);
    Wire.write(selecao_jogo);
    Wire.write(erro_geral);
    Wire.endTransmission(); 
    Wire.requestFrom(1, 2);
    if(Wire.available()){
      int erro_recebido_senhas = Wire.read();
      erro_senhas = erro_recebido_senhas;
      int fim_recebido_senhas = Wire.read();
      fim_senhas = fim_recebido_senhas;
      }
    Wire.beginTransmission(2);
    Wire.write(selecao_jogo); 
    Wire.endTransmission(); 
    Wire.requestFrom(2, 2);
    if(Wire.available()){
      int erro_recebido_leds = Wire.read();
      erro_leds = erro_recebido_leds;
      int fim_recebido_leds = Wire.read();
      fim_leds = fim_recebido_leds;
      } 

    Wire.beginTransmission(3);
    Wire.write(selecao_jogo); 
    Wire.endTransmission();
    Wire.requestFrom(3, 2);
    if(Wire.available()){
      int erro_recebido_memoria = Wire.read();
      erro_memoria = erro_recebido_memoria;
      int fim_recebido_memoria = Wire.read();
      fim_memoria = fim_recebido_memoria;
      }

    Wire.beginTransmission(4);
    Wire.write(selecao_jogo); 
    Wire.endTransmission();
    Wire.requestFrom(4, 2);
    if(Wire.available()){
      int erro_recebido_fios = Wire.read();
      erro_fios = erro_recebido_fios;
      int fim_recebido_fios = Wire.read();
      fim_fios = fim_recebido_fios;
      }  
    erro_geral = erro_senhas + erro_leds + erro_memoria + erro_fios;
    fim_geral = fim_senhas + fim_leds + fim_memoria + fim_fios;

    if(erro_geral == 1 && cont <=5){
       tone(9,100);
       cont++;
      }
     if(erro_geral == 2 && cont <=10){
       tone(9,100);
       cont++;
      }
    
    if(fim_geral == 4){
      lcd.clear();
      lcd.setCursor(6, 0);
      lcd.print("BOMBA");
      lcd.setCursor(4, 1);
      lcd.print("DESARMADA!");
      delay(5000);
      acionamento = 0;
      }
    //Serial.print(fim_senhas);
    //Serial.print(fim_leds);
    
    if(contador_loop == 10){
      lcd.clear();
      lcd.setCursor(0, 1);
      lcd.print("ERROS:");
      lcd.setCursor(8, 1);
      lcd.print(erro_geral);  
      lcd.setCursor(0,0);
      lcd.print("TEMPO:");
      S--;
      if(S<0 && M>=0){
        M--;
        S = 59;
        }
      if(M<0){
        lcd.clear();
        lcd.setCursor(6,0);
        lcd.print("GAME");
        lcd.setCursor(6,1);
        lcd.print("OVER");
        erro_geral = 3;
        Wire.beginTransmission(1);
        Wire.write(erro_geral);
        Wire.endTransmission();
        delay(5000);
        acionamento = 0;
        }
      if(M>9 && M>=0){
        lcd.setCursor(7,0);
        lcd.print(M);
        lcd.setCursor(9,0);
        lcd.print(":");
        }
      else if(M>=0){
        lcd.setCursor(7,0);
        lcd.print("0");
        lcd.setCursor(8,0);
        lcd.print(M);
        lcd.setCursor(9,0);
        lcd.print(":");
        }
      if(S>9 && M>=0){
        lcd.setCursor(10,0);
        lcd.print(S);
        }
      else if(M>=0){
        lcd.setCursor(10,0);
        lcd.print("0");
        lcd.setCursor(11,0);
        lcd.print(S);
        }
      }
    delay(100);
    }
    if(acionamento == 0){
      cont = 0;
      M = 5;
      S = 0;
      if(reset == 0){
        digitalWrite(2, LOW);
        delay(100);
        reset = 1;
        }
      digitalWrite(2, HIGH);  
      lcd.clear();
      lcd.setCursor(4, 0);
      lcd.print("INICIE");
      lcd.setCursor(4, 1);
      lcd.print("O JOGO!");
      selecao_jogo = 'A';
      erro_geral = 0;
      Wire.beginTransmission(1);
      Wire.write(selecao_jogo);
      Wire.write(erro_geral);
      Wire.endTransmission();
      suporte = 0; 
      delay(100);
      }
  Serial.print(erro_fios); 
  Serial.print("  ");
  Serial.println(fim_fios);    
}  

