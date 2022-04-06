#include "Item.h"

class CD : public Item
{
private:
    string artistName;
    int numberOfTracks;
    double playingTime;
    string genre;
public:
    CD(string, string, int, double, string, double , int);
   
    ~CD();


    string getArtist();
    void setArtist(string );
    string getGenre();
    void setGenre(string);
    int getNumberOfTracks();
    void setNumberOfTracks(int);
    double getPlayingTime();
    void setPlayingTime(double);
    virtual void display();





};
