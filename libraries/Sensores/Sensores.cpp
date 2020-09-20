// #include "Arduino.h"
#include "Sensores.h"

Sensores::Sensores(int Sens8, int Sens4, int Sens2,int Sens1)
{
   pinMode(Sens8, INPUT);
   pinMode(Sens4, INPUT);
   pinMode(Sens2, INPUT);
   pinMode(Sens1, INPUT);
   
  _Sens8 = Sens8;
  _Sens4 = Sens4;
  _Sens2 = Sens2;
  _Sens1 = Sens1;
}

float Sensores::posicion(){
   
  int sens1=digitalRead(_Sens1);
  int sens2=1-digitalRead(_Sens2);
  int sens4=1-digitalRead(_Sens4);
  int sens8=digitalRead(_Sens8);
  float n=0;
  if(sens1>0){
    n++;
    }
  if(sens2>0){
    n++;
    }
  if(sens4>0){
    n++;
    }
  if(sens8>0){
    n++;
    }
    int nCombinacion= sens1*1+sens2*2+sens4*4 +sens8*8;
  
    float posObstacle=0;
  
/*  
  if(nCombinacion==0){
      posObstacle=10;//no hay nada
    }
  else if(nCombinacion==5){
      posObstacle=-0.1;
    }
  else if(nCombinacion==9){
      posObstacle=2;//ambiguedad
        
    }
  else if(nCombinacion==10){
        posObstacle=0.1;
    }
  else if(nCombinacion==11){
        posObstacle=1.5;
    }
  else if(nCombinacion==13){
        posObstacle=-1.5;
    }
  else{
    posObstacle=(sens1*2 + sens2*1 + sens4*(-1) +sens8*(-2))/n;
    }
*/
switch (nCombinacion) {
  case 0:
   posObstacle=10;
    break;
case 1: 
    posObstacle=2;
    break;
case 3: case 11:
    posObstacle=1.5;
    break;   
case 2: case 10: 
    posObstacle=0.1;
    break;   
case 6: case 7: case 14: case 15:
    posObstacle=0;
    break;   
case 4: case 5:
    posObstacle=-0.1;
    break;   
case 12: case 13:
    posObstacle=-1.5;
    break;   
case 8: case 9:
    posObstacle=-2;
    break;   
}



  return posObstacle;
  }
