#include <iostream>
#include <ctime>
#include "Coordinate.h"
using namespace std;

void randomAssignment(Coordinate c[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; ++i) {
        float x = static_cast<float>(rand() % 201 - 100); // Random x between -100 and 100
        float y = static_cast<float>(rand() % 201 - 100); // Random y between -100 and 100
        c[i] = Coordinate(x, y);
    }
}

void sort(Coordinate c[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (c[j] > c[j + 1]) {
                Coordinate temp = c[j];
                c[j] = c[j + 1];
                c[j + 1] = temp;
            }
        }
    }
}

Coordinate highest(const Coordinate c[], int size) {
    Coordinate max_Coord = c[0];
    for (int i = 1; i < size; ++i) {
        if (c[i] > max_Coord) {
            max_Coord = c[i];
        }
    }
    return max_Coord;
}

Coordinate lowest(const Coordinate c[], int size) {
    Coordinate min_Coord = c[0];
    for (int i = 1; i < size; ++i) {
        if (c[i] < min_Coord) {
            min_Coord = c[i];
        }
    }
    return min_Coord;
}

int main()
{
    Coordinate ar[10], h, l;
    randomAssignment(ar, 10);
    h = highest(ar, 10);
    l =lowest(ar, 10);
    for(int i = 0; i < 10; i++)
        ar[i].display();
    return 0;
}
