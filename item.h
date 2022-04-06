#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Item 
{
//protected:
	string title;
private:
	string itemType;
	int SKU;
	static int count;
	double cost;
	double price;
	int unitsAvailable;
	double markUp;
	int SoldID;
	int soldQuantity;
	string message;

public:
	Item();
	Item(string , string, double , double , int );
	int getSKU();
	void setTitle(string );
	string getTitle();
	string getItemType();
	void setCost(double );
	double getCost();

	void setPrice(double);
	double getPrice();
	void setItemType(string );
	void setUnitsAvailable(int);
	int getUnitsAvailable(); 
	void setMarkUp(double);
	double getMarkUp();
	int getSoldID();
	void setSoldID(int);
	int getSoldQuantity();
	void setSoldQuantity(int);
	void setMessage(string);
	string getMessage();
	virtual void display();

};

#endif
