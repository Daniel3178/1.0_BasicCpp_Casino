#pragma once
#include "Statistics.h"
namespace statistics
{
	void DisplayStatistic(std::array<std::array<std::string, 2>, 6>& aStatisticLst)
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

	void SaveStatistic(std::string* aGameName, const std::string* aStatistic, std::array<std::array<std::string, 2>, 6>& aStatisticLst)
	{
		for (uint8_t i = 5; i >= 2; i--)
		{
			aStatisticLst[i][0] = aStatisticLst[static_cast<uint8_t>(i - 1)][0];
			aStatisticLst[i][1] = aStatisticLst[static_cast<uint8_t>(i - 1)][1];
		}
		aStatisticLst[1][0] = *aGameName;
		aStatisticLst[1][1] = *aStatistic;
	}

	void CheckCurrentGameLimit(casino::Player* aPlayer, casino::CasinoGames* aGame,
		std::array<std::array<std::string, 2>, 6>& aStatisticLst)
	{
		std::string profitLossStr = bufferTools::IntToString(aGame->GetProfitloss());
		std::string gameName = aGame->GetGameName();
		if (aGame->GetProfitloss() >= aGame->GetMax() || aGame->GetProfitloss() <= aGame->GetMin())
		{
			aGame->GetProfitloss() >= aGame->GetMax() ? (std::cout << "\n\tYou are not allowed to continue this game due to too much profit" << '\n') :
				(std::cout << "\n\tYou are not allowed to continue this game due to too much losses" << '\n');
			SaveStatistic(&gameName, &profitLossStr, aStatisticLst);
			aPlayer->SetPlayerPlayingState(false);
			aPlayer->SetPlayerLegit(false);
			aGame->SetProfitLoss(0);
			system("pause");
		}
	}

	void CheckBudget(casino::Player* aPlayer, bool& isGameActive)
	{
		if (aPlayer->GetPlayerTotalBudget() <= 0) {
			std::cout << "	\n\tYou ran out of money!\n\tThe escort will lead you out... \n";
			isGameActive = false;
		}
	}
}
