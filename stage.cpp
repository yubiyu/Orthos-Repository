#include "stage.h"

void Stage::Initialize()
{
    PC::pc = new PC();
    PC::pc->PC::Initialize(PC::HULL_PC_ORTHOS_A);

    Generator::Initialize(1);
}

void Stage::Uninitialize()
{
    delete PC::pc;

    for(std::vector<Bullet*>::iterator it = Bullet::bullets.begin(); it != Bullet::bullets.end();)
    {
        delete *it;
        it = Bullet::bullets.erase(it);
    }
    for(std::vector<NPC*>::iterator it = NPC::npcs.begin(); it != NPC::npcs.end();)
    {
        delete *it;
        it = NPC::npcs.erase(it);
    }

    Generator::Uninitialize();
}

void Stage::Logic()
{
    Generator::Logic();

    std::pair<std::multimap<int, NPC*>::iterator, std::multimap<int, NPC*>::iterator>range = Generator::stageShipList.equal_range(Generator::elaspedTime);

    for(std::multimap<int, NPC*>::iterator it = range.first; it != range.second; ++it)
    {
        NPC::npcs.push_back(it->second);
        (*it).second->SetTrackedTarget(PC::pc);
        Generator::stageShipList.erase(it);
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
            it = Bullet::bullets.erase(it);
        }
    }

    for(std::vector<NPC*>::iterator it = NPC::npcs.begin(); it!= NPC::npcs.end();)
    {
        if((*it)->GetIsActive())
        {
            (*it)->Logic();
            ++it;
        }
        else
        {
            delete *it;
            it = NPC::npcs.erase(it);
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

    if(Mouse::mouseButtonHoldTicks[Mouse::MOUSE_LEFT] == 1)
    {

    }
    */

    if(Keyboard::keyHoldTicks[Keyboard::KEY_LEFT] >= 1)
    {
        PC::pc->SetXPosition(PC::pc->GetXPosition()-4);
    }
    if(Keyboard::keyHoldTicks[Keyboard::KEY_RIGHT] >= 1)
    {
        PC::pc->SetXPosition(PC::pc->GetXPosition()+4);
    }
    if(Keyboard::keyHoldTicks[Keyboard::KEY_UP] >= 1)
    {
        PC::pc->SetYPosition(PC::pc->GetYPosition()-4);
    }
    if(Keyboard::keyHoldTicks[Keyboard::KEY_DOWN] >= 1)
    {
        PC::pc->SetYPosition(PC::pc->GetYPosition()+4);
    }

    if(Keyboard::keyHoldTicks[Keyboard::KEY_J] > 0)
    {
        PC::pc->SetFireCommandReceived(true);
    }
    else
        PC::pc->SetFireCommandReceived(false);

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
    DrawDebugGrid();
    DrawDebugGridCameraCrosshair();
    DrawDebugGridText();

    for(std::vector<NPC*>::iterator it = NPC::npcs.begin(); it != NPC::npcs.end(); ++it)
        (*it)->Drawing();

    PC::pc->Drawing();

    for(std::vector<Bullet*>::iterator it = Bullet::bullets.begin(); it != Bullet::bullets.end(); ++it)
        (*it)->Drawing();

    al_draw_multiline_text(Font::monogram32, COLKEY_TEXT_LIGHT, Display::WIDTH, 0, 600, 16, ALLEGRO_ALIGN_RIGHT,
                           "<ESC> to return to title.\n<UDLR> to move ship.\n<J> to fire.\n<K> to toggle test BGM.");


}

void Stage::DrawDebugGrid()
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



void Stage::DrawDebugGridCameraCrosshair()
{
    al_draw_line(Display::WIDTH/2, 0, Display::WIDTH/2, Display::HEIGHT, COLKEY_CAMERA_CROSSHAIR_LOCKED, 1);
    al_draw_line(0, Display::HEIGHT/2, Display::WIDTH, Display::HEIGHT/2, COLKEY_CAMERA_CROSSHAIR_LOCKED, 1);
}



void Stage::DrawDebugGridText()//float mouseTransformedX, float mouseTransformedY
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
