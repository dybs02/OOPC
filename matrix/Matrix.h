#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <iostream>
#include <memory>
#include <experimental/random>
#include <sstream>
#include "MatrixData.h"

using namespace std;

class Matrix {
  public:
    Matrix(int rows = 0, int columns = 0);
    Matrix(const Matrix& m);
    ~Matrix();
    void assignRandomValues();
    void assignSameValues(double value);
    Matrix& operator=(const Matrix& m);
    Matrix operator+(const Matrix& m) const;
    Matrix& operator+=(const Matrix& m);
    Matrix operator-(const Matrix& m) const;
    Matrix& operator-=(const Matrix& m);
    Matrix operator-() const;
    Matrix operator*(const Matrix& m) const;
    Matrix& operator*=(const Matrix& m);
    double& operator()(int row, int column);
    double operator()(int row, int column) const;
    bool operator==(const Matrix& m) const;
    bool operator!=(const Matrix& m) const;
private:
    MatrixData* data;
    void decrement();
    friend istream& operator>>(istream& s, Matrix& m);
    friend ostream& operator<<(ostream& s, const Matrix& m);
};

#endif