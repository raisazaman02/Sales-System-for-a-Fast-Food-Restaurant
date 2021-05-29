//item.cpp

#include <iostream>
#include <string>
#include "Item.h"

using namespace std;

//Implementation default constructor 
Item::Item()
{
	name = " ";
	price = 0.0;
	calories = 0;
	quantities = 0;
}

//Implementation of constructor with parameters
Item::Item(string In, double Ip, int Ic, int Iq)
{
	setName(In);
	setCalories(Ic);
	setQuantities(Iq);
	setPrice(Ip);
}

//Implementation of setName
void Item::setName(string n)
{
	name= n;
}

// Implementation of getName
string Item :: getName()const
{
	return name;
}

//Implementation of setPrice
void Item::setPrice(double p)
{
	price = p;
}

//Implementation of getPrice
double Item::getPrice() const
{
	return price;
}

//Implementation of setCalories
void Item:: setCalories(int c)
{
	calories = c;
}

//Implementation of getCalories
int Item::getCalories() const
{
	return calories;
}

//Implementation of setQuantities
void Item::setQuantities(int q)
{
	quantities = q;
}

//Implementation of getQuantities
int Item::getQuantities() const
{
	return quantities;
}

//Implementation of printItem
void Item::printItem() const
{
	cout << "Name: " << name << "; " << "Price: " << price << "; "
		<< "Calories: " << calories << "; " << "Quantities: " <<
		quantities << "; ";
}

bool Item::greater(Item *item1, Item *item2)
{
	return item1->calories > item2->calories;
}
