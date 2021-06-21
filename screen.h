#ifndef SCREEN_CLASS
#define SCREEN_CLASS

#include <string>
#include "person.h"
#include "login.h"

class Person;

class Screen;

namespace login
{
    void login(Screen*);
}

class Screen
{
    private:
    int outputposition = 5;
    int inputposition = 17;
    int menuend = 15;

    int tableIDsize = 4;
    int tableNAMEsize = 18;
    int tableLASTNAMEsize = 20;
    int tableSTATUSsize = 10;
    int tableUNIQUEsize = 13;

    std::string user = "NaN";

    std::vector<Person*>* students;
    std::vector<Person*>* teachers;
    std::vector<Person*>* staff;

    public:

    Screen();
    Screen(std::vector<Person*>*, std::vector<Person*>*, std::vector<Person*>*);

    std::string getuser();
    
    int gettableIDsize();
    int gettableNAMEsize();
    int gettableLASTNAMEsize();
    int gettableSTATUSsize();
    int gettableUNIQUEsize();

    std::vector<Person*>* getstudentspointer();
    std::vector<Person*>* getteacherspointer();
    std::vector<Person*>* getstaffpointer();

    void standardscreen();
    void menuscreen();
    void table(int);

    void friend login::login(Screen*);

    void menuline();
    void inputline();
    void outputline();
};

#endif