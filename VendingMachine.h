/* 
 * File:   VendingMachine.h
 * Author: John Donahue
 *
 * Created on 1 February 2018, 10:26 AM
 * Version: 7 Feb 2018
 */

#ifndef VENDINGMACHINE_H
#define	VENDINGMACHINE_H
#include <iostream>
#include <string>
#include "Product.h"
#include "Queue.h"

/*
 * This class is used to represent a common vending machine.
 */
class VendingMachine {
public:
	VendingMachine();
	VendingMachine(const VendingMachine& orig);
	virtual ~VendingMachine();
        int getNumRows();
        int getNumCols();
        bool isEmpty();
        double getPrice(int row, int col);
        void setPrice(int row, int col, double price);
        int fillSlot(int row, int col, Product& product);
        void createDefaultMachine();
        string toString();
        double getMoneyEarned();
        double getMoneySpent();
        void addMoneyEarned(double money);
        void addMoneySpent(double money);
        Queue* getSlot(int row, int col);
        
private:
        int numRows;
        int numCols;
        /* 2-D array made up of Queue objects */
        Queue *grid [5][3];
        /* 2-D array of product prices (double, USD) */
        double prices [5][3]; // direct mapping to the grid
        double moneyEarned;
        double moneySpent; // spent on filling slots
};

#endif	/* VENDINGMACHINE_H */

