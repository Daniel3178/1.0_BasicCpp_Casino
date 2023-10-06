#pragma once
#include "Menu.h"
#include "BufferTools.h"
#include "Bar_dice.h"
#include "OddOrEven.h"
#include "Guess.h"
#include "Scoreboard.h"
#include "CrownAndAnchor.h"

namespace menu {

	char GetUserOption() {

		std::cout << "	Casino 1.4	" << '\n';
		std::cout << "	Press [1] :: Play Guessing Game	" << '\n';
		std::cout << "	Press [2] :: Play Odd/Even Game " << '\n';
		std::cout << "	Press [3] :: Play Bar_Dice " << '\n';
		std::cout << "	Press [4] :: Play Crown and Anchor " << '\n';
		std::cout << "	Press [5] :: Display statistics " << '\n';

		std::cout << "	Your choice: ";
		char usrInput{ 0 };
		bool isAccepted{ false };
		do {
			isAccepted = true;
			usrInput = bufferTools::GetUserIntFormat();
			if (!(usrInput == 1 || usrInput == 2 || usrInput == 3 || usrInput == 4 || usrInput == 5)) {
				system("cls");
				std::cout << "Your choices are 1, 2, 3, 4 or 5 " << '\n';
				isAccepted = false;
			}
		} while (!isAccepted);

		return usrInput;
	}


	void RunCasino() {

		bool isGameActive{ true };
		int currentBudget = 400, playerBet = 0;
		const unsigned char ROW = 6, COLUMN = 2;

		std::array<std::array<std::string, COLUMN>, ROW> statisticLst{{
		{"Game","	Profits/Losses"},
		{"No statistics","No statistics"},
		{"No statistics","No statistics"},
		{"No statistics","No statistics"},
		{"No statistics","No statistics"},
		{"No statistics","No statistics"},
		} };

		enum class Optiones
		{
			Guess = 1, OddOrEven, Bar_Dice, Crown_and_Anchor,ScoreBoard
		};

		while (isGameActive) 
		{
			system("cls"), bufferTools::DisplayRules();
			switch (GetUserOption())
			{
			case static_cast<char>(Optiones::Guess):
				guess::RunGuess(currentBudget, playerBet, isGameActive, statisticLst, ROW);
				break; 
			case static_cast<char>(Optiones::OddOrEven):
				oddOrEven::RunEvenOrOdd(currentBudget, playerBet, isGameActive, statisticLst, ROW);
				break;
			case static_cast<char>(Optiones::Bar_Dice):
				bar_dice::RunBar_Dice(currentBudget, isGameActive, statisticLst, ROW);
				break;
			case static_cast<char>(Optiones::Crown_and_Anchor):
				crownAndAnchor::RunCrownAndAnchor(currentBudget, playerBet, isGameActive, statisticLst, ROW);
				break;
			case static_cast<char>(Optiones::ScoreBoard):
				scoreboard::RunBoard(statisticLst, ROW, COLUMN);
				break;
			}

		}
	}
}