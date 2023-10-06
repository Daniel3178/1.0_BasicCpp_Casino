#include <iostream>
#include <random>
#include <array>

typedef unsigned char p_byte;

bool isGameActive{ false };
short currentBudget = 400;
short playerBet = 0;


void ClearInputBuffer() {
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
void DisplayCurrentBudget() {
	std::cout << "		Your current budget is: " << currentBudget << std::endl;
}
void DisplayRules() {
	std::string rules = "	\n********************************************\n	\
Here are the rules: \n	#1 Follow the rules\n	\
#2 Follow rule #1\n********************************************\n";
	std::cout << rules << std::endl;
}

void BettingDialouge() {
	std::cout << "\n	Your current budget is: " << currentBudget;
	std::cout << "\n	Please enter the amount you want to bet: ";

	bool isAccepted{ false };
	do {
		isAccepted = true;
		std::cin >> playerBet;
		while (std::cin.fail() || std::cin.peek() != '\n') {
			std::cin.clear();
			ClearInputBuffer();
			system("cls");
			std::cout << "Please enter the right format: " << std::endl;
			std::cin >> playerBet;
		}
		if (!(playerBet <= currentBudget && playerBet > 0)) {
			system("cls");
			std::cout << "Remeber, you are only allowed to bet above 0$ and less than the maximum budget!" << std::endl;
			isAccepted = false;
		}
		if (playerBet == currentBudget) {
			std::cout << "\n	Warning! you are about to go all in!!" << std::endl;
		}
	} while (!isAccepted);

}

void CheckBudget() {
	if (currentBudget <= 0) {

		std::cout << "	\n\tYou ran out of money!\n\tThe escort will lead you out... \n";
		isGameActive = false;
	}
}


namespace scoreboard {

	std::array<std::array<std::string, 2>, 6> myArray{ {{"Game","	Profits/Losses"},
		{"No statistics","No statistics"},
		{"No statistics","No statistics"},
		{"No statistics","No statistics"},
		{"No statistics","No statistics"},
		{"No statistics","No statistics"},
	} };

	std::string intToString(int anInt) {
		std::string result = "";
		bool isNegativ = false;

		if (anInt == 0) {
			return "0";
		}
		if (anInt < 0) {
			anInt = -anInt;
			isNegativ = true;
		}

		while (anInt > 0) {
			int digit = 0;
			digit = anInt % 10;
			result += '0' + digit;
			anInt /= 10;
		}
		if (isNegativ) {
			result += '-';
		}

		for (int i = 0; i < result.length() / 2; i++) {

			char temp = result[i];
			result[i] = result[result.length() - 1 - i];
			result[result.length() - 1 - i] = temp;
		}

		return result;
	}

	void DisplayScores() {
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 2; j++) {

				if (myArray[i][j] == "Guess") {
					std::cout << "\t" << myArray[i][j] << "\t\t";
				}
				else {

					std::cout << "\t" << myArray[i][j] << "\t";
				}


			}
			std::cout << std::endl;
		}
	}

	void saveStatistics(std::string aGameName, std::string aScore) {
		for (int i = 0; i < 6; i++) {
			if (scoreboard::myArray[i][0] == "No statistics") {
				scoreboard::myArray[i][0] = aGameName;
				scoreboard::myArray[i][1] = aScore;
				break;
			}
		}
	}



	void CheckCurrentGameLimit(std::string aGameName, int* aProfitLoss, bool& aPlayerState, bool& aKeepPlayingState, const short& anUperLimit, const short& anUnderLimit) {
		if (*aProfitLoss >= anUperLimit) {
			aKeepPlayingState = false;
			aPlayerState = false;
			std::cout << "You are not allowed to continue this game due to too much losses" << std::endl;
			scoreboard::saveStatistics(aGameName, scoreboard::intToString(*aProfitLoss));
			*aProfitLoss = 0;
		}
		if (*aProfitLoss <= anUnderLimit) {
			aKeepPlayingState = false;
			aPlayerState = false;
			std::cout << "You are not allowed to continue this game due to too much profit" << std::endl;
			scoreboard::saveStatistics(aGameName, scoreboard::intToString(*aProfitLoss));
			*aProfitLoss = 0;
		}
	}

	void RunBoard() {


		bool isAccepted{ false };
		char usrOpt{ 'n' };
		do {
			system("cls");
			DisplayScores();
			std::cout << "\n\n	Press [x] to exit: ";
			isAccepted = true;
			std::cin >> usrOpt;
			while (std::cin.fail() || std::cin.peek() != '\n') {
				std::cin.clear();
				ClearInputBuffer();
				system("cls");
				std::cout << "Please answer with only one char : " << std::endl;
				std::cin >> usrOpt;
			}
			if (!(usrOpt == 'x' || usrOpt == 'X')) {

				isAccepted = false;
			}
			else {
				isAccepted = true;
			}
		} while (!isAccepted);
		system("pause");

	}
}

namespace guess {



	int GetUserGuess() {

		std::cout << "\n\tPlease guess a number between 2 and 12: ";
		int usrInput{ 0 };
		bool isAccepted{ false };
		do {
			isAccepted = true;
			std::cin >> usrInput;
			while (std::cin.fail() || std::cin.peek() != '\n') {
				std::cin.clear();
				ClearInputBuffer();
				system("cls");
				std::cout << "Please enter the right format: " << std::endl;
				std::cin >> usrInput;
			}
			if (!(usrInput >= 2 && usrInput <= 12)) {
				system("cls");
				std::cout << "Number out of range, please keep it between 2 and 12" << std::endl;
				isAccepted = false;
			}
		} while (!isAccepted);

		return usrInput;
	}

	char GetUserOption() {
		bool isAccepted{ false };
		char usrOpt{ 'n' };
		do {
			isAccepted = true;
			std::cin >> usrOpt;
			while (std::cin.fail() || std::cin.peek() != '\n') {
				std::cin.clear();
				ClearInputBuffer();
				system("cls");
				std::cout << "Please answer with only one char : " << std::endl;
				std::cin >> usrOpt;
			}
			if (!(usrOpt == 'n' || usrOpt == 'y')) {
				system("cls");
				std::cout << "Answer unknown, please answer with [y/n]" << std::endl;
				isAccepted = false;
			}
		} while (!isAccepted);
		return usrOpt;
	}

	std::string GetDieSum() {
		std::string dieResult = "";
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> dis(1, 6);

		int dieRollOne = dis(gen);
		std::cout << " \n\n	Die one is : " << dieRollOne << "\n";
		int dieRollTwo = dis(gen);
		std::cout << "	Die two is : " << dieRollTwo << "\n";
		dieResult = (char)dieRollOne + (char)dieRollTwo;
		return dieResult;
	}


	void RunGuess() {

		int guessProfitLoss = 0;
		const short UPER_LIMIT = 1000;
		const short UNDER_LIMIT = -1000;
		bool isKeepPlaying = true;
		bool isPlayerLegit = true;
		std::string gameName = "Guess";

		while (isKeepPlaying && isGameActive) {

			system("cls");
			ClearInputBuffer();
			BettingDialouge();

			int usrGuess = GetUserGuess();
			std::cout << "\n	Your choise is : " << usrGuess;
			std::string dieSumStr = GetDieSum();
			int dieSumInt = (int)dieSumStr[0] + (int)dieSumStr[1];
			std::cout << "\n	The sum is : " << dieSumInt;

			if (dieSumInt == usrGuess) {
				std::cout << "\n	Daniel: Congratulation bro! You won!";
				currentBudget += playerBet * 2;
				guessProfitLoss += playerBet * 2;
				scoreboard::CheckCurrentGameLimit(gameName, &guessProfitLoss, isPlayerLegit, isKeepPlaying, UPER_LIMIT, UNDER_LIMIT);
				std::cout << "\n\tYour budget increased to " << currentBudget << std::endl;
				playerBet = 0;
			}
			else {
				std::cout << "\n	Daniel: Sorry man, you lost!";
				currentBudget -= playerBet;
				guessProfitLoss -= playerBet * 2;
				playerBet = 0;
				scoreboard::CheckCurrentGameLimit(gameName, &guessProfitLoss, isPlayerLegit, isKeepPlaying, UPER_LIMIT, UNDER_LIMIT);
				CheckBudget();
			}
			if (isPlayerLegit && isGameActive) {

				std::cout << "\n\n	Do you want to try again [y / n]: ";
				if (GetUserOption() == 'n') {
					isKeepPlaying = false;
					scoreboard::saveStatistics(gameName, scoreboard::intToString(guessProfitLoss));
				}


			}
		}
		system("pause");

	}


}

namespace oddOrEven {


	char GetUserGuess() {

		std::cout << "\n\tDo you want to bet on even or odd number? answer with [e/o]: ";
		bool isAccepted{ false };
		char usrOpt{ 'o' };
		do {
			isAccepted = true;
			std::cin >> usrOpt;
			while (std::cin.fail() || std::cin.peek() != '\n') {
				std::cin.clear();
				ClearInputBuffer();
				system("cls");
				std::cout << "Please answer with only one char : " << std::endl;
				std::cin >> usrOpt;
			}
			if (!(usrOpt == 'e' || usrOpt == 'o')) {
				system("cls");
				std::cout << "Answer unknown, please answer with [e/o]" << std::endl;
				isAccepted = false;
			}
		} while (!isAccepted);
		return usrOpt;
	}



	void RunEvenOrOdd() {

		int oddOrEvenProfitLoss = 0;
		const short UPER_LIMIT = 1000;
		const short UNDER_LIMIT = -1000;
		bool isKeepPlaying = true;
		bool isPlayerLegit = true;
		std::string gameName = "Odd/Even";

		while (isKeepPlaying && isGameActive) {

			system("cls");
			ClearInputBuffer();
			BettingDialouge();

			char usrGuess = GetUserGuess();
			if (usrGuess == 'o') {

				std::cout << "\n	You have bet on an odd number!" << std::endl;
			}
			else {
				std::cout << "\n	You have bet on an even number!" << std::endl;

			}
			std::string dieSumStr = guess::GetDieSum();

			if (((int)dieSumStr[0] % 2 == 0 && (int)dieSumStr[1] % 2 == 0 && usrGuess == 'e') ||
				((int)dieSumStr[0] % 2 != 0 && (int)dieSumStr[1] % 2 != 0 && usrGuess == 'o')) {

				std::cout << "\n	Daniel: Congratulation bro! You won!";
				currentBudget += playerBet * 2;
				oddOrEvenProfitLoss += playerBet;
				scoreboard::CheckCurrentGameLimit(gameName, &oddOrEvenProfitLoss, isPlayerLegit, isKeepPlaying, UPER_LIMIT, UNDER_LIMIT);
				std::cout << "\n\tYour budget increased to " << currentBudget << std::endl;
				playerBet = 0;
			}
			else {
				std::cout << "\n	Daniel: Sorry man, you lost!";
				currentBudget -= playerBet;
				oddOrEvenProfitLoss -= playerBet;
				playerBet = 0;
				scoreboard::CheckCurrentGameLimit(gameName, &oddOrEvenProfitLoss, isPlayerLegit, isKeepPlaying, UPER_LIMIT, UNDER_LIMIT);
				CheckBudget();
			}
			if (isPlayerLegit && isGameActive) {

				std::cout << "\n\n	Do you want to try again [y / n]: ";
				if (guess::GetUserOption() == 'n') {
					isKeepPlaying = false;
					scoreboard::saveStatistics(gameName, scoreboard::intToString(oddOrEvenProfitLoss));
				}
			}
		}

		system("pause");
	}
}

namespace bar_dice {


	int GetUserDiceResult() {

		std::cout << "\n\tPress [R] on the keyboard to roll the dices: ";
		bool isAccepted{ false };
		char usrOpt{ 'o' };
		do {
			isAccepted = true;
			std::cin >> usrOpt;
			while (std::cin.fail() || std::cin.peek() != '\n') {
				std::cin.clear();
				ClearInputBuffer();
				system("cls");
				std::cout << "Please answer with only one char : " << std::endl;
				std::cin >> usrOpt;
			}
			if (!(usrOpt == 'r' || usrOpt == 'R')) {
				system("cls");
				std::cout << "Answer unknown, please answer with [R/r]" << std::endl;
				isAccepted = false;
			}
		} while (!isAccepted);
		system("cls");
		std::string dieSumStr = guess::GetDieSum();
		int dieSum = (int)dieSumStr[0] + (int)dieSumStr[1];
		std::cout << "\tYour sum is: " << dieSum << std::endl;
		return dieSum;
	}

	void DisplayBarInfo() {
		std::cout << "\tEach drink costs 50$! " << std::endl;
	}

	int GetBotPlayerDiceResult() {
		std::string dieSumStr = guess::GetDieSum();
		int dieSum = (int)dieSumStr[0] + (int)dieSumStr[1];
		system("cls");
		std::cout << "\tDaniel's sum is: " << dieSum << std::endl;
		return dieSum;
	}



	void RunBar_Dice() {

		int bar_diceProfitLoss = 0;
		const p_byte DRINK_PRICE = 50;
		const short UPER_LIMIT = 400;
		const short UNDER_LIMIT = -400;
		bool isKeepPlaying = true;
		bool isPlayerLegit = true;
		std::string gameName = "Bar_Dice";

		while (isKeepPlaying && isGameActive) {

			system("cls");
			ClearInputBuffer();
			DisplayBarInfo();
			int botResult = GetBotPlayerDiceResult();
			int usrResult = GetUserDiceResult();

			if (botResult < usrResult) {

				std::cout << "\n	Daniel: Damn! I'll swish you the money!";
				currentBudget += DRINK_PRICE;
				bar_diceProfitLoss += DRINK_PRICE;
				scoreboard::CheckCurrentGameLimit(gameName, &bar_diceProfitLoss, isPlayerLegit, isKeepPlaying, UPER_LIMIT, UNDER_LIMIT);
				std::cout << "\n\tYour budget increased to " << currentBudget << std::endl;
			}
			else if (botResult > usrResult) {
				std::cout << "\n	Daniel: Sorry man, I will watch you paying for my drink!";
				currentBudget -= DRINK_PRICE;
				bar_diceProfitLoss -= DRINK_PRICE;
				scoreboard::CheckCurrentGameLimit(gameName, &bar_diceProfitLoss, isPlayerLegit, isKeepPlaying, UPER_LIMIT, UNDER_LIMIT);
				CheckBudget();
			}
			if (isPlayerLegit && isGameActive) {

				std::cout << "\n\n	Do you want to try again [y / n]: ";
				if (guess::GetUserOption() == 'n') {
					isKeepPlaying = false;
					scoreboard::saveStatistics(gameName, scoreboard::intToString(bar_diceProfitLoss));

				}
			}
		}
		system("pause");
	}
}


namespace menu {

	int GetUserOption() {

		std::cout << "	Casino 1.2	" << std::endl;
		std::cout << "	Press [1] :: Play Guessing Game	" << std::endl;
		std::cout << "	Press [2] :: Play Odd/Even Game " << std::endl;
		std::cout << "	Press [3] :: Play Bar_Dice " << std::endl;
		std::cout << "	Press [4] :: Display statistics " << std::endl;

		std::cout << "	Your choice: ";
		int usrInput{ 0 };
		bool isAccepted{ false };
		do {
			isAccepted = true;
			std::cin >> usrInput;
			while (std::cin.fail() || std::cin.peek() != '\n') {
				std::cin.clear();
				ClearInputBuffer();
				system("cls");
				std::cout << "Please enter the right format: " << std::endl;
				std::cin >> usrInput;
			}
			if (!(usrInput == 1 || usrInput == 2 || usrInput == 3 || usrInput == 4)) {
				system("cls");
				std::cout << "Your choices are 1, 2, 3 or 4 " << std::endl;
				isAccepted = false;
			}
		} while (!isAccepted);

		return usrInput;
	}


	void RunCasino() {

		isGameActive = true;
		enum class Optiones
		{
			Guess = 1, OddOrEven, Bar_Dice, ScoreBoard
		};

		while (isGameActive) {

			system("cls");
			DisplayRules();

			switch (GetUserOption())
			{

			case static_cast<int>(Optiones::Guess):
				guess::RunGuess();
				break;
			case static_cast<int>(Optiones::OddOrEven):
				oddOrEven::RunEvenOrOdd();
				break;
			case static_cast<int>(Optiones::Bar_Dice):
				bar_dice::RunBar_Dice();
				break;
			case static_cast<int>(Optiones::ScoreBoard):
				scoreboard::RunBoard();
				break;
			}

		}
	}
}



int main() {
	menu::RunCasino();
	return 0;
}