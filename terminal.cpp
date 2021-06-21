#include <iostream>
#include "terminal.h"
#include "config.h"

void terminal::charline(int n)
{
    for(int i = 0; i < n; i++)
    {
        std::cout << "=";
    }
}

void terminal::gotoline(int i)
{
    printf("\033[%i;0H", i);
}

void terminal::newline()
{
    std::cout << "\x1b[E";
}

void terminal::start()
{
    std::cout << "\033[;H";
}

void terminal::clear()
{
    std::cout << "\033[2J";
}

void terminal::cursorup()
{
    std::cout << "\033[1A";
}

void terminal::cursordown()
{
    std::cout << "\033[1B";
}

void terminal::clearline()
{
    std::cout << "\033[2K";
}


