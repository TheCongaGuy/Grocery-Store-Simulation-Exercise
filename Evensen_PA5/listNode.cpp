#include "listNode.hpp"

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
ListNode::ListNode(const string nItem)
{
	item = nItem;
	mpNext = nullptr;
	mpPrev = nullptr;
}