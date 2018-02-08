/* 
 * File:   main.cpp
 * Author: John Donahue
 *
 * Created on 31 January 2018, 9:49 AM
 * Version: 7 Feb 2018
 */

#include <cstdlib>
#include <iostream>
#include "Product.h"
#include "Queue.h"
#include "VendingMachine.h"
using namespace std;

string greetingString = "|-- This is the Vending Machine Project! --|\n \t  Developed by J. Donahue\n";
string divider = "|]================================================[|\n";
int NUM_ROWS = 5;
int NUM_COLS = 3;
VendingMachine myMachine;

/*
 * Inform user of possible selections.
 * Take in user selection that needs to be processed.
 * Return user's selection number.
 */
int receiveInstruction()
{
    cout << "Here are your options..." << endl;
    cout << "(1) : Get product from specified slot." << endl;
    cout << "(2) : Check machine slot (product and price)." << endl;
    cout << "(3) : Fill a slot with products." << endl;
    cout << "(4) : Empty a specified slot." << endl;
    cout << "(5) : Empty vending machine." << endl;
    cout << "(6) : Print out machine details." << endl;
    cout << "(7) : Print out sales information." << endl;
    cout << "(8) : Help (Information About Selections)" << endl;
    cout << "(9) : Exit program." << endl;
    cout << "Make your selection now: ";
    int selection;
    cin >> selection;
    cout << selection << endl;
    return selection;
}

/*
 * Take in user's decision number and process appropriately.
 */
bool processInfo(int n)
{
    int row;
    int col;
    switch(n)
    {
        case 1: /* - - - - - - Selection 1 - - - - - - */
            cout << "Get product from specified slot.\n" << endl;
            cout << "What row would you like to choose from? (0-4) ";
            int row;
            cin >> row;
            cout << row << endl;
            cout << "What column would you like to choose from? (0-2) ";
            cin >> col;
            cout << col << endl;
            if (row > 4 || row < 0 || col > 2 || col < 0)
            {
                cout << "ERROR: Selection out of bounds." << endl;
                break;
            }
            if (myMachine.getSlot(row, col)->isEmpty() == true)
            {
                cout << "ERROR! Slot [" << row << ", " << col << "] is empty." << endl;
            }
            else
            {
                cout << "Slot [" << row << ", " << col << "] contains:" << endl;
                cout << myMachine.getSlot(row, col)->dequeue().getName() << endl;;
                myMachine.addMoneyEarned(myMachine.getPrice(row,col));
                cout << "You paid: $" << myMachine.getPrice(row, col) << endl;
            }
            break;
            
        case 2: /* - - - - - - Selection 2 - - - - - - */
            cout << "Check machine slot (product and price).\n" << endl;
            cout << "What row would you like to inspect? (0-4) ";
            cin >> row;
            cout << row << endl;
            cout << "What column would you like to inspect? (0-2) ";
            cin >> col;
            cout << col << endl;
            if (row > 4 || row < 0 || col > 2 || col < 0)
            {
                cout << "ERROR: Selection out of bounds." << endl;
                break;
            }
            if (myMachine.getSlot(row, col)->isEmpty() == true)
            {
                cout << "Slot is empty" << endl;
            }
            else
            {
                cout << "Product: " << myMachine.getSlot(row, col)->peek()->getName() << endl;
                cout << "Type: " << myMachine.getSlot(row, col)->peek()->getType() << endl;
                cout << "Nutrition Facts: " << myMachine.getSlot(row, col)->peek()->getNutritionFacts() << endl;
                cout << "Amount: " << myMachine.getSlot(row, col)->getNumItems() << endl;
                cout << "Price: $" << myMachine.getPrice(row, col) << endl;
            }
            break;
            
        case 3: /* - - - - - - Selection 3 - - - - - - */
            cout << "Fill a slot with products.\n" << endl;
            // NOTE: Fill cost is only half of the selling price
            int numFills;
            double fillCost;
            cout << "What row would you like to choose from? (0-4) ";
            cin >> row;
            cout << row << endl;
            cout << "What column would you like to choose from? (0-2)";
            cin >> col;
            cout << col << endl;
            if (row > 4 || row < 0 || col > 2 || col < 0)
            {
                cout << "ERROR: Selection out of bounds." << endl;
                break;
            }
            if (myMachine.getSlot(row, col)->getNumItems() == 5)
            {
                cout << "Slot already full!" << endl;
                fillCost = 0;
            }
            else
            {
                if (myMachine.getSlot(row, col)->isEmpty() == true)
                {
                    // product info
                    cout << "What is the name of this product? ";
                    string name;
                    cin >> name;
                    cout << name << endl;
                    cout << "What type of product is this? ";
                    string type;
                    cin >> type;
                    cout << type << endl;
                    cout << "What are the nutrition facts for this product? ";
                    string facts;
                    cin >> facts;
                    cout << facts << endl;
                    Product *newProduct = new Product(name, type, facts);
                    // price info
                    cout << "How much does this product cost? ";
                    double productCost;
                    cin >> productCost;
                    cout << productCost << endl;
                    numFills = myMachine.fillSlot(row, col, *newProduct);
                    myMachine.setPrice(row, col, productCost);
                    fillCost = productCost * numFills / 2;
                }
                else
                {
                    Product *tempProduct = myMachine.getSlot(row, col)->peek();
                    numFills = myMachine.fillSlot(row, col, *tempProduct);
                    fillCost = myMachine.getPrice(row, col) * numFills / 2;
                }
            }
            
            myMachine.addMoneySpent(fillCost);
            cout << "Machine paid $" << fillCost << " to fill slot." << endl;
            break;
            
        case 4: /* - - - - - - Selection 4 - - - - - - */
            cout << "Empty a specified slot.\n" << endl;
            // ask for row and column
            // empty and have ***user pay***
            cout << "What row would you like to select? (0-4) ";
            cin >> row;
            cout << row << endl;
            cout << "What column would you like to select> (0-2) ";
            cin >> col;
            cout << col << endl;
            if (row > 4 || row < 0 || col > 2 || col < 0)
            {
                cout << "ERROR: Selection out of bounds." << endl;
                break;
            }
            if (myMachine.getSlot(row, col)->getNumItems() == 0)
            {
                cout << "Slot [" << row << ", " << col << "] is already empty!"<< endl;
            }
            else
            {
                int deqCount = 0;
                double itemEmptyCost = myMachine.getPrice(row, col);
                while (myMachine.getSlot(row, col)->isEmpty() == false)
                {
                    myMachine.getSlot(row, col)->dequeue();
                    deqCount++;
                }
                double slotEmptyCost = deqCount * itemEmptyCost;
                myMachine.addMoneyEarned(slotEmptyCost);
            cout << "User paid $" << slotEmptyCost << " to empty slot." << endl;
            }
            break;
            
        case 5: /* - - - - - - Selection 5 - - - - - - */
            cout << "Empty vending machine.\n" << endl;
            // empty whole machine and ***user pays***
            if (myMachine.isEmpty() == true)
            {
                cout << "Machine is already empty!" << endl;
            }
            else
            {
                cout << "else" << endl;
                cout << "Emptying Vending Machine!" << endl;
                double emptyMachineCost = 0;
                for (int i = 0; i < NUM_ROWS; i++)
                {
                    for (int j = 0; j < NUM_COLS; j++)
                    {
                        double tempPrice = myMachine.getPrice(i,j);
                        if (myMachine.getSlot(i, j)->isEmpty() == false)
                        {
                            emptyMachineCost += tempPrice;
                        }
                    }
                }
                myMachine.addMoneyEarned(emptyMachineCost);
                cout << "User paid $" << emptyMachineCost << " to empty machine." << endl;
                cout << "Vending machine is now empty!" << endl;
            }
            break;
            
        case 6: /* - - - - - - Selection 6 - - - - - - */
            cout << "Print out machine details.\n" << endl;
            cout << "Printing details..." << endl;
            cout << myMachine.toString() << endl;
            break;
            
        case 7: /* - - - - - - Selection 7 - - - - - - */
            cout << "Print out sales information.\n" << endl;
            double earned;
            earned = myMachine.getMoneyEarned();
            double spent;
            spent = myMachine.getMoneySpent();
            double profit;
            profit = earned - spent;
            cout << "Machine Earned: $" << earned << endl;
            cout << "Machine Lost: $" << spent << endl;
            cout << "Total Profit: $" << profit << endl;
            break;
            
        case 8: /* - - - - - - Selection 8 - - - - - - */
            cout << "Help (Information About Selections)\n" << endl;
            cout << "(1) : Pay for an item in the slot you choose." << endl;
            cout << "(2) : See what product (and its price) is in the chosen slot." << endl;
            cout << "(3) : Machine pays to add products to a slot." << endl;
            cout << "(4) : User pays to remove all products from a slot." << endl;
            cout << "(5) : User pays to remove all products from machine." << endl;
            cout << "(6) : Tell what products (and how many) are in each slot." << endl;
            cout << "(7) : Tell what money was spent and earned by the machine." << endl;
            cout << "(8) : You are here! Tell user specifics." << endl;
            cout << "(9) : End user decision processing.\n\n" << endl;
            break;
            
        case 9: /* - - - - - - Selection 9 - - - - - - */
            cout << "Exit program.\n" <<endl;
            return false;
            break;
            
        default: /* - - - - - - Default - - - - - - */
            cout << "Improper Input!\n" << endl;
            break;
    }
    return true;
}

/*
 * Main function for program running and testing.
 */
int main(int argc, char** argv) {
    cout << greetingString << endl;
    cout << "Your standard vending machine has been created." << endl;
    cout << "The dimensions are 5 rows by 3 columns." << endl;
    cout << "Each slot has enough room for 5 items." << endl;
    bool gettingDefault = true;
    while (gettingDefault == true)
    {
        cout << "Do you want a default machine? y/n ";
        string answer;
        cin >> answer;
        cout << answer << endl;
        if (answer.compare("y") == 0 || answer.compare("Y") == 0)
        {
            myMachine.createDefaultMachine();
            cout << "Default Machine Created!" << endl;
            gettingDefault = false;
            break;
        }
        else if (answer.compare("n") == 0 || answer.compare("N") == 0)
        {
            cout << "Empty Machine Created!" << endl;
            gettingDefault = false;
            break;
        }
        else
        {
            cout << "Improper input!" << endl;
        }
    }
    
    cout << divider << endl;
    cout << "   Not all parts of this program take sloppy user " << endl;
    cout << "     decisions into account. Select with care." << endl;
    bool processing = true;
    while (processing == true)
    {
        cout << divider << endl;
        int instruction = receiveInstruction();
        cout << divider << endl;
        processing = processInfo(instruction);
    }
    cout << "All done!" << endl;
    cout << "Program ended." << endl;
    
    return 0;
}
