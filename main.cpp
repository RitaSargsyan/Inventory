#include "Inventory.h"


void  mainMenu() {
	cout << "Jane's Inventory\n" << endl;
	cout << "----Main Menu----\n\n";
	cout << "Press\n1) To enter a New Item, enter 1 \n2) To enter an order, enter 2\n3) For Sale, enter 3 \n4)For a complete report, enter 4\n0) To quit, enter 0\n input>>";

}

int main(){
	int choice;
	Inventory myInventory;
	do {
		mainMenu();
		cin >> choice;
		if (choice == 1) {
			myInventory.addItem();
		}
		else if (choice == 2) {
			myInventory.Order();
		}
		else if (choice == 3) {
			myInventory.sale();
		}
		else if (choice == 4) {
			myInventory.display();

		}
		
		else if (choice == 0) {
			cout << "***********************" << endl;
		}
		else {
			cout << "----------Invalid Selection---------\n-----------try Again--------\n";
		}


	} while (choice != 0);
	return 0;
}
