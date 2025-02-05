#include "./UserInterface.h"

UserInterface::UserInterface() {
    marked = FL_ISO;
    selected = FL_NONE;
    isoIndex = 3;
    apertureIndex = 3;
    shutterIndex = 3;
};

int UserInterface::getNextIndex(int index, int maxIndex, bool buttonUp, bool buttonDown) {
    if (buttonUp) {
        if (index == maxIndex) {
            return 0;
        } else {
            return index + 1;
        }
        return index;
    }
    if (buttonDown) {
        if (index == 0) {
            return maxIndex; 
        } else {
            return index - 1;
        }
        return index;
    }
}

void UserInterface::handleUI(bool buttonUp, bool buttonDown, bool buttonAccept) {
    switch (selected) {
    case FL_NONE:
        if (buttonUp) {
            marked = 
                marked == FL_ISO ? FL_APERTURE : 
                marked == FL_APERTURE ? FL_SHUTTER : 
                marked == FL_SHUTTER ? FL_FILM : 
                marked == FL_FILM ? FL_ISO : 
                FL_ISO;
            return;
        }

        if (buttonDown) {
            marked = 
                marked == FL_ISO ? FL_FILM : 
                marked == FL_FILM ? FL_SHUTTER : 
                marked == FL_SHUTTER ? FL_APERTURE : 
                marked == FL_APERTURE ? FL_ISO : 
                FL_ISO;
            return;
        }

        
        if (buttonAccept) {
            selected = marked;
            return;
        }

    case FL_ISO:
        if (buttonAccept) {
            selected = FL_NONE;
        } else {
            isoIndex = getNextIndex(isoIndex, ISO_SIZEOF, buttonUp, buttonDown);
        }
    
    case FL_APERTURE:
        if (buttonAccept) {
            selected = FL_NONE;
        } else {
            apertureIndex = getNextIndex(apertureIndex, APERTURE_SIZEOF, buttonUp, buttonDown);
        }

    case FL_SHUTTER:
        if (buttonAccept) {
            selected = FL_NONE;
        } else {
            shutterIndex = getNextIndex(shutterIndex, SHUTTER_SIZEOF, buttonUp, buttonDown);
        }

    case FL_FILM:
        // TODO
        break;

    default:
        break;
    }
}

int UserInterface::getISO() {
    return ISO_VALUES[isoIndex];
}

float UserInterface::getAperture() {
    return APERTURE_VALUES[apertureIndex];
}

int UserInterface::getShutter() {
    return SHUTTER_VALUES[shutterIndex];
}

FL_Parameter UserInterface::getMarked() {
    return marked;
}
