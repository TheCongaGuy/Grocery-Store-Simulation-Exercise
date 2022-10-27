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
    
    // Destructor
    ~Queue();

    // Insertion method
    void enqueue(const LinkedList& shoppingList, const int ID);

    // Deletion method
    void dequeue();

    // Check to see if the queue is empty
    // Returns true if queue is empty
    bool isEmpty();

    // Prints the queue to the screen
    void printQueue();

    // Peeks at the head or tail of the queue
    Data* peekHead() const { return pHead->getData(); }
    Data* peekTail() const { return pTail->getData(); }

private:
    // Data members
    QueueNode* pHead;
    QueueNode* pTail;
};

// Runs through the queue to find it's length
// Takes the current head pointer of the queue; Cannot be null
// Returns the number of nodes in the queue
int queueLength(QueueNode* const pHead);