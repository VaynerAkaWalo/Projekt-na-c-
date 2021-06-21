#ifndef PERSON_CLASS
#define PERSON_CLASS

#include <string>
#include <vector>
#include "screen.h"

class Screen;

class Person
{
    protected:
        unsigned int id;
        std::string name;
        std::string lastname;
        std::string status;

    public:
    virtual unsigned int getid() = 0;

    virtual void wyswietl(Screen*) = 0;
};

#endif