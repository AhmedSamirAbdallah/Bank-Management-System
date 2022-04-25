#include <iostream>
#include <sstream>
#include<string>
#include<vector>
#include"Account.h"
#include<fstream>
using namespace std;
void start_screen()
{
    cout<<"\n\n\n\t\t\t\t\t\t\t BANK";
	cout<<"\n\n\t\t\t\t\t\t\tMANAGEMENT";
	cout<<"\n\n\t\t\t\t\t\t\t SYSTEM";
	//cout<<"\n\n\n\t\t\t\t\t\t\t MADE BY : Ahmed Samir Abdallah";
	cin.get();
}
void writeAccount()
{
    Account acc;
    ofstream file;
    file.open("account.dat",ios::app);
    acc.createAccount();

    file <<"Account number : "<<acc.getAccount_num()<<endl;
    file <<"Name : "<<acc.getOwner()<<endl;
    file <<"Type : "<<acc.getType()<<endl;
    file <<"Balance amount : "<<acc.getMoney()<<endl;
    file <<string(50,'*')<<endl;

    file.close();
}
string convertIntToString(long long num)
{
    string ret="";
    stringstream ss;
    ss<<num;
    ss>>ret;
    return ret;
}
int convertStringToInt(string num)
{
    long long ret=0;
    stringstream ss;
    ss<<num;
    ss>>ret;
    return ret;
}
void SearchByAccNum(long long id)
{
    bool found=0;
    string acc_number=convertIntToString(id);
    ifstream file ;
    file.open("account.dat");
    string Buffer;
    vector<string>data;
    while(getline(file,Buffer))
    {
        if(found&&Buffer[0]=='*')break;
        if(Buffer[0]=='A')
        {
            string number="";
            for(auto a:Buffer)
            {
                if(!isdigit(a))continue;
                number+=a;
            }
            if(number==acc_number)
            {
                found=1;
            }
        }
         if(found)data.push_back(Buffer);

    }
    file.close();
    if(data.empty())
    {
        cout<<"Not found \n";
        return ;
    }
    cout<<string(50,'*')<<endl;
    for(auto a:data)
    {
        cout<<a<<endl;
    }
    cout<<string(50,'*')<<endl;

}
void deposit_or_withdraw(int id,long long amount, int option)
{
    string acc_num=convertIntToString(id);
    ifstream oldFile;
    ofstream newFile;
    oldFile.open("account.dat");
    newFile.open("update.dat");
    if(!newFile)
    {
        cout<<"can't open \n";
    }
    string buffer,num="";
    bool found=0,enter=0;
    while(getline(oldFile,buffer))
    {
        if(buffer[0]=='A'&&!found&&!enter)
        {
            num="";
            for(auto a:buffer)
            {
                if(!isdigit(a))continue;
                num+=a;
            }
            if(acc_num==num)
            {
                found=1;
            }
        }
        else if(buffer[0]=='B'&&found&&!enter)
        {
            enter=1;
            string money_in="";
            for(auto a:buffer)
            {
                if(!isdigit(a))continue;
                money_in+=a;
            }
            long long LL_NUM=convertStringToInt(money_in);
            if(option)
            {
                LL_NUM+=amount;
            }
            else
            {
                if(LL_NUM>=amount)
                {
                     LL_NUM-=amount;
                }
                else
                {
                    cout<<"The account doesn't have enough Money to make this request\n";
                    return;
                }
            }
            string newBuffer="";
            for(auto a:buffer)
            {
                if(!isdigit(a))newBuffer+=a;
            }
            string newAmmountOfMoney=convertIntToString(LL_NUM);
            newBuffer+=newAmmountOfMoney;
            buffer=newBuffer;
        }
        newFile<<buffer<<endl;
    }
    if(!found)
        cout<<"\nRecord Not Found...";
    else
        cout<<"\nRecord Updated...";
    oldFile.close();
    newFile.close();
    remove("account.dat");
    rename("update.dat","account.dat");

}
void deleteAccount(long long id)
{
    ifstream oldFile;
    ofstream newFile;
    oldFile.open("account.dat");
    newFile.open("update.dat");
    string buffer;
    string acc_num=convertIntToString(id);
    bool found=0,enter=0;
    while(getline(oldFile,buffer))
    {
        if(found&&!enter&&buffer[0]=='*')found=0;
        if(buffer[0]=='A'&&!found&&!enter)
        {
            string num="";
            for(auto a:buffer)
            {
                if(!isdigit(a))continue;
                num+=a;
            }
            if(num==acc_num)
            {
                found=1;
            }
        }
        if(found)continue;
        newFile<<buffer<<endl;
    }
    newFile.close();
    oldFile.close();
    remove("account.dat");
    rename("update.dat","account.dat");
    cout<<"Record Deleted ....";
}
void modifyAccount(long long id)
{
    deleteAccount(id);
    writeAccount();
}
void showAllAccounts()
{
    ifstream file;
    file.open("account.dat");
    if(!file)
    {
        cout<<"can't open Accounts please try again....\n";
        return;
    }
    string buffer;
    while(getline(file,buffer))
    {
        cout<<buffer<<endl;
    }
    file.close();
}
int main()
{
    start_screen();

    int option;
    system("cls");
    do{
        cout<<"\n\nMAIN MEUE";
        cout<<"\n\n01.NEW ACCOUNT";
        cout<<"\n\n02.DEPOSIT AMOUNT";
        cout<<"\n\n03.WITHDRAW AMOUNT";
        cout<<"\n\n04.BALANCE ENQUIRY";
        cout<<"\n\n05.ALL ACCOUNT HOLDER LIST";
		cout<<"\n\n06. MODIFY AN ACCOUNT";
        cout<<"\n\n07.CLOSE AN ACCOUNT";
        cout<<"\n\n08.EXIT\n";
        cin>>option;
        long long acc_num,amount;
        if(option==1)
        {
            cin.ignore();
            writeAccount();
        }
        else if(option==2)
        {
            cout<<"Enter The Account number\n";
            cin>>acc_num;
            cout<<"Enter Amount of money\n";
            cin>>amount;
            deposit_or_withdraw(acc_num,amount,1);
        }
        else if(option==3)
        {
            cout<<"Enter The Account number\n";
            cin>>acc_num;
            cout<<"Enter Amount of money\n";
            cin>>amount;
            deposit_or_withdraw(acc_num,amount,0);
        }
        else if(option==4)
        {
            cout<<"Enter The Account number\n";
            cin>>acc_num;
            SearchByAccNum(acc_num);
        }
        else if(option==5)
        {
            showAllAccounts();
        }
        else if(option==6)
        {
            cout<<"Enter The Account number\n";
            cin>>acc_num;
            modifyAccount(acc_num);
        }
        else if(option==7)
        {
             cout<<"Enter The Account number to close it \n";
             cin>>acc_num;
            deleteAccount(acc_num);
        }
        cin.get();

    }while(option!=8);
    return 0;
}
