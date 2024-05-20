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
    for(int pos = 0; pos <= 180; pos += 10) { //Looping untuk servo yang akan bergerak setiap 10 posisi membuka setiap pergerakan
        servo.write(pos);  //Lokasi servo ssesuai dengan posisinya
        digitalWrite(LEDmerah, LOW); //Ketika servo bergerak membuka, LED merah redup
        digitalWrite(LEDhijau, HIGH); // Ketika servo bergerak membuka, LED hijau menyala abangkuh
    }
    for(int pos = 180; pos >= 0; pos -= 10) {  //Looping untuk servo yang akan menutup setiap 10 posisi membuka setiap pergerakan
        servo.write(pos);    //Lokasi servo sesuai dengan posisinya
        digitalWrite(LEDmerah, HIGH); //Ketika servo bergerak menutup, LED merah menyala abangkuh
        digitalWrite(LEDhijau, LOW); //Ketika servo bergerak menutup, LED hijau redup, tetap ilmu padi
    }
}
