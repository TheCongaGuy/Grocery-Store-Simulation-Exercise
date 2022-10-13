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

#include "listNode.hpp"

class LinkedList
{
public:
	// Constructors
	LinkedList();
	LinkedList(const LinkedList& rhs);

	// Getters
	ListNode* getHead() const { return mpHead; }

	// Insertion Method
	void insertFront(const string& item);

private:
	ListNode* mpHead;
};

// Gets the length of a linked list
int length(const ListNode* list);