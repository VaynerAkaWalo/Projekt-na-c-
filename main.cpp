#include <iostream>
#include <string>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <ctime>
#include <cstdio>
#include "person.h"
#include "student.h"
#include "teacher.h"
#include "staff.h"
#include "terminal.h"
#include "config.h"
#include "login.h"
#include "screen.h"
#include "input.h"

using namespace std;
using namespace terminal;



void linedown(void)
{
    gotoline(ENDLINE);
}


int main()
{
    vector<Person*> uczniowie;
    uczniowie.push_back(new Student(1, "Norbert", "Gierczak", "aktywny", "3A"));
    uczniowie.push_back(new Student(2, "Piotr", "Wegrzyn", "aktywny", "2A"));
    uczniowie.push_back(new Student(3, "Lukasz", "Stefan", "aktywny", "2B"));

    vector<Person*> nauczyciele;
    nauczyciele.push_back(new Teacher(10, "Witold", "Tacikiewicz", "aktywny", "Matematyka"));
    nauczyciele.push_back(new Teacher(11, "Remigiusz", "Puch", "aktywny", "Wf"));
    nauczyciele.push_back(new Teacher(12, "Krzysztof", "Sauc", "aktywny", "Przyroda"));

    vector<Person*> obsluga;
    obsluga.push_back(new Staff(20, "Marcin", "Majkut", "aktywny", "Dyrektor"));
    obsluga.push_back(new Staff(21, "Pawel", "Szabla", "aktywny", "Wozny"));
    obsluga.push_back(new Staff(22, "Oskar", "Bogdan", "aktywny", "Kucharz"));
    
    atexit(linedown);
    Screen *screen = new Screen(&uczniowie, &nauczyciele, &obsluga);
    screen->menuscreen();
    

    return 0;
}