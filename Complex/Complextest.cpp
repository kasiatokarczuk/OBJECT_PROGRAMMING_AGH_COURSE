#include <iostream>
using namespace std;

#include "Complex.h"

int main()
{

    Complex z1(4, 3);
    
    cout << "Enter a complex number (Re Im): ";
    Complex z2;
    cin >> z2;

    Complex addition = z1 + z2;
    Complex substraction = z1 - z2;
    Complex multiplication = z1 * z2;
    Complex division = z1 / z2;

    cout << "addition: " << addition << endl;
    cout << "substraction: " << substraction << endl;
    cout << "multiplication: " << multiplication << endl;
    cout << "division: " << division << endl;

    cout << "addition modulo: " << addition.Modulo() << endl;
    cout << "substraction modulo: " << substraction.Modulo() << endl;
    cout << "multiplication modulo: " << multiplication.Modulo() << endl;
    cout << "division modulo: " << division.Modulo() << endl;

    return 0;

}



