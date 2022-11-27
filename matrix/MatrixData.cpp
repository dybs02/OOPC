#include "MatrixData.h"

MatrixData::MatrixData()
{

}

MatrixData::MatrixData(int rows, int columns)
{
    this->row_n = rows;
    this->column_n = columns;
    this->ref_n = 1;

    this->matrix = new double*[rows];
    for (int r = 0; r < rows; r++) {
        this->matrix[r] = new double[columns];
    }
}

MatrixData::~MatrixData()
{
    for (int r = 0; r < row_n; ++r) {
        delete[] matrix[r];
    }
    delete[] matrix;
}