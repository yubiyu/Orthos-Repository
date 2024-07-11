#include "archive.h"

std::string Archive::returnToTitleString;

void Archive::Logic()
{

}

void Archive::Input()
{
    if(Keyboard::keyHoldTicks[Keyboard::KEY_ESC] == 1 || Keyboard::keyHoldTicks[Keyboard::KEY_ENTER] == 1)
    {
        Scene::ChangeScene(Scene::SCENE_TITLE);
    }
}

void Archive::Drawing()
{
    {
        Hax::string_al_draw_text(Font::monogram32, COLKEY_TEXT_LIGHT,
                                 Archive::RETURN_TO_TITLE_TEXT_X, Archive::RETURN_TO_TITLE_TEXT_Y,
                                 ALLEGRO_ALIGN_CENTER, Archive::returnToTitleString);
    }
}
