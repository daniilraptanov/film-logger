#include <./ultrasonic/Ultrasonic.h>

Ultrasonic::Ultrasonic(int trigPin, int echoPin, int measurementsCount) {
    this->trigPin = trigPin;
    this->echoPin = echoPin;
    this->measurementsCount = measurementsCount;
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

long Ultrasonic::getFilteredDistanceCM() {
    long result = 0;
    for (int i = 0; i < measurementsCount; i++) {
        result += getDistanceCM();
        delay(10);
    }
    return result / measurementsCount;
}
