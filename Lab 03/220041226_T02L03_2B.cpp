#include <iostream>
using namespace std;

class RationalNumber{
    private:
        int nume;
        int denom;
    public:
        int assign(int numerator, int denominator)
        {
            if(denominator == 0)
            {
                return -1;
            }
            nume = numerator;
            denom = denominator;
            return 0;
        }
        double convert()
        {
            double res = nume * 1.0/denom;
            return res;
        }
        int invert()
        {
            if(nume == 0)
                return -1;
            swap(nume, denom);
                return 0;

        }
        void print()
        {
            cout << "The Rational Number is " << nume << "/" << denom << ".\n";
        }
};

int main()
{
    RationalNumber n;
    if(n.assign(2,0))
    {
        cout << "You can not assign 0 as denominator." << endl;
    }
    if(n.assign(2,3))
    {
        cout << "You can not assign 0 as denominator." << endl;
    }
    n.print();
    if(n.invert())
        cout << "You can not assign 0 as denominator. Inversion failed!" << endl;
    else
        cout << n.convert() << endl;
    n.print();
    n.assign(0, 5);
    if(n.invert())
        cout << "You can not assign 0 as denominator. Inversion failed!" << endl;
    else
        cout << n.convert() << endl;
    n.print();
    return 0;
}
