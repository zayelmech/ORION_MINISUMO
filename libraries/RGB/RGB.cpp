 
//#include "Arduino.h"
#include "RGB.h"

RGB::RGB(int pinR, int pinG, int pinB){
   pinMode(pinR, OUTPUT);
   pinMode(pinG, OUTPUT);
   pinMode(pinB, OUTPUT);
  _pinR = pinR;
  _pinG = pinG;
  _pinB = pinB;
  
  }

/*void RGB::color(String colorName){
  switch (colorName){
    case "rojo":
      digitalWrite(_pinR,HIGH);
      digitalWrite(_pinG,LOW);
      digitalWrite(_pinB,LOW);
      break;
    case "azul":
      digitalWrite(_pinR,LOW);
      digitalWrite(_pinG,LOW);
      digitalWrite(_pinB,HIGH);
      break;
    case "verde":
      digitalWrite(_pinR,LOW);
      digitalWrite(_pinG,HIGH);
      digitalWrite(_pinB,LOW);
      break;
    case "amarillo":
      digitalWrite(_pinR,HIGH);
      digitalWrite(_pinG,HIGH);
      digitalWrite(_pinB,LOW);
      break;  
    case "morado":
      digitalWrite(_pinR,HIGH);
      digitalWrite(_pinG,LOW);
      digitalWrite(_pinB,HIGH);
      break;  
   case "turquesa":
      digitalWrite(_pinR,LOW);
      digitalWrite(_pinG,HIGH);
      digitalWrite(_pinB,HIGH);
      break;  
   case "blanco":
      digitalWrite(_pinR,HIGH);
      digitalWrite(_pinG,HIGH);
      digitalWrite(_pinB,HIGH);
      break;  

   default:
      digitalWrite(_pinR,LOW);
      digitalWrite(_pinG,LOW);
      digitalWrite(_pinB,LOW);
      break;  
  }


}
*/
void RGB::valores(int valueR, int valueG, int valueB){

  if(_pinR==3 || _pinR==5 ||_pinR==6 ||_pinR==9 ||_pinR==10 ||_pinR==11){
    
    analogWrite(_pinR,valueR);
    }
   
  else{
     if(valueR>0)  
       digitalWrite(_pinR,HIGH);
     else
       digitalWrite(_pinR,LOW);
    }

 
  if(_pinG==3 || _pinG==5 ||_pinG==6 ||_pinG==9 ||_pinG==10 ||_pinG==11){
    
    analogWrite(_pinG,valueG);
    }
   
  else{
     if(valueG>0)  
       digitalWrite(_pinG,HIGH);
     else
       digitalWrite(_pinG,LOW);
    }
    
  if(_pinB==3 || _pinB==5 ||_pinB==6 ||_pinB==9 ||_pinB==10 ||_pinB==11){
    
    analogWrite(_pinB,valueB);
    }
   
  else{
     if(valueB>0)  
       digitalWrite(_pinB,HIGH);
     else
       digitalWrite(_pinB,LOW);
    }
  }
  
