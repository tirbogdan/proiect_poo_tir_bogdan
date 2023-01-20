#include "Auxiliare.h"
#include <iostream>
#include <iomanip>
#include <string>
#pragma warning(disable: 4996)
using namespace std;



void Auxiliare::afisareOptiuniMeniuprincipal()
{
	system("CLS");
	cout << "Selecteaza una dintre optiuni pentru a continua: " << endl;
	cout << "1. Meniu locatii" << endl;
	cout << "2. Meniu bilete" << endl;
	cout << "3. Meniu evenimente" << endl;
	cout << "0. Iesire" << endl;
}

void Auxiliare::afisareOptiuniMeniuLocatii()
{
	system("CLS");
	cout << "Selecteaza una dintre optiuni pentru a continua: " << endl;
	cout << "1. Adaugare locatie" << endl;
	cout << "2. Afisare locatii" << endl;
	cout << "3. Stergere locatie" << endl;
	cout << "4. Modificare locatie" << endl;
	cout << "0. Iesire" << endl;
}

void Auxiliare::afisareOptiuniMeniuBilete()
{
	system("CLS");
	cout << "Selecteaza una dintre optiuni pentru a continua: " << endl;
	cout << "1. Adaugare bilet" << endl;
	cout << "2. Afisare bilete" << endl;
	cout << "3. Stergere bilet" << endl;
	cout << "4. Modificare bilet" << endl;
	cout << "0. Iesire" << endl;
}

void Auxiliare::afisareOptiuniMeniuEvenimente()
{
	system("CLS");
	cout << "Selecteaza una dintre optiuni pentru a continua: " << endl;
	cout << "1. Adaugare eveniment" << endl;
	cout << "2. Afisare evenimente" << endl;
	cout << "3. Stergere eveniment" << endl;
	cout << "4. Modificare eveniment" << endl;
	cout << "0. Iesire" << endl;
}

bool Auxiliare::verificareOptiune(string optiune, int nrMaxOptiuni)
{
	if (optiune.length() > 2) return false;
	for (int i = 0; i < optiune.length(); i++)
	{
		if (!isdigit(optiune[i]))
		{
			return false;
		}
	}
	int optiuneInt = stoi(optiune);
	if (optiuneInt >= 0 && optiuneInt <= nrMaxOptiuni)
		return true;
	else
		return false;
}

void Auxiliare::functionalitateMeniuPrincipal(string &optiune)
{
	int optiuneInt = 0;
	do
	{
		if (optiune != "0")
			Auxiliare::afisareOptiuniMeniuprincipal();
		getline(cin, optiune);
		if (!cin.fail() && verificareOptiune(optiune, 3))
		{
			optiuneInt = stoi(optiune);
			switch (optiuneInt)
			{
			case 1:
				afisareOptiuniMeniuLocatii();
				functionalitateMeniuLocatii(optiune);
				optiune = "1";
				break;
			case 2:
				afisareOptiuniMeniuBilete();
				functionalitateMeniuBilete(optiune);
				optiune = "2";
				break;
			case 3:
				afisareOptiuniMeniuEvenimente();
				functionalitateMeniuEvenimente(optiune);
				optiune = "3";
				break;
			case 0:
				break;
			default:
				break;
			}
		}
		else
			cout << "Optiunea selectata nu este valida!" << endl;
	} while (optiune != "0");
}

void Auxiliare::functionalitateMeniuLocatii(string& optiune)
{
	int optiuneInt = 0;
	do
	{
		getline(cin, optiune);
		if (!cin.fail() && verificareOptiune(optiune, 4))
		{
			optiuneInt = stoi(optiune);
			switch (optiuneInt)
			{
			case 1:
				//adaugare locatie
				cout << "Adaugare locatie" << endl;
				break;
			case 2:
				cout << "Afisare locatii" << endl;
				//afisare locatii
				break;
			case 3:
				cout << "Stergere locatie" << endl;
				//stergere locatie
				break;
			case 4:
				cout << "Modificare locatie" << endl;
				//modificare locatie
				break;
			case 0:
				
				break;
			default:
				break;
			}
		}
		else
			cout << "Optiunea selectata nu este valida!" << endl;
	}
	while (optiune != "0");
}

void Auxiliare::functionalitateMeniuBilete(string& optiune)
{
	int optiuneInt = 0;
	do
	{
		getline(cin, optiune);
		if (!cin.fail() && verificareOptiune(optiune, 4))
		{
			optiuneInt = stoi(optiune);
			switch (optiuneInt)
			{
			case 1:
				//adaugare bilet
				cout << "Adaugare bilet" << endl;
				break;
			case 2:
				cout << "Afisare bilete" << endl;
				//afisare bilete
				break;
			case 3:
				cout << "Stergere bilet" << endl;
				//stergere bilet
				break;
			case 4:
				cout << "Modificare bilet" << endl;
				//modificare bilet
				break;
			case 0:
				break;
			default:
				break;
			}
		}
		else
			cout << "Optiunea selectata nu este valida!" << endl;
	} while (optiune != "0");
}

void Auxiliare::functionalitateMeniuEvenimente(string& optiune)
{
	int optiuneInt = 0;
	do
	{
		getline(cin, optiune);
		if (!cin.fail() && verificareOptiune(optiune, 4))
		{
			optiuneInt = stoi(optiune);
			switch (optiuneInt)
			{
			case 1:
				//adaugare eveniment
				cout << "Adaugare eveniment" << endl;
				break;
			case 2:
				cout << "Afisare evenimente" << endl;
				//afisare evenimente
				break;
			case 3:
				cout << "Stergere eveniment" << endl;
				//stergere eveniment
				break;
			case 4:
				cout << "Modificare eveniment" << endl;
				//modificare eveniment
				break;
			case 0:
				break;
			default:
				break;
			}
		}
		else
			cout << "Optiunea selectata nu este valida!" << endl;
	} while (optiune != "0");
}

bool Auxiliare::continuam()
{
	string raspuns;
	cout << "Continuam?" << endl;
	getline(cin, raspuns);
	while (!(raspuns == "da" || raspuns == "Da" || raspuns == "DA" || raspuns == "dA" || raspuns == "nu" || raspuns == "Nu" || raspuns == "NU" || raspuns == "nU"))
	{
		cout << "Trebuie sa imi spui da sau nu. E o intrebare..." << endl;
		getline(cin, raspuns);
	}
	if (raspuns == "nu" || raspuns == "Nu" || raspuns == "NU" || raspuns == "nU")
	{
		cout << "Ok, atat de vazut aici atunci." << endl;
		return false;
	}
	return true;
}