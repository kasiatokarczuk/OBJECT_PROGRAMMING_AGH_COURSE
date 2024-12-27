#include "Vector.h"


Vector::Vector(int nDim /*= 2*/, double nInitVal /*= 0*/)
{
	createVec(nDim);
	for (int i = 0; i < nDim; i++)
	{
		m_pCoord[i] = nInitVal;
	}
}

Vector::Vector(const Vector& v)
{
	m_pCoord = NULL;
	m_nDim = 0;
	*this = v;
}


Vector:: ~Vector()
{
	delete[] m_pCoord; 
}


Vector& Vector::operator = (const Vector& v)  
{
	if (this->getDim() != v.getDim())
	{
		if (m_pCoord) delete[] m_pCoord;
		createVec(v.getDim());
	}
	copyVec(v);
	return *this;
}

istream& operator >> (istream& in, Vector& v)
{
	for (int i = 0; i < v.getDim(); i++)
		in >> v.m_pCoord[i];
	return in;
}


ostream& operator << (ostream& out, const Vector& v)
{

	out << '[';
	for (int i = 0; i < v.getDim(); i++)
	{
		out << v.m_pCoord[i] << ((i < v.getDim() - 1) ? "," : "");

	}
	out << ']';
	return out;
}


//------ADDITION---------
const Vector operator + (const Vector& v1, const Vector& v2) //v1+v2
{
	Vector res(v1);
	return res += v2;
}

const Vector operator + (const Vector& v, double x)  //v+x
{
	Vector res(v);
	return res += x;
}

const Vector operator + (double x, const Vector& v)  //x+v
{
	return v + x;
}

Vector& Vector::operator += (const Vector& v) //v1+=v2
{

	if (this->getDim() != v.getDim())
	{
		cerr << " operator += Invalid vector sizes\n";
		return *this;
	}
	for (int i = 0; i < getDim(); i++)
	{
		m_pCoord[i] += v.m_pCoord[i];
	}
	return *this;

}

Vector& Vector::operator += (double x)  //v1 += x
{
	for (int i = 0; i < getDim(); i++)
	{
		m_pCoord[i] += x;
		return *this;
	}
}


//---------SUBSTRACTION----------
const Vector operator - (const Vector& v1, const Vector& v2) 	// v1-v2 
{
	Vector res(v1);
	return res -= v2;
}

const Vector operator - (const Vector& v, double x)	//v1-x
{
	Vector res(v);
	return res -= x;
}

Vector& Vector::operator -= (const Vector& v) 	//v1 -= v2 
{
	if (this->getDim() != v.getDim())
	{
		cerr << "operator-: Invalid vector sizes\n";
		return *this;
	}

	for (int i = 0; i < getDim(); i++)
		m_pCoord[i] -= v.m_pCoord[i];

	return *this;
}

Vector& Vector::operator -= (double x)
{
	for (int i = 0; i < getDim(); i++)
		m_pCoord[i] -= x;

	return *this;
}


//--------UNARY MINUS-----------
const Vector operator - (const Vector& v) 
{
	Vector res(v);
	for (int i = 0; i < v.getDim(); i++)
		res.m_pCoord[i] *= -1;

	return res;
}


//------MULTIPLICATION-----------
const Vector operator * (const Vector& v, double x)
{
	Vector res(v);
	return res *= x;
}

const Vector operator * (double x, const Vector& v)
{
	Vector res(v);
	return res *= x;
}

Vector& Vector::operator *= (double x) 
{
	for (int i = 0; i < getDim(); i++)
		m_pCoord[i] *= x;

	return *this;

}

//--------SCALAR MULTIPLICATION-------------
double operator * (const Vector& v1, const Vector& v2) 
{
	if (v1.getDim() != v2.getDim())
	{
		cerr << "operator*: Invalid vector sizes\n";
		return NULL;
	}

	double res = 0;
	for (int i = 0; i < v1.getDim(); i++)
		res += v1.m_pCoord[i] * v2.m_pCoord[i];

	return res;
}




//---------------INDEXATION----------------- 
double& Vector::operator [] (int ix)
{
	if (this->getDim() < ix)
	{
		cerr << " indexation error\n";
		return *m_pCoord;
	}
	return m_pCoord[ix];
}

const double& Vector::operator [] (int ix) const
{
	if (this->getDim() < ix)
	{
		cerr << "indexation error\n";
		return *m_pCoord;
	}

	return m_pCoord[ix];
}



//--------------COMPARISION-----------
bool operator == (const Vector& v1, const Vector& v2)
{
	if (v1.getDim() != v2.getDim())
	{
		return false;
	}

	for (int i = 0; i < v1.getDim(); i++)
		if (v1.m_pCoord[i] != v2.m_pCoord[i]) return false;

	return true;
}

bool operator != (const Vector& v1, const Vector& v2)
{
	return !(v1 == v2);
}




