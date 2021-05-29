#pragma once
#include "Item.h"
//appetizers class inherits
class appetizers : public Item
{
private:
	friend ostream& operator<< (ostream&, const appetizers&);
	//Declare type
	string appetizerType;
public:
	appetizers();
	appetizers(string An, double Ap, int Ac, int Aq, string At);
	void setappetizers(string An, double Ap, int Ac, int Aq, string At);
	void setappetizerType(string);
	string getappetizerType()const;
	void printItem() const;
};