#pragma once
#include "Person.h"

//typedef enum { POLSKI, MATEMATYKA, FIZYKA, CHEMIA, INFORMATYKA, ANGIELSKI, NIEMIECKI }Subjects;
enum Subjects { POLSKI, MATEMATYKA, FIZYKA, CHEMIA, INFORMATYKA, ANGIELSKI, NIEMIECKI };

#define MAXSUBJECTS NIEMIECKI+1


class Pupil : public Person
{
public:
	Pupil(string name = "", int age = 0, string classname = "") noexcept;
	virtual ~Pupil() {}

	void setClassName ( string newClassName );  
	string getClassName() const;  

	string getID() const;
	double getAve() const;  //srednia ocen
	void clearNotes();  //wyczyszczenie ocen
	double calcAve();   //liczenie sredniej
	void setNote(Subjects subject, double note); //ustawienie ocen
	void printPupil(); 
	virtual void printOutfit() {} //nie implementujemy
	

protected:
	string m_ID; //jest dostepna wprost z klasy pochodnych


private:
	string m_ClassName; 
	static int m_baseID;
	double m_Notes[MAXSUBJECTS];
	double m_Ave;
};




//--------INLINE FUNCTIONS--------
inline string Pupil::getID() const
{
	return m_ID;
}

inline double Pupil::getAve() const
{
	return m_Ave;
}

inline void Pupil::setClassName ( string newClassName )
{
	m_ClassName = newClassName;
}

inline string Pupil::getClassName() const
{
	return m_ClassName;
}