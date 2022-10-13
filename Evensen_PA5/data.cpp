#include "data.hpp"

/*******************************************************************************
 * Programmer: Drew Evensen		                                               *
 * Class: CptS 122; Lab Section 7                                              *
 * Programming Assignment: 5	                                               *
 * Date: 10/12/22                                                              *
 *                                                                             *
 * Description: Simulates a grocery store using queues to represent lines of   *
 *				shoppers.													   *
 ******************************************************************************/

// Constructors
Data::Data(const LinkedList& shoppingList, const Data* preData)
{
	serviceTime = length(shoppingList.getHead());

	// Starting data point
	if (preData == nullptr)
	{
		customerNumber = 1;
		totalTime = serviceTime;
	}

	// Data point further in list
	else
	{
		customerNumber = 1 + preData->getCustomerNumber();
		totalTime = serviceTime + preData->getTotalTime();
	}
}