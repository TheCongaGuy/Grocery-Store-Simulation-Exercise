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
	if(testEnqueueEmpty())
		std::cout << std::endl << "Passed EnqueueEmpty()" << std::endl;

	if (testEnqueueCapOne())
		std::cout << std::endl << "Passed EnqueueCapOne()" << std::endl;

	return 0;
}