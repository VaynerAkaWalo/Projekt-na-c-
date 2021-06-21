#ifndef ACCOUNT_CLASS
#define ACCOUNT_CLASS

#include <string>

class Account
{
    private:
    std::string login;
    std::string password;

    public:
    Account();
    Account(std::string, std::string);

    void setlogin(std::string);
    void setpassword(std::string);
    bool operator ==(const Account&);
};

#endif