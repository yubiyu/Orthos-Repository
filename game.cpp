#include "game.h"

bool Game::exit;
bool Game::redraw;

void Game::MainLoop()
{
    while(!exit)
    {
        al_wait_for_event(Event::eventQueue, &Event::event);

        if(Event::event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            exit = true;

        if(Event::event.type == ALLEGRO_EVENT_KEY_DOWN)
            Keyboard::InputKeydown();

        if(Event::event.type == ALLEGRO_EVENT_KEY_UP)
            Keyboard::InputKeyup();

        if(Event::event.type == ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY)
        {

        }

        if(Event::event.type == ALLEGRO_EVENT_MOUSE_LEAVE_DISPLAY)
        {

        }

        if(Event::event.type == ALLEGRO_EVENT_MOUSE_AXES)
        {
            Mouse::InputMouseXY();
            Mouse::InputMousewheel();
        }

        if(Event::event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
            Mouse::InputMouseDown();

        if(Event::event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
            Mouse::InputMouseUp();

        if(Event::event.type == ALLEGRO_EVENT_TIMER)
        {
            redraw = true;

            InputSwitchboard();
            LogicSwitchboard();

            Audio::Logic();

            Mouse::mouseAxesAltered = false;
        }

        if(redraw && al_is_event_queue_empty(Event::eventQueue))
        {
            DrawingSwitchboard();
        }
    }
}

bool Game::Initialize(char **argv)
{
    exit = false;
    redraw = true;

    srand(time(NULL));

    al_install_system(ALLEGRO_VERSION_INT,NULL);
    Display::Initialize();
    Keyboard::Initialize();
    Mouse::Initialize();
    Timer::Initialize();
    Event::Initialize();
    Filesystem::Initialize(argv);
    Image::Initialize();
    Font::Initialize();
    Audio::Initialize();

    Palette::Initialize();
    Scene::Initialize();

    Camera::Initialize();
    Camera::SetCell(0, 0);
    Camera::WarpToDestination();

    Title::Initialize();
    Stage::Initialize();
    Settings::Initialize();
    Archive::Initialize();

    return true;
}

void Game::Uninitialize()
{
    Stage::Uninitialize();

    Camera::Uninitialize();

    Audio::Uninitialize();
    Font::Uninitialize();
    Image::Uninitialize();
    Filesystem::Uninitialize();

    Event::Uninitialize();
    Timer::Uninitialize();
    Mouse::Uninitialize();
    Keyboard::Uninitialize();
    Display::Uninitialize();

    al_uninstall_system();

}


void Game::InputSwitchboard()
{
    Keyboard::InputKeyHold();
    Mouse::InputMouseButtonHold();

    switch(Scene::inputContext)
    {
    case Scene::INPUT_CONTEXT_TITLE:
        TitleInput();
        break;
    case Scene::INPUT_CONTEXT_STAGE:
        StageInput();
        break;
    case Scene::INPUT_CONTEXT_ARCHIVE:
        ArchiveInput();
        break;
    case Scene::INPUT_CONTEXT_SETTINGS:
        SettingsInput();
        break;
    }
}

void Game::TitleInput()
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
            exit = true;
            break;
        }
    }
}

void Game::StageInput()
{
    if(Mouse::mousewheelInput[Mouse::MOUSEWHEEL_UP])
    {
        al_set_mouse_z(0);
    }
    else if(Mouse::mousewheelInput[Mouse::MOUSEWHEEL_DOWN])
    {
        al_set_mouse_z(0);
    }
    else if(Mouse::mouseInput[Mouse::MOUSE_MIDDLE])
    {

    }

    if(Mouse::mouseButtonHoldTicks[Mouse::MOUSE_LEFT] == 1)
    {

    }

    if(Keyboard::keyHoldTicks[Keyboard::KEY_LEFT] >= 1)
    {
        Camera::xPosition -= 4;
    }
    if(Keyboard::keyHoldTicks[Keyboard::KEY_RIGHT] >= 1)
    {
        Camera::xPosition += 4;
    }
    if(Keyboard::keyHoldTicks[Keyboard::KEY_UP] >= 1)
    {
        Camera::yPosition -= 4;
    }
    if(Keyboard::keyHoldTicks[Keyboard::KEY_DOWN] >= 1)
    {
        Camera::yPosition += 4;
    }

    if(Keyboard::keyHoldTicks[Keyboard::KEY_J] == 1)
    {
        ALLEGRO_SAMPLE_INSTANCE*genericLaserShoot;
        genericLaserShoot = al_create_sample_instance(Audio::genericLaserShootWav);
        al_set_sample_instance_gain(genericLaserShoot, Audio::sfxGain);
        al_attach_sample_instance_to_mixer(genericLaserShoot, al_get_default_mixer());
        Audio::activeSfxInstances.push_back(genericLaserShoot);
        al_play_sample_instance(genericLaserShoot);
    }

    if(Keyboard::keyHoldTicks[Keyboard::KEY_K] == 1)
    {
        /*
        if(al_get_sample_instance_playing(Audio::genericBgmSampleInstance))
            al_stop_sample_instance(Audio::genericBgmSampleInstance);
        else
        {
            al_set_sample_instance_playmode(Audio::genericBgmSampleInstance, ALLEGRO_PLAYMODE_LOOP);
            al_play_sample_instance(Audio::genericBgmSampleInstance);
        }
        */
    }

    if(Keyboard::keyHoldTicks[Keyboard::KEY_ENTER] == 1)
    {
        Scene::ChangeScene(Scene::SCENE_TITLE);
    }
}

void Game::ArchiveInput()
{
    if(Keyboard::keyHoldTicks[Keyboard::KEY_ESC] == 1 || Keyboard::keyHoldTicks[Keyboard::KEY_ENTER] == 1)
    {
        Scene::ChangeScene(Scene::SCENE_TITLE);
    }
}


void Game::SettingsInput()
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

void Game::LogicSwitchboard()
{
    switch(Scene::scene)
    {
    case Scene::SCENE_TITLE:
        TitleSceneLogic();
        break;
    case Scene::SCENE_STAGE:
        StageSceneLogic();
        break;
    case Scene::SCENE_SETTINGS:
        SettingsSceneLogic();
        break;
    case Scene::SCENE_ARCHIVE:
        ArchiveSceneLogic();
        break;
    }
}

void Game::TitleSceneLogic()
{

}

void Game::StageSceneLogic()
{

}

void Game::SettingsSceneLogic()
{

}

void Game::ArchiveSceneLogic()
{

}

void Game::DrawingSwitchboard()
{
    Game::redraw = false;
    al_clear_to_color(COLKEY_BACKGROUND);

    switch(Scene::scene)
    {
    case Scene::SCENE_TITLE:
        TitleSceneDrawing();
        break;
    case Scene::SCENE_STAGE:
        StageSceneDrawing();
        break;
    case Scene::SCENE_SETTINGS:
        SettingsSceneDrawing();
        break;
    case Scene::SCENE_ARCHIVE:
        ArchiveSceneDrawing();
        break;
    }

    al_flip_display();
}

void Game::TitleSceneDrawing()
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

void Game::StageSceneDrawing()
{
    DrawDebugGrid();
    DrawDebugGridCameraCrosshair();
    DrawDebugGridText();

    al_draw_multiline_text(Font::monogram32, COLKEY_TEXT_LIGHT, Display::WIDTH, 0, 600, 16, ALLEGRO_ALIGN_RIGHT,
                           "<Enter> to proceed to title.\n<UDLR> to test camera.\n<J> to test SFX.\n<K> to toggle test BGM.");
}

void Game::SettingsSceneDrawing()
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

void Game::ArchiveSceneDrawing()
{
    Hax::string_al_draw_text(Font::monogram32, COLKEY_TEXT_LIGHT,
                             Archive::RETURN_TO_TITLE_TEXT_X, Archive::RETURN_TO_TITLE_TEXT_Y,
                             ALLEGRO_ALIGN_CENTER, Archive::returnToTitleString);
}

void Game::DrawDebugGrid()
{
    for(int x = 0; x <= Display::WIDTH / Tile::WIDTH; x++) //Columns
    {
        al_draw_line(x*Tile::WIDTH - (int)Camera::xPosition%(int)Tile::HEIGHT,
                     0,
                     x*Tile::WIDTH  - (int)Camera::xPosition%(int)Tile::HEIGHT,
                     Display::HEIGHT,
                     COLKEY_GRID,1);
    }

    for(int y = 0; y <= Display::HEIGHT / Tile::HEIGHT; y++) //Rows
    {
        al_draw_line(0,
                     y*Tile::WIDTH  - (int)Camera::yPosition%(int)Tile::HEIGHT,
                     Display::WIDTH,
                     y*Tile::WIDTH  - (int)Camera::yPosition%(int)Tile::HEIGHT,
                     COLKEY_GRID,1);
    }
}



void Game::DrawDebugGridCameraCrosshair()
{
    al_draw_line(Display::WIDTH/2, 0, Display::WIDTH/2, Display::HEIGHT, COLKEY_CAMERA_CROSSHAIR_LOCKED, 1);
    al_draw_line(0, Display::HEIGHT/2, Display::WIDTH, Display::HEIGHT/2, COLKEY_CAMERA_CROSSHAIR_LOCKED, 1);
}



void Game::DrawDebugGridText()//float mouseTransformedX, float mouseTransformedY
{
    int camXPos = Camera::xPosition;
    int camYPos = Camera::yPosition;

    int camXCell = std::round(camXPos/Tile::WIDTH);
    int camYCell = std::round(camYPos/Tile::HEIGHT);

    int zoomPercentage = Camera::zoomScale*100;

    std::string cameraPositionString = "Crosshair position: (" + std::to_string(camXPos) + ", " + std::to_string(camYPos) + ") : ("
                                       + std::to_string(camXCell) + ", " + std::to_string(camYCell) + ") "
                                       + std::to_string(zoomPercentage) + "% zoom";

    Hax::string_al_draw_text(Font::builtin8,COLKEY_CAMERA_CROSSHAIR_LOCKED,0,0,ALLEGRO_ALIGN_LEFT,cameraPositionString);

}
