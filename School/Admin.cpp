#include "Admin.h"

Admin::Admin(string name, int age, double salary, int timework, string position) noexcept : Worker(name, age, salary, timework)
{
	setName(name);
	setAge(age);
	setSalary(salary);
	setTimework(timework);
	setPosition(position);
}

Admin::~Admin()
{

}

double Admin::calcBrutto()
{
    return getSalary();
}


double Admin::calcTax()
{
    double brutto = calcBrutto();

    double tax = ((brutto - KOSZTYUZYSKANIA) * 0.18) - KWOTAWOLNA;

    // ujemny podatek
    if (tax < 0) {
        tax = 0;
    }

    return tax;
}


double Admin::calcNetto()
{
    double brutto = calcBrutto();
    double tax = calcTax();

    double netto = brutto - tax;

    return netto;
}


void Admin::printWage()
{
    cout << "Pensja brutto: " << calcBrutto() << ", Podatek: " << calcTax() << ", Pensja netto: " << calcNetto() << "\n";
}


void Admin::printWorker()
{

     cout << getName() << " ,Stanowisko: " << getPosition() << "\n";
     printWage();
    
}