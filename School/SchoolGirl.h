#pragma once
#include "Pupil.h"
class SchoolGirl :
    public Pupil
{
public:
    SchoolGirl(string name, int age, string ClassName) noexcept;
    virtual void printOutfit() final;
    //void printOutfit() override;

};

