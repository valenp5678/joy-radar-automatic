void servoMachine() {





  //myservo.write(anguloServo);
  valorADC = (analogRead(A0));
  porcentaje = map(valorADC, 8, 830, 100, -100);

  int escritura = map(anguloServo, 0, 180, 750, 2250);
  myservo.write(escritura);

  int valorNeopixel = map(anguloServo, 0, 180, 63, 55);
  //Serial.println(valorNeopixel);
  Serial.println(anguloServo);






  switch (maquinaServo) {

    


    case PARADO:

      if (porcentaje < -UMBRAL) {
        Serial.println("Izquierda");
        msEncendidoIzquierda = anguloServo;
        digitalWrite(LED_CENTRO, HIGH);
        digitalWrite(LED_IZQUIERDA, LOW);
        digitalWrite(LED_DERECHA, LOW);
        digitalWrite(LED_BLANCO_CENTRO, LOW);
        maquinaServo = IZQUIERDA;
      }


      if (porcentaje > UMBRAL) {
        Serial.println("Derecha");
        msEncendidoDerecha = anguloServo;
        maquinaServo = DERECHA;
        digitalWrite(LED_CENTRO, HIGH);
        digitalWrite(LED_IZQUIERDA, LOW);
        digitalWrite(LED_DERECHA, LOW);
        digitalWrite(LED_BLANCO_CENTRO, LOW);
      }

      digitalWrite(LED_CENTRO, HIGH);
      digitalWrite(LED_IZQUIERDA, LOW);
      digitalWrite(LED_DERECHA, LOW);
      digitalWrite(LED_BLANCO_CENTRO, LOW);

      if (anguloServo >= 180) {
        anguloServo -= 5;
      }

      if (anguloServo <= 0) {
        anguloServo += 5;
      }

      if(digitalRead(PIN_PIR) == HIGH && lado == "derecha"){
        digitalWrite(LED_CENTRO, HIGH);
        digitalWrite(LED_IZQUIERDA, LOW);
        digitalWrite(LED_DERECHA, HIGH);
        digitalWrite(LED_BLANCO_CENTRO, LOW);
      }
      if(digitalRead(PIN_PIR) == HIGH && lado == "izquierda"){
        digitalWrite(LED_CENTRO, HIGH);
        digitalWrite(LED_IZQUIERDA, HIGH);
        digitalWrite(LED_DERECHA, LOW);
        digitalWrite(LED_BLANCO_CENTRO, LOW);
      }

      if (digitalRead(BUTTON_JOY) == LOW) {
        Serial.println("Automatic");
        anguloServo = 0;
        msEncendidoIzquierda = anguloServo;
        digitalWrite(LED_CENTRO, LOW);
        digitalWrite(LED_IZQUIERDA, LOW);
        digitalWrite(LED_DERECHA, LOW);
        digitalWrite(LED_BLANCO_CENTRO, HIGH);
        maquinaServo = AUTOMATICO;
      }



      break;



    case IZQUIERDA:

      if (porcentaje > UMBRAL) {
        Serial.println("Derecha");
      } else {
        Serial.println("Parado");
        digitalWrite(LED_CENTRO, HIGH);
        digitalWrite(LED_IZQUIERDA, LOW);
        digitalWrite(LED_DERECHA, LOW);
        digitalWrite(LED_BLANCO_CENTRO, LOW);
        lado = "izquierda";
        maquinaServo = PARADO;
      }

      anguloServo = msEncendidoIzquierda;

      if (anguloServo >= 180) {
        digitalWrite(LED_CENTRO, HIGH);
        digitalWrite(LED_IZQUIERDA, LOW);
        digitalWrite(LED_DERECHA, LOW);
        digitalWrite(LED_BLANCO_CENTRO, LOW);
        maquinaServo = PARADO;
      }

      if(digitalRead(PIN_PIR) == HIGH){
        digitalWrite(LED_CENTRO, HIGH);
        digitalWrite(LED_IZQUIERDA, HIGH);
        digitalWrite(LED_DERECHA, LOW);
        digitalWrite(LED_BLANCO_CENTRO, LOW);
      }
      //Serial.println(anguloServo);

      if (digitalRead(BUTTON_JOY) == LOW) {
        Serial.println("Automatic");
        msEncendidoIzquierda = 0;
        digitalWrite(LED_CENTRO, LOW);
        digitalWrite(LED_IZQUIERDA, LOW);
        digitalWrite(LED_DERECHA, LOW);
        digitalWrite(LED_BLANCO_CENTRO, HIGH);
        maquinaServo = AUTOMATICO;
      }

      break;

    case DERECHA:

      if (porcentaje < -UMBRAL) {
        Serial.println("Izquierda");
        maquinaServo = IZQUIERDA;
      } else {
        Serial.println("Parado");
        digitalWrite(LED_CENTRO, HIGH);
        digitalWrite(LED_IZQUIERDA, LOW);
        digitalWrite(LED_DERECHA, LOW);
        digitalWrite(LED_BLANCO_CENTRO, LOW);
        lado = "derecha";
        maquinaServo = PARADO;
      }

      if(digitalRead(PIN_PIR) == HIGH){
        digitalWrite(LED_CENTRO, HIGH);
        digitalWrite(LED_IZQUIERDA, LOW);
        digitalWrite(LED_DERECHA, HIGH);
        digitalWrite(LED_BLANCO_CENTRO, LOW);
      }



      anguloServo = msEncendidoDerecha;

      if (anguloServo <= 0) {
        digitalWrite(LED_CENTRO, HIGH);
        digitalWrite(LED_IZQUIERDA, LOW);
        digitalWrite(LED_DERECHA, LOW);
        digitalWrite(LED_BLANCO_CENTRO, LOW);
        maquinaServo = PARADO;
      }
      //Serial.println(anguloServo);

      if (digitalRead(BUTTON_JOY) == LOW) {
        Serial.println("Automatic");
        msEncendidoIzquierda = 0;
        digitalWrite(LED_CENTRO, LOW);
        digitalWrite(LED_IZQUIERDA, LOW);
        digitalWrite(LED_DERECHA, LOW);
        digitalWrite(LED_BLANCO_CENTRO, HIGH);
        maquinaServo = AUTOMATICO;
      }


      break;

    case AUTOMATICO:

      //anguloServo = msEncendidoIzquierda;

      //msEncendidoIzquierda = anguloServo;

      if (msEncendidoIzquierda <= 180) {
        msEncendidoIzquierda = 0;
        maquinaServo = AUTO_IZQ;
      }

      if (digitalRead(BUTTON_STOP) == LOW) {
        digitalWrite(LED_CENTRO, HIGH);
        digitalWrite(LED_IZQUIERDA, LOW);
        digitalWrite(LED_DERECHA, LOW);
        digitalWrite(LED_BLANCO_CENTRO, LOW);
        maquinaServo = PARADO;
      }


      break;

    case AUTO_IZQ:
      anguloServo = msEncendidoIzquierda;
      if (msEncendidoIzquierda >= 180) {
        msEncendidoDerecha = anguloServo;
        maquinaServo = AUTO_DER;
      }

      if(digitalRead(PIN_PIR) == HIGH){
        digitalWrite(LED_CENTRO, LOW);
        digitalWrite(LED_IZQUIERDA, HIGH);
        digitalWrite(LED_DERECHA, LOW);
        digitalWrite(LED_BLANCO_CENTRO, HIGH);
      }

      if (digitalRead(BUTTON_STOP) == LOW) {
        digitalWrite(LED_CENTRO, HIGH);
        digitalWrite(LED_IZQUIERDA, LOW);
        digitalWrite(LED_DERECHA, LOW);
        digitalWrite(LED_BLANCO_CENTRO, LOW);
        maquinaServo = PARADO;
      }



      break;

    case AUTO_DER:
      anguloServo = msEncendidoDerecha;
      if (msEncendidoDerecha <= 0) {
        msEncendidoIzquierda = anguloServo;
        maquinaServo = AUTO_IZQ;
      }

      if(digitalRead(PIN_PIR) == HIGH){
        digitalWrite(LED_CENTRO, LOW);
        digitalWrite(LED_IZQUIERDA, LOW);
        digitalWrite(LED_DERECHA, HIGH);
        digitalWrite(LED_BLANCO_CENTRO, HIGH);
      }

      if (digitalRead(BUTTON_STOP) == LOW) {
        digitalWrite(LED_CENTRO, HIGH);
        digitalWrite(LED_IZQUIERDA, LOW);
        digitalWrite(LED_DERECHA, LOW);
        digitalWrite(LED_BLANCO_CENTRO, LOW);
        maquinaServo = PARADO;
      }

      break;


  }
}
