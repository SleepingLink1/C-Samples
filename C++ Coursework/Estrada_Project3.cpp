#include <iostream>
#include <string>
#include "QueueADT.h"
#include "Stacks.h"

using namespace std;

/*program to check if a string is a palindrome
using a queue and stack*/
int main()
{
	//instantiate queue and stack
	queueType<char> wordQueue;
	stackType<char> wordStack;

	string input;

	cout << "\n Please Enter a String:" << endl;
	getline(cin, input, '\n');
	char c;
	//push string onto stack and queue
	for (unsigned int i = 0; i < input.size(); i++)
	{
		c = input.at(i);
		if (c != ' ')
		{
			//convert letter to lowercase
			c = tolower(c);
			//push char onto queue and stack
			wordStack.push(c);
			wordQueue.addQueue(c);

		}
	}
	bool Palindrome = true;

	do //use do loop so the program will assert empty if they are empty.
	{
		if (wordQueue.front() == wordStack.top())
		{
			wordQueue.deleteQueue();
			wordStack.pop();
		}
		else// if elements are not equal
		{
			cout << "\n Current Queue Front = " << wordQueue.front() << endl;
			cout << "Current Stack top = " << wordStack.top() << endl;
			cout << input << " is not a Palindrome." << endl;
			system("pause");
			return 0;
		}
	} while (!wordQueue.isEmptyQueue() && !wordStack.isEmptyStack());


	if (Palindrome) // if palindrome true...
	{
		cout << "Your string: " << input << " is a Palindrome.\n";
	}
	else
	{
		cout << input << " is not a Palindrome." << endl;
	}

	system("pause");
	return 0;
}