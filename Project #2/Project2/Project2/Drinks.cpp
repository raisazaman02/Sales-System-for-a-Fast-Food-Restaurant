
#include <iostream>
#include <string>
#include "Item.h"
#include "Drinks.h"

//Implementation of default constructor
drinks::drinks()
{
	drinktype = " ";
}

//Implementation of constructor with parameters
drinks::drinks(string Dn, double Dp, int Dc, int Dq, string Dt)
	:Item(Dn, Dp, Dc, Dq)
{
	drinktype = Dt;
}

//Implementation of setDrinks method
void drinks::setDrinks(string Dn, double Dp, int Dc, int Dq, string Dt)
{
	setName(Dn);
	setPrice(Dp);
	setCalories(Dc);
	setQuantities(Dq);
	setDrinktype(Dt);
}


//Implementation of operator overload method
ostream& operator<< (ostream& cout, const drinks& drinksobject)
{
	drinksobject.printItem();
	return cout;
}

//Implementation of setType 
void drinks::setDrinktype(string Dt)
{
	drinktype = Dt;
}

//Implementation of getDrinktype
string drinks::getDrinktype() const
{
	return drinktype;
}

//Implementation of printDrinks
void drinks::printItem() const
{
	Item::printItem();
	cout << "Drink type: " << drinktype << endl;
	cout << endl;
}