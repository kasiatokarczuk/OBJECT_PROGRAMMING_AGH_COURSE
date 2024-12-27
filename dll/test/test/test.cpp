// test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "testDll.h"
#include "Date.h"
#include "CTime.h"
#include "DateTime.h"

int main()
{
	Date d(9, 12, 2023);
	cout << "d = " << d << endl;

	Time t(22, 10, 24);
	cout << "t = " << t << endl;

	DateTime dt(d,t);
	cout << "Dt = " << dt << endl;

}

