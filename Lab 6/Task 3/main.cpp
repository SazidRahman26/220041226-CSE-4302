#include <iostream>

#include "Celsius.h"
#include "Fahrenheit.h"
#include "Kelvin.h"

using namespace std;

int main()
{
    Celsius c(100);
    Fahrenheit f;
    Kelvin k;

    k = c;
    k.display();
    return 0;

}
