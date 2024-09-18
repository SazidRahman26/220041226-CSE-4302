#include <iostream>
using namespace std;

class RationalNumber{
    private:
        int nume;
        int denom;
    public:
        void assign(int numerator, int denominator)
        {
            if(denominator == 0)
            {
                cout << "You can not assign 0 as denominator." << endl;
                return;
            }
            nume = numerator;
            denom = denominator;
        }
        double convert()
        {
            double res = nume * 1.0/denom;
            return res;
        }
        void invert()
        {
            if(nume == 0)
                cout << "You cannot assign 0 as denominator.\nInversion Failed." << endl;
            else{
                swap(nume, denom);
            }
        }
        void print()
        {
            cout << "The Rational Number is " << nume << "/" << denom << ".\n";
        }
};

int main()
{
    RationalNumber n;
    n.assign(2,0);
    n.assign(2,3);
    n.print();
    cout << n.convert() << endl;
    n.invert();
    cout << n.convert() << endl;
    n.assign(0, 5);
    n.invert();
    cout << n.convert() << endl;
}
