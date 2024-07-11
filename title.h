#ifndef TITLE_H_INCLUDED
#define TITLE_H_INCLUDED

#include "keyboard.h"
#include "display.h"

#include "image.h"
#include "font.h"

#include "scene.h"

#include "palette.h"
#include "hax.h"

#include <string>

struct Title
{
    enum enumOptions
    {
        OPTION_NEW_GAME = 0,
        OPTION_LOAD_GAME = 1,
        OPTION_ARCHIVE = 2,
        OPTION_SETTINGS = 3,
        OPTION_EXIT = 4
    };
    static const int NUM_OPTIONS = 5;
    static const int FIRST_OPTION = OPTION_NEW_GAME;
    static const int LAST_OPTION = OPTION_EXIT;

    static std::string optionStrings[NUM_OPTIONS];

    static int optionTextX[NUM_OPTIONS];
    static const int OPTION_TEXT_X_BASE = Display::WIDTH/2;

    static int optionTextY[NUM_OPTIONS];
    static const int OPTION_TEXT_Y_SPACING = 64;

    static float optionMarkerLeftX, optionMarkerRightX;
    static constexpr float OPTION_MARKER_SPRITE_WIDTH = 32;
    static constexpr float OPTION_MARKER_SPRITE_X_SPACING = 8;

    static int targetedOption;
    static bool exitOptionSelected;

    static void Initialize();

    static void Logic();
    static void Input();
    static void Drawing();

    static void RecalculateOptionMarkerX();

    static void AdjustTargetedOptionUp();
    static void AdjustTargetedOptionDown();
    static void SetTargetedOption(int whichOption);
};

#endif // TITLE_H_INCLUDED
