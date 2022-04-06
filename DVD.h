#include "Item.h"


class DVD : public Item
{
private:
   
    string director;
    string leadActor;
    double playingTime;
    string genre;
public:

    DVD(string, string, string, double, string, double , int ) ;

    ~DVD(); //destructor
    string getDirector();
    void setDirector(string);
    string getLeadActor();
    void setLeadActor(string);
    double getPlayingTime();
    void setPlayingTime(double);
    string getGenre();
    void setGenre(string);

    virtual void display();





};


