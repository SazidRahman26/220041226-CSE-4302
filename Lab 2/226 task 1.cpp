#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, c, d;
    char ch;
    cout << "Enter first fraction: ";
    cin >> a >> ch >> b;
    cout << "Enter second fraction: ";
    cin >> c >> ch >> d;
    cout << "Sum = " << (a * d + b * c) << "/" << (b * d) << endl;
    return 0;
}
