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
			isAccepted = true;
			aBet = bufferTools::GetUserIntFormat();
			if (!(aBet <= aBudget && aBet > 0)) 
			{
				system("cls");
				std::cout << "Remeber, you are only allowed to bet above 0$ and less than the maximum budget!" << '\n';
				isAccepted = false;
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
	void DisplayScores(std::array<std::array<std::string, 2>, 6>& aStatisticLst, const unsigned char aRow, const unsigned char aColumn) 
	{
		for (int i = 0; i < aRow; i++)
		{
			for (int j = 0; j < aColumn; j++)
			{
				if (aStatisticLst[i][j] == "Guess")
				{
					std::cout << "\t" << aStatisticLst[i][j] << "\t\t";
				}
				else
				{
					std::cout << "\t" << aStatisticLst[i][j] << "\t";
				}
			}
			std::cout << '\n';
		}
	}

	void SaveStatistics(std::string aGameName, std::string aScore, std::array<std::array<std::string, 2>, 6>& aStatisticLst, const unsigned char aRow)
	{
		for (unsigned char i = 5; i >= 2; i--)
		{
			aStatisticLst[i][0] = aStatisticLst[static_cast<unsigned char>(i - 1)][0];
			aStatisticLst[i][1] = aStatisticLst[static_cast<unsigned char>(i - 1)][1];
		}
		aStatisticLst[1][0] = aGameName;
		aStatisticLst[1][1] = aScore;
	}



	void CheckCurrentGameLimit(std::string aGameName, int* aProfitLoss, bool& aPlayerState, bool& aKeepPlayingState, const short& anUperLimit, const short& anLowerLimit,
		std::array<std::array<std::string, 2>, 6>& aStatisticLst, const unsigned char aRow) 
	{
		if (*aProfitLoss >= anUperLimit || *aProfitLoss <= anLowerLimit)
		{
			if (*aProfitLoss >= anUperLimit)
			{
				std::cout << "\n\tYou are not allowed to continue this game due to too much profit" << '\n';
			}
			else 
			{
				std::cout << "\n\tYou are not allowed to continue this game due to too much losses" << '\n';
			}
			scoreboard::SaveStatistics(aGameName, bufferTools::IntToString(*aProfitLoss), aStatisticLst, aRow);
			aKeepPlayingState = false, aPlayerState = false, * aProfitLoss = 0;
			system("pause");
		}
	}

	void RunBoard(std::array<std::array<std::string, 2>, 6>& aStatisticLst, const unsigned char aRow, const unsigned char aColumn) 
	{
		bool isExitPressed{ false };
		char usrOpt{ 'n' };
		do {
			isExitPressed = true;
			system("cls");
			DisplayScores(aStatisticLst, aRow, aColumn);
			std::cout << "\n\n	Press [x] to exit: ";
			isExitPressed = true;
			usrOpt = bufferTools::GetUserCharFormat();
			if (!(usrOpt == 'x' || usrOpt == 'X')) 
			{
				isExitPressed = false;
			}
		} while (!isExitPressed);
		system("pause");
	}
}