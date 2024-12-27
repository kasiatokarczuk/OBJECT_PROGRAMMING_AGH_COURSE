#pragma once
#include "Person.h"

#define KOSZTYUZYSKANIA 111.25
#define KWOTAWOLNA 556.02

class Worker :
    public Person
{
public:
    Worker(string name = "", int age = 0, double salary = 0, int timework = 0); //salary-brutto
    virtual ~Worker();


    void setSalary(double newSalary);
    double getSalary() const;
    void setTimework(int newTimework);
    int getTimework() const;

    virtual void printWorker() {}

private:
    double m_Salary;
    int m_Timework;

};

//------------INLINE FUNCTIONS--------
inline void Worker::setSalary(double newSalary)
{
    m_Salary = newSalary;
}

inline double Worker::getSalary() const
{
    return m_Salary;
}

inline void Worker::setTimework(int newTimework)
{
    m_Timework = newTimework;
}

inline int Worker::getTimework() const
{
    return m_Timework;
}