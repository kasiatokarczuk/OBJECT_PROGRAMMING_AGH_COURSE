#include "pch.h"
#include "testDll.h"
#include "DateTime.h"

DateTime::DateTime(int DD, int MM, int YYYY, int hh, int mm, int ss)
    : Date(DD, MM, YYYY), Time(hh, mm, ss)
{

}

DateTime::DateTime(const DateTime& dt) : Date((Date&)dt), Time((Time&)dt)
{

}

DateTime::DateTime(const Date& date, const Time& time): Date( date),Time(time)
{

}

DateTime& DateTime::operator = (const DateTime& dt)
{
    (Date&)*this = (Date&)dt;
    *(Time*)this = (Time&)dt;

    return *this;

}

void DateTime::setDateTime(int DD, int MM, int YYYY, int hh, int mm, int ss)
{
    setDate(DD, MM, YYYY);
    setTime(hh, mm, ss);
}

istream& operator >>(istream& in, DateTime& dt)
{
    in >> (Date&)dt;
    in >> (Time&)dt;

    return in;
}

ostream& operator <<(ostream& out, const DateTime& dt)
{
    out << (Date&)dt << " " << (Time&)dt;

    return out;
}
