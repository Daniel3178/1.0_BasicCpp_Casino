#pragma once
#include "OddOrEven.h"
#include "BufferTools.h"
#include "Scoreboard.h"
#include "Guess.h"
#include "Menu.h"
namespace oddOrEven {

	void RunEvenOrOdd(int& aCurrentBudget, int& aPlayerBet, bool& isGameActive,
		std::array<std::array<std::string, 2>, 6>& aStatisticLst) 
	{
		int oddOrEvenProfitLoss = 0;
		const short UPER_LIMIT = 1000, LOWER_LIMIT = -1000;
		bool isKeepPlaying = true, isPlayerLegit = true, flag = false;
		char usrGuess = 0;
		const char gameName[]{ "Odd/Even" };
		uint8_t* dieResult{ nullptr };

		while (isKeepPlaying && isGameActive) 
		{
			system("cls"), bufferTools::ClearInputBuffer();
			scoreboard::BettingDialouge(aCurrentBudget, aPlayerBet);
			std::cout << "\n\tDo you want to bet on even or odd number? answer with [e/o]: ";
			usrGuess = bufferTools::GetUserCharInput(static_cast<uint8_t>(bufferTools::CharInputOption::EvenOrOddChoice));
			(usrGuess == 'o') ? (std::cout << "\n	You have bet on an odd number!" << '\n') :
				(std::cout << "\n	You have bet on an even number!" << '\n');
			dieResult = guess::Get5DieResult().data();
			flag = ((dieResult[0] % 2 == 0 && dieResult[1] % 2 == 0 && usrGuess == 'e') ||
				(dieResult[0] % 2 != 0 && dieResult[1] % 2 != 0 && usrGuess == 'o')) ? true : false;
			aCurrentBudget = (flag) ? (aCurrentBudget + aPlayerBet * 2) : (aCurrentBudget - aPlayerBet);
			oddOrEvenProfitLoss = (flag) ? (oddOrEvenProfitLoss + aPlayerBet *2) : (oddOrEvenProfitLoss - aPlayerBet);
			(flag) ? (std::cout << "\n	Daniel: Congratulation bro! You won!\n\tYour budget increased to " << aCurrentBudget << '\n')
				: (std::cout << "\n	Daniel: Sorry man, you lost!");
			scoreboard::CheckCurrentGameLimit(gameName, &oddOrEvenProfitLoss, isPlayerLegit, isKeepPlaying, UPER_LIMIT, LOWER_LIMIT, aStatisticLst);
			scoreboard::CheckBudget(aCurrentBudget, isGameActive);
			aPlayerBet = 0;
			bufferTools::PlayOrExit(gameName, oddOrEvenProfitLoss, isGameActive, isKeepPlaying, isPlayerLegit, aStatisticLst);
		}
		system("pause");
	}
}