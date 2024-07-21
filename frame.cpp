#include "frame.h"

std::string Frame::chapterString[5];
std::string Frame::difficultyString[2];
std::string Frame::scoreString;

std::string Frame::bombNameString;
std::string Frame::bombStatusString;

std::string Frame::lockonStatusString[8];

std::string Frame::mainWeaponNameString;
std::string Frame::mainWeaponStatusString;
std::string Frame::subWeaponNameString;
std::string Frame::subWeaponStatusString;

void Frame::Initialize()
{
    chapterString[0] = "Chapter I";
    chapterString[1] = "Chapter II";
    chapterString[2] = "Chapter III";
    chapterString[3] = "Chapter IV";
    chapterString[4] = "Chapter V";

    difficultyString[0] = "Normal";
    difficultyString[1] = "Hard";

    scoreString = "0000000000";

    bombNameString = "CRS-DIVARI";
    bombStatusString = "0%";

    for(int i = 0; i < 8; i++)
        lockonStatusString[i] = "Recalibrating";

    mainWeaponNameString = "MC-ORTH";
    mainWeaponStatusString = "Level 1";

    subWeaponNameString = "SC-KLAI";
    subWeaponStatusString = "Level 1";
}

void Frame::Drawing()
{
    al_draw_bitmap(Image::framePng,0,0,0);

    Hax::string_al_draw_text(Font::monogram32, COLKEY_TEXT_LIGHT, CHAPTER_READOUT_X, CHAPTER_READOUT_Y, ALLEGRO_ALIGN_LEFT, chapterString[0]);
    Hax::string_al_draw_text(Font::monogram32, COLKEY_TEXT_LIGHT, DIFFICULTY_READOUT_X, DIFFICULTY_READOUT_Y, ALLEGRO_ALIGN_LEFT, difficultyString[0]);

    Hax::string_al_draw_text(Font::monogram32, COLKEY_TEXT_LIGHT, SCORE_READOUT_X, SCORE_READOUT_Y, ALLEGRO_ALIGN_LEFT, scoreString);

    Hax::string_al_draw_text(Font::monogram32, COLKEY_TEXT_LIGHT, BOMB_NAME_READOUT_X, BOMB_NAME_READOUT_Y, ALLEGRO_ALIGN_LEFT, bombNameString);
    Hax::string_al_draw_text(Font::monogram32, COLKEY_TEXT_LIGHT, BOMB_STATUS_READOUT_X, BOMB_STATUS_READOUT_Y, ALLEGRO_ALIGN_LEFT, bombStatusString);

    for(int i = 0; i < 8; i++)
        Hax::string_al_draw_text(Font::monogram32, COLKEY_TEXT_LIGHT, LOCKON_STATUS_READOUT_X, LOCKON_STATUS_READOUT_Y + i*LOCKON_STATUS_READOUT_Y_SPACING, ALLEGRO_ALIGN_LEFT, lockonStatusString[i]);

    al_draw_bitmap(Image::frameEmitterIconSub[FRAME_EMITTER_ICON_ORTHOS_MAIN], MAIN_WEAPON_ICON_X, MAIN_WEAPON_ICON_Y, 0);
    Hax::string_al_draw_text(Font::monogram32, COLKEY_TEXT_LIGHT, MAIN_WEAPON_NAME_READOUT_X, MAIN_WEAPON_NAME_READOUT_Y, ALLEGRO_ALIGN_LEFT, mainWeaponNameString);
    Hax::string_al_draw_text(Font::monogram32, COLKEY_TEXT_LIGHT, MAIN_WEAPON_STATUS_READOUT_X, MAIN_WEAPON_STATUS_READOUT_Y, ALLEGRO_ALIGN_LEFT, mainWeaponStatusString);

    Hax::string_al_draw_text(Font::monogram32, COLKEY_TEXT_LIGHT, SUB_WEAPON_NAME_READOUT_X, SUB_WEAPON_NAME_READOUT_Y, ALLEGRO_ALIGN_LEFT, subWeaponNameString);
    Hax::string_al_draw_text(Font::monogram32, COLKEY_TEXT_LIGHT, SUB_WEAPON_STATUS_READOUT_X, SUB_WEAPON_STATUS_READOUT_Y, ALLEGRO_ALIGN_LEFT, subWeaponStatusString);
}

void Frame::UpdateScoreString(int score)
{
    std::stringstream ss;
    ss << std::setw(9) << std::setfill('0') << score;
    scoreString = ss.str();
}



