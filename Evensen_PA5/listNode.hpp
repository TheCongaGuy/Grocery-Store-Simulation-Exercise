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

#include <iostream>
#include <string>

using std::string;

class ListNode
{
public:
	// Constructors
	ListNode(const string item);

	// Getters
	string getItem() const { return item; }
	ListNode* getPPrev() const { return mpPrev; }
	ListNode* getPNext() const { return mpNext; }

	// Setters
	void setPPrev(ListNode* nPPrev) { mpPrev = nPPrev; }
	void setPNext(ListNode* nPNext) { mpNext = nPNext; }

private:
	string item;
	ListNode* mpPrev;
	ListNode* mpNext;
};