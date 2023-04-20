#include <iostream>
#include <random>


bool isGameActive{ false };
short budget = 400;
short playerBet = 0;


void ClearInputBuffer() {
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
void DisplayCurrentBudget() {
	std::cout << "		Your current budget is: " << budget << std::endl;
}
void DisplayRules() {
	std::string rules = "	\n********************************************\n	\
Here are the rules: \n	#1 Follow the rules\n	\
#2 Follow rule #1\n********************************************\n";
	std::cout << rules << std::endl;
}
void BettingDialouge() {
	std::cout << "\n	Your current budget is: " << budget;
	std::cout << "\n	Please enter the amount you want to bet: ";
	/*	int usrInput{ 0 };*/
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
		if (!(playerBet <= budget && playerBet > 0)) {
			system("cls");
			std::cout << "Remeber, you are only allowed to bet above 0$ and less than the maximum budget!" << std::endl;
			isAccepted = false;
		}
		if (playerBet == budget) {
			std::cout << "\n	Warning! you are about to go all in!!" << std::endl;
		}
	} while (!isAccepted);

}

void CheckBudget() {
	if (budget == 0) {
		system("cls");
		std::cout << "	You ran out of money!\n		The escort will lead you out... \n";
		isGameActive = false;
	}
}






namespace guess {
	int GetUserGuess() {

		//system("cls");
		std::cout << "Please guess a number between 2 and 12" << std::endl;
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
		bool isKeepPlaying = true;
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
			budget += playerBet * 2;
			playerBet = 0;
		}
		else {
			std::cout << "\n	Daniel: Sorry man, you lost!";
			budget -= playerBet;
			playerBet = 0;
			CheckBudget();
		}
		std::cout << "\n\n	Do you want to try again [y / n]: ";
		if (GetUserOption() == 'n') {
			isKeepPlaying = false;
		}
		}
	}
}

namespace oddOrEven {

	char GetUserGuess() {
		//system("cls");
		std::cout << "Do you want to bet on even or odd number? answer with [e/o]: " << std::endl;
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
		bool isKeepPlaying = true;
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
				budget += playerBet * 2;
				playerBet = 0;
			}
			else {
				std::cout << "\n	Daniel: Sorry man, you lost!";
				budget -= playerBet;
				playerBet = 0;
				CheckBudget();
			}
			std::cout << "\n\n	Do you want to try again [y / n]: ";
			if (guess::GetUserOption() == 'n') {
				isKeepPlaying = false;
			}
		}
	}
}


namespace menue {

	int GetUserOption() {
		//system("cls");
		std::cout << "	Casino 1.2	" << std::endl;
		std::cout << "	Press [1] :: Play Guessing Game	" << std::endl;
		std::cout << "	Press [2] :: Play Odd/Even Game " << std::endl;
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
			if (!(usrInput == 1 || usrInput == 2)) {
				system("cls");
				std::cout << "Your choices are 1 or 2 " << std::endl;
				isAccepted = false;
			}
		} while (!isAccepted);

		return usrInput;
	}


	void RunCasino() {
		isGameActive = true;
		while (isGameActive) {
			system("cls");
			DisplayRules();

			switch (GetUserOption())
			{

			case 1:
				guess::RunGuess();
				break;
			case 2:
				oddOrEven::RunEvenOrOdd();
				break;
			}
		}
	}
}



int main() {
	menue::RunCasino();
	return 0;
}