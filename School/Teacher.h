#pragma once
#include "Worker.h"
class Teacher :
    public Worker
{
public:
    Teacher(string name = "", int age = 0, double salary = 0, int timework = 0, string subject = "", bool wychowawca = false, string classname="") noexcept;
    virtual ~Teacher();

    void setSubject(string nSubject);
    string getSubject() const;

    void setClassname(string classname);
    string getClassname();

    void setWychowawca(bool nWychowawca);
    bool getWychowawca() const;


    //funckje do pensji:
    double calcBrutto();
    double calcTax();
    double calcNetto();
    void printWage(); // drukuje pensje (brutto,podatek,netto)
    virtual void printWorker() final;



private:
    string m_Subject;
    bool m_Wychowawca;
    string m_Classname;

};



//------------INLINE FUNCTIONS---------------
inline void Teacher::setSubject(string nSubject)
{
    m_Subject = nSubject;
}

inline string Teacher::getSubject() const
{
    return m_Subject;
}


inline void Teacher::setClassname(string classname)
{
    m_Classname = m_Classname;
}

inline string Teacher::getClassname()
{
    return m_Classname;
}

inline void Teacher::setWychowawca(bool nWychowawca)
{
    m_Wychowawca = nWychowawca;
}


inline bool Teacher::getWychowawca() const
{
    return m_Wychowawca;
}
