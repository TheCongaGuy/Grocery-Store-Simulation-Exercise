#include "shoppingList.hpp"

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
LinkedList::LinkedList()
{
	mpHead = nullptr;
}
LinkedList::LinkedList(const LinkedList& rhs)
{
	mpHead = rhs.mpHead;
}

// Insertion Method
void LinkedList::insertFront(const string& item)
{
	ListNode* pMem = new ListNode(item);

	// List is empty
	if (mpHead == nullptr)
		mpHead = pMem;

	// List is not empty
	else
	{
		mpHead->setPPrev(pMem);
		pMem->setPNext(mpHead);
		mpHead = pMem;
	}
}

// Gets the length of a linked list
int length(const ListNode* node)
{
	if (node != nullptr)
		return 1 + length(node->getPNext());
	else
		return 0;
}