#include "Guess.h"
namespace casino
{
	Guess::Guess(uint16_t aMinimumBet, uint16_t aMaximumBet) :
		CasinoGames::CasinoGames(aMinimumBet, aMaximumBet)
	{
		CasinoGames::maxProfit = (aMaximumBet - aMinimumBet) * 2;
		CasinoGames::minLoss = (aMaximumBet - aMinimumBet) * (-1);
		CasinoGames::gameName = "Guess";
	}

	void Guess::PlayOrExit(Player* aPlayer, bool& isGameActive,
		std::array<std::array<std::string, 2>, 6>& aStatisticLst)
	{
		CasinoGames::PlayOrExit(aPlayer, isGameActive,
			aStatisticLst);

	}
	void Guess::Run(casino::Player* aPlayer, bool& isGameActive,
		std::array<std::array<std::string, 2>, 6>& aStatisticLst)
	{
		uint8_t playerGuess{ 0 }, dieSum{ 0 };
		const uint8_t FACTOR_TWO{ 2 };
		aPlayer->SetPlayerPlayingState(true);
		aPlayer->SetPlayerLegit(true);
		uint8_t* ptrDieResult{ nullptr };

		while (aPlayer->GetPlayerPlaying() && isGameActive)
		{
			system("cls"), bufferTools::ClearInputBuffer();
			BettingDialouge(aPlayer, this);
			playerGuess = bufferTools::GetPlayerIntGuess(aPlayer);
			std::cout << "\n	Your choice is : " << (int)playerGuess;
			ptrDieResult = dice::Get5DiceResult().data();
			dieSum = ptrDieResult[0] + ptrDieResult[1];
			std::cout << "\n	The sum is : " << static_cast<int>(dieSum);
			(dieSum == playerGuess) ? aPlayer->IncreasePlayerTotalBudget(aPlayer->GetPlayerBet() * FACTOR_TWO)
				: aPlayer->DecreasePlayerTotalBudget(aPlayer->GetPlayerBet());
			(dieSum == playerGuess) ? IncreaseProfitLoss(aPlayer->GetPlayerBet() * FACTOR_TWO)
				: DecreaseProfitLoss(aPlayer->GetPlayerBet());
			(dieSum == playerGuess) ? (std::cout << "\n	Daniel: Congratulation bro! You won!\n\tYour budget increased to " << aPlayer->GetPlayerTotalBudget() << '\n') :
				(std::cout << "\n	Daniel: Sorry man, you lost!");
			statistics::CheckCurrentGameLimit(aPlayer, this, aStatisticLst);
			statistics::CheckBudget(aPlayer, isGameActive);
			aPlayer->SetPlayerBet(0);
			PlayOrExit(aPlayer, isGameActive, aStatisticLst);
		}
		system("pause");
	}
	void Guess::BettingDialouge(casino::Player* aPlayer, casino::CasinoGames* aGame)
	{
		int aBet{ 0 };
		std::cout << "\n	Okay " << aPlayer->GetPlayerName() <<
			"your current budget is : " << aPlayer->GetPlayerTotalBudget();
		std::cout << "\n	Please enter the amount you want to bet: ";
		bool isAccepted{ false };
		do {

			aBet = bufferTools::GetPlayerIntFormat();
			isAccepted = (!(aBet <= aPlayer->GetPlayerTotalBudget() && aBet > 0) ||
				!(aBet <= aGame->GetMax() && aBet >= aGame->GetMin())) ? false : true;
			if (!isAccepted)
			{
				system("cls");
				std::cout << "\n\t Please pay attention to the minimum and maximum amount that you can bet\n\t " <<
					"For this game the minimum amount is " << aGame->GetMin() << " and the maximum is "<<
					aGame->GetMax()<<'\n';

			}
			if (aBet == aPlayer->GetPlayerTotalBudget()) {
				std::cout << "\n	Warning! you are about to go all in!!" << '\n';
			}
		} while (!isAccepted);
		aPlayer->SetPlayerBet(aBet);
	}
	void Guess::DisplayRules(casino::Player* aPlayer)
	{
		std::cout << "\n\t These are the rules for guessing game\n";
	}
}