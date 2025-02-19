#include <fstream>
#include <iostream>
using namespace std;

int main()
{
    char ch;
    ifstream infile("TEST.TXT");
    
    while (1)
    {
        infile.get(ch);
        if(infile == 0)
            break;
        cout << ch;
    }
    
    cout << endl;
    return 0;
}