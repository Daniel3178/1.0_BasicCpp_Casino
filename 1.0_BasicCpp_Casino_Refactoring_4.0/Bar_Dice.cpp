#include "Bar_Dice.h"

namespace casino
{
	
	Bar_Dice::Bar_Dice(uint16_t aMinimumBet, uint16_t aMaximumBet) :
		CasinoGames::CasinoGames(aMinimumBet, aMaximumBet)
	{
		maxProfit = (aMaximumBet - aMinimumBet) * 2;
		minLoss = (aMaximumBet - aMinimumBet) * (-1);
		gameName = "Bar_Dice";
	}

	void Bar_Dice::PlayOrExit(Player* aPlayer, bool& isGameActive,
		std::array<std::array<std::string, 2>, 6>& aStatisticLst)
	{
		CasinoGames::PlayOrExit(aPlayer, isGameActive, aStatisticLst);
	}

	void Bar_Dice::Run(Player* aPlayer, bool& isGameActive,
		std::array<std::array<std::string, 2>, 6>& aStatisticLst)
	{

	int botResult = 0, usrResult = 0;
	const short DRINK_PRICE = 50;
	aPlayer->SetPlayerPlayingState(true);
	aPlayer->SetPlayerLegit(true);
	
	while (aPlayer->GetPlayerPlaying() && isGameActive)
	{
		system("cls"), bufferTools::ClearInputBuffer();

		botResult = dice::GetBotPlayerDiceSum(), usrResult = dice::GetPlayerDiceSum(aPlayer);
		if (botResult < usrResult)
		{
			std::cout << "\n	Daniel: Damn! I'll swish you the money!";
			aPlayer->IncreasePlayerTotalBudget(DRINK_PRICE); 
			IncreaseProfitLoss(DRINK_PRICE);
			statistics::CheckCurrentGameLimit(aPlayer, this, aStatisticLst);
			std::cout << "\n\tYour budget increased to " << aPlayer->GetPlayerTotalBudget() << '\n';
		}
		else if (botResult > usrResult)
		{
			std::cout << "\n	Daniel: Sorry man, I will watch you paying for my drink!";
			aPlayer->DecreasePlayerTotalBudget(DRINK_PRICE);
			DecreaseProfitLoss(DRINK_PRICE);
			statistics::CheckCurrentGameLimit(aPlayer, this, aStatisticLst);
			statistics::CheckBudget(aPlayer, isGameActive);
		}
		else
		{
			std::cout << "\n	Daniel: Let's do it one more time!";
		}
		PlayOrExit(aPlayer, isGameActive, aStatisticLst);
	}
	system("pause");

	}

	void Bar_Dice::DisplayRules(casino::Player* aPlayer)
	{
		std::cout << "\n\t These are the rules for Bar_Dice game\n";
	}
}