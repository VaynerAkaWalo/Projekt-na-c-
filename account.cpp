#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "account.h"

Account::Account(std::string login, std::string password)
{
    this->login = login;
    this->password = password;
}

void Account::setlogin(std::string login)
{
    this->login = login;
}

void Account::setpassword(std::string password)
{
    this->password = password;
}

bool Account::operator==(const Account& account)
{
    if((this->login == account.login) && (this->password == account.password))
        return true;
    else
        return false;
}