#include <iostream>
using namespace std;


class Vehicle
{
private:
    string license_plate;
    string manufacturer;
    int size_limit;
public:
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
    string setLicensePlate()
    {
        return license_plate;
    }
    string setManufacturer()
    {
        return manufacturer;
    }
    int setCarriageSizeLimit()
    {
        return size_limit;
    }

};

class GasolineVehicle : public Vehicle
{
private:
    int fuel_capacity;
    string fuel_type;
public:
    GasolineVehicle(string license, string manufact, int lim, int fuel_cap, string ftype): Vehicle(license, manufact, lim), fuel_capacity(fuel_cap), fuel_type(ftype){}
};

class ElectricVehicle : public Vehicle
{
private:
    int battery_capacity;
    float charging_time;
public:
    ElectricVehicle(string license, string manufact, int lim, int bat_cap, float ctime): Vehicle(license, manufact, lim), battery_capacity(bat_cap), charging_time(ctime){}
};

class Motorcycle : public GasolineVehicle
{
public:
    Motorcycle(string license, string manufact, int lim, int fuel_cap, string ftype) : GasolineVehicle(license, manufact, lim, fuel_cap, ftype){}

};

class Car : public GasolineVehicle
{
private:
    int passenger_limit;
public:
    Car(string license, string manufact, int lim, int fuel_cap, string ftype, int plim) : GasolineVehicle(license, manufact, lim, fuel_cap, ftype), passenger_limit(plim){}
};

class Truck : public GasolineVehicle
{
private:
    int cargo_capacity;
public:
    Truck(string license, string manufact, int lim, int fuel_cap, string ftype, int ccap) : GasolineVehicle(license, manufact, lim, fuel_cap, ftype) , cargo_capacity(ccap) {}
};

class Hybrid : public GasolineVehicle , public ElectricVehicle
{
private:
    float energy_regen;
public:
    Hybrid(string license, string manufact, int lim, int fuel_cap, string ftype, int bat_cap, float ctime, float eregen) : GasolineVehicle(license, manufact, lim, fuel_cap, ftype), ElectricVehicle(license, manufact, lim, bat_cap, ctime), energy_regen(eregen){}
};

class Employee
{
private:
    string name;
    int id;
public:
    Employee(string Name, int Id) : name(Name), id(Id){}
};

class Manager: public Employee
{
public:
    Manager(string Name, int Id) : Employee(Name, Id){}
    string getName()
    {
        return ("Mr. " + name);
    }
};

class Driver: public Employee
{
public:
    Driver(string Name, int Id) : Employee(Name, Id){}
    string getName()
    {
        return name;
    }
};

