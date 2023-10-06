#pragma once
#include "CasinoGames.h"
#include <string>
#include <iostream>

namespace menu {

	int GetPlayerOption();
	void RunCasino();
	

	 enum  class Optiones 
	{
		GuessHighStack = 1,
		GuessLowStack, 
		OddOrEven, 
		Bar_Dice, 
		Crown_and_Anchor, 
		Roulette, 
		ScoreBoard
	};
}