#pragma once
#include "Bar_dice.h"
#include "BufferTools.h"
#include "Scoreboard.h"
#include "Guess.h"


namespace bar_dice {

	uint8_t GetUserDiceResult() {

		std::cout << "\n\tPress [R] on the keyboard to roll the dices: ";
		bool isAccepted{ false };
		char usrOpt{ 'o' };
		do {
			isAccepted = true;
			usrOpt = bufferTools::GetUserCharFormat();
			if (!(usrOpt == 'r' || usrOpt == 'R')) {
				system("cls");
				std::cout << "Answer unknown, please answer with [R/r]" << '\n';
				isAccepted = false;
			}
		} while (!isAccepted);
		uint8_t* dieSumStr = guess::Get5DieResult().data();
		uint8_t dieSum = dieSumStr[0] + dieSumStr[1];
		std::cout << "\tYour sum is: " << bufferTools::IntToString(dieSum) << '\n';
		return dieSum;
	}

	void DisplayBarInfo() {
		std::cout << "\tEach drink costs 50$! " << '\n';
	}

	uint8_t GetBotPlayerDiceResult() {
		uint8_t* dieSumStr = guess::Get5DieResult().data();
		uint8_t dieSum = dieSumStr[0] + dieSumStr[1];
		std::cout << "\tDaniel's sum is: " << bufferTools::IntToString(dieSum) << '\n';
		return dieSum;
	}

	void RunBar_Dice(int& aCurrentBudget, bool& isGameActive,
		std::array<std::array<std::string, 2>, 6>& aStatisticLst) 
	{
		int bar_diceProfitLoss = 0, botResult=0, usrResult=0;
		const short UPER_LIMIT = 400, LOWER_LIMIT = -400, DRINK_PRICE = 50;
		bool isKeepPlaying = true, isPlayerLegit = true;
		const char gameName[]{ "Bar_Dice" };

		while (isKeepPlaying && isGameActive) 
		{
			system("cls"), bufferTools::ClearInputBuffer();
			DisplayBarInfo();
			botResult = GetBotPlayerDiceResult(), usrResult = GetUserDiceResult();
			if (botResult < usrResult) 
			{
				std::cout << "\n	Daniel: Damn! I'll swish you the money!";
				aCurrentBudget += DRINK_PRICE, bar_diceProfitLoss += DRINK_PRICE;
				scoreboard::CheckCurrentGameLimit(gameName, &bar_diceProfitLoss, isPlayerLegit, isKeepPlaying, UPER_LIMIT, LOWER_LIMIT, aStatisticLst);
				std::cout << "\n\tYour budget increased to " << aCurrentBudget << '\n';
			}
			else if (botResult > usrResult) 
			{
				std::cout << "\n	Daniel: Sorry man, I will watch you paying for my drink!";
				aCurrentBudget -= DRINK_PRICE, bar_diceProfitLoss -= DRINK_PRICE;
				scoreboard::CheckCurrentGameLimit(gameName, &bar_diceProfitLoss, isPlayerLegit, isKeepPlaying, UPER_LIMIT, LOWER_LIMIT, aStatisticLst);
				scoreboard::CheckBudget(aCurrentBudget, isGameActive);
			}
			else 
			{
				std::cout << "\n	Daniel: Let's do it one more time!";
			}
			bufferTools::PlayOrExit(gameName, bar_diceProfitLoss, isGameActive, isKeepPlaying, isPlayerLegit, aStatisticLst);
		}
		system("pause");

	}
}