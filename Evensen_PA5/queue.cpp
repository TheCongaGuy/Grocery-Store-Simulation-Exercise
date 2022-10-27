#pragma once

/*******************************************************************************
 * Programmer: Drew Evensen		                                               *
 * Class: CptS 122; Lab Section 7                                              *
 * Programming Assignment: 5	                                               *
 * Date: 10/12/22                                                              *
 *                                                                             *
 * Description: Simulates a grocery store using queues to represent lines of   *
 *				shoppers.													   *
 ******************************************************************************/

#include "queue.hpp"

// Constructors
Queue::Queue()
{
	pHead = nullptr;
	pTail = nullptr;
}

// Destructor
Queue::~Queue()
{
	// Iterate through the queue and dequeue all nodes
	while (pHead != nullptr)
		dequeue();
}

// Check to see if queue is empty
// Returns true if queue is empty
bool Queue::isEmpty()
{
	return pHead == nullptr;
}

// Insertion Method
void Queue::enqueue(const LinkedList& nShoppingList, const int ID)
{
	// Queue is empty
	if (isEmpty())
	{
		pHead = new QueueNode(nShoppingList, ID);
		pTail = pHead;
	}

	// Queue is not empty
	else
	{
		pTail->setPNext(new QueueNode(nShoppingList, ID, pTail->getData()));
		pTail = pTail->getPNext();
	}
}

// Deletion method
void Queue::dequeue()
{
	QueueNode* pTemp = pHead;
	pHead = pHead->getPNext();

	if (pHead == nullptr)
		pTail = pHead;
	else
		pHead->updateWaitTime(pTemp->getData()->getServiceTime());

	delete pTemp;
}

// Prints the queue to the screen
void Queue::printQueue()
{
	// Queue is empty
	if (isEmpty())
		std::cout << "Line is currently empty." << std::endl;

	// Queue is not empty
	else
		std::cout << queueLength(pHead) << " customer(s) in line. Estimated wait time: " << pTail->getData()->getTotalTime() << " minutes" << std::endl;
}

// Returns the number of items in a queue
// Takes a pointer to the head of the node
int queueLength(QueueNode* const pHead)
{
	int len = 0;
	QueueNode* pCur = pHead;

	while (pCur != nullptr)
	{
		len++;
		pCur = pCur->getPNext();
	}

	return len;
}