#include "CD.h"
#include <iomanip>
    CD::CD(string title ,string artistName, int numberOfTracks, double playingTime, string genre, double cost, int unitsAvailable) : Item(title, "CD", cost, 0.30, unitsAvailable) {
        
       this-> artistName = artistName;
       this->numberOfTracks = numberOfTracks;
       this->playingTime = playingTime;
       this->genre =  genre;

    }
    CD::~CD() {
        
    }
    


    string CD::getArtist() {
        return this->artistName;
    }
    void  CD:: setArtist(string artistName) {
        this->artistName= artistName;

    }
    string  CD:: getGenre() {
        return this->genre;
    }
    void  CD:: setGenre(string genre) {
        this->genre = genre;
    }
    int  CD:: getNumberOfTracks() {
        return this->numberOfTracks;

    }
    void  CD:: setNumberOfTracks(int numberOfTracks) {
        this->numberOfTracks = numberOfTracks;
    }
    double  CD:: getPlayingTime() {
        return this->playingTime;
    }
    void  CD:: setPlayingTime(double playingTime) {

        this->playingTime = playingTime;
    }

     void CD::display() {
      

         cout << " SKU :: " << this->getSKU() << " (CD) " << this->getMessage()
             << "\nTitle   ::  " << this->getTitle()
             << "\nType    ::  " << this->getItemType()
             << "\nUnits On Hand :: " << this->getUnitsAvailable()
             << "\nArtist Name ::  " << this->getArtist()
             << "\nNumber of Tracks :: " << this->getNumberOfTracks()
             << "\nPlaying Time ::  " << this->getPlayingTime()
             << "\nGenre     ::  " << this->getGenre();

        cout  << "\nCost    ::  " << "$" << setprecision(2) << fixed << this->getCost()
             << "\nMark Up ::  " << this->getMarkUp()
             << "\nPrice   ::  " << "$" << setprecision(2) << fixed << this->getPrice()
             << "\nTotal $ Value:: " << "$" << setprecision(2) << fixed << this->getPrice() * this->getUnitsAvailable() << endl;

         cout << "______________________________________" << endl;
    }

