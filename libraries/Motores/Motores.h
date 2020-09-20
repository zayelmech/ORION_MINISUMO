#ifndef Motores_h
#define Motores_h

#ifdef ARDUINO
    #if ARDUINO < 100
        #include "WProgram.h"
    #else
        #include "Arduino.h"
    #endif
#endif

class Motores
{
  public:
    Motores(int IN1A, int IN2A, int PWMA,int IN1B, int IN2B, int PWMB);
    void izq(int poderA);
    void der(int poderB);
  private:
    int _IN1A,_IN2A,_PWMA,_IN1B,_IN2B,_PWMB;
};

#endif
