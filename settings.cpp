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

    SetBgmBars(3);
    SetSfxBars(3);
}

void Settings::Logic()
{

}

void Settings::Input()
{
    if(Keyboard::keyHoldTicks[Keyboard::KEY_UP] == 1)
    {
        Settings::AdjustTargetedOptionUp();
    }
    else if(Keyboard::keyHoldTicks[Keyboard::KEY_DOWN] == 1)
    {
        Settings::AdjustTargetedOptionDown();
    }

    if(Keyboard::keyHoldTicks[Keyboard::KEY_LEFT] == 1)
    {
        if(Settings::targetedOption == Settings::OPTION_BGM_LEVEL)
        {
            Settings::SetBgmBars(Settings::bgmBars - 1);
        }
        else if(Settings::targetedOption == Settings::OPTION_SFX_LEVEL)
        {
            Settings::SetSfxBars(Settings::sfxBars - 1);
        }
    }
    else if(Keyboard::keyHoldTicks[Keyboard::KEY_RIGHT] == 1)
    {
        if(Settings::targetedOption == Settings::OPTION_BGM_LEVEL)
        {
            Settings::SetBgmBars(Settings::bgmBars + 1);
        }
        else if(Settings::targetedOption == Settings::OPTION_SFX_LEVEL)
        {
            Settings::SetSfxBars(Settings::sfxBars + 1);
        }
    }

    if(Keyboard::keyHoldTicks[Keyboard::KEY_ESC] == 1)
    {
        Settings::SetTargetedOption(Settings::OPTION_RETURN_TO_TITLE);
    }
    else if(Keyboard::keyHoldTicks[Keyboard::KEY_ENTER] == 1)
    {
        if(Settings::targetedOption == Settings::OPTION_GLOBAL_MUTE)
        {

        }
        else if(Settings::targetedOption == Settings::OPTION_RETURN_TO_TITLE)
        {
            Scene::ChangeScene(Scene::SCENE_TITLE);
        }
    }
}

void Settings::Drawing()
{
    al_draw_bitmap(Image::titleOptionMarkerPng,
                   Settings::optionTextX[Settings::targetedOption] - Settings::optionMarkerLeftX,
                   Settings::optionTextY[Settings::targetedOption],
                   0);

    for(int i = 0; i < Settings::NUM_OPTIONS; i++)
    {
        Hax::string_al_draw_text(Font::monogram32, COLKEY_TEXT_LIGHT,
                                 Settings::optionTextX[i], Settings::optionTextY[i],
                                 ALLEGRO_ALIGN_LEFT | ALLEGRO_ALIGN_INTEGER, Settings::optionStrings[i]);
    }

    al_draw_bitmap(Image::settingsVolumeBarEmptyPng,
                   Settings::VOLUME_BARS_X, Settings::optionTextY[Settings::OPTION_BGM_LEVEL],
                   0);

    al_draw_bitmap_region(Image::settingsVolumeBarPng,
                          0,0,
                          Settings::bgmBarsTotalWidth, Settings::VOLUME_BAR_HEIGHT,
                          Settings::VOLUME_BARS_X, Settings::optionTextY[Settings::OPTION_BGM_LEVEL],
                          0);

    al_draw_bitmap(Image::settingsVolumeBarEmptyPng,
                   Settings::VOLUME_BARS_X, Settings::optionTextY[Settings::OPTION_SFX_LEVEL],
                   0);

    al_draw_bitmap_region(Image::settingsVolumeBarPng,
                          0,0,
                          Settings::sfxBarsTotalWidth, Settings::VOLUME_BAR_HEIGHT,
                          Settings::VOLUME_BARS_X, Settings::optionTextY[Settings::OPTION_SFX_LEVEL],
                          0);
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
