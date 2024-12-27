#include "pch.h"
#include "testDll.h"
#include "Date.h"




Date::Date(int dd/*=1*/, int mm/*=1*/, int yy/*=1990*/)
{
	setDate(dd, mm, yy);
}

Date::Date(const Date& d)
{
	*this = d;
}


void Date::setDate(int dd, int mm, int yy)  
{
	setDay(dd);
	setMonth(mm);
	setYear(yy);
}



void Date::printDate()
{
	cout << m_nDay << ':' << getMonth() << ':' << getYear();
}
void Date::readDate()
{
	//hh:mm:ss
	char c;
	int x;
	cin >> x >> c; setDay(x);
	cin >> x >> c; setMonth(x);
	cin >> x; setYear(x);
}


ostream& operator <<(ostream& out, const Date& d)
{
	out << d.m_nDay << '/' << d.getMonth() << '/' << d.getYear();

	return out;
}


istream& operator >>(istream& in, Date& d)
{
	char c;
	int x;
	in >> x >> c, d.setDay(x);
	in >> x >> c, d.setMonth(x);
	in >> x, d.setYear(x);

	return in;
}
