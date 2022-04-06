#include "Book.h"
#include <iomanip>

Book::Book():Item() {
	this->description = "";
	this->author = "";


}

   
Book:: Book(string title, string author, string description, double cost, int unitsAvailable):Item( title, "BOOK",  cost, 0.25,  unitsAvailable) {

	this->author = author;
	this->description = description;

}

string Book:: getAuthor() {
	return this -> author;
}
string Book:: getDescription() {
	return this->description;
}

void Book:: setAuthor(string author) {
	this->author = author;
}
void Book:: setDescription(string description) {
	this->description= description;
}

 void Book::display() {
	
	 cout << " SKU :: " << this->getSKU() << " (Book) " << this->getMessage()
		 << "\nTitle   ::  " << this->getTitle()
		 << "\nType    ::  " << this->getItemType()
		 << "\nUnits On Hand :: " << this->getUnitsAvailable()
		 << "\nAuthor ::  " <<  this->getAuthor()
		 << "\nDescription :: " << this->getDescription();

    cout << "\nCost    ::  " << "$" << setprecision(2) << fixed << this->getCost()
		 << "\nMark Up ::  " << this->getMarkUp()
		 << "\nPrice   ::  " << "$" << setprecision(2) << fixed << this->getPrice()
         << "\nTotal $ Value :: " << "$" << setprecision(2) << fixed << this->getPrice() * this->getUnitsAvailable() << endl;
	           

			cout << "\n________________________________________________\n\n";
		
}
