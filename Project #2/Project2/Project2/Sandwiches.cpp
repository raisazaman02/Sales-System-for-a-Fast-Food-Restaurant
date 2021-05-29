#include <iostream>
#include <string>
#include "Sandwiches.h"

//Implementation of default constructor
sandwiches::sandwiches()
{
	sandwicheType = " ";
}

//Implementation of constructor with parameters
sandwiches::sandwiches(string Sn, double Sp, int Sc, int Sq, string St)
	:Item(Sn, Sp, Sc, Sq)
{
	sandwicheType = St;
}

//Implementation of setSandwiches
void sandwiches::setSandwiches(string Sn, double Sp, int Sc, int Sq, string St)
{
	setName(Sn);
	setPrice(Sp);
	setCalories(Sc);
	setQuantities(Sq);
	setsandwicheType(St);
}

//Implementation of setsandwicheType
void sandwiches::setsandwicheType(string St)
{
	sandwicheType = St;
}

//Implementation of getsandwicheType
string sandwiches::getsandwicheType() const
{
	return sandwicheType;
}

//Implementation of printSandwiches
void sandwiches::printItem() const
{
	Item::printItem();
	cout << "Sandwich type: " << sandwicheType << endl;
	cout << endl;
}

//Implementation of operator overload
ostream& operator<< (ostream& cout, const sandwiches& sandwichesobject)
{
	sandwichesobject.printItem();
	return cout;
}