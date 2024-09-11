#include <bits/stdc++.h>

using namespace std;

enum etype {laborer, secretary, manager, accountant, executive, researcher};

int main()
{
    char ch;
    etype employee;

    cout << "Enter employee type (First letter only): ";
    cin >> ch;

    switch(ch){
        case 'l': employee = laborer;
            break;
        case 's': employee = secretary;
            break;
        case 'm': employee = manager;
            break;
        case 'a': employee = accountant;
            break;
        case 'e': employee = executive;
            break;
        case 'r': employee = researcher;
            break;
        default: cout << "Invalid employee type!"<<endl;
            return 0;
    }

    cout << "Employee type is ";

    switch(employee){
        case 0: cout << "laborer";
            break;
        case 1: cout << "secretary";
            break;
        case 2: cout << "manager";
            break;
        case 3: cout << "accountant";
            break;
        case 4: cout << "executive";
            break;
        case 5: cout << "researcher";
            break;

    }
    cout << endl;
    return 0;

}
