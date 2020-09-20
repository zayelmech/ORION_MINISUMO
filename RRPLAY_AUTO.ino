#include <Sensores.h>
#include <RGB.h>
#include <Motores.h>

#define pinRed 9     //pwm
#define pinGreen 10  //pwm
#define pinBlue 12

#define sensIzq A1 //MSB
#define sensDer A0 //LSB
#define sensFrontIzq A4
#define sensFrontDer A2
#define boton 2

Sensores vision(A1,A3,A2,A0);
RGB rgb(pinRed,pinGreen,pinBlue);
Motores motor(3,4,5,8,7,6);


volatile unsigned int lineIzq=400;
volatile unsigned int lineDer=400;

volatile unsigned long tiempoAnterior=0; // variable para mantener el tiempo de muestreo
volatile float dT; 
unsigned long tiempoActual;


float errorAnterior=0;
float error=0;
float errorDer=0;

float kp=5;
float kd=0.08;
float ki=5.0;
float PD=0;

boolean bandera=false;

int vm = 0;//55 


int alturaAnt[10]={0,0,0,0,0,0,0,0,0,0};

int alturaT=0;
unsigned int index=0;
  

void setup() {
  
SREG = (SREG & 0b01111111); //Esta instrucción deshabilita a las interrupciones globales sin modificar el resto de las interrupciones.
TCNT2 = 0;     //Limpiar el registro que guarda la cuenta del Timer-2.
TIMSK2 =TIMSK2|0b00000001;      //Habilitación de la bandera 0 del registro que habilita la interrupción por sobre flujo o desbordamiento del TIMER2.
TCCR2B = 0b00000011; //Configura preescala para que FT2 sea de 250kHz
SREG = (SREG & 0b01111111) | 0b10000000; //Habilitar interrupciones //Desabilitar interrupciones
pinMode(boton,INPUT_PULLUP);

}

void loop() {

while(bandera==false){

if(digitalRead(boton)==LOW){
  digitalWrite(9,HIGH);
  bandera=true;
  delay(2000);
/*if(analogRead(pot)>500)
     lineFun(false);*/
  }
}//end while true
  
  if(lineIzq<300 && lineDer<300 ){
  //1 1
    motor.der(-250);
    motor.izq(-150);
    delay(200);
    motor.der(0);
    motor.izq(0);
   // delay(500);

}
  else if(lineIzq<300 && lineDer>300 ){
  //1 0
  
    motor.der(-250);
    motor.izq(-150);
    delay(200);
    motor.izq(150);
    motor.der(-250);
    delay(100);
    motor.der(0);
    motor.izq(0);
    //delay(1000);
  }
  else if(lineIzq>300 && lineDer<300 ){
  //0 1
   motor.der(-250);
    motor.izq(-150);
    delay(200);
    motor.izq(-150);
    motor.der(250);
    delay(100);
    motor.der(0);
    motor.izq(0);
   // delay(1000);
  }
  else {
    
    
tiempoActual = millis();
dT=(double)(tiempoActual - tiempoAnterior) ; //Tiempo de muestreo en milisegundos

if(dT>=2){ //cada 2mS (tiempo de muestreo)
 
float errorActual= vision.posicion();
float errorReal=errorActual;

if(errorActual==10){
  if(errorAnterior>=2 && errorAnterior<4){
    errorActual=2.5;
    }
  else if(errorAnterior>=1.5 && errorAnterior<2){
    errorActual=1.75;
    }
  else if(errorAnterior>0 && errorAnterior<1){
    errorActual=0.8;
    }  
  else if(errorAnterior<0 && errorAnterior>-1){
    errorActual=-0.8;
    }  
  else if(errorAnterior<-1.5 && errorAnterior>-2){
    errorActual=-1.75;
    }
  else if(errorAnterior<=-2 && errorAnterior>-4){
    errorActual=-2.5;
    }    
  else{
    //buscar();
    errorActual=0;
  }
}
else if(errorActual==9){
  errorActual=0;
      //BusquedaRapida();
}
  
  error=errorActual;
  errorDer=((errorActual-errorAnterior)*1000)/dT;
  
  alturaT +=errorActual;
  int alturaReal=alturaT - alturaAnt[index];
  alturaAnt[index]=alturaT;
  index++;
  
  if(index>9){
    index=0;
  }
  float errorInt=(alturaReal);//*dT/1000
  
  PD=error*kp+ errorDer*kd +errorInt*ki;

 if(PD>255 )
  PD=255;//50
 if(PD<-255 )
  PD=-255;//50
 if(PD>0&&PD<40 )
  PD=40;//50
 if(PD<0&&PD>-40 )
  PD=-40;//50
  
if(errorInt==0 && errorReal==0){
  motor.der(0);
  motor.izq(0);
  }
else if(abs(errorReal)>=1.5 && abs(alturaReal)>=15 ){
  motor.der(-PD);
  motor.izq(PD);
  }
  
else{
  motor.der(vm - PD);
  motor.izq(vm + PD);
  }
  if(errorActual==0)
    rgb.valores(0,255,0);
  else if(errorActual>0 && errorActual!=10 && errorActual!=9)
    rgb.valores(0,0,255);
  else if(errorActual<0)
    rgb.valores(255,0,0);
  else if(errorActual==9)  
    rgb.valores(255,0,255);
  else   
    rgb.valores(255,255,255);

  errorAnterior=errorActual;
  tiempoAnterior=tiempoActual;
 }  
 
 }
}
ISR(TIMER2_OVF_vect){
 lineIzq=analogRead(A5);
 lineDer=analogRead(A4);

}
