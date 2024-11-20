#ifndef FAHRENHEIT_H
#define FAHRENHEIT_H

#include "Celsius.h"
#include "Kelvin.h"

class Kelvin;
class Celsius;

class Fahrenheit
{
    public:
        Fahrenheit();
        Fahrenheit(float temperature);
        virtual ~Fahrenheit();
        float Gettemp();
        void assign(float val);
        operator Celsius() const;
        operator Kelvin() const;
        void display();
    protected:

    private:
        float temp;
};

#endif // FAHRENHEIT_H
