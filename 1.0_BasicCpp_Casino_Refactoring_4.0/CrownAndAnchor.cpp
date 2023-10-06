#include "CrownAndAnchor.h"

namespace casino
{
	CrownAndAnchor::CrownAndAnchor(uint16_t aMinimumBet, uint16_t aMaximumBet) :
		CasinoGames::CasinoGames(aMinimumBet, aMaximumBet)
	{
		CasinoGames::maxProfit = (aMaximumBet - aMinimumBet) * 2;
		CasinoGames::minLoss = (aMaximumBet - aMinimumBet) * (-1);
		CasinoGames::gameName = "CrownAndAnchor";
	}

	void CrownAndAnchor::PlayOrExit(casino::Player* aPlayer, bool& isGameActive,
		std::array<std::array<std::string, 2>, 6>& aStatisticLst)
	{
		PlayOrExit(aPlayer, isGameActive, aStatisticLst);
	}

	void CrownAndAnchor::Run(casino::Player* aPlayer, bool& isGameActive,
		std::array<std::array<std::string, 2>, 6>& aStatisticLst)
	{
		uint8_t playerGuess{0}, counter{0};
		const char gameName[]{ "CrownAndAnchor" };
		uint8_t* dieResult{ nullptr };

		while (aPlayer->GetPlayerPlaying() && isGameActive)
		{
			system("cls");
			bufferTools::ClearInputBuffer();
			std::cout << "\tPress[1] :: Crown (.) \n\tPress[2] :: Anchor (:) \n\tPress[3] :: Diamond (:.)" <<
				" \n\tPress[4] ::Spade(::) \n\tPress[5] ::Heart(:. : ) \n\tPress[6] ::Club(:::)" << '\n';
			std::cout << "\n\tWhat symbole do you want to bet on: ";
			playerGuess = bufferTools::GetPlayerIntFormat(); //alt GetUserIntFormat
			BettingDialouge(aPlayer, this);
			std::cout << "\n	You have bet on " << playerGuess << '\n';
			dieResult = dice::Get5DiceResult().data();
			std::cout << "\tDie three is : " << static_cast<int>(dieResult[2]) << '\n';

			for (char i = 0; i < 3; i++)
			{
				counter += (dieResult[i] == playerGuess) ? 1 : 0;
			}

			(counter) ? aPlayer->IncreasePlayerTotalBudget(aPlayer->GetPlayerBet() * counter)
				: (aPlayer->DecreasePlayerTotalBudget(aPlayer->GetPlayerBet()));
			(counter) ? IncreaseProfitLoss( aPlayer->GetPlayerBet() * counter) : DecreaseProfitLoss(aPlayer->GetPlayerBet());
			(counter) ? (std::cout << "\n	Daniel: Congratulation bro! You won!\n\tYour budget increased to " << aPlayer->GetPlayerTotalBudget() << '\n')
				: (std::cout << "\n	Daniel: Sorry man, you lost!");
			statistics::CheckCurrentGameLimit(aPlayer, this, aStatisticLst);
			statistics::CheckBudget(aPlayer, isGameActive);
			aPlayer->SetPlayerBet(0);
			counter = 0;
			PlayOrExit(aPlayer, isGameActive, aStatisticLst);
		}
	}

	void CrownAndAnchor::BettingDialouge(casino::Player* aPlayer, casino::CasinoGames* aGame)
	{
		CasinoGames::BettingDialouge(aPlayer, aGame);
	}

	void CrownAndAnchor::DisplayRules(casino::Player* aPlayer)
	{
		std::cout << "\n\t These are the rules for crownAndAnchor game\n";
	}
}