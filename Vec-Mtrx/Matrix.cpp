#include "Matrix.h"
#include "Vector.h"


Matrix::Matrix(int nRows /*= 2*/, int nCols /*=2*/, double nInitVal/*= 0*/)
{
    creatematrix(nRows, nCols);

    if (nCols != 2 || nInitVal != 0)
    {
        for (int i = 0; i < nRows; i++)
        {
            pRows[i] = Vector(nCols, nInitVal);
        }
    }
}

Matrix::Matrix(const Matrix& m)
{
    pRows = NULL;
    nRows = 0;
    *this = m;
}

Matrix::~Matrix()
{
    delete[] pRows;
}

Matrix& Matrix::operator = (const Matrix& m)
{
    if (this != &m)
    {
        delete[] pRows;    
        nRows = m.getRowNo();
        creatematrix(m.getRowNo(), m.getColNo());
    }
    copymatrix(m);
    return *this;
}


istream& operator >> (istream& in, Matrix& m)
{
    for (int i = 0; i < m.getRowNo(); i++)
        in >> m.pRows[i];

    return in;
}
ostream& operator << (ostream& out, const Matrix& m)
{
    for (int i = 0; i < m.getRowNo(); i++)
        out << m.pRows[i] << endl;

    return out;
}

Vector& Matrix::operator[](int ir)
{
    return pRows[ir];
}
const Vector& Matrix::operator[](int ir) const
{
    return pRows[ir];
}

Matrix::operator Vector* () const
{
    return pRows;
}

bool operator == (const Matrix& m1, const Matrix& m2)
{
    if (m1.getRowNo() != m2.getRowNo())
    {
        cerr << "operator ==: invalid matrix sizes" << endl;
        return false;
    }

    for (int i = 0; i < m1.getRowNo(); i++)
    {
        if (m1[i] != m2[i])
            return false;
    }

    return true;
}

bool operator != (const Matrix& m1, const Matrix& m2)
{
    return !(m1 == m2);
}


const Matrix operator * (const Matrix& m1, const Matrix& m2)
{
    if (m1.getColNo() != m2.getRowNo())
    {
        cerr << "error *: invalid matrix sizes " << endl;
        return m1;
    }

    Matrix res(m1.getRowNo(), m2.getColNo());

    for (int i = 0; i < m1.getRowNo(); i++)
    {
        for (int j = 0; j < m2.getColNo(); j++)
        {
            for (int k = 0; k < m1.getColNo(); k++)
                res[i][j] += m1[i][k] * m2[k][j];
        }
    }

    return res;
}

const Vector operator * (const Matrix& m, const Vector& v)
{
    if (m.getColNo() != v.getDim())
    {
        cerr << "error *: invalid matrix sizes " << endl;
        return v;
    }

    
    Vector res( m.getColNo());

    for (int i = 0; i < m.getRowNo(); i++)
    {
        res[i] = m[i] * v;
    }

    return res;
}