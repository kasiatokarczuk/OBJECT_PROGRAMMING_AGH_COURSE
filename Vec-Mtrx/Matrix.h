#pragma once
#include <iostream>
#include "Vector.h"
using namespace std;

class Matrix
{
public:
    Matrix(int nRows = 2, int nCols = 2, double nInitVal = 0);
    Matrix(const Matrix& m);  // copy constructor
    virtual ~Matrix();  // virtual destructor


    // getters
    int getColNo() const;
    int getRowNo() const;

public:
    Matrix& operator = (const Matrix& m); // assignment operator

    // input/output operators
    friend istream& operator >> (istream& in, Matrix& m);
    friend ostream& operator << (ostream& out, const Matrix& m);

    // indexing operator
    Vector& operator [] (int ir);
    const Vector& operator [] (int ir) const;

    // cast operator to pointer to vector
    operator Vector* () const;

    // equality operators
    friend bool operator == (const Matrix& m1, const Matrix& m2);
    friend bool operator != (const Matrix& m1, const Matrix& m2);

    // multiplication
    friend const Matrix operator * (const Matrix& m1, const Matrix& m2);
    friend const Vector operator * (const Matrix& m, const Vector& v); // matrix by vector

private:
    int nRows;
    Vector* pRows;
    void creatematrix(int rows, int cols);
    void copymatrix(const Matrix& m);
};

//----------------INLINE FUNCTIONS-------------
inline int Matrix::getRowNo() const
{
    return nRows;
}

inline int Matrix::getColNo() const
{
    return pRows[0].getDim();
}

inline void Matrix::creatematrix(int rows, int cols)
{
    if (rows < 2)
    {
        rows = 2;
    }
    nRows = rows;
    pRows = new(nothrow) Vector[rows];
    if (!pRows)
        cerr << "creatematrix: error";
}

inline void Matrix::copymatrix(const Matrix& m)
{
    for (int i = 0; i < nRows; i++)
    {
        pRows[i] = m.pRows[i];
    }
}
