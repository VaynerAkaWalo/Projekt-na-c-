#ifndef TABLE_FUNCTIONS
#define TABLE_FUNCTIONS

#include <vector>
#include "screen.h"
#include "person.h"

void addperson(Screen*);

std::vector<Person*>::iterator findperson(unsigned int, std::vector<Person*>*);

void deleteperson(Screen*);


#endif