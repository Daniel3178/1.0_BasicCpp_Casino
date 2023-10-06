#include "CasinoGames.h"

namespace casino
{
	CasinoGames::CasinoGames(uint16_t aMinimumBet, uint16_t aMaximumBet) :
		profitLoss(0), lowestPossibleBet(aMinimumBet), highestPossibleBet(aMaximumBet),
		maxProfit(0), minLoss(0), gameName("")
	{
	}

	const int16_t CasinoGames::GetMax() const
	{
		return maxProfit;
	}
	const int16_t CasinoGames::GetMin() const
	{
		return minLoss;
	}
	void CasinoGames::SetProfitLoss(const int aValue)
	{
		profitLoss = aValue;
	}
	void CasinoGames::IncreaseProfitLoss(const int aValue)
	{
		profitLoss += aValue;


	}
	void CasinoGames::DecreaseProfitLoss(const int aValue)
	{
		profitLoss -= aValue;
	}
	const int CasinoGames::GetProfitloss() const
	{
		return profitLoss;
	}
	void CasinoGames::PlayOrExit(Player* aPlayer, bool& isGameActive,
		std::array<std::array<std::string, 2>, 6>& aStatisticLst)
	{
		if (aPlayer->GetPlayerLegit() && isGameActive)
		{
			std::string profitLossStr = bufferTools::IntToString(GetProfitloss());
			std::cout << "\n\n\n";
			std::cout << "	Press [1] :: Play this game again" << '\n';
			std::cout << "	Press [2] :: Exit this game" << '\n';
			std::cout << "	Press [3] :: Exit the Casino" << '\n';
			std::cout << "	Your choice: ";
			char usrInput{ 0 };
			bool isAccepted{ false };
			do
			{
				isAccepted = true;
				usrInput = bufferTools::GetPlayerIntFormat();
				if (!(usrInput == 1 || usrInput == 2 || usrInput == 3))
				{
					system("cls");
					std::cout << "Your choices are 1, 2 or 3 " << '\n';
					isAccepted = false;
				}
			} while (!isAccepted);

			switch (usrInput)
			{
			case 1:
				return;
				break;
			case 2:
				aPlayer->SetPlayerPlayingState(false);
				statistics::SaveStatistic(&gameName, &profitLossStr, aStatisticLst);
				return;
				break;
			case 3:
				system("cls");
				std::cout << "Good Bye" << '\n';
				isGameActive = false;
				return;
				break;
			}
		}

	}
	void CasinoGames::BettingDialouge(casino::Player* aPlayer, casino::CasinoGames* aGame)
	{
		int aBet{ 0 };
		std::cout << "\n	Okay " << aPlayer->GetPlayerName() <<
			"your current budget is : " << aPlayer->GetPlayerTotalBudget();
		std::cout << "\n	Please enter the amount you want to bet: ";
		bool isAccepted{ false };
		do {

			aBet = bufferTools::GetPlayerIntFormat();
			isAccepted = (!(aBet <= aPlayer->GetPlayerTotalBudget() && aBet > 0)) ? false : true;
			if (!isAccepted)
			{
				system("cls");
				std::cout << "Remeber, you are only allowed to bet above 0$ and less than the maximum budget!" << '\n';
			}
			if (aBet == aPlayer->GetPlayerTotalBudget()) {
				std::cout << "\n	Warning! you are about to go all in!!" << '\n';
			}
		} while (!isAccepted);
		aPlayer->SetPlayerBet(aBet);

	}

	void CasinoGames::DisplayRules(casino::Player* aPlayer)
	{
		std::cout << "\n\t This is general rules!\n";
	}
	std::string CasinoGames::GetGameName() const
	{
		return gameName;
	}
	void CasinoGames::Run(Player* aPlayer, bool& isGameActive,
		std::array<std::array<std::string, 2>, 6>& aStatisticLst)
	{
	}
}