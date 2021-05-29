#pragma once
#include "Item.h"
//drinks class inherits
class drinks : public Item
{
private:
	friend ostream& operator<< (ostream&, const  drinks&);
	//Declare type
	string drinktype;
public:
	drinks();
	drinks(string Dn, double Dp, int Dc, int Dq, string Dt);
	void setDrinks(string Dn, double Dp, int Dc, int Dq, string Dt);
	void setDrinktype(string);
	string getDrinktype()const;
	void printItem() const;
};
