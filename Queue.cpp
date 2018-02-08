/* 
 * File:   Queue.cpp
 * Author: John Donahue
 * 
 * Created on 31 January 2018, 2:51 PM
 * Version: 7 Feb 2018
 */

#include <iostream>
#include <string>
#include <sstream>
#include "Product.h"
#include "Queue.h"

/*
 * Constructor for the Queue class.
 *   Sets default values
 */
Queue::Queue() {
    front = 0;
    back = 0;
    numItems = 0;
}

Queue::Queue(const Queue& orig) {
}

Queue::~Queue() {
}

/* - - - - - - - - Accessor Functions - - - - - - - - */

bool Queue::isEmpty()
{
    return (numItems == 0);
}

int Queue::getNumItems()
{
    return numItems;
}

/* - - - - - - - - Queue Functions - - - - - - - - */

Product* Queue::peek()
{
    return items[front];
}

void Queue::enqueue(Product& newItem)
{
    Product *myP = &newItem;
    if (numItems == 5) // list is full
    {
        cout << "QueueException on Enqueue" << endl;
    }
    //Add item to list
    items[back] = myP;
    //Increment back
    back = ((back + 1) % 5);
    numItems++;
}

Product Queue::dequeue()
{
    Product *ref;
    if (numItems != 0)
    {
	ref = items[front];
	items[front] = NULL;
	front = ((front + 1) % 5);
	numItems --;
    }
    else
    { 
	cout << "QueueException on Dequeue." <<endl;
    }
    return *ref;
}

void Queue::dequeueAll()
{
    for (int i = 0; i < 5; i++)
    {
        items[i] = NULL;
    }
    front = back = numItems = 0;
}

/* - - - - - - - - Special Functions - - - - - - - - */

string Queue::toString()
{
    string result = "";
    for (int i = 0; i < numItems; i++)
    {
        ostringstream convert;
        convert << (i+1);
	result += convert.str() + " - " + items[(front+i)%5]->toString() + "\n";
    }
    return result;
}
