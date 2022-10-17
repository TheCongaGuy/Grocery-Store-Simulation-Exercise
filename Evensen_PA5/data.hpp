#pragma once

/*******************************************************************************
 * Programmer: Drew Evensen		                                               *
 * Class: CptS 122; Lab Section 7                                              *
 * Programming Assignment: 5	                                               *
 * Date: 10/12/22                                                              *
 *                                                                             *
 * Description: Simulates a grocery store using queues to represent lines of   *
 *				shoppers.													   *
 ******************************************************************************/

#include "shoppingList.hpp"

// Given Data class
class Data
{
public: // Member functions
    // Constructors
    Data(const LinkedList& shoppingList, const Data* preData = nullptr);

    // Getters
    int getCustomerNumber() const { return customerNumber; }
    int getServiceTime() const { return serviceTime; }
    int getTotalTime() const { return totalTime; }

    // Setters
    void setTotalTime(int newTime) { totalTime = newTime; }

private:
    int customerNumber; // Unique identifier; starts at 1; after 24 hours should be reset to 1
    int serviceTime;   // Random time; varies between express and normal lanes; units in minutes
    int totalTime;     // totalTime = serviceTime + sum of serviceTimes of customers in line before this customer; units in minutes
}; // This memory needs to be allocated on the heap!