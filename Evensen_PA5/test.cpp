#include "test.h"

/*******************************************************************************
 * Programmer: Drew Evensen		                                               *
 * Class: CptS 122; Lab Section 7                                              *
 * Programming Assignment: 5	                                               *
 * Date: 10/12/22                                                              *
 *                                                                             *
 * Description: Simulates a grocery store using queues to represent lines of   *
 *				shoppers.													   *
 ******************************************************************************/

 // Test cases for queue
// Enqueue to an empty queue
bool testEnqueueEmpty()
{
	Queue newQueue, newQueue2;
	LinkedList testShop, testShop2;

	// <------ Test 1 ------>
	std::cout << "Queue 1: " << std::endl;
	testShop.insertFront("Milk");
	testShop.insertFront("Eggs");
	testShop.insertFront("Yogurt");
	newQueue.enqueue(testShop);
	newQueue.printQueue();
	if (newQueue.isEmpty())
		return false;

	// <------ Test 2 ------>
	std::cout << "Queue 2: " << std::endl;
	testShop2.insertFront("Bacon");
	newQueue2.enqueue(testShop2);
	newQueue2.printQueue();
	if (newQueue.isEmpty())
		return false;

	return true;
}

// Enqueue to a queue containing one node
bool testEnqueueCapOne()
{
	Queue newQueue;
	LinkedList testShop, testShop2;
	testShop.insertFront("Milk");
	testShop.insertFront("Eggs");
	testShop.insertFront("Yogurt");
	newQueue.enqueue(testShop);
	testShop2.insertFront("Bacon");
	newQueue.enqueue(testShop2);
	newQueue.printQueue();

	return true;
}

// Dequeue to a queue containing one node
bool testDequeueCapOne()
{
	Queue newQueue;

	return true;
}

// Dequeue to a queue containing two nodes
bool testDequeueCapTwo()
{
	Queue newQueue;

	return true;
}