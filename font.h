#ifndef FONT_H_INCLUDED
#define FONT_H_INCLUDED

#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

struct Font
{
    static ALLEGRO_FONT *builtin8;
    static ALLEGRO_FONT *monogram32;

    static void Initialize();
    static void Uninitialize();

    static void LoadResources();
    static void UnloadResources();
};

#endif // FONT_H_INCLUDED
