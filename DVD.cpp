#include "DVD.h"
#include <iomanip>

  

  DVD:: DVD(string title ,string director, string leadActor, double playingTime, string genre, double cost, int unitsAvailable) :Item(title, "DVD", cost, 0.40, unitsAvailable){
  
        this->director = director;
        this->leadActor = leadActor;
        this->playingTime = playingTime;
        this->genre = genre;

    }

  DVD::  ~DVD() {
  
  } //destructor

    string DVD:: getDirector() {
    
        return this->director;
    
    }
    void DVD:: setDirector(string director) {
    
        this->director = director;

    }

    string DVD:: getLeadActor() {
        return this->leadActor;
    }
    void DVD:: setLeadActor(string leadActor) {
    
        this->leadActor = leadActor;
    }
    double DVD:: getPlayingTime() {
        return this->playingTime;
    }
    void DVD:: setPlayingTime(double playingTime) {
        this->playingTime = playingTime;
    }
    string DVD:: getGenre() {
        return this->genre;
    }
    void DVD:: setGenre(string genre){
        this->genre = genre;
    
    
    }


     void DVD::display() {
        
         cout << " SKU :: " << this->getSKU() << " (DVD) " << this->getMessage()
             << "\nTitle   ::  " << this->getTitle()
             << "\nType    ::  " << this->getItemType()
             << "\nUnits On Hand ::  " << this->getUnitsAvailable()
             << "\nDirector    ::    " << this->getDirector()
             << "\nLead Actor   ::    " << this->getLeadActor()
             << "\nPlaying Time ::  " << this->getPlayingTime()
             << "\nGenre     ::  " << this->getGenre();

        cout << "\nCost    ::  " << "$" << setprecision(2) << fixed << this->getCost() 
             << "\nMark Up ::  " << this->getMarkUp()
            << "\nPrice   ::  " << "$" << setprecision(2) << fixed << this->getPrice()
             << "\nTotal $ Value:: " <<"$" <<setprecision(2) << fixed << this->getPrice() * this->getUnitsAvailable() << endl;
         cout << "\n________________________________________________\n\n";
    }
