#include <bits/stdc++.h>

using namespace std;

typedef struct fraction{
    int nume;
    int denom;
} fraction;

int main()
{
    fraction a, b, ans;
    char ch;

    cout << "Enter first fraction: ";
    cin >> a.nume >> ch >> a.denom;

    cout << "Enter second fraction: ";
    cin >> b.nume >> ch >> b.denom;

    ans.nume = (a.nume * b.denom) + (a.denom * b.nume);
    ans.denom = a.denom * b.denom;

    cout << "Sum = " << ans.nume << "/" << ans.denom << endl;
    return 0;
}
