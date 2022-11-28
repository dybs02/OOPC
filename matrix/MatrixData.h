#ifndef _MATRIXDATA_H_
#define _MATRIXDATA_H_

#include <cstring>

using namespace std;

class MatrixData {
  public:
    int row_n;
    int column_n;
    double** matrix; // matrix[row][column]
    int ref_n;
    MatrixData();
    MatrixData(int rows, int columns);
    ~MatrixData();
    MatrixData* detach();
};

#endif