#include <string>
#include <iostream>
#include "staff.h"


Staff::Staff(int id, std::string name, std::string lastname, std::string status, std::string role)
{
    this->id  = id;
    this->name = name;
    this->lastname = lastname;
    this->status = status;
    this->role = role;
}

Staff::Staff(Staff &other)
{
    this->id  = other.id;
    this->name = other.name;
    this->lastname = other.lastname;
    this->status = other.status;
    this->role = other.role;
}

void Staff::wyswietl(Screen* screen)
{
    std::cout.width(screen->gettableIDsize());
    std::cout << this->id;
    std::cout << "|";
    std::cout.width(screen->gettableNAMEsize());
    std::cout << this->name;
    std::cout << "|";
    std::cout.width(screen->gettableLASTNAMEsize());
    std::cout << this->lastname;
    std::cout << "|";
    std::cout.width(screen->gettableSTATUSsize());
    std::cout << this->status;
    std::cout << "|";
    std::cout.width(screen->gettableUNIQUEsize());
    std::cout << this->role;
    std::cout << "|";
}

unsigned int Staff::getid()
{
    return this->id;
}