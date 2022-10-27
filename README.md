# Grocery Store Simulation

This project involved simulating queues of customers in a grocery store; tracking their ID, items bought, and time spent in checkout. This program could be expanded to create a report of revenue earned after the elapsed time or a record of reciepts from customers, but that was out of the scope of this assignment.

---

## Structure

```
                                            +---------------------+
                                            |        Main         |
                                            | Queue1       Queue2 |
                                            +---^-------------^---+
                                                |             |    
   +------------------------+               +---+-------------+---+               +------------------------+
   |          Data          |               |        Queue        |               |       LinkedList       |
   |         int ID         +------+        |    qNode* pHead     |        +------+                        |
   | int serTme  int totTme |      |        |    qNode* pTail     |        |      |    listNode* pHead     |
   +------------------------+      |        +---------^-^---------+        |      +-----------^------------+
                                   |                  | |                  |                  |
                                   |       +----------+-+----------+       |      +-----------+------------+
                                   |       |       queueNode       |       |      |        listNode        |
                                   +-------> Data* ctm   LinLis* l <-------+      |    std::string item    |
                                           |     qNode* pNext      |              | lNde* pPrv  lNde* pNxt |
                                           +-----------------------+              +------------------------+

```

At the start of the program, two queues are initialized in **main**. One queue is an express queue, gaining customers much faster than the second queue, A.K.A the normal queue. When a customer arrives they are assigned an ID, a randomly generated shopping list, and enqueued in line of either the express queue or the normal queue, depending on the queue's randomly assigned arrival time. When a customer has waited long enough to get through their service time, they are dequeued and the next customer in line is helped.

In each **list**, it contains only one pointer to a head listNode. When inserting into a list, all the list has to do is create the listNode (we'll call pMem) somewhere in memory with the given string, assign pMem's pNext to the head's pNext, assign the head's pNext's pPrev to pMem, and finally assign the head pointer to pMem.

In each **listNode**, it is solely a container class with getters and setters. The List class assigns most of it's values.

In each **queue**, it contains a pointer to a head queueNode and a tail queueNode. These two pointers are used for enqueuing and dequeuing. When a customer is enqueued, a new queueNode is instantiated on the heap with the customer's ID and Shopping List and (bear with me on this explination), the tail node's pointer to the next node is assigned the address of the new node on the heap. In code, that is `pTail->pNext = new queueNode(ID, list);` The tail pointer is then moved up to the new node. When dequeuing, the pHead pointer's data is moved forward to the head node's next pointer, and a temporary pointer was left in it's place. From there, we can safely delete the data pTemp is pointing at.

In each **queueNode**, there are three pointers; a pointer to the Data contined in the node, a pointer to the Shopping list paired with the data, and a pointer to the next queueNode in line. When a queueNode is constructed, it will copy the contents of the Shopping List over to a Linked List created on the heap. The queueNode will then construct a new Data point on the heap as well, passing in the shopping list the unique ID of the customer, and the next customer's total wait time.

In each **Data** point, the ID of the customer is assigned to it. Using the given list and next customer Data point, the service time and total time are calculated. Service time is 1 unit of time (assumed to be minutes) for each item in the customers shopping list. Total time is simply the service time plus the next customer's total time.
