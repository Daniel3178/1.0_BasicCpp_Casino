#include <iostream>
#include <random>

int sum{ 0 };

void DisplayRules() {
	std::string rules = "Here is the rules: \n#1 Follow the rules\n #2 Follow rule #1";
	std::cout << rules << std::endl;
}

int GetUserInput() {
	int userInput{ 0 };
	bool wrong = false;
	system("cls");
	std::cout << "Guess a number between 2 and 12 : ";
	while (userInput < 2 || userInput >12) {
		if (wrong) {
			system("cls");
			std::cout << "please follow the instruction! \n";
			std::cout << "Guess a number between 2 and 12 : ";
		}
		std::cin >> userInput;
		if (userInput < 2 || userInput >12) {
			wrong = true;
		}
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
	int a = GetUserInput();
	std::cout << "\n	Your choise is : " << a;
	GetDieSum();
	std::cout << "\n	The sum is : " << sum;

	if (sum == a) {
		std::cout << "\n	congratulation! You won!";
	}
	else {
		std::cout << "\n	Sorry, you lost!";
	}
	
}


