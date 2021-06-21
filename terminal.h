#ifndef TERMINAL_HEADER
#define TERMINAL_HEADER

#include <string>
#include "login.h"

namespace terminal
{
    void charline(int);

    void gotoline(int);

    void newline();

    void start();

    void clear();

    void cursorup();

    void cursordown();

    void exitline();

    void clearline();

}

#endif
