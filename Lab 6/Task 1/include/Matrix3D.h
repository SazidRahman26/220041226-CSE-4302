#ifndef MATRIX3D_H
#define MATRIX3D_H


class Matrix3D {
private:
    double matrix[3][3];
    int increment;
    int count;
public:

    Matrix3D(double mat[3][3], int inc);
    ~Matrix3D();
    double det();
    void incrementMatrix();
    void setIncrement(int val);
    void getMatrix();
    void getInverse();
    Matrix3D operator+(const Matrix3D& other) const;
    Matrix3D operator-(const Matrix3D& other) const;
    bool operator>(const Matrix3D& other) const;
    bool operator<(const Matrix3D& other) const;
    bool operator>=(const Matrix3D& other) const;
    bool operator<=(const Matrix3D& other) const ;
    bool operator==(const Matrix3D& other) const;
    bool operator!=(const Matrix3D& other) const;
};


#endif
