#include <iostream>  
#include <iomanip>
#include <fstream>
#include <string>
#include <list>
#include <queue>

using namespace std;
void myList();
void myQueue();

int main()
{


	

	int choice = 0;

	do {
		cout << "1) Use a List\n"
			<< "2) Use a Queue\n"
			<< "Please select an option: ";
		cin >> choice;

	} while (choice != 1 && choice != 2);
	

		
	
	if (choice == 1)
	{
		myList();
	}
	else if (choice == 2)
	{
		myQueue();
	}
	else {
		cout << "ERROR!!" << endl;
	}

	
	
	system("pause");
	return 0;
}

void myList()
{
	double GPA;
	double highest_GPA;
	string name;

	//creates a string object of list 
	list<string> lstvalue;

	ifstream in_file;

	in_file.open("HighestGPAData.txt");

	//Terminates program if input file is not found
	if (!in_file)
	{
		cout << "could not find data"
			<< "Program terminates!"
			<< endl;
		return;
	}

	cout << fixed << showpoint;
	cout << setprecision(2);
	in_file >> GPA >> name;

	highest_GPA = GPA;

	while (in_file)
	{
		if (GPA > highest_GPA)
		{
			lstvalue.clear();
			lstvalue.push_back(name);
			highest_GPA = GPA;
		}
		else if (GPA == highest_GPA)
		{
			lstvalue.push_back(name);
		}
		in_file >> GPA >> name;
	}

	cout << "Highest GPA = " << highest_GPA << endl;
	cout << "The students holding the highest GPA are: " << endl;

	while (!lstvalue.empty())
	{

		cout << lstvalue.front() << endl;

		lstvalue.pop_front();
	}

	cout << endl;

	return;

}

void myQueue()
{
	double GPA;
	double highest_GPA;
	string name;

	queue<string> q1;

	ifstream in_file;

	in_file.open("HighestGPAData.txt");

	if (!in_file)

	{
		cout << "could not find data"

			<< "Program terminates!" << endl;
		return;
	}

	cout << fixed << showpoint;

	cout << setprecision(2);

	in_file >> GPA >> name;

	highest_GPA = GPA;

	while (in_file)

	{

		if (GPA > highest_GPA)

		{

			while (!q1.empty())

				q1.pop();

			q1.push(name);

			highest_GPA = GPA;

		}
		else if (GPA == highest_GPA)

		{
			q1.push(name);

		}

		in_file >> GPA >> name;

	}

	cout << "Highest GPA = " << highest_GPA << endl;
	cout << "The students holding the highest GPA are: " << endl;

	while (!q1.empty())

	{
		cout << q1.front() << endl;

		q1.pop();

	}
	cout << endl;

	return;
}