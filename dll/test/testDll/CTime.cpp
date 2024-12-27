#include "pch.h"
#include "testDll.h"
#include "CTime.h"

Time::Time(int hh/*=0*/, int mm/*=0*/, int ss/*=0*/)
{
	setTime(hh, mm, ss);
}


Time::Time(const Time& t)
{
	*this = t;
}



void Time::setTime(int hh, int mm, int ss)  
{
	setHour(hh);
	setMin(mm);
	setSec(ss);
}







void Time::printTime()
{
	cout << mHour << ':' << getMin() << ':' << getSec();
}
void Time::readTime()
{
	//hh:mm:ss
	char c;
	int x;
	cin >> x >> c; setHour(x);
	cin >> x >> c; setMin(x);
	cin >> x; setSec(x);
}


ostream& operator <<(ostream& out, const Time& t)
{
	out << t.mHour << ':' << t.getMin() << ':' << t.getSec();

	return out;
}


istream& operator >>(istream& in, Time& t)
{
	char c;
	int x;
	in >> x >> c, t.setHour(x);
	in >> x >> c, t.setMin(x);
	in >> x, t.setSec(x);

	return in;
}