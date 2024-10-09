#ifndef MATRIX3D_H
#define MATRIX3D_H


class Matrix3D {
private:
    double matrix[3][3][3];
    int increment;
    int count;

public:

    Matrix3D(double mat[3][3][3], int inc = 1);
    ~Matrix3D();
    double det();
    void incrementMatrix();
    void setIncrement(int val);
    void getMatrix();
    Matrix3D operator+(const Matrix3D& other);
    Matrix3D operator-(const Matrix3D& other);
    bool operator>(const Matrix3D& other);
    bool operator<(const Matrix3D& other);
    bool operator>=(const Matrix3D& other);
    bool operator<=(const Matrix3D& other);
    bool operator==(const Matrix3D& other);
    bool operator!=(const Matrix3D& other);
};


#endif
