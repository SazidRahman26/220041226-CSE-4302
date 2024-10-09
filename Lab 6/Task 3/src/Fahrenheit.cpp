#include "Celsius.h"
#include "Fahrenheit.h"
#include "Kelvin.h"
#include <iostream>
Fahrenheit::Fahrenheit()
{

}

Fahrenheit::Fahrenheit(float temperature)
{
    if(temperature < -459.67){
        std::cout << "Invalid temperature\n";
        temp = 32;
    }
    else
        temp = temperature;
}

Fahrenheit::~Fahrenheit()
{

}

float Fahrenheit::Gettemp() { return temp; }

void Fahrenheit::assign(float temperature)
{
    if(temperature < -459.67)
        std::cout << "Invalid temperature\n";
    else
        temp = temperature;
}
Fahrenheit::operator Celsius() const
{
    return Celsius((temp - 32) * (5.0/9.0));
}
Fahrenheit::operator Kelvin() const
{
    return Kelvin(((temp - 32) * 5.0/9.0) + 273.15);
}
void Fahrenheit::display()
{
    std::cout << "Temperature (F) = " << temp << std::endl;
}
