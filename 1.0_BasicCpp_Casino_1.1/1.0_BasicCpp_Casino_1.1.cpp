#include <iostream>
#include <random>

int sum{ 0 };

void DisplayRules() {
	std::string rules = "Here is the rules: \n#1 Follow the rules\n #2 Follow rule #1";
	std::cout << rules << std::endl;
}

int GetRightFormatInt() {
	int usrInput{ 0 };
	while (!(std::cin >> usrInput)) {
		std::cout << "Wrong answer format, please try again ... \n	";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	return usrInput;
}

char GetRightFormatChar() {
	char usrInput{ 0 };
	while (!(std::cin >> usrInput)) {
		std::cout << "Wrong answer format, please try again ...";
		std::cin.clear();
	}
	return usrInput;
}

int GetUserInput() {
	bool wrong = true;
	system("cls");
	std::cout << "Guess a number between 2 and 12 : ";
	int userInput = GetRightFormatInt();
	while (userInput < 2 || userInput >12) {
		system("cls");
		std::cout << "Guess a number between 2 and 12 : ";
		if (wrong == true) {
			system("cls");
			std::cout << "please follow the instruction! \n";
			std::cout << "Guess a number between 2 and 12 : ";
		}
		userInput = GetRightFormatInt();

	}
	system("cls");
	std::cout << "	Let's see how lucky you are!";
	return userInput;
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


int main()
{
	bool isGameActiv{ true };
	while (isGameActiv) {
		system("cls");
		int a = GetUserInput();
		char userChoice{ 'n' };
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
		userChoice = GetRightFormatChar();
		while (userChoice != 'n' && userChoice != 'y') {
			system("cls");
			std::cout << "\n	invalid input try again, [y/n]: ";
			userChoice = GetRightFormatChar();
			if (userChoice == 'n') {
				isGameActiv = false;
			}

		}
		if (userChoice == 'n') {
			isGameActiv = false;
		}
	}
	return 0;
}


