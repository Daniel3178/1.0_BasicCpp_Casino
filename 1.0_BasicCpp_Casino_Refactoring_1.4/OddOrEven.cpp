#pragma once
#include "OddOrEven.h"
#include "BufferTools.h"
#include "Scoreboard.h"
#include "Guess.h"
#include "Menu.h"
namespace oddOrEven {

	void RunEvenOrOdd(int& aCurrentBudget, int& aPlayerBet, bool& isGameActive,
		std::array<std::array<std::string, 2>, 6>& aStatisticLst, const unsigned char aRow) 
	{
		int oddOrEvenProfitLoss = 0;
		const short UPER_LIMIT = 1000, LOWER_LIMIT = -1000;
		bool isKeepPlaying = true, isPlayerLegit = true;
		char usrGuess = 0;
		std::string gameName = "Odd/Even", dieSumStr ="";

		while (isKeepPlaying && isGameActive) 
		{
			system("cls"), bufferTools::ClearInputBuffer();
			scoreboard::BettingDialouge(aCurrentBudget, aPlayerBet);
			std::cout << "\n\tDo you want to bet on even or odd number? answer with [e/o]: ";
			usrGuess = bufferTools::GetUserCharInput(static_cast<unsigned char>(bufferTools::CharInputOption::EvenOrOddChoice));
			
			if (usrGuess == 'o') 
			{
				std::cout << "\n	You have bet on an odd number!" << '\n';
			}
			else 
			{
				std::cout << "\n	You have bet on an even number!" << '\n';
			}
		    dieSumStr = guess::GetDieSum();

			if ((static_cast<int>(dieSumStr[0] % 2) == 0 && static_cast<int>(dieSumStr[1] % 2) == 0 && usrGuess == 'e') ||
				(static_cast<int>(dieSumStr[0] % 2) != 0 && static_cast<int>(dieSumStr[1] % 2) != 0 && usrGuess == 'o'))
			{
				std::cout << "\n	Daniel: Congratulation bro! You won!";
				aCurrentBudget += aPlayerBet * 2, oddOrEvenProfitLoss += aPlayerBet, aPlayerBet = 0;
				scoreboard::CheckCurrentGameLimit(gameName, &oddOrEvenProfitLoss, isPlayerLegit, isKeepPlaying, UPER_LIMIT, LOWER_LIMIT, aStatisticLst, aRow);
				std::cout << "\n\tYour budget increased to " << aCurrentBudget << '\n';
			}
			else
			{
				std::cout << "\n	Daniel: Sorry man, you lost!";
				aCurrentBudget -= aPlayerBet, oddOrEvenProfitLoss -= aPlayerBet, aPlayerBet = 0;
				scoreboard::CheckCurrentGameLimit(gameName, &oddOrEvenProfitLoss, isPlayerLegit, isKeepPlaying, UPER_LIMIT, LOWER_LIMIT, aStatisticLst, aRow);
				scoreboard::CheckBudget(aCurrentBudget, isGameActive);
			}
			bufferTools::PlayOrExit(gameName, oddOrEvenProfitLoss, isGameActive, isKeepPlaying, isPlayerLegit, aStatisticLst, aRow);
		}
		system("pause");
	}
}