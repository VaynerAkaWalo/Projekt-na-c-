#include <string>
#include <iostream>
#include "teacher.h"


Teacher::Teacher(int id, std::string name, std::string lastname, std::string status, std::string subject)
{
    this->id  = id;
    this->name = name;
    this->lastname = lastname;
    this->status = status;
    this->subject = subject;
}

Teacher::Teacher(Teacher &other)
{
    this->id  = other.id;
    this->name = other.name;
    this->lastname = other.lastname;
    this->status = other.status;
    this->subject = other.subject;
}

void Teacher::wyswietl(Screen* screen)
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
    std::cout << this->subject;
    std::cout << "|";
}

unsigned int Teacher::getid()
{
    return this->id;
}