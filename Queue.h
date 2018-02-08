/* 
 * File:   Queue.h
 * Author: John Donahue
 *
 * Created on 31 January 2018, 2:51 PM
 * Version: 7 Feb 2018
 */

#ifndef QUEUE_H
#define	QUEUE_H
#include <iostream>
#include <string>
#include "Product.h"
using namespace std;

/*
 * This class is used to represent a "slot" in a vending machine.
 */
class Queue {
public:
	Queue();
	Queue(const Queue& orig);
	virtual ~Queue();
        bool isEmpty();
        void enqueue(Product& newItem);
        void resize();
        Product dequeue();
        void dequeueAll();
        Product* peek();
        int getNumItems();
        string toString();

private:
        Product* items[5];
        int front;
        int back;
        int numItems;

};

#endif	/* QUEUE_H */

