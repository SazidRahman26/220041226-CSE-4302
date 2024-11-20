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
      static int tax;
  public:
    static int TotAccountCreated;
    static int CurAccountCreated;
    BankAccount(double minBal) : minBalance(minBal)
    {
        TotAccountCreated++;
        CurAccountCreated++;
    }
    BankAccount(int Num, string Name, string Type, double CurBalance, double MinBalance) : accountNum(Num), name(Name), type(Type), curBalance(CurBalance), minBalance(MinBalance)
    {
        TotAccountCreated++;
        CurAccountCreated++;
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
        tax += (0.1 * 0.03 * curBalance);
        curBalance = 1.03*curBalance - (0.1 * 0.03 * curBalance) ;

    }
    ~BankAccount()
    {
        cout << "Account of " << name << " with account no " << accountNum << " is destroyed with a balance BDT " << curBalance << endl;
        CurAccountCreated--;
    }
    double getBalance() const
    {
        return curBalance;
    }
    static double getTotalTax()
    {
        return tax;
    }
};

int BankAccount :: TotAccountCreated = 0;
int BankAccount :: CurAccountCreated = 0;
int BankAccount :: tax = 0;

void display_stat()
{
    cout << "Total number of BankAccount objects created: " << BankAccount :: TotAccountCreated << endl;
    cout << "Total number of BankAccount objects currently present: " << BankAccount :: CurAccountCreated << endl;
    cout << "Total amount of source tax collected from all BankAccount: " << BankAccount :: getTotalTax() << endl;
}

BankAccount Larger(const BankAccount A, const BankAccount B)
{
    double A_Balance = A.getBalance();
    double B_Balance = B.getBalance();
    if(A_Balance >= B_Balance)
        return A;
    else
        return B;
}

int main()
{
    BankAccount Ashraful(1213, "Ashraful", "savings", 123321, 0);
    BankAccount Sazid(123413, "Ashraf", "savings", 1321, 23);
    Ashraful.giveInterest();
    Sazid.giveInterest();
    display_stat();
    return 0;
}
