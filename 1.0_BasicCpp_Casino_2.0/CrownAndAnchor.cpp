#include "CrownAndAnchor.h"
#include "BufferTools.h"
#include "Scoreboard.h"
#include "Guess.h"


namespace crownAndAnchor {

	void RunCrownAndAnchor(int& aCurrentBudget, int& aPlayerBet, bool& isGameActive,
		std::array<std::array<std::string, 2>, 6>& aStatisticLst) 
	{
		int crownAndAnchorProfitLoss = 0, usrGuess = 0;
		const short UPER_LIMIT = 1000, LOWER_LIMIT = -1000;
		bool isKeepPlaying = true, isPlayerLegit = true;
	    char counter = 0;
		const char gameName[]{ "CrownAndAnchor" };
		uint8_t* dieResult{ nullptr };

		while (isKeepPlaying && isGameActive) 
		{
			system("cls");
			bufferTools::ClearInputBuffer();
			std::cout << "\tPress[1] :: Crown (.) \n\tPress[2] :: Anchor (:) \n\tPress[3] :: Diamond (:.)"<<
				" \n\tPress[4] ::Spade(::) \n\tPress[5] ::Heart(:. : ) \n\tPress[6] ::Club(:::)" << '\n';
			std::cout << "\n\tWhat symbole do you want to bet on: ";
			usrGuess = bufferTools::GetUserIntFormat(); //alt GetUserIntFormat
			scoreboard::BettingDialouge(aCurrentBudget, aPlayerBet);
			std::cout << "\n	You have bet on " << usrGuess << '\n';
			dieResult = guess::Get5DieResult().data();
			std::cout << "\tDie three is : " << static_cast<int>(dieResult[2]) << '\n';

			for (char i = 0; i < 3; i++) 
			{
				counter += (dieResult[i] == usrGuess ) ? 1 : 0;
			}

			aCurrentBudget = (counter) ? (aCurrentBudget + aPlayerBet * counter) : (aCurrentBudget - aPlayerBet);
			crownAndAnchorProfitLoss = (counter) ? (crownAndAnchorProfitLoss + aPlayerBet * counter) : (crownAndAnchorProfitLoss - aPlayerBet);
			(counter) ? (std::cout << "\n	Daniel: Congratulation bro! You won!\n\tYour budget increased to " << aCurrentBudget << '\n')
				: (std::cout << "\n	Daniel: Sorry man, you lost!");
			scoreboard::CheckCurrentGameLimit(gameName, &crownAndAnchorProfitLoss, isPlayerLegit, isKeepPlaying, UPER_LIMIT, LOWER_LIMIT, aStatisticLst);
			scoreboard::CheckBudget(aCurrentBudget, isGameActive);
			aPlayerBet = 0, counter = 0;
			bufferTools::PlayOrExit(gameName, crownAndAnchorProfitLoss, isGameActive, isKeepPlaying, isPlayerLegit, aStatisticLst);
		}

	}
}