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
	std::cout << "Enqueue Test 1: " << std::endl;
	testShop.insertFront("Milk");
	testShop.insertFront("Eggs");
	testShop.insertFront("Yogurt");
	newQueue.enqueue(testShop);
	newQueue.printQueue();

	if (newQueue.isEmpty())
		return false;
	if (newQueue.peekHead()->getCustomerNumber() != 1)
		return false;
	if (newQueue.peekHead()->getServiceTime() != 3)
		return false;
	if (newQueue.peekHead()->getTotalTime() != 3)
		return false;
	

	// <------ Test 2 ------>
	std::cout << "Enqueue Test 2: " << std::endl;
	testShop2.insertFront("Bacon");
	newQueue2.enqueue(testShop2);
	newQueue2.printQueue();

	if (newQueue2.isEmpty())
		return false;
	if (newQueue2.peekHead()->getCustomerNumber() != 1)
		return false;
	if (newQueue2.peekHead()->getServiceTime() != 1)
		return false;
	if (newQueue2.peekHead()->getTotalTime() != 1)
		return false;

	return true;
}

// Enqueue to a queue containing one node
bool testEnqueueCapOne()
{
	Queue newQueue;
	LinkedList testShop, testShop2;

	std::cout << "Enqueue CapOne Test : " << std::endl;
	testShop.insertFront("Milk");
	testShop.insertFront("Eggs");
	testShop.insertFront("Yogurt");
	newQueue.enqueue(testShop);
	newQueue.printQueue();

	testShop2.insertFront("Bacon");
	newQueue.enqueue(testShop2);
	newQueue.printQueue();

	if (newQueue.isEmpty())
		return false;
	if (newQueue.peekTail()->getCustomerNumber() != 2 || newQueue.peekHead()->getCustomerNumber() != 1)
		return false;
	if (newQueue.peekTail()->getServiceTime() != 1 || newQueue.peekHead()->getServiceTime() != 3)
		return false;
	if (newQueue.peekTail()->getTotalTime() != 4)
		return false;

	return true;
}

// Dequeue to a queue containing one node
bool testDequeueCapOne()
{
	Queue newQueue;
	LinkedList testShop;

	std::cout << "Dequeue CapOne Test: " << std::endl;
	testShop.insertFront("Milk");
	testShop.insertFront("Eggs");
	testShop.insertFront("Yogurt");
	newQueue.enqueue(testShop);
	newQueue.printQueue();

	newQueue.dequeue();

	newQueue.printQueue();

	if (!newQueue.isEmpty())
		return false;

	return true;
}

// Dequeue to a queue containing two nodes
bool testDequeueCapTwo()
{
	Queue newQueue;
	LinkedList testShop;

	std::cout << "Dequeue CapTwo Test: " << std::endl;
	testShop.insertFront("Milk");
	testShop.insertFront("Eggs");
	testShop.insertFront("Yogurt");
	newQueue.enqueue(testShop);
	newQueue.enqueue(testShop);
	newQueue.printQueue();

	newQueue.dequeue();

	newQueue.printQueue();

	if (newQueue.peekTail()->getCustomerNumber() != 1)
		return false;
	if (newQueue.peekTail()->getServiceTime() != 3 || newQueue.peekTail()->getTotalTime() != 3)
		return false;
	if (newQueue.peekHead() != newQueue.peekTail())
		return false;

	return true;
}