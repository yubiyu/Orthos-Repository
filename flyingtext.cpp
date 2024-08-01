#include "flyingtext.h"

std::vector<FlyingText*> FlyingText::flyingTexts;

FlyingText::FlyingText()
{

}

FlyingText::~FlyingText()
{

}

void FlyingText::Initialize(std::string text_content, int x_position, int y_position)
{
	isActive = true;

	text = text_content;
	xPosition = x_position;
	yPosition = y_position;

	lifespan = BASE_LIFESPAN;
}

void FlyingText::Initialize(int text_content, int x_position, int y_position)
{
	isActive = true;

	text = std::to_string(text_content);
	xPosition = x_position;
	yPosition = y_position;

	lifespan = BASE_LIFESPAN;
}

void FlyingText::Logic()
{
	lifespan--;
	if (lifespan <= 0)
	{
		isActive = false;
	}
}

void FlyingText::Drawing()
{
	Hax::string_al_draw_text(Font::monogram32, Palette::COL_ORTHOS_WHITE, xPosition, yPosition, ALLEGRO_ALIGN_CENTER, text);
}