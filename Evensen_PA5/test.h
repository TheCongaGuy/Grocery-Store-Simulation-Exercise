# pragma once

/*******************************************************************************
 * Programmer: Drew Evensen		                                               *
 * Class: CptS 122; Lab Section 7                                              *
 * Programming Assignment: 5	                                               *
 * Date: 10/12/22                                                              *
 *                                                                             *
 * Description: Simulates a grocery store using queues to represent lines of   *
 *				shoppers.													   *
 ******************************************************************************/

#include "queue.hpp"

// Test cases for queue
bool testEnqueueEmpty(); // Enqueue to an empty queue
bool testEnqueueCapOne(); // Enqueue to a queue containing one node
bool testDequeueCapOne(); // Dequeue to a queue containing one node
bool testDequeueCapTwo(); // Dequeue to a queue containing two nodes