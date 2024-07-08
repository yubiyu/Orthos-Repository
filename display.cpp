#include "display.h"

ALLEGRO_DISPLAY* Display::display;

void Display::Initialize()
{
    display = al_create_display(Display::WIDTH, Display::HEIGHT);
}

void Display::Uninitialize()
{
    al_destroy_display(display);
}
