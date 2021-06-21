#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "terminal.h"
#include "login.h"
#include "screen.h"
#include "account.h"
#include "input.h"

bool login::checkforaccount(std::vector<Account> accounts, Account currentuser)
{
    for(Account account : accounts)
    {
        if (account == currentuser)
        return true;
    }
    return false;
}

void login::load(std::vector<Account> &accounts)
{
    std::fstream file;
    file.open("accounts.txt", std::ios::in);
    if (file.good() == false)
    {
        throw std::runtime_error("blad otwarcia pliku z kontami");
    }
    std::string login;
    std::string password;

    while(file.peek() != EOF)
    {
        std::getline(file, login, ' ');
        std::getline(file, password);
        Account account(login, password);
        accounts.push_back(account);
    }
}


void login::login(Screen* screen)
{
    if (screen->user == "NaN")
    {
        screen->standardscreen();
        std::vector<Account> accounts;
        try
        {
            login::load(accounts);
        }
        catch(std::runtime_error & e)
        {
            screen->outputline();
            std::cout << "Runtime error: " << e.what();
            exit(1);
        }

        std::string login = "";
        std::string password = "";

        screen->outputline();
        std::cout << "Logowanie - Podaj login: ";

        screen->inputline();
        std::cout << "Wpisz login: ";
        while(login == "")
        {
            try
            {
                input(login);
            }
            catch (std::runtime_error & e)
            {
                screen->outputline();
                std::cout << "Blad wejscia podaj login jeszcze raz";
                screen->inputline();
                std::cout << "Wpisz login: ";
            }
        }
        screen->outputline();
        std::cout << "Logowanie - Podaj haslo: ";
        screen->inputline();
        std::cout << "Wpisz haslo: ";
        while(password == "")
        {
            try
            {
                input(password);
            }
            catch (std::runtime_error & e)
            {
                screen->outputline();
                std::cout << "Blad wejscia podaj haslo jeszcze raz";
                screen->inputline();
                std::cout << "Wpisz haslo: ";
            }
        }
        Account currentuser(login, password);
        
        screen->outputline();
        if (login::checkforaccount(accounts, currentuser))
        {
            screen->user = login;
            screen->outputline();
            screen->menuline();
            screen->inputline();
            screen->menuscreen();
        }
        else
        {
            std::cout << "Nieprawidlowy login lub haslo!";
            screen->menuline();
            terminal::newline();
            std::cout << "1. Ponow probe logowania";
            terminal::newline();
            std::cout << "2. Zamknij program";
            screen->inputline();
            std::cout << "Podaj liczbe: ";
            int choice;
            while(1)
            {
                try
                {
                    input(choice);
                }
                catch (std::runtime_error & e)
                {
                    screen->outputline();
                    std::cout << "Podano nieprawilowy znak, podaj liczbe!";
                    screen->inputline();
                    std::cout << "Podaj liczbe: ";
                    choice = -1;
                }

                if (choice != -1)
                {
                    switch(choice)
                    {
                        case 1:
                        login::login(screen);

                        case 2:
                        exit(EXIT_SUCCESS);

                        default:
                        screen->outputline();
                        std::cout << "Nie ma takiej opcji podaj liczbe jeszcze raz!";
                        screen->inputline();
                        std::cout << "Podaj liczbe: ";
                    }
                }
            }
            
            
        }
        
    }
}