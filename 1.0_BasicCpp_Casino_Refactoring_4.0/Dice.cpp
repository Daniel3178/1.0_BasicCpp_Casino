#include "Dice.h"

namespace dice
{
	std::array<uint8_t, 5> Get5DiceResult()
	{
		std::array<uint8_t, 5> dieResult{ 0 };
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> dis(1, 6);

		uint8_t dieRollOne = dis(gen), dieRollTwo = dis(gen), dieRollThree = dis(gen),
			dieRollFour = dis(gen), dieRollFive = dis(gen);
		std::cout << " \n\n	Die one is : " << static_cast<int>(dieRollOne) << "\n";
		std::cout << "	Die two is : " << static_cast<int>(dieRollTwo) << "\n";
		dieResult = { dieRollOne, dieRollTwo, dieRollThree, dieRollFour, dieRollFive };
		return dieResult;
	}

	uint8_t GenerateRouletteBollNum()
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> dis(0, 36);
		return dis(gen);
	}
	uint8_t GetPlayerDiceSum(casino::Player* aPlayer) {

		std::cout << "\n\t Hey " <<aPlayer->GetPlayerName() 
			<< " please press [R] on the keyboard to roll the dices: ";
		bool isAccepted{ false };
		char usrOpt{ 'o' };
		do {
			isAccepted = true;
			usrOpt = bufferTools::GetPlayerCharFormat();
			if (!(usrOpt == 'r' || usrOpt == 'R')) {
				system("cls");
				std::cout << "Answer unknown, please answer with [R/r]" << '\n';
				isAccepted = false;
			}
		} while (!isAccepted);
		uint8_t* dieSumStr = Get5DiceResult().data();
		uint8_t dieSum = dieSumStr[0] + dieSumStr[1];
		std::cout << "\tYour sum is: " << bufferTools::IntToString(dieSum) << '\n';
		return dieSum;
	}

	uint8_t GetBotPlayerDiceSum() {
		uint8_t* dieSumStr = Get5DiceResult().data();
		uint8_t dieSum = dieSumStr[0] + dieSumStr[1];
		std::cout << "\tDaniel's sum is: " << bufferTools::IntToString(dieSum) << '\n';
		return dieSum;
	}
}