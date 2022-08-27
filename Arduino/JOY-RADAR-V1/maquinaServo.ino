void servoMachine() {





  //myservo.write(anguloServo);
  valorADC = (analogRead(A0));
  porcentaje = map(valorADC, 8, 830, 100, -100);

  int escritura = map(anguloServo, 0, 180, 750, 2250);
  myservo.write(escritura);

  int valorNeopixel = map(anguloServo, 0, 180, 63, 55);
  Serial.println(valorNeopixel);
  
 




  switch (maquinaServo) {



    case PARADO:

      if (porcentaje < -UMBRAL) {
        Serial.println("Izquierda");
        msEncendidoIzquierda = anguloServo;
        maquinaServo = IZQUIERDA;
      }


      if (porcentaje > UMBRAL) {
        Serial.println("Derecha");
        msEncendidoDerecha = anguloServo;
        maquinaServo = DERECHA;

      }

      if (anguloServo >= 180) {
        anguloServo -= 5;
      }

      if (anguloServo <= 0) {
        anguloServo += 5;
      }



      break;



    case IZQUIERDA:

      if (porcentaje > UMBRAL) {
        Serial.println("Derecha");
      } else {
        Serial.println("Parado");
        maquinaServo = PARADO;
      }

      anguloServo = msEncendidoIzquierda;

      if (anguloServo >= 180) {
        maquinaServo = PARADO;
      }
      //Serial.println(anguloServo);


      break;

    case DERECHA:

      if (porcentaje < -UMBRAL) {
        Serial.println("Izquierda");
        maquinaServo = IZQUIERDA;
      } else {
        Serial.println("Parado");
        maquinaServo = PARADO;
      }



      anguloServo = msEncendidoDerecha;

      if (anguloServo <= 0) {
        maquinaServo = PARADO;
      }
      //Serial.println(anguloServo);



      break;

  }
}
