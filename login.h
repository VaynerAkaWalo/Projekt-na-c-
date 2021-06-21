#ifndef LOGIN_HEADER
#define LOGIN_HEADER

#include <string>
#include <vector>
#include "screen.h"
#include "account.h"

class Screen;

class Account;

namespace login
{
    void login(Screen*);

    bool checkforaccount(std::vector<Account>, Account);

    void load(std::vector<Account>&);

}

#endif