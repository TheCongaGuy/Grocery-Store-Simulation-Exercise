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
	// <TEST CASES>
	if(testEnqueueEmpty())
		std::cout << "Passed EnqueueEmpty()" << std::endl << std::endl;

	if (testEnqueueCapOne())
		std::cout << "Passed EnqueueCapOne()" << std::endl << std::endl;

	if (testDequeueCapOne())
		std::cout << "Passed DequeueCapOne()" << std::endl << std::endl;

	if (testDequeueCapTwo())
		std::cout << "Passed DequeueCapTwo()" << std::endl << std::endl;
	// <END TEST CASES>

	return 0;
}