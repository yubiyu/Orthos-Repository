#include "reticle.h"

float Reticle::displayXPosition;
float Reticle::displayYPosition;

float Reticle::arenaXPosition;
float Reticle::arenaYPosition;

void Reticle::Initialize()
{
    displayXPosition = 0;
    displayYPosition = 0;

    arenaXPosition = 0;
    arenaYPosition = 0;
}

void Reticle::Update()
{

    displayXPosition = Mouse::mouseDisplayX;
    displayYPosition = Mouse::mouseDisplayY;

    arenaXPosition = Mouse::mouseDisplayX - Arena::X_POSITION;
    arenaYPosition = Mouse::mouseDisplayY - Arena::Y_POSITION;
}

void Reticle::Drawing()
{
    al_draw_rotated_bitmap(Image::reticlePng, 32, 32, displayXPosition, displayYPosition, 0, 0);
}
