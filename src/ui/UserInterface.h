#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H

enum FL_Parameter {
    FL_NONE = 0,
    FL_ISO = 1,
    FL_APERTURE = 2,
    FL_SHUTTER = 3,
    FL_FILM = 4,
};

class UserInterface {
    private:
        int ISO_VALUES[16] = {0, 15, 50, 100, 200, 250, 400, 500, 600, 800, 1000, 1200, 1600, 1800, 3200, 6400};
        float APERTURE_VALUES[12] = {0, 1.4, 2, 2.8, 3.5, 4, 5.6, 8, 11, 16, 22, 64};
        int SHUTTER_VALUES[12] = {0, 1000, 500, 250, 125, 60, 30, 15, 8, 4, 2, 1};
        
        int ISO_SIZEOF = 16;
        int APERTURE_SIZEOF = 12;
        int SHUTTER_SIZEOF = 12;

        FL_Parameter marked;
        FL_Parameter selected;

        int isoIndex;
        int apertureIndex;
        int shutterIndex;
        int filmIndex;

        int getNextIndex(int index, int maxIndex, bool buttonUp, bool buttonDown);

    public:
        UserInterface();

        void handleUI(bool buttonUp, bool buttonDown, bool buttonAccept);
        
        FL_Parameter getMarked();
        FL_Parameter getSelected();
        int getISO();
        float getAperture();
        int getShutter();
};

#endif
