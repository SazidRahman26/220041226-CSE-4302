#ifndef CELSIUS_H
#define CELSIUS_H

#include "Fahrenheit.h"
#include "Kelvin.h"
#include <iostream>
class Fahrenheit;
class Kelvin;

class Celsius
{
    public:
        Celsius();
        Celsius(float temperature);
        virtual ~Celsius();
        float Gettemp();
        void assign(float temperature);
        void display();
        operator Fahrenheit() const;
        operator Kelvin() const;

    protected:

    private:
        float temp;
};

#endif // CELSIUS_H
