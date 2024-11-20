#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "Employee.cpp"
#include <cstring>

class Employee
{
    public:
        Employee();
        virtual ~Employee();

        string Getname();
        void Setname(string val);
        string Getdateofbirth();
        void Setdateofbirth(string val);
        int Getsalary();
        void Setsalary(int val);

    protected:

    private:
        string name;
        string dateofbirth;
        int salary;
};

#endif // EMPLOYEE_
