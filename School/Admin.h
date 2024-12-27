#pragma once
#include "Worker.h"


//enum Position {mlodszy_specjalista,specjalista,starszy_specjalista};


class Admin :
    public Worker
{
public:
    Admin(string name = "", int age = 0, double salary = 0, int timework = 0, string position = "") noexcept;
    virtual ~Admin();
   
    void setPosition(string nPosition);
    string getPosition() ;

    double calcBrutto();
    double calcTax();
    double calcNetto();
    void printWage();

    virtual void printWorker() final;

private:
    string m_Position;
};


//-------INLINE FUNCTIONS-----------
inline void Admin::setPosition(string nPosition)
{
    m_Position = nPosition;
}

inline string Admin::getPosition() 
{
    return m_Position;
}