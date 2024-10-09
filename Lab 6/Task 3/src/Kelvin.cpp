#include "Celsius.h"
#include "Fahrenheit.h"
#include "Kelvin.h"
#include <iostream>
Kelvin::Kelvin()
{
}

Kelvin::~Kelvin()
{
}

Kelvin::Kelvin(float temperature) : temp(temperature)
{
    if(temperature < 0){
        std::cout << "Invalid temperature\n";
        temp = 273.15;
    }
    else
        temp = temperature;
}

float Kelvin::Gettemp() { return temp; }

void Kelvin::assign(float temperature)
{
    if(temperature < 0)
        std::cout << "Invalid temperature\n";
    else
        temp = temperature;
}

Kelvin::operator Fahrenheit()
{
    return Fahrenheit(((temp - 273.15) * 9/5) + 32);
}
Kelvin::operator Celsius()
{
    return Celsius(temp - 273.15);
}
void Kelvin::display()
{
    std::cout << "Temperature (K) = " << temp << std::endl;
}
