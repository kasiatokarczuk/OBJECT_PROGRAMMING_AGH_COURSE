#pragma once
#include <iostream>
#include<math.h>

using namespace std;

class Complex
{
public:
	Complex(double Re = 0, double Im = 0);  // Default constructor
	Complex(const Complex& z); // Copy constructor

	// Input/Output operators
	friend istream& operator >>(istream& in, Complex& z);
	friend ostream& operator <<(ostream& out, const Complex& z);

	// Setters
	void SetRe(double re);  // Set real part
	void SetIm(double im);  // Set imaginary part
	void SetComplex(double, double); // Set both real and imaginary parts

	// Getters
	double GetRe() const;
	double GetIm() const;

	Complex& operator = (const Complex& z); // Assignment operator

	friend Complex operator +(const Complex& z1, const Complex& z2); // Addition
	friend Complex operator -(const Complex& z1, const Complex& z2); // Subtraction
	friend Complex operator *(const Complex& z1, const Complex& z2); // Multiplication
	friend Complex operator /(const Complex& z1, const Complex& z2); // Division

	// Operators
	Complex& operator +=(const Complex& z1);
	Complex& operator -=(const Complex& z1);
	Complex& operator *=(const Complex& z1);
	Complex& operator /=(const Complex& z1);

	operator double(); // Convert to real part
	double Modulo();  // Calculates modulus


private:
	double m_re;
	double m_im;

	double sq();   // Helper function
};



//-------------INLINE FUNCTIONS-------------------
inline double Complex::GetRe() const {
	return m_re;
};
inline double Complex::GetIm() const {
	return m_im;
};

inline void Complex::SetIm(double im) {
	m_im = im;
};

inline void Complex::SetRe(double re) {
	m_re = re;
}


inline void Complex::SetComplex(double re, double im) {
	m_re = re;
	m_im = im;
};

inline Complex::operator double() {
	return GetRe();
}



