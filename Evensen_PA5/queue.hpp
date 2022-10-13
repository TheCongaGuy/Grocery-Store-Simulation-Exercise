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

#include "queueNode.hpp"

// Given Queue class
class Queue
{
public: // Member functions
    // Constructor
    Queue();

    // Insertion method
    void enqueue(const LinkedList& shoppingList);

    // Check to see if the queue is empty
    // Returns true if queue is empty
    bool isEmpty();

    // Prints the queue to the screen
    void printQueue();

private:
    QueueNode* pHead;
    QueueNode* pTail;
};