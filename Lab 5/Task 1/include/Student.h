#ifndef STUDENT_H
#define STUDENT_H

#include <string.h>
#include "Student.h"

class Student
{
    public:
        Student();
        virtual ~Student();
        static int cse1;
        static int cse2;
        static int swe;
        static int eee1;
        static int eee2;
        static int eee3;
        static int me1;
        static int me2;
        static int ipe;
        static int cee1;
        static int cee2;
        static int btm;
        static int tve;
        string Getname();
        void Setname(string val);
        string Getdept();
        void Setdept(string val);
        string Getprogram();
        void Setprogram(string val);
        string Getsection();
        void Setsection(string val);
        string Getaddress();
        void Setaddress;
        int Getyear();
        void Setyear(int val);
        float Getgpa();
        void Setgpa(float val);
        int generateID();
        void calculateGPA();

        int Getquiz1();
        void Setquiz1(int val);
        int Getquiz2();
        void Setquiz2(float val);
        int Getquiz3();
        void Setquiz3(int val);
        int Getquiz4();
        void Setquiz4(float val);
        int Getmid();
        void Setmid(int val);
        int Getfinal();
        void Setfinal(int val);
        int Getattendence();
        void Setattendence(int val);

    protected:

    private:
        string name;
        string dept;
        string program;
        string section;
        string address;
        int year;
        float gpa;
        int id;
        int quiz1;
        int quiz2;
        int quiz3;
        int quiz4;
        int mid;
        int final;
        int attendence;
};

#endif // STUDENT_H
