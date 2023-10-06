#include "OddOrEven.h"

namespace casino
{
	OddOrEven::OddOrEven(uint16_t aMinimumBet, uint16_t aMaximumBet) :
		CasinoGames::CasinoGames(aMinimumBet, aMaximumBet)
	{
		CasinoGames::maxProfit = (aMaximumBet - aMinimumBet) * 2;
		CasinoGames::minLoss = (aMaximumBet - aMinimumBet) * (-1);
		CasinoGames::gameName = "OddOrEven";
	}

	void OddOrEven::Run(Player* aPlayer, bool& isGameActive,
		std::array<std::array<std::string, 2>, 6>& aStatisticLst)
	{

		aPlayer->SetPlayerPlayingState(true);
		aPlayer->SetPlayerLegit(true);
		bool flag{ false };
		char playerGuess{ 0 };
		uint8_t* dieResult{ nullptr };

		while (aPlayer->GetPlayerPlaying() && isGameActive)
		{
			system("cls"), bufferTools::ClearInputBuffer();
			BettingDialouge(aPlayer, this);
			std::cout << "\n\tDo you want to bet on even or odd number? answer with [e/o]: ";
			playerGuess = bufferTools::GetPlayerCharAnswer(static_cast<uint8_t>(bufferTools::CharInputOption::EvenOrOddChoice));
			(playerGuess == 'o') ? (std::cout << "\n	You have bet on an odd number!" << '\n') :
				(std::cout << "\n	You have bet on an even number!" << '\n');
			dieResult = dice::Get5DiceResult().data();
			flag = ((dieResult[0] % 2 == 0 && dieResult[1] % 2 == 0 && playerGuess == 'e') ||
				(dieResult[0] % 2 != 0 && dieResult[1] % 2 != 0 && playerGuess == 'o')) ? true : false;
			(flag) ? aPlayer->IncreasePlayerTotalBudget(aPlayer->GetPlayerBet() * 2) 
				: aPlayer->DecreasePlayerTotalBudget(aPlayer->GetPlayerBet());
			(flag) ? IncreaseProfitLoss(aPlayer->GetPlayerBet()*2) : DecreaseProfitLoss(aPlayer->GetPlayerBet());
			(flag) ? (std::cout << "\n	Daniel: Congratulation bro! You won!\n\tYour budget increased to " << aPlayer->GetPlayerTotalBudget() << '\n')
				: (std::cout << "\n	Daniel: Sorry man, you lost!");
			statistics::CheckCurrentGameLimit(aPlayer, this, aStatisticLst);
			statistics::CheckBudget(aPlayer, isGameActive);
			aPlayer->SetPlayerBet( 0);
			PlayOrExit(aPlayer, isGameActive, aStatisticLst);
		}
		system("pause");
	}

	void OddOrEven::PlayOrExit(Player* aPlayer, bool& isGameActive,
		std::array<std::array<std::string, 2>, 6>& aStatisticLst)
	{
		CasinoGames::PlayOrExit( aPlayer,  isGameActive,
			aStatisticLst);
	}

	void OddOrEven::BettingDialouge(casino::Player* aPlayer, casino::CasinoGames* aGame)
	{
		CasinoGames::BettingDialouge(aPlayer, aGame);
	}

	void OddOrEven::DisplayRules(casino::Player* aPlayer)
	{
		std::cout << "\n\t These are the rules for oddOrEven game\n";

	}

}