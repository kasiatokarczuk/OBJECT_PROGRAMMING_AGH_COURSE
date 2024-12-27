#pragma once

#include <iostream>
using namespace std;

#define VERROR					0x00
#define INDEX_OUT_OF_RANGE		0x01
#define ALLOCATION_ERROR		0x02
#define INCOMPATIBILE_SIZES		0x04


class Vector
{
public: 
	Vector(int nDim = 2, double nInitVal = 0);
	Vector(const Vector& v); 
	virtual ~Vector();  // virtual destructor, no parameters

	int getDim() const; // returns the dimension of the vector

public: //operators
	Vector& operator = (const Vector& v); // assignment operator v1 = v2 = v3
//input/output
	friend istream& operator >> (istream& in, Vector& v);
	friend ostream& operator << (ostream& out, const Vector& v);

//addition
	friend const Vector operator + (const Vector& v1, const Vector& v2); //v1+v2
	friend const Vector operator + (const Vector& v, double x);  //v+x 
	friend const Vector operator + ( double x, const Vector& v);  //x+v
	Vector& operator += (const Vector& v);  // v1+=v2 
	Vector& operator += (double x);  //v+=x

	
//substraction
	friend const Vector operator - (const Vector& v1, const Vector& v2); //v1-v2
	friend const Vector operator - (const Vector& v, double x);  //v-x 
	Vector& operator -= (const Vector& v);  // v1-=v2
	Vector& operator -= (double x);  //v-=x


//unary minus
	friend const Vector operator - (const Vector& v);  //-v


//multiplication
	friend const Vector operator * (const Vector& v, double x); //v*x
	friend const Vector operator * (double x, const Vector& v);  //x*v
	Vector& operator *= (double x);  //v*=x


//scalar multiplication
	friend double operator * (const Vector& v1, const Vector& v2); //v1*v2


//indexation
	double& operator [] (int ix);  
	const double& operator [] ( int ix ) const; 

//comparision
	friend bool operator == (const Vector& v1, const Vector& v2);
	friend bool operator != (const Vector& v1, const Vector& v2);


//cast
	operator double* () const;


private:
	void createVec(int nDim);
	void copyVec(const Vector& v);

private:
	int m_nDim; //vector dimension
	double* m_pCoord;  //vector coordinates


};


//-----------------INLINE-------------
inline Vector:: operator double* () const
{
	return m_pCoord;
}

inline int Vector::getDim() const
{
	return m_nDim;
}

inline void Vector::createVec(int nDim)
{

	if (nDim < 2)
	{
		nDim = 2;
		cerr << "createVec(): Invalid vector dimension\n";
	}
	m_nDim=nDim;
	m_pCoord = new(nothrow) double[nDim];
	if (!m_pCoord) cerr << "createVec(): Allocation error\n";
	
}

inline void Vector::copyVec(const Vector& v)
{

	memcpy(m_pCoord, (double*)v, m_nDim * sizeof(double));
}