#include <iostream>
#include <string>
#include "tablefunctions.h"
#include "terminal.h"
#include "input.h"
#include "person.h"
#include "student.h"
#include "teacher.h"
#include "staff.h"

void addperson(Screen* screen)
{
    screen->outputline();
    std::cout << "Kogo chcesz dodac?  -- Podaj liczbe zeby wybrac";

    screen->menuline();
    terminal::newline();
    std::cout << "1. Ucznia" << std::endl;
    std::cout << "2. Nauczyciela" << std::endl;
    std::cout << "3. Pracownika" << std::endl;

    screen->inputline();
    std::cout << "Podaj liczbe: ";
    int choice;

    while(choice != 1 && choice != 2 && choice != 3)
    {
        try
        {
            input(choice);
        }
        catch (std::runtime_error & e)
        {
            screen->outputline();
            std::cout << "Wprowadzono nieprawidlowy znak! Podaj liczbe";
            screen->inputline();
            std::cout << "Podaj liczbe: ";
            choice = -1;
        }

        if(choice != 1 && choice != 2 && choice != 3)
        {
            screen->outputline();
            std::cout << "Nie ma takiej opcji podaj liczbe jeszcze raz!";
            screen->inputline();
            std::cout << "Podaj liczbe: ";
        }
    }
    unsigned int id = 100;
    std::string name;
    std::string lastname;
    std::string status;
    std::string unique;
    screen->menuline();

    screen->outputline();
    std::cout << "Podaj imie osoby ktora chcesz dodac";
    screen->inputline();
    std::cout << "Podaj imie: ";
    input(name);

    screen->outputline();
    std::cout << "Podaj nazwisko osoby ktora chcesz dodac";
    screen->inputline();
    std::cout << "Podaj nazwisko: ";
    input(lastname);

    screen->outputline();
    std::cout << "Wybierz status dodawanej osoby -- Podaj liczbe zeby wybrac";
    screen->menuline();
    terminal::newline();
    std::cout << "1. Aktywny" << std::endl;
    std::cout << "2. Nieaktywny";
    screen->inputline();
    std::cout << "Podaj liczbe: ";
    int choice1;
    while(choice1 != 1 && choice1 != 2)
    {
        try
        {
            input(choice1);
        }
        catch (std::runtime_error & e)
        {
            screen->outputline();
            std::cout << "Wprowadzono nieprawidlowy znak! Podaj liczbe";
            choice1 = -1;
        }
        if(choice1 != 1 && choice1 != 2)
        {
            screen->inputline();
            std::cout << "Podaj liczbe: ";
        }
    }
            
    switch(choice1)
    {
        case 1:
        status = "aktywny";
        break;

        default:
        status = "nieaktywny";
        break;
        
    }

    screen->menuline();
    screen->outputline();
    switch(choice)
    {
        case 1:
        std::cout << "Podaj klase do ktorej chodzi uczen";
        break;

        case 2:
        std::cout << "Podaj przedmiot ktorego uczy";
        break;

        default:
        std::cout << "Podaj zawod jaki wynokuje";
        break;
    }
    
    screen->inputline();
    std::cout << "Wpisz: ";
    input(unique);

    screen->menuline();
    terminal::newline();
    std::cout << "Podano: " << std::endl;
    std::cout << "Imie: " << name << std::endl;
    std::cout << "Nazwisko: " << lastname << std::endl;
    std::cout << "Status: " << status << std::endl;

    switch(choice)
    {
        case 1:
        std::cout << "Klasa: " << unique << std::endl;
        break;

        case 2:
        std::cout << "Uczy: " << unique << std::endl;
        break;

        default:
        std::cout << "Zawod: " << unique << std::endl;
        break;
    }
    
    screen->outputline();
    std::cout << "Zeby dodac wpisz 1 || Zeby anulowac wpisz 2";
    int choice2;
    while(1)
    {
        screen->inputline();
        std::cout << "Podaj liczbe: ";
        try
        {
            input(choice2);
        }
        catch (std::runtime_error & e)
        {
            screen->outputline();
            std::cout << "Wprowadzono nieprawidlowy znak! Podaj liczbe";
            choice2 = -1;
        }
        if (choice2 == 1 || choice2 == 2)
        {
            switch(choice2)
            {
                case 1:
                {
                    std::vector<Person*>* persons;
                    Person* person;
                    switch(choice)
                    {
                        case 1:
                        person = new Student(id, name, lastname, status, unique);
                        persons = screen->getstudentspointer();
                        persons->push_back(person);
                        break;

                        case 2:
                        person = new Teacher(id, name, lastname, status, unique);
                        persons = screen->getteacherspointer();
                        persons->push_back(person);
                        break;

                        default:
                        person = new Staff(id, name, lastname, status, unique);
                        persons = screen->getstaffpointer();
                        persons->push_back(person);
                        break;
                    }

                    screen->menuscreen();
                    break;
                }
                default:
                screen->menuscreen();
                break;
            }
        }
    }
    
}

std::vector<Person*>::iterator findperson(unsigned int id, std::vector<Person*>* persons)
{
    std::vector<Person*>::iterator it;

    for(it = persons->begin(); it < persons->end(); it++)
    {
        if((*it)->getid() == id)
        {
            return it;
        }
    }
    throw std::runtime_error("Nie ma osoby o takim id");
}

void deleteperson(Screen* screen)
{
    screen->outputline();
    std::cout << "Kogo chcesz usunac? -- Podaj liczbe zeby wybrac";

    screen->menuline();
    terminal::newline();
    std::cout << "1. Ucznia" << std::endl;
    std::cout << "2. Nauczyciela" << std::endl;
    std::cout << "3. Pracownika" << std::endl;

    screen->inputline();
    std::cout << "Podaj liczbe: ";

    int choice;

    while(choice != 1 && choice != 2 && choice != 3)
    {
        try
        {
            input(choice);
        }
        catch (std::runtime_error & e)
        {
            choice = -1;
        }

        if (choice != 1 && choice != 2 && choice != 3)
        {
            screen->outputline();
            std::cout << "Nie na takiej opcji!! Podaj liczbe jeszcze raz";
            screen->inputline();
            std::cout << "Podaj liczbe: ";
        }
    }

    screen->inputline();
    std::cout << "Podaj id osoby ktora chcesz usunac";

    screen->menuline();

    screen->inputline();
    std::cout << "Podaj id: ";

    int id = -2;

    while(id < 0)
    {
        try
        {
            input(id);
        }
        catch (std::runtime_error & e)
        {
            id = -1;
        }

        if (id  < 0)
        {
            screen->outputline();
            std::cout << "Nieprawidlowy id -- Podaj id jeszcze raz";
            screen->inputline();
            std::cout << "Podaj id: ";
        }
    }

    std::vector<Person*>::iterator it;
    try
    {
        switch(choice)
        {
            case 1:
            it = findperson(id, screen->getstudentspointer());
            break;

            case 2:
            it = findperson(id, screen->getteacherspointer());
            break;

            default:
            it = findperson(id, screen->getstaffpointer());
            break;
        }
    }
    catch (std::runtime_error & e)
    {
        screen->outputline();
        std::cout << "Nie znaleziono osoby o danym numerze id -- Wpisz 1 zeby wrocic do menu";

        screen->menuline();

        int exit = 0;
        while(1)
        {
            screen->inputline();
            std::cout << "Wpisz 1: ";

            try
            {
                input(exit);
            }
            catch (std::runtime_error & e)
            {
                exit = -1;
            }

            if (exit == 1)
            {
                screen->menuscreen();
            }
        }
    }
    screen->outputline();
    std::cout << "Wpisz 1 zeby usunac || 2 zeby anulowac";


    screen->menuline();
    terminal::newline();
    std::cout << "Czy na pewno chcesz usunac: " << std::endl;

    (*it)->wyswietl(screen);

    int choice2;

    while(1)
    {
        screen->inputline();
        std::cout << "Wpisz liczbe: ";

        try
        {
            input(choice2);
        }
        catch (std::runtime_error & e)
        {
            choice2 = -1;
        }

        switch(choice2)
        {
            case 1:
            {
                switch(choice)
                {
                    case 1:
                    screen->getstudentspointer()->erase(it);
                    break;

                    case 2:
                    screen->getteacherspointer()->erase(it);

                    default:
                    screen->getstaffpointer()->erase(it);
                }
                screen->menuscreen();
            }

            case 2:
            screen->menuscreen();

            default:
            screen->outputline();
            std::cout << "Nie na takiej opcji!! Podaj liczbe jeszcze raz";
        }
    }
}