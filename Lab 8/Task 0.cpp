#include <iostream>
using namespace std;


class Vehicle
{
private:
    string license_plate;
    string manufacturer;
    int size_limit;
public:
    Vehicle() : license_plate(""), manufacturer(""), size_limit(0)
    {}
    Vehicle(string plate, string manufact, int lim) : license_plate(plate), manufacturer(manufact), size_limit(lim)
    {}
    void setLicensePlate(string s)
    {
        license_plate = s;
    }
    void setManufacturer(string s)
    {
        manufacturer = s;
    }
    void setCarriageSizeLimit(int n)
    {
        size_limit = n;
    }

};

class GasolineVehicle : public Vehicle
{
private:
    int fuel_capacity;
    string fuel_type;
};

class ElectricVehicle : public Vehicle
{
private:
    int battery_capacity;
    float charging_time;
};

class Motorcycle : public GasolineVehicle
{
private:

};

class Car : public GasolineVehicle
{
private:
    int passenger_limit;
};

class Truck : public GasolineVehicle
{
private:
    int cargo_capacity;
};

class Hybrid : public GasolineVehicle , public ElectricVehicle
{
private:
    float energy_regen;
};

class Employee
{
private:
    string name;
    int id;
};

class Manager: public Employee
{
public:
    string getName()
    {
        return ("Mr. " + name);
    }
};

class Driver: public Employee
{
public:
    string getName()
    {
        return name;
    }
};

