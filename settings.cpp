#include "settings.h"

std::string Settings::optionStrings[NUM_OPTIONS];

int Settings::optionTextX[NUM_OPTIONS];
int Settings::optionTextY[NUM_OPTIONS];

float Settings::optionMarkerLeftX;

int Settings::targetedOption;

int Settings::bgmBars;
int Settings::sfxBars;

float Settings::bgmBarsTotalWidth;
float Settings::sfxBarsTotalWidth;

void Settings::Initialize()
{
    optionStrings[OPTION_GLOBAL_MUTE] = "Mute ";
    optionStrings[OPTION_BGM_LEVEL] = "Music";
    optionStrings[OPTION_SFX_LEVEL] = "Sound";
    optionStrings[OPTION_RETURN_TO_TITLE] = "Return to Title";

    for(int i = 0; i < NUM_OPTIONS; i++)
    {
        optionTextX[i] = OPTION_TEXT_X_BASE;
        optionTextY[i] = OPTION_TEXT_Y_BASE + i*OPTION_TEXT_Y_SPACING;
    }
    optionTextY[OPTION_RETURN_TO_TITLE] += OPTION_TEXT_Y_SPACING;

    SetTargetedOption(OPTION_GLOBAL_MUTE);

    SetBgmBars(6);
    SetSfxBars(6);
}

void Settings::RecalculateOptionMarkerX()
{
    optionMarkerLeftX = OPTION_MARKER_SPRITE_WIDTH + OPTION_MARKER_SPRITE_X_SPACING;
}

void Settings::AdjustTargetedOptionUp()
{
    if(targetedOption > FIRST_OPTION)
    {
        targetedOption --;
        RecalculateOptionMarkerX();
    }
}

void Settings::AdjustTargetedOptionDown()
{
    if(targetedOption < LAST_OPTION)
    {
        targetedOption ++;
        RecalculateOptionMarkerX();
    }
}

void Settings::SetTargetedOption(int whichOption)
{
    targetedOption = whichOption;
    RecalculateOptionMarkerX();
}

void Settings::SetBgmBars(int bars)
{
    bgmBars = bars;
    if(bgmBars < 0)
        bgmBars = 0;
    else if(bgmBars > 10)
        bgmBars = 10;

    bgmBarsTotalWidth = VOLUME_BAR_WIDTH * bgmBars;

    Audio::SetBgmGain(bars * 0.1);
}

void Settings::SetSfxBars(int bars)
{
    sfxBars = bars;
    if(sfxBars < 0)
        sfxBars = 0;
    else if(sfxBars > 10)
        sfxBars = 10;

    sfxBarsTotalWidth = VOLUME_BAR_WIDTH * sfxBars;

    Audio::SetSfxGain(bars * 0.1);
}
