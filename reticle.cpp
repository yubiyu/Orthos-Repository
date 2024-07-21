#include "reticle.h"

float Reticle::displayXPosition;
float Reticle::displayYPosition;

float Reticle::frameXPosition;
float Reticle::frameYPosition;

void Reticle::Initialize()
{
    displayXPosition = 0;
    displayYPosition = 0;

    frameXPosition = 0;
    frameYPosition = 0;
}

void Reticle::Update()
{

    displayXPosition = Mouse::mouseDisplayX;
    displayYPosition = Mouse::mouseDisplayY;

    frameXPosition = Mouse::mouseDisplayX - Frame::ARENA_X;
    frameYPosition = Mouse::mouseDisplayY - Frame::ARENA_Y;
}

void Reticle::Drawing()
{
    al_draw_rotated_bitmap(Image::reticlePng, 32, 32, displayXPosition, displayYPosition, 0, 0);
}
