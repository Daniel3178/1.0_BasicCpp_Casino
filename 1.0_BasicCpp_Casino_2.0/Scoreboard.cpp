#pragma once
#include "Scoreboard.h"
#include "BufferTools.h"

namespace scoreboard {

	void BettingDialouge(int& aBudget, int& aBet) 
	{
		std::cout << "\n	Your current budget is: " << aBudget;
		std::cout << "\n	Please enter the amount you want to bet: ";
		bool isAccepted{ false };
		do {
			aBet = bufferTools::GetUserIntFormat();
			isAccepted = (!(aBet <= aBudget && aBet > 0)) ? false : true;
			if (!isAccepted) 
			{
				system("cls");
				std::cout << "Remeber, you are only allowed to bet above 0$ and less than the maximum budget!" << '\n';
			}
			if (aBet == aBudget) {
				std::cout << "\n	Warning! you are about to go all in!!" << '\n';
			}
		} while (!isAccepted);
	}

	void CheckBudget(int& aBudget, bool& isGameActive) {
		if (aBudget <= 0) {
			std::cout << "	\n\tYou ran out of money!\n\tThe escort will lead you out... \n";
			isGameActive = false;
		}
	}

	void DisplayScores(std::array<std::array<std::string, 2>, 6>& aStatisticLst) 
	{
		for (int i = 0; i < aStatisticLst.size(); i++)
		{
			for (int j = 0; j < aStatisticLst[0].size(); j++)
			{
				(aStatisticLst[i][j] == "Guess") ? (std::cout << "\t" << aStatisticLst[i][j] << "\t\t") :
					(std::cout << "\t" << aStatisticLst[i][j] << "\t");
			}
			std::cout << '\n';
		}
	}

	void SaveStatistics(std::string aGameName, std::string aScore, std::array<std::array<std::string, 2>, 6>& aStatisticLst)
	{
		for (uint8_t i = 5; i >= 2; i--)
		{
			aStatisticLst[i][0] = aStatisticLst[static_cast<uint8_t>(i - 1)][0];
			aStatisticLst[i][1] = aStatisticLst[static_cast<uint8_t>(i - 1)][1];
		}
		aStatisticLst[1][0] = aGameName;
		aStatisticLst[1][1] = aScore;
	}

	void CheckCurrentGameLimit(const char aGameName[], int* aProfitLoss, bool& aPlayerState, bool& aKeepPlayingState, const short& anUperLimit, const short& anLowerLimit,
		std::array<std::array<std::string, 2>, 6>& aStatisticLst) 
	{
		if (*aProfitLoss >= anUperLimit || *aProfitLoss <= anLowerLimit)
		{
			(*aProfitLoss >= anUperLimit) ? (std::cout << "\n\tYou are not allowed to continue this game due to too much profit" << '\n') :
				(std::cout << "\n\tYou are not allowed to continue this game due to too much losses" << '\n');
			scoreboard::SaveStatistics(aGameName, bufferTools::IntToString(*aProfitLoss), aStatisticLst);
			aKeepPlayingState = false, aPlayerState = false, * aProfitLoss = 0;
			system("pause");
		}
	}

	void RunBoard(std::array<std::array<std::string, 2>, 6>& aStatisticLst) 
	{
		bool isExitPressed{ false };
		char usrOpt{ 'n' };
		do {
			system("cls");
			DisplayScores(aStatisticLst);
			std::cout << "\n\n	Press [x] to exit: ";
			usrOpt = bufferTools::GetUserCharFormat();
			isExitPressed = (!(usrOpt == 'x' || usrOpt == 'X')) ? false : true;
		} while (!isExitPressed);
		system("pause");
	}
}