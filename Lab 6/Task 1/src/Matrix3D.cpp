#include "Matrix3D.h"
#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <vector>

Matrix3D::Matrix3D(double mat[3][3][3], int inc = 1) : increment(inc), count(0) {
        if (inc < 0) {
            increment = 1;
        }
        std::copy(&mat[0][0][0], &mat[0][0][0] + 3 * 3 * 3, &matrix[0][0][0]);
}

Matrix3D::~Matrix3D() {}

double Matrix3D::det() {
    return matrix[0][0][0] * (matrix[0][1][1] * matrix[0][2][2] - matrix[0][1][2] * matrix[0][2][1]) -
            matrix[0][0][1] * (matrix[0][1][0] * matrix[0][2][2] - matrix[0][1][2] * matrix[0][2][0]) +
            matrix[0][0][2] * (matrix[0][1][0] * matrix[0][2][1] - matrix[0][1][1] * matrix[0][2][0]);
}

void Matrix3D::incrementMatrix() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                matrix[i][j][k] += increment;
            }
        }
    }
    count++;
}

void Matrix3D::setIncrement(int val) {
    if (count == 0) {
        if (val < 0) {
            std::cout << "Cannot set negative increment value." << std::endl;
            return;
        }
        increment = val;
    } else {
        std::cout << "Cannot set increment after modifications." << std::endl;
    }
}

void Matrix3D::getMatrix(){
    for (int i = 0; i < 3; ++i) {
        std::cout << "Layer " << i + 1 << ":" << std::endl;
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                std::cout << std::setw(5) << matrix[i][j][k] << " ";
            }
            std::cout << std::endl;
        }
    }
}

Matrix3D Matrix3D::operator+(Matrix3D& other){
    Matrix3D result{{0}};
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                result.matrix[i][j][k] = matrix[i][j][k] + other.matrix[i][j][k];
            }
        }
    }
    return result;
}

Matrix3D Matrix3D::operator-(Matrix3D& other){
    Matrix3D result{{0}};
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                result.matrix[i][j][k] = matrix[i][j][k] - other.matrix[i][j][k];
            }
        }
    }
    return result;
}

bool Matrix3D::operator>(Matrix3D& other){
    return det() > other.det();
}

bool Matrix3D::operator<(Matrix3D& other){
    return det() < other.det();
}

bool Matrix3D::operator>=(Matrix3D& other){
    return det() >= other.det();
}

bool Matrix3D::operator<=(Matrix3D& other){
    return det() <= other.det();
}

bool Matrix3D::operator==(Matrix3D& other){
    return det() == other.det();
}

Matrix3D::bool operator!=(Matrix3D& other){
    return det() != other.det();
}
