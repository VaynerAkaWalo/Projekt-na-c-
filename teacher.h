#ifndef TEACHER_CLASS
#define TEACHER_CLASS

#include <string>
#include "person.h"
#include "screen.h"


class Teacher : public Person
{
    protected:
        std::string subject;

    public:
    Teacher(int, std::string, std::string, std::string, std::string);

    unsigned int getid();

    void wyswietl(Screen*);

};

#endif