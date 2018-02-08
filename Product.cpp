/* 
 * File:   Product.cpp
 * Author: John Donahue
 * 
 * Created on 1 February 2018, 11:41 AM
 * Version: 7 Feb 2018
 */

#include <iostream>
#include <string>
#include "Product.h"

/*
 * Constructor for the Product class.
 *   Sets default values
 */
Product::Product(string pName, string pType, string pFacts) {
    name = pName;
    type = pType;
    nutritionFacts = pFacts;
}

Product::Product(const Product& orig) {
}

Product::~Product() {
}

/* - - - - - - - - Accessor Functions - - - - - - - - */

string Product::getName()
{
    return name;
}

string Product::getType()
{
    return type;
}

string Product::getNutritionFacts()
{
    return nutritionFacts;
}

/* - - - - - - - - Special Functions - - - - - - - - */

string Product::toString()
{
    string result = name;
    result += ": ";
    result += type;
    result += " , ";
    result += nutritionFacts;
    return result;
}