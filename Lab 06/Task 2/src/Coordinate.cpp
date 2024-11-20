#include "Coordinate.h"
using namespace std;
Coordinate::Coordinate() : abscissa(0.00), ordinate(0.00)
{

}

Coordinate::Coordinate(float x, float y) : abscissa(x), ordinate(y)
{

}

Coordinate::~Coordinate()
{
}

float Coordinate::Getabscissa() { return abscissa; }
void Coordinate::Setabscissa(float val) { abscissa = val; }
float Coordinate::Getordinate() { return ordinate; }
void Coordinate::Setordinate(float val) { ordinate = val; }
void Coordinate::display() { cout << "Abscissa = " << abscissa << "\nOrdinate = " << ordinate << endl;}
float Coordinate::operator - (const Coordinate& c) const
{
    return sqrt((c.abscissa - abscissa) * (c.abscissa - abscissa)) - ((c.ordinate - ordinate) * (c.ordinate - ordinate));

}
void Coordinate::move_x(float val)
{
    abscissa += val;
}
void Coordinate::move_y(float val)
{
    ordinate += val;
}
void Coordinate::move(float x_val, float y_val)
{
    abscissa += x_val;
    ordinate += y_val;
}
float Coordinate::getDistance() const {
    return std::sqrt(abscissa * abscissa + ordinate * ordinate);
}

bool Coordinate::operator>(const Coordinate& other) const {
    return getDistance() > other.getDistance();
}

bool Coordinate::operator<(const Coordinate& other) const {
    return getDistance() < other.getDistance();
}

bool Coordinate::operator>=(const Coordinate& other) const {
    return getDistance() >= other.getDistance();
}

bool Coordinate::operator<=(const Coordinate& other) const {
    return getDistance() <= other.getDistance();
}

bool Coordinate::operator==(const Coordinate& other) const {
    return getDistance() == other.getDistance();
}

bool Coordinate::operator!=(const Coordinate& other) const {
    return getDistance() != other.getDistance();
}

