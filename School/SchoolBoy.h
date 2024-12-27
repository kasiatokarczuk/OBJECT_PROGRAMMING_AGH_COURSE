#pragma once
#include "Pupil.h"
class SchoolBoy :
    public Pupil
{
public:
    SchoolBoy(string name, int age, string ClassName) noexcept;
    virtual void printOutfit() final;
};

