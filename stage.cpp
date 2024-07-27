#include "stage.h"

void Stage::Initialize()
{
    PC::pc = new PC();
    PC::pc->PC::Initialize(PC::HULL_PC_ORTHOS_A);

    Generator::Initialize(1);

    Lockon::Initialize();
    Frame::Initialize();
    Reticle::Initialize();
}

void Stage::Uninitialize()
{
    delete PC::pc;
    PC::pc = nullptr;

    for(std::vector<Bullet*>::iterator it = Bullet::bullets.begin(); it != Bullet::bullets.end();)
    {
        delete *it;
        *it = nullptr;
        it = Bullet::bullets.erase(it);
    }
    for(std::vector<NPC*>::iterator it = NPC::npcs.begin(); it != NPC::npcs.end();)
    {
        delete *it;
        *it = nullptr;
        it = NPC::npcs.erase(it);
    }

    Generator::Uninitialize();
    Lockon::Uninitialize();
}

void Stage::Logic()
{
    Generator::Logic();

    Lockon::Logic();

    std::pair<std::multimap<int, NPC*>::iterator, std::multimap<int, NPC*>::iterator>range;
    range = Generator::stageShipList.equal_range(Generator::elaspedTime);
    for(std::multimap<int, NPC*>::iterator it = range.first; it != range.second;)
    {
        NPC::npcs.push_back(it->second);
        (*it).second->SetTrackedTarget(PC::pc);
        it = Generator::stageShipList.erase(it);
    }

    PC::pc->Logic();

    for(std::vector<Bullet*>::iterator it = Bullet::bullets.begin(); it != Bullet::bullets.end();)
    {
        if((*it)->GetIsActive())
        {
            (*it)->Logic();
            ++it;
        }
        else
        {
            delete *it;
            *it = nullptr;
            it = Bullet::bullets.erase(it);
        }
    }

    for(std::vector<NPC*>::iterator it = NPC::npcs.begin(); it != NPC::npcs.end();)
    {
        if((*it)->GetIsActive())
        {
            (*it)->Logic();
            ++it;
        }
        else
        {
            delete *it;
            *it = nullptr;
            it = NPC::npcs.erase(it);
        }
    }

    for(std::vector<Particle*>::iterator it = Particle::particles.begin(); it != Particle::particles.end();)
    {
        if((*it)->GetIsActive())
        {
            (*it)->Logic();
            ++it;
        }
        else
        {
            delete *it;
            *it = nullptr;
            it = Particle::particles.erase(it);
        }
    }
}

void Stage::Input()
{
    /*
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
    */
    if(Mouse::mouseAxesAltered)
    {
        Reticle::Update();
    }

    if(Mouse::mouseButtonHoldTicks[Mouse::MOUSE_LEFT] > 0)
    {
        PC::pc->SetFireCommandReceived(true);
    }
    else
        PC::pc->SetFireCommandReceived(false);

    if(Keyboard::keyHoldTicks[Keyboard::KEY_A] >= 1)
    {
        PC::pc->SetXPosition(PC::pc->GetXPosition()-4);
    }
    if(Keyboard::keyHoldTicks[Keyboard::KEY_D] >= 1)
    {
        PC::pc->SetXPosition(PC::pc->GetXPosition()+4);
    }
    if(Keyboard::keyHoldTicks[Keyboard::KEY_W] >= 1)
    {
        PC::pc->SetYPosition(PC::pc->GetYPosition()-4);
    }
    if(Keyboard::keyHoldTicks[Keyboard::KEY_S] >= 1)
    {
        PC::pc->SetYPosition(PC::pc->GetYPosition()+4);
    }

    if(Keyboard::keyHoldTicks[Keyboard::KEY_F] >= 1)
    {
        PC::pc->LockonRelease();
    }

    if(Keyboard::keyHoldTicks[Keyboard::KEY_K] == 1)
    {

        //if(al_get_sample_instance_playing(Audio::genericBgmSampleInstance))
          //  al_stop_sample_instance(Audio::genericBgmSampleInstance);
        //else
        //{
            //al_set_sample_instance_playmode(Audio::genericBgmSampleInstance, ALLEGRO_PLAYMODE_LOOP);
          //  al_play_sample_instance(Audio::genericBgmSampleInstance);
        //}

    }

    if(Keyboard::keyHoldTicks[Keyboard::KEY_ESC] == 1)
    {
        Scene::ChangeScene(Scene::SCENE_TITLE);
    }
}

void Stage::Drawing()
{
    al_set_target_bitmap(Camera::cameraBuffer);
    al_clear_to_color(Palette::currentClearColour);

    DrawDebugGrid();
    //DrawDebugGridCameraCrosshair();
    DrawDebugGridText();

    for(std::vector<NPC*>::iterator it = NPC::npcs.begin(); it != NPC::npcs.end(); ++it)
        (*it)->Drawing();

    PC::pc->MainDrawing();

    for(std::vector<Particle*>::iterator it = Particle::particles.begin(); it != Particle::particles.end(); ++it)
        (*it)->Drawing();

    PC::pc->SubshipDrawing();

    for(std::vector<Bullet*>::iterator it = Bullet::bullets.begin(); it != Bullet::bullets.end(); ++it)
        (*it)->Drawing();

    Lockon::Drawing();

    al_set_target_bitmap(al_get_backbuffer(Display::display));
    al_clear_to_color(Palette::currentClearColour);
    al_draw_bitmap(Camera::cameraBuffer, Frame::ARENA_X, Frame::ARENA_Y, 0);

    Frame::Drawing();
    Reticle::Drawing();

    /*
    al_draw_multiline_text(Font::monogram32, COLKEY_TEXT_LIGHT, Display::WIDTH, 0, 600, 16, ALLEGRO_ALIGN_RIGHT,
                           "<ESC> to return to title.\n<WASD> to move ship.\n<Click> to fire.\n");
                           */
}

void Stage::DrawDebugGrid()
{
    for(int x = 0; x <= Arena::WIDTH / Tile::WIDTH; x++) //Columns
    {
        al_draw_line(x*Tile::WIDTH - (int)Camera::xPosition%(int)Tile::HEIGHT,
                     0,
                     x*Tile::WIDTH  - (int)Camera::xPosition%(int)Tile::HEIGHT,
                     Arena::HEIGHT,
                     COLKEY_GRID,1);
    }

    for(int y = 0; y <= Arena::HEIGHT / Tile::HEIGHT; y++) //Rows
    {
        al_draw_line(0,
                     y*Tile::WIDTH  - (int)Camera::yPosition%(int)Tile::HEIGHT,
                     Arena::WIDTH,
                     y*Tile::WIDTH  - (int)Camera::yPosition%(int)Tile::HEIGHT,
                     COLKEY_GRID,1);
    }
}



void Stage::DrawDebugGridCameraCrosshair()
{
    al_draw_line(Arena::WIDTH/2, 0, Arena::WIDTH/2, Arena::HEIGHT, COLKEY_CAMERA_CROSSHAIR_LOCKED, 1);
    al_draw_line(0, Arena::HEIGHT/2, Arena::WIDTH, Arena::HEIGHT/2, COLKEY_CAMERA_CROSSHAIR_LOCKED, 1);
}



void Stage::DrawDebugGridText()//float mouseTransformedX, float mouseTransformedY
{
    /*
    int camXPos = Camera::xPosition;
    int camYPos = Camera::yPosition;

    int camXCell = std::round(camXPos/Tile::WIDTH);
    int camYCell = std::round(camYPos/Tile::HEIGHT);

    int zoomPercentage = Camera::zoomScale*100;

    std::string cameraPositionString = "Crosshair position: (" + std::to_string(camXPos) + ", " + std::to_string(camYPos) + ") : ("
                                       + std::to_string(camXCell) + ", " + std::to_string(camYCell) + ") "
                                       + std::to_string(zoomPercentage) + "% zoom";

    Hax::string_al_draw_text(Font::builtin8,COLKEY_CAMERA_CROSSHAIR_LOCKED,0,0,ALLEGRO_ALIGN_LEFT,cameraPositionString);
    */
}
