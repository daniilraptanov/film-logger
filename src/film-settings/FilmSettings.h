#ifndef FILM_SETTINGS_H
#define FILM_SETTINGS_H

class FilmSettings {
    private:
        int ISO[16] = {0, 15, 50, 100, 200, 250, 400, 500, 600, 800, 1000, 1200, 1600, 1800, 3200, 6400};
        int ISO_Count = sizeof(ISO) / sizeof(ISO[0]);

        float APERTURE[12] = {0, 1.4, 2, 2.8, 3.5, 4, 5.6, 8, 11, 16, 22, 64};
        int APERTURE_Count = sizeof(APERTURE) / sizeof(APERTURE[0]);

        int SHUTTER[12] = {0, 1000, 500, 250, 125, 60, 30, 15, 8, 4, 2, 1};
        int SHUTTER_Count = sizeof(SHUTTER) / sizeof(SHUTTER[0]);


    public:
        FilmSettings();

        int mapISO(int analogValue);   
        float mapAperture(int analogValue);
        int mapShutter(int analogValue);
};

#endif
