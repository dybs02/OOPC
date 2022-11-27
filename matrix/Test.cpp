#include "Matrix.h"

void testAddition();

int main()
{
    testAddition();

    return 0;
}

void testAddition()
{
    cout << "Testing addition" << endl;

    Matrix m1 = Matrix(2, 3);
    Matrix m2 = Matrix(2, 3);
    Matrix m3 = Matrix(2, 3);
    m1.assignRandomValues();
    m2.assignRandomValues();

    cout << "m3 = m1 + m2 :" << endl;
    m3 = m1 + m2;
    cout << m3;

    cout << "m3 += m1 :" << endl;
    m3 += m1;
    cout << m3;
}