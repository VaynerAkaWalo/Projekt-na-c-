#ifndef STAFF_CLASS
#define STAFF_CLASS

#include <string>
#include "person.h"
#include "screen.h"


class Staff : public Person
{
    protected:
        std::string role;

    public:
    Staff(int, std::string, std::string, std::string, std::string);

    Staff(Staff &);

    virtual ~Staff() {}

    unsigned int getid();

    void wyswietl(Screen*);
};

#endif