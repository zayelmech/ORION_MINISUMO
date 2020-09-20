#ifndef Sensores_h
#define Sensores_h

#ifdef ARDUINO
    #if ARDUINO < 100
        #include "WProgram.h"
    #else
        #include "Arduino.h"
    #endif
#endif

class Sensores
{
  public:
    Sensores(int Sens8, int Sens4, int Sens2,int Sens1);
    float posicion();
  private:
    int _Sens1,_Sens2,_Sens4,_Sens8;
};

#endif
