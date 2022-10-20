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

// Copy Constructor
LinkedList::LinkedList(const LinkedList& rhs)
{
	ListNode* pCur = rhs.mpHead;

	while (pCur != nullptr)
	{
		insertFront(pCur->getItem());
		pCur = pCur->getPNext();
	}
}

// Destructor
LinkedList::~LinkedList()
{
	ListNode* pTemp = mpHead;

	while (mpHead != nullptr)
	{
		mpHead = mpHead->getPNext();
		delete pTemp;
		pTemp = mpHead;
	}
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
// Takes the current head of the list
// Returns the number of nodes in the list
int length(const ListNode* const node)
{
	if (node != nullptr)
		return 1 + length(node->getPNext());
	else
		return 0;
}