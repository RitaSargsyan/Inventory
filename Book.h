#include "Item.h"

class Book : public Item
{
private:
    string author;
    string description;
public:

    Book();
    Book(string , string , string , double , int );
 
   
    string getAuthor();
    string getDescription();
    void setAuthor(string);
    void setDescription(string);
    virtual void display();
    
};

