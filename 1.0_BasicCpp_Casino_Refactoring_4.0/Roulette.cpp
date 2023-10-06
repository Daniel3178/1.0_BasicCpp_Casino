#include "Roulette.h"

namespace casino
{
	Roulette::Roulette(uint16_t aMinimumBet, uint16_t aMaximumBet) :
		CasinoGames::CasinoGames(aMinimumBet, aMaximumBet)
	{
		CasinoGames::maxProfit = (aMaximumBet - aMinimumBet) * 2;
		CasinoGames::minLoss = (aMaximumBet - aMinimumBet) * (-1);
		CasinoGames::gameName = "Roulette";
	}

	void Roulette::DisplayRouletteBoard()
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

	std::array<int8_t, 2> Roulette::GetSplitSequence()
	{
		std::cout << "\n\tPlease choose a number from the Roulette board: ";
		bool isAccepted{ false };
		int8_t usrFirstNum{ 0 }, usrSecondNum{ 0 };
		int8_t possibleNum3{ -1 }, possibleNum2{ -1 }, possibleNum1{ -1 }, possibleNum4{ -1 };
		std::array<int8_t, 2> result{ 0 };
		do 
		{
			usrFirstNum = bufferTools::GetPlayerIntFormat();
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
				std::cout << "\n\tYour possible choices are: " << (int)possibleNum3 << '\t' << ((!(possibleNum2 < 0)) ? bufferTools::IntToString(possibleNum2) : "") << '\t' <<
					((!(possibleNum1 < 0)) ? bufferTools::IntToString(possibleNum1) : "") << '\n';
				std::cout << "\tPlease enter your choice: ";
				do {
					usrSecondNum = bufferTools::GetPlayerIntFormat();
					isAccepted = (!(usrSecondNum == possibleNum3 || usrSecondNum == possibleNum2 || usrSecondNum == possibleNum1)) ? false : true;
				} while (!isAccepted);
			}
			break;
			case static_cast<uint8_t>(Column::Column2):
			{

				possibleNum3 = usrFirstNum + 1;
				possibleNum4 = usrFirstNum - 1;
				std::cout << "\n\tYour possible choices are: " << (int)possibleNum3 << '\t' << ((!(possibleNum2 < 0)) ? bufferTools::IntToString(possibleNum2) : "") << '\t' <<
					((!(possibleNum1 < 0)) ? bufferTools::IntToString(possibleNum1) : "") << '\t' << (int)possibleNum4 << '\n';
				std::cout << "\tPlease enter your choice: ";
				do {
					usrSecondNum = bufferTools::GetPlayerIntFormat();
					isAccepted = (!(usrSecondNum == possibleNum3 || usrSecondNum == possibleNum2 || usrSecondNum == possibleNum1 || usrSecondNum == possibleNum4)) ? false : true;
				} while (!isAccepted);
			}
			break;
			case static_cast<uint8_t>(Column::Column3):
			{

				possibleNum3 = usrFirstNum - 1;
				std::cout << "\n\tYour possible choices are: " << (int)possibleNum3 << '\t' << ((!(possibleNum2 < 0)) ? bufferTools::IntToString(possibleNum2) : "") << '\t' <<
					((!(possibleNum1 < 0)) ? bufferTools::IntToString(possibleNum1) : "") << '\n';
				std::cout << "\tPlease enter your choice: ";
				do
				{
					usrSecondNum = bufferTools::GetPlayerIntFormat();
					isAccepted = (!(usrSecondNum == possibleNum3 || usrSecondNum == possibleNum2 || usrSecondNum == possibleNum1)) ? false : true;
				} while (!isAccepted);
			}
			break;
			}
		}
		else
		{
			std::cout << "\n\tYour possible choices are: 1 2 3" << '\n';
			do 
			{
				usrSecondNum = bufferTools::GetPlayerIntFormat();
				isAccepted = (!(usrSecondNum == 1 || usrSecondNum == 2 || usrSecondNum == 3)) ? false : true;
			} while (!isAccepted);
		}
		result = { usrFirstNum, usrSecondNum };
		return result;
	}

	std::array<int8_t, 4> Roulette::GetCornerSequence()
	{
		std::cout << "\n\tPlease choose a number from the Roulette board: ";
		bool isAccepted{ false };
		int8_t usrFirstNum{ 0 }, usrSecondNum{ 0 };
		int8_t possibleNum1{ -1 }, possibleNum2{ -1 }, possibleNum3{ -1 }, possibleNum4{ -1 };
		std::array<int8_t, 4> result{ 0 };
		do 
		{
			usrFirstNum = bufferTools::GetPlayerIntFormat();
			isAccepted = (!(usrFirstNum <= 36 && usrFirstNum > 0)) ? false : true;
		} while (!isAccepted);

		switch (usrFirstNum % 3)
		{
		case static_cast<uint8_t>(Column::Column1):
		{

			possibleNum1 = (usrFirstNum - 2 > 0) ? usrFirstNum - 2 : -1;
			possibleNum2 = (usrFirstNum + 4 < 36) ? usrFirstNum + 4 : -1;
			std::cout << "\n\tTo create your corner, you can choose the following numbers : " << ((possibleNum1 > 0)
				? bufferTools::IntToString(possibleNum1) : "") << '\t' << ((possibleNum2 > 0) ? bufferTools::IntToString(possibleNum2) : "") << '\n';
			std::cout << "\tPlease enter your choice: ";
			do 
			{
				usrSecondNum = bufferTools::GetPlayerIntFormat();
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
		std::cout << "\n\tTo create your corner, you can choose the following numbers : " << ((possibleNum1 > 0) ? (int)possibleNum1 : (char)' ')
			<< '\t' << ((possibleNum2 > 0) ? bufferTools::IntToString(possibleNum2) : "") << '\t' << ((possibleNum3 > 0) ? bufferTools::IntToString(possibleNum3) : "")
			<< '\t' << ((possibleNum4 > 0) ? bufferTools::IntToString(possibleNum4) : "") << '\n';
		std::cout << "\tPlease enter your choice: ";
		do {
			usrSecondNum = bufferTools::GetPlayerIntFormat();
			isAccepted = (!(usrSecondNum == possibleNum1 || usrSecondNum == possibleNum2 || usrSecondNum == possibleNum3 || usrSecondNum == possibleNum4)) ? false : true;
		} while (!isAccepted);
	}
	break;
		case static_cast<uint8_t>(Column::Column3):
		{

			possibleNum1 = (usrFirstNum - 4 > 0) ? usrFirstNum - 4 : -1;
			possibleNum2 = (usrFirstNum + 2 < 36) ? usrFirstNum + 2 : -1;
			std::cout << "\n\tTo create your corner, you can choose the following numbers : " << ((possibleNum1 > 0) ? bufferTools::IntToString(possibleNum1) : "") << '\t'
				<< ((possibleNum2 > 0) ? bufferTools::IntToString(possibleNum2) : "") << '\n';
			std::cout << "\tPlease enter your choice: ";
			do {
				usrSecondNum = bufferTools::GetPlayerIntFormat();
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

	void Roulette::Run(Player* aPlayer, bool& isGameActive,
		std::array<std::array<std::string, 2>, 6>& aStatisticLst)
	{
		aPlayer->SetPlayerPlayingState(true);
		aPlayer->SetPlayerLegit(true);
		char usrBetOpt = 0;
		int8_t* usrBetNumbers{ nullptr };
		int8_t usrBetNumber{ 0 };

		while (aPlayer->GetPlayerPlaying() && isGameActive)
		{
			system("cls");
			bufferTools::ClearInputBuffer();
			DisplayRouletteBoard();
			BettingDialouge(aPlayer, this);
			std::cout << "\n\tPlease choose your bet optione : ";
			usrBetOpt = bufferTools::GetPlayerIntFormat();
			usrBetNumbers = nullptr;
			usrBetNumber = 0;
			switch (usrBetOpt)
			{
			case static_cast<char>(RouletteBetType::Straight):
			{

				usrBetNumber = GetStraightNum();
				usrBetNumbers = &usrBetNumber;
				CalculateTheOutcome(usrBetNumbers,
					static_cast<char>(RouletteBetType::Straight), aPlayer, isGameActive, aStatisticLst);
			}
			break;
			case static_cast<char>(RouletteBetType::RedOrBlack):
			{

				usrBetNumber = GetRedOrBlack_EvenOrOdd(static_cast<char>(RouletteBetType::RedOrBlack));
				usrBetNumbers = &usrBetNumber;
				CalculateTheOutcome(usrBetNumbers,
					static_cast<char>(RouletteBetType::RedOrBlack), aPlayer, isGameActive, aStatisticLst);
			}
			break;
			case static_cast<char>(RouletteBetType::EvenOrOdd):
			{

				usrBetNumber = GetRedOrBlack_EvenOrOdd(static_cast<char>(RouletteBetType::EvenOrOdd));
				usrBetNumbers = &usrBetNumber;
				CalculateTheOutcome(usrBetNumbers,
					static_cast<char>(RouletteBetType::EvenOrOdd), aPlayer, isGameActive, aStatisticLst);
			}
			break;
			case static_cast<char>(RouletteBetType::ColumnBet):
			{

				usrBetNumber = GetColumnNum();
				usrBetNumbers = &usrBetNumber;
				CalculateTheOutcome(usrBetNumbers,
					static_cast<char>(RouletteBetType::ColumnBet), aPlayer, isGameActive, aStatisticLst);
			}
			break;
			case static_cast<char>(RouletteBetType::Split):
			{

				usrBetNumbers = GetSplitSequence().data();
				CalculateTheOutcome(usrBetNumbers,
					static_cast<char>(RouletteBetType::Split), aPlayer, isGameActive, aStatisticLst);
			}
			break;
			case static_cast<char>(RouletteBetType::Corner):
			{

				usrBetNumbers = GetCornerSequence().data();
				CalculateTheOutcome(usrBetNumbers,
					static_cast<char>(RouletteBetType::Corner), aPlayer, isGameActive, aStatisticLst);
			}
			break;
			}
			system("pause");
		}
	}

	int8_t Roulette::GetStraightNum()
	{
		int8_t usrOpt{ 0 };
		bool isAccepted{ false };
		std::cout << "\n\tChoose a number from the board: ";
		do {
			usrOpt = bufferTools::GetPlayerIntFormat();
			isAccepted = (!(usrOpt >= 0 && usrOpt <= 36)) ? false : true;
		} while (!isAccepted);
		return usrOpt;
	}

	int8_t Roulette::GetRedOrBlack_EvenOrOdd(uint8_t anOption)
	{ 
		int8_t usrOpt{ 0 };
		bool isAccepted{ false };
		(anOption == static_cast<uint8_t>(RouletteBetType::RedOrBlack)) ? (std::cout << "\n\t [PRESS 1]:: Red\n\t [PRESS 2]:: Black" << '\n') :
			(std::cout << "\n\t [PRESS 1]:: Even\n\t [PRESS 2]:: Odd" << '\n');
		do 
		{
			usrOpt = bufferTools::GetPlayerIntFormat();
			isAccepted = (!(usrOpt == 2 || usrOpt == 1)) ? false : true;
		} while (!isAccepted);
		return usrOpt;
	}

	int8_t Roulette::GetColumnNum()
	{
		int8_t usrOpt{ 0 };
		bool isAccepted{ false };
		std::cout << "\n\tChoose a column from the board: ";
		do {
			usrOpt = bufferTools::GetPlayerIntFormat();
			isAccepted = (!(usrOpt >= 1 && usrOpt <= 3)) ? false : true;
		} while (!isAccepted);
		return usrOpt;
	}

	void Roulette::CalculateTheOutcome(const int8_t* aStringToRead,
		const uint8_t aBetType, Player* aPlayer,
		bool& isGameActive, std::array<std::array<std::string, 2>, 6>& aStatisticLst)
	{
		uint8_t bollResult{ 0 };
		system("cls");
		bufferTools::ClearInputBuffer();
		bollResult = dice::GenerateRouletteBollNum();
		DisplayRouletteBoard();

		switch (aBetType)
		{
		case static_cast<uint8_t>(RouletteBetType::Straight):
		{
			std::cout << "\n\tYour bet type is Straight which if win gives 36X\n\tYou have bet on :" << (int)aStringToRead[0]
				<< "\n\tThe boll landed on: " << (int)bollResult << '\n';
			(bollResult == static_cast<uint8_t>(aStringToRead[0])) ? aPlayer->IncreasePlayerTotalBudget(aPlayer->GetPlayerBet() * 36) 
				: aPlayer->DecreasePlayerTotalBudget(aPlayer->GetPlayerBet());
			(bollResult == static_cast<uint8_t>(aStringToRead[0])) ? IncreaseProfitLoss(aPlayer->GetPlayerBet() * 36) 
				: DecreaseProfitLoss(aPlayer->GetPlayerBet());
			(bollResult == static_cast<uint8_t>(aStringToRead[0])) ? (std::cout << "\n	Daniel: Congratulation bro! You won!\n\tYour budget increased to " << aPlayer->GetPlayerTotalBudget() << '\n')
				: (std::cout << "\n	Daniel: Sorry man, you lost!" << '\n');
		}
		break;
		case static_cast<uint8_t>(RouletteBetType::RedOrBlack):
		{
			std::cout << "\n\tYour bet type is RedOrBlack which if win gives 2X\n\t " << (aStringToRead[0] == 1) ?
				(std::cout << "Red") : (std::cout << "Black");;
			std::cout << "\n\tThe boll landed on: " << (int)bollResult << '\n';
			(IsNumAmongRed(bollResult) && aStringToRead[0] == 1) ? aPlayer->IncreasePlayerTotalBudget(aPlayer->GetPlayerBet() * 2) 
				: aPlayer->DecreasePlayerTotalBudget(aPlayer->GetPlayerBet());
			(IsNumAmongRed(bollResult) && aStringToRead[0] == 1) ? IncreaseProfitLoss(aPlayer->GetPlayerBet() * 2) 
				: DecreaseProfitLoss (aPlayer->GetPlayerBet());
			(IsNumAmongRed(bollResult) && aStringToRead[0] == 1) ? (std::cout << "\n	Daniel: Congratulation bro! You won!\n\tYour budget increased to " << aPlayer->GetPlayerTotalBudget() << '\n')
				: (std::cout << "\n	Daniel: Sorry man, you lost!" << '\n');
		}
		break;
		case static_cast<uint8_t>(RouletteBetType::EvenOrOdd):
		{
			std::cout << "\n\tYour bet type is EvenOrOdd which if win gives 2X\n\tYou have bet on :" << (aStringToRead[0] == 1) ?
				(std::cout << "Even") : (std::cout << "Odd");
			std::cout << "\n\tThe boll landed on: " << (int)bollResult << '\n';
			(bollResult % 2 == 0 && aStringToRead[0] == 1) ? aPlayer->IncreasePlayerTotalBudget(aPlayer->GetPlayerBet() * 2) 
				: aPlayer->DecreasePlayerTotalBudget(aPlayer->GetPlayerBet());
			(bollResult % 2 == 0 && aStringToRead[0] == 1) ? IncreaseProfitLoss(aPlayer->GetPlayerBet() * 2) 
				: DecreaseProfitLoss(aPlayer->GetPlayerBet());
			(bollResult % 2 == 0 && aStringToRead[0] == 1) ? (std::cout << "\n	Daniel: Congratulation bro! You won!\n\tYour budget increased to " << aPlayer->GetPlayerTotalBudget() << '\n')
				: (std::cout << "\nDaniel: Sorry man, you lost!" << '\n');
		}
		break;
		case static_cast<uint8_t>(RouletteBetType::ColumnBet):
		{
			std::cout << "\n\tYour bet type is ColumnBet which if win gives 10X\n\tYou have bet on :" << (int)aStringToRead[0];
			std::cout << "\n\tThe boll landed on: " << (int)bollResult << '\n';
			((bollResult % 3 == 0 && aStringToRead[0] == 3) || bollResult % 3 == aStringToRead[0]) ? aPlayer->IncreasePlayerTotalBudget(aPlayer->GetPlayerBet() * 10) 
				: aPlayer->DecreasePlayerTotalBudget(aPlayer->GetPlayerBet());
			((bollResult % 3 == 0 && aStringToRead[0] == 3) || bollResult % 3 == aStringToRead[0]) ? IncreaseProfitLoss(aPlayer->GetPlayerBet() * 10) : DecreaseProfitLoss(aPlayer->GetPlayerBet());
			((bollResult % 3 == 0 && aStringToRead[0] == 3) || bollResult % 3 == aStringToRead[0]) ? (std::cout << "\n	Daniel: Congratulation bro! You won!\n\tYour budget increased to " << aPlayer->GetPlayerTotalBudget() << '\n')
				: (std::cout << "\nDaniel: Sorry man, you lost!" << '\n');
		}
		break;
		case static_cast<uint8_t>(RouletteBetType::Split):
		{
			std::cout << "\n\tYour bet type is Split which if win gives 20X\n\tYou have bet on the following numbers :" << (int)aStringToRead[0] << '\t' << (int)aStringToRead[1];
			std::cout << "\n\tThe boll landed on: " << (int)bollResult << '\n';
			(bollResult == aStringToRead[0] || bollResult == aStringToRead[1]) ? aPlayer->IncreasePlayerTotalBudget(aPlayer->GetPlayerBet() * 20) 
				: aPlayer->DecreasePlayerTotalBudget(aPlayer->GetPlayerBet());
		    (bollResult == aStringToRead[0] || bollResult == aStringToRead[1]) ? IncreaseProfitLoss(aPlayer->GetPlayerBet() * 20) 
				: DecreaseProfitLoss(aPlayer->GetPlayerBet());
			(bollResult == aStringToRead[0] || bollResult == aStringToRead[1]) ? (std::cout << "\nDaniel: Congratulation bro! You won!\n\tYour budget increased to " << aPlayer->GetPlayerTotalBudget() << '\n')
				: (std::cout << "\nDaniel: Sorry man, you lost!" << '\n');
		}
		break;
		case static_cast<uint8_t>(RouletteBetType::Corner):
		{
			std::cout << "\n\tYour bet type is Corner which if win gives 15X\n\tYou have bet on the following numbers :" << (int)aStringToRead[0] << '\t' << (int)aStringToRead[1]
				<< '\t' << (int)aStringToRead[2] << '\t' << (int)aStringToRead[3] << '\n';
			std::cout << "\n\tThe boll landed on: " << (int)bollResult << '\n';
			(bollResult == aStringToRead[0] || bollResult == aStringToRead[1] || bollResult == aStringToRead[2] || bollResult == aStringToRead[3])
				? aPlayer->IncreasePlayerTotalBudget(aPlayer->GetPlayerBet() * 2) : aPlayer->DecreasePlayerTotalBudget(aPlayer->GetPlayerBet());
			(bollResult == aStringToRead[0] || bollResult == aStringToRead[1] || bollResult == aStringToRead[2] || bollResult == aStringToRead[3])
				? IncreaseProfitLoss(aPlayer->GetPlayerBet() * 2) : DecreaseProfitLoss(aPlayer->GetPlayerBet());
			(bollResult == aStringToRead[0] || bollResult == aStringToRead[1] || bollResult == aStringToRead[2] || bollResult == aStringToRead[3])
				? (std::cout << "\nDaniel: Congratulation bro! You won!\n\tYour budget increased to " << aPlayer->GetPlayerTotalBudget() << '\n') : (std::cout << "\n	Daniel: Sorry man, you lost!" << '\n');
			system("pause");
		}
		break;
		}
		statistics::CheckCurrentGameLimit(aPlayer, this, aStatisticLst);
		statistics::CheckBudget(aPlayer, isGameActive);
		aPlayer->SetPlayerBet(0);
		PlayOrExit(aPlayer, isGameActive, aStatisticLst);
	}
	bool Roulette::IsNumAmongRed(uint8_t aNum)
	{
		uint8_t redNumLst[] = { 32, 19, 21, 25, 34, 27, 36, 30, 23, 5, 16, 1, 14, 9, 18, 7, 12, 3 };
		for (uint8_t eachNum : redNumLst) {
			if (eachNum == aNum) {
				return true;
			}
		}
		return false;
	}

	void Roulette::BettingDialouge(casino::Player* aPlayer, casino::CasinoGames* aGame)
	{
		CasinoGames::BettingDialouge(aPlayer, aGame);
	}

	void Roulette::DisplayRules(casino::Player* aPlayer)
	{
		std::cout << "\n\tThese are the rules for roulette game\n";
	}
}