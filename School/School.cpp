// School.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
#include <iostream>
using namespace std;

#include "Admin.h"
#include "Teacher.h"
#include "SchoolBoy.h"
#include "SchoolGirl.h"
#include "Pupil.h"




#define MAXPUPIL 9

void printPupils(Pupil** tab, int PupilNo);
void sortPupils(Pupil** tab, int PupilNo);

void printWorkers(Worker** tab, int WorkerNo);


int main()
{
	//-------------------------------PUPILS----------------------------------------

	Pupil* pupils[MAXPUPIL] = {NULL}; //nullptr
	Pupil* v = NULL;

	pupils[0] = v = new SchoolGirl("Kowalska Dominika", 16, "4a");
	v->setNote(MATEMATYKA, 3.5);
	v->setNote(FIZYKA, 3.5);
	v->setNote(POLSKI, 2.5);
	v->setNote(CHEMIA, 5.0);

	pupils[1] = v = new SchoolGirl("Kwiatkowska Aleksandra", 17, "4b");
	v->setNote(MATEMATYKA, 5.0);
	v->setNote(POLSKI, 4.0);
	v->setNote(INFORMATYKA, 4.5);
	v->setNote(ANGIELSKI, 5.0);

	pupils[2] = v = new SchoolBoy("Nowak Karol", 19, "6b");
	v->setNote(MATEMATYKA, 3.5);
	v->setNote(POLSKI, 4.0);
	v->setNote(NIEMIECKI, 3.5);
	v->setNote(CHEMIA, 3.0);

	pupils[8] = v = new SchoolBoy("Kowalik Artur", 17, "3b");

	sortPupils(pupils, 3);
	printPupils(pupils, 3);



	//-------------------------------WORKERS-----------------------------------------

	Worker* workers[9] = { NULL };
	Worker* w = NULL;

	workers[0] = w = new Teacher ("Kowalski Jan", 35, 5000, 10, "Matematyka", true, "2B");
	workers[1] = w = new Teacher ("Nowak Krzysztof", 40, 6000, 15, "Język angielski", false, "");
	workers[2] = w = new Teacher ("Kwiatkowska Aneta", 45, 7000, 8, "Historia", false, "");
	workers[3] = w = new Teacher ("Lipska Patrycja", 60, 5000, 9, "Informatyka", false, "");
	workers[4] = w = new Teacher ("Buczkowska Marta", 45, 6500, 4, "Biologia", true, "4A");
	workers[5] = w = new Teacher ("Pietnowski Adrian", 55, 5500, 11, "WF", true, "4B");


	workers[6] = w = new Admin ("Niebo Karolina", 30, 4500, 3, "mlodszy_specjalista");
	workers[7] = w = new Admin ("Wisniewski Karol", 38, 5500, 7, "specjalista");
	workers[8] = w = new Admin ("Wujcik Dawid", 42, 6500, 20, "starszy_specjalista");

	printWorkers(workers, 9);



	return 0;
}

//-------------funkcje------------------------

void printWorkers(Worker** tab, int WorkerNo)
{
	for (int i = 0; i < WorkerNo; i++)
	{
		tab[i]->printWorker();
		cout << "\n";
	}

}


void printPupils(Pupil** tab, int PupilNo)
{
	for (int i = 0; i < PupilNo; i++)
	{
		tab[i]->printPupil();
		cout << "\n\n";
	}

}


void sortPupils(Pupil** tab, int PupilNo)
{
	for (int i = 1; i < PupilNo; i++)
	{
		int j = i - 1;
		Pupil* v = tab[i];
		while (j >= 0 && v->getName() < tab[j]->getName())
		{
			tab[j + 1] = tab[j--];
			tab[j + 1] = v;
		}
	}
}



