#include "title.h"

std::string Title::optionStrings[NUM_OPTIONS];

int Title::optionTextX[NUM_OPTIONS];
int Title::optionTextY[NUM_OPTIONS];

float Title::optionMarkerLeftX, Title::optionMarkerRightX;

int Title::targetedOption;


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
