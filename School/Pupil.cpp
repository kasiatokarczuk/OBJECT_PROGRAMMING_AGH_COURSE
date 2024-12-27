#include "Pupil.h"

int Pupil::m_baseID = 10000;


Pupil:: Pupil(string name /*= ""*/, int age /*= 0*/, string classname /*= ""*/) noexcept : Person(name,age)
{
    setPerson(name,age);
    setClassName(classname); 
    m_ID=to_string(m_baseID++);  
    clearNotes();
}



void Pupil::clearNotes()
{
    memset(m_Notes, 0, MAXSUBJECTS * sizeof(double));
}


double Pupil::calcAve()
{
    double sum = 0;
    int count = 0;

    for (int i = 0; i < MAXSUBJECTS; i++)
    {
        if (m_Notes[i] > 1)  
        {
            sum += m_Notes[i];
            count++;
        }
    }

    m_Ave = (count>0) ? sum / count : 0;
    return m_Ave;
}


void Pupil::setNote(Subjects subject, double note)
{
    if (subject >=POLSKI && subject <MAXSUBJECTS && note >= 2 && note <= 5)
    {
        m_Notes[subject] = note;
    }
    
}


void Pupil::printPupil()   
{
    cout << getID() << ' ' << getName() << " (" << getClassName() << ") " << getAge() << " lat ";
cout << "srednia: " << calcAve() << endl;
cout << '\t';
printOutfit();

}