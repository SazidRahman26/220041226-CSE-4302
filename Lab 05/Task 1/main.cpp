#include <iostream>
#include "Student.h"
#include <time.h>
#include <string>

using namespace std;


Student::static int cse1 = 1;
Student::static int cse2 = 1;
Student::static int swe = 1;
Student::static int eee1 = 1;
Student::static int eee2 = 1;
Student::static int eee3 = 1;
Student::static int me1 = 1;
Student::static int me2 = 1;
Student::static int ipe = 1;
Student::static int cee1 = 1;
Student::static int cee2 = 1;
Student::static int btm = 1;
Student::static int tve = 1;

void EditInformationByKeyboard(Student *data)
{
    string name,dept,address,section,prog;
    int year;
    float gpa;

    cout << "Enter name: ";
    getline(cin, name);
    data.Setname(name);

    cout << "Enter department: ";
    cin >> dept;
    data.Setdept(dept);

    cout << "Enter program: ";
    cin >> prog;
    data.Setprogram(prog);

    cout << "Enter section: ";
    cin >> section;
    data.Setsection(section);

    cout << "Enter year: ";
    cin >> year;
    data.Setyear(year);

    cout << "Enter address: ";
    getline(cin, address);
    data.Setaddress(address);

    cout << "Enter gpa: ";
    cin >> gpa;
    data.Setgpa(gpa);
}

void generateInformaiotnRandom(Student *data)
{
    srand(time(0));
    data.quiz1 = rand() % 11;
    data.quiz2 = rand() % 11;
    data.quiz3 = rand() % 11;
    data.quiz4 = rand() % 11;
    data.attendenceattend = rand() % 11;
    data.mid = rand() % 26;
    data.final = rand() % 26;
}

int compare_str(Student const *a,Student const *b){
    string aa= a.Getname();
    string bb= b.Getname();

    if(aa==bb) return 0;
    else if(aa>bb) return 1;
    else return -1;
}

void ShowAllAlphabetically(Student ar[])
{
    qsort(ar,100,sizeof(ar),compare_str);
}

int main()
{
    Student info[100];

    return 0;
}
