#ifndef _MATRIXEXCEPTION_H_
#define _MATRIXEXCEPTION_H_

#include <exception>
#include <string>
#include "MatrixData.h"

class DifferentMatrixDimensions : public exception {
  public:
    DifferentMatrixDimensions(MatrixData* data1, MatrixData* data2);
    virtual const char* what() const throw ();
  private:
    int row_n1, row_n2, column_n1, column_n2;
    string msg;
};

class MatrixNotMultiplicable : public exception {
  public:
    MatrixNotMultiplicable(MatrixData* data1, MatrixData* data2);
    virtual const char* what() const throw ();
  private:
    int row_n2, column_n1;
    string msg;
};

class InvalidMatrixRange : public exception {
  public:
    InvalidMatrixRange(int row, int column);
    virtual const char* what() const throw ();
  private:
    string msg;
};

#endif