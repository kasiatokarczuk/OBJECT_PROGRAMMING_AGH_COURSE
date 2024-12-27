#pragma once
using namespace std;
#include <iostream>
#include <string>


class Person
{
public:
	Person(string name = "", int age = 0) noexcept; //nie rzuca wyjatkami
	virtual ~Person() {}
	//Person& operator = (const Person& z) = default; //nie mozna go implementowac

//gettery
	string getName() const;
	int getAge() const;

//settery
	void setName(string newName);
	void setAge(int newAge);
	void setPerson(string newName, int nAge);

private:
	string m_Name;
	int m_Age;
};




//---------INLINE FUNCTIONS-------

inline string Person::getName() const
{
	return m_Name;
}

inline int Person::getAge() const
{
	return m_Age;
}

inline void Person::setName(string newName)
{
	m_Name = newName;
}

inline void Person::setAge(int newAge)
{
	m_Age = newAge;
}

