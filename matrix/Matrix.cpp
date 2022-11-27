#include "Matrix.h"

Matrix::Matrix(int rows, int columns)
{
    data = new MatrixData(rows, columns);
}

Matrix::Matrix(const Matrix& m)
{
    m.data->ref_n++;
    data = m.data;
}

Matrix::~Matrix()
{
    this->decrement();
}

void Matrix::assignRandomValues()
{
    for (int r = 0; r < data->row_n; ++r) {
        for (int c = 0; c < data->column_n; ++c) {
            (*this)(r, c) = experimental::randint(-50, 50);
        }
    }
}

Matrix& Matrix::operator=(const Matrix& m)
{
    m.data->ref_n++;
    this->decrement();
    data = m.data;
    return *this;
}

Matrix Matrix::operator+(const Matrix& m) const
{
    return Matrix(*this) += m;
}

Matrix& Matrix::operator+=(const Matrix& m)
{
    if (data->row_n != m.data->row_n || data->column_n != m.data->column_n) {
        // TODO throw custom error
        return *this;
    }

    Matrix result = Matrix(data->row_n, data->column_n);

    for (int r = 0; r < data->row_n; ++r) {
        for (int c = 0; c < data->column_n; ++c) {
            result(r, c) = data->matrix[r][c] + m.data->matrix[r][c];
        }
    }

    *this = m;
    return *this;
}

double& Matrix::operator()(int row, int column)
{
    // TODO add range check & throw custom error
    return data->matrix[row][column];
}

void Matrix::decrement()
{
    data->ref_n--;
    if (data->ref_n == 0) {
        delete data;
    }
}

ostream& operator<<(ostream& s, const Matrix& m)
{
    s << "Matrix " << m.data->row_n << "x" << m.data->column_n << endl;
    for (int r = 0; r < m.data->row_n; ++r) {
        for (int c = 0; c < m.data->column_n; ++c) {
            s << m.data->matrix[r][c] << " ";
        }
        s << endl;
    }
    return s;
}
