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

	std::string GetDieSum() 
	{
		std::string dieResult = "";
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> dis(1, 6);

		unsigned char dieRollOne = dis(gen), dieRollTwo = dis(gen), dieRollThree = dis(gen),dieRollFour = dis(gen), dieRollFive = dis(gen);
		std::cout << " \n\n	Die one is : " << static_cast<int>(dieRollOne) << "\n";
		std::cout << "	Die two is : " << static_cast<int>(dieRollTwo) << "\n";
		dieResult += dieRollOne, dieResult += dieRollTwo, dieResult += dieRollThree, dieResult += dieRollFour, dieResult += dieRollFive;
		return dieResult;
	}


	void RunGuess(int& aCurrentBudget, int& aPlayerBet, bool& isGameActive, 
		std::array<std::array<std::string, 2>, 6>& aStatisticLst, const unsigned char aRow) 
	{
		int guessProfitLoss = 0, usrGuess = 0, dieSumInt = 0;
		const short UPER_LIMIT = 1000, LOWER_LIMIT = -1000, MULTIPLE_TWO = 2;
		bool isKeepPlaying = true, isPlayerLegit = true;
		std::string gameName = "Guess", dieSumStr = "";

		while (isKeepPlaying && isGameActive)
		{
			system("cls"), bufferTools::ClearInputBuffer();
			scoreboard::BettingDialouge(aCurrentBudget, aPlayerBet);
			usrGuess = GetUserGuess();
			std::cout << "\n	Your choice is : " << usrGuess;
		    dieSumStr = GetDieSum();
		    dieSumInt = static_cast<int>(dieSumStr[0]) + static_cast<int>(dieSumStr[1]);
			std::cout << "\n	The sum is : " << dieSumInt;

			if (dieSumInt == usrGuess) 
			{
				std::cout << "\n	Daniel: Congratulation bro! You won!";
				aCurrentBudget += aPlayerBet * MULTIPLE_TWO, guessProfitLoss += aPlayerBet * MULTIPLE_TWO, aPlayerBet = 0;
				scoreboard::CheckCurrentGameLimit(gameName, &guessProfitLoss, isPlayerLegit, isKeepPlaying, UPER_LIMIT, LOWER_LIMIT, aStatisticLst, aRow);
				std::cout << "\n\tYour budget increased to " << aCurrentBudget << '\n';
			}
			else 
			{
				std::cout << "\n	Daniel: Sorry man, you lost!";
				aCurrentBudget -= aPlayerBet, guessProfitLoss -= aPlayerBet, aPlayerBet = 0;
				scoreboard::CheckCurrentGameLimit(gameName, &guessProfitLoss, isPlayerLegit, isKeepPlaying, UPER_LIMIT, LOWER_LIMIT, aStatisticLst, aRow);
				scoreboard::CheckBudget(aCurrentBudget, isGameActive);
			}
			bufferTools::PlayOrExit(gameName, guessProfitLoss, isGameActive, isKeepPlaying, isPlayerLegit, aStatisticLst, aRow);
		}
		system("pause");

	}


}