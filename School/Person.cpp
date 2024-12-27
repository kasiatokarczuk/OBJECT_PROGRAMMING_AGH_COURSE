#include "Person.h"


Person::Person(string name /*= ""*/, int age /*= 0*/) noexcept
{
	setPerson(name, age);
}

void Person::setPerson(string newName, int newAge)
{
	m_Name = newName;
	m_Age = newAge;
}