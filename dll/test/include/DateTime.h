#pragma once
#include "Date.h"
#include "CTime.h"

class TESTDLL_API DateTime : public Date, public Time  //klasa ³¹czna
{
public:
	DateTime(int DD = 1, int MM = 1, int YYYY = 1990, int hh = 0, int mm = 0, int ss = 0);
	DateTime(const DateTime& dt);
	DateTime(const Date& dt, const Time& time);

	DateTime& operator = (const DateTime& dt);

	void setDateTime(int DD, int MM, int YYYY, int hh, int mm, int ss);

	friend TESTDLL_API istream& operator >>(istream& in, DateTime& dt);

	friend TESTDLL_API ostream& operator <<(ostream& out, const DateTime& dt);


};


