#include "CrownAndAnchor.h"
#include "BufferTools.h"
#include "Scoreboard.h"
#include "Guess.h"


namespace crownAndAnchor {

	void RunCrownAndAnchor(int& aCurrentBudget, int& aPlayerBet, bool& isGameActive,
		std::array<std::array<std::string, 2>, 6>& aStatisticLst, const unsigned char aRow) 
	{
		int crownAndAnchorProfitLoss = 0;
		const short UPER_LIMIT = 1000, LOWER_LIMIT = -1000;
		bool isKeepPlaying = true, isPlayerLegit = true;
	    char counter = 0, usrGuess = 0;
		std::string gameName = "CrownAndAnchor", dieSumStr = "";

		while (isKeepPlaying && isGameActive) 
		{
			system("cls");
			bufferTools::ClearInputBuffer();
			std::cout << "\tPress[1] :: Crown (.) \n\tPress[2] :: Anchor (:) \n\tPress[3] :: Diamond (:.)"<<
				" \n\tPress[4] ::Spade(::) \n\tPress[5] ::Heart(:. : ) \n\tPress[6] ::Club(:::)" << '\n';
			std::cout << "\n\tWhat symbole do you want to bet on: ";
			usrGuess = bufferTools::GetUserCharInput(static_cast<unsigned char>(bufferTools::CharInputOption::CrownAndAnchorSymbolChoice));
			scoreboard::BettingDialouge(aCurrentBudget, aPlayerBet);
			std::cout << "\n	You have bet on " << usrGuess << '\n';
			dieSumStr = guess::GetDieSum();
			std::cout << "\tDie three is : " << static_cast<int>(dieSumStr[2]) << '\n';

			for (char i = 0; i < 3; i++) 
			{
				if (dieSumStr[i] == usrGuess - 48) 
				{
					counter++;
				}
			}

			if (counter) 
			{
				std::cout << "\n	Daniel: Congratulation bro! You won!";
				aCurrentBudget += aPlayerBet * counter, crownAndAnchorProfitLoss += aPlayerBet * counter, aPlayerBet = 0, counter = 0;
				std::cout << "\n\tYour budget increased to " << aCurrentBudget << '\n';
				scoreboard::CheckCurrentGameLimit(gameName, &crownAndAnchorProfitLoss, isPlayerLegit, isKeepPlaying, UPER_LIMIT, LOWER_LIMIT, aStatisticLst, aRow);
			}

			else 
			{
				std::cout << "\n	Daniel: Sorry man, you lost!";
				aCurrentBudget -= aPlayerBet, crownAndAnchorProfitLoss -= aPlayerBet, aPlayerBet = 0, counter = 0;
				scoreboard::CheckCurrentGameLimit(gameName, &crownAndAnchorProfitLoss, isPlayerLegit, isKeepPlaying, UPER_LIMIT, LOWER_LIMIT, aStatisticLst, aRow);
				scoreboard::CheckBudget(aCurrentBudget, isGameActive);
			}
			bufferTools::PlayOrExit(gameName, crownAndAnchorProfitLoss, isGameActive, isKeepPlaying, isPlayerLegit, aStatisticLst, aRow);
		}

	}
}