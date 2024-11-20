#include "Task3.cpp"
#include <vector>

bool cmp(Vehicle* a, Vehicle* b)
{
    return a->getCarriageSizeLimit() > b->getCarriageSizeLimit();
}

void sort_vehicles_by_capacity(Vehicle** vehicles, int n)
{
    sort(vehicles, vehicles + n, cmp);
}

int main()
{
    vector <Vehicle> vehicles;

}