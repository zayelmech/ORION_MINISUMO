// #include "Arduino.h"
#include "Motores.h"

Motores::Motores(int IN1A, int IN2A, int PWMA,int IN1B, int IN2B, int PWMB)
{
   pinMode(IN1A, OUTPUT);
   pinMode(IN2A, OUTPUT);
   pinMode(PWMA, OUTPUT);
   pinMode(IN1B, OUTPUT);
   pinMode(IN2B, OUTPUT);
   pinMode(PWMB, OUTPUT);
  _IN1A = IN1A;
  _IN2A = IN2A;
  _PWMA = PWMA;
  _IN1B = IN1B;
  _IN2B = IN2B;
  _PWMB = PWMB;
}

void Motores::izq(int poderA){
  if(poderA>0){
    digitalWrite(_IN1A,LOW);
    digitalWrite(_IN2A,HIGH);
    analogWrite(_PWMA,abs(poderA));
    }
  else if(poderA<0){
    digitalWrite(_IN2A,LOW);
    digitalWrite(_IN1A,HIGH);
    analogWrite(_PWMA,abs(poderA));
    }
  else{
    digitalWrite(_IN1A,LOW);
    digitalWrite(_IN2A,LOW);
    analogWrite(_PWMA,0);
    }
}
void Motores::der(int poderB){
  if(poderB>0){
    digitalWrite(_IN2B,LOW);
    digitalWrite(_IN1B,HIGH);
    analogWrite(_PWMB,abs(poderB));
    }
  else if(poderB<0){
    digitalWrite(_IN1B,LOW);
    digitalWrite(_IN2B,HIGH);
    analogWrite(_PWMB,abs(poderB));
    }
  else{
    digitalWrite(_IN1B,LOW);
    digitalWrite(_IN2B,LOW);
    analogWrite(_PWMB,0);
    }
}
  
