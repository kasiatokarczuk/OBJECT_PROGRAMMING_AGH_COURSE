#pragma once
#include <iostream>
using namespace std;

class TESTDLL_API Date  
{

public:  
	Date(int dd=1, int mm=1, int yy=1990);
	Date(const Date& d);  


public:
	//  setters/getters  
	void setDate(int hh, int mm, int ss);  
	void setDay(int newDay);
	void setMonth(int newMonth);
	void setYear(int newYear);


	int getDay()const;   
	int getMonth()const;
	int getYear()const;


	void printDate();
	void readDate();
	friend TESTDLL_API ostream& operator<<(ostream& out, const Date& d);
	friend TESTDLL_API istream& operator>>(istream& in, Date& d);  
	


private:
	int m_nDay;   
	int m_nMonth;
	int m_nYear;

};


//------------ INLINE FUNCTIONS
inline void Date::setDay(int newDay)
{
	m_nDay = newDay;
}
inline void Date::setMonth(int newMonth)
{
	m_nMonth = newMonth;
}
inline void Date::setYear(int newYear)
{
	m_nYear = newYear;
}



inline int Date::getDay()const
{
	return m_nDay;
}

inline int Date::getMonth()const
{
	return m_nMonth;
}
inline int Date::getYear()const
{
	return m_nYear;
}

/// Date.inl
// #include "Date.inl"