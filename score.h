#ifndef SCORE_H_INCLUDED
#define SCORE_H_INCLUDED

#include <iostream>

struct Score
{
	enum enumScoreTier
	{
		SCORE_TIER_POPCORN_SHIP = 0,
		SCORE_TIER_SMALL_SHIP = 1,
		SCORE_TIER_MEDIUM_SHIP = 2,
		SCORE_TIER_LARGE_SHIP = 3,
		SCORE_TIER_BOSS_SECTION = 4,
		SCORE_TIER_BOSS_CORE = 5
	};
	static const int NUM_SCORE_TIERS = 6;

	static float score;
	static float multiplier;
	static float value[NUM_SCORE_TIERS];

	static void Initialize()
	{
		score = 0;
		multiplier = 1.0;
		value[SCORE_TIER_POPCORN_SHIP] = 100;
		value[SCORE_TIER_SMALL_SHIP] = 200;
		value[SCORE_TIER_MEDIUM_SHIP] = 400;
		value[SCORE_TIER_LARGE_SHIP] = 800;
		value[SCORE_TIER_BOSS_SECTION] = 3200;
		value[SCORE_TIER_BOSS_CORE] = 6400;
	}

	static void AddValue(float score_value)
	{
		// multiplier += 0.1; // or something

		score = score + score_value*multiplier;
		std::cout << score << std::endl;
	}
};


#endif //SCORE_H_INCLUDED
