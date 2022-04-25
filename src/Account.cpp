#include "Account.h"
#include <iomanip>
Account::Account():Account_num(0),Owner(""),Type(""),Money(0){}

Account::~Account()
{
    //dtor
}
void Account::setAccount_num(int num)
{
    Account_num=num;
}
void Account::setOwner(string name)
{
    Owner=name;
}
void Account::setType(string type)
{
    Type=type;
}
void Account::setMoney(int money)
{
    Money=money;
}
int Account::getAccount_num()
{
    return Account_num;
}
string Account::getOwner()
{
    return Owner;
}
string Account::getType()
{
    return Type;
}
long long Account::getMoney()
{
    return Money;
}
void Account::createAccount()
{
    string name ,type ;
    int acc_num,option;
    long long money;

    cout<<"\n\nEnter The Name of The account owner : ";
    getline(cin,name);
    setOwner(name);
    cout<<"\nEnter The account Number. :";
    cin>>acc_num;
    setAccount_num(acc_num);


    cout<<"\nSelect Type of The account :\n";
    cout<<"01: Checking account.\n";
    cout<<"02: Savings accounts.\n";
    cout<<"03: Money market accounts (MMAs).\n";
    cout<<"04: Certificate of deposit accounts (CDs).\n";
    cin>>option;
    if(option==1)
    {
        setType("Checking account");
    }
    else if(option==2)
    {
        setType("Savings account.");

    }
    else if(option==3)
    {
        setType("Money market account (MMA).");
    }
    else
    {
        setType("Certificate of deposit account (CD).");
    }

    cout<<"\nEnter The Initial amount(>=1000 for Saving and >=1000 for current ) : ";
    cin>>money;
    setMoney(money);

    cout<<"\n\n\nAccount Created.....\n";
}
void Account::deposition(long long add)
{
    long long sum=getMoney()+add;
    setMoney(sum);
    cout<<"Done.....\n";
}
void Account::withdrawing(long long get)
{
    if(Money<get)
    {
        cout<<"Can't make this operation due to money not enough in your account\n";
        return ;
    }
    int subtract_=getMoney()-get;
    setMoney(subtract_);
    cout<<"Done.....\n";
}
void Account::Show_Account()
{
    cout<<string(50,'-')<<endl;;
    cout<<"\nAccount No. : "<<Account_num<<endl;
	cout<<"\nAccount owner Name : "<<Owner<<endl;
	cout<<"\nType of Account : "<<Type<<endl;
	cout<<"\nBalance amount : "<<Money<<endl;
    cout<<string(50,'-')<<endl;;

}

