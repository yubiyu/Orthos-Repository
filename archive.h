#ifndef ARCHIVE_H_INCLUDED
#define ARCHIVE_H_INCLUDED

#include "display.h"

#include <string>

struct Archive
{
    static std::string returnToTitleString;

    static const int RETURN_TO_TITLE_TEXT_X = Display::WIDTH/2;
    static const int RETURN_TO_TITLE_TEXT_Y = Display::HEIGHT/2;

    static void Initialize()
    {
        returnToTitleString = "Press [ESC / Enter] to return to title.";
    }
};

#endif // ARCHIVE_H_INCLUDED
