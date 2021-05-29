#pragma once
//Item.h
#include <iostream>
#include <string>
using namespace std;

//Declaration of Item class
class Item
{
public:
	Item();
	Item(string In, double Ip, int Ic, int Iq);
	void setName(string);
	string getName()const;
	void setPrice(double);
	double getPrice() const;
	void setCalories(int);
	int getCalories() const; 
	void setQuantities(int);
	int getQuantities()const;
	virtual void printItem() const;
	static bool greater(Item *item1, Item *item2);
private:
	string name;
	double price;
	int calories;
	int quantities;
};
