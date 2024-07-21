#include "palette.h"

//ALLEGRO_COLOR Palette::COL_NYX8[8];
//ALLEGRO_COLOR Palette::COL_OIL6[6];

ALLEGRO_COLOR Palette::COL_ORTHOS_BLUE[4];
ALLEGRO_COLOR Palette::COL_ORTHOS_ORANGE[4];
ALLEGRO_COLOR Palette::COL_ORTHOS_BLACK;
ALLEGRO_COLOR Palette::COL_ORTHOS_WHITE;

//ALLEGRO_COLOR Palette::COL_NYX8[8];
//ALLEGRO_COLOR Palette::COL_OIL6[6];

ALLEGRO_COLOR Palette::currentClearColour;
ALLEGRO_COLOR Palette::transparentColour;

void Palette::InitializeOrthos()
{
    COL_ORTHOS_BLUE[0] = al_map_rgb( 128, 222, 234); // Lightest blue
    COL_ORTHOS_BLUE[1] = al_map_rgb(  78, 208, 225); // Light blue
    COL_ORTHOS_BLUE[2] = al_map_rgb(   0, 131, 143); // Dark blue
    COL_ORTHOS_BLUE[3] = al_map_rgb(   0,  96, 100); // Darkest blue

    COL_ORTHOS_ORANGE[0] = al_map_rgb( 255, 224, 130); // Lighest orange
    COL_ORTHOS_ORANGE[1] = al_map_rgb( 255, 183,  77); // Light orange
    COL_ORTHOS_ORANGE[2] = al_map_rgb( 255, 143,   0); // Dark orange
    COL_ORTHOS_ORANGE[3] = al_map_rgb( 255, 111,   0); // Darkest orange
    COL_ORTHOS_BLACK = al_map_rgb( 33,  33,  33);
    COL_ORTHOS_WHITE = al_map_rgb(238, 238, 238);


    currentClearColour = COLKEY_BACKGROUND;
    transparentColour = al_map_rgba(0,0,0,0);

}

/*
void Palette::InitializeNyx()
{
    COL_NYX8[0] =  al_map_rgb(  8,  20,  30);
    COL_NYX8[1] =  al_map_rgb( 15,  42,  63);
    COL_NYX8[2] =  al_map_rgb( 32,  57,  79);
    COL_NYX8[3] =  al_map_rgb(246, 214, 189);
    COL_NYX8[4] =  al_map_rgb(195, 163, 138);
    COL_NYX8[5] =  al_map_rgb(153, 117, 119);
    COL_NYX8[6] =  al_map_rgb(129,  98, 113);
    COL_NYX8[7] =  al_map_rgb( 78,  73,  95);
}
*/

/*
void Palette::InitializeOil6()
{
    COL_OIL6[0] = al_map_rgb(251, 241, 239); // Bright Space
    COL_OIL6[1] = al_map_rgb(242, 211, 171); // Bright Light
    COL_OIL6[2] = al_map_rgb(198, 159, 165); // Bright Shadow
    COL_OIL6[3] = al_map_rgb(139, 109, 156); // Dark Light
    COL_OIL6[4] = al_map_rgb( 73,  77, 126); // Dark Shadow
    COL_OIL6[5] = al_map_rgb( 39,  39,  68); // Dark Space
}

*/
