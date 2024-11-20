#ifndef KELVIN_H
#define KELVIN_H

#include "Celsius.h"
#include "Fahrenheit.h"

class Fahrenheit;
class Celsius;

class Kelvin
{
    public:
        Kelvin();
        virtual ~Kelvin();
        Kelvin(float temperature);
        float Gettemp();
        void assign(float val);
        operator Fahrenheit();
        operator Celsius();
        void display();
    protected:

    private:
        float temp;
};

#endif // KELVIN_H
