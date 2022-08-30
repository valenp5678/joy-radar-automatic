#include <TimerOne.h>
#include <ServoTimer2.h>
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

#define PIN        3 // On Trinket or Gemma, suggest changing this to 1

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 63 // Popular NeoPixel ring size

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 500

ServoTimer2 myservo;  // create servo object to control a servo

#define PIR_PIN    A4

// A0 == Y AXIS
// A1 == X AXIS
#define PARADO    0
#define IZQUIERDA 1
#define DERECHA   2

#define UMBRAL    15

int maquinaServo = PARADO;
float msEncendidoIzquierda, msEncendidoDerecha;

int anguloServo = 90;
int valorADC, porcentaje;






void setup() {
  myservo.attach(A5);  // attaches the servo on pin 9 to the servo object
  Serial.begin(115200);



  Timer1.initialize(10005);
  Timer1.attachInterrupt(timerEncendido);

  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)






}

void loop() {

  servoMachine();
  //Serial.println(digitalRead(A4));
  //valorADC = (analogRead(A0));
  //porcentaje = map(valorADC, 8, 830, 100, -100);
  //Serial.println(valorADC);
  //Serial.println(analogRead(A0));

  //pixels.clear();
  
  pixels.setPixelColor(50, pixels.Color(0, 2, 0));

  pixels.show();   // Send the updated pixel colors to the hardware.


}
//<>

void timerEncendido() {

  msEncendidoIzquierda = msEncendidoIzquierda + 1;
  msEncendidoDerecha = msEncendidoDerecha - 1;

}
