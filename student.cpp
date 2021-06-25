#include <string>
#include <iostream>
#include "student.h"
#include "screen.h"

Student::Student(int id, std::string name, std::string lastname, std::string status, std::string group)
{
    this->id  = id;
    this->name = name;
    this->lastname = lastname;
    this->status = status;
    this->group = group;
}

Student::Student(Student &other)
{
    this->id  = other.id;
    this->name = other.name;
    this->lastname = other.lastname;
    this->status = other.status;
    this->group = other.group;
}

void Student::wyswietl(Screen* screen)
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
    std::cout << this->group;
    std::cout << "|";
}

unsigned int Student::getid()
{
    return this->id;
}