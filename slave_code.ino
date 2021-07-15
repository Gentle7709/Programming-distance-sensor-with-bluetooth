#include <Servo.h>

#define LedPin 2  //أستبدلت الفيديو ب :LED

Servo servo;  // أستبدلت الأذرع الكاملة ب سيرفو واحد فقط حاليأ

void setup()
{
Serial.begin(38400);
  pinMode(LedPin, OUTPUT);
  servo.attach(3);

}

void loop()
{
  if(Serial.available() > 0){
  if(Serial.read() == '1')
    digitalWrite(LedPin, HIGH);
    servo.write(90);
    delay(10);
  }
    else {
    digitalWrite(LedPin, LOW);
        servo.write(0);
    }
  
  
}
