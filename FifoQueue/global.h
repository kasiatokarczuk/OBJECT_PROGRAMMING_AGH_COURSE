#pragma once
#include <iostream>
using namespace std;

#define FQINFO FQInfo  


struct FQInfo
{
	FQInfo(int key); 
	virtual ~FQInfo(); 

	friend ostream& operator <<(ostream& out, const FQINFO& f); 

	int nKey;
	int* p;  
};



//----------INLINE FUNCTIONS--------------

inline FQInfo::~FQInfo()
{
	delete p;
}

inline FQInfo::FQInfo(int key)
{
	nKey = key;
	p = new int[2];
	p[0] = key;
	p[1] = key;
}


inline ostream& operator <<(ostream& out, const FQINFO& f)
{
	out << "Key:" << f.nKey << " p: [" << f.p[0] << "," << f.p[1] << "]   \n";
	return out;
}

