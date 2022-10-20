#include "queue.hpp"
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

int main(int argc, char argv[])
{
#pragma region
	if (!testEnqueueEmpty())
	{
		std::cout << "Fail EnqueueEmpty()" << std::endl << std::endl;
		return -1;
	}
	system("cls");
	if (!testEnqueueCapOne())
	{
		std::cout << "Fail EnqueueCapOne()" << std::endl << std::endl;
		return -2;
	}
	system("cls");
	if (!testDequeueCapOne())
	{
		std::cout << "Fail DequeueCapOne()" << std::endl << std::endl;
		return -3;
	}
	system("cls");
	if (!testDequeueCapTwo())
	{
		std::cout << "Fail DequeueCapTwo()" << std::endl << std::endl;
		return -4;
	}
	system("cls");
	if (!test24HourRun())
	{
		std::cout << "Fail 24HourRun()" << std::endl << std::endl;
		return -5;
	}
#pragma endregion Test Cases before program start

	// Catches user input
	int runTime;

	// Prompt the user for the runtime of the simulation
	std::cout << "This is a simulation of a grocery store given a certain amount of minutes go by." << std::endl
		<< "There are two checkout lanes, an express lane and a normal lane." << std::endl
		<< "Customers arrive to the express lane every one to five minutes." << std::endl
		<< "Customers arrive to the normal lane every three to eight minutes." << std::endl
		<< "How many minutes would you like to run the simulation for?" << std::endl;

	// Catch the users choice
	std::cin >> runTime;

	std::cout << std::endl << "Running Simulation..." << std::endl;
	system("pause");
	system("cls");

	// Set the seed to the current time
	srand((unsigned)time(NULL));

	// Initialize both queues
	Queue express;
	Queue normal;

	// Integers to track arrival and serve times, as well as customer ID
	int expArr = 0, expServeTime = 0;
	int norArr = 0, norServeTime = 0;
	int customer = 0;

	for (int time = 1; time <= runTime; time++)
	{
		// Decrement the arrival times every minute
		expArr--;
		norArr--;

		// Add another customer when arrival time reaches 0
		if (expArr <= 0)
		{
			// Create a random shopping list
			LinkedList shopList;

			switch (rand() % 4 + 1)
			{
			case 4: shopList.insertFront("Eggs");
			case 3: shopList.insertFront("Bacon");
			case 2: shopList.insertFront("Cheese");
			case 1: shopList.insertFront("Ham");
			}

			// Enqueue the list into the express lane
			express.enqueue(shopList, ++customer);

			// Alert the user that a customer has entered the express lane
			std::cout << "Customer " << express.peekTail()->getCustomerNumber() << " entered Express Lane at " << time << " minutes" << std::endl;

			// Generate a new arrival time
			expArr = rand() % 4 + 1;
		}
		if (norArr <= 0)
		{
			// Populate a random shopping list
			LinkedList shopList;

			switch (rand() % 4 + 1)
			{
			case 4:shopList.insertFront("Eggs");
			case 3:shopList.insertFront("Bacon");
			case 2:shopList.insertFront("Cheese");
			case 1:shopList.insertFront("Ham");
			}

			// Enqueue the list into the normal lane
			normal.enqueue(shopList, ++customer);

			// Alert the user that a customer has entered the normal lane
			std::cout << "Customer " << normal.peekTail()->getCustomerNumber() << " entered Normal Lane at " << time << " minutes" << std::endl;

			// Generate a new arrival time
			norArr = rand() % 6 + 3;
		}

		// Increment the service time when a customer is in line
		if (!express.isEmpty())
		{
			expServeTime++;

			// Dequeue the customer when service time has been reached
			if (express.peekHead()->getServiceTime() <= expServeTime)
			{
				// Alert the user a customer has left the express lane
				std::cout << "Customer " << express.peekHead()->getCustomerNumber() << " exited Express Lane at " << time << " minutes" << std::endl;

				express.dequeue();
				expServeTime = 0;
			}
		}
		if (!normal.isEmpty())
		{
			norServeTime++;

			// Dequeue the customer when service time has been reached
			if (normal.peekHead()->getServiceTime() <= norServeTime)
			{
				// Alert the user a customer has left the express lane
				std::cout << "Customer " << normal.peekHead()->getCustomerNumber() << " exited Normal Lane at " << time << " minutes" << std::endl;

				normal.dequeue();
				norServeTime = 0;
			}
		}

		// Print the queues every 10 minutes
		if (time % 10 == 0)
		{
			std::cout << "Time: " << time << " minutes in." << std::endl << "Express Lane: ";
			express.printQueue();

			std::cout << "Normal Lane: ";
			normal.printQueue();
			
			std::cout << std::endl;
		}
	}

	std::cout << "Complete" << std::endl;

	return 0;
}