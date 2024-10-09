#include "Celsius.h"
#include "Fahrenheit.h"
#include "Kelvin.h"

Celsius::Celsius() : temp(0.00)
{
}

Celsius::Celsius(float temperature)
{
    if(temperature < -273.15){
        std::cout << "Invalid temperature\n";
        temp = 0;
    }
    else
        temp = temperature;
}
Celsius::~Celsius()
{
}

float Celsius::Gettemp()
{
    return temp;
}
void Celsius::assign(float temperature)
{
    if(temperature < -273.15)
        std::cout << "Invalid temperature\n";
    else
        temp = temperature;
}
void Celsius::display()
{
    std::cout << "Temperature (C) = " << temp << std::endl;
}

Celsius::operator Fahrenheit() const
{
    return Fahrenheit(temp*(9.0/5.0) + 32);
}
Celsius::operator Kelvin()
{
    return Kelvin(temp + 273.15);
}
