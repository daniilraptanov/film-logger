#include "./FilmSettings.h"
#include "Arduino.h"

FilmSettings::FilmSettings() {};

int FilmSettings::mapISO(int analogValue) {
  int index = map(analogValue, 0, 1020, 0, ISO_Count - 1);
  return ISO[index];
}

float FilmSettings::mapAperture(int analogValue) {
  int index = map(analogValue, 0, 1020, 0, APERTURE_Count - 1);
  return APERTURE[index];
}

int FilmSettings::mapShutter(int analogValue) {
  int index = map(analogValue, 0, 1020, 0, SHUTTER_Count - 1);
  return SHUTTER[index];
}

