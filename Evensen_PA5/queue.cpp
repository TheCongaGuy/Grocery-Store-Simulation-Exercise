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

// Check to see if queue is empty
// Returns true if queue is empty
bool Queue::isEmpty()
{
	return pHead == nullptr;
}

// Insertion Method
void Queue::enqueue(const LinkedList& nShoppingList)
{
	// Queue is empty
	if (isEmpty())
	{
		pHead = new QueueNode(nShoppingList);
		pTail = pHead;
	}

	// Queue has one node
	else if (pHead = pTail)
	{
		// Implement: getters and setters for QueueNode, Insertion Method for one node, Insertion Method for multiple nodes
	}

	// Queue has multiple nodes
	else
	{

	}
}

// Prints the queue to the screen
void Queue::printQueue()
{
	// Queue is empty
	if (isEmpty())
		std::cout << "Line is currently empty." << std::endl;

	// Queue is not empty
	else
		std::cout << pTail->getData()->getCustomerNumber() << " customer(s) in line. Estimated wait time: " << pTail->getData()->getTotalTime() << std::endl;
}