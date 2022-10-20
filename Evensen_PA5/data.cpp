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
Data::Data(const LinkedList& shoppingList, const int ID, const Data* preData)
{
	serviceTime = length(shoppingList.getHead());
	customerNumber = ID;

	// Starting data point
	if (preData == nullptr)
		totalTime = serviceTime;

	// Data point further in list
	else
		totalTime = serviceTime + preData->getTotalTime();
}