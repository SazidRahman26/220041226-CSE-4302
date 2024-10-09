#ifndef COORDINATE_H
#define COORDINATE_H
#include <iostream>
#include <math.h>

class Coordinate
{
    public:
        Coordinate();
        Coordinate(float x, float y);
        virtual ~Coordinate();
        float Getabscissa();
        void Setabscissa(float val);
        float Getordinate();
        void Setordinate(float val);
        void display();
        float operator - (const Coordinate& c) const;
        void move_x(float val);
        void move_y(float val);
        void move(float x_val, float y_val);
        float getDistance() const;
        bool operator>(const Coordinate& other) const;
        bool operator<(const Coordinate& other) const;
        bool operator>=(const Coordinate& other) const;
        bool operator<=(const Coordinate& other) const;
        bool operator==(const Coordinate& other) const;
        bool operator!=(const Coordinate& other) const;
    protected:

    private:
        float abscissa;
        float ordinate;
};

#endif // COORDINATE_H
