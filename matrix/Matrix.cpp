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

void Matrix::assignSameValues(double value)
{
    for (int r = 0; r < data->row_n; ++r) {
        for (int c = 0; c < data->column_n; ++c) {
            (*this)(r, c) = value;
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
        throw (DifferentMatrixDimensions(data, m.data));
    }

    Matrix result = Matrix(data->row_n, data->column_n);

    for (int r = 0; r < data->row_n; ++r) {
        for (int c = 0; c < data->column_n; ++c) {
            result(r, c) = (*this)(r, c) + m(r, c);
        }
    }

    *this = result;
    return *this;
}

Matrix Matrix::operator-(const Matrix& m) const
{
    return Matrix(*this) -= m;
}

Matrix& Matrix::operator-=(const Matrix& m)
{
    return (*this) += (-m);
}

Matrix Matrix::operator-() const
{
    Matrix result = Matrix(data->row_n, data->column_n);

    for (int r = 0; r < result.data->row_n; ++r) {
        for (int c = 0; c < result.data->column_n; ++c) {
            result(r, c) = (*this)(r, c) * (-1);
        }
    }

    return result;
}

Matrix Matrix::operator*(const Matrix& m) const
{
    return Matrix(*this) *= m;
}

Matrix& Matrix::operator*=(const Matrix& m)
{
    if (data->column_n != m.data->row_n) {
        throw (MatrixNotMultiplicable(data, m.data));
    }

    Matrix result = Matrix(data->row_n, m.data->column_n);

    for (int r = 0; r < result.data->row_n; ++r) {
        for (int c = 0; c < result.data->column_n; ++c) {
            double sum = 0;

            for (int n = 0; n < data->column_n; ++n) {
                sum += (*this)(r, n) * m(n, c);
            }

            result(r, c) = sum;
        }
    }

    *this = result;
    return *this;
}

double& Matrix::operator()(int row, int column)
{
//    cout << "double& operator() - write:" << endl;
    if (row < 0 || row >= data->row_n || column < 0 || column >= data->column_n) {
        throw (InvalidMatrixRange(row, column));
    }

    data = data->detach();
    return data->matrix[row][column];
}

double Matrix::operator()(int row, int column) const
{
//    cout << "double operator() - read:" << endl;
    if (row < 0 || row >= data->row_n || column < 0 || column >= data->column_n) {
        throw (InvalidMatrixRange(row, column));
    }

    return data->matrix[row][column];
}

bool Matrix::operator==(const Matrix& m) const
{
    if (data->row_n != m.data->row_n || data->column_n != m.data->column_n) {
        return false;
    }

    for (int r = 0; r < data->row_n; ++r) {
        for (int c = 0; c < data->column_n; ++c) {
            if ((*this)(r, c) != m(r, c)) {
                return false;
            }
        }
    }

    return true;
}

bool Matrix::operator!=(const Matrix& m) const
{
    return !((*this) == m);
}

void Matrix::decrement()
{
    data->ref_n--;
    if (data->ref_n == 0) {
        delete data;
    }
}

istream& operator>>(istream& s, Matrix& m)
{
    Matrix newMatrix;
    string line;

    if (getline(s, line)) {
        int rows, columns;
        stringstream ss(line);
        ss >> rows >> columns;
        newMatrix = Matrix(rows, columns);
    }

    for (int r = 0; r < newMatrix.data->row_n && getline(s, line); ++r) {
        stringstream ss(line);
        for (int c = 0; c < newMatrix.data->column_n; ++c) {
//            ss >> newMatrix.data->matrix[r][c];
            ss >> newMatrix(r, c);
        }
    }

    m = newMatrix;
    return s;
}

ostream& operator<<(ostream& s, const Matrix& m)
{
    s << "Matrix " << m.data->row_n << "x" << m.data->column_n << endl;
    for (int r = 0; r < m.data->row_n; ++r) {
        for (int c = 0; c < m.data->column_n; ++c) {
            s << m(r, c) << " ";
        }
        s << endl;
    }
    return s;
}
