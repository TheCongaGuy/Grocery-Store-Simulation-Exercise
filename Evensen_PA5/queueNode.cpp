#include "queueNode.hpp"

/*******************************************************************************
 * Programmer: Drew Evensen		                                               *
 * Class: CptS 122; Lab Section 7                                              *
 * Programming Assignment: 5	                                               *
 * Date: 10/12/22                                                              *
 *                                                                             *
 * Description: Simulates a grocery store using queues to represent lines of   *
 *				shoppers.													   *
 ******************************************************************************/

// Constructors
QueueNode::QueueNode(const LinkedList& npShoppingList, const int ID, const Data* preData)
{
	pData = new Data(npShoppingList, ID, preData);
	pShoppingList = new LinkedList(npShoppingList);
	pNext = nullptr;
}

// Destructor
QueueNode::~QueueNode()
{
	delete pData;
	delete pShoppingList;
}

// Helper setter to update the wait time of the queue
void QueueNode::updateWaitTime(int waitReduce)
{
	// Go through the queue and subtract the wait reduce integer from all nodes
	pData->setTotalTime(pData->getTotalTime() - waitReduce);
	if (pNext != nullptr)
		pNext->updateWaitTime(waitReduce);
}