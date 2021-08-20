//Program 9. Converting Roman Numberals in to intergers.
#include <iostream>
#include <string>
using namespace std;

class romantype
{
private:
	string romanNumbers;
	int numbers;
	

public:
	int convertRoman(string romanNumbers);//converts the romanNumber array into an integer value
	int value(char romanNumeral);//declares the values of the romanNumbers array
	string getNumeral(string romanNumbers);//allows user to view their roman numeral input
};
string romantype::getNumeral(string romanNumbers)
{
	return romanNumbers;
}

int romantype::value(char romanNumeral)
{
	switch (romanNumeral)//order from smallest to large to because array reads from smallest to largest
	{
	case 'I': return 1;
	case 'V': return 5;
	case 'X': return 10;
	case 'L': return 50;
	case 'C': return 100;
	case 'D': return 500;
	case 'M': return 1000;
	}
	
}

int romantype::convertRoman(string romanNumbers)
{
	int arraylength;
	int total = 0;
	int digit = 0;

	arraylength = romanNumbers.length();//used to read roman numerals from right to left to allow easy conversion without going out of bounds.

	for (int i = arraylength - 1; i >= 0; i--)
	{
		if (value(romanNumbers[i]) >= digit)
		{
			total += value(romanNumbers[i]);
		}
		else
		{
			total -= value(romanNumbers[i]);
		}
		digit = value(romanNumbers[i]);
	}
	return total;

}


int main()
{
	int option;
	string romanNumbers = string();

	
	while (true)//continues to allow inputs until user is finished with conversions
	{
		system("cls");
		
		cout << "\t\tRoman Numeral Converter\n\n";
		cout << "Please enter a roman numeral.";
		cin >> romanNumbers;

		romantype conversion;
		cout << "\t\tPlease select an option.\n";
		cout << "1) Output Integers\n";
		cout << "2) Output Roman Numerals\n";
		cout << "3) Quit.\n";
		cout << "\t\t";
		cin >> option;

		if (option == 1)
		{
			cout << " the integer value is: " << conversion.convertRoman(romanNumbers) << endl;
			system("pause");
		}
		else if (option == 2)
		{
			cout << conversion.getNumeral(romanNumbers) << endl;
			system("pause");
		}
		else if (option == 3)
		{
			exit(0);
		}
		else
			while (cin.fail())
			{
				cin.clear();
				cout << "Invalid input" << endl;
				cin.ignore(1000, '\n');
			}

	}

 
	system("pause");
}
