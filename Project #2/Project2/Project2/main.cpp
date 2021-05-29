//main.cpp
#include <iomanip> // set decimal points 
#include <iostream>
#include <string> 
#include <vector>// vector header file
#include <algorithm>// built in sorting function
#include "Item.h"// the base class item
#include "Drinks.h"// the derived class drinks
#include "Sandwiches.h" // the derived class sandwiches
#include "Appetizers.h" // the derived class appetizers
#include <conio.h> // For function getch()
#include "main.h"
using namespace std;

// Load the inverntory 
void loadInventory(vector<Item*> &vec)
{
	vec.push_back(new drinks("lemonade", 1.59, 20, 0, "cold"));
	vec.push_back(new drinks("iced tea", 1.59, 0, 0, " cold"));
	vec.push_back(new drinks("green tea", 1.59, 130, 0, "cold"));
	vec.push_back(new drinks("hot tea", 1.59, 0, 0, "hot"));
	vec.push_back(new drinks("hot coffie", 1.59, 1, 0, "hot"));
	vec.push_back(new sandwiches("grilled turkey", 9.99, 510, 0, "wheat bread"));
	vec.push_back(new sandwiches("grilled chicken", 9.99, 910, 0, "white bread"));
	vec.push_back(new sandwiches("roasted chicken", 10.79, 680, 0, "white beard"));
	vec.push_back(new sandwiches("roasted turkey", 10.79, 380, 0, "wheat beard"));
	vec.push_back(new sandwiches("cuban sandwich", 9.99, 880, 0, "white bread"));
	vec.push_back(new appetizers("garlic sticks", 4.00, 306, 0, "with cheese"));
	vec.push_back(new appetizers("garlic bread", 4.00, 206, 0, "no cheese"));
	vec.push_back(new appetizers("french fries", 2.00, 365, 0, "with cheese"));
	vec.push_back(new appetizers("fish sticks", 2.00, 365, 0, "no chilly"));
	vec.push_back(new appetizers("stuffed mushrooms", 7.50, 107, 0, "with bacon"));

}

// show the main menu
void showMenu()
{
	cout << "1. Search items" << endl;
	cout << "2. Add item to cart" << endl;
	cout << "3. Remove item from cart" << endl;
	cout << "4. View meals and offers" << endl;
	cout << "5. View cart" << endl;
	cout << "6. Sort meals by calories" << endl;
	cout << "7. Quit" << endl;
}

// search for an individual item
void searchItems(vector<Item*> &vec)
{
	string trash;
	vector <Item*> ::iterator it;
	string enter;
	getline(cin, trash);
	cout << "Enter the item: ";
	getline(cin, enter);
	for (it = vec.begin(); it != vec.end(); it++)
	{
		if ((*it)->getName() == enter)
		{
			(*it)->printItem();
			return;
		}
	}
	
	cout << "Item not found." << endl;
	cout << endl;
}

// add an item to the cart 
void addItem(vector<Item*> &vec)
{
	string trash;
	vector <Item*> ::iterator it;
	for (it = vec.begin(); it != vec.end(); it++)
	{
		(*it)->printItem();
	}
	cout << endl;
	string enter;
	int amount = 0;
	getline(cin, trash);
	cout << "Enter the item: ";
	getline(cin, enter);
	for (it = vec.begin(); it != vec.end(); it++)
	{
		if ((*it)->getName() == enter)
		{
			cout << "How many do you want: ";
			cin >> amount;
			cout << amount << " " << enter << " " << "has been added to your cart." << endl;
			cout << endl;
			(*it)->setQuantities(amount);
			if (!cin)
			{
				throw string("Error: wrong input.");
			}
			return;
		}
	}
	cout << "Item not found." << endl;
	cout << endl;
}

// delete an item from the cart
void deleteItem(vector<Item*> &vec)
{
	string trash;
	string enter;
	int num = 0;
	vector <Item*> ::iterator it;
	getline(cin, trash);
	cout << "Enter an item to remove: ";
	getline(cin, enter);
	for (it = vec.begin(); it != vec.end(); it++)
	{
		if ((*it)->getName() == enter)
		{
			cout << "How many would you like to remove: ";
			cin >> num;
			if (!cin)
			{
				throw string("Error: please enter a number.");
			}

			cout << num << " " << enter << " " << "has been deleted to your cart." << endl;
			cout << endl;
			
			if ((*it)->getQuantities() > num)
			{
				((*it)->setQuantities((*it)->getQuantities() - num));
				return;
			}
			
			else
			{
				cout << "error. cannot remove more the currently amount in cart.";
			}
		}
	}
	cout << "item was not found." << endl;
	cout << endl;
}

// load in combos 
void showCombo()
{
	cout << "1. lemonade, grilled chicken, and french fries" << endl;
	cout << "2. green tea and garlic sticks" << endl;
	cout << "3. lemonade, roasted chicken, and french fries" << endl;
	cout << "4. green tea, grilled chicken, and garlic sticks" << endl;
	cout << "5. stuffed mushrooms and hot tea" << endl;
	cout << "6. cuban sandwich, and green tea" << endl;
	cout << "7. Quit" << endl;
}

// select a combo
void viewMeal(vector<Item*> &vec)
{
	string trash;
	vector<Item*> ::iterator it;
	char num = 0;
	int amount;
	showCombo();
	getline(cin, trash);
	cout << "Enter a selection from the menu listed above(1-7): ";
	cin >> num;
	switch (num)
	{
	case '1':
		cout << "How many do you want: ";
		cin >> amount;
		cout << endl;
		if (!cin)
		{
			throw string("Error: must be a number.");
		}
		for (it = vec.begin(); it != vec.end(); it++)
		{
			if ((*it)->getName() == "lemonade" || (*it)->getName() == "grilled chicken" || (*it)->getName() == "french fries")
			{
				if ((*it)->getQuantities() > 0)
				{
					(*it)->setQuantities(amount + (*it)->getQuantities());
				}
				else
				{
					(*it)->setQuantities(amount);
				}
			}
		}
		cout << amount << " " << "lemonade, grilled chicken and french fries has been added to your cart. " << endl << endl;
		break;
	case '2':
		cout << "How many do you want: ";
		cin >> amount;
		cout << endl;
		if (!cin)
		{
			throw string("Error: must be a number.");
		}
		for (it = vec.begin(); it != vec.end(); it++)
		{
			if ((*it)->getName() == "green tea" || (*it)->getName() == "garlic sticks")
			{
				if ((*it)->getQuantities() > 0)
				{
					(*it)->setQuantities(amount + (*it)->getQuantities());
				}
				else
				{
					(*it)->setQuantities(amount);
				}
			}
		}
		cout << amount << " " << "green tea and garlic sticks has been added to your cart. " << endl << endl;
		break;
	case '3':
		cout << "How many do you want: ";
		cin >> amount;
		cout << endl;
		if (!cin)
		{
			throw string("Error: must be a number.");
		}
		for (it = vec.begin(); it != vec.end(); it++)
		{
			if ((*it)->getName() == "lemonade" || (*it)->getName() == "roasted chicken" || (*it)->getName() == "french fries")
			{
				if ((*it)->getQuantities() > 0)
				{
					(*it)->setQuantities(amount + (*it)->getQuantities());
				}
				else
				{
					(*it)->setQuantities(amount);
				}
			}
		}
		cout << amount << " " << "lemonade, roasted chicken, and french fries has been added to your cart. " << endl << endl;
		break;
	case '4':
		cout << "How many do you want: ";
		cin >> amount;
		cout << endl;
		if (!cin)
		{
			throw string("Error: must be a number.");
		}
		for (it = vec.begin(); it != vec.end(); it++)
		{
			if ((*it)->getName() == "green tea" || (*it)->getName() == "grilled chicken" || (*it) ->getName() == "garlic sticks")
			{
				if ((*it)->getQuantities() > 0)
				{
					(*it)->setQuantities(amount + (*it)->getQuantities());
				}
				else
				{
					(*it)->setQuantities(amount);
				}
			}
		}
		cout << amount << " " << "green tea, grilled chicken, and garlic sticks has been added to your cart. " << endl << endl;
		break;
	case '5':
		cout << "How many do you want: ";
		cin >> amount;
		cout << endl;
		if (!cin)
		{
			throw string("Error: must be a number.");
		}
		for (it = vec.begin(); it != vec.end(); it++)
		{
			if ((*it)->getName() == "stuffed mushrooms" || (*it)->getName() == "hot tea")
			{
				if ((*it)->getQuantities() > 0)
				{
					(*it)->setQuantities(amount + (*it)->getQuantities());
				}
				
				else
				{
					(*it)->setQuantities(amount);
				}
			}
		}
		cout << amount << " " << "stuffed mushrooms and hot tea has been added to your cart. " << endl << endl;
		break;
	case '6':
		cout << "How many do you want: ";
		cin >> amount;
		cout << endl;
		if (!cin)
		{
			throw string("Error: must be a number.");
		}
		for (it = vec.begin(); it != vec.end(); it++)
		{
			if ((*it)->getName() == "cuban sandwich" || (*it)->getName() == "green tea")
			{
				if ((*it)->getQuantities() > 0)
				{
					(*it)->setQuantities(amount + (*it)->getQuantities());
				}
				else
				{
					(*it)->setQuantities(amount);
				}
			}
		}
		cout << amount << " " << "cuban sandwich, and green tea has been added to your cart. " << endl << endl;
		break;
	case '7':
		return ;
	default:
		cout << "Invalid Input. Try again.\n";
	}

}

// view your cart
void viewCart(vector<Item*> &vec)
{
	double total = 0.0;
	double totalTemp = 0.0;
	int totalCalories = 0;
	vector<Item*> ::iterator it;

	for (it = vec.begin(); it != vec.end(); it++)
	{
		if ((*it)->getQuantities() > 0)
		{
			(*it)->printItem();
			total += (*it)->getPrice() * (*it)->getQuantities();
			totalCalories += (*it)->getCalories();
		}
	}
	cout << "Totla calories: " << totalCalories << endl;
	cout << endl;
	totalTemp = total * (.06);
	total = total + totalTemp;
	cout << "Total price with tax: $ " << total << endl;
	cout << endl;
}

// print the meal in order (calories) 
void sortCalories(vector<Item*> &vec)
{
	vector<Item*> ::iterator it;
	sort(vec.begin(), vec.end(), Item::greater);
	for (it = vec.begin(); it != vec.end(); it++)
	{
		(*it)->printItem();
	}
	cout << endl;
}

// Delete memory
void destroy(vector<Item*> &vec)
{
	/*
	for (auto it = vec.begin(); it != vec.end(); it++)
	{
		delete (*it);
	}
	*/
	
	while (!vec.empty()) 
	{
		delete vec.back();
		vec.pop_back();
	}
	
}

// select from the main menu
void selectMenu(vector<Item*> &menuList)
{
	char select;
	showMenu();
	while (true)
	{
		cout << "Enter a selection from the menu listed above(1-7): ";
		cin >> select;

		switch (select)
		{
		case '1':
			searchItems(menuList);
			break;
		case '2':
			addItem(menuList);
			break;
		case '3':
			deleteItem(menuList);
			break;
		case '4':
			viewMeal(menuList);
			break;
		case '5':
			viewCart(menuList);
			break;
		case '6':
			sortCalories(menuList);
			break;
		case '7':
			destroy(menuList);
			cout << "press enter" << endl;
			return;
		default:
			cout << "Invalid Input. Try again.\n";
		}

	}
}

// main
int main()
{
	// Decimal point
	cout << setprecision(2) << fixed;
	// catch the error 
	try
	{
		// Call the functions 
		vector<Item*> menuList;
		loadInventory(menuList);
		selectMenu(menuList);
	}
	catch (string s)
	{
		string t;
		cout << s << "Try again. \n";
		cout << endl;
		cin.clear();
		getline(cin, t);
		vector<Item*> menuList;
		loadInventory(menuList);
		selectMenu(menuList);
	}

	_getch();
	
}
