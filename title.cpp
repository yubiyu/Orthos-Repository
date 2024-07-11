#include "title.h"

std::string Title::optionStrings[NUM_OPTIONS];

int Title::optionTextX[NUM_OPTIONS];
int Title::optionTextY[NUM_OPTIONS];

float Title::optionMarkerLeftX, Title::optionMarkerRightX;

int Title::targetedOption;
bool Title::exitOptionSelected;


void Title::Initialize()
{
    optionStrings[OPTION_NEW_GAME] = "New Game";
    optionStrings[OPTION_LOAD_GAME] = "Load Game";
    optionStrings[OPTION_ARCHIVE] = "Archive";
    optionStrings[OPTION_SETTINGS] = "Settings";
    optionStrings[OPTION_EXIT] = "Exit";

    for(int i = 0; i < NUM_OPTIONS; i++)
    {
        optionTextX[i] = Display::WIDTH/2;
        optionTextY[i] = Display::HEIGHT/2 + i*OPTION_TEXT_Y_SPACING;
    }

    SetTargetedOption(OPTION_NEW_GAME);
    exitOptionSelected = false;
}

void Title::Logic()
{

}

void Title::Input()
{
    if(Keyboard::keyHoldTicks[Keyboard::KEY_UP] == 1)
    {
        Title::AdjustTargetedOptionUp();
    }
    else if(Keyboard::keyHoldTicks[Keyboard::KEY_DOWN] == 1)
    {
        Title::AdjustTargetedOptionDown();
    }

    if(Keyboard::keyHoldTicks[Keyboard::KEY_ESC] == 1)
    {
        Title::SetTargetedOption(Title::OPTION_EXIT);
    }
    else if(Keyboard::keyHoldTicks[Keyboard::KEY_ENTER] == 1)
    {
        switch(Title::targetedOption)
        {
        case Title::OPTION_NEW_GAME:
            Scene::ChangeScene(Scene::SCENE_STAGE);
            break;
        case Title::OPTION_LOAD_GAME:
            Scene::ChangeScene(Scene::SCENE_STAGE);
            break;
        case Title::OPTION_ARCHIVE:
            Scene::ChangeScene(Scene::SCENE_ARCHIVE);
            break;
        case Title::OPTION_SETTINGS:
            Scene::ChangeScene(Scene::SCENE_SETTINGS);
            break;
        case Title::OPTION_EXIT:
            exitOptionSelected = true;
            break;
        }
    }
}

void Title::Drawing()
{
    al_draw_bitmap(Image::titleOptionMarkerPng,
                   Title::optionTextX[Title::targetedOption] - Title::optionMarkerLeftX,
                   Title::optionTextY[Title::targetedOption],
                   0);

    al_draw_bitmap(Image::titleOptionMarkerPng,
                   Title::optionTextX[Title::targetedOption] + Title::optionMarkerRightX,
                   Title::optionTextY[Title::targetedOption],
                   0);

    for(int i = 0; i < Title::NUM_OPTIONS; i++)
    {
        Hax::string_al_draw_text(Font::monogram32, COLKEY_TEXT_LIGHT,
                                 Title::optionTextX[i], Title::optionTextY[i],
                                 ALLEGRO_ALIGN_CENTRE, Title::optionStrings[i]);
    }
}

void Title::RecalculateOptionMarkerX()
{
    optionMarkerLeftX = Hax::string_al_get_text_width(Font::monogram32, optionStrings[targetedOption])/2 + OPTION_MARKER_SPRITE_WIDTH + OPTION_MARKER_SPRITE_X_SPACING;
    optionMarkerRightX = Hax::string_al_get_text_width(Font::monogram32, optionStrings[targetedOption])/2 + OPTION_MARKER_SPRITE_X_SPACING;
}

void Title::AdjustTargetedOptionUp()
{
    if(targetedOption > FIRST_OPTION)
    {
        targetedOption --;
        RecalculateOptionMarkerX();
    }
}

void Title::AdjustTargetedOptionDown()
{
    if(targetedOption < LAST_OPTION)
    {
        targetedOption ++;
        RecalculateOptionMarkerX();
    }
}

void Title::SetTargetedOption(int whichOption)
{
    targetedOption = whichOption;
    RecalculateOptionMarkerX();
}
