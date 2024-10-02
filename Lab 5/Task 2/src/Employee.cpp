#include "Employee.h"
#include <cstring>

Employee::Employee()
{
    //ctor
}

Employee::~Employee()
{
    //dtor
}

int spaceCheck(string s)
{
    int k = 0
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == ' ')
            k++;
    }
    return k;
}

float ageChecker(string date)
{
    int day = 10 * (date[0] - '0') + date[1] - '0';
    int month = 10*(date[3] - '0') + date[4] - '0';
    int year = 1000*(date[6] - '0') + 100*(date[7] - '0') + 10*(date[8] - '0') + (date[9] - '0');
    if(year >= 2006 && month >= 2 && day >= 10 )
        return 1;
    else
        return 0;
}

Employee::string Getname() { return name; }
Employee::void Setname(string val)
    {
        if(spaceCheck(val) <= 2)
            name = "John Doe";
        else
            name = val;
     }
Employee::string Getdateofbirth() { return dateofbirth; }
Employee::void Setdateofbirth(string val)
    {
        if(ageChecker(val))
            dateofbirth = "01/01/2002;
        else
            dateofbirth = val;
    }
Employee::int Getsalary() { return salary; }
Employee::void Setsalary(int val)
    {
        if(salary < 10000 || salary > 100000)
            salary = 10000
        else
            salary = val;
    }

Employee::void setInfo()
{
    string name, dob;
    int sal;

    cout << "Enter name : ";
    cin >> name;
    Setname(name);

    cout << "Enter date of birth (DD/MM/YYYY) : ";
    cin >> dob;
    Setdateofbirth(dob);

    cout << "Enter Salary : ";
    cin >> sal;
    Setsalary(sal);
}

Employee::void getInfo()
{
    cout << "Name : " << Getname();
    cout << "\nDate of birth (DD/MM/YYYY) : " << Getdateofbirth();
    cout << "\nEnter Salary : " ;
}
