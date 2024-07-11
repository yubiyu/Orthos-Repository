#ifndef SETTINGS_H_INCLUDED
#define SETTINGS_H_INCLUDED

#include "display.h"
#include "keyboard.h"

#include "image.h"
#include "font.h"
#include "audio.h"

#include "scene.h"

#include "palette.h"
#include "hax.h"

#include <string>
#include <iostream>

struct Settings
{
    enum enumOptions
    {
        OPTION_GLOBAL_MUTE = 0,
        OPTION_BGM_LEVEL = 1,
        OPTION_SFX_LEVEL = 2,
        OPTION_RETURN_TO_TITLE = 3
    };
    static const int NUM_OPTIONS = 4;
    static const int FIRST_OPTION = OPTION_GLOBAL_MUTE;
    static const int LAST_OPTION = OPTION_RETURN_TO_TITLE;

    static std::string optionStrings[NUM_OPTIONS];

    static int optionTextX[NUM_OPTIONS];
    static const int OPTION_TEXT_X_BASE = Display::WIDTH * 0.33;

    static int optionTextY[NUM_OPTIONS];
    static const int OPTION_TEXT_Y_BASE = Display::HEIGHT/2;
    static const int OPTION_TEXT_Y_SPACING = 64;

    static float optionMarkerLeftX, optionMarkerRightX;
    static constexpr float OPTION_MARKER_SPRITE_WIDTH = 32;
    static constexpr float OPTION_MARKER_SPRITE_X_SPACING = 8;

    static int targetedOption;

    static int bgmBars;
    static int sfxBars;
    static const int MAX_VOLUME_BARS = 10;
    static constexpr float VOLUME_BARS_X = OPTION_TEXT_X_BASE + 128;
    static constexpr float VOLUME_BAR_WIDTH = 32;
    static float bgmBarsTotalWidth;
    static float sfxBarsTotalWidth;
    static constexpr float VOLUME_BAR_HEIGHT = 32;

    static void Initialize();

    static void Logic();
    static void Input();
    static void Drawing();

    static void RecalculateOptionMarkerX();

    static void AdjustTargetedOptionUp();
    static void AdjustTargetedOptionDown();
    static void SetTargetedOption(int whichOption);

    static void SetBgmBars(int bars);
    static void SetSfxBars(int bars);
};

#endif // SETTINGS_H_INCLUDED
