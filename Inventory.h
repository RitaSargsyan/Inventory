ifndef INVENTORY_H
#define INVENTORY_H
#include <string>
# include"Item.h"
#include "DVD.h"
#include"CD.h"
#include"Book.h"
using namespace std;

class Inventory
{

private:
	Item* myInvertory[20];
	Item* mySoldInvertory[20];

//protected:
	int availableItems=0;
	int soldItems = 0;

public:
	Inventory(); //default	
	void addItem ();
	void Order();
	void display();
	void sale();
	~Inventory();//destructor


};
#endif
