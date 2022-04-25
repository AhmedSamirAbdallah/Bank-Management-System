#include <iostream>
#ifndef ACCOUNT_H
#define ACCOUNT_H
using namespace std;
class Account
{
    private:
        int Account_num;
        string Owner;
        string Type;
        int Money;

    public:
        Account();
        virtual ~Account();
        void setAccount_num(int num);
        void setOwner(string name);
        void setType(string type);
        void setMoney(int num);
        int getAccount_num();
        string getOwner();
        string getType();
        long long getMoney();
        void createAccount();
        void deposition(long long add);
        void withdrawing(long long sub);
        void Show_Account();
};

#endif // ACCOUNT_H
