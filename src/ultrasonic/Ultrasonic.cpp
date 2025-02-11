#include <./ultrasonic/Ultrasonic.h>

Ultrasonic::Ultrasonic(int trigPin, int echoPin) {
    this->trigPin = trigPin;
    this->echoPin = echoPin;
}

void Ultrasonic::begin() {
    pinMode(this->echoPin, INPUT);
    pinMode(this->trigPin, OUTPUT);
    digitalWrite(this->trigPin, LOW);
}

long Ultrasonic::getDistanceCM() {
    long duration, cm, tmp1;
    tmp1 = micros();

    digitalWrite(trigPin, HIGH);

    delayMicroseconds(10);

    digitalWrite(trigPin, LOW);

    delayMicroseconds(500);

    while(digitalRead(echoPin) == HIGH) {
        if(micros() - tmp1 > 15000) break;
    } 

    duration=micros() - tmp1;

    cm = duration / 58;

    if(duration > 15000)
        return 150;
    else return cm;
}
