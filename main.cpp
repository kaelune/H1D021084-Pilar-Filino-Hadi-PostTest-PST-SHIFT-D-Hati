#include <Arduino.c>
#include <Servo.h>

Servo servo; //Inisialisasi awal servo sebagai servo
int LEDmerah = D2; //Inisialisasi LED merah yang pinnya ditancaapkan ke pin digital D2
int LEDhijau = D3; //Inisialisasi LED hijau yang pinnya ditancaapkan ke pin digital D3

void setup() {
    pinMode(LEDmerah, OUTPUT); //Inisialisasi LED merah dan hijau sebagai output
    pinMode(LEDhijau, OUTPUT);
    servo.attach(D1); //Servo yang ditancapkan pada pin D1
    Serial.begin(9600);
}

void loop() {
    for(int pos = 0; pos <= 180; pos += 10) {
        servo.write(pos);
        digitalWrite(LEDmerah, LOW);
        digitalWrite(LEDhijau, HIGH);
        delay(10);
    }
    for(int pos = 180; pos >= 0; pos -= 10) {
        servo.write(pos);
        digitalWrite(LEDmerah, HIGH);
        digitalWrite(LEDhijau, LOW);
        delay(10);
    }
}