#include <TimerOne.h>
#include <ServoTimer2.h>

ServoTimer2 myservo;  // create servo object to control a servo

#define PIN_PIR      13
#define BUTTON_JOY   A2
#define BUTTON_STOP  A4

// A0 == Y AXIS
// A1 == X AXIS
#define PARADO       0
#define IZQUIERDA    1
#define DERECHA      2

#define AUTOMATICO   3
#define AUTO_DER     4
#define AUTO_IZQ     5

#define UMBRAL    50
 
#define LED_IZQUIERDA          2
#define LED_CENTRO             3

#define LED_DERECHA            5
#define LED_BLANCO_CENTRO      6

int maquinaServo = PARADO;
int maquinaAutomatico = AUTOMATICO;

float msEncendidoIzquierda, msEncendidoDerecha;

int anguloServo = 90;
int valorADC, porcentaje;

String lado;






void setup() {
  myservo.attach(A5);  // attaches the servo on pin 9 to the servo object
  Serial.begin(115200);



  Timer1.initialize(10005);
  Timer1.attachInterrupt(timerEncendido);

  pinMode(BUTTON_JOY, INPUT_PULLUP);
  pinMode(BUTTON_STOP, INPUT_PULLUP);

  for(int i = 2; i < 7; i++){
    pinMode(i, OUTPUT);
  }







}

void loop() {

  servoMachine();
  //Serial.println(digitalRead(A4));
  //valorADC = (analogRead(A0));
  //porcentaje = map(valorADC, 0, 1023, 100, -100);
  //Serial.println(valorADC);
  //Serial.println(porcentaje);
  //Serial.println(digitalRead(PIR_PIN));


  
 


}
//<>

void timerEncendido() {

  msEncendidoIzquierda = msEncendidoIzquierda + 1;
  msEncendidoDerecha = msEncendidoDerecha - 1ddd;

}
