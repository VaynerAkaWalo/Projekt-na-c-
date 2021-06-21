#include <iostream>
#include <string>
#include "screen.h"
#include "config.h"
#include "terminal.h"
#include "input.h"
#include "tablefunctions.h"

Screen::Screen(std::vector<Person*>* students, std::vector<Person*>* teachers, std::vector<Person*>* staff)
{
    this->students = students;
    this->teachers = teachers;
    this->staff = staff;
}

void Screen::standardscreen()
{
    terminal::clear();
    terminal::start();
    terminal::charline(INTERFACELENGTH);
    terminal::newline();
    std::cout << "Szkolna baza danych wersja: " << VERSION;
    terminal::newline();
    terminal::charline(INTERFACELENGTH);
    terminal::newline();
    terminal::newline();
    terminal::newline();
    terminal::newline();
    terminal::charline(INTERFACELENGTH);
    terminal::newline();
    terminal::newline();
    terminal::newline();
    terminal::newline();
    terminal::newline();
    terminal::newline();
    terminal::newline();
    terminal::newline();
    terminal::newline();
    terminal::charline(INTERFACELENGTH);
    terminal::newline();
    terminal::newline();
    terminal::charline(INTERFACELENGTH);
}

void Screen::menuscreen()
{
    if (this->user != "NaN")
    {
        this->outputline();
        std::cout << "Zalogowano jako " << this->user << "  --  Co chcesz zrobic?";
        
        this->menuline();
        terminal::newline();
        std::cout << "1. Wyswietl liste uczniow" << std::endl;
        std::cout << "2. Wyswietl liste nauczycieli" << std::endl;
        std::cout << "3. Wyswietl liste personelu" << std::endl;
        std::cout << "4. Dodaj nowa osobe" << std::endl;
        std::cout << "5. Usun osobe" << std::endl;
        std::cout << "6. Zakoncz program" << std::endl;

        int choice;
        this->inputline();
        std::cout << "Podaj liczbe: ";
        while(1)
        {
            try
            {
                input(choice);
            }
            catch (std::runtime_error & e)
            {
                this->outputline();
                std::cout << "Wprowadzono nieprawidlowy znak! Podaj liczbe";
                this->inputline();
                std::cout << "Podaj liczbe: ";
                choice = -1;
            }

            if(choice != -1)
            {
                switch(choice)
                {
                    case 1:
                    this->table(1);
                    break;

                    case 2:
                    this->table(2);
                    break;

                    case 3:
                    this->table(3);
                    break;

                    case 4:
                    addperson(this);
                    break;

                    case 5:
                    deleteperson(this);
                    break;

                    case 6:
                    exit(EXIT_SUCCESS);

                    default:
                    this->outputline();
                    std::cout << "Nie ma takiej opcji podaj liczbe jeszcze raz!";
                    this->inputline();
                    std::cout << "Podaj liczbe: ";
                }
            }
        }
    }
    else
    {
        login::login(this);
    }
}

void Screen::table(int mode)
{
    if(mode == 1 || mode == 2 || mode == 3)
    {
        this->outputline();
        switch(mode)
        {
            case 1:
            std::cout << "Tabela uczniow" << "  --  Aby wrocic do menu wpisz 1";
            break;

            case 2:
            std::cout << "Tabela nauczycieli" << "  --  Aby wrocic do menu wpisz 1";
            break;

            default:
            std::cout << "Tabela pracownikow" << "  --  Aby wrocic do menu wpisz 1";
            break;
        }
        
        this->menuline();
        std::cout.width(this->tableIDsize);
        std::cout << std::left << "ID" << "|";
        std::cout.width(this->tableNAMEsize);
        std::cout << std::left << "Imie" << "|";
        std::cout.width(this->tableLASTNAMEsize);
        std::cout << std::left << "Nazwisko" << "|";
        std::cout.width(this->tableSTATUSsize);
        std::cout << std::left << "Status" << "|";
        std::cout.width(this->tableUNIQUEsize);

        std::vector<Person*>* persons;

        switch(mode)
        {
            case 1:
            std::cout << std::left << "Klasa" << "|";
            persons = this->students;
            break;

            case 2:
            std::cout << std::left << "Uczy" << "|";
            persons = this->teachers;
            break;

            default:
            std::cout << std::left << "Zawod" << "|";
            persons = this->staff;
            break;
        }

        for(std::vector<Person*>::iterator it = persons->begin(); it != persons->end();it++)
        {
            terminal::newline();
            (*it)->wyswietl(this);
        }

        this->inputline();
        std::cout << "Podaj liczbe: ";
        int choice;
        while(1)
        {
            try
            {
                input(choice);
            }
            catch(std::runtime_error & e)
            {
                this->outputline();
                std::cout << "Wprowadzono niepoprawny znak, podaj 1 aby wrocic do menu!";
                this->inputline();
                std::cout << "Podaj liczbe: ";
                choice = -1;
            }

            if(choice == 1)
            {
                this->menuscreen();
            }
            else
            {
                this->outputline();
                std::cout << "Nie ma takiej opcji, aby wrocic do menu wpisz 1";
                this->inputline();
                std::cout << "Podaj liczbe: ";
            }
        }
    }
}

std::string Screen::getuser()
{
    return this->user;
}

int Screen::gettableIDsize()
{
    return this->tableIDsize;
}

int Screen::gettableNAMEsize()
{
    return this->tableNAMEsize;
}

int Screen::gettableLASTNAMEsize()
{
    return this->tableLASTNAMEsize;
}

int Screen::gettableSTATUSsize()
{
    return this->tableSTATUSsize;
}

int Screen::gettableUNIQUEsize()
{
    return this->tableUNIQUEsize;
}

std::vector<Person*>* Screen::getstudentspointer()
{
    return this->students;
}
std::vector<Person*>* Screen::getteacherspointer()
{
    return this->teachers;
}
std::vector<Person*>* Screen::getstaffpointer()
{
    return this->staff;
}

void Screen::outputline()
{
    terminal::gotoline(this->outputposition);
    terminal::clearline();
}

void Screen::inputline()
{
    terminal::gotoline(this->inputposition);
    terminal::clearline();
}

void Screen::menuline()
{
    terminal::gotoline(this->outputposition+3);
    for(int i = this->outputposition+3; i < menuend+1; i++)
    {
        terminal::clearline();
        terminal::newline();
    }
    terminal::gotoline(this->outputposition+3);
}