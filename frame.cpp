#include "frame.h"

std::string Frame::chapterString[5];
std::string Frame::difficultyString[2];
std::string Frame::scoreString;

std::string Frame::smartbombNameString[Smartbomb::NUM_TYPES];
std::string Frame::smartbombStatusString;

std::string Frame::lockonStatusString[8];

std::string Frame::mainWeaponNameString[PC::NUM_HULL_TYPES];
std::string Frame::mainWeaponStatusString;
std::string Frame::subshipNameString[Subship::NUM_HULL_TYPES];
std::string Frame::subshipStatusString;

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

    smartbombNameString[Smartbomb::SMARTBOMB_KATHETOS] = "CR-KATHETOS";
    smartbombNameString[Smartbomb::SMARTBOMB_KLAFTHMOS] = "CR-KLAFTHMOS";
    smartbombStatusString = "[ DISABLED ]";

    for(int i = 0; i < 8; i++)
        lockonStatusString[i] = " ";

    mainWeaponNameString[PC::HULL_PC_ORTHOS_A] = "MC-ORTHOS A";
    mainWeaponNameString[PC::HULL_PC_ORTHOS_B] = "MC-ORTHOS B";
    mainWeaponNameString[PC::HULL_PC_LITHOS_A] = "MC-LITHOS A";
    mainWeaponNameString[PC::HULL_PC_LITHOS_B] = "MC-LITHOS B";
    mainWeaponStatusString = "Level 1";

    subshipNameString[Subship::HULL_SUBSHIP_XIPHOS] = "SC-XIPHOS";
    subshipNameString[Subship::HULL_SUBSHIP_EFTHYMIA] = "SC-EFTHYMIA";
    subshipStatusString = "Level 1";
}

void Frame::Drawing()
{
    al_draw_bitmap(Image::framePng,0,0,0);

    Hax::string_al_draw_text(Font::monogram32, COLKEY_TEXT_LIGHT, CHAPTER_READOUT_X, CHAPTER_READOUT_Y, ALLEGRO_ALIGN_LEFT, chapterString[0]);
    Hax::string_al_draw_text(Font::monogram32, COLKEY_TEXT_LIGHT, DIFFICULTY_READOUT_X, DIFFICULTY_READOUT_Y, ALLEGRO_ALIGN_LEFT, difficultyString[0]);

    Hax::string_al_draw_text(Font::monogram32, COLKEY_TEXT_LIGHT, SCORE_READOUT_X, SCORE_READOUT_Y, ALLEGRO_ALIGN_LEFT, scoreString);

    al_draw_bitmap(Image::frameSmartbombIconSub[Smartbomb::type], SMARTBOMB_ICON_X, SMARTBOMB_ICON_Y, 0);
    Hax::string_al_draw_text(Font::monogram32, COLKEY_TEXT_LIGHT, SMARTBOMB_NAME_READOUT_X, SMARTBOMB_NAME_READOUT_Y, ALLEGRO_ALIGN_LEFT, smartbombNameString[Smartbomb::type]);
    Hax::string_al_draw_text(Font::monogram32, COLKEY_TEXT_LIGHT, SMARTBOMB_STATUS_READOUT_X, SMARTBOMB_STATUS_READOUT_Y, ALLEGRO_ALIGN_LEFT, smartbombStatusString);

    for(int i = 0; i < Lockon::NUM_LOCKS; i++)
    {
        switch(Lockon::GetLockState(i))
        {
            case Lockon::LOCKON_STATE_READY:
                lockonStatusString[i] = "Ready";
            break;

            case Lockon::LOCKON_STATE_ACQUIRED:
                lockonStatusString[i] = "Lock-on!";
                al_draw_bitmap(Image::frameLockonBubbleBluePng, LOCKON_STATUS_BUBBLE_X, LOCKON_STATUS_BUBBLE_Y + i*LOCKON_STATUS_Y_SPACING, 0);
                al_draw_bitmap_region(Image::frameLockonBarBluePng, 0, 0, LOCKON_BAR_WIDTH * ((float)Lockon::lockCoherence[i] / Lockon::BASE_LOCK_COHERENCE), LOCKON_BAR_HEIGHT, LOCKON_STATUS_BAR_X, LOCKON_STATUS_BAR_Y + i*LOCKON_STATUS_Y_SPACING, 0);

            break;

            case Lockon::LOCKON_STATE_FIRE_GUIDANCE:
                lockonStatusString[i] = "Guidance";
                al_draw_bitmap(Image::frameLockonBubbleRedPng, LOCKON_STATUS_BUBBLE_X, LOCKON_STATUS_BUBBLE_Y + i*LOCKON_STATUS_Y_SPACING, 0);
                al_draw_bitmap(Image::frameLockonBarRedPng, LOCKON_STATUS_BAR_X, LOCKON_STATUS_BAR_Y + i*LOCKON_STATUS_Y_SPACING, 0);

            break;
        }
        Hax::string_al_draw_text(Font::monogram32, COLKEY_TEXT_LIGHT, LOCKON_STATUS_READOUT_X, LOCKON_STATUS_READOUT_Y + i*LOCKON_STATUS_Y_SPACING, ALLEGRO_ALIGN_LEFT, lockonStatusString[i]);

    }
    al_draw_bitmap(Image::frameEmitterIconSub[PC::pc->GetHullType()], MAIN_WEAPON_ICON_X, MAIN_WEAPON_ICON_Y, 0);
    Hax::string_al_draw_text(Font::monogram32, COLKEY_TEXT_LIGHT, MAIN_WEAPON_NAME_READOUT_X, MAIN_WEAPON_NAME_READOUT_Y, ALLEGRO_ALIGN_LEFT, mainWeaponNameString[PC::pc->GetHullType()]);
    Hax::string_al_draw_text(Font::monogram32, COLKEY_TEXT_LIGHT, MAIN_WEAPON_STATUS_READOUT_X, MAIN_WEAPON_STATUS_READOUT_Y, ALLEGRO_ALIGN_LEFT, mainWeaponStatusString);

    al_draw_bitmap(Image::frameSubshipIconSub[PC::pc->GetSubshipHullType()], SUBSHIP_ICON_X, SUBSHIP_ICON_Y, 0);
    Hax::string_al_draw_text(Font::monogram32, COLKEY_TEXT_LIGHT, SUBSHIP_NAME_READOUT_X, SUBSHIP_NAME_READOUT_Y, ALLEGRO_ALIGN_LEFT, subshipNameString[PC::pc->GetSubshipHullType()]);
    Hax::string_al_draw_text(Font::monogram32, COLKEY_TEXT_LIGHT, SUBSHIP_STATUS_READOUT_X, SUBSHIP_STATUS_READOUT_Y, ALLEGRO_ALIGN_LEFT, subshipStatusString);
}

void Frame::UpdateScoreString(int score)
{
    std::stringstream ss;
    ss << std::setw(9) << std::setfill('0') << score;
    scoreString = ss.str();
}



