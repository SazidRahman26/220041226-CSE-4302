#include "Task1.cpp"

enum fuelType{Petrol, Octane, CNG};
enum Maintenance{gasoline, electric, hybrid};

class GasolineVehicle : public Vehicle
{
    protected:
        int fuelTankCapacity;
        fuelType type;
    public:
        GasolineVehicle(string lplate, string manufact, int carryLim, int fuelLim, fuelType fuelTyp) : Vehicle(lplate, manufact, carryLim), fuelTankCapacity(fuelLim), type(fuelTyp)
        {} 
        double calculateFuelConsumption(double distance)
        {
            return 0.234 * distance;
        }
        void performMaintenance(Maintenance maintenance)
        {
            switch(maintenance)
            {
                case 0: cout << "Gasoline" << endl;
                    break;
                case 1: cout << "Electric" << endl;
                    break;
                case 2: cout << "Hybrif" << endl;
                    break;
                default: break;
            }
        }
};

class ElectricVehicle : public Vehicle
{
    protected:
        int batteryCapacity;
        int chargingTime;
    public:
        ElectricVehicle(string lplate, string manufact, int carryLim, int battLim, int ctime) : Vehicle(lplate, manufact, carryLim), batteryCapacity(battLim), chargingTime(ctime)
        {} 
        double electricityConsumption(double distance)
        {
            return 0.345 * distance;
        }
        void performMaintenance(Maintenance maintenance)
        {
            switch(maintenance)
            {
                case 0: cout << "Gasoline" << endl;
                    break;
                case 1: cout << "Electric" << endl;
                    break;
                case 2: cout << "Hybrif" << endl;
                    break;
                default: break;
            }
        }
};