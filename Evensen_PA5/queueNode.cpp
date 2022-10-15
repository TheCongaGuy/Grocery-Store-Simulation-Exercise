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
QueueNode::QueueNode(const LinkedList& npShoppingList, const Data* preData)
{
	pData = new Data(npShoppingList, preData);
	pShoppingList = new LinkedList(npShoppingList);
	pNext = nullptr;
}