#pragma once
#include <iostream>
#include "BufferTools.h"
#include "Roulette.h"
#include "Scoreboard.h"
namespace roulette {

	void DisplayRouletteBoard()
	{

		std::cout
			<< "\n                                    -------------------------\n"
			<< "				    |           0           |\n"
			<< "                     	|------------------------------------\n"
			<< "                     	|           |   1   |  (2)  |   3   |\n"
			<< "                     	|           -------------------------\n"
			<< "                     	|    ODD    |  (4)  |   5   |  (6)  |\n"
			<< "                        |           -------------------------\n"
			<< "Press[1]::Straight  	|           |   7   |  (8)  |   9   |\n"
			<< "                     	|------------------------------------\n"
			<< "Press[2]::Red/(Black)	|           |  (10) |  (11) |   12  |\n"
			<< "                     	|           -------------------------\n"
			<< "Press[3]::Odd/Even     	|   EVEN    |  (13) |   14  |  (15) |\n"
			<< "               	    	|           -------------------------\n"
			<< "Press[4]::Column    	|           |   16  |  (17) |   18  |\n"
			<< "                     	|------------------------------------\n"
			<< "Press[5]::Split     	|           |   19  |  (20) |   21  |\n"
			<< "                     	|           -------------------------\n"
			<< "Press[6]::Corner    	|    RED    |  (22) |   23  |  (24) |\n"
			<< "                     	|           -------------------------\n"
			<< "                     	|           |   25  |  (26) |   27  |\n"
			<< "                     	|------------------------------------\n"
			<< "                     	|           |  (28) |  (29) |   30  |\n"
			<< "                     	|           -------------------------\n"
			<< "                     	|   BLACK   |  (31) |   32  |  (33) |\n"
			<< "                     	|           -------------------------\n"
			<< "                     	|           |   34  |  (35) |   36  |\n"
			<< "                     	|------------------------------------\n"
			<< "                     	|           |COL I  |COL II |COL III|\n"
			//<< "------------------------------------------\n"
			<< std::endl;
	}

	std::array<int8_t, 2> GetSplitSequence()
	{
		std::cout << "\n\t Please choose a number from the Roulette board: ";
		bool isAccepted{ false };
		int8_t usrFirstNum{ 0 }, usrSecondNum{ 0 };
		int8_t possibleNum3{ -1 }, possibleNum2{ -1 }, possibleNum1{ -1 }, possibleNum4{ -1 };
		std::array<int8_t, 2> result{ 0 };
		do {
			usrFirstNum = bufferTools::GetUserIntFormat();
			isAccepted = (!(usrFirstNum <= 36 && usrFirstNum >= 0)) ? false : true;
		} while (!isAccepted);

		if (usrFirstNum)
		{
			possibleNum2 = (usrFirstNum + 3 <= 36) ? usrFirstNum + 3 : -1;
			possibleNum1 = (usrFirstNum - 3 >= 0) ? usrFirstNum - 3 : -1;
			switch (usrFirstNum % 3)
			{
			case static_cast<uint8_t>(Column::Column1):
			{

				possibleNum3 = usrFirstNum + 1;
				std::cout << "\n\t Your possible choices are: " << (int)possibleNum3 << '\t' << ((!(possibleNum2 < 0)) ? bufferTools::IntToString(possibleNum2) : "") << '\t' <<
					((!(possibleNum1 < 0)) ? bufferTools::IntToString(possibleNum1) : "") << '\n';
				std::cout << "\t Please enter your choice: ";
				do {
					usrSecondNum = bufferTools::GetUserIntFormat();
					isAccepted = (!(usrSecondNum == possibleNum3 || usrSecondNum == possibleNum2 || usrSecondNum == possibleNum1)) ? false : true;
				} while (!isAccepted);
			}
				break;
			case static_cast<uint8_t>(Column::Column2):
			{

				possibleNum3 = usrFirstNum + 1;
				possibleNum4 = usrFirstNum - 1;
				std::cout << "\n\t Your possible choices are: " << (int)possibleNum3 << '\t' << ((!(possibleNum2 < 0)) ? bufferTools::IntToString(possibleNum2) : "") << '\t' <<
					((!(possibleNum1 < 0)) ? bufferTools::IntToString(possibleNum1) : "") << '\t' << (int)possibleNum4 << '\n';
				std::cout << "\t Please enter your choice: ";
				do {
					usrSecondNum = bufferTools::GetUserIntFormat();
					isAccepted = (!(usrSecondNum == possibleNum3 || usrSecondNum == possibleNum2 || usrSecondNum == possibleNum1 || usrSecondNum == possibleNum4)) ? false : true;
				} while (!isAccepted);
			}
				break;
			case static_cast<uint8_t>(Column::Column3):
			{

				possibleNum3 = usrFirstNum - 1;
				std::cout << "\n\t Your possible choices are: " << (int)possibleNum3 << '\t' << ((!(possibleNum2 < 0)) ? bufferTools::IntToString(possibleNum2) : "") << '\t' <<
					((!(possibleNum1 < 0)) ? bufferTools::IntToString(possibleNum1) : "") << '\n';
				std::cout << "\t Please enter your choice: ";
				do {
					usrSecondNum = bufferTools::GetUserIntFormat();
					isAccepted = (!(usrSecondNum == possibleNum3 || usrSecondNum == possibleNum2 || usrSecondNum == possibleNum1)) ? false : true;
				} while (!isAccepted);
			}
				break;
			}
		}
		else
		{
			std::cout << "\n\t Your possible choices are: 1 2 3" << '\n';
			do {
				usrSecondNum = bufferTools::GetUserIntFormat();
				isAccepted = (!(usrSecondNum == 1 || usrSecondNum == 2 || usrSecondNum == 3)) ? false : true;
			} while (!isAccepted);
		}
		result = { usrFirstNum, usrSecondNum };
		return result;
	}

	std::array<int8_t, 4> GetCornerSequence()
	{
		std::cout << "\n\t Please choose a number from the Roulette board: ";
		bool isAccepted{ false };
		int8_t usrFirstNum{ 0 }, usrSecondNum{ 0 };
		int8_t possibleNum1{ -1 }, possibleNum2{ -1 }, possibleNum3{ -1 }, possibleNum4{ -1 };
		std::array<int8_t, 4> result{ 0 };
		do {
			usrFirstNum = bufferTools::GetUserIntFormat();
			isAccepted = (!(usrFirstNum <= 36 && usrFirstNum > 0)) ? false : true;
		} while (!isAccepted);

		switch (usrFirstNum % 3)
		{
		case static_cast<uint8_t>(Column::Column1):
		{

			possibleNum1 = (usrFirstNum - 2 > 0) ? usrFirstNum - 2 : -1;
			possibleNum2 = (usrFirstNum + 4 < 36) ? usrFirstNum + 4 : -1;
			std::cout << "\n\t To create your corner, you can choose the following numbers : " << ((possibleNum1 > 0)
				? bufferTools::IntToString(possibleNum1) : "") << '\t' << ((possibleNum2 > 0) ? bufferTools::IntToString(possibleNum2) : "") << '\n';
			std::cout << "\t Please enter your choice: ";
			do {
				usrSecondNum = bufferTools::GetUserIntFormat();
				isAccepted = (!(usrSecondNum == possibleNum1 || usrSecondNum == possibleNum2)) ? false : true;
			} while (!isAccepted);
		}
			break;
		case static_cast<uint8_t>(Column::Column2):
		{

			possibleNum1 = (usrFirstNum - 2 > 0) ? usrFirstNum - 2 : -1;
			possibleNum2 = (usrFirstNum + 2 < 36) ? usrFirstNum + 2 : -1;
			possibleNum3 = (usrFirstNum - 4 > 0) ? usrFirstNum - 4 : -1;
			possibleNum4 = (usrFirstNum + 4 < 36) ? usrFirstNum + 4 : -1;
			std::cout << "\n\t To create your corner, you can choose the following numbers : " << ((possibleNum1 > 0) ? (int)possibleNum1 : (char)' ')
				<< '\t' << ((possibleNum2 > 0) ? bufferTools::IntToString(possibleNum2) : "") << '\t' << ((possibleNum3 > 0) ? bufferTools::IntToString(possibleNum3) : "")
				<< '\t' << ((possibleNum4 > 0) ? bufferTools::IntToString(possibleNum4) : "") << '\n';
			std::cout << "\t Please enter your choice: ";
			do {
				usrSecondNum = bufferTools::GetUserIntFormat();
				isAccepted = (!(usrSecondNum == possibleNum1 || usrSecondNum == possibleNum2 || usrSecondNum == possibleNum3 || usrSecondNum == possibleNum4)) ? false : true;
			} while (!isAccepted);
		}
			break;
		case static_cast<uint8_t>(Column::Column3):
		{

			possibleNum1 = (usrFirstNum - 4 > 0) ? usrFirstNum - 4 : -1;
			possibleNum2 = (usrFirstNum + 2 < 36) ? usrFirstNum + 2 : -1;
			std::cout << "\n\t To create your corner, you can choose the following numbers : " << ((possibleNum1 > 0) ? bufferTools::IntToString(possibleNum1) : "") << '\t'
				<< ((possibleNum2 > 0) ? bufferTools::IntToString(possibleNum2) : "") << '\n';
			std::cout << "\t Please enter your choice: ";
			do {
				usrSecondNum = bufferTools::GetUserIntFormat();
				isAccepted = (!(usrSecondNum == possibleNum1 || usrSecondNum == possibleNum2)) ? false : true;
			} while (!isAccepted);

		}
			break;
		}
		result[0] = usrFirstNum;
		result[1] = usrSecondNum;
		result[2] = (usrFirstNum < usrSecondNum ? usrFirstNum + 3 : usrFirstNum - 3);
		result[3] = (usrSecondNum < usrFirstNum ? usrSecondNum + 3 : usrSecondNum - 3);
		return result;
	}

	void RunRoulette(int& aCurrentBudget, int& aPlayerBet, bool& isGameActive,
		std::array<std::array<std::string, 2>, 6>& aStatisticLst)
	{
		int rouletteProfitLoss = 0;
		bool isKeepPlaying = true, isPlayerLegit = true;
		char usrBetOpt = 0;
		int8_t* usrBetNumbers{ nullptr };
		int8_t usrBetNumber{ 0 };

		while (isKeepPlaying && isGameActive)
		{
			system("cls");
			bufferTools::ClearInputBuffer();
			DisplayRouletteBoard();
			scoreboard::BettingDialouge(aCurrentBudget, aPlayerBet);
			std::cout << "\n\t Please choose your bet optione : ";
			usrBetOpt = bufferTools::GetUserIntFormat();
			usrBetNumbers = nullptr;
			usrBetNumber = 0;
			switch (usrBetOpt)
			{
			case static_cast<char>(RouletteBetType::Straight):
			{

				usrBetNumber = GetStraightNum();
				usrBetNumbers = &usrBetNumber;
				CalculateTheOutcome(usrBetNumbers, static_cast<char>(RouletteBetType::Straight), aCurrentBudget,
					aPlayerBet, rouletteProfitLoss, isPlayerLegit, isKeepPlaying, isGameActive, aStatisticLst);
			}
				break;
			case static_cast<char>(RouletteBetType::RedOrBlack):
			{

				usrBetNumber = GetRedOrBlack_EvenOrOdd(static_cast<char>(RouletteBetType::RedOrBlack));
				usrBetNumbers = &usrBetNumber;
				CalculateTheOutcome(usrBetNumbers, static_cast<char>(RouletteBetType::RedOrBlack), aCurrentBudget,
					aPlayerBet, rouletteProfitLoss, isPlayerLegit, isKeepPlaying, isGameActive, aStatisticLst);
			}
				break;
			case static_cast<char>(RouletteBetType::EvenOrOdd):
			{

				usrBetNumber = GetRedOrBlack_EvenOrOdd(static_cast<char>(RouletteBetType::EvenOrOdd));
				usrBetNumbers = &usrBetNumber;
				CalculateTheOutcome(usrBetNumbers, static_cast<char>(RouletteBetType::EvenOrOdd), aCurrentBudget,
					aPlayerBet, rouletteProfitLoss, isPlayerLegit, isKeepPlaying, isGameActive, aStatisticLst);
			}
				break;
			case static_cast<char>(RouletteBetType::ColumnBet):
			{

				usrBetNumber = GetColumnNum();
				usrBetNumbers = &usrBetNumber;
				CalculateTheOutcome(usrBetNumbers, static_cast<char>(RouletteBetType::ColumnBet), aCurrentBudget,
					aPlayerBet, rouletteProfitLoss, isPlayerLegit, isKeepPlaying, isGameActive, aStatisticLst);
			}
				break;
			case static_cast<char>(RouletteBetType::Split):
			{

				usrBetNumbers = GetSplitSequence().data();
				CalculateTheOutcome(usrBetNumbers, static_cast<char>(RouletteBetType::Split), aCurrentBudget,
					aPlayerBet, rouletteProfitLoss, isPlayerLegit, isKeepPlaying, isGameActive, aStatisticLst);
			}
				break;
			case static_cast<char>(RouletteBetType::Corner):
			{

				usrBetNumbers = GetCornerSequence().data();
				CalculateTheOutcome(usrBetNumbers, static_cast<char>(RouletteBetType::Corner), aCurrentBudget,
					aPlayerBet, rouletteProfitLoss, isPlayerLegit, isKeepPlaying, isGameActive, aStatisticLst);
			}
				break;
			}
			system("pause");
		}
	}

	int8_t GetStraightNum()
	{
		int8_t usrOpt{ 0 };
		bool isAccepted{ false };
		std::cout << "\n\t Choose a number from the board: ";
		do {
			usrOpt = bufferTools::GetUserIntFormat();
			isAccepted = (!(usrOpt >= 0 && usrOpt <= 36)) ? false : true;
		} while (!isAccepted);
		return usrOpt;
	}
	int8_t GetRedOrBlack_EvenOrOdd(uint8_t anOption)
	{ //Allowed arg : RouletteBetType:: Even../Red..; Return 1 or 2 respectively 
		int8_t usrOpt{ 0 };
		bool isAccepted{ false };
		(anOption == static_cast<uint8_t>(RouletteBetType::RedOrBlack)) ? (std::cout << "\n\t [PRESS 1]:: Red\n\t [PRESS 2]:: Black" << '\n') :
			(std::cout << "\n\t [PRESS 1]:: Even\n\t [PRESS 2]:: Odd" << '\n');
		do {
			usrOpt = bufferTools::GetUserIntFormat();
			isAccepted = (!(usrOpt == 2 || usrOpt == 1)) ? false : true;
		} while (!isAccepted);
		return usrOpt;
	}

	int8_t GetColumnNum()
	{
		int8_t usrOpt{ 0 };
		bool isAccepted{ false };
		std::cout << "\n\t Choose a column from the board: ";
		do {
			usrOpt = bufferTools::GetUserIntFormat();
			isAccepted = (!(usrOpt >= 1 && usrOpt <= 3)) ? false : true;
		} while (!isAccepted);
		return usrOpt;
	}

	void CalculateTheOutcome(const int8_t* aStringToRead, const uint8_t aBetType, int& aCurrentBudget, int& aPlayerBet,
		int& aProfitLoss, bool& aPlayerState, bool& aKeepPlayingState, bool& isGameActive, std::array<std::array<std::string, 2>, 6>& aStatisticLst)
	{
		const short UPER_LIMIT = 1000, LOWER_LIMIT = -1000;
		char gameName[]{ "Roulette" };
		uint8_t bollResult{ 0 };
		system("cls");
		bufferTools::ClearInputBuffer();
		bollResult = GenerateRouletteBollNum();
		DisplayRouletteBoard();

		switch (aBetType)
		{
		case static_cast<uint8_t>(RouletteBetType::Straight):
		{
			std::cout << "\n\t Your bet type is Straight which if win gives 36X\n\t You have bet on :" << (int)aStringToRead[0]
			<< "\n\t The boll landed on: " << (int)bollResult << 'n';
			aCurrentBudget = (bollResult == static_cast<uint8_t>(aStringToRead[0])) ? (aCurrentBudget + aPlayerBet * 36) : (aCurrentBudget - aPlayerBet);
			aProfitLoss = (bollResult == static_cast<uint8_t>(aStringToRead[0])) ? (aProfitLoss + aPlayerBet * 36) : (aProfitLoss - aPlayerBet);
			(bollResult == static_cast<uint8_t>(aStringToRead[0])) ? (std::cout << "\n	Daniel: Congratulation bro! You won!\n\tYour budget increased to " << aCurrentBudget << '\n')
			: (std::cout << "\n	Daniel: Sorry man, you lost!" << '\n');
		}
			break;
		case static_cast<uint8_t>(RouletteBetType::RedOrBlack):
		{
			std::cout << "\n\t Your bet type is RedOrBlack which if win gives 2X\n\t " << (aStringToRead[0] == 1) ?
			(std::cout << "Red") : (std::cout << "Black");;
			std::cout << "\n\t The boll landed on: " << (int)bollResult << 'n';
			aCurrentBudget = (isNumAmongRed(bollResult) && aStringToRead[0] == 1) ? (aCurrentBudget + aPlayerBet * 2) : (aCurrentBudget - aPlayerBet);
			aProfitLoss = (isNumAmongRed(bollResult) && aStringToRead[0] == 1) ? (aProfitLoss + aPlayerBet * 2) : (aProfitLoss - aPlayerBet);
			(isNumAmongRed(bollResult) && aStringToRead[0] == 1) ? (std::cout << "\n	Daniel: Congratulation bro! You won!\n\tYour budget increased to " << aCurrentBudget << '\n')
			: (std::cout << "\n	Daniel: Sorry man, you lost!" << '\n');
		}
			break;
		case static_cast<uint8_t>(RouletteBetType::EvenOrOdd):
		{
			std::cout << "\n\t Your bet type is EvenOrOdd which if win gives 2X\n\t You have bet on :" << (aStringToRead[0] == 1) ?
			(std::cout << "Even") : (std::cout << "Odd");
			std::cout << "\n\t The boll landed on: " << (int)bollResult << '\n';
			aCurrentBudget = (bollResult % 2 == 0 && aStringToRead[0] == 1) ? (aCurrentBudget + aPlayerBet * 2) : (aCurrentBudget - aPlayerBet);
			aProfitLoss = (bollResult % 2 == 0 && aStringToRead[0] == 1) ? (aProfitLoss + aPlayerBet * 2) : (aProfitLoss - aPlayerBet);
			(bollResult % 2 == 0 && aStringToRead[0] == 1) ? (std::cout << "\n	Daniel: Congratulation bro! You won!\n\tYour budget increased to " << aCurrentBudget << '\n')
			: (std::cout << "\n	Daniel: Sorry man, you lost!" << '\n');
		}
			break;
		case static_cast<uint8_t>(RouletteBetType::ColumnBet):
		{
			std::cout << "\n\t Your bet type is ColumnBet which if win gives 10X\n\t You have bet on :" << (int)aStringToRead[0];
			std::cout << "\n\t The boll landed on: " << (int)bollResult << '\n';
			aCurrentBudget = ((bollResult % 3 == 0 && aStringToRead[0] == 3) || bollResult % 3 == aStringToRead[0]) ? (aCurrentBudget + aPlayerBet * 10) : (aCurrentBudget - aPlayerBet);
			aProfitLoss = ((bollResult % 3 == 0 && aStringToRead[0] == 3) || bollResult % 3 == aStringToRead[0]) ? (aProfitLoss + aPlayerBet * 10) : (aProfitLoss - aPlayerBet);
			((bollResult % 3 == 0 && aStringToRead[0] == 3) || bollResult % 3 == aStringToRead[0]) ? (std::cout << "\n	Daniel: Congratulation bro! You won!\n\tYour budget increased to " << aCurrentBudget << '\n')
				: (std::cout << "\n	Daniel: Sorry man, you lost!" << '\n');
		}
			break;
		case static_cast<uint8_t>(RouletteBetType::Split):
		{
			std::cout << "\n\t Your bet type is Split which if win gives 20X\n\t You have bet on the following numbers :" << (int)aStringToRead[0] << '\t' << (int)aStringToRead[1];
			std::cout << "\n\t The boll landed on: " << (int)bollResult << '\n';
			aCurrentBudget = (bollResult == aStringToRead[0] || bollResult == aStringToRead[1]) ? (aCurrentBudget + aPlayerBet * 20) : (aCurrentBudget - aPlayerBet);
			aProfitLoss = (bollResult == aStringToRead[0] || bollResult == aStringToRead[1]) ? (aProfitLoss + aPlayerBet * 20) : (aProfitLoss - aPlayerBet);
			(bollResult == aStringToRead[0] || bollResult == aStringToRead[1]) ? (std::cout << "\n	Daniel: Congratulation bro! You won!\n\tYour budget increased to " << aCurrentBudget << '\n')
				: (std::cout << "\n	Daniel: Sorry man, you lost!" << '\n');
		}
			break;
		case static_cast<uint8_t>(RouletteBetType::Corner):
		{
			std::cout << "\n\t Your bet type is Corner which if win gives 15X\n\t You have bet on the following numbers :" << (int)aStringToRead[0] << '\t' << (int)aStringToRead[1]
			<< '\t' << (int)aStringToRead[2] << '\t' << (int)aStringToRead[3] << '\n';
			std::cout << "\n\t The boll landed on: " << (int)bollResult << '\n';
			aCurrentBudget = (bollResult == aStringToRead[0] || bollResult == aStringToRead[1] || bollResult == aStringToRead[2] || bollResult == aStringToRead[3])
			? (aCurrentBudget + aPlayerBet * 2) : (aCurrentBudget - aPlayerBet);
			aProfitLoss = (bollResult == aStringToRead[0] || bollResult == aStringToRead[1] || bollResult == aStringToRead[2] || bollResult == aStringToRead[3])
			? (aProfitLoss + aPlayerBet * 2) : (aProfitLoss - aPlayerBet);
			(bollResult == aStringToRead[0] || bollResult == aStringToRead[1] || bollResult == aStringToRead[2] || bollResult == aStringToRead[3])
			? (std::cout << "\n	Daniel: Congratulation bro! You won!\n\tYour budget increased to " << aCurrentBudget << '\n') : (std::cout << "\n	Daniel: Sorry man, you lost!" << '\n');
			system("pause");
		}
		break;
		}
		scoreboard::CheckCurrentGameLimit(gameName, &aProfitLoss, aPlayerState, aKeepPlayingState, UPER_LIMIT, LOWER_LIMIT, aStatisticLst);
		scoreboard::CheckBudget(aCurrentBudget, isGameActive);
		aPlayerBet = 0;
		bufferTools::PlayOrExit(gameName, aProfitLoss, isGameActive, aKeepPlayingState, aPlayerState, aStatisticLst);
	}

	bool isNumAmongRed(uint8_t aNum)
	{
		uint8_t redNumLst[] = { 32, 19, 21, 25, 34, 27, 36, 30, 23, 5, 16, 1, 14, 9, 18, 7, 12, 3 };
		for (uint8_t eachNum : redNumLst) {
			if (eachNum == aNum) {
				return true;
			}
		}
		return false;
	}
	uint8_t GenerateRouletteBollNum()
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> dis(0, 36);
		return dis(gen);
	}
}