#include <iostream>
using namespace std;

class Account
{
    string accountNo;
    string accountName;
    float balance;
  public:
    Account(){}
    void setAccountNo(string s)
    {
        accountNo = s;
    }
    void setAccountName(string s)
    {
        accountName = s;
    }
    void setBalance(int n)
    {
        balance = n;
    }

    void getAccountNo()
    {
        return accountNo;
    }
    void getAccountName()
    {
        return Name;
    }
    void getBalance()
    {
        return balance;
    }
};

class CurrentAccount : public Accounts
{}
