#ifndef STUDENT_CLASS
#define STUDENT_CLASS

#include <string>
#include "person.h"
#include "screen.h"



class Student : public Person
{
    protected:
        std::string group;

    public:
    Student(int, std::string, std::string, std::string, std::string);

    unsigned int getid();
    
    void wyswietl(Screen*);

};

#endif