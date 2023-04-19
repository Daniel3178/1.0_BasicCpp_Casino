#include <iostream>
#include <random>


bool isGameActive{ false };

void DisplayRules() {
	std::cout << "	\n********************************************\n	\
Here are the rules: \n	#1 Follow the rules\n	\
#2 Follow rule #1\n********************************************\n" << std::endl;
}

void ClearInputBuffer() {
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int GetUserGuess() {

	system("cls");
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

int GetDieSum() {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(1, 6);

	int dieRollOne = dis(gen);
	std::cout << " \n\n	Die one is : " << dieRollOne << "\n";
	int dieRollTwo = dis(gen);
	std::cout << "	Die two is : " << dieRollTwo << "\n";

	return dieRollOne + dieRollTwo;
}

void Run() {
	system("cls");
	DisplayRules();
	std::cout << "Press Enter to continue" << std::endl;
	ClearInputBuffer();

	int usrGuess = GetUserGuess();
	std::cout << "\n	Your choise is : " << usrGuess;
	int dieSum = GetDieSum();
	std::cout << "\n	The sum is : " << dieSum;

	if (dieSum == usrGuess) {
		std::cout << "\n	Daniel: Congratulation bro! You won!";
	}
	else {
		std::cout << "\n	Daniel: Sorry man, you lost!";
	}
	std::cout << "\n\n	Do you want to try again [y / n]: ";
	if (GetUserOption() == 'n') {
		isGameActive = false;
	}
}

int main() {
	isGameActive = true;
	while (isGameActive) {
		Run();
	}
	return 0;
}
