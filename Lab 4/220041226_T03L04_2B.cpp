#include <iostream>
using namespace std;

class Employee
{
private:
    string empName;
    int memberID;
    int memberAge;
    float memberSalary;
    string getStatus()
    {
        if(memberAge <= 25 && memberSalary <= 20000)
            return "Low";
        if(memberAge <= 25 && memberSalary > 20000)
            return "Moderate";
        if(memberAge > 25 && memberSalary <= 21000)
            return "Low";
        if(memberAge > 25 && memberSalary > 21000 && memberSalary <= 60000)
            return "Moderate";
        if(memberAge > 25 && memberSalary > 60000)
            return "High";
    }
public:
    FeedInfo(string name,int age, int id, float salary)
    {
        empName = name;
        memberAge = age;
        memberID = id;
        memberSalary = salary;
    }
    ShowInfo()
    {
        cout << "Employee Name: " << empName << endl;
        cout << "Employee ID: " << memberID << endl;
        cout << "Employee Age: " << memberAge << endl;
        cout << "Employee Salary: " << memberSalary << endl;
        cout << "Current status: " << getStatus() << " Salaried Person" << endl;
    }
};

int main()
{
    Employee e1;
    e1.FeedInfo("Saom", 21, 220041224, 80000.00);
    e1.ShowInfo();
    return 0;
}
