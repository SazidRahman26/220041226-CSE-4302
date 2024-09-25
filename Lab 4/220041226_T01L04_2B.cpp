#include <iostream>
#include <cmath>
using namespace std;

float pi = 2 * asin(1);

class Calculator
{
private:
    float value;
public:
    Calculator() : value(0)
    {

    }
    float getCurrent(float val)
    {
        return val;
    }
    void setCurrent(float val)
    {
        value = val;
    }
    float calculateSine()
    {
        return sin(value*pi/180);
    }
    float calculateCosine()
    {
        return cos(value*pi/180);
    }
    float calculateTangent()
    {
        if(value == 90 || value == 270)
        {
            cout << "Invalid operation; undefined result." << endl;
            return -1;
        }
        return tan(value*pi/180);
    }
    float calculateArcSine()
    {
        int angle = pi*value/180;
        cout << angle << endl;
        return asin(angle);
    }
    float calculateArcCosine()
    {
        int angle = pi*value/180;
        cout << angle << endl;
        return acos(angle);
    }
    float calculateArcTangent()
    {
        int angle = pi*value/180;
        cout << angle << endl;
        return atan(angle);
    }
    void calculateForAngle(float paramAngle)
    {
        cout << "Sine: " << sin(paramAngle * pi / 180.0) << endl;
        cout << "Cosine: " << cos(paramAngle * pi / 180.0) << endl;
        if(paramAngle == 90 || paramAngle == 270)
            cout << "Invalid operation: Undefined result!" << endl;
        else
            cout << "Tangent: " << tan(paramAngle * pi / 180.0) << endl;
    }
    void clear()
    {
        value = 0;
    }
    void display()
    {
        cout << "Calculator display: " << value << endl;
    }
    ~Calculator()
    {
        cout << "Destructor of the Calculator object is called" << endl;
    }
};

int main()
{
    Calculator c1;
    c1.setCurrent(50);
    cout << c1.calculateSine() << endl;
    cout << c1.calculateCosine() << endl;
    cout << c1.calculateTangent() << endl;
    cout << c1.calculateArcSine() << endl;
    cout << c1.calculateArcCosine() << endl;
    cout << c1.calculateArcTangent() << endl;
    c1.calculateForAngle(90.0);

}
