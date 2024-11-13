#include <iostream>
#include <algorithm>
using namespace std;

//Task 1

class Vehicle
{
    protected:
        string licensePlate;
        string manufacturer;
        int carriageSizeLimit;
    public:
        Vehicle(string lplate, string manufact, int carryLim) : licensePlate(lplate), manufacturer(manufact), carriageSizeLimit(carryLim)
        {}
        int getCarriageSizeLimit()
        {
            return carriageSizeLimit;
        }
        virtual void performMaintenance() = 0;
};