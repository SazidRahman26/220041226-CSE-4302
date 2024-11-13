#include "Task2.cpp"

class Motorcycle : public GasolineVehicle
{
    private:
    public:
        Motorcycle(string plate, string maker, double limit,
               double tankCapacity,fuelType fuel)
        : GasolineVehicle(plate, maker, limit, tankCapacity, fuel) {}
        double calculateFuelConsumption(double distance)
        {
            return 0.31 * distance;
        }
        void performMaintenance(Maintenance maintenance)
        {
            switch(maintenance)
            {
                case 0: cout << "Motorcycle - Gasoline" << endl;
                    break;
                case 1: cout << "Motorcycle - Electric" << endl;
                    break;
                case 2: cout << "Motorcycle - Hybrid" << endl;
                    break;
                default: break;
            }
        }

};

class Car : public GasolineVehicle
{
    private:
        int passengerCapacity;
    public:
        Car(string plate, string maker, double limit,
        double tankCapacity, fuelType fuel, int passengers)
        : GasolineVehicle(plate, maker, limit, tankCapacity, fuel), passengerCapacity(passengers) {}
        double calculateFuelConsumption(double distance)
        {
            return 0.2 * distance;
        }
        void performMaintenance(Maintenance maintenance)
        {
            switch(maintenance)
            {
                case 0: cout << "Car - Gasoline" << endl;
                    break;
                case 1: cout << "Car - Electric" << endl;
                    break;
                case 2: cout << "Car - Hybrid" << endl;
                    break;
                default: break;
            }
        }
};

class Truck : public GasolineVehicle
{
    private:
        int cargoCapacity;
    public:
        Truck(string plate, string maker, double limit,
          double tankCapacity, fuelType fuel, double cargo)
        : GasolineVehicle(plate, maker, limit, tankCapacity, fuel), cargoCapacity(cargo) {}

        double calculateFuelConsumption(double distance)
        {
            return 0.41 * distance;
        }
        void performMaintenance(Maintenance maintenance)
        {
            switch(maintenance)
            {
                case 0: cout << "Truck - Gasoline" << endl;
                    break;
                case 1: cout << "Truck - Electric" << endl;
                    break;
                case 2: cout << "Truck - Hybrid" << endl;
                    break;
                default: break;
            }
        }
};

class HybridVehicle : public GasolineVehicle, public ElectricVehicle
{
    private:
        double energyRegenerationEfficiency;
    public:
        HybridVehicle(string plate, string maker, double limit,
              double tankCapacity, fuelType fuel, double batteryCap,
              double chargeTime, double regenEfficiency)
    :
      GasolineVehicle(plate, maker, limit, tankCapacity, fuel),
      ElectricVehicle(plate, maker, limit, batteryCap, chargeTime),
      energyRegenerationEfficiency(regenEfficiency) {}

        double calculateFuelConsumption(double distance)
        {
            return 0.31 * energyRegenerationEfficiency *distance;
        }
        void performMaintenance(Maintenance maintenance)
        {
            switch(maintenance)
            {
                case 0: cout << "HybriVehicle - Gasoline" << endl;
                    break;
                case 1: cout << "HybriVehicle - Electric" << endl;
                    break;
                case 2: cout << "HybriVehicle - Hybrid" << endl;
                    break;
                default: break;
            }
        }
};