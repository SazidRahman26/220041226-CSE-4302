#include <fstream>
#include <iostream>
using namespace std;
#include <process.h>
#include <cstdlib>S

const int MAX = 1000;
int buff[MAX];

int main()
{
    for(int j=0; j<MAX; j++)
        buff[j] = j;
    
    ofstream os;
    os.open("a:edata.dat", ios::trunc | ios::binary);
    if(!os)
    { 
        cerr << "Could not open output file\n"; 
        exit(1); 
    }
    
    os.write( reinterpret_cast<char*>(buff), MAX*sizeof(int) );
    if(!os)
    { 
        cerr << "Could not write to file\n"; 
        exit(1); 
    }
    os.close();

    for(int j=0; j<MAX; j++)
        buff[j] = 0;

    ifstream is;
    is.open("a:edata.dat", ios::binary);
    if(!is)
    { 
        cerr << "Could not open input file\n"; 
        exit(1); 
    }
    
    is.read( reinterpret_cast<char*>(buff), MAX*sizeof(int) );
    if(!is)
    { 
        cerr << "Could not read from file\n"; 
        exit(1); 
    }
    
    for(int j=0; j<MAX; j++) 
        if( buff[j] != j )
        { 
            cerr << "\nData is incorrect\n"; 
            exit(1); 
        }
    
    cout << "Data is correct\n";
    return 0;
}
