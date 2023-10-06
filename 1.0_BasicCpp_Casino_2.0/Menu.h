#pragma once
#include <string>
#include <iostream>

namespace menu {

	char GetUserOption();
	void RunCasino();
	enum class Optiones
	{
		Guess = 1, OddOrEven, Bar_Dice, Crown_and_Anchor,Roulette, ScoreBoard
	};
}