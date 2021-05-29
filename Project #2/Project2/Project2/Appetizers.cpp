
#include <iostream>
#include <string>
#include "Appetizers.h"

//Implementation of default constructor
appetizers::appetizers()
{
	appetizerType = " ";
}

//Implementation of constructor with parameters
appetizers::appetizers(string An, double Ap, int Ac, int Aq, string At)
	:Item(An, Ap, Ac, Aq)
{
	appetizerType = At;
}

//Implementation of setappetizers
void appetizers::setappetizers(string An, double Ap, int Ac, int Aq, string At)
{
	setName(An);
	setPrice(Ap);
	setCalories(Ac);
	setQuantities(Aq);
	setappetizerType(At);
}

//Implementation of setappetizerType
void appetizers::setappetizerType(string At)
{
	appetizerType = At;
}

//Implementation of getappetizerType
string appetizers::getappetizerType() const
{
	return appetizerType;
}

//Implementation of printAppetizers
void appetizers::printItem() const
{
	Item::printItem();
	cout << "Appetizer Type: " << appetizerType << endl;
	cout << endl;
}

//Implementation of operator overload
ostream& operator<< (ostream& cout, const appetizers& appetizersobject)
{
	appetizersobject.printItem();
	return cout;

}
