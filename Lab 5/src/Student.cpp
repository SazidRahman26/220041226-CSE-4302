#include "Student.h"

Student::Student()
{
    //ctor
}

Student::~Student()
{
    //dtor
}
Student::string Getname() { return name; }
Student::void Setname(string val) { name = val; }
Student::string Getdept() { return dept; }
Student::void Setdept(string val) { dept = val; }
Student::string Getprogram() { return program; }
Student::void Setprogram(string val) { program = val; }
Student::string Getsection() { return section; }
Student::void Setsection(string val) { section = val; }
Student::string Getaddress() { return address; }
Student::void Setaddress(string val) { address = val; }
Student::int Getyear() { return year; }
Student::void Setyear(int val) { year = val; }
Student::float Getgpa() { return gpa; }
Student::void Setgpa(float val) { gpa = val; }
Student::int generateID()
{
    int id = 0;
    id = (year % 100) * 10000000;
    switch(dept)
    {
        case "CSE" : switch(program)
                    {
                        case "CSE" : switch(section)
                                    {
                                        case "1" : id += 41100 + cse1++;
                                                    break;
                                        case "2" : id += 41200 + cse2++;
                                                    break;
                                    }
                                    break;
                        case "SWE" : id += 42100 + swe++;
                                    break;
                    }
                    break;
        case "EEE" :switch(section)
                    {
                        case "1" : id += 21100 + eee1++;
                                        break;
                        case "2" : id += 21200 + eee2++;
                                        break;
                        case "3" : id += 21300 + eee3++;
                                        break;
                    }
                    break;
        case "MPE" : switch(program)
                    {
                        case "ME" : switch(section)
                                    {
                                        case "1" : id += 11100 + me1++;
                                                    break;
                                        case "2" : id += 11200 + me2++;
                                                    break;
                                    }
                                    break;
                        case "IPE" : id += 12100 + ipe++;
                                    break;
                    }
                    break;
        case "CEE" :switch(section)
                    {
                        case "1" : id += 51100 + cee1++;
                                        break;
                        case "2" : id += 51200 + cee2++;
                                        break;
                    }
                    break;
        case "BTM" : id += 61100 + btm++;
                        break;
        case "TVE" : id += 31100 + tve++;
                        break;
    }
    return id;
}

Student::void calculateGPA()
{
    int total = quiz1 + quiz2 + quiz3 + quiz4 + mid + final + attendence;
    if(total >= 80)
        gpa = 4.00;
    else if(total >=75)
        gpa = 3.75;
    else if(total >=70)
        gpa = 3.50;
    else if(total >=65)
        gpa = 3.25;
    else if(total >=60)
        gpa = 3.0;
    else if(total >=55)
        gpa = 2.75;
    else if(total >=50)
        gpa = 2.5;
    else if(total >=45)
        gpa = 2.25;
    else if(total >=40)
        gpa = 2.00;
    else
        gpa = 0;

}
