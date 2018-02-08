/* 
 * File:   VendingMachine.cpp
 * Author: John Donahue
 * 
 * Created on 1 February 2018, 10:26 AM
 * Version: 7 Feb 2018
 */

#include <iostream>
#include <string>
#include <sstream>
#include "Product.h"
#include "Queue.h"
#include "VendingMachine.h"

/*
 * Constructor for the VendingMacine class.
 *   Sets default values and allocated memory for Queues
 */
VendingMachine::VendingMachine() {
    numRows = 5;
    numCols = 3;
    moneyEarned = 0;
    moneySpent = 0;
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            Queue *test = new Queue();
            grid[i][j] = test; // allocate memory
            prices[i][j] = 0.00;
        }
    }
}

VendingMachine::VendingMachine(const VendingMachine& orig) {
}

VendingMachine::~VendingMachine() {
}

/* - - - - - - - - Accessor Functions - - - - - - - - */

int VendingMachine::getNumRows()
{
    return numRows;
}

int VendingMachine::getNumCols()
{
    return numCols;
}

double VendingMachine::getPrice(int row, int col)
{
    return prices[row][col];
}

double VendingMachine::getMoneyEarned()
{
    return moneyEarned;
}

Queue* VendingMachine::getSlot(int row, int col)
{
    return grid[row][col];
}

/* - - - - - - - - Mutator Functions - - - - - - - - */

void VendingMachine::setPrice(int row, int col, double price)
{
    prices[row][col] = price;
}

double VendingMachine::getMoneySpent()
{
    return moneySpent;
}

void VendingMachine::addMoneyEarned(double money)
{
    moneyEarned += money;
}

void VendingMachine::addMoneySpent(double money)
{
    moneySpent += money;
}

/* - - - - - - - - Important Functions - - - - - - - - */

bool VendingMachine::isEmpty()
{
    // go through all Queue's in 2-D array
    // if a single one is not empty, return false
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            if (grid[i][j]->isEmpty() == 0) // (false)
            {
                return false;
            }
        }
    }
    return true;
}

int VendingMachine::fillSlot(int row, int col, Product& product)
{
    int counter = 0;
    // if the slot is already full, return false
    // otherwise, add products until it becomes full and return true
    if (grid[row][col]->getNumItems() == 5)
    {
        return counter;
    }
    else
    {
        while (grid[row][col]->getNumItems() < 5)
        {
            grid[row][col]->enqueue(product);
            counter++;
        }
        return counter;
    }
}  

void VendingMachine::createDefaultMachine()
{
    /* Create default products to fill machine */
    Product *snickers = new Product("Snickers", "Chocolate Bar", "Unhealthy");
    Product *gatorade = new Product("Gatorade", "Drink", "Healthy");
    Product *apple = new Product("Apple", "Fruit", "Healthy");
    Product *celery = new Product("Celery Sticks", "Vegetable", "Healthy");
    Product *musketeers = new Product("3 Musketeers", "Chocolate Bar", "Unhealthy");
    
    /* Fill machine with default products */
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 3; j++) // same product going across
        {
            if (i == 0){ this->fillSlot(i, j, *snickers); 
                    prices[i][j] = 1.00; }
            else if (i == 1) { this->fillSlot(i, j, *gatorade); 
                    prices[i][j] = 1.75; }
            else if (i == 2) { this->fillSlot(i, j, *apple);
                    prices[i][j] = 0.75;}
            else if (i == 3) { this->fillSlot(i, j, *celery);
                    prices[i][j] = 0.50;}
            else { this->fillSlot(i, j, *musketeers); 
                    prices[i][j] = 1.00;}
        }
    }
}

string VendingMachine::toString()
{
    string result = "";
    for (int i = 0; i < numRows; i++)
    {
        ostringstream iStr;
        iStr << i;
        for (int j = 0; j < numCols; j++)
        {
            ostringstream jStr;
            jStr << j;
            int numProducts = grid[i][j]->getNumItems();
            string nameProducts = "";
            if (grid[i][j]->peek() != NULL)
            {
                nameProducts = grid[i][j]->peek()->getName();
            }
            else
            {
                nameProducts = "EMPTY";
            }
            ostringstream numStr;
            numStr << numProducts;
            result += "Slot [";
            result += iStr.str();
            result += ", ";
            result += jStr.str();
            result += "] contains: ";
            result += numStr.str();
            result += " ";
            result += nameProducts;
            result += "\n";
        }
    }
    return result;
}