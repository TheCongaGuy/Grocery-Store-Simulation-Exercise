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
	// Initialize two test queues and lists
	Queue newQueue, newQueue2;
	LinkedList testShop, testShop2;

	// <------ Test 1 ------>
	// Populate queue 1 and list 1
	testShop.insertFront("Milk");
	testShop.insertFront("Eggs");
	testShop.insertFront("Yogurt");
	newQueue.enqueue(testShop, 1);

	// If the queue is empty, customer number is not 1, service time and total time are not 3 the test fails
	if (newQueue.isEmpty())
		return false;
	if (newQueue.peekHead()->getCustomerNumber() != 1)
		return false;
	if (newQueue.peekHead()->getServiceTime() != 3)
		return false;
	if (newQueue.peekHead()->getTotalTime() != 3)
		return false;
	

	// <------ Test 2 ------>
	// Populate queue 2 and list 2
	testShop2.insertFront("Bacon");
	newQueue2.enqueue(testShop2, 1);

	// If the queue is empty, customer number is not 1, service time or total time are not 1 the test fails
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
	// Initialize the test queue and two test lists
	Queue newQueue;
	LinkedList testShop, testShop2;

	// Populate queue 1 and list 1
	testShop.insertFront("Milk");
	testShop.insertFront("Eggs");
	testShop.insertFront("Yogurt");
	newQueue.enqueue(testShop, 1);

	// Populate and insert list 2 into the queue
	testShop2.insertFront("Bacon");
	newQueue.enqueue(testShop2, 2);

	// If the queue is empty, customer numbers are incorrect, service times are incorrect or total time is incorrect the test fails
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
	// Initialize the test queue and list
	Queue newQueue;
	LinkedList testShop;

	// Populate the queue and list
	testShop.insertFront("Milk");
	testShop.insertFront("Eggs");
	testShop.insertFront("Yogurt");
	newQueue.enqueue(testShop, 1);

	// Remove the head node from the queue
	newQueue.dequeue();

	// If the queue is not empty the test fails
	if (!newQueue.isEmpty())
		return false;

	return true;
}

// Dequeue to a queue containing two nodes
bool testDequeueCapTwo()
{
	// Initialize the test queue and list
	Queue newQueue;
	LinkedList testShop;

	// Populate the queue with two lists
	testShop.insertFront("Milk");
	testShop.insertFront("Eggs");
	testShop.insertFront("Yogurt");
	newQueue.enqueue(testShop, 1);
	newQueue.enqueue(testShop, 2);

	// Remove the first node in the queue
	newQueue.dequeue();

	// If the customer number is incorrect, service time is incorrect or total time is incorrect the test fails
	if (newQueue.peekTail()->getCustomerNumber() != 2)
		return false;
	if (newQueue.peekTail()->getServiceTime() != 3)
		return false;
	if (newQueue.peekHead() != newQueue.peekTail())
		return false;
	if (newQueue.peekTail()->getTotalTime() != 3)
		return false;

	return true;
}

bool test24HourRun()
{
	// Try to run a simulation for 24 hours
	try
	{
		// Set the seed to the current time
		srand((unsigned)time(NULL));

		// Initialize both queues
		Queue express;
		Queue normal;

		// Integers to track arrival and serve times, as well as customer ID
		int expArr = 0, expServeTime = 0;
		int norArr = 0, norServeTime = 0;
		int customer = 0;

		// Loop through 1140 units of time (24 hours | 1140 minutes)
		for (int time = 1; time <= 1140; time++)
		{
			// Count down the arrival times each minute
			expArr--;
			norArr--;

			// Add another customer when arrival time reaches 0
			if (expArr <= 0)
			{
				// Populate a new random shopping list
				LinkedList shopList;

				switch (rand() % 4 + 1)
				{
				case 4: shopList.insertFront("Eggs");
				case 3: shopList.insertFront("Bacon");
				case 2: shopList.insertFront("Cheese");
				case 1: shopList.insertFront("Ham");
				}

				// Enqueue the new shopping list to the express lane and increment the customer's ID
				express.enqueue(shopList, ++customer);

				// Generate a new random arrival time
				expArr = rand() % 5 + 1;
			}
			if (norArr <= 0)
			{
				// Populate a new random shopping list
				LinkedList shopList;

				switch (rand() % 4 + 1)
				{
				case 4:shopList.insertFront("Eggs");
				case 3:shopList.insertFront("Bacon");
				case 2:shopList.insertFront("Cheese");
				case 1:shopList.insertFront("Ham");
				}

				// Enqueue the new shopping list to the normal lane and increment the customer's ID
				normal.enqueue(shopList, ++customer);

				// Generate a new random arrival time
				norArr = rand() % 6 + 3;
			}

			// Only count service time when customer is in line
			if (!express.isEmpty())
			{
				expServeTime++;

				// Dequeue when service time matches customer's
				if (express.peekHead()->getServiceTime() <= expServeTime)
				{
					express.dequeue();
					expServeTime = 0;
				}
			}

			// Only count service time when customer is in line
			if (!normal.isEmpty())
			{
				norServeTime++;

				// Dequeue when service time matches customer's
				if (normal.peekHead()->getServiceTime() <= norServeTime)
				{
					normal.dequeue();
					norServeTime = 0;
				}
			}
		}

		// If the program does not crash it passes
		return true;
	}
	// If the program crashes the test fails
	catch (...)
	{
		std::cout << "Fail" << std::endl;
		return false;
	}
}