#pragma once
#include "Guess.h"
#include "BufferTools.h"
#include "Scoreboard.h"
namespace guess {

	int GetUserGuess() {

		std::cout << "\n\tPlease guess a number between 2 and 12: ";
		int usrInput{ 0 };
		bool isAccepted{ false };
		do {
			isAccepted = true;
			usrInput = bufferTools::GetUserIntFormat();
			if (!(usrInput >= 2 && usrInput <= 12)) {
				system("cls");
				std::cout << "Number out of range, please keep it between 2 and 12" << '\n';
				isAccepted = false;
			}
		} while (!isAccepted);
		return usrInput;
	}

	std::array<uint8_t, 5> Get5DieResult() 
	{
		std::array<uint8_t, 5> dieResult{0};
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> dis(1, 6);

		uint8_t dieRollOne = dis(gen), dieRollTwo = dis(gen), dieRollThree = dis(gen),
			dieRollFour = dis(gen), dieRollFive = dis(gen);
		std::cout << " \n\n	Die one is : " << static_cast<int>(dieRollOne) << "\n";
		std::cout << "	Die two is : " << static_cast<int>(dieRollTwo) << "\n";
		dieResult = { dieRollOne, dieRollTwo, dieRollThree, dieRollFour, dieRollFive };
		return dieResult;
	}

	void RunGuess(int& aCurrentBudget, int& aPlayerBet, bool& isGameActive, 
		std::array<std::array<std::string, 2>, 6>& aStatisticLst) 
	{
		int guessProfitLoss = 0, usrGuess = 0, dieSumInt = 0;
		const short UPER_LIMIT = 1000, LOWER_LIMIT = -1000, MULTIPLE_TWO = 2;
		bool isKeepPlaying = true, isPlayerLegit = true;
		const char gameName[]{ "Guess" };
		uint8_t* ptrDieResult{ nullptr };

		while (isKeepPlaying && isGameActive)
		{
			system("cls"), bufferTools::ClearInputBuffer();
			scoreboard::BettingDialouge(aCurrentBudget, aPlayerBet);
			usrGuess = GetUserGuess();
			std::cout << "\n	Your choice is : " << usrGuess;
			ptrDieResult = Get5DieResult().data();
		    dieSumInt = static_cast<int>(ptrDieResult[0]) + static_cast<int>(ptrDieResult[1]);
			std::cout << "\n	The sum is : " << dieSumInt;
			aCurrentBudget = (dieSumInt == usrGuess) ? (aCurrentBudget + aPlayerBet * MULTIPLE_TWO) : (aCurrentBudget - aPlayerBet);
			guessProfitLoss = (dieSumInt == usrGuess) ? (guessProfitLoss + aPlayerBet * MULTIPLE_TWO) : (guessProfitLoss - aPlayerBet);
			(dieSumInt == usrGuess) ? (std::cout << "\n	Daniel: Congratulation bro! You won!\n\tYour budget increased to " << aCurrentBudget << '\n') :
				(std::cout << "\n	Daniel: Sorry man, you lost!");
			scoreboard::CheckCurrentGameLimit(gameName, &guessProfitLoss, isPlayerLegit, isKeepPlaying, UPER_LIMIT, LOWER_LIMIT, aStatisticLst);
			scoreboard::CheckBudget(aCurrentBudget, isGameActive);
			aPlayerBet = 0;
			bufferTools::PlayOrExit(gameName, guessProfitLoss, isGameActive, isKeepPlaying, isPlayerLegit, aStatisticLst);
		}
		system("pause");

	}


}