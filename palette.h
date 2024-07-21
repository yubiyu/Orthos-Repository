#ifndef PALETTE_H_INCLUDED
#define PALETTE_H_INCLUDED

#include <allegro5/allegro5.h>

#define COLKEY_TEXT_LIGHT                 Palette::COL_ORTHOS_WHITE

#define COLKEY_BACKGROUND                 Palette::COL_ORTHOS_BLACK
#define COLKEY_GRID                       Palette::COL_ORTHOS_ORANGE[1]
#define COLKEY_CAMERA_CROSSHAIR_LOCKED    Palette::COL_ORTHOS_ORANGE[0]

struct Palette
{
    static ALLEGRO_COLOR COL_ORTHOS_BLUE[4];
    static ALLEGRO_COLOR COL_ORTHOS_ORANGE[4];
    static ALLEGRO_COLOR COL_ORTHOS_BLACK;
    static ALLEGRO_COLOR COL_ORTHOS_WHITE;

    //static ALLEGRO_COLOR COL_NYX8[8]; // Uses Javier Guerrero's palette "Nyx 8" --- https://lospec.com/palette-list/nyx8
    //static ALLEGRO_COLOR COL_OIL6[6]; // Uses GrafxKid's palette "Oil 6" --- https://lospec.com/palette-list/oil-6

    static ALLEGRO_COLOR currentClearColour;
    static ALLEGRO_COLOR transparentColour;

    static void InitializeOrthos();
    //static void InitializeNyx();
    //static void InitializeOil6();
};

#endif // PALETTE_H_INCLUDED
