#ifndef INPUT_TEMPLATE
#define INPUT_TEMPLATE

#include <iostream>

template<typename T>
void input(T &variable)
{
    std::cin >> variable;
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(256, '\n');
        throw std::runtime_error("Wprowadzono błędny znak!!!");
    }
}

#endif