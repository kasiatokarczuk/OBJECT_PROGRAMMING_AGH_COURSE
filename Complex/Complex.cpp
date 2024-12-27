#include "Complex.h"

Complex::Complex(double Re, double Im) {
	m_re = Re;
	m_im = Im;
};


Complex::Complex(const Complex& z) {
	*this = z;
};


Complex& Complex::operator=(const Complex& z) {
	if (this != &z) {
		m_re = z.m_re;
		m_im = z.m_im;
	}
	return *this;
}


istream& operator >>(istream& in, Complex& z) 
{
	double w;
	in >> w;
	z.SetRe(w);
	in >> w;
	z.SetIm(w);
	return in;
};


ostream& operator <<(ostream& out, const Complex& z) {
	out << z.GetRe() << ',' << z.GetIm();
	return out;
};


Complex operator +(const Complex& z1, const Complex& z2) {
	Complex res(z1);
	return res += z2;
};


Complex operator -(const Complex& z1, const Complex& z2) {
	Complex res(z1);
	return res -= z2;
};


Complex operator *(const Complex& z1, const Complex& z2) {
	Complex res(z1);
	return res *= z2;
};


Complex operator /(const Complex& z1, const Complex& z2) {
	Complex res(z1);
	return res /= z2;
};


Complex& Complex::operator +=(const Complex& z1) {
	SetRe(GetRe() + z1.GetRe());
	SetIm(GetIm() + z1.GetIm());
	return *this;
};


Complex& Complex::operator -=(const Complex& z1) {
	this->SetRe(this->GetRe() - z1.GetRe());
	this->SetIm(this->GetIm() - z1.GetIm());
	return *this;
};


Complex& Complex::operator *=(const Complex& z1) {
	double x = this->GetRe();
	this->SetRe(this->GetRe() * z1.GetRe() - this->GetIm() * z1.GetIm());
	this->SetIm(x * z1.GetIm() + this->GetIm() * z1.GetRe());
	return *this;
};


Complex& Complex::operator /=(const Complex& z1) {
	double x = this->GetRe();
	this->SetRe((this->GetRe() * z1.GetRe() + this->GetIm() * z1.GetIm()) / (pow(z1.GetIm(), 2.0) + pow(z1.GetRe(), 2.0)));
	this->SetIm((this->GetIm() * z1.GetRe() - x * z1.GetIm()) / (pow(z1.GetIm(), 2.0) + pow(z1.GetRe(), 2.0)));
	return *this;
}


double Complex::sq() {
	return GetRe() * GetRe() + GetIm() * GetIm();
}


double Complex::Modulo() {
	return sqrt(sq());
}



