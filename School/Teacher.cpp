#include "Teacher.h"

Teacher::Teacher(string name /*= ""*/, int age /*= 0*/, double salary /*= 0*/, int timework /*= 0*/, string subject /*= ""*/, bool wychowawca /*= false*/,string classname/*=""*/) noexcept : Worker(name,age,salary,timework)
{
	setName(name);
	setAge(age);
	setSalary(salary);
	setTimework(timework);
	setSubject(subject);
	setWychowawca(wychowawca);

	m_Wychowawca = wychowawca;
	if (m_Wychowawca)
	{
		m_Classname= classname;
	}
}

Teacher::~Teacher()
{
}


 double Teacher::calcBrutto()
{
    double brutto = getSalary();
    int timework = getTimework();

    //bonus za wysluge lat
    if (timework >= 5 && timework <= 20) {
        brutto += brutto * (timework / 100.0);
    }
    else if (timework > 20) {
        brutto += brutto * 0.20; // max sta¿owe
    }

    //bonus dla wychowawcy
    if (getWychowawca()) {
        brutto += 400.0;
    }

    return brutto;
}


double Teacher::calcTax()
{
    double brutto = calcBrutto();

    double tax = ((0.8*brutto - 0.5*KOSZTYUZYSKANIA) * 0.18) - KWOTAWOLNA;

    // ujemny podatek
    if (tax < 0) {
        tax = 0;
    }

    return tax;
}


double Teacher::calcNetto()
{
    double brutto = calcBrutto();
    double tax = calcTax();

    double netto = brutto - tax;

    return netto;
}


void Teacher::printWage()
{
    cout << "Pensja brutto: " << calcBrutto() << ", Podatek: " << calcTax() << ", Pensja netto: " << calcNetto() <<"\n";
}


void Teacher::printWorker()
{
    cout << getName() << " Stanowisko: Nauczyciel" << "  Przedmiot: " << getSubject() <<"\n"; //<< ", Wychowawca: " << (getWychowawca() ? "Tak" : "Nie") << " ,Klasa: " << getClassname() << "\n";
    printWage();
}