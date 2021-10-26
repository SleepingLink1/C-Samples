#pragma once
#include <iostream> 
#include <cassert>
using namespace std;

template <class Type>
class queueADT
{
public:
	virtual bool isEmptyQueue() const = 0;
	virtual bool isFullQueue() const = 0;
	virtual void initializeQueue() = 0;
	virtual Type front() const = 0; //Function to return the first element of the queue.
	virtual Type back() const = 0; //Function to return the last element of the queue.
	virtual void addQueue(const Type& queueElement) = 0; //Function to add queueElement to the queue.
	virtual void deleteQueue() = 0; //Function to remove the first element of the queue.
};

template <class Type>
class queueType : public queueADT<Type>
{
private:
	int maxQueueSize; //variable to store the maximum queue size
	int count;        //variable to store the number of elements in the queue
	int queueFront;   //variable to point to the first element of the queue
	int queueRear;    //variable to point to the last element of the queue
	Type *list;       //pointer to the array that holds the queue elements 

public:
	queueType(int queueSize = 100) //Constructor
	{
		if (queueSize <= 0)
		{
			cerr << "Size of the array to hold the queue must "
				<< "be positive." << endl;
			cerr << "Creating an array of size 100." << endl;

			maxQueueSize = 100;
		}
		else
			maxQueueSize = queueSize;   //set maxQueueSize to queueSize

		queueFront = 0;                 //initialize queueFront
		queueRear = maxQueueSize - 1;   //initialize queueRear
		count = 0;
		list = new Type[maxQueueSize];  //create the array to hold the queue elements
	}

	queueType(const queueType<Type>& otherQueue) //Copy constructor
	{
		maxQueueSize = otherQueue.maxQueueSize;
		queueFront = otherQueue.queueFront;
		queueRear = otherQueue.queueRear;
		count = otherQueue.count;

		list = new Type[maxQueueSize];

		//copy other queue in this queue
		for (int j = queueFront; j <= queueRear; j = (j + 1) % maxQueueSize)
			list[j] = otherQueue.list[j];
	} //end copy constructor


	~queueType() //Destructor
	{
		delete[] list;
	}

	const queueType<Type>& operator=(const queueType<Type>& otherQueue) //Overload the assignment operator.
	{
		int j;

		if (this != &otherQueue) //avoid self-copy
		{
			maxQueueSize = otherQueue.maxQueueSize;
			queueFront = otherQueue.queueFront;
			queueRear = otherQueue.queueRear;
			count = otherQueue.count;

			delete[] list;
			list = new Type[maxQueueSize];

			//copy other queue in this queue
			if (count != 0)
				for (j = queueFront; j <= queueRear; j = (j + 1) % maxQueueSize)
					list[j] = otherQueue.list[j];
		} //end if

		return *this;
	}


	bool isEmptyQueue() const //Function to determine whether the queue is empty.
	{
		return (count == 0);
	} //end isEmptyQueue


	bool isFullQueue() const //Function to determine whether the queue is full.
	{
		return (count == maxQueueSize);
	} //end isFullQueue

	void initializeQueue() //Function to initialize the queue to an empty state.
	{
		queueFront = 0;
		queueRear = maxQueueSize - 1;
		count = 0;
	}

	Type front() const //Function to return the first element of the queue.
	{
		assert(!isEmptyQueue());
		return list[queueFront];
	}

	Type back() const //Function to return the last element of the queue.
	{
		assert(!isEmptyQueue());
		return list[queueRear];
	} //end back

	void addQueue(const Type& newElement) //Function to add queueElement to the queue.
	{
		if (!isFullQueue())
		{
			queueRear = (queueRear + 1) % maxQueueSize; //use mod
														//operator to advance queueRear  
														//because the array is circular
			count++;
			list[queueRear] = newElement;
		}
		else
			cerr << "Cannot add to a full queue." << endl;
	}


	void deleteQueue()  //Function to remove the first element of the queue.
	{
		if (!isEmptyQueue())
		{
			count--;
			queueFront = (queueFront + 1) % maxQueueSize; //use the
														  //mod operator to advance queueFront 
														  //because the array is circular 
		}
		else
			cerr << "Cannot remove from an empty queue." << endl;
	}
};

void testCopyConstructor(queueType<int> otherQueue);


void testCopyConstructor(queueType<int> otherQueue)
{
	if (!otherQueue.isEmptyQueue())
	{
		cout << "Other Queue is not empty" << endl;
		cout << "Front element of Other Queue : "
			<< otherQueue.front() << endl;
		otherQueue.deleteQueue();
	}
}