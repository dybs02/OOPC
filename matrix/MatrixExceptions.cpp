#include "MatrixExceptions.h"

DifferentMatrixDimensions::DifferentMatrixDimensions(MatrixData* data1, MatrixData* data2)
{
    row_n1 = data1->row_n;
    row_n2 = data2->row_n;
    column_n1 = data1->column_n;
    column_n2 = data2->column_n;
    msg = "Matrices have different ";

    if (row_n1 != row_n2) {
        msg += "number of rows (" + to_string(row_n1) + " != " + to_string(row_n2) + ")";
        if (column_n1 != column_n2) {
            msg += " and ";
        }
    }
    if (column_n1 != column_n2) {
        msg += "number of columns (" + to_string(column_n1) + " != " + to_string(column_n2) + ")";
    }
    msg += "\n";
}

const char* DifferentMatrixDimensions::what() const throw ()
{
    return msg.c_str();
}

MatrixNotMultiplicable::MatrixNotMultiplicable(MatrixData* data1, MatrixData* data2)
{
    column_n1 = data1->column_n;
    row_n2 = data2->row_n;
    msg = "Matrix does not have proper dimensions for multiplication ";
    msg += "(Matrix 1 number of columns = " + to_string(column_n1) + ", ";
    msg += "Matrix 2 number of rows = " + to_string(row_n2) + ")\n";
}

const char* MatrixNotMultiplicable::what() const throw ()
{
    return msg.c_str();
}

InvalidMatrixRange::InvalidMatrixRange(int row, int column)
{
    msg = "Unable to access Matrix at ";
    msg += "row = " + to_string(row) + ", column = " + to_string(column) + "\n";
}

const char* InvalidMatrixRange::what() const throw ()
{
    return msg.c_str();
}