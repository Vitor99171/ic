#include <Servo.h>

Servo servo_3;
Servo servo_6;
Servo servo_9;

void setup() {
  Serial.begin(9600); // Inicia a comunicação serial
  pinMode(12, OUTPUT);
  servo_3.attach(3);
  servo_6.attach(6);
  servo_9.attach(9);
}

void loop() {
  if (Serial.available() > 0) {
    char gesture = Serial.read();
    switch (gesture) {
      case 'R':
        Serial.println("O sistema escolheu Pedra.");
        tone(12,131);
        delay(100);
        noTone(12);
        servo_3.write(179);
        delay(1000);
        servo_3.write(90);
        delay(500);
        break;
      case 'P':
        Serial.println("O sistema escolheu Papel.");
        tone(12,131);
        delay(100);
        noTone(12);
        servo_6.write(179);
        delay(1000);
        servo_6.write(90);
        delay(500);
        break;
      case 'T':
        Serial.println("O sistema escolheu Tesoura.");
        tone(12,131);
        delay(100);
        noTone(12);
        servo_9.write(179);
        delay(1000);
        servo_9.write(90);
        delay(500);
        break;
    }
  }
}
