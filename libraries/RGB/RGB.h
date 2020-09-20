#ifndef RGB_h
#define RGB_h

#ifdef ARDUINO
    #if ARDUINO < 100
        #include "WProgram.h"
    #else
        #include "Arduino.h"
    #endif
#endif

class RGB
{
  public:
    RGB(int pinR, int pinG, int pinB);
    /*void color(String colorName);*/
    void valores(int valueR, int valueG, int valueB);
  private:
    int _pinR,_pinG,_pinB;
};

#endif

