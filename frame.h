#ifndef FRAME_H_INCLUDED
#define FRAME_H_INCLUDED

#include "image.h"
#include "font.h"
#include "palette.h"

#include "lockon.h"

#include "arena.h"
#include "tile.h"

#include "hax.h"

#include <string>
#include <sstream>
#include <iomanip>

struct Frame
{
    static constexpr float ARENA_X = 320;
    static constexpr float ARENA_Y = 24;
    static constexpr float ARENA_HEIGHT = Arena::HEIGHT;

    static constexpr float CHAPTER_READOUT_X = Tile::WIDTH*2;
    static constexpr float CHAPTER_READOUT_Y = Tile::HEIGHT*4;
    static std::string chapterString[5];

    static constexpr float DIFFICULTY_READOUT_X = Tile::WIDTH*2;
    static constexpr float DIFFICULTY_READOUT_Y = Tile::HEIGHT*5;
    static std::string difficultyString[2];

    static constexpr float SCORE_READOUT_X = Tile::WIDTH*2;
    static constexpr float SCORE_READOUT_Y = Tile::HEIGHT*7;
    static std::string scoreString;

    static constexpr float LIVES_READOUT_X = 0;
    static constexpr float LIVES_READOUT_Y = 0;

    enum enumFrameEmitterIcons
    {
        FRAME_EMITTER_ICON_ORTHOS_MAIN = 0,
        FRAME_EMITTER_ICON_LITHOS_MAIN = 1,
    };

    enum enumFrameSubshipIcons
    {
        FRAME_SUBSHIP_ICON_XIPHOS = 0,
        FRAME_SUBSHIP_ICON_EFTHYMIA = 1
    };

    static constexpr float BOMB_NAME_READOUT_X = 136;
    static constexpr float BOMB_NAME_READOUT_Y = 380;
    static constexpr float BOMB_STATUS_READOUT_X = BOMB_NAME_READOUT_X;
    static constexpr float BOMB_STATUS_READOUT_Y = BOMB_NAME_READOUT_Y + 32;
    static std::string bombNameString;
    static std::string bombStatusString;

    static constexpr float LOCKON_STATUS_BUBBLE_X = 64;
    static constexpr float LOCKON_STATUS_BUBBLE_Y = 464;
    static constexpr float LOCKON_STATUS_BAR_X = 104;
    static constexpr float LOCKON_STATUS_BAR_Y = LOCKON_STATUS_BUBBLE_Y;
    static constexpr float LOCKON_STATUS_READOUT_X = 104;
    static constexpr float LOCKON_STATUS_READOUT_Y = 456;
    static constexpr float LOCKON_STATUS_Y_SPACING = 40;
    static constexpr float LOCKON_BAR_WIDTH = 152;
    static constexpr float LOCKON_BAR_HEIGHT = 16;
    static std::string lockonStatusString[8];

    static constexpr float MAIN_WEAPON_ICON_X = 56;
    static constexpr float MAIN_WEAPON_ICON_Y = 784;
    static constexpr float MAIN_WEAPON_NAME_READOUT_X = 132;
    static constexpr float MAIN_WEAPON_NAME_READOUT_Y = 784;
    static constexpr float MAIN_WEAPON_STATUS_READOUT_X = MAIN_WEAPON_NAME_READOUT_X;
    static constexpr float MAIN_WEAPON_STATUS_READOUT_Y = MAIN_WEAPON_NAME_READOUT_Y + 32;
    static std::string mainWeaponNameString;
    static std::string mainWeaponStatusString;

    static constexpr float SUBSHIP_ICON_X = 56;
    static constexpr float SUBSHIP_ICON_Y = 856;
    static constexpr float SUBSHIP_NAME_READOUT_X = 132;
    static constexpr float SUBSHIP_NAME_READOUT_Y = 856;
    static constexpr float SUBSHIP_STATUS_READOUT_X = SUBSHIP_NAME_READOUT_X;
    static constexpr float SUBSHIP_STATUS_READOUT_Y = SUBSHIP_NAME_READOUT_Y + 32;
    static std::string subshipNameString;
    static std::string subshipStatusString;

    static void Initialize();

    static void Drawing();

    static void UpdateScoreString(int score);


};

#endif // FRAME_H_INCLUDED
