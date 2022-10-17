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

	testShop2.insertFront("Bacon");
	newQueue.enqueue(testShop2);

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

	newQueue.dequeue();

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

	newQueue.dequeue();

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
	try
	{
		srand(time(NULL));

		Queue express;
		Queue normal;

		int expArr = 0, expServeTime = 0;
		int norArr = 0, norServeTime = 0;

		for (int time = 1; time <= 1140; time++)
		{
			expArr--;
			norArr--;

			// Add another customer when arrival time reaches 0
			if (expArr <= 0)
			{
				LinkedList shopList;

				switch (rand() % 4 + 1)
				{
				case 4: shopList.insertFront("Eggs");
				case 3: shopList.insertFront("Bacon");
				case 2: shopList.insertFront("Cheese");
				case 1: shopList.insertFront("Ham");
				}

				express.enqueue(shopList);

				expArr = rand() % 4 + 1;
			}
			if (norArr <= 0)
			{
				LinkedList shopList;

				switch (rand() % 4 + 1)
				{
				case 4:shopList.insertFront("Eggs");
				case 3:shopList.insertFront("Bacon");
				case 2:shopList.insertFront("Cheese");
				case 1:shopList.insertFront("Ham");
				}

				normal.enqueue(shopList);

				norArr = rand() % 6 + 3;
			}

			// Dequeue customers who are finished
			if (!express.isEmpty())
			{
				expServeTime++;

				if (express.peekHead()->getServiceTime() <= expServeTime)
				{
					express.dequeue();
					expServeTime = 0;
				}
			}
			if (!normal.isEmpty())
			{
				norServeTime++;

				if (normal.peekHead()->getServiceTime() <= norServeTime)
				{
					normal.dequeue();
					norServeTime = 0;
				}
			}
		}

		return true;
	}
	catch (...)
	{
		return false;
	}
}