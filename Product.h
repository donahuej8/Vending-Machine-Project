/* 
 * File:   Product.h
 * Author: John Donahue
 *
 * Created on 1 February 2018, 11:41 AM
 * Version: 7 Feb 2018
 */

#ifndef PRODUCT_H
#define	PRODUCT_H
#include <iostream>
#include <string>
using namespace std;

/*
 * This class is used to represent a product that would be found in a vending machine
 */
class Product {
public:
        Product();
	Product(string pName, string pType, string pFacts);
	Product(const Product& orig);
	virtual ~Product();
        string getName();
        string getType(); // change to enum eventually
        string getNutritionFacts(); // maybe NutritionFacts class???
        string toString();

private:
        string name;
        string type; // change to enum eventually
        string nutritionFacts;
};

#endif	/* PRODUCT_H */

