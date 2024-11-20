#include <iostream>
using namespace std;

class Account
{
    string accountNo;
    string accountName;
    float balance;
  public:
    Account(const string& name, float initialBalance, const string& accountPrefix): accountName(name), balance(bal)
    {
         accountNo = accountPrefix + "-" + to_string(nextAccountNo++);
    }
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

    string getAccountNo()
    {
        return accountNo;
    }
    string getAccountName()
    {
        return Name;
    }
    float getBalance()
    {
        return balance;
    }
};

class CurrentAccount : public Accounts
{
    const static float serviceChage;
    const static string accountPrefix;
    static string nextAccount;
public:
    CurrentAccount(const string& name, float initialBalance)
        : Account(name, initialBalance, accountPrefix) {}
};

class SavingsAccount : public Accounts
{
    float interestRate;
    float monthlyDeopsitAmount;
    const static string accountPrefix;
    static string nextAccount;
public:
    SavingsAccount(const string& name, float initialBalance, float rate, float depositAmount)
        : Account(name, initialBalance, accountPrefix), interestRate(rate), monthlyDepositAmount(depositAmount) {}
    void setInterestRate(float n)
    {
        interestRate = n;
    }
    void setMonthlyDepositAmount(float n)
    {
        monthlyDeopsitAmount = n;
    }
    float getInterestRate(float n)
    {
        return interestRate;
    }
    float getMonthlyDepositAmount(float n)
    {
        return monthlyDeopsitAmount;
    }
    string nextAccountNo()
    {
        string temp = nextAccount;
        temp[temp.size() - 1] += 1;
        return temp;
    }
};

class MonthlyDepositScheme : public Account
{
    float interestRate;
    float monthlyDepositAmount;
    const static string accountPrefix;
    static string nextAccount;
public:
    MonthlyDepositScheme(const string& name, float initialBalance, float rate, float depositAmount, const string& accountPrefix)
        : Account(name, initialBalance, accountPrefix), interestRate(rate), monthlyDepositAmount(depositAmount) {}
    void setInterestRate(float n)
    {
        interestRate = n;
    }
    void setMonthlyDepositAmount(float n)
    {
        monthlyDepositAmount = n;
    }
    string nextAccountNo()
    {
        string temp = nextAccount;
        temp[temp.size() - 1] += 1;
        return temp;
    }
};

class LoanAccount : public Account
{
    float interestRate;
    float monthlyDepositAmount;
    const static string accountPrefix;
    static string nextAccount;
public:
    LoanAccount(const string& name, float initialBalance, float rate, float depositAmount)
        : Account(name, initialBalance, accountPrefix), interestRate(rate), monthlyDepositAmount(depositAmount) {}

    void setInterestRate(float n)
    {
        interestRate = n;
    }
    void setMonthlyDepositAmount(float n)
    {
        monthlyDepositAmount = n;
    }
    float getInterestRate(float n)
    {
        return interestRate;
    }
    float getMonthlyDepositAmount(float n)
    {
        return monthlyDeopsitAmount;
    }
    string nextAccountNo()
    {
        string temp = nextAccount;
        temp[temp.size() - 1] += 1;
        return temp;
    }
};

class TwoYearMDS : public MonthlyDepositScheme
{
    float maximumInterest;
public:
    MonthlyDepositScheme(const string& name, float initialBalance, float rate, float depositAmount, const string& accountPrefix)
        : Account(name, initialBalance, accountPrefix), interestRate(rate), monthlyDepositAmount(depositAmount) {}
    void setMaximumInterest(float n)
    {
        maximumInterest = n;
    }
    float getMaximumInterest()
    {
        return maximumInterest;
    }
};

class FiveYearMDS : public MonthlyDepositScheme
{
    float maximumInterest;
public:
      MonthlyDepositScheme(const string& name, float initialBalance, float rate, float depositAmount, const string& accountPrefix)
        : Account(name, initialBalance, accountPrefix), interestRate(rate), monthlyDepositAmount(depositAmount) {}
    void setMaximumInterest(float n)
    {
        maximumInterest = n;
    }
    float getMaximumInterest()
    {
        return maximumInterest;
    }
};

class InitialDepositMDS : public MonthlyDepositScheme
{
    float maximumInterest;
    float initialDepositAmount;
public:
    InitialDepositMDS(const string& name, float initialBalance, float rate, float depositAmount,float initialAmount const string& accountPrefix)
        : Account(name, initialBalance, accountPrefix), interestRate(rate), monthlyDepositAmount(depositAmount) {}
    void setMaximumInterest(float n)
    {
        maximumInterest = n;
    }
    float getMaximumInterest()
    {
        return maximumInterest;
    }
    void setInitialDepositAmount(float n)
    {
        initialDepositAmount = n;
    }
    float getInitialDepositAmount()
    {
        return initialDepositAmount;
    }
};

int main()
{


}
