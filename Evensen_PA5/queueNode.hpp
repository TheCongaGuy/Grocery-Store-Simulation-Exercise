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

#include "data.hpp"

// Given QueueNode class
class QueueNode
{
public: // Member functions
    // Constructor
    QueueNode(const LinkedList& pShoppingList, const Data* pData = nullptr);

    // Getters
    Data* getData() const { return pData; }
    LinkedList* getShoppingList() const { return pShoppingList; }
    QueueNode* getPNext() const { return pNext; }

    // Setters
    void setPNext(QueueNode* nNext) { pNext = nNext; }
private:
    Data* pData;    // The memory for Data will need to be allocated on the heap as well!
    LinkedList* pShoppingList;
    QueueNode* pNext;
};