#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <iostream>
#include <memory>
#include <experimental/random>
#include <sstream>
#include "MatrixData.h"
#include "MatrixExceptions.h"

using namespace std;

class Matrix {
    class DoubleRef;
  public:
    Matrix(int rows = 0, int columns = 0);
    Matrix(const Matrix& m);
    ~Matrix();
    void assignRandomValues(); // TODO move to Test.cpp
    void assignSameValues(double value);
    Matrix& operator=(const Matrix& m);
    Matrix operator+(const Matrix& m) const;
    Matrix& operator+=(const Matrix& m);
    Matrix operator-(const Matrix& m) const;
    Matrix& operator-=(const Matrix& m);
    Matrix operator-() const;
    Matrix operator*(const Matrix& m) const;
    Matrix operator*(double d) const;
    Matrix& operator*=(const Matrix& m);
    Matrix& operator*=(double d);
    DoubleRef operator()(int row, int column);
    double operator()(int row, int column) const;
    bool operator==(const Matrix& m) const;
    bool operator!=(const Matrix& m) const;
  private:
    class DoubleRef {
      public:
        DoubleRef(Matrix* matrix, int r, int c);
        operator double() const;
        DoubleRef& operator=(double d);
        DoubleRef& operator=(const DoubleRef& ref);
        DoubleRef& operator+=(double d);
        DoubleRef& operator+=(const DoubleRef& ref);
        DoubleRef& operator*=(double d);
        DoubleRef& operator*=(const DoubleRef& ref);
      private:
        Matrix* matrix;
        int r, c;
    };
    MatrixData* data;
    void decrement();
    friend istream& operator>>(istream& s, Matrix& m);
    friend ostream& operator<<(ostream& s, const Matrix& m);
};

Matrix operator*(double d, const Matrix& m);

#endif