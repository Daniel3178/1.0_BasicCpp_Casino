#pragma once
#include "Menu.h"
#include "Guess.h"
#include "Player.h"
#include "Bar_Dice.h"
#include "CrownAndAnchor.h"
#include "OddOrEven.h"
#include "Roulette.h"

namespace menu {

	int GetPlayerOption() {

		std::cout << "	Casino 1.4	" << '\n';
		std::cout << "	Press [1] :: Play Guessing Game	(High Stack)" << '\n';
		std::cout << "	Press [2] :: Play Guessing Game	(Low Stack)" << '\n';
		std::cout << "	Press [3] :: Play Odd/Even Game " << '\n';
		std::cout << "	Press [4] :: Play Bar_Dice " << '\n';
		std::cout << "	Press [5] :: Play Crown and Anchor " << '\n';
		std::cout << "	Press [6] :: Play Roulette " << '\n';
		std::cout << "	Press [7] :: Display statistics " << '\n';

		std::cout << "	Your choice: ";
		int usrInput{ 0 };
		bool isAccepted{ false };
		do
		{
			isAccepted = true;
			usrInput = bufferTools::GetPlayerIntFormat();
			if (!(usrInput == 1 || usrInput == 2 || usrInput == 3 || usrInput == 4 || usrInput == 5
				|| usrInput == 6 || usrInput == 7))
			{
				system("cls");
				std::cout << "Your choices are 1, 2, 3, 4, 5, 6 or 7 " << '\n';
				isAccepted = false;
			}
		} while (!isAccepted);

		return usrInput;
	}

	casino::Player RegisterPlayer()
	{
		std::string tempStr = "";
		std::cout << "\n\t Please enter your name : ";
		std::string usrInput{ 0 };
		bool isAccepted{ true };
		do
		{
			std::cin >> usrInput;
			if (std::cin.fail()) {
				tempStr = "";
				std::cin.clear();
				bufferTools::ClearInputBuffer();
				system("cls");
			}
			else
			{
				tempStr += usrInput;
			}
		} while (std::cin.peek() != '\n');

		for (char c : tempStr)
		{
			if (!((c <= 'Z' && c >= 'A') || (c <= 'z' && c >= 'a')))
			{
				isAccepted = false;
				break;
			}
		}

		if (!isAccepted || tempStr.length() <= 2)
		{
			system("cls");
			std::cout << "Invalid name! Please use only characters \n";
			return RegisterPlayer();
		}
		else
		{
			casino::Player registeredPlayer(tempStr);
			return registeredPlayer;
		}

	}
	char GetInGameOption()
	{
		std::cout << "	Press [1] :: Disply the rules" << '\n';
		std::cout << "	Press [2] :: Run the game" << '\n';
		std::cout << "	Press [3] :: Exit the game " << '\n';
		std::cout << "	Your choice: ";
		char usrInput{ 0 };
		bool isAccepted{ false };
		do
		{
			isAccepted = true;
			usrInput = bufferTools::GetPlayerIntFormat();
			if (!(usrInput == 1 || usrInput == 2 || usrInput == 3))
			{
				system("cls");
				std::cout << "Your choices are 1, 2 or 3 " << '\n';
				isAccepted = false;
			}
		} while (!isAccepted);

		return usrInput;
	}
	void RunCasino() {

		bool isGameActive{ true };
		const uint8_t ROW = 6, COLUMN = 2;

		std::array<std::array<std::string, COLUMN>, ROW> statisticLst{ {
		{"Game","	Profits/Losses"},
		{"No statistics","No statistics"},
		{"No statistics","No statistics"},
		{"No statistics","No statistics"},
		{"No statistics","No statistics"},
		{"No statistics","No statistics"},
		} };

		casino::Player player1 = RegisterPlayer();

		while (isGameActive)
		{
			system("cls");
			switch (GetPlayerOption())
			{
			case static_cast<int>(Optiones::GuessHighStack):
			{
				bool remain = true;
				while (remain) {

					system("cls");

					switch (GetInGameOption())
					{
					case 1:
					{
						casino::Guess myGuess1(100, 500);
						myGuess1.DisplayRules(&player1);
						system("pause");
					}
					break;
					case 2:
					{
						casino::Guess myGuess1(100, 500);
						myGuess1.Run(&player1, isGameActive, statisticLst);
						remain = false;
					}
					break;
					case 3:
					{
						remain = false;
						break;
					}
					}
				}
			}
			break;
			case static_cast<int>(Optiones::GuessLowStack):
			{
				bool remain = true;
				while (remain)
				{
					system("cls");

					switch (GetInGameOption())
					{
					case 1:
					{
						casino::Guess myGuess2(100, 500);
						myGuess2.DisplayRules(&player1);
						system("pause");

					}
					break;
					case 2:
					{
						casino::Guess myGuess2(100, 500);
						myGuess2.Run(&player1, isGameActive, statisticLst);
						remain = false;
					}
					break;
					case 3:
					{
						remain = false;
						break;
					}
					}
				}
			}
			break;
			case static_cast<int>(Optiones::OddOrEven):
			{
				bool remain = true;
				while (remain)
				{
					system("cls");

					switch (GetInGameOption())
					{
					case 1:
					{
						casino::OddOrEven myOddOrEven(100, 500);
						myOddOrEven.DisplayRules(&player1);
						system("pause");

					}
					break;
					case 2:
					{
						casino::OddOrEven myOddOrEven(100, 500);
						myOddOrEven.Run(&player1, isGameActive, statisticLst);
						remain = false;

					}
					break;
					case 3:
					{
						remain = false;
						break;
					}
					}
				}

			}
			break;
			case static_cast<int>(Optiones::Bar_Dice):
			{
				bool remain = true;
				while (remain)
				{
					system("cls");

					switch (GetInGameOption())
					{
					case 1:
					{
						casino::Bar_Dice myBar_Dice(100, 500);
						myBar_Dice.DisplayRules(&player1);
						system("pause");

					}
					break;
					case 2:
					{
						casino::Bar_Dice myBar_Dice(100, 500);
						myBar_Dice.Run(&player1, isGameActive, statisticLst);
						remain = false;

					}
					break;
					case 3:
					{
						remain = false;

						break;
					}
					}
				}

			}
			break;
			case static_cast<int>(Optiones::Crown_and_Anchor):
			{
				bool remain = true;
				while (remain)
				{
					system("cls");

					switch (GetInGameOption())
					{
					case 1:
					{
						casino::CrownAndAnchor myCrownAndAnchor(100, 500);
						myCrownAndAnchor.DisplayRules(&player1);
						system("pause");

					}
					break;
					case 2:
					{
						casino::CrownAndAnchor myCrownAndAnchor(100, 500);
						myCrownAndAnchor.Run(&player1, isGameActive, statisticLst);
						remain = false;

					}
					break;
					case 3:
					{
						remain = false;

						break;
					}
					}
				}

			}
			break;
			case static_cast<int>(Optiones::Roulette):
			{
				bool remain = true;
				while (remain)
				{

					system("cls");

					switch (GetInGameOption())
					{
					case 1:
					{
						casino::Roulette myRoulette(100, 500);
						myRoulette.DisplayRules(&player1);
						system("pause");

					}
					break;
					case 2:
					{
						casino::Roulette myRoulette(100, 500);
						myRoulette.Run(&player1, isGameActive, statisticLst);
						remain = false;

					}
					break;
					case 3:
					{
						remain = false;

						break;
					}
					}
				}
			}
			break;
			case static_cast<int>(Optiones::ScoreBoard):
			{
				system("cls");

				statistics::DisplayStatistic(statisticLst);
				system("pause");
			}
			break;

			}
		}
	}
}
