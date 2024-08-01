#ifndef FLYINGTEXT_H
#define FLYINGTEXT_H

#include <string>
#include <vector>

#include "font.h"

#include "timer.h"

#include "palette.h"
#include "hax.h"

class FlyingText
{
	bool isActive{};

	std::string text;
	int size{};
	int xPosition{};
	int yPosition{};

	int lifespan{};
	static const int BASE_LIFESPAN = Timer::FPS * 1;

public:
	static std::vector<FlyingText*>flyingTexts;

	FlyingText();
	~FlyingText();

	void Initialize(std::string text_content, int x_position, int y_position);
	void Initialize(int text_content, int x_position, int y_position);

	void Logic();
	void Drawing();

	bool GetIsActive() const { return isActive; }
	void SetIsActive(bool active) { isActive = active; }


};

#endif // FLYINGTEXT_H