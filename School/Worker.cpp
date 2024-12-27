#include "Worker.h"

Worker::Worker(string name, int age, double salary, int timework) : Person(name, age)
{
    setName(name);
    setAge(age);
    setSalary(salary);
    setTimework(timework);
}

Worker::~Worker()
{
}


