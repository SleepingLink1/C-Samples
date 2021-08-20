//project 8 Automated Menu
//header files
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <conio.h>
#include <string>
using namespace std;
//food names left justified, cost is right justified to two decimal points.
//function prototypes
void menuItems(string menuList[], double itemCost[], int& maxList);
void showMenu(string menuList[], double itemCost[], int qty[], int& maxList, double& total);
void ClearAll(string menuList[], int qty[]);
void printCheck(string menuList[], double itemCost[], int qty[], double& total);

//structs
struct menuitemType
{
	string menuList[100];
	double itemCost[100];
};



int main()//main Function
{
	menuitemType myMenu;
	bool flag = bool();
	int maxList = int();
	int selection = 0;
	double total = double();
	int qty[8] = {};
	//call function to load menu info
	menuItems(myMenu.menuList, myMenu.itemCost, maxList);
	
	//main menu loop
	while (true)
	{
		system("cls");
		cout << "\t\t    Welcome to Daniel's Diner!" << endl;
		cout << "\t\tDelicious isn't an option, it's a guarantee!" << endl;

		cout << endl << "\t\t1. Menu options" << endl;
		cout << "\t\t2. Clear All Selections" << endl;
		cout << "\t\t3. Finalize Check" << endl;
		cout << "\t\t4. Exit." << endl;

		cout << endl << "\t\t Please make a Selection: ";
		cin >> selection;

		switch (selection)
		{
		case 1://menu module to make selections

			showMenu(myMenu.menuList, myMenu.itemCost, qty, maxList, total);
			break;

		case 2://module to reset options
			ClearAll(myMenu.menuList, qty);
			break;

		case 3://module to print check
			printCheck(myMenu.menuList, myMenu.itemCost, qty, total);
			break;

		case 4: //Exit program
			exit(1);

		default:
			cout << "\t\tInvalid Input. Please enter a Valid option.";
			
		}
		while(cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
		}
	
		//allow customer to select "Go to Menu option
		//call function to go to menu and allow customer to select their food.
		//tally up the check for the customer and output the cost and thank you message.
	}
	return 0;
}

//make a function getData to load info into the array menuList
//load two arrays. one menu item and the other cost into the struct./
void menuItems(string menuList[], double itemCost[], int& maxList)
{
	int i = 0;
	char dummy;
	ifstream in;
	in.open("Data.txt");

	while (!in.eof())
	{
		
		getline(in, menuList[i]);
		in >> itemCost[i];
		in.get(dummy);
		maxList++;
		i++;
	}
}

//make a function showMenu to show different menu items and tell the user to select menu items.
void showMenu(string menuList[], double itemCost[], int qty[], int& maxList, double& total)
{
	system("cls");
	bool flag = bool();
	int i = 0;
	int listItem = 1;	
	int selection = 0;
	
	while (true)//display menu options
	{
		system("cls");
		cout << "\t\t    Welcome to Daniel's Diner!" << endl;
		cout << "\t\tDelicious isn't an option, it's a guarantee!" << endl;
		cout << fixed << showpoint;
		
		while (i < maxList)
		{
			cout << listItem << ". " << setfill(' ') << left << setw(25) << menuList[i] << " "
				<< setprecision(2) << setfill(' ') << right << setw(8)
				<< "$" << itemCost[i] << " " << setfill(' ') << right << setw(3)
				 << qty[i] << " " << endl;
			i++;
			listItem++;
		}
		cout << "Please make a Selection or Enter 0 to return to the main menu: ";
		cin >> selection;
		
		if (selection <= 8 && selection != 0)
		{
			selection = selection - 1;
			cout << "\t\t Please Enter the Quantity: ";
			cin >> qty[selection];
			i = 0;
			listItem = 1;
		}
		else if (selection > 8)
		{
			i = 0;
			listItem = 1;
			cout << "Invalid Input.\n";
		}
		else if (selection == false || selection == 0)
		{
			break;
		}
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(10000, '\n');
		}
	}
}

//module to clear all selections
void ClearAll(string menuList[],int qty[])
{
	char cont = char();
	
	system("cls");
	cout << "\t\t    Welcome to Daniel's Diner!" << endl;
	cout << "\t\tDelicious isn't an option, it's a guarantee!\n\n";

	for (int i = 0; i < 8; i++)
	{ 
		if (qty[i] > 0)
		{
			cout << setfill(' ') << left << setw(25) << menuList[i] << " "
				<< setfill(' ') << right << setw(8) << qty[i] << " " << endl;
		}
	}
	cout << "\t\tDelete all items? (Y)es/(N)o: ";
	cin >> cont;
	if (cont == 'Y' || cont == 'y')
	{
		for (int i = 0; i < 8; i++)
		{
			qty[i] = 0;
		}
	}
	else
		return;
}

//make function printCheck to calculate and print the check along with a 5% tax.
void printCheck(string menuList[], double itemCost[], int qty[], double& total)
{
	int i = 0;
	double salesTax = .05;
	cout << fixed << showpoint;
	
	system("cls");
	cout << "\t\t    Welcome to Daniel's Diner!" << endl;
	cout << "\t\tDelicious isn't an option, it's a guarantee!\n\n";
	
	for (int i = 0; i < 8; i++)
	{	
		
		if (qty[i] > 0)
		{
			double itemTotal = 0;

			itemTotal = itemCost[i] * static_cast<double> (qty[i]);

			cout << setprecision(0) << qty[i] << " " << setfill(' ') << left << setw(25)
				 << menuList[i] << " " << setprecision(2) << setfill(' ') << right << setw(8) << "$"
				 << itemTotal << endl;

			total = total + itemTotal;
		}
	}
	if (total == 0)
	{
		cout << "No selections have been made. Press any key to return to the main menu." << endl;
		system("pause");
		return;
	}
	cout << "  " << setfill(' ') << left << setw(26) << "Net Total: "
		<< setprecision(2) << setfill(' ') << right << setw(8) << "$" << total << endl;

	salesTax = total * salesTax;
	total = total + salesTax;
	cout << "  " << setfill(' ') << left << setw(26) << "Tax (5%)"
		 << setprecision(2) << setfill(' ') << right << setw(8) << "$" << salesTax << endl;

	cout << "  " << setfill(' ') << left << setw(25) << "Amount Due: "
		<< setprecision(2) << setfill(' ') << right << setw(8) << "$" << total << endl;
	
	system("pause");
	exit(1);
}