#include "Inventory.h"
#include <iomanip>
#include <iostream>

Inventory::Inventory()
{
	
}
Inventory::~Inventory() {
	for (int x = 0; x < availableItems; x++) {
		delete myInvertory[x];
	}

	for (int y = 0; y < soldItems; y++)
	{
		delete mySoldInvertory[y];
	}
}
void Inventory::Order() {

	int SKU;
	cout << "----Order----\n\n";
	cout << "Enter SKU To place Order :: ";
	cin >> SKU;
	bool found = false;
	int quantity;
	double cost;
	double price;
	for (int x = 0; x < availableItems; x++) {
		if (myInvertory[x]->getSKU() == SKU) {
			cout << "Enter the quantity recived :: ";
			cin >> quantity;
			cout << "Enter the price :: ";
			cin >> cost;
			price = cost + (cost * myInvertory[x]->getMarkUp());
			myInvertory[x]->setCost (cost);
			myInvertory[x]->setPrice(price);
			int  previousUnits = myInvertory[x]->getUnitsAvailable();
			quantity = quantity + previousUnits;
			myInvertory[x]->setUnitsAvailable(quantity);
			cout << "*********** Inventory Updated Successfully *************" << endl;

			found = true;
			break;
		}

	}
	
	if (found == false) {
		cout << "******** Invalid SKU***********\n";
	}



}


void Inventory::display() { 
	cout << "\n\n****************************************\n\n";
	// cout << "\n\n*********  Report Is As Follows *********\n\n";
		// cout<< "\n\n****************************************\n\n";

		cout << "\n-----Report-----\n\n";
	for (int x = 0; x < availableItems; x++) {
		cout << x + 1 << ") ";
		
		myInvertory[x]->display();
		

	}
		cout<<"\n\n****************************************\n\n";
	

}
void Inventory::addItem() {
	int selection;
	const int maxSize = 20;
	if (availableItems < maxSize) {
		do {
			cout << "----New Item-----\n\n";
			cout << "Press \n1) To add a DVD, enter 1\n2) To add a CD, enter 2 \n3) To add a Book, enter 3\n0) To go back to Main Menu, enter 0  \n input >> ";
			cin >> selection;
			if (selection == 1) {
				string title;
				string director;
				string leadActor;
				double playingTime ;
				string genre;
				double cost;
				int availableUnits;

				
				cout << "Please enter the title of the DVD :: ";
				cin >> title;
				
				cout << " Please enter the director name :: ";
				cin >> director;
			
				cout << " Please enter the lead actor name :: ";
				cin >> leadActor;
		
				do {
				cout << " Please enter the playing time :: ";
				cin >> playingTime;
				if (playingTime < 0) {
					cout << " --------- Can't Enter Negative Number ! -------" << endl;
				}
			    }while (playingTime < 0);

				cout << "Please enter the genre of the DVD ::  ";
				cin >> genre;

				do{
				cout << " Please enter the cost of DVD :: ";
				cin >> cost;
				if (cost < 0) {
					cout << " --------- Can't Enter Negative Number ! -------" << endl;
				}
			    }while (cost < 0);

			    do {
					cout << " Please enter the units on hand :: ";
					cin >> availableUnits;
					if (availableUnits < 0) {
						cout << " --------- Can't Enter Negative Number ! -------" << endl;
					}
				}while (availableUnits < 0);

				

				myInvertory[availableItems] = new DVD(title, director, leadActor, playingTime, genre,cost,availableUnits);


				cout << "********* DVD Added Successfully ********* " << endl;
				availableItems++;

			}
			else if (selection == 2) {
				string title;
				string artistName;
				int numberOfTracks;
				double playingTime = 0;
				string genre;
				double cost;
				int availableUnits;

				cout << "Please enter the title of the CD :: ";
				cin >> title;
				

				cout << " Please enter the arist name :: ";
				cin >> artistName;
				

				do {
				cout << " Please enter the number of tracks  :: ";
				cin >> numberOfTracks;
				if (numberOfTracks < 0) {
					cout << " --------- Can't Enter Negative Number ! -------" << endl;
				}
				} while (numberOfTracks < 0);

				do {
				cout << " Please enter the playing time :: ";
				cin >> playingTime;
				if (playingTime < 0) {
					cout << " --------- Can't Enter Negative Number ! -------" << endl;
				}
				} while (playingTime < 0);

				cout << "Please enter the genre of the CD ::  ";
				cin >> genre;

				do {
				cout << " Please enter the cost of CD :: ";
				cin >> cost;
				if (cost < 0) {
					cout << " --------- Can't Enter Negative Number ! -------" << endl;
				}
				} while (cost < 0);

				do {
				cout << " Please enter the units on hand :: ";
				cin >> availableUnits;
				if (availableUnits < 0) {
					cout << " --------- Can't Enter Negative Number ! -------" << endl;
				}
				} while (availableUnits < 0);

				myInvertory[availableItems] = new CD(title, artistName, numberOfTracks, playingTime, genre, cost, availableUnits);
				cout << "********* CD Added Successfully ********* " << endl;
				
				availableItems++;


			}
			else if (selection == 3) {
				string title;
				string author;
				string description;
				double cost;
				int availableUnits;

				cout << "Please enter the title of the book :: ";
				cin >> title;

				cout << " Please enter the author :: ";
				cin >> author;

				cout << "Please enter the description :: ";
				cin.ignore();
				getline(cin, description);

				do{
				cout << " Please enter the cost of book :: ";
				cin >> cost;
				if (cost < 0) {
					cout << " --------- Can't Enter Negative Number ! -------" << endl;
				}
				} while (cost < 0);

				do {
					cout << " Please enter the units on hand :: ";
					cin >> availableUnits;
					if (availableUnits < 0) {
						cout << " --------- Can't Enter Negative Number ! -------" << endl;
					}
				} while (availableUnits < 0);

				myInvertory[availableItems] = new Book(title, author, description,cost,availableUnits);
				
				cout << "********* Book Added Successfully ********* " << endl;
				availableItems++;


			}
			else if (selection ==0 ) {
				cout << "__________________________________________________\n\n";
					
			}
			else
			{
				cout << " ******** Invalid selection !********\n";
			}
		} while (selection != 0);
	}
	else {
		cout << "********Inventory Is Full ******\n";
	}
	
}

void Inventory::sale() {

	int  opp;
	int SKU;
	int quantity;
	bool found = false;
	


	do {
		cout << "\n---- Sale-----\n\n";
		cout << "Press\n1)To sell an Item, enter 1\n0) To exit, enter 0 \n input >>  ";
		cin >> opp;
		if (opp == 1) {

			cout << " Enter SKU :: ";
			cin >> SKU;

			for (int x = 0; x < availableItems; x++) {
				if (myInvertory[x]->getSKU() == SKU) {
					cout << "Please enter quantity :: ";
					cin >> quantity;

					if (quantity > myInvertory[x]->getUnitsAvailable() && myInvertory[x]->getUnitsAvailable() >0) {

						int selection;
						cout << "\nNOTE! ****(We only have " << myInvertory[x]->getUnitsAvailable() << " Units available)" << endl;
						cout << " \nPress \n 1) To buy " << myInvertory[x]->getUnitsAvailable() << " units, enter 1  "
								<< "\n0) To exit, enter 0 \n input >> ";
							cin >> selection;
							if (selection == 1) {
								bool alreadySold = false;
								for (int x = 0; x < soldItems; x++) {
									if (SKU == mySoldInvertory[x]->getSoldID()) {
										alreadySold = true;
									 // the amountRequested means the quantity of the item that the customer want more of
										int amountRequested = mySoldInvertory[x]->getSoldQuantity()+ myInvertory[x]->getUnitsAvailable();
										mySoldInvertory[x]->setSoldQuantity(amountRequested);
										mySoldInvertory[x]->setMessage("(*** Low in Stock ***)");
										myInvertory[x]->setMessage("(***Low in Stock***)");
										//break;
									}
								}

								if (alreadySold == false) {
									mySoldInvertory[soldItems] = myInvertory[x];
									mySoldInvertory[soldItems]->setSoldID(myInvertory[x]->getSKU());
									mySoldInvertory[soldItems]->setSoldQuantity(myInvertory[x]->getUnitsAvailable());
									mySoldInvertory[soldItems]->setMessage(" (***Low in Stock ***)");
									myInvertory[soldItems]->setMessage(" (***Low in Stock***)");

									soldItems++;

								}
								

								myInvertory[x]->setUnitsAvailable(0);
							   
							}
							else if (selection == 0) {

								cout << " _______ We hope to see you soon or maybe next time? ________" << endl;
							}
							else {
								cout << "\n  _________Invalid Try Again ____ " << endl;

							}

					}
					else if(myInvertory[x]->getUnitsAvailable() <=0){
					   
						cout << "***** Sorry, but we are out of Stock  ******" << endl;
						cout << "********* We will order soon for you.**********" << endl;
						
						myInvertory[x]->setMessage(" (***Low in Stock ***)");
					}
					else if (myInvertory[x]->getUnitsAvailable() >= quantity) {

						myInvertory[x]->setUnitsAvailable(myInvertory[x]->getUnitsAvailable() - quantity);
				

						bool alreadySold = false;
						for (int x = 0; x < soldItems; x++) {
							if (SKU == mySoldInvertory[x]->getSoldID()) {
								alreadySold = true;
								
								int amountRequested = mySoldInvertory[x]->getSoldQuantity() + quantity;
								mySoldInvertory[x]->setSoldQuantity(amountRequested);
								break;
							}
						}

						if (alreadySold == false) {

							mySoldInvertory[soldItems] = myInvertory[x];
							mySoldInvertory[soldItems]->setSoldID(myInvertory[x]->getSKU());
							mySoldInvertory[soldItems]->setSoldQuantity(quantity);
							soldItems++;

						}

				
					}

					found = true;
				}
			}

			
			if (found == false) {
				cout << " **************** Invalid SKU, Please enter again**********\n ";
			}
			
		}
		else if(opp==0) {
			double totalCost = 0;
			const double TAX = 0.0925;
			double totalTax = 0;
			cout << "\n----Reciept-----\n\n";
			for (int x = 0; x < soldItems; x++) {
				
				cout << "SKU : " << mySoldInvertory[x]->getSKU() <<"   "<<mySoldInvertory[x]->getMessage()
					 << "    "<<mySoldInvertory[x]->getSoldQuantity()
					 << "   $" << setprecision(2) << fixed << mySoldInvertory[x]->getPrice()
					 << "   $" << setprecision(2) << fixed << mySoldInvertory[x]->getPrice()* mySoldInvertory[x]->getSoldQuantity()<< endl;
			
				totalCost = totalCost + (mySoldInvertory[x]->getPrice() * mySoldInvertory[x]->getSoldQuantity());
				totalTax = totalTax + (myInvertory[x]->getPrice() * mySoldInvertory[x]->getSoldQuantity() * TAX);
			
			}
			//cout << " \n\n****************** Total Cost**************************" << endl;
			cout << "\n  Total Cost :: " << "$" << setprecision(2) << fixed << totalCost
				<< "\n  TAX        :: " << "$" << setprecision(2) << fixed << totalTax
				<< "\n  Subtotal   :: " << "$" << setprecision(2) << fixed << (totalCost+totalTax) << endl;
			cout << " \n\n****************************************************" << endl;
			soldItems = 0;
		}
		else {

			cout << " ___________ Ivalid Input ______ " << endl;
		}
	} while (opp != 0);




}
