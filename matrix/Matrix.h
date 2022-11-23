#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <istream>
#include <ostream>

class Matrix {
  public:
    Matrix();
    Matrix(const Matrix& m);
    Matrix& operator=(const Matrix& m);
    Matrix operator+(const Matrix& c) const;
    Matrix operator-(const Matrix& c) const;
    Matrix operator-() const;
    Matrix operator*(const Matrix& c) const;
    Matrix& operator+=(const Matrix& c);
    Matrix& operator-=(const Matrix& c);
    Matrix& operator*=(const Matrix& c);
    double& operator()(int x, int y);
    double operator()(int x, int y) const;
private:
    friend std::istream& operator>>(std::istream& s, Matrix& m);
    friend std::ostream& operator<<(std::ostream& s, const Matrix& m);
};

#endif