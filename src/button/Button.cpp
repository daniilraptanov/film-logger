#include "Button.h"

Button::Button(uint8_t pin, unsigned long debounceDelay) {
    this->pin = pin;
    this->debounceDelay = debounceDelay;
    this->state = HIGH;
    this->lastDebounceDelay = 0;
}

void Button::begin() {
    pinMode(pin, INPUT_PULLUP);
}

bool Button::isPressed() {
    return digitalRead(pin) == LOW;
}

bool Button::wasPressed() {
  bool currentState = digitalRead(pin);
  if (currentState == LOW && state == HIGH && (millis() - lastDebounceDelay) > debounceDelay) {
    state = true;
    lastDebounceDelay = millis();
    return true;
  }
  state = currentState;
  return false;
}

bool Button::wasReleased() {
  bool currentState = digitalRead(pin);
  if (currentState == HIGH && state == LOW && (millis() - lastDebounceDelay) > debounceDelay) {
    state = true;
    lastDebounceDelay = millis();
    return true;
  }
  state = currentState;
  return false;
}
