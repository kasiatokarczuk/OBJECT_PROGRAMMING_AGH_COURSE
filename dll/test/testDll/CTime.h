#pragma once
#include <iostream>
using namespace std;

class TESTDLL_API Time  
{

public:  //constructors
	Time(int hh = 0, int mm = 0, int ss = 0);
	Time(const Time& t);  


public:
	//  setters/getters  
	void setTime(int hh, int mm, int ss);  
	void setHour(int newHour);
	void setMin(int newMin);
	void setSec(int newSec);

public:
	int getHour()const;  
	int getMin()const;
	int getSec()const;


	void printTime();
	void readTime();
	friend TESTDLL_API ostream& operator<<(ostream& out, const Time& t);
	friend TESTDLL_API istream& operator>>(istream& in, Time& t);  
	


private:
	int mHour;   
	int mMin;
	int mSec;

};

//----------- INLINE FUNCTIONS

inline void Time::setHour(int newHour)
{
	mHour = newHour;
}
inline void Time::setMin(int newMin)
{
	mMin = newMin;
}
inline void Time::setSec(int newSec)
{
	mSec = newSec;
}



inline int Time::getHour()const
{
	return mHour;
}

inline int Time::getMin()const
{
	return mMin;
}
inline int Time::getSec()const
{
	return mSec;
}

