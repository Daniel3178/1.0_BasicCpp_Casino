#include "BufferTools.h"
#include "Scoreboard.h"
namespace bufferTools {

	std::string IntToString(int anInt) {
		std::string result = "";
		bool isNegativ = false;
		char temp = 0, digit = 0;

		if (anInt == 0)
		{
			return "0";
		}
		if (anInt < 0)
		{
			anInt = -anInt;
			isNegativ = true;
		}
		while (anInt > 0)
		{
			digit = 0;
			digit = anInt % 10;
			result += '0' + digit;
			anInt /= 10;
		}
		if (isNegativ) {
			result += '-';
		}

		for (size_t i = 0, j = result.length()-1; i <= j; i++, j--)
		{
			temp = result[i];
			result[i] = result[j];
			result[j] = temp;
		}
		return result;
	}
	void ClearInputBuffer()
	{
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	void DisplayCurrentBudget(int& aBudget)
	{
		std::cout << "		Your current budget is: " << aBudget << '\n';
	}
	void DisplayRules()
	{
		std::cout << "	\n********************************************\n	\
		Here are the rules: \n	#1 Follow the rules\n	\
		#2 Follow rule #1\n********************************************\n" << '\n';
	}

	char GetUserCharFormat()
	{
		char usrInput{ 0 };
		std::cin >> usrInput;
		while (std::cin.fail() || std::cin.peek() != '\n') {
			std::cin.clear();
			bufferTools::ClearInputBuffer();
			system("cls");
			std::cout << "Please answer with only one char character : " << '\n';
			std::cin >> usrInput;
		}
		return usrInput;
	}

	int GetUserIntFormat()
	{
		unsigned int usrInput{ 0 };
		std::cin >> usrInput;
		while (std::cin.fail() || std::cin.peek() != '\n') {
			std::cin.clear();
			bufferTools::ClearInputBuffer();
			system("cls");
			std::cout << "Please answer with only digits : " << '\n';
			std::cin >> usrInput;
		}
		return usrInput;
	}

	char GetUserCharInput(uint8_t aCharInputOption) 
	{
		bool isAccepted{ false };
		char usrOpt{ 'n' };
		do {
			isAccepted = true;
			usrOpt = bufferTools::GetUserCharFormat();
			switch (aCharInputOption)
			{
			case static_cast<uint8_t>(CharInputOption::YesOrNoChoice):
				if (!(usrOpt == 'n' || usrOpt == 'y' || usrOpt == 'x' || usrOpt == 'X'))
				{
					system("cls");
					std::cout << "Answer unknown, please answer with [y/n]" << '\n';
					isAccepted = false;
				}
				break;
			case static_cast<uint8_t>(CharInputOption::CrownAndAnchorSymbolChoice):

				if (!(usrOpt == '1' || usrOpt == '2' || usrOpt == '3' || usrOpt == '4' || usrOpt == '5' || usrOpt == '6')) 
				{
					system("cls");
					std::cout << "Answer unknown, your optiones are [1,2,3,..,6]" << '\n';
					isAccepted = false;
				}
				break;
			case static_cast<uint8_t>(CharInputOption::EvenOrOddChoice):
				if (!(usrOpt == 'e' || usrOpt == 'o'))
				{
					system("cls");
					std::cout << "Answer unknown, please answer with [e/o]" << '\n';
					isAccepted = false;
				}
				break;
			case static_cast<uint8_t>(CharInputOption::Roulette):
				if (!(usrOpt == '1' || usrOpt == '2' || usrOpt == '3' || usrOpt == '4' || usrOpt == '5' || usrOpt == '6'))
				{
					system("cls");
					std::cout << "Answer unknown, your optiones are [1,2,3,..,6]" << '\n';
					isAccepted = false;
				}
			}
		} while (!isAccepted);
		return usrOpt;
	}
	void PlayOrExit(const char aGameName[], int& aProfitLoss, bool& isGameActive, bool& isKeepPlaying, const bool& isPlayerLegit,
		std::array<std::array<std::string, 2>, 6>& aStatisticLst)
	{
		if (isPlayerLegit && isGameActive)
		{
			std::cout << "\n\n	Do you want to try again [y / n] or Exit the casino [x/X]: ";
			char usrOpt = bufferTools::GetUserCharInput(static_cast<uint8_t>(bufferTools::CharInputOption::YesOrNoChoice));
			if (usrOpt == 'n')
			{
				isKeepPlaying = false;
				scoreboard::SaveStatistics(aGameName, bufferTools::IntToString(aProfitLoss), aStatisticLst);
				return;
			}
			else if (usrOpt == 'x' || usrOpt == 'X')
			{
				system("cls");
				std::cout << "Good Bye" << '\n';
				isGameActive = false;
				return;
			}
		}
	}

}