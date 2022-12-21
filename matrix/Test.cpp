#include "Matrix.h"
#include <fstream>

void assignRandomValues(Matrix& m);

void testExceptions();
void testFileInput();
void testAssignments();
void testAddition();
void testSubtraction();
void testMultiplication();
void testComparison();
void testReferenceCounting();

int main()
{
    testExceptions();
    testFileInput();
    testAssignments();
    testAddition();
    testSubtraction();
    testMultiplication();
    testComparison();
    testReferenceCounting();

    return 0;
}

void assignRandomValues(Matrix& m)
{
    for (int r = 0; r < m.getRowNumber(); ++r) {
        for (int c = 0; c < m.getColumnNumber(); ++c) {
            m(r, c) = experimental::randint(-50, 50);
        }
    }
}

void testExceptions()
{
    cout << "-----------------------------" << endl;
    cout << "Testing exceptions" << endl;
    Matrix m1 = Matrix(2, 2);
    Matrix m2 = Matrix(5, 5);
    assignRandomValues(m1);
    assignRandomValues(m2);

    cout << "m1 :" << endl;
    cout << m1 << endl;

    cout << "m2 :" << endl;
    cout << m2 << endl;

    cout << "m1 + m2" << endl;
    try {
        m1 + m2;
    }catch (const exception& e) {
        cout << e.what();
    }

    cout << "m1 * m2" << endl;
    try {
        m1 * m2;
    }catch (const exception& e) {
        cout << e.what();
    }

    cout << "m1(1, 55)" << endl;
    try {
        m1(1, 55);
    }catch (const exception& e) {
        cout << e.what();
    }
}

void testFileInput()
{
    cout << "-----------------------------" << endl;
    cout << "Testing file input stream" << endl;
    Matrix m1, m2;

    {
        ifstream fileIn("m1.txt");
        fileIn >> m1;
    }
    {
        ifstream fileIn("m2.txt");
        fileIn >> m2;
    }

    cout << "m1 :" << endl;
    cout << m1 << endl;

    cout << "m2 :" << endl;
    cout << m2 << endl;
}

void testAssignments()
{
    cout << "-----------------------------" << endl;
    cout << "Testing assignments" << endl;

    Matrix m1 = Matrix(2, 3);
    m1.assignSameValues(1);

    cout << "m2 = m1" << endl << endl;
    Matrix m2 = m1;

    cout << "m1 :" << endl;
    cout << m1 << endl;

    cout << "m2 :" << endl;
    cout << m2 << endl;

    cout << "assignRandomValues(m1)" << endl << endl;
    assignRandomValues(m1);

    cout << "m1 :" << endl;
    cout << m1 << endl;

    cout << "m2 :" << endl;
    cout << m2 << endl;
}

void testAddition()
{
    cout << "-----------------------------" << endl;
    cout << "Testing addition" << endl;

    Matrix m1 = Matrix(2, 3);
    Matrix m2 = Matrix(2, 3);
    Matrix m3 = Matrix(2, 3);
    assignRandomValues(m1);
    assignRandomValues(m2);

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
    assignRandomValues(m1);
    assignRandomValues(m2);

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
    Matrix m4 = Matrix(4, 2);
    assignRandomValues(m1);
    assignRandomValues(m2);
    assignRandomValues(m4);

    cout << "m1 :" << endl;
    cout << m1 << endl;

    cout << "m2 :" << endl;
    cout << m2 << endl;

    cout << "m3 = m1 * m2 :" << endl;
    m3 = m1 * m2;
    cout << m3 << endl;

    cout << "m4 :" << endl;
    cout << m4 << endl;

    cout << "m4 *= m1 :" << endl;
    m4 *= m1;
    cout << m4 << endl;

    cout << "m1 * 100 :" << endl;
    cout << m1 * 100 << endl;

    cout << "100 * m1 :" << endl;
    cout << 100 * m1 << endl;

    cout << "m1 *= 100 :" << endl;
    m1 *= 100;
    cout << m1 << endl;
}

void testComparison()
{
    cout << "-----------------------------" << endl;
    cout << "Testing comparison" << endl;

    Matrix m1 = Matrix(2, 3);
    Matrix m2 = Matrix(3, 4);
    assignRandomValues(m1);
    assignRandomValues(m2);

    cout << "m1 :" << endl;
    cout << m1 << endl;

    cout << "m2 :" << endl;
    cout << m2 << endl;

    cout << "m1 == m2 : " << (m1 == m2) << endl;
    cout << "m1 != m2 : " << (m1 != m2) << endl;
    cout << "m1 == m1 : " << (m1 == m1) << endl;
}

void testReferenceCounting()
{
    cout << "-----------------------------" << endl;
    cout << "Testing reference counting" << endl;

    Matrix m1 = Matrix(2, 3);
    m1.assignSameValues(1);

    cout << "m1 :" << endl;
    cout << m1 << endl;

    Matrix m2(m1);
    cout << "Matrix m2(m1)" << endl;

    Matrix m3(m2);
    cout << "Matrix m3(m2)" << endl;

    Matrix m4 = m1;
    cout << "Matrix m4 = m1" << endl;

    cout << "m2 :" << endl;
    cout << m2 << endl;

    cout << "m3 :" << endl;
    cout << m3 << endl;

    cout << "m4 :" << endl;
    cout << m4 << endl;

    cout << "m1 reference count = " << m1.getReferenceNumber() << endl;

    assignRandomValues(m1);
    cout << "assignRandomValues(m1)" << endl;

    cout << "m1 :" << endl;
    cout << m1 << endl;

    cout << "m2 :" << endl;
    cout << m2 << endl;

    cout << "m3 :" << endl;
    cout << m3 << endl;

    cout << "m4 :" << endl;
    cout << m4 << endl;

    cout << "m2 :" << endl;
    cout << m2 << endl;

    cout << "m1 reference count = " << m1.getReferenceNumber() << endl;
    cout << "m2 reference count = " << m2.getReferenceNumber() << endl;
    cout << "m3 reference count = " << m3.getReferenceNumber() << endl;
    cout << "m4 reference count = " << m4.getReferenceNumber() << endl;
}