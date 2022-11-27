#include "Matrix.h"

void testAddition();
void testSubtraction();
void testMultiplication();

int main()
{
//    testAddition();
    testSubtraction();
//    testMultiplication();

    return 0;
}

void testAddition()
{
    cout << "-----------------------------" << endl;
    cout << "Testing addition" << endl;

    Matrix m1 = Matrix(2, 3);
    Matrix m2 = Matrix(2, 3);
    Matrix m3 = Matrix(2, 3);
    m1.assignRandomValues();
    m2.assignRandomValues();

    cout << "m1 :" << endl;
    cout << m1 << endl;

    cout << "m2 :" << endl;
    cout << m2 << endl;

    cout << "m3 = m1 + m2 :" << endl;
    m3 = m1 + m2;
    cout << m3 << endl;

    cout << "m3 += m1 :" << endl;
    m3 += m1;
    cout << m3 << endl;
}

void testSubtraction()
{
    cout << "-----------------------------" << endl;
    cout << "Testing subtraction" << endl;

    Matrix m1 = Matrix(2, 3);
    Matrix m2 = Matrix(2, 3);
    Matrix m3 = Matrix(2, 3);
    m1.assignRandomValues();
    m2.assignRandomValues();

    cout << "m1 :" << endl;
    cout << m1 << endl;

    cout << "m2 :" << endl;
    cout << m2 << endl;

    cout << "-m1 :" << endl;
    cout << -m1 << endl;

    cout << "m3 = m1 - m2 :" << endl;
    m3 = m1 - m2;
    cout << m3 << endl;

    cout << "m3 -= m1 :" << endl;
    m3 -= m1;
    cout << m3 << endl;
}

void testMultiplication()
{
    cout << "-----------------------------" << endl;
    cout << "Testing multiplication" << endl;

    Matrix m1 = Matrix(2, 3);
    Matrix m2 = Matrix(3, 4);
    Matrix m3 = Matrix(4, 2);
    m1.assignRandomValues();
    m2.assignRandomValues();

    cout << "m1 :" << endl;
    cout << m1 << endl;

    cout << "m2 :" << endl;
    cout << m2 << endl;

    cout << "m3 = m1 * m2 :" << endl;
    m3 = m1 * m2;
    cout << m3 << endl;

    cout << "m3 *= m1 :" << endl;
    m3 *= m1;
    cout << m3 << endl;
}