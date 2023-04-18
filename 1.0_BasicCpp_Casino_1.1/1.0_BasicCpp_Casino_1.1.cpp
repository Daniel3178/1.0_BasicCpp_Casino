#include <iostream>
#include <string>
#include <random>

int sum{ 0 };
bool isGameActive{ false };

void DisplayRules() {
	std::string rules = "	\n********************************************\n	\
Here are the rules: \n	#1 Follow the rules\n	\
#2 Follow rule #1\n********************************************\n";
	std::cout << rules << std::endl;
}

bool IsInt(char aChar) {
	if (aChar >= '0' && aChar <= '9') {
		return true;
	}
	else {
		return false;
	}
}

bool isLetter(char aChar) {
	if ((aChar >= 'A' && aChar <= 'Z') || (aChar >= 'a' && aChar <= 'z')) {
		return true;
	}
	else {
		return false;
	}
}

int StringToInt(std::string aString /*Make sure that aString contains only digits 0-9*/) {
	int result{ 0 };
	int const base{ 10 };
	int decimalPower = (int)aString.length() - 1;
	for (int i = 0; i < aString.length(); i++) {
		int tempFactor = aString[i] - 48;
		int tempResult{ 1 };
		for (int j = 0; j < decimalPower; j++) {
			tempResult *= base;
		}
		result += tempFactor * tempResult;
		decimalPower--;
	}
	return result;
}
int GetUserGuess() {
	std::string usrInput = "";
	bool isAccepted{ true };
	system("cls");
	std::cout << "Guess a number between 2 and 12 : ";
	do {
		isAccepted = true;
		std::cin.clear();
		std::getline(std::cin, usrInput);
		std::cin.clear();
		if (usrInput.length() <= 2 && usrInput.length() > 0) {

			for (int i = 0; i < usrInput.length(); i++) {
				if (!(IsInt(usrInput[i]))) {
					isAccepted = false;
					break;
				}
			}
		}
		else {
			isAccepted = false;
		}
		if (isAccepted && (StringToInt(usrInput) > 12 || StringToInt(usrInput) < 2)) {
			isAccepted = false;
		}

		if (!isAccepted) {
			system("cls");
			std::cout << "Error! wrong input, please enter only a positive integer between 12 and 2" << std::endl;
		}
	} while (!isAccepted);

	return StringToInt(usrInput);

}


char GetUserOption() {

	std::string usrInput = "";
	bool isAccepted{ true };

	do {
		isAccepted = true;
		std::cin.clear();
		std::getline(std::cin, usrInput);
		std::cin.clear();
		if (!(usrInput.length() == 1)) {
			isAccepted = false;
		}
		else {
			if (!(isLetter(usrInput[0]))) {
				isAccepted = false;
			}
			else if (!(usrInput[0] == 'y' || usrInput[0] == 'n')) {
				isAccepted = false;
			}
		}
		if (!isAccepted) {
			system("cls");
			std::cout << "Error! wrong input, please enter only a char characte [y/n]" << std::endl;
		}
	} while (!isAccepted);
	return usrInput[0];

}


void GetDieSum() {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(1, 6);

	int dieRollOne = dis(gen);
	std::cout << " \n\n	Die one is : " << dieRollOne << "\n";
	int dieRollTwo = dis(gen);
	std::cout << "	Die two is : " << dieRollTwo << "\n";

	sum = dieRollOne + dieRollTwo;

}

void Run() {
	system("cls");
	DisplayRules();
	std::cout << "Press Enter to continue" << std::endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	int a = GetUserGuess();

	std::cout << "\n	Your choise is : " << a;
	GetDieSum();
	std::cout << "\n	The sum is : " << sum;

	if (sum == a) {
		std::cout << "\n	congratulation! You won!";
	}
	else {
		std::cout << "\n	Sorry, you lost!";
	}
	std::cout << "\n	Do you want to try again [y / n]: ";
	if (GetUserOption() == 'n') {
		isGameActive = false;
	}
}

int main()
{
	isGameActive = true;

	while (isGameActive) {

		Run();
	}
	return 0;
}


