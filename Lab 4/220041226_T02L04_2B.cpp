#include <iostream>
using namespace std;

class BankAccount
{
  private:
      int accountNum;
      string name;
      string type;
      double curBalance;
      const double minBalance;
  public:
    BankAccount(double minBal) : minBalance(minBal)
    {

    }
    BankAccount(int Num, string Name, string Type, double CurBalance, double MinBalance) : accountNum(Num), name(Name), type(Type), curBalance(CurBalance), minBalance(MinBalance)
    {

    }
    void setNum(int accountNum)
    {
        this->accountNum = accountNum;
    }
    void setName(string name)
    {
        this->name = name;
    }
    void setType(string type)
    {
        this->type = type;
    }
    void setCurrentBalance(double curBalance)
    {
        this->curBalance = curBalance;
    }
    void displayInfo()
    {
        cout << "Account Number: " << accountNum << endl;
        cout << "Account Name: " << name << endl;
        cout << "Account Type: " << type << endl;
        cout << "Current Balance: " << curBalance << endl;
        cout << "Minimum Balance: " << minBalance << endl;
    }
    void showBalance()
    {
        cout << "Current Balance: " << curBalance << endl;
    }
    void deposit(double amount)
    {
        if(amount < minBalance)
            cout << "Invalid Amount!" << endl;
        else
            curBalance += amount;
    }
    void withdraw(double amount)
    {
        if((curBalance - amount) < minBalance)
            cout << "Invalid Amount!" << endl;
        else
            curBalance -= amount;
    }
    void giveInterest()
    {
        curBalance = 1.03*curBalance - (0.1 * 0.03 * curBalance);
    }
    ~BankAccount()
    {
        cout << "Account of " << name << " with account no " << accountNum << " is destroyed with a balance BDT " << curBalance << endl;
    }
};

int main()
{

}
