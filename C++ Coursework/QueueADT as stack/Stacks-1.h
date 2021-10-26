#pragma once
#include <iostream>
#include <cassert>
#include <string>
using namespace std;

template <class Type>
class stackADT
{
public:
	virtual void initializeStack() = 0;
	virtual bool isEmptyStack() const = 0;
	virtual bool isFullStack() const = 0;
	virtual void push(const Type& newItem) = 0;
	virtual Type top() const = 0;
	virtual void pop() = 0;
};

template <class Type>
class stackType : public stackADT<Type>
{
private:
	int maxStackSize;
	int stackTop;
	Type *list;
public:
	void initializeStack()
	{
		stackTop = 0;
		
	}

	void print()
	{
		for (int i = 0; i < stackTop; i++)
		{
			cout << list[i] << endl;
		}
	}

	bool isEmptyStack() const
	{
		return(stackTop == 0);
	}

	bool isFullStack() const
	{
		return(stackTop == maxStackSize);
	}

	void push(const Type& newItem)
	{
		if (!isFullStack())
		{
			list[stackTop] = newItem;
			stackTop++;
		}
		else
		{
			cout << "Cannot add to a full stack." << endl;
		}
		

		
	}

	Type top() const
	{
		assert(stackTop != 0); //if stack is empty, terminate the program.                            
		return list[stackTop - 1];
	}

	void pop()
	{
		if (!isEmptyStack())
			stackTop--;
		else
			cout << "Cannot remove from an empty stack." << endl;

		
	}

	stackType(int stackSize = 100)
	{
		if (stackSize <= 0)
		{
			
			maxStackSize = 100;
		}
		else
		{
			maxStackSize = stackSize;
			
		}

		stackTop = 0;
		list = new Type[maxStackSize];
	}

	stackType(const stackType<Type>& otherStack)
	{
		list = NULL;
		copyStack(otherStack);
	}

	~stackType()
	{
		delete[] list;
	}

	const stackType<Type>& operator=(const stackType<Type>& otherStack)
	{
		if (this != &otherStack)
		{
			copyStack(otherStack);
		}
		return *this;
	}

	bool operator==(const stackType<Type>& otherStack) const
	{
		if (this == &otherStack)
		{
			return true;
		}
		else
		{
			if (stackTop != otherStack.stackTop)
			{
				return false;
			}
			else
			{
				for (int i = 0; i < stackTop; i++)
				{
					if (list[i] != otherStack.list[i])
					{
						return false;
					}
					return true;
				}
			}
		}
	}

	void copyStack(const stackType<Type>& otherStack)
	{
		delete[] list;
		maxStackSize = otherStack.maxStackSize;
		stackTop = otherStack.stackTop;

		list = new Type[maxStackSize];

		//copy otherStack into this stack. 
		for (int j = 0; j < stackTop; j++)
		{
			list[j] = otherStack.list[j];
		}
	}
};
