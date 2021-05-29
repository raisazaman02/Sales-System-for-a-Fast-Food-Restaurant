#pragma once
#include "Item.h"
//sandwiches class inherits
class sandwiches : public Item
{
private:
	friend ostream& operator<< (ostream&, const sandwiches&);
	//Declare type
	string sandwicheType;
public:
	sandwiches();
	sandwiches(string Sn, double Sp, int Sc, int Sq, string St);
	void setSandwiches(string Sn, double Sp, int Sc, int Sq, string St);
	void setsandwicheType(string);
	string getsandwicheType()const;
	void printItem() const;
};